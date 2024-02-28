
public class Rectangle extends Shape implements Drawable{
	private double length, width;
	
	Rectangle(){
		this(-1, -1, -1, -1);
	}
	Rectangle(int x, int y, double width){
		this(x, y, width, 0);
	}
	Rectangle(int x, int y, double width, double length){
		super(x, y);
		this.width = width;
		this.length = length;
	}
	
	public double getWidth() {
		return width;
	}
	public void setWidth(double w) {
		width = w;
	}
	public double getLength() {
		return length;
	}
	public void setLength(double l) {
		length = l;
	}
	
	public double calcArea() {
		return length * width;
	}
	public String toString() {
		String rslt = "";
		int x = super.getX();
		int y = super.getY();
		double area = calcArea();
		
		rslt += "사각형, 중심좌표: (" + x + ", " + y + "), ";
		rslt += "가로: " + String.format("%.2f", width) + ", 세로: " + String.format("%.2f", length);
		rslt += ", 면적: " + String.format("%.2f", area) + "\n";
		
		return rslt;
	}
	
	public void draw() {
		String rslt = "사각형, ";
		
		rslt += toString();
		System.out.print(rslt);
	}
}