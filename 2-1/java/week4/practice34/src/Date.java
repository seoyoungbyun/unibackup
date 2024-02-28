
public class Date {
	private Integer year, month, day;
	
	public Date() {
		this(1990, 1, 1);
	}
	public Date(Integer year) {
		this(year, 1, 1);
	}
	public Date(Integer year, Integer month) {
		this(year, month, 1);
	}
	public Date(Integer year, Integer month, Integer day) {
		this.year = year;
		this.month = month;
		this.day = day;
	}
	
	public Integer getYear() {
		return year;
	}
	public void setYear(int y) {
		year = y;
	}
	public Integer getMonth() {
		return month;
	}
	public void setMonth(int m) {
		month = m;
	}
	public Integer getDay() {
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