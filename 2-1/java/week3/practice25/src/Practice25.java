
public class Practice25 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Date d1 = new Date();
		Date d2 = new Date(2006);
		Date d3 = new Date(2007, 2);
		Date d4 = new Date(2007, 3, 2);
		Date d5 = new Date(2007, 4);
		Date d6 = new Date(2007, 4, 26);
		
		d1.setYear(2007);
		d1.setMonth(2);
		d1.setDay(18);
		d2.setMonth(3);
		d2.setDay(2);
		d3.setDay(27);
		d5.setDay(20);
		
		String rslt = d1.toString();
		System.out.println("오늘은 " + rslt + "입니다.");
		rslt = d2.toString();
		System.out.println("내가 동덕여자대학교에 입학한 날짜는 " + rslt + "입니다.");
		rslt = d3.toString();
		String rslt2 = d4.toString();
		System.out.println("2007학년도 개강일은 " + rslt + "에서 " + rslt2 + "로 변경되었습니다.");
		rslt = d5.toString();
		rslt2 = d6.toString();
		System.out.print("중간고사 기간은 " + rslt + "부터 " + rslt2 + "까지 입니다.");
	}

}
