
public class Practice47 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Dog myDog = new Dog();
		Person p1 = new Person("김동덕", 1);
		Person p2 = new Person("홍길동", 20);
		
		speak3Times(myDog);
		speak3Times(p1);
		speak3Times(p2);
	}
	
	private static void speak3Times(Dog d) {
		d.speak();
		d.speak();
		d.speak();
	}

	private static void speak3Times(Person p) {
		p.speak();
		p.speak();
		p.speak();
	}
}
