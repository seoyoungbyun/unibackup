import java.util.Scanner;

public class Practice30 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BodyData me = new BodyData();
		BodyData you = new BodyData();
		int m, y;
		
		System.out.print("내 키를 입력하세요: ");
		m = sc.nextInt();
		me.setHeight(m);
		System.out.print("내 몸무게를 입력하세요: ");
		m = sc.nextInt();
		me.setWeight(m);
		
		System.out.print("당신의 키를 입력하세요: ");
		y = sc.nextInt();
		you.setHeight(y);
		System.out.print("당신의 몸무게를 입력하세요: ");
		y = sc.nextInt();
		you.setWeight(y);
		
		boolean tall = me.isTallerThan(you);
		if (tall) {
			m = me.getHeight();
			y = you.getHeight();
			if (m > y) {
				System.out.println("키는 내가 더 큽니다.");
			}
			else {
				System.out.println("나와 당신의 키는 같습니다.");
			}
		}
		else {
			System.out.println("키는 당신이 더 큽니다.");
		}
		
		boolean diet = me.needDiet();
		if (diet) {
			System.out.println("나는 다이어트가 필요합니다.");
		}
		else {
			System.out.println("나는 다이어트가 필요하지 않습니다.");
		}
		
		diet = you.needDiet();
		if (diet) {
			System.out.print("당신은 다이어트가 필요합니다.");
		}
		else {
			System.out.print("당신은 다이어트가 필요하지 않습니다.");
		}
		
		sc.close();
	}

}
