import java.util.Scanner;

public class Practice5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num, renum;
		
		System.out.print("정수를 입력하세요: ");
		num = sc.nextInt();
		
		if (num < 0) {
			renum = num * -1;
		}
		else {
			renum = num;
		}
		
		System.out.println("입력한 정수 " + num + "의 절대값은 " + renum + "입니다.");
		sc.close();
	}

}
