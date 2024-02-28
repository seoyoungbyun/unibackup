import java.util.Scanner;

public class Practice58 {
    // 메소드 헤더와 메소드 바디를 적절하게 작성하세요.
	public static int searchArray(int[] array, int key) throws NotFoundException{
        for (int i = 0; i < array.length; i++){
            if (array[i] == key){
                return i;
            }
        }
        
        throw(new NotFoundException(key));
    }
    
    // 메소드 헤더와 메소드 바디를 적절하게 작성하세요.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[10];
        
        for (int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }
        int key = sc.nextInt();
        
        System.out.println("배열에 저장된 숫자입니다.");
        for (int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + "     ");
        }
        System.out.println();
        
        try{
            int index = searchArray(arr, key);
            System.out.println("입력된 숫자 " + key + "는 인덱스 " + index + "번에 존재합니다.");
        }
        catch(NotFoundException e){
            System.out.println(e.getMessage());
        }
        
        sc.close();
    }
}

// 사용자 정의 예외는 아래의 코드를 그대로 사용하면 됩니다.
@SuppressWarnings("serial")
class NotFoundException extends Exception { 
    public NotFoundException(int key){
        super("입력된 숫자 " + key + "는 배열에 존재하지 않습니다.");
    }
}