//컴퓨터학과 20220769 변서영
import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Practice82 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("원하는 작업을 선택하세요(0-종료/1-열기/2-저장/3-계좌업무): ");
		int check = sc.nextInt();
		ArrayList<BankAccount> list = new ArrayList<BankAccount>();
		
		while (check != 0) {
			if (check == 1) {
				System.out.print("파일 이름을 입력하세요: ");
				String fname = sc.next();
				load(fname, list);
				
				printAccInfo(list);
			}
			else if (check == 2){
				System.out.print("파일 이름을 입력하세요: ");
				String fname = sc.next();
				save(fname, list);
			}
			else
			{
				System.out.print("업데이트할 계좌번호를 입력하세요: ");
				int accNum = sc.nextInt();
				System.out.print("원하는 계좌 작업을 선택하세요(1-입금/2-출금): ");
				int choose = sc.nextInt();
	            
                if (choose == 1) {
                	System.out.print("입금액을 입력하세요: ");
                	int money = sc.nextInt();
                    list.get(accNum - 1).deposit(money);
                    System.out.println("입금이 완료되었습니다.");
                }
                else {
                	System.out.print("출금액을 입력하세요: ");
                	int money = sc.nextInt();
                	list.get(accNum - 1).withdraw(money);
                    System.out.println("출금이 완료되었습니다.");
                }
                
                printAccInfo(list);
			}
			System.out.print("원하는 작업을 선택하세요(0-종료/1-열기/2-저장/3-계좌업무): ");
			check = sc.nextInt();
		}
		System.out.print("프로그램을 종료합니다.");
		sc.close();
	}
	public static void load(String fname, ArrayList<BankAccount> list) {
		try {
			Scanner scan = new Scanner(new FileReader(fname));
			
			while(scan.hasNext()) {
				scan.nextInt();
				String name = scan.next();
				int balance = scan.nextInt();
				BankAccount ba = new BankAccount(name, balance);
				list.add(ba);
			}
			
			if (scan != null) {
				scan.close();
			}
		}catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void save(String fname, ArrayList<BankAccount> list) {
		try {
			PrintWriter pw = new PrintWriter(new FileWriter(fname));
			String rslt = "";
			
			for (int i = 0; i < list.size(); i++) {
				String s = list.get(i).toString();
				rslt += (i + 1) + s;
			}
			pw.println(rslt);
			
			System.out.println("잔고현황이 성공적으로 저장되었습니다.\n");
			if (pw != null) {
				pw.close();
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	private static void printAccInfo(ArrayList<BankAccount> list){
        String rslt, plus;
		
		rslt = "\n현재 잔고현황입니다.\n";
		rslt += "계좌번호\t계좌주\t잔고\n";
		for (int i = 0; i < list.size(); i++) {
			plus = list.get(i).toString();
			rslt += (i + 1) + plus;
		}
		System.out.println(rslt);
    }
}