
public class Date {
	private int year, month, day;
	
	public Date() {
		this(1990, 1, 1);
	}
	public Date(int year) {
		this(year, 1, 1);
	}
	public Date(int year, int month) {
		this(year, month, 1);
	}
	public Date(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
	}
	
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

	protected boolean isReap() {
		if (year % 4 == 0 || year % 400 == 0) {
			return true;
		}
		else if (year % 100 != 0) {
			return false;
		}
		else {
			return false;
		}
	}
	
	public String testReapYears() {
		boolean reap = isReap();
		String rslt = "";
		
		if (reap) {
			rslt += year + "년은 윤년입니다.";
		}
		else {
			rslt += year + "년은 윤년이 아닙니다.";
		}
		
		return rslt;
	}
}