import java.util.Scanner;
import java.util.HashSet;

public class Practice71 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        HashSet<Integer> set = new HashSet<Integer>();
        int count = 0;
        
        while (count < 5){
            int input = sc.nextInt();
            
            if (!set.contains(input)){
                count++;
                set.add(input);
            }
            System.out.println(count + "개의 숫자가 입력되었습니다.");
        }
        
        System.out.println(set);
        sc.close();
    }
}