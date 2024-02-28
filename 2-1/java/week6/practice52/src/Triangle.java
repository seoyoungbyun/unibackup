
public class Triangle extends Shape implements Drawable{
	private double base, height;
	
	Triangle(){
		this(-1, -1, -1, -1);
	}
	Triangle(int x, int y, double base){
		this(x, y, base, -1);
	}
	Triangle(int x, int y, double base, double height){
		super(x, y);
		this.base = base;
		this.height = height;
	}
	
	public double getBase() {
		return base;
	}
	public void setBase(double base) {
		this.base = base;
	}
	public double getLength() {
		return height;
	}
	public void setLength(double height) {
		this.height = height;
	}
	
	public double calcArea() {
		return (base * height) / 2;
	}
	public String toString() {
		String rslt = "";
		int x = super.getX();
		int y = super.getY();
		double area = calcArea();
		
		rslt += "삼각형, 중심좌표: (" + x + ", " + y + "), ";
		rslt += "밑변: " + String.format("%.2f", base) + ", 높이: " + String.format("%.2f", height);
		rslt += ", 면적: " + String.format("%.2f", area) + "\n";
		
		return rslt;
	}
	
	public void draw() {
		String rslt = "삼각형, ";
		
		rslt += toString();
		System.out.print(rslt);
	}
}