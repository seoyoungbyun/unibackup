<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Date" %>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Application Object: 02</title>
</head>
<body>
<%
	String name = request.getParameter("id");
	out.println(name + "님 환영합니다.<br>");
	out.println("현재 시간: " + new Date() + "<br>");
	Integer count = (Integer)application.getAttribute("count");
	if (count == null){
		count =0;
	}
	
	count++;
	application.setAttribute("count", count);
	out.println("오늘의 접속자수: " + count);
	
%>
</body>
</html>