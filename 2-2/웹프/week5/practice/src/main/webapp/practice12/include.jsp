<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 12</title>
</head>
<body>
	<div align="center">
	<h2>include 지시어 연습</h2>
	<hr>
	<p>
	<table>
		<tr>
			<td style="width:300px;height:90px;"><font size=-1><%@ include file="calendar.jsp" %></font></td>
			<td style="width:30px;"></td>
			<td style="width:100px;height:90px;"><%@ include file="news.jsp" %></td>
		</tr>
	</table>
	</div>
</body>
</html>