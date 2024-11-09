package lab4;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

import util.JDBCUtil;

public class CompanyDao {
	private JDBCUtil jdbcUtil = null;	// JDBCUtil 필드 선언
		
	public CompanyDao() {				// 생성자 
		jdbcUtil = new JDBCUtil();		// JDBCUtil 객체 생성
		
/*		// JDBCUtil 이용 시 불필요: DBCP 활용		
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");	
		} catch (ClassNotFoundException ex) {
			ex.printStackTrace();
		}
*/
	}

/*	// JDBCUtil 이용 시 불필요: 내부적으로 connection 생성 및 사용 
	private Connection getConnection() {
		String url = "jdbc:oracle:thin:@dblab.dongduk.ac.kr:1521/orclpdb";		
		String user = "[user]";
		String passwd = "[pw]";

		// DBMS와의 연결 획득
		Connection conn = null;
		try {
			conn = DriverManager.getConnection(url, user, passwd);
		} catch (SQLException e) {
			e.printStackTrace();
		}	 
		return conn;
	}
*/
	
    public Department findDeptByName(String deptName) {
    	/* 실습 #3의 printDeptInfo()를 변형. 
    	 * 부서정보 검색 후 Department DTO를 생성하고 검색 결과를 저장해서 return함
    	 * (검색 결과가 없을 경우 null을 반환) 
    	 */
        StringBuffer query = new StringBuffer();
        query.append("SELECT deptno, manager, COUNT(empno) AS numOfEmps ");
        query.append("FROM EMP0769 JOIN DEPT0769 USING (deptno) ");
        query.append("WHERE dname = ? ");
        query.append("GROUP BY deptno, manager");
        
    	jdbcUtil.setSqlAndParameters(query.toString(), new Object[]{deptName});	// JDBCUtil에 질의문과 파라미터 설정	
		
		try {
			ResultSet rs = jdbcUtil.executeQuery();
			
			if (rs.next()) {		// 검색 결과 존재
				Department dept = new Department(rs.getInt("deptno"), deptName, rs.getInt("manager"), rs.getInt("numOfEmps"));
				
				return dept;
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			jdbcUtil.close();		// ResultSet, PreparedStatement, Connection 등 해제
		}
    	return null;
    } 

    public List<Employee> getAllEmpsInDept(int deptNo) {
    	/* 실습 #3의 printAllEmpsInDept()를 변형.
    	 * ArrayList<Employee> 타입 객체를 생성한 후, 검색된 각 사원 정보에 대해
    	 * Employee DTO를 생성 및 저장하고 List 객체에 추가함. List 객체를 반환함
    	 */
        StringBuffer query = new StringBuffer();
        query.append("SELECT empno, ename, job, sal, comm, dname ");
        query.append("FROM EMP0769 JOIN DEPT0769 USING (deptno) ");
        query.append("WHERE deptNo = ?"); 
        
        jdbcUtil.setSqlAndParameters(query.toString(), new Object[] {deptNo});
    	
    	try {
    	    ResultSet rs = jdbcUtil.executeQuery();
    	    List<Employee> empList = new ArrayList<Employee>(); 
    	    while (rs.next()) {
    	        Employee emp = new Employee();
    	        emp.setEmpNo(rs.getInt("empno"));
    	        emp.setEmpName(rs.getString("ename"));
    	        emp.setJob(rs.getString("job"));
    	        emp.setSal(rs.getDouble("sal"));
    	        emp.setComm(rs.getDouble("comm"));
    	        emp.setDeptName(rs.getString("dname"));
    	        
    	        empList.add(emp);
    	    }
    	    return empList;
    	}catch(Exception ex) {
    	    ex.printStackTrace();
        }finally {
            jdbcUtil.close();
        }	
    	return null;
    }

    public Employee replaceManagerOfDept(Appointment appo) {
    	/* 실습 #3의 replaceManagerOfDept()와 유사하나, 매개변수 전달을 위해 Appointment
    	 * DTO를 이용하고, 실행 결과로 기존 관리자 사원 정보를 포함하는 Employee DTO를 반환함
    	 */    	
        try {
        	Employee oldMgr = new Employee();
        	
        	String query1 = "SELECT manager FROM DEPT0769 WHERE deptNo = ?";
        	jdbcUtil.setSqlAndParameters(query1, new Object[] {appo.getDeptNo()});
        	ResultSet rs = jdbcUtil.executeQuery();
        	
        	if (rs.next())
        	    oldMgr.setEmpNo(rs.getInt("manager"));
        	
        	String query2 = "UPDATE EMP0769 SET ename = REPLACE(ename, '(M)', '') WHERE empno = ?";
        	jdbcUtil.setSqlAndParameters(query2, new Object[] {oldMgr.getEmpNo()}); 
        	jdbcUtil.executeUpdate();
        	
        	String query3 = "SELECT empno, ename, job, hiredate, sal, comm, dname FROM EMP0769 JOIN DEPT0769 USING (deptno) WHERE empno = ?";
        	
        	jdbcUtil.setSqlAndParameters(query3, new Object[] {oldMgr.getEmpNo()});
        	rs = jdbcUtil.executeQuery();
        	if (rs.next()) {
        	    oldMgr.setEmpName(rs.getString("ename"));
        	    oldMgr.setJob(rs.getString("job"));
        	    oldMgr.setHiredate(rs.getDate("hiredate"));
        	    oldMgr.setSal(rs.getDouble("sal"));
        	    oldMgr.setComm(rs.getDouble("comm"));
        	    oldMgr.setDeptName(rs.getString("dname"));
        	}
        	
        	String query4 = "UPDATE EMP0769 SET ename = ename || '(M)', comm = NVL(comm,0) + ? WHERE empno = ?";
        	jdbcUtil.setSqlAndParameters(query4, new Object[] {appo.getCommission(), appo.getNewMgrNo()});
        	jdbcUtil.executeUpdate();
        	
        	String query5 = "UPDATE DEPT0769 SET manager = ? WHERE deptno = ?"; 
        	jdbcUtil.setSqlAndParameters(query5, new Object[] {appo.getNewMgrNo(), appo.getDeptNo()});
        	jdbcUtil.executeUpdate();
        	
        	return oldMgr;
        } catch (Exception ex) {
        	jdbcUtil.rollback();	// 트랜잭션 rollback 실행
        	ex.printStackTrace();
        } finally {
            jdbcUtil.commit();		// 트랜잭션 commit 실행
            jdbcUtil.close();
        }
    	return null;
    }
    
    public Employee findEmployee(int empNo) {
    	/* 실습 #3의 printEmpInfo()를 변형
    	 * 주어진 사번에 해당하는 사원 정보를 검색 후 Employee DTO를 생성 및 저장하고 반환함
         * (검색 결과가 없을 경우 null을 반환) 
         */ 
        StringBuffer query = new StringBuffer();
        query.append("SELECT ename, job, hiredate, sal, comm, dname "); 
        query.append("FROM EMP0769 e, DEPT0769 d WHERE e.deptno = d.deptno AND empno = ?");
        
        jdbcUtil.setSqlAndParameters(query.toString(), new Object[] {empNo});
        
        try {
            ResultSet rs = jdbcUtil.executeQuery();
            
            if (rs.next()) {        // 검색 결과 존재
                Employee emp = new Employee();
                
                emp.setEmpNo(empNo);
                emp.setEmpName(rs.getString("ename"));
                emp.setJob(rs.getString("job"));
                emp.setHiredate(rs.getDate("hiredate"));
                emp.setSal(rs.getDouble("sal"));
                emp.setComm(rs.getDouble("comm"));
                emp.setDeptName(rs.getString("dname"));
                
                return emp;
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            jdbcUtil.close();
        }
        return null;     
    }
} 

