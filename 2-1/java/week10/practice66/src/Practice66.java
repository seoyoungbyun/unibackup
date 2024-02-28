import java.util.Scanner;

public class Practice66 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        String[] sArray = {"하나", "두울", "세엣"};
        Integer[] iArray = {10, 20, 30, 40};
        
        System.out.println("문자열 배열의 내용입니다.");
        MyArray.displayArray(sArray);
        System.out.println();
        
        for (int i = 0; i < 2; i++){
            int idx = sc.nextInt();
            System.out.print(idx + "번 인덱스 저장 내용: ");
            String s = MyArray.pick(sArray, idx);
            if (s != null){
                System.out.println(s);
            }
            else{
                System.out.println("null");
            }
        }
        System.out.println();
        
        int changeIdx = sc.nextInt();
        MyArray.swap(sArray, 0, changeIdx);
        System.out.println("변경 후 문자열 배열");
        MyArray.displayArray(sArray);
        System.out.println();
        
        System.out.println("정수형 배열의 내용입니다.");
        MyArray.displayArray(iArray);
        System.out.println();
        
        for (int i = 0; i < 2; i++){
            int idx = sc.nextInt();
            System.out.print(idx + "번 인덱스 저장 내용: ");
            Integer num = MyArray.pick(iArray, idx);
            if (num != null){
                System.out.println(num);
            }
            else{
                System.out.println("null");
            }
        }
        System.out.println();
        
        changeIdx = sc.nextInt();
        MyArray.swap(iArray, 0, changeIdx);
        System.out.println("변경 후 문자열 배열");
        MyArray.displayArray(iArray);
        
        sc.close();
    }
}

// 필요한 클래스 코드를 완성하세요.
class MyArray{
    public static <T> T pick(T[] arr, int idx){
        if (idx < 0 || idx >= arr.length){
            System.out.println("인덱스가 범위를 벗어났습니다 >> ");
            return null;
        }
        return arr[idx];
    }
    public static <T> void displayArray(T[] arr){
        for (T element:arr){
            System.out.print(element + "     ");
        }
        System.out.println();
    }
    public static <T> void swap(T[] arr, int i, int j){
        T tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

@SuppressWarnings("serial")
class InvalidInputException extends Exception { 
    public InvalidInputException(){
        super("인덱스가 범위를 벗어났습니다 >> null");
    }
}
