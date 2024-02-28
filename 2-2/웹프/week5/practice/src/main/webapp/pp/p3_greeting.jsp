<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>greeting</title>
</head>
<body>
	<h2>greeting에서 출력</h2>
	<% request.setCharacterEncoding("UTF-8"); %>
	${param.name }
	${param.date }
</body>
</html>