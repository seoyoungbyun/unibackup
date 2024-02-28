import java.util.Scanner;

public class Practice49 {

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
		
		System.out.println("입력된 정보입니다.");
		String rslt = s.toString();
		System.out.print(rslt);
		r.draw();
		t.draw();
		
		dx = sc.nextInt();
		dy = sc.nextInt();
		
		System.out.println("입력된 도형의 정보");
		s.move(dx, dy);
		rslt = s.toString();
		System.out.print(rslt);
		r.move(dx, dy);
		r.draw();
		t.move(dx, dy);
		t.draw();
		
		sc.close();
	}

}