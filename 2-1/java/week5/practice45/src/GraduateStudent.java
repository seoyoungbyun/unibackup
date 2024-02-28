
public class GraduateStudent extends Student{
	private String lab;
	
	public GraduateStudent(int id, int tuition, double gpa, String lab) {
		super(id, tuition, gpa);
		this.lab = lab;
	}
	
	public String getLab() {
		return lab;
	}
	public void setLab(String lab) {
		this.lab = lab;
	}
	
	public String toString() {
		return super.toString() + ", 연구실:" + lab;
	}
	public int scholarship() {
		double gpa = super.getGpa();
		int scholarship;
		
		if (gpa >= 3.5) {
			scholarship = super.scholarship();
			return scholarship;
		}
		else {
			scholarship = (int)(super.getTuition() * 0.1);
			return scholarship;
		}
	}
}