import java.util.Scanner;

public class Practice44 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int id, tuition, year;
		double gpa;
		String lab;
		
		id = sc.nextInt();
		tuition = sc.nextInt();
		gpa = sc.nextDouble();
		Student s1 = new Student(id, tuition, gpa);
		
		id = sc.nextInt();
		tuition = sc.nextInt();
		gpa = sc.nextDouble();
		year = sc.nextInt();
		UndergraduateStudent s2 = new UndergraduateStudent(id, tuition, gpa, year);
		
		id = sc.nextInt();
		tuition = sc.nextInt();
		gpa = sc.nextDouble();
		lab = sc.next();
		GraduateStudent s3 = new GraduateStudent(id, tuition, gpa, lab);
		
		System.out.println("입력된 정보입니다.");
		String s = s1.toString();
		System.out.println(s);
		s = s2.toString();
		System.out.println(s);
		s = s3.toString();
		System.out.println(s);
		
		sc.close();
	}

}
