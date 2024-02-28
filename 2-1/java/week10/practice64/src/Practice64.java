import java.util.Scanner;

public class Practice64 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        
        String s1 = sc.next();
        String s2 = sc.next();
        MyPair<String> s = new MyPair<String>(s1, s2);
        
        System.out.println(s);
        
        int num = sc.nextInt();
        
        if (num == 1){
            s1 = sc.next();
            s.setFirst(s1);
        }
        else{
            s2 = sc.next();
            s.setSecond(s2);
        }
        System.out.println(s);
        
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        MyPair<Integer> n = new MyPair<Integer>(num1, num2);
        
        System.out.println(n);
        System.out.println(num1 + " + " + num2 + " = " + (num1 + num2));
        
        sc.close();
    }
}

// 필요한 클래스 코드를 완성하세요.
class MyPair<T>{
    T first;
    T second;
    
    public MyPair(T first, T second){
        this.first = first;
        this.second = second;
    }
    
    T getFirst(){
        return first;    
    }
    void setFirst(T first){
        this.first = first;
    }
    T getSecond(){
        return second;    
    }
    void setSecond(T second){
        this.second = second;
    }
    
    public String toString(){
        String rslt = "";
        
        rslt += "만들어진 순서쌍: (" + first + ", " + second + ")";
        
        return rslt;
    }
}
