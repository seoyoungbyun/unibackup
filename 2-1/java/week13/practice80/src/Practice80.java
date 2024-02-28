//컴퓨터학과 20220769 변서영
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;

public class Practice80 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int count = 0;
		
		System.out.print("난수값이 저장된 파일 이름을 입력하세요: ");
		String fname = sc.next();
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		try {
			Scanner scan = new Scanner(new FileReader(fname));
			
			System.out.println("파일에서 난수를 읽어 드립니다.");
			while(scan.hasNext()) {
				count++;
				int num = scan.nextInt();
				list.add(num);
			}
			
			if (scan != null) {
				scan.close();
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		System.out.println("난수의 개수는 모두 " + count + "개입니다.");
		System.out.println("입력된 난수는 다음과 같습니다.");
		printArray10PerLine(list);
		
		Collections.sort(list);
		System.out.println("정렬된 난수는 다음과 같습니다.");
		printArray10PerLine(list);
		
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
}
