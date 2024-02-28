import java.util.Scanner;

public class Practice19 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int[] arr1 = new int[3];
		int[] arr2 = new int[3];
		int same1 = 0, same2 = 0;
		
		System.out.print("첫번째 배열 입력: ");
		for (int i = 0; i < arr1.length; i++) {
			arr1[i] = sc.nextInt();
		}
		System.out.print("두번째 배열 입력: ");
		for (int i = 0; i < arr2.length; i++) {
			arr2[i] = sc.nextInt();
		}
		
		for (int i = 0; i < arr1.length; i++) {
			int index = searchArray(arr2, arr1[i]);
			if (index == -1) {
				continue;
			}
			else if (index == i) {
				same2++;
			}
			else {
				same1++;
			}
		}
		System.out.print("첫번째 배열:");
		printArray(arr1);
		System.out.print("두번째 배열:");
		printArray(arr2);
		System.out.println("자리와 값이 모두 같은 숫자: " + same2 + "개");
		System.out.print("자리는 다르고 값만 같은 숫자: " + same1 + "개");
		
		sc.close();
	}
	
	public static int searchArray(int[] array, int key) {
		for (int i = 0; i < array.length; i++) {
			if (array[i] == key) {
				return i;
			}
		}
		
		return -1;
	}
	
	public static void printArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
}