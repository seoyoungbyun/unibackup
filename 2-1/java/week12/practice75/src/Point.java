
public class Point {
	// 여기에 필요한 코드를 작성하세요.    
    private int x;
    private int y;
    
    public Point(){
        x = 0;
        y = 0;
    }
    
    public int getX(){
        return x;
    }
    public void setX(int x){
        this.x = x;
    }
    public int getY(){
        return y;
    }
    public void setY(int y){
        this.y = y;
    }
    
    public String toString(){
        String rslt = "";
        
        rslt += "중심좌표: (" + x + ", " + y + ")\n";
        
        return rslt;
    }
}
