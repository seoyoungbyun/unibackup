
public class Practice22 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] intArray = {
				{1 , 2, 3, 4},
				{10, 20, 30, 40},
				{100, 200, 300, 400}
		};
		int[] colSum = new int[4];
		
		for (int j = 0; j < 4; j++) {
			colSum[j] = 0;
			for (int i = 0; i < 3; i++) {
				colSum[j] += intArray[i][j];
			}
		}
		
		System.out.println("배열만 출력");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(intArray[i][j] + " ");
			}
			System.out.println();
		}
		
		System.out.println("\n합과 함께 출력");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(intArray[i][j] + " ");
			}
			System.out.println();
		}
		for (int i = 0; i < 4; i++) {
			System.out.print(colSum[i] + " ");
		}
	}

}
