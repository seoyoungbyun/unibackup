import java.util.Scanner;

public class Practice63 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        
        String input = sc.next();
        MyBox<String> fir = new MyBox<String>(input);
        String s = fir.get();
        System.out.println("MyBox에 저장된 내용: " + s);
        input = sc.next();
        fir.set(input);
        s = fir.get();
        System.out.println("MyBox에 저장된 내용: " + s);
        
        int num = sc.nextInt();
        MyBox<Integer> sec = new MyBox<Integer>(num);
        
        num = sc.nextInt();
        MyBox<Integer> thi = new MyBox<Integer>(num);
        
        int n1 = sec.get();
        int n2 = thi.get();
        System.out.println(n1 + " + " + n2 + " = " + (n1 + n2));
        
        sc.close();
    }
}

// 필요한 클래스 코드를 완성하세요.
class MyBox<T>{
    private T s;
    
    public MyBox(T s){
        this.s = s;
    }
    
    void set(T s){
        this.s = s;
    }
    T get(){
        return s;
    }
}