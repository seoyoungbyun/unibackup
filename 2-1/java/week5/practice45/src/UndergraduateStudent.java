
public class UndergraduateStudent extends Student{
	private int year;
	
	public UndergraduateStudent(int id, int tuition, double gpa, int year) {
		super(id, tuition, gpa);
		this.year = year;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	
	public String toString() {
		String rslt = super.toString();
		
		rslt += ", 학년:" + year;
		
		return rslt;
	}
	public int scholarship() {
		int tuition = super.getTuition();
		
		return (int)(tuition * 0.3);
	}
}
