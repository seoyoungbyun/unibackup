
public class Pracitce29 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student p1 = new Student("김동덕", 20132468, "컴퓨터학");
		Student p2 = new Student("홍길동", 20111234);
		Student p3 = new Student();
		
		p1.setAge(22);
		p1.setAddress("서울시");
		
		p2.setAge(30);
		p2.setAddress("제주시");
		p2.setMajor("컴퓨터학");
		
		p3.setName("성춘향");
		p3.setAge(16);
		p3.setAddress("남원시");
		p3.setSid(20121357);
		p3.setMajor("국문학");
		
		String rslt = p1.toString();
		System.out.println(rslt);
		rslt = p2.toString();
		System.out.println(rslt);
		rslt = p3.toString();
		System.out.println(rslt);
		
		rslt = p1.printSafely();
		System.out.println(rslt);
		rslt = p2.printSafely();
		System.out.println(rslt);
		rslt = p3.printSafely();
		System.out.print(rslt);
	}

}
