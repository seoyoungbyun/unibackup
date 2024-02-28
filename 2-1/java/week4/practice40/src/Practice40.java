import java.util.Scanner;

public class Practice40 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num, sid;
		String name, major;
		
		System.out.print("학생 숫자를 입력하세요: ");
		num = sc.nextInt();
		Student[] stuList = new Student[num];
		
		for (int i = 0; i < num; i++) {
			System.out.println((i + 1) + "번 학생의 정보");
			System.out.print("이름: ");
			name = sc.next();
			System.out.print("학번: ");
			sid = sc.nextInt();
			System.out.print("전공: ");
			major = sc.next();
			
			stuList[i] = new Student(name, sid, major);
		}
		
		System.out.println("\n입력된 학생의 정보입니다.");
		for (int i = 0; i < num; i++) {
			String rslt = stuList[i].printSafely();
			System.out.println("[" + (i + 1) + "]" + rslt);
		}
		
		System.out.println();
		for (int i = 1; i < num; i++) {
			boolean equals = stuList[0].equalsMajor(stuList[i]);
			int isSid = stuList[0].isSenior(stuList[i]);
			
			String n1 = stuList[0].getName();
			String n2 = stuList[i].getName();
			
			String rslt = "\"" + n1 + "\"학생은 \"" + n2 + "\"학생과 ";
			if (equals) {
				rslt += "전공은 같고, ";
				if (isSid == 1) {
					rslt += "학번은 느립니다.";
				}
				else if (isSid ==0) {
					rslt += "학번도 같습니다.";
				}
				else {
					rslt += "학번은 빠릅니다.";
				}
			}
			else {
				rslt += "전공은 다르고, ";
				if (isSid == 1) {
					rslt += "학번은 느립니다.";
				}
				else if (isSid ==0) {
					rslt += "학번은 같습니다.";
				}
				else {
					rslt += "학번은 빠릅니다.";
				}
			}
			System.out.println(rslt);
		}
		sc.close();
	}

}
