
public class Practice34 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Date d1 = new Date(2007, 2, 18);
		Date d2 = new Date(2006, 3, 2);
		Date d3 = new Date(2007, 2, 27);
		Date d4 = new Date(2007, 3, 2);
		Date d5 = new Date(2007, 4, 20);
		Date d6 = new Date(2007, 4, 26);
		
		String rslt = d1.toString();
		System.out.println("오늘은 " + rslt + "입니다.");
		rslt = d2.toString();
		System.out.println("내가 동덕여자대학교에 입학한 날짜는 " + rslt + "입니다.");
		rslt = d3.toString();
		String rslt2 = d4.toString();
		System.out.println("2007학년도 개강일은 " + rslt + "에서 " + rslt2 + "로 변경되었습니다.");
		d3 = d5;
		d4 = d6;
		rslt = d3.toString();
		rslt2 = d4.toString();
		System.out.print("중간고사 기간은 " + rslt + "부터 " + rslt2 + "까지 입니다.");
	}

}
