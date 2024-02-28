import java.util.Scanner;

public class Practice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		double inch;
		
		System.out.print("인치 값을 입력하세요: ");
		inch = sc.nextDouble();
		int centimeter = (int)(2.54 * inch);
		System.out.println("해당하는 센티미터 값은 " + centimeter + "입니다.");
		
		sc.close();
	}

}
