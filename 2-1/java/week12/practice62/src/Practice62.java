import java.util.Scanner;

public class Practice62 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        int check, money;
        
        int num = sc.nextInt();
		BankAccount[] arr = new BankAccount[num];
		
        getAccInfo(sc, arr);
		printAccInfo(arr);
        
        try{
            int n = getAccNum(sc, arr);
            while (n != 0){
                check = getOperationNum(sc);
                money = sc.nextInt();
            
                if (check == 1) {
                    arr[n - 1].deposit(money);
                    System.out.println("입금이 완료되었습니다.");
                }
                else {
                    arr[n - 1].withdraw(money);
                    System.out.println("출금이 완료되었습니다.");
                }
                
                printAccInfo(arr);
                n = getAccNum(sc, arr);
            }
        }
        catch(NoSuchAccountException e){
            System.out.println(e.getMessage());
        }
        catch(NoSuchOperationException e){
            System.out.println(e.getMessage());
        }
        catch(NegativeBalanceException e){
            System.out.println(e.getMessage());
        }
        System.out.print("프로그램을 종료합니다.");
		sc.close();
    }
    
    private static void getAccInfo(Scanner scan, BankAccount[] ba){
        String owner;
		int balance, money, check;
		
		for (int i = 0; i < ba.length; i++) {
			owner = scan.next();
			balance = scan.nextInt();
			ba[i] = new BankAccount(owner, balance);
		}
    }
    private static void printAccInfo(BankAccount[] ba){
        String rslt, plus;
		
		rslt = "현재 잔고현황입니다.\n";
		rslt += "계좌번호     계좌주     잔고\n";
		for (int i = 0; i < ba.length; i++) {
			plus = ba[i].toString();
			rslt += (i + 1) + plus;
		}
		System.out.println(rslt);
    }
    private static int getAccNum(Scanner scan, BankAccount[] ba) throws NoSuchAccountException{
        int size = ba.length;
        int n = scan.nextInt();
        
        if (n >= size){
            throw(new NoSuchAccountException());
        }
        else{
            return n;
        }
    }
    private static int getOperationNum(Scanner scan) throws NoSuchOperationException{
        int n = scan.nextInt();
        
        if (n != 1 && n != 2){
            throw(new NoSuchOperationException());
        }
        else{
            return n;
        }
    }
}

// 필요한 클래스 코드를 완성하세요.
class BankAccount {
	private String owner;
	private int balance;
	
	public BankAccount() {
		this("모름", -1);
	}
	public BankAccount(String owner, int balance) {
		this.owner = owner;
		this.balance = balance;
	}
	
	public String getOwner() {
		return owner;
	}
	public void setOwner(String owner) {
		this.owner = owner;
	}
	public int getBalance() {
		return balance;
	}
	public void setBalance(int balance) {
		this.balance = balance;
	}
	
	public String toString() {
		String rslt = "     " + owner + "     " + balance + "\n";
		
		return rslt;
	}
	public void deposit(int money) throws NegativeBalanceException{
        if (money < 0){
		    throw(new NegativeBalanceException());
        }
        else{
            balance += money;
        }
	}
	public void withdraw(int money) throws NegativeBalanceException{
        if (money > balance || money < 0){
            throw(new NegativeBalanceException());
        }
        else{
		    balance -= money;
        }
	}
}
@SuppressWarnings("serial")
class NoSuchAccountException extends Exception { 
    public NoSuchAccountException(){
        super("잘못된 계좌번호입니다. 다시 입력하세요.");
    }
}
@SuppressWarnings("serial")
class NoSuchOperationException extends Exception { 
    public NoSuchOperationException(){
        super("입력된 금액이 잘못되었습니다. 다시 입력하세요.");
    }
}
@SuppressWarnings("serial")
class NegativeBalanceException extends Exception { 
    public NegativeBalanceException(){
        super("잘못된 작업입니다. 다시 입력하세요.");
    }
}