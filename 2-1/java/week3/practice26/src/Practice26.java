
public class Practice26 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Date d1 = new Date(2004);
		Date d2 = new Date(1997);
		Date d3 = new Date();
		Date d4 = new Date(2000);
		
		String rslt = d1.testReapYears();
		System.out.println(rslt);
		rslt = d2.testReapYears();
		System.out.println(rslt);
		rslt = d3.testReapYears();
		System.out.println(rslt);
		rslt = d4.testReapYears();
		System.out.print(rslt);
	}

}
