import java.util.Scanner;

public class Practice61 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
		BankAccount[] arr = new BankAccount[3];
		String owner;
		int balance, money, n, check;
		
		for (int i = 0; i < arr.length; i++) {
			owner = sc.next();
			balance = sc.nextInt();
			arr[i] = new BankAccount(owner, balance);
		}
		
		String rslt, plus;
		
		rslt = "현재 잔고현황입니다.\n";
		rslt += "계좌번호     계좌주     잔고\n";
		for (int i = 0; i < arr.length; i++) {
			plus = arr[i].toString();
			rslt += (i + 1) + plus;
		}
		System.out.println(rslt);
		
		n = sc.nextInt();
		while (n != 0) {
			check = sc.nextInt();
			money = sc.nextInt();
            try{
                if (check == 1) {
                    arr[n - 1].deposit(money);
                    System.out.println("입금이 완료되었습니다.");
                }
                else {
                    arr[n - 1].withdraw(money);
                    System.out.println("출금이 완료되었습니다.");
                }
            }
            catch(NegativeBalanceException e){
                System.out.println(e.getMessage());
            }
			
			rslt = "현재 잔고현황입니다.\n";
			rslt += "계좌번호     계좌주     잔고\n";
			for (int i = 0; i < arr.length; i++) {
				plus = arr[i].toString();
				rslt += (i + 1) + plus;
			}
			System.out.println(rslt);
			n = sc.nextInt();
		}
        System.out.print("프로그램을 종료합니다.");
		sc.close();
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
	public void deposit(int money) {
		balance += money;
	}
	public void withdraw(int money) throws NegativeBalanceException{
        if (money > balance){
            throw(new NegativeBalanceException());
        }
        else{
		    balance -= money;
        }
	}
}
@SuppressWarnings("serial")
class NegativeBalanceException extends Exception { 
    public NegativeBalanceException(){
        super("입력된 금액이 잘못되었습니다. 다시 입력하세요.");
    }
}