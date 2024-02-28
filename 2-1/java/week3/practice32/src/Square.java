
public class Square {
	private int width;
	private int height;
	
	public int getWidth() {
		return width;
	}
	public void setWidth(int w) {
		width = w;
	}
	public int getHeight() {
		return height;
	}
	public void setHeight(int h) {
		height = h;
	}
	
	private int area() {
		return width * height;
	}
	
	public boolean isSmallerThan(Square s) {
		int me = area();
		int you = s.area();
		
		if (me < you) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public static Square getInstance(int width, int height) {
		Square s = new Square();
		
		s.setWidth(width);
		s.setHeight(height);
		
		return s;
	}
}