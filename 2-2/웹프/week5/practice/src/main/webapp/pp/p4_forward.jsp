<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>forward</title>
</head>
<body>
	<h2>forward</h2>
	<jsp:forward page="p4_greeting.jsp">
		<jsp:param name="name" value="DongdukUniversity"/>
		<jsp:param name="date" value="2011/04/03"/>
	</jsp:forward>
</body>
</html>