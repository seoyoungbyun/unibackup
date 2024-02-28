
public class Student extends Person{
	private long sid;
	private String major;
	
	Student(){
		super();
		sid = -1;
		major = "모름";
	}
	Student(String name){
		super(name);
		sid = -1;
		major = "모름";
	}
	Student(String name, long sid){
		super(name);
		this.sid = sid;
		major = "모름";
	}
	Student(String name, long sid, String major){
		super(name);
		this.sid = sid;
		this.major = major;
	}
	
	public long getSid() {
		return sid;
	}
	public void setSid(long sid) {
		this.sid = sid;
	}
	public String getMajor() {
		return major;
	}
	public void setMajor(String major) {
		this.major = major;
	}
	
	public String toString() {
		String rslt = super.toString();
		rslt += ", 학번:" + sid + ", 전공:" + major;
		
		return rslt;
	}
	
	public String printSafely() {
		String name = super.getName();
		
		String rslt = "이름:" + name + ", 학번:" + sid + ", 전공:" + major;
		
		return rslt;
	}
	
	public int isSenior(Student s) {
		long you = s.getSid();
		if (sid < you) {
			return -1;
		}
		else if (sid == you) {
			return 0;
		}
		else {
			return 1;
		}
	}
	public boolean equalsMajor(Student s) {
		String you = s.getMajor();
		
		if (you.equals(major)) {
			return true;
		}
		else {
			return false;
		}
	}
}
