import java.util.Scanner;

public class Practice35 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int x, y;
		
		System.out.print("1번째 순서쌍 x좌표: ");
		x = sc.nextInt();
		System.out.print("1번째 순서쌍 y좌표: ");
		y = sc.nextInt();
		Pair p1 = new Pair(x, y);
		
		System.out.print("2번째 순서쌍 x좌표: ");
		x = sc.nextInt();
		System.out.print("2번째 순서쌍 y좌표: ");
		y = sc.nextInt();
		Pair p2 = new Pair(x, y);
		
		System.out.print("입력된 1번 순서쌍: ");
		String s = p1.toString();
		System.out.println(s);
		System.out.print("입력된 2번 순서쌍: ");
		s = p2.toString();
		System.out.println(s);
		
		Pair add = Pair.add(p1, p2);
		Pair sub = Pair.sub(p1, p2);
		Pair mult = Pair.mult(p1, p2);
		Pair div = Pair.div(p1, p2);
		
		System.out.print("덧셈 결과: ");
		s = add.toString();
		System.out.println(s);
		System.out.print("뺄셈 결과: ");
		s = sub.toString();
		System.out.println(s);
		System.out.print("곱셈 결과: ");
		s = mult.toString();
		System.out.println(s);
		System.out.print("나눗셈 결과: ");
		s = div.toString();
		System.out.println(s);
		
		sc.close();
	}

}
