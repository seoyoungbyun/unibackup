import java.util.Scanner;

public class Practice32 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int w, h;
		
		System.out.print("사각형1의 가로를 입력: ");
		w = sc.nextInt();
		System.out.print("사각형1의 세로를 입력: ");
		h = sc.nextInt();
		Square s1 = Square.getInstance(w, h);
		
		System.out.print("사각형2의 가로를 입력: ");
		w = sc.nextInt();
		System.out.print("사각형2의 세로를 입력: ");
		h = sc.nextInt();
		Square s2 = Square.getInstance(w, h);
		
		boolean small1 = s1.isSmallerThan(s2);
		if (small1) {
			System.out.print("사각형1의 넓이가 더 작습니다.");
		}
		else {
			boolean small2 = s2.isSmallerThan(s1);
			if (small2) {
				System.out.print("사각형2의 넓이가 더 작습니다.");
			}
			else {
				System.out.print("두 사각형의 넓이가 같습니다.");
			}
		}
		
		sc.close();
	}

}