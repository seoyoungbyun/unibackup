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
<title>Practice 22</title>
</head>
<body>
	<h2>Processing Parameters</h2>
	id: ${param.id }<p>
	pw: ${param.pw }<p>
	gender: ${param.gender }<p>
	phone1: ${param.phone1 }<p>
	phone2: ${param.phone2 }<p>
	phone3: ${param.phone3 }<p>
	email: ${param.email }<p>
	birth: ${param.birth }<p>
	<%@ page import="java.util.Enumeration" %>
	<% 
		String[] hobby = request.getParameterValues("hobby");
		int count = 0;
		if (hobby != null){
			session.setAttribute("hobby", hobby);
			count = hobby.length;
		}
	%>
	hobby: ${count }<p>
	[0]:${sessionScope.hobby[0] }
	[1]:${sessionScope.hobby[1] }
	[2]:${sessionScope.hobby[2] }
	[3]:${sessionScope.hobby[3] }
	[4]:${sessionScope.hobby[4] }
	
</body>
</html>