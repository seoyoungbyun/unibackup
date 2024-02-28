import java.util.Scanner;

public class Practice48 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int x, y, dx, dy;
		double w, h;
		
		System.out.println("test");
		x = sc.nextInt();
		y = sc.nextInt();
		Shape s = new Shape(x, y);
		
		x = sc.nextInt();
		y = sc.nextInt();
		w = sc.nextDouble();
		h = sc.nextDouble();
		Rectangle r = new Rectangle(x, y, w, h);
		
		x = sc.nextInt();
		y = sc.nextInt();
		w = sc.nextDouble();
		h = sc.nextDouble();
		Triangle t = new Triangle(x, y, w, h);
		
		System.out.println("입력된 도형의 정보입니다.");
		System.out.println(s);
		System.out.println("입력된 사각형의 정보입니다.");
		System.out.println(r);
		System.out.println("입력된 삼각형의 정보입니다.");
		System.out.println(t);
		
		dx = sc.nextInt();
		dy = sc.nextInt();
		
		System.out.println("입력된 도형의 정보입니다.");
		s.move(dx, dy);
		System.out.println(s);
		System.out.println("입력된 사각형의 정보입니다.");
		r.move(dx, dy);
		System.out.println(r);
		System.out.println("입력된 삼각형의 정보입니다.");
		t.move(dx, dy);
		System.out.println(t);
		
		sc.close();
	}

}
