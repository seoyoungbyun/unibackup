import java.util.Scanner;

public class Practice16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int win = 0, lose = 0, same = 0;
		
		System.out.println("현재 당신의 전적: " + win + "승 " + lose + "패 " + same + "무");
		System.out.print("컴퓨터의 생성: ");
		String computer = sc.next();
		System.out.print("당신의 입력(가위/바위/보/그만): ");
		String me = sc.next();
		
		int whowin = whoswin(computer, me);
		while(!(me.equals("그만")))
		{
			if (whowin == 0) {
				System.out.println("비겼습니다.");
				same++;
			}
			else if (whowin == 1) {
				System.out.println("당신이 이겼습니다.");
				win++;
			}
			else {
					System.out.println("컴퓨터가 이겼습니다.");
					lose++;
			}
			
			System.out.println("현재 당신의 전적: " + win + "승 " + lose + "패 " + same + "무");
			System.out.print("컴퓨터의 생성: ");
			computer = sc.next();
			System.out.print("당신의 입력(가위/바위/보/그만): ");
			me = sc.next();
			
			whowin = whoswin(computer, me);
		}
		System.out.println("프로그램을 종료합니다.");
		
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
