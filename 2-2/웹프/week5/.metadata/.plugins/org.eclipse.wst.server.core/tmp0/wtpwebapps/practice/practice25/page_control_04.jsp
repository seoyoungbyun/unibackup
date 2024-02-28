<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Enumeration" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 04</title>
</head>
<body>
<%
	String src = request.getParameter("src");
	out.println(src + "에서 전달된 내용입니다.<br>");
	String userName = request.getParameter("username");
%>
	page_control_04.jsp에서 출력합니다.
	<hr>
	넘겨받은 파라미터들<br>
<%
	Enumeration<String> e = request.getParameterNames();
	while (e.hasMoreElements()){
		String s = e.nextElement();
		out.println(s + " : " + request.getParameter(s) + "<br>");
	}
%>
	<hr>
	안녕하세요, <%=userName %>님. 반갑습니다.
	<hr>
</body>
</html>