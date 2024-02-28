import java.util.Scanner;

public class Practice14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		System.out.print("컴퓨터의 생성: ");
		String computer = sc.next();
		while (!(computer.equals("가위") || computer.equals("바위") || computer.equals("보")))
		{
			System.out.println("잘못된 입력입니다. 다시 입력하세요");
			System.out.print("컴퓨터의 생성: ");
			computer = sc.next();
		}
		
		System.out.print("당신의 입력: ");
		String me = sc.next();
		while (!(me.equals("가위") || me.equals("바위") || me.equals("보"))) {
			System.out.println("잘못된 입력입니다. 다시 입력하세요");
			System.out.print("당신의 입력: ");
			me = sc.next();
		}
		
		if (me.equals(computer)) {
			System.out.println("비겼습니다.");
		}
		else if (me.equals("가위")) {
			if (computer.equals("바위")) {
				System.out.println("컴퓨터가 이겼습니다.");
			}
			else{
				System.out.println("당신이 이겼습니다.");
			}
		}
		else if (me.equals("바위")) {
			if (computer.equals("보")) {
				System.out.println("컴퓨터가 이겼습니다.");
			}
			else{
				System.out.println("당신이 이겼습니다.");
			}
		}
		else {
			if (computer.equals("가위")) {
				System.out.println("컴퓨터가 이겼습니다.");
			}
			else{
				System.out.println("당신이 이겼습니다.");
			}
		}
		
		sc.close();
	}

}