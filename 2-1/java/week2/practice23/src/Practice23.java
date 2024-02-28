
public class Practice23 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] intArray = new int[3][4];
		int[] rowSum = new int[3];
		int[] colSum = new int[4];
		int total = 0;
		
		for (int i = 0; i < 3; i++) {
			rowSum[i] = 0;
			for (int j = 0; j < 4; j++) {
				intArray[i][j] = (int) ((j + 1) * Math.pow(10, i));
				rowSum[i] += intArray[i][j];
			}
		}
		for (int j = 0; j < 4; j++) {
			colSum[j] = 0;
			for (int i = 0; i < 3; i++) {
				colSum[j] += intArray[i][j];
			}
			total += colSum[j];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(intArray[i][j] + " ");
			}
			System.out.println(rowSum[i]);
		}
		for (int i = 0; i < 4; i++) {
			System.out.print(colSum[i] + " ");
		}
		System.out.print(total);
	}

}