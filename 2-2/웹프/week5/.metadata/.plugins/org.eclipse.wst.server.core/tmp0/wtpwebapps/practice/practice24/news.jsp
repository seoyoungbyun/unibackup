<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>news.jsp</title>
</head>
<body>
<%
	String task1 = request.getParameter("TASK1");
	String task2 = request.getParameter("TASK2");
	if (task1 == null){
		task1 = "일정 없음";
	}
	if (task2 == null){
		task2 = "일정 없음";
	}
%>
	<div align=center><h2>오늘의 일정</h2></div>
	<hr>
	<ol style='width:400px;margin-left:auto;margin-right:auto;'>
		<li><%=task1 %></li>
		<li><%=task2 %></li>
	</ol>
</body>
</html>