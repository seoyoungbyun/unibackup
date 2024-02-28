
public class Practice39 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = new Student("홍길동", 20111234, "컴퓨터학");
		Student s2 = new Student("성춘향", 20121357, "국문학");
		Student s3 = new Student("이몽룡", 20101357, "컴퓨터학");
		
		System.out.println("1번 학생의 정보");
		String s = s1.printSafely();
		System.out.println(s);
		System.out.println("2번 학생의 정보");
		s = s2.printSafely();
		System.out.println(s);
		System.out.println("3번 학생의 정보");
		s = s3.printSafely();
		System.out.println(s);
		
		String n1 = s1.getName();
		String n2 = s2.getName();
		String n3 = s3.getName();
		
		boolean equals = s1.equalsMajor(s2);
		int sid = s1.isSenior(s2);
		String rslt = "\n\"" + n1 + "\"학생은 \"" + n2 + "\"학생과 ";
		if (equals) {
			rslt += "전공은 같고, ";
			if (sid == 1) {
				rslt += "학번은 느립니다.";
			}
			else if (sid ==0) {
				rslt += "학번도 같습니다.";
			}
			else {
				rslt += "학번은 빠릅니다.";
			}
		}
		else {
			rslt += "전공은 다르고, ";
			if (sid == 1) {
				rslt += "학번은 느립니다.";
			}
			else if (sid ==0) {
				rslt += "학번은 같습니다.";
			}
			else {
				rslt += "학번은 빠릅니다.";
			}
		}
		System.out.println(rslt);
		
		equals = s1.equalsMajor(s3);
		sid = s1.isSenior(s3);
		rslt = "\"" + n1 + "\"학생은 \"" + n3 + "\"학생과 ";
		if (equals) {
			rslt += "전공은 같고, ";
			if (sid == 1) {
				rslt += "학번은 느립니다.";
			}
			else if (sid ==0) {
				rslt += "학번도 같습니다.";
			}
			else {
				rslt += "학번은 빠릅니다.";
			}
		}
		else {
			rslt += "전공은 다르고, ";
			if (sid == 1) {
				rslt += "학번은 느립니다.";
			}
			else if (sid ==0) {
				rslt += "학번은 같습니다.";
			}
			else {
				rslt += "학번은 빠릅니다.";
			}
		}
		System.out.print(rslt);
	}

}
