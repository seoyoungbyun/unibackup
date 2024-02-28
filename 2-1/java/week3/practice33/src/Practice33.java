
public class Practice33 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student p1 = new Student("홍길동", 20111234, "컴퓨터학");
		Student p2 = new Student("성춘향", 20121357, "국문학");
		Student p3 = new Student("성춘향", 20121357, "국문학");
		Student p4 = p1;
		
		System.out.println("객체 p1의 정보");
		System.out.println(p1.printSafely());
		System.out.println("객체 p2의 정보");
		System.out.println(p2.printSafely());
		System.out.println("객체 p3의 정보");
		System.out.println(p2.printSafely());
		System.out.println("객체 p4의 정보");
		System.out.println(p4.printSafely());
		
		printInfo(p1, p2);
		printInfo(p2, p2);
		printInfo(p2, p3);
		printInfo(p1, p4);
	}
	
	public static void printInfo(Student sa, Student sb) {
		long asid = sa.getSid();
		long bsid = sb.getSid();
		
		if (sa == sb) {
			System.out.println("같은 객체");
		}
		else if (asid == bsid) {
			System.out.println("다른 객체/같은 학번");
		}
		else {
			System.out.println("다른 객체/다른 학번");
		}
	}
}
