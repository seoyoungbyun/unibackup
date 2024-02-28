import java.util.Scanner;

public class Practice11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num;
		boolean isPrime = true;
		
		System.out.print("숫자를 입력하세요: ");
		num = sc.nextInt();
		while(num <= 0) {
			System.out.println("잘못된 입력입니다. 다시 입력하세요.");
			System.out.print("숫자를 입력하세요: ");
			num = sc.nextInt();
		}
		
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				isPrime = false;
				break;
			}
		}
		
		if (isPrime) {
			System.out.println("입력된 숫자 " + num + "은 소수입니다.");
		}
		else {
			System.out.println("입력된 숫자 " + num + "은 소수가 아닙니다.");
		}
		
		sc.close();
	}
}
