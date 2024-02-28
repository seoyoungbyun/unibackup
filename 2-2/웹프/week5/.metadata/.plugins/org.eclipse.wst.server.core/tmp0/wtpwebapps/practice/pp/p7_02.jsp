<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	${param.username }
	세셔id : <%=session.getId() %>
	세션 지속시간: <%=session.getMaxInactiveInterval() %>초
	<a href="p7_03.jsp">p7_03</a>
</body>
</html>