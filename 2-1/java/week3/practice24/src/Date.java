
public class Date {
	private int year, month, day;
	
	public int getYear() {
		return year;
	}
	public void setYear(int y) {
		year = y;
	}
	public int getMonth() {
		return month;
	}
	public void setMonth(int m) {
		month = m;
	}
	public int getDay() {
		return day;
	}
	public void setDay(int d) {
		day = d;
	}
	
	public String toString() {
		int y = getYear();
		int m = getMonth();
		int d = getDay();
		
		String s = y + "년 " + m + "월 " + d + "일";
		
		return s;
	}

}
