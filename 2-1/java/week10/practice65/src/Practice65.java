public class Practice65 {
    public static void main(String[] args) {
		// 여기에 필요한 코드를 작성하세요.
        HealthData<Integer, Integer> p1 = new HealthData<Integer, Integer>("김동덕", 150, 50);
        HealthData<Integer, Double> p2 = new HealthData<Integer, Double>("홍길동", 180, 100.35);
        HealthData<Double, Integer> p3 = new HealthData<Double, Integer>("성춘향", 156.7, 65);
        
        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p3);
        
        int w1 = p1.getWeight();
        double w2 = p2.getWeight();
        int w3 = p3.getWeight();
        System.out.println("3사람 체중의 합: " + (w1 + w2 + w3));
    }
}

// 필요한 클래스 코드를 완성하세요.
class HealthData<H, W>{
    private String name;
    private W weight;
    private H height;
    
    public HealthData(String name,  H height, W weight){
        this.name = name;
        this.weight = weight;
        this.height = height;
    }
    
    String getName(){
        return name;
    }
    void setName(String name){
        this.name = name;
    }
    W getWeight(){
        return weight;
    }
    void setWeight(W weight){
        this.weight = weight;
    }
    H getHeight(){
        return height;
    }
    void setHeight(H height){
        this.height = height;
    }
    
    public String toString(){
        String rslt = "";
        
        rslt += "(" + name + ", " + height + ", " + weight + ")";
        
        return rslt;
    }
}