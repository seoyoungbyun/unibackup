import java.util.Scanner;

public class Practice78 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        
        int num = sc.nextInt();
        Movie[] arr = new Movie[num];
        String rslt = "";
        
        for (int i = 0; i < num; i++){
            String title = sc.next();
            String director = sc.next();
            int y = sc.nextInt();
            int m = sc.nextInt();
            int d = sc.nextInt();
            Date date = new Date(y, m, d);
            
            arr[i] = new Movie(title, director, date);
            rslt += arr[i].toString();
        }
        
        System.out.println("입력된 영화 정보입니다.");
        System.out.println(rslt);
        
        Movie fast = arr[0];
        for (int i = 1; i < num; i++){
            Date f = fast.getViewDay();
            Date c = arr[i].getViewDay();
            int compare = Date.compareDate(f, c);
            
            if (compare == -1)
            {
                fast = arr[i];
            }
        }
        String ft =fast.getTitle();
        System.out.println("관람일이 가장 빠른 영화는 \"" + ft + "\"입니다.");
        
        sc.close();
    }
}

class Date {
		// 여기에 필요한 코드를 작성하세요.   
    private int year;
    private int month;
    private int day;
    
    public Date(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }
    public String toString(){
        String rslt = year + "년 " + month + "월 " + day + "일\n";
        return rslt;
    }
    
    public static int compareDate(Date x, Date y) {
		if (x.year < y.year) {
			return -1;
		}
		else if (x.year > y.year) {
			return 1;
		}
		else {
			if (x.month < y.month) {
				return -1;
			}
			else if (x.month > y.month) {
				return 1;
			}
			else {
				if (x.day < y.day) {
					return -1;
				}
				else if (x.day > y.day) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
}

class Movie {
		// 여기에 필요한 코드를 작성하세요. 
    private String title;
    private String director;
    private Date viewDay;
    
    public Movie(){
        this("모름", "모름", new Date(1999, 9, 9));
    }
    public Movie(String title, String director){
        this(title, director, new Date(1999, 9, 9));
    }
    public Movie(String title, String director, Date viewDay){
        this.title = title;
        this.director = director;
        this.viewDay = viewDay;
    }
    
    public String getTitle(){
        return title;
    }
    public void setTitle(String title){
        this.title = title;
    }
    public String getDirector(){
        return director;
    }
    public void setDirector(String director){
        this.director = director;
    }
    public Date getViewDay(){
        return viewDay;
    }
    public void setViewDay(Date viewDay){
        this.viewDay = viewDay;
    }
    
    public String toString(){
        String rslt = title + " / ";
        
        rslt += director + " / ";
        rslt += viewDay.toString();
        
        return rslt;
    }
}