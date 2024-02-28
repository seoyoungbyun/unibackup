<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%request.setCharacterEncoding("UTF-8"); %>
	<jsp:useBean id="login" class="jspbook.pr30.LoginBean" scope="page"/>
	<jsp:setProperty name="login" property="*"/>
	
	<h2>등록내용</h2>
	이름:<jsp:getProperty name="login" property="id"/>
	패스워드:<jsp:getProperty name="login" property="passwd"/>
	이메일:<jsp:getProperty name="login" property="email"/>
	성별:<jsp:getProperty name="login" property="gender"/>
	생일:<jsp:getProperty name="login" property="birth"/>
	
<%
	if (login.isGrownUp()){
		out.println("성인");
	}
	else{
		out.println("child");
	}
	if ()
%>
</body>
</html>