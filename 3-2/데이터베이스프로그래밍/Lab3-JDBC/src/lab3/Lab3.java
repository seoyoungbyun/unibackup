package lab3;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;
import java.sql.Date;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Lab3 {
    public Lab3() {     // 생성자
        // JDBC 드라이버 로딩
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");   
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }   
    }
    
    private static Connection getConnection() {
        String url = "jdbc:oracle:thin:@dblab.dongduk.ac.kr:1521/orclpdb";        
        //String url = "jdbc:oracle:thin:@localhost:1521/xepdb1";
        String user = "[user]";
        String passwd = "[pw]";

        // DBMS와의 연결 생성
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url, user, passwd);
        } catch (SQLException e) {
            e.printStackTrace();
        }    
        return conn;
    }
    
    public static void printDeptInfo(String deptName) throws DeptNotFoundException {
        Connection conn = null;
        PreparedStatement pStmt = null;
        ResultSet rs = null;

        StringBuffer query = new StringBuffer();
        query.append("SELECT deptno, manager, COUNT(empno) AS numOfEmps ");
        query.append("FROM EMP0769 JOIN DEPT0769 USING (deptno) ");
        query.append("WHERE dname = ? ");
        query.append("GROUP BY deptno, manager");

        conn = getConnection(); 
        try {                   
            pStmt = conn.prepareStatement(query.toString());
            pStmt.setString(1, deptName);
            rs = pStmt.executeQuery();
            
            if (rs.next()) {
                int deptno = rs.getInt("deptno");
                int manager = rs.getInt("manager");
                int empNum = rs.getInt("numOfEmps");
                System.out.println("<부서정보>");
                System.out.println("부서번호: " + deptno + "\n부서명: " + deptName + "\n관리자사번: " + manager + "\n사원 수: " + empNum + "\n");
            }
            else {
                throw new DeptNotFoundException("Department not found: " + deptName);
            }
            
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally { 
            if (rs != null) {
                try { 
                    rs.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (pStmt != null) { 
                try { 
                    pStmt.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (conn != null) { 
                try { 
                    conn.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
        }
    }
    
    public static void printAllEmpsInDept(String deptName) {
        Connection conn = null;
        PreparedStatement pStmt = null;
        ResultSet rs = null;

        StringBuffer query = new StringBuffer();
        query.append("SELECT empno, ename, job, sal, NVL(comm, 0) AS comm ");
        query.append("FROM EMP0769 JOIN DEPT0769 USING (deptno) ");
        query.append("WHERE dname = ? ");
        query.append("ORDER BY empno");

        conn = getConnection(); 
        System.out.println("<사원정보>");
        System.out.println("사번\t    이름\t\t  직무\t\t  급여\t      수당");
        System.out.println("----------------------------------------------------------");
        try {                   
            pStmt = conn.prepareStatement(query.toString());
            pStmt.setString(1, deptName);
            rs = pStmt.executeQuery();
            while (rs.next()) {
                int empno = rs.getInt("empno");
                String ename = rs.getString("ename");
                String job = rs.getString("job");
                double sal = rs.getDouble("sal");
                double comm = rs.getDouble("comm");
                System.out.println(String.format("%d\t%8s\t%8s\t%7.2f\t%9.2f", empno, ename, job, sal, comm));
            }
            System.out.println();
            
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally { 
            if (rs != null) {
                try { 
                    rs.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (pStmt != null) { 
                try { 
                    pStmt.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (conn != null) { 
                try { 
                    conn.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
        }
        
    }
    
    public static int replaceManagerOfDept(String deptName, int newMgrNo, double newMgrComm) 
            throws EmpNotFoundException {
        Connection conn = null;
        PreparedStatement pStmt = null;
        ResultSet rs = null;
        int oldMgrNo = 0;

        conn = getConnection();

        StringBuffer selectQuery = new StringBuffer();
        selectQuery.append("SELECT manager ");
        selectQuery.append("FROM DEPT0769 ");
        selectQuery.append("WHERE dname = ? ");
        try {     
            // 기존 부서 관리자 사번 조회 (SELECT문 실행)
            pStmt = conn.prepareStatement(selectQuery.toString());
            pStmt.setString(1, deptName);
            rs = pStmt.executeQuery();
            if (rs.next()) {
                oldMgrNo = rs.getInt("manager");
            }
            rs.close(); 
            pStmt.close();
            
            // 기존 관리자 사원의 이름에서 "(M)" 삭제 (UPDATE문 실행)
            StringBuffer updateQuery = new StringBuffer();
            updateQuery.append("UPDATE EMP0769 ");
            updateQuery.append("SET ename = REPLACE(ename, '(M)', '') ");
            updateQuery.append("WHERE empno = ? ");
                
            pStmt = conn.prepareStatement(updateQuery.toString());
            pStmt.setInt(1, oldMgrNo);
            pStmt.executeUpdate();
            pStmt.close(); 
               
            // 새 관리자 사원의 이름과 수당 변경 (UPDATE문 실행)
            StringBuffer newQuery = new StringBuffer();
            newQuery.append("UPDATE EMP0769 ");
            newQuery.append("SET ename = ename || '(M)', comm = NVL(comm, 0) + ? ");
            newQuery.append("WHERE empno = ? ");
                
            pStmt = conn.prepareStatement(newQuery.toString());
            pStmt.setDouble(1, newMgrComm);
            pStmt.setInt(2, newMgrNo);
            int updateRow = pStmt.executeUpdate();
            if (updateRow == 0) {
                throw new EmpNotFoundException("Employee with empno " + newMgrNo + " not found.");
            }
            pStmt.close(); 
             
            // 부서의 관리자 변경 (UPDATE문 실행)
            StringBuffer manageQuery = new StringBuffer();
            manageQuery.append("UPDATE DEPT0769 ");
            manageQuery.append("SET manager = ? ");
            manageQuery.append("WHERE dname = ? ");
                
            pStmt = conn.prepareStatement(manageQuery.toString());
            pStmt.setInt(1, newMgrNo);
            pStmt.setString(2, deptName);
            pStmt.executeUpdate();
            pStmt.close(); 
             
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally { 
            if (rs != null) {
                try { 
                    rs.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (pStmt != null) { 
                try { 
                    pStmt.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (conn != null) { 
                try { 
                    conn.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
        }
        
        return oldMgrNo; 
    }
    
    public static void printEmpInfo(int empNo) {           
        Connection conn = null;
        PreparedStatement pStmt = null;
        ResultSet rs = null;
          
        StringBuffer query = new StringBuffer();
        query.append("SELECT empno, ename, job, hiredate, sal, NVL(comm, 0) AS comm, deptno ");
        query.append("FROM EMP0769 ");
        query.append("WHERE empno = ?");

        conn = getConnection();  
        try {                   
            pStmt = conn.prepareStatement(query.toString());
            pStmt.setInt(1, empNo);
            rs = pStmt.executeQuery();
            if (rs.next()) {
                int empno = rs.getInt("empno");
                String ename = rs.getString("ename");
                String job = rs.getString("job");
                //Date->String 변환
                Date sqlDate = rs.getDate("hiredate");
                LocalDate localDate = sqlDate.toLocalDate();
                DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
                String hiredate = localDate.format(formatter); 
                double sal = rs.getDouble("sal");
                double comm = rs.getDouble("comm");
                int deptno = rs.getInt("deptno");
                
                System.out.println(String.format("%d %s %s %s %.2f %.2f %d", empno, ename, job, hiredate, sal, comm, deptno));
            }
            
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally { 
            if (rs != null) {
                try { 
                    rs.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (pStmt != null) { 
                try { 
                    pStmt.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
            if (conn != null) { 
                try { 
                    conn.close(); 
                } catch (SQLException ex) { ex.printStackTrace(); }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);   
        
        System.out.print("부서명을 입력하시오: ");
        String deptName = scanner.next();
        System.out.println();
     
        try {
            // 입력된 부서명 이용 printDeptInfo 호출
            printDeptInfo(deptName);
            // 입력된 부서명 이용 printAllEmpsInDept 호출
            printAllEmpsInDept(deptName);
            
            System.out.print("새 관리자 사번과 보직수당을 입력하시오: ");
            int managerNo  = scanner.nextInt();
            double commission = scanner.nextDouble();
                
            // 입력된 값들을 이용 replaceManagerOfDept 호출 (기존 관리자 사번 반환)
            int oldMgrNo = replaceManagerOfDept(deptName, managerNo, commission);
            System.out.println("<기존 관리자>");     
            // 기존 관리자 사번에 대해 printEmpInfo 호출      
            printEmpInfo(oldMgrNo);
            System.out.println("<새 관리자>");
            // 새 관리자 사번에 대해 printEmpInfo 호출      
            printEmpInfo(managerNo);
        } catch (Exception ex) {  // (DeptNotFoundException | EmpNotFoundException ex) {
            ex.printStackTrace();
        }    
        scanner.close();
    }
}
