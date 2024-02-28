//컴퓨터학과 20220769 변서영
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Practice79 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int size, range;
		
		System.out.print("원하는 난수의 개수를 입력하세요: ");
		size = sc.nextInt();
		System.out.print("난수 값의 범위를 설정하세요: ");
		range = sc.nextInt();
		
		ArrayList<Integer> list = getRandomList(size, range);
		System.out.println("생성된 난수는 다음과 같습니다.");
		printArray10PerLine(list);
		
		System.out.print("난수 값을 저장할 파일 이름을 입력하세요: ");
		String fname = sc.next();
		
		try {
			PrintWriter pw = new PrintWriter(new FileWriter(fname));
			
			for (int i = 0; i < list.size(); i++) {
				pw.println(list.get(i));
			}
			System.out.println("파일 " + fname + "에 난수값이 저장되었습니다.");
			if (pw != null) {
				pw.close();
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
		
		sc.close();
	}
	
	public static void printArray10PerLine(ArrayList<Integer> a)
	{
		int i;
		for (i = 0; i < a.size(); i++) {
			System.out.print(a.get(i) + "\t");
			if (i % 10 == 9) {
				System.out.println();
			}
		}
		if (i % 10 != 0) {
			System.out.println();
		}
	}
	public static ArrayList<Integer> getRandomList(int size, int range){
		ArrayList<Integer> list = new ArrayList<Integer>();
		ArrayList<Integer> newList = new ArrayList<Integer>();
		
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
}
