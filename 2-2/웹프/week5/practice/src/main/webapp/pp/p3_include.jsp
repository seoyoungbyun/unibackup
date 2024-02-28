<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Include</title>
</head>
<body>
	<h3>include 액션 연습</h3><hr>
	<jsp:include page="p3_greeting.jsp">
		<jsp:param name="name" value="DongdukUniversity"/>
		<jsp:param name="date" value="2011/04/03"/>
	</jsp:include>
</body>
</html>