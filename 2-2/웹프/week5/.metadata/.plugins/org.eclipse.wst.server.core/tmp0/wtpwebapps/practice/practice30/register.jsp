<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>ch07</title>
</head>
<body>
	<div align=center>
		<h2>등록내용</h2>
		<jsp:useBean id = "login" class="jspbook.pr30.LoginBean" scope="page"/>
		<jsp:setProperty name="login" property="*"/>
		이름 : <jsp:getProperty name="login" property="id"/>
		<p>
		패스워드 : <jsp:getProperty name="login" property="pw"/>
		<p>
		이메일 : <jsp:getProperty name="login" property="email"/>
		<p>
		성별 : <jsp:getProperty name="login" property="gender"/>
		<p>
		생일 : <jsp:getProperty name="login" property="birth"/>
		<hr>
		<jsp:getProperty name="login" property="id"/>씨는 
		<%
			int gender = login.getGender();
			if (gender == 1){
				out.print("여성이고, ");
			}
			else{
				out.println("남성이고, ");
			}
			
			if (login.isGrownUp()){
				out.println("성인입니다.");
			}
			else{
				out.println("성인이 아닙니다.");
			}
		%>
	</div>
</body>
</html>