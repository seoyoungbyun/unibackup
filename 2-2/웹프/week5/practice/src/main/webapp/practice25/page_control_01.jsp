<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 04</title>
</head>
<body>
	<form method='post' action='page_control_02.jsp'>
		아이디: <input type=text name=username>비밀번호:<input type=text name=password> <input type=submit value='forward 전송'>
	</form>
	<form method='post' action='page_control_03.jsp'>
		아이디: <input type=text name=username>비밀번호:<input type=text name=password> <input type=submit value='sendRedirect 전송'>
	</form>
</body>
</html>