
public class Practice28 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person p1 = new Person("김동덕", 22, "서울시");
		Person p2 = new Person("홍길동", 30);
		Person p3 = new Person("성춘향");
		
		p2.setAddress("제주시");
		
		p3.setAge(16);
		p3.setAddress("남원시");
		
		String rslt = p1.toString();
		System.out.println(rslt);
		rslt = p2.toString();
		System.out.println(rslt);
		rslt = p3.toString();
		System.out.print(rslt);
	}

}
