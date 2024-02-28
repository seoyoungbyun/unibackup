import java.util.Scanner;

public class Practice76 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        String title, director;
        int y, m, d;
        
        Movie m1 = new Movie();
        
        title = sc.next();
        director = sc.next();
        y = sc.nextInt();
        m = sc.nextInt();
        d = sc.nextInt();
        
        Movie m2 = new Movie(title, director);
        Date date = new Date(y, m, d);
        m2.setViewDay(date);
        
        title = sc.next();
        director = sc.next();
        y = sc.nextInt();
        m = sc.nextInt();
        d = sc.nextInt();
        
        date = new Date(y, m, d);
        Movie m3 = new Movie(title, director, date);
        
        System.out.println("첫 번째 영화의 정보입니다.");
        System.out.println(m1);
        System.out.println("두 번째 영화의 정보입니다.");
        System.out.println(m2);
        System.out.println("세 번째 영화의 정보입니다.");
        System.out.println(m3);
        
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
        String rslt = "관람일: " + year + "년 " + month + "월 " + day + "일\n";
        return rslt;
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
        String rslt = "제목: " + title + "\n";
        
        rslt += "감독: " + director + "\n";
        rslt += viewDay.toString();
        
        return rslt;
    }
}