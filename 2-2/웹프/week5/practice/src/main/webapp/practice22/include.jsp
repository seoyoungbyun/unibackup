<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>include action</title>
</head>
<body>
	<div align=center>
		<h2>include 액션 연습</h2>
		<hr>
		<jsp:include page="greeting.jsp">
			<jsp:param name="name" value="Dongduk University" />
			<jsp:param name="date" value="2011/04/05" />
		</jsp:include>
	</div>
</body>
</html>