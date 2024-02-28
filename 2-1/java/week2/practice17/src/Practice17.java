import java.util.Scanner;

public class Practice17 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int[] array = new int[10];
		
		for (int i = 0; i < array.length; i++) {
			array[i] = sc.nextInt();
		}
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
		
		for (int i = array.length - 1; i >= 0; i--) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
		
		int sum = 0;
		for (int i = 0; i < array.length; i++) {
			sum += array[i];
		}
		
		double average = 0;
		for (int i = 0; i < array.length; i++) {
			average += array[i];
		}
		average = average / array.length;
		System.out.println("총합: " + sum);
		System.out.println("평균: " + String.format("%.2f", average));
		
		sc.close();
	}

}
