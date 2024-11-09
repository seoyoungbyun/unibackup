package lab4;

import java.sql.Date;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Employee {
    // 필드: 사번, 이름, 직무, 입사일, 월급, 수당, 소속부서명 
    private int empNo;
    private String empName;
    private String job;
    private Date hiredate;
    private double sal;
    private double comm;
    private String deptName;
    
    // default 생성자와, 위 필드들에 대한 getter & setter method 정의
    public Employee() {}
    
    public int getEmpNo() {
        return empNo;
    }
    public void setEmpNo(int empNo) {
        this.empNo = empNo;
    }
    public String getEmpName() {
        return empName;
    }
    public void setEmpName(String empName) {
        this.empName = empName;
    }
    public String getJob() {
        return job;
    }
    public void setJob(String job) {
        this.job = job;
    }
    public Date getHiredate() {
        return hiredate;
    }
    public void setHiredate(Date hiredate) {
        this.hiredate = hiredate;
    }
    public double getSal() {
        return sal;
    }
    public void setSal(double sal) {
        this.sal = sal;
    }
    public double getComm() {
        return comm;
    }
    public void setComm(double comm) {
        this.comm = comm;
    }
    public String getDeptName() {
        return deptName;
    }
    public void setDeptName(String deptName) {
        this.deptName = deptName;
    }
    
    // 위 필드들을 초기화하는 생성자를 정의해서 활용 가능 
    public Employee(int empNo, String empName, String job, Date hiredate, double sal, double comm, String deptName) {
        super();
        this.empNo = empNo;
        this.empName = empName;
        this.job = job;
        this.hiredate = hiredate;
        this.sal = sal;
        this.comm = comm;
        this.deptName = deptName;
    }
    
    // 모든 필드 값들을 출력하기 위한 toString() 정의 (Source > Generate toString() 메뉴 이용)
    @Override
    public String toString() {
        LocalDate localDate = this.hiredate.toLocalDate();   
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        String hireDate = localDate.format(formatter);
        
        return String.format("%d %s %s %s %.2f %.2f %s", empNo, empName, job, hireDate, sal, comm, deptName);
    }

}
