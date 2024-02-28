//컴퓨터학과 20220769 변서영
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Practice74 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub	
		try {
			Config c = getInput();
			
			int count = 1;
			
			ArrayList<Integer> list = getRandomNumbers(c);
			int key = c.getKey();
			System.out.print("(" + count + "차)");
			printArray(list);
			boolean check = searchArray(list, key);
			
			while (check != true) {
				list = getRandomNumbers(c);
				count++;
				System.out.print("(" + count + "차)");
				printArray(list);
				
				check = searchArray(list, key);
			}
			System.out.println(count +"차 실행에서 난수 " + key + "이 발생했으므로 프로그램을 종료합니다.");
		}
		catch(ImproperKeyValueException e) {
			System.out.println(e.getMessage());
		}
		
	}
	private static Config getInput() throws ImproperKeyValueException {
		Scanner sc = new Scanner(System.in);
		int size, range, key;
		
		System.out.print("원하는 난수의 개수를 입력하세요: ");
		size = sc.nextInt();
		System.out.print("난수값의 범위를 설정하세요: ");
		range = sc.nextInt();
		System.out.print("찾고 싶은 난수값을 입력하세요: ");
		key = sc.nextInt();
		
		sc.close();
		
		if (key > range) {
			throw(new ImproperKeyValueException());
		}
		
		Config c = new Config(size, range, key);
		
		return c;
	}
	private static ArrayList<Integer> getRandomNumbers(Config c){
		ArrayList<Integer> list = new ArrayList<Integer>();
		ArrayList<Integer> newList = new ArrayList<Integer>();
		
		int range = c.getRange();
		int size = c.getSize();
		
		for (int i = 0; i <= range; i++) {
			list.add(i);
		}
		Collections.shuffle(list);
		
		for (int i = 0; i < size; i++)
		{
			newList.add(list.get(i));
		}
		
		return newList;
	}
	private static void printArray(ArrayList<Integer> list) {
		int i;
		
		for (i = 0; i < list.size(); i++) {
			System.out.print(list.get(i) + "\t");
			if (i % 10 == 9) {
				System.out.println();
			}
		}
		if (i % 10 != 0) {
				System.out.println();
		}
	}
	private static boolean searchArray(ArrayList<Integer> list, Integer key) {
		Collections.sort(list);
		int idx = Collections.binarySearch(list, key);
		
		if (idx >= 0) {
			return true;
		}
		return false;

	}
}
