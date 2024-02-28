import java.util.Scanner;

public class Practice60 {
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
        
        return input;
    }
    static String getValidInput(Scanner s){
        int flag = 0;
        
        while(true){
            try{
                String input = getInput(s);
                return input;
            }
            catch(InvalidInputException e){
                System.out.println(e.getMessage());
                continue;
            }
        }
    }
    
    // 메인 메소드를 변경하지 마세요.
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	
		String com = getValidInput(sc);
		String you = getValidInput(sc);

		switch (whoswin(com, you))  {
			case 0 : System.out.println("비겼습니다."); break;
			case 1 : System.out.println("당신이 이겼습니다."); break;
			case -1 : System.out.println("컴퓨터가 이겼습니다.");
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

