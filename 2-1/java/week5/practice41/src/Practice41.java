import java.util.Scanner;

public class Practice41 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int x, y;
		double length, height;
		
		System.out.println("test");
		x = sc.nextInt();
		y = sc.nextInt();
		Shape s = new Shape(x, y);
		
		x = sc.nextInt();
		y = sc.nextInt();
		length = sc.nextDouble();
		height = sc.nextDouble();
		Rectangle r = new Rectangle(x, y, length, height);
		
		x = sc.nextInt();
		y = sc.nextInt();
		length = sc.nextDouble();
		height = sc.nextDouble();
		Triangle t = new Triangle(x, y, length, height);
		
		System.out.println("입력된 도형의 정보입니다.");
		System.out.println(s);
		System.out.println("입력된 사각형의 정보입니다.");
		System.out.println(r);
		System.out.println("입력된 삼각형의 정보입니다.");
		System.out.println(t);
		
		sc.close();
	}

}
