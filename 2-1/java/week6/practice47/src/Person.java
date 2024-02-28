
public class Person implements Speakable{
	public int age;
	public String name;
	
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public void speak() {
		if (age >= 2) {
			System.out.println("안녕");
		}
		else {
			System.out.println("응애");
		}
	}
}
