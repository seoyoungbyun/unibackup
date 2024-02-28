import java.util.Scanner;

public class Practice59 {
    // 여기에 필요한 코드를 추가하세요.
    public static int whoswin(String com, String you) {
		if (you.equals(com)) {
			return 0;
		}
		else if (you.equals("가위")) {
			if (com.equals("바위")) {
				return -1;
			}
			else{
				return 1;
			}
		}
		else if (you.equals("바위")) {
			if (com.equals("보")) {
				return -1;
			}
			else{
				return 1;
			}
		}
		else {
			if (com.equals("가위")) {
				return -1;
			}
			else{
				return 1;
			}
		}
	}
    static String getInput(Scanner s) throws InvalidInputException
    {
        String input;
        
        input = s.next();
        if (input.equals("가위") == false && input.equals("바위") == false && input.equals("보") == false){
            throw(new InvalidInputException());
        }
        
        s.close();
        return input;
        
    }
    public static void main(String[] args) {
    // 여기에 필요한 코드를 작성하세요.     
        Scanner sc = new Scanner(System.in);
        String computer, me;
		
        try{
            computer = getInput(sc);
            me = getInput(sc);

        }catch(InvalidInputException e){
            System.out.println(e.getMessage());
            return;
        }
		
        int win = whoswin(computer, me);
        if (win == 0) {
            System.out.println("비겼습니다.");
        }
        else if (win == 1) {
           System.out.println("당신이 이겼습니다.");
        }
        else {
            System.out.println("컴퓨터가 이겼습니다.");
        }
        
		sc.close();
    }
    
}

// 여기에 사용자 예외를 정의하세요. 
@SuppressWarnings("serial")
class InvalidInputException extends Exception { 
    public InvalidInputException(){
        super("잘못된 입력입니다.");
    }
}