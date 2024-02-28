import java.util.Scanner;

public class Practice75 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        Point p = new Point();
        
        Circle c1 = new Circle();
        System.out.println("첫번째 원 c1의 정보입니다.");
        String rslt = c1.toString();
        System.out.println(rslt);
        
        System.out.println("두번째 원 c2의 정보를 입력받습니다.");
        System.out.print("중심좌표의 X값을 입력하세요: ");
        int x = sc.nextInt();
        System.out.print("중심좌표의 Y값을 입력하세요: ");
        int y = sc.nextInt();
        System.out.print("반지름 값을 입력하세요: ");
        int r = sc.nextInt();
        
        Circle c2 = new Circle(x, y, r);
        System.out.println("두번째 원 c2의 정보입니다.");
        rslt = c2.toString();
        System.out.println(rslt);
        
        p.setX(60);
        p.setY(70);
        Circle c3 = new Circle(p, 80);
        System.out.println("세번째 원 c3의 정보입니다.");
        rslt = c3.toString();
        System.out.println(rslt);
        
        System.out.println("네번째 원 c4의 정보를 입력받습니다.");
        System.out.print("중심좌표의 X값을 입력하세요: ");
        x = sc.nextInt();
        System.out.print("중심좌표의 Y값을 입력하세요: ");
        y = sc.nextInt();
        System.out.print("반지름 값을 입력하세요: ");
        r = sc.nextInt();
        
        p.setX(x);
        p.setY(y);
        Circle c4 = new Circle(p, r);
        System.out.println("네번째 원 c4의 정보입니다.");
        rslt = c4.toString();
        System.out.println(rslt);
        
        System.out.println("첫번째 원 c1의 정보입니다.");
        rslt = c1.toString();
        System.out.println(rslt);
        System.out.println("두번째 원 c2의 정보입니다.");
        rslt = c2.toString();
        System.out.println(rslt);
        System.out.println("세번째 원 c3의 정보입니다.");
        rslt = c3.toString();
        System.out.println(rslt);
        System.out.println("네번째 원 c4의 정보입니다.");
        rslt = c4.toString();
        System.out.println(rslt);
        
        sc.close();
    }
}
