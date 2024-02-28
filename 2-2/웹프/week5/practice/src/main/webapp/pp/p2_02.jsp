<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<% request.setCharacterEncoding("UTF-8"); %>
<%
	String name = request.getParameter("id");
%>
	<%=name %>님 환영합니다.<p>
	현재시간: <%=new java.util.Date() %>
<%
	Integer count = (Integer)application.getAttribute("count");
	if (count == null){
		count = new Integer(0);
	}
	count++;
	application.setAttribute("count", count);
	
%>
	오늘의 접속자수: ${applicationScope.count }
</body>
</html>