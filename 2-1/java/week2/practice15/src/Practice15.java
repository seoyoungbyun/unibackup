import java.util.Scanner;

public class Practice15 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("컴퓨터의 생성: ");
		String computer = sc.next();
		System.out.print("당신의 입력: ");
		String me = sc.next();
		
		int win = whoswin(computer, me);
		if (win == 0) {
			System.out.println("비겼습니다.");
		}
		else if (win == 1) {
			System.out.println("당신이 이겼습니다.");
		}
		else {
				System.out.println("컴퓨터가 이겼습니다.");
		}
		
		sc.close();
	}
	
	public static int whoswin(String com, String you) {
		if (you.equals(com)) {
			return 0;
		}
		else if (you.equals("가위")) {
			if (com.equals("바위")) {
				return -1;
			}
			else{
				return 1;
			}
		}
		else if (you.equals("바위")) {
			if (com.equals("보")) {
				return -1;
			}
			else{
				return 1;
			}
		}
		else {
			if (com.equals("가위")) {
				return -1;
			}
			else{
				return 1;
			}
		}
	}

}