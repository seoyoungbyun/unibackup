<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Enumeration" %>
<%@ page import="java.util.ArrayList" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 34</title>
</head>
<body>
	<h2>Processing Parameters</h2>
	<div>
		id: ${param.id}<br>
		pw: ${param.pw }<br>
		gender: ${param.gender }<br>
		phone1: ${param.phone1 }<br>
		phone2: ${param.phone2 }<br>
		phone3: ${param.phone3 }<br>
		email: ${param.email }<br>
		birth: ${param.birth }<br>
	<%
		String[] data = request.getParameterValues("hobby");
		if (data != null){
			session.setAttribute("len", data.length);
		}
		else{
			session.setAttribute("len", 0);
		}
	%>
		hobby: 선택된 관심분야 ${ sessionScope.len}개<br>
		&nbsp;&nbsp;&nbsp;[0]:${paramValues.hobby[0]}<br>
		&nbsp;&nbsp;&nbsp;[1]:${paramValues.hobby[1]}<br>
		&nbsp;&nbsp;&nbsp;[2]:${paramValues.hobby[2]}<br>
		&nbsp;&nbsp;&nbsp;[3]:${paramValues.hobby[3]}<br>
		&nbsp;&nbsp;&nbsp;[4]:${paramValues.hobby[4]}
		</div>
</body>
</html>