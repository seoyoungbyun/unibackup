import java.util.Scanner;

public class Practice9 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num, sum = 0;
		
		System.out.print("숫자를 입력하세요: ");
		num = sc.nextInt();
		while (num != 0) {
			if (num < 0) {
				System.out.println("음수가 입력되었습니다. 다시 입력하세요");
			}
			else {
				sum += num;
			}
			System.out.print("숫자를 입력하세요: ");
			num = sc.nextInt();
		}
		
		System.out.println("입력된 숫자들의 합은 " + sum + "입니다.");
		sc.close();
	}

}
