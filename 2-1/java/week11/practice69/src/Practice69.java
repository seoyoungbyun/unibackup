import java.util.Scanner;
import java.util.ArrayList;

public class Practice69 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        RandomList<Integer> list = new RandomList<Integer>();
        
        int listSize = sc.nextInt();
        for (int i = 0; i < listSize; i++){
            int input = sc.nextInt();
            list.add(input);
        }
        
        System.out.println("리스트의 내용을 출력합니다.");
        list.print();
        System.out.println("마지막 원소 출력: " + list.selectLast());
        
        RandomList<String> slist = new RandomList<String>();
        listSize = sc.nextInt();
        for (int i = 0; i < listSize; i++){
            String input = sc.next();
            slist.add(input);
        }
        
        System.out.println();
        System.out.println("리스트의 내용을 출력합니다.");
        slist.print();
        System.out.println("마지막 원소 출력: " + slist.selectLast());
        
        sc.close();
    }
}

// 필요한 클래스 코드를 완성하세요.
class RandomList<T>{
    ArrayList<T> list;
    
    public RandomList(){
        list = new ArrayList<T>();
    }
    
    public void add(T item){
        list.add(item);
    }
    public T selectLast(){
        int size = list.size();
        
        return list.get(size - 1);
    }
    public void print(){
        for (T t:list){
            System.out.print(t + "     ");
        }
        System.out.println();
    }
}