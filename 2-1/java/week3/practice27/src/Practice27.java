
public class Practice27 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Date d1 = new Date(2010, 9, 2);
		Date d2 = new Date(1997, 4, 1);
		
		String rslt1 = d1.toString();
		String rslt2 = d1.printWestern();
		System.out.println(rslt1);
		System.out.println(rslt2);
		
		rslt1 = d2.toString();
		rslt2 = d2.printWestern();
		System.out.println(rslt1);
		System.out.println(rslt2);
	}

}