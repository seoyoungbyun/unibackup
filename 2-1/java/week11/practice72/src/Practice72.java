import java.util.*;
public class Practice72 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        HashSet<String> set = new HashSet<String>();
        
        set.add("Milk");
        set.add("Bread");
        set.add("Butter");
        set.add("Ham");
        set.add("Cheese");
        
        String rslt = set.toString();
        System.out.println(rslt);
        
        System.out.print("[");
        for(String s:set){
            System.out.print(s + ", ");
        }
        System.out.println("]");
        
        int size = set.size();
        int count = 0;
        System.out.print("[");
        for(String s:set){
            System.out.print(s);
            count++;
            if (size == count){
                break;
            }
            else{
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }
}