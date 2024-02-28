import java.util.Scanner;

public class Practice12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num, count = 0;
		
		System.out.print("정수를 입력하세요: ");
		num = sc.nextInt();
		while(num <= 0) {
			System.out.println("잘못된 입력입니다. 다시 입력하세요.");
			System.out.print("정수를 입력하세요: ");
			num = sc.nextInt();
		}
		
		for (int i = 1; i <= num; i++) {
			if (i % 5 == 0) {
				continue;
			}
			System.out.print(i + "\t");
			count++;
			
			if (count == 7) {
				System.out.println();
			}
		}
		
		sc.close();
	}

}
