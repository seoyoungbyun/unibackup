<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
	<h2>오늘의 일정</h2>
	<hr>
	<ol>
		<li><c:out value="${param['TASK1'] }">일정없음</c:out></li>
		<li><c:out value="${param['TASK2'] }"/></li>
	</ol>
</body>
</html>