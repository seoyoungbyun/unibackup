import java.util.Scanner;

public class Practice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int f;
		double c;
		
		System.out.print("화씨 온도를 입력하세요: ");
		f = sc.nextInt();
		
		c = (double)5/9 * (f - 32);
		System.out.println("해당하는 섭씨 온도는 " + String.format("%.2f", c) + "입니다.");
		sc.close();
	}

}
