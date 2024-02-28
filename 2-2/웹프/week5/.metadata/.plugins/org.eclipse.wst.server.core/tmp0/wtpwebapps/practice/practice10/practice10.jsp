<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 10</title>
<style>
	td{ 
		width: 90px;
		height: 30px;
		text-align: center;
		font-weight: bold;
	}
</style>
</head>
<body>
<%
	out.println("<div align = center>");
	out.println("<table border=1>");
	out.println("<tr>");
	out.println("<td><font color = red>일</font></td>");
	out.println("<td>월</td>");
	out.println("<td>화</td>");
	out.println("<td>수</td>");
	out.println("<td>목</td>");
	out.println("<td>금</td>");
	out.println("<td><font color = blue>토</font></td>");
	for (int i = 0; i < 4; i++){
		out.println("<tr>");
		for (int j = 0; j < 7; j++){
			out.println("<td> &nbsp; </td>");
		}
		out.println("</tr>");
	}
	out.println("</table>");
	out.println("</div>");
%>
</body>
</html>
