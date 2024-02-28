//컴퓨터학과 20220769 변서영
public class Config {
	private int size, range, key;
	
	public Config(int size, int range, int key) {
		this.size = size;
		this.range = range;
		this.key = key;
	}
	
	public int getRange() {
		return range;
	}
	public int getSize() {
		return size;
	}
	public int getKey() {
		return key;
	}
}
