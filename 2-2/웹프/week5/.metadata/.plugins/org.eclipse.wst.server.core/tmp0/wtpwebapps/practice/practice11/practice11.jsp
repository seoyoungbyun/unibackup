<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 11</title>
</head>
<body>
<%
	out.println("<div align=center><h1>구구단 출력</h1>");
	out.println("<hr>");
	
	int num = 2;
	out.println("<table border=1>");
	for (int i = 1; i <= 2; i++){
		out.println("<tr>");
		for (int j = 1; j <= 4; j++){
			out.println("<td style='width:100px;height:220px;'>");
			for (int k = 1; k <= 9; k++){
				out.println("&nbsp;&nbsp;" + num + " * " + k + " = " + num * k + "<br>");
			}
			out.println("</td>");
			num++;
		}
		out.println("</tr>");
	}
	out.println("</table><div>");
%>
</body>
</html>