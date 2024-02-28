import java.util.Scanner;

public class Practice36 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Date[] dateList = new Date[5];
		int y, m, d;
		
		for (int i = 0; i < dateList.length; i++) {
			System.out.print((i + 1) + "번째 날짜를 입력하세요: ");
			y = sc.nextInt();
			m = sc.nextInt();
			d = sc.nextInt();
			
			dateList[i] = new Date(y, m, d);
		}
		
		for (int i = 0; i < dateList.length; i++) {
			String date = dateList[i].toString();
			
			System.out.println((i + 1) + "번째 날짜는 " + date + "입니다.");
		}
		
		sc.close();
	}

}
