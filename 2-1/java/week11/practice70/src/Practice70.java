import java.util.Scanner;
import java.util.ArrayList;

public class Practice70 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        Scanner sc = new Scanner(System.in);
        ArrayList<Double> list = new ArrayList<Double>();
        
        int num = sc.nextInt();
        for (int i = 0; i < num; i++){
            double input = sc.nextDouble();
            list.add(input);
        }
        
        System.out.println("입력된 점수:");
        for (int i = 0; i < num; i++){
            System.out.print(String.format("%.4f", list.get(i)) + "     ");
            if (i % 2 == 1){
                System.out.println();
            }
        }
        if (num % 2 == 1){
            System.out.println();
        }
        System.out.println();
        
        double avg = getAve(list);
        System.out.println("평균값: " + String.format("%.4f", avg));
        double max = findMax(list);
        System.out.println("가장 높은 점수: " + String.format("%.4f", max));
        double min = findMin(list);
        System.out.println("가장 낮은 점수: " + String.format("%.4f", min));
        System.out.println();
        
        int size = list.size();
        System.out.println("최고점과 최저점을 제외한 결과:");
        for (int i = 0; i < size; i++){
            System.out.print(String.format("%.4f", list.get(i)) + " ");
            if (i % 2 == 1){
                System.out.println();
            }
        }
        if (size % 2 == 1){
            System.out.println();
        }
        System.out.println();
        
        avg = getAve(list);
        System.out.print("최종 점수: " + String.format("%.4f", avg));
        
        sc.close();
    }
    public static Double findMax(ArrayList<Double> scores){
        double max = -1;
        int maxIdx = 0;
        
        for (int i = 0; i < scores.size(); i++){
            if (max < scores.get(i)){
                max = scores.get(i);
                maxIdx = i;
            }
        }
        scores.remove(new Integer(maxIdx));
        
        return max;
    }
    public static Double findMin(ArrayList<Double> scores){
        double min = 11;
        int minIdx = 0;
        
        for (int i = 0; i < scores.size(); i++){
            if (min > scores.get(i)){
                min = scores.get(i);
                minIdx = i;
            }
        }
        scores.remove(new Integer(minIdx));
        
        return min;
    }
    public static Double getAve(ArrayList<Double> scores){
        int num = scores.size();
        double sum = 0;
        
        for (Double element:scores){
            sum += element;
        }
        sum /= num;
        return sum;
    }
}