import java.util.Scanner;

public class Practice45 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n;
		
		n = sc.nextInt();
		Student[] arr = new Student[n];
		
		int id, tuition, year;
		double gpa;
		String lab;
		
		for (int i = 0; i < arr.length; i++) {
			n = sc.nextInt();
			
			id = sc.nextInt();
			tuition = sc.nextInt();
			gpa = sc.nextDouble();
			
			if (n == 1) {
				Student s1 = new Student(id, tuition, gpa);
				arr[i] = s1;
			}
			else if (n == 2) {
				year = sc.nextInt();
				Student s2 = new UndergraduateStudent(id, tuition, gpa, year);
				arr[i] = s2;
			}
			else {
				lab = sc.next();
				Student s3 = new GraduateStudent(id, tuition, gpa, lab);
				arr[i] = s3;
			}
		}
		System.out.println("입력된 정보입니다.");
		printAll(arr);
		sc.close();
	}
	
	public static void printAll(Student[] s) {
		String rslt = "";
		for (int i = 0; i < s.length; i++) {
			rslt += s[i].toString() + "\n";
		}
		
		System.out.print(rslt);
	}

}
