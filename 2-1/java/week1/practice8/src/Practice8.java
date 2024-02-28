import java.util.Random;
public class Practice8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random rg = new Random();
		
		for (int i = 1; i <= 10; i++) {
			System.out.println("(" + i + "차 실행)");
			for (int j = 0; j < 10; j++) {
				int random = rg.nextInt(100);
				System.out.print(random + "\t");
			}
			System.out.println();
		}
	}

}
