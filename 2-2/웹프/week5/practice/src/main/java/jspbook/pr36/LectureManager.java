//컴퓨터학과 20220769 변서영 
//웹프 기말과제
//Microsoft Edge에 최적화되어있습니다.
package jspbook.pr36;
import java.util.List;
import java.util.ArrayList;

public class LectureManager {
	private ArrayList<LectureBean> lectureList;
	private static final int times = 6;
	private static final int days = 5;
	private int[][] typeMatrix = new int[times][days];
	private int[][] titleMatrix = new int[times][days];
	private int[][] spanMatrix = new int[times][days];
	
	public LectureManager() {
		this.lectureList = new ArrayList<>();
	}
	
	public List<LectureBean> getLectureList(){
		return lectureList;
	}
	public void add(LectureBean lbean) {
		lectureList.add(lbean);
	}
	
	public void buildMatrix() {
		for (int i = 0; i < times; i++) {
			for (int j = 0; j < days; j++) {
				typeMatrix[i][j] = 0;
				titleMatrix[i][j] = -1;
				spanMatrix[i][j] = 1;
			}
		}
		for (int i = 0; i < lectureList.size(); i++) {
			int time = lectureList.get(i).getTime() - 1;
			int day = lectureList.get(i).getDay();
			int type = lectureList.get(i).getType() + 1;
			int title = lectureList.get(i).getTitle();
			int consecutive = lectureList.get(i).getConsecutive();
				
			typeMatrix[time][day] = type;	
			titleMatrix[time][day] = title;
			spanMatrix[time][day] = consecutive;
			if (consecutive > 1) {	
				for (int j = 1; j < consecutive; j++) {
					spanMatrix[time + j][day] = 0;
				}
			}
		}
	}
	public static void printMatrix(int[][] matrix) {
		for (int i = 0; i < times; i++) {
			for (int j = 0; j < days; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	public int[][] getTypeMatrix() {
		return typeMatrix;
	}

	public int[][] getTitleMatrix() {
		return titleMatrix;
	}

	public int[][] getSpanMatrix() {
		return spanMatrix;
	}
	
	public String getTable(int i) {
		String tableStr = "<tr>";
		tableStr += "<th>" + (i + 1) + "</th>";
		for (int j = 0; j < days; j++) {
			if (spanMatrix[i][j] == 0){
					continue;
				}
			
			if (typeMatrix[i][j] == 0){
				tableStr += "<td></td>";
			}
			else{
				tableStr += "<td rowspan = '" + spanMatrix[i][j];
				
				int idx = titleMatrix[i][j];
				if (typeMatrix[i][j] != 0 && typeMatrix[i][j] != 4){
					if (typeMatrix[i][j] == 1){
						tableStr += "' class = 'yellow'>";
					}
					else if (typeMatrix[i][j] == 2){
						tableStr += "' class = 'blue'>";
					}
					else{
						tableStr += "' class = 'gray'>";
					}
				}
				else{
					tableStr += "'>";
				}
				tableStr += LectureBean.titleNames[idx] + "</td>";
			}
		
		}
		tableStr += "</tr>";
		return tableStr;
	}
}
