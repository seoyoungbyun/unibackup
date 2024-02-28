import java.util.Scanner;

public class Practice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num;
		
		System.out.print("정수를 입력하세요: ");
		num = sc.nextInt();
		
		if (num < 0) {
			System.out.println("입력한 정수 " + num + "은 음수입니다.");
		}
		else if (num % 2 == 0) {
			System.out.println("입력한 정수 " + num + "은 짝수입니다.");
		}
		else {
			System.out.println("입력한 정수 " + num + "은 홀수입니다.");
		}
		
		sc.close();
	}

}
