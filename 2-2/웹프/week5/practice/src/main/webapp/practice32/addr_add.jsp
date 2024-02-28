<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="bean" class="jspbook.pr32.AddrBean"/>
	<jsp:useBean id="manager" class="jspbook.pr32.AddrManager" scope="application"/>
	<jsp:setProperty name="bean" property="*"/>
	<jsp:setProperty name="manager" property="*"/>
	<%
		manager.add(bean);
	%>
	<div align=center>
		<h2>등록내용</h2>
		이름:<jsp:getProperty name="bean" property="username"/>
		<p>
		전화번호:<jsp:getProperty name="bean" property="tel"/>
		<p>
		이메일:<jsp:getProperty name="bean" property="email"/>
		<p>
		성별:<jsp:getProperty name="bean" property="gender"/>
		<p>
		그룹:<jsp:getProperty name="bean" property="group"/>
		<hr>
		<a href="addr_form.jsp">주소 추가</a> &nbsp;<a href="addr_list.jsp">전체 목록 보기</a> &nbsp;<a href="addr_list_group.jsp">그룹별 목록 보기</a>
	</div>
</body>
</html>