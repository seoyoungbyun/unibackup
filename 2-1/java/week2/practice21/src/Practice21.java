import java.util.Scanner;

public class Practice21 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int len;
		
		System.out.print("배열의 길이: ");
		len = sc.nextInt();
		
		int[] array = new int[len];
		
		System.out.println("숫자를 입력하세요:");
		for (int i = 0; i < array.length; i++) {
			array[i] = sc.nextInt();
		}
		System.out.println("배열에 저장된 숫자:");
		printArray(array);
		
		int key;
		System.out.print("찾고 싶은 숫자를 입력하세요: ");
		key = sc.nextInt();
		int index = searchArray(array, key);
		if (index == -1) {
			System.out.println("입력한 숫자 " + key + "는 배열에 없습니다.");
		}
		else {
			System.out.print("입력한 숫자 " + key + "는 배열의 " + index + "번 자리에 있습니다.");
		}
		
		sc.close();
	}
	
	public static int searchArray(int[] array, int key) {
		int index = 0;
		for (int arr : array) {
			if (arr == key) {
				return index;
			}
			index++;
		}
		
		return -1;
	}
	
	public static void printArray(int[] array) {
		for (int arr : array) {
			System.out.print(arr + " ");
		}
		System.out.println();
	}
}
