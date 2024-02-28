<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>컴퓨터학과 2학년 시간표</title>
    <style>
	    table{
	        border-collapse: collapse;
	    }
	
	    table, th, td{
	        border: 1px solid black;
	    }
	    caption {
	        font-size: 20px;
	        font-weight: bold;
	
	    }
	    th, td {
	        width: 90px;
	        height : 50px;
	    }
	    th{
	        font-size: 20px;
	    }
	    td{
	        font-size: 13px;
	        text-align: center;
	    }
	
	    td.yellow {
	        background-color: #f5e198;
	    }
	    td.blue {
	        background-color: #bcccfa;
	    }
	    td.gray {
	        background-color: #bdbdbd;
	    }
    </style>
</head>
<body>
<%!
	int[][] lectureType = {
			{0, 1, 1, 0, 1},
			{1, 0, 0, 0, 2},
			{0, 0, 2, 0, 4},
			{2, 3, 0, 3, 0},
			{0, 0, 0, 2, 0},
			{0, 0, 0, 0, 0}
	};
	
	int[][] consecutive = {
			{1, 2, 1, 1, 1},
			{2, 0, 1, 1, 1},
			{0, 1, 1, 1, 4},
			{2, 1, 1, 1, 0},
			{0, 1, 1, 2, 0},
			{1, 1, 1, 0, 0}
	};
	
	int[][] lectureTitle = {
			{-1, 4, 5, -1, 5},
			{3, -1, -1, -1, 1},
			{-1, -1, 1, -1, 7},
			{0, 6, -1, 6, -1},
			{-1, -1, -1, 2, -1},
			{-1, -1, -1, -1, -1}
	};
	
	String[] titleNames = {
			"웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론",
			"자료구조", "네트워크", "창의와감성", "사회봉사"
	};
%>
    <div align = "center">
    	<h2>강의 시간표</h2>
        <table>
            <tr>
                <th>2학년</th>
                <th>월</th>
                <th>화</th>
                <th>수</th>
                <th>목</th>
                <th>금</th>
            </tr>
          	<%
          		for (int i = 0; i < 6; i++){
          			out.println("<tr>");
          			out.println("<th>" + (i + 1) + "</th>");
          			for (int j = 0; j < 5; j++){
          				if (consecutive[i][j] == 0){
          					continue;
          				}
          				
          				if (lectureType[i][j] == 0){
          					out.println("<td></td>");
          				}
          				else{
          					int idx = lectureTitle[i][j];
          					String color;
          					if (lectureType[i][j] != 0 && lectureType[i][j] != 4){
          						if (lectureType[i][j] == 1){
          							color = "yellow";
          						}
          						else if (lectureType[i][j] == 2){
          							color = "blue";
          						}
          						else{
          							color = "gray";
          						}
          						out.print("<td rowspan = '" + consecutive[i][j] + "' class = '" + color + "'>" + titleNames[idx] + "</td>");
          					}
          					else{
          						out.print("<td rowspan = '" + consecutive[i][j] + "'>" + titleNames[idx] + "</td>");
          					}
          				}
          			}
          			out.println("</tr>");
          		}
          	%>
        </table>
    </div>
</body>
</html>