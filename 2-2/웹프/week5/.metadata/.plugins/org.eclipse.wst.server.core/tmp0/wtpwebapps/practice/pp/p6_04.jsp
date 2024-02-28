<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>04</title>
</head>
<body>
	<%request.setCharacterEncoding("UTF-8"); %>
	${param.src }
	<hr>
	<%@ page import="java.util.Enumeration" %>
	<%
		Enumeration<String> e = request.getParameterNames();
		while (e.hasMoreElements()){
			String name = e.nextElement();
			String value = (String)request.getParameter(name);
			out.println(name + ":" + value + "<br>");
		}
	%>
	${param.username }
</body>
</html>