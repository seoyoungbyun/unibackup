//20220769 컴퓨터학과 변서영
import java.util.Scanner;

public class Practice55 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		boolean isDone = false;
		int num1 = 0, num2 = 0;
		
		while(isDone != true) {
			try {
				String n1 = sc.next();
				num1 = Integer.parseInt(n1);
			}catch(NumberFormatException e) {
				System.out.println("잘못된 형식의 숫자입니다. 다시 입력하세요.");
				continue;
			}
			isDone = true;
		}
		
		isDone = false;
		while(isDone != true) {
			try {
				String n2 = sc.next();
				num2 = Integer.parseInt(n2);
			}catch(NumberFormatException e) {
				System.out.println("잘못된 형식의 숫자입니다. 다시 입력하세요.");
				continue;
			}
			isDone = true;
		}
		
		int sum = num1 + num2;
		System.out.println(num1 + " + " + num2 + " = " + sum);
		
		sc.close();
	}

}
