package lab4;

import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Lab4 {
   
	private static CompanyDao compDao = new CompanyDao();
    
	public static void main(String[] args) {		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("부서명을 입력하시오: ");
		String deptName = scanner.next();
        System.out.println();
		
	    Department dept = compDao.findDeptByName(deptName);
        // dept 객체의 필드 값 출력 (주의: dept 객체가 반환되었는지 확인 필요)
	    if (dept != null) {
    	    System.out.println("<부서정보>");
            System.out.println("부서번호: " + dept.getDeptNo());
            System.out.println("부서명: " + deptName);
            System.out.println("관리자사번: " + dept.getMgrNo());
            System.out.println("사원 수: " + dept.getNumOfEmps());
            System.out.println();
	    }
	    else {
	        System.out.println("error!");
	    }
		
	    System.out.println("<사원정보>");
	    System.out.println("사번        이름           직무          급여         수당");
        System.out.println("------------------------------------------------------");
	    List<Employee> empList = compDao.getAllEmpsInDept(dept.getDeptNo());
        // empList에 포함된 모든 Employee 객체들의 필드 값을 출력: 
        //   Employee 객체들을 하나씩 접근하기 위해 empList로부터 Iterator를 구해서 활용
	    Iterator<Employee> iter = empList.iterator();
	    while (iter.hasNext()) {
	        Employee emp = iter.next();
	        System.out.printf("%d %10s %15s %10.2f %10.2f\n", emp.getEmpNo(), emp.getEmpName(), emp.getJob(), emp.getSal(), emp.getComm());
	    }
	    System.out.println();

		System.out.print("새 관리자 사번과 관리자 보직수당을 입력하시오: ");
		int managerNo  = scanner.nextInt();
		double commission = scanner.nextDouble();
        System.out.println();
		
		// 관리자 교체를 위한 DTO 객체 생성
        Appointment appo = new Appointment(dept.getDeptNo(), managerNo, commission);   
	    Employee oldMgr = compDao.replaceManagerOfDept(appo);	 
		      
        System.out.println("<기존 관리자>");     
		// 반환된 oldMgr 객체의 필드 값 출력 
        System.out.println(oldMgr.toString());
		
        Employee newMgr = compDao.findEmployee(managerNo);
        
        System.out.println("<새 관리자>");         
	    // 반환된 newMgr 객체의 필드 값 출력 
        System.out.println(newMgr.toString());
        
		scanner.close();
	}
}