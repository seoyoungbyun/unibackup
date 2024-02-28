//컴퓨터학과 20220769 변서영
import java.util.Scanner;

public class Practice46 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
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
		System.out.print(rslt);
		
		n = sc.nextInt();
		while (n != 0) {
			check = sc.nextInt();
			money = sc.nextInt();
			if (check == 1) {
				arr[n - 1].deposit(money);
                System.out.println("입금이 완료되었습니다.");
			}
			else {
				arr[n - 1].withdraw(money);
                System.out.println("출금이 완료되었습니다.");
			}
			
			rslt = "현재 잔고현황입니다.\n";
			rslt += "계좌번호     계좌주     잔고\n";
			for (int i = 0; i < arr.length; i++) {
				plus = arr[i].toString();
				rslt += (i + 1) + plus;
			}
			System.out.print(rslt);
			n = sc.nextInt();
		}
        System.out.print("프로그램을 종료합니다.");
		sc.close();
	}

}
