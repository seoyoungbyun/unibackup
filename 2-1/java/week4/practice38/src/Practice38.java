import java.util.Scanner;

public class Practice38 {

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
		
		Date earlist = dateList[0];
		int index = 1;
		for (int i = 1; i < dateList.length; i++) {
			int compare = Date.compareDate(earlist, dateList[i]);
			
			if (compare == 1) {
				earlist = dateList[i];
				index = i + 1;
			}
		}
		
		String rslt = earlist.toString();
		System.out.print("\n가장 빠른 날짜는 " + index + "번째 입력된 " + rslt + "입니다.");
		
		sc.close();
	}

}
