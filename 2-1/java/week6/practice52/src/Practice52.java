import java.util.Scanner;

public class Practice52 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Shape arr[] = new Shape[3];
		int x, y, dx, dy;
		double w, h;
		
		x = sc.nextInt();
		y = sc.nextInt();
		arr[0] = new Shape(x, y);
		
		x = sc.nextInt();
		y = sc.nextInt();
		w = sc.nextDouble();
		h = sc.nextDouble();
		arr[1] = new Rectangle(x, y, w, h);
		
		x = sc.nextInt();
		y = sc.nextInt();
		w = sc.nextDouble();
		h = sc.nextDouble();
		arr[2] = new Triangle(x, y, w, h);
		
		String rslt;
		System.out.println("입력된 정보입니다.");
		for (int i = 0; i < arr.length; i++) {
			System.out.print((i + 1) + ": ");
			rslt = arr[i].toString();
			System.out.print(rslt);
		}
		
		dx = sc.nextInt();
		dy = sc.nextInt();
		
		System.out.println("이동 후의 정보입니다.");
		
		for (int i = 0; i < arr.length; i++) {
			arr[i].move(dx, dy);
			System.out.print((i + 1) + ": ");
			rslt = arr[i].toString();
			System.out.print(arr[i]);
		}
		
		sc.close();
	}

}
