
public class Circle {
	private Point center;
    private int radius;
    
    public Circle(){
        this(new Point(), 0);
    }
    public Circle(int x, int y, int radius){
    	center = new Point();
        center.setX(x);
        center.setY(y);
        this.radius = radius;
    }
    public Circle(Point p, int radius){
        center = p;
        this.radius = radius;
    }
    
    public Point getCenter(){
        return center;
    }
    public void setCenter(Point center){
        this.center = center;
    }
    public int getRadius(){
        return radius;
    }
    public void setRadius(int radius){
        this.radius = radius;
    }
    
    public String toString(){
        String rslt = center.toString();
        
        rslt += "반지름: " + radius + "\n";
        
        return rslt;
        
    }
}
