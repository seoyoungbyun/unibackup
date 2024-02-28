import java.util.Scanner;

public class Practice56A {
    // 메소드 헤더와 메소드 바디를 적절하게 작성하세요.    
    public static void main(String[] args) {
		int[] iArray = getInput();
        
        for (int i = 0; i < iArray.length; i++){
            iArray[i] = i * 20;
        }
        for (int x:iArray){
            System.out.print(x + "     ");
        }
    }
    
    // 메소드 헤더와 메소드 바디를 적절하게 작성하세요. 
    public static int[] getInput()  {
        Scanner s = new Scanner(System.in);
        
        try{
            String str = s.next();

            int num = Integer.parseInt(str);

            int[] rslt = makeArray(num);
            return rslt;
        }
        catch(NumberFormatException e){
            System.out.println("잘못된 형식의 숫자입니다.");
            int[] rslt = new int[0];
            return rslt;
        }
        finally {
        	s.close();
        }
        
        
    }
    
    // 메소드 헤더와 메소드 바디를 적절하게 작성하세요.
    public static int[] makeArray(int size)  {
        try{
            int[] rslt = new int[size];
            return rslt;
        }
        catch(NegativeArraySizeException e){
            System.out.println("배열의 크기가 음수입니다.");
            int[] rslt = new int[0];
            return rslt;
        }
    }
}