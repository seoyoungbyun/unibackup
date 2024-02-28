
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
		super(name, -1);
		this.sid = sid;
		major = "모름";
	}
	Student(String name, long sid, String major){
		super(name, -1, "모름");
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
		long sid = getSid();
		String major = getMajor();
		
		rslt += ", 학번:" + sid + ", 전공:" + major;
		
		return rslt;
	}
	
	public String printSafely() {
		String name = super.getName();
		
		String rslt = "이름:" + name + ", 학번:" + sid + ", 전공:" + major;
		
		return rslt;
	}
}
