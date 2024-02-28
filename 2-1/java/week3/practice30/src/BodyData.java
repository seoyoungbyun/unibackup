
public class BodyData {
	private int weight;
	private int height;
	
	public int getWeight() {
		return weight;
	}
	public void setWeight(int w) {
		weight = w;
	}
	public int getHeight() {
		return height;
	}
	public void setHeight(int h) {
		height = h;
	}
	
	public int idealWeight() {
		return height - 110;
	}
	public boolean needDiet() {
		int ideal = idealWeight();
		if (ideal < weight) {
			return true;
		}
		else {
			return false;
		}
	}
	public boolean isTallerThan(BodyData b) {
		int height2 = b.getHeight();
		if (height >= height2) {
			return true;
		}
		else {
			return false;
		}
	}
}
