<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	String name = request.getParameter("username");
	String tel = request.getParameter("tel");
	String email = request.getParameter("email");
	String gender = request.getParameter("gender");
%>
	<div align=center>
		<h2>등록내용</h2>
		이름:<%=name %><br>
		전화번호:<%=tel %><br>
		이메일:<%=email %><br>
		성별:<%=gender %>
		<hr>
		<a href="addr_list.jsp">목록 보기</a> &nbsp;<a href="addr_form.jsp">주소 추가</a>
	</div>
<%
	String p = name + "/" + tel + "/" + email + "/" + gender;
	ArrayList<String> sadd = (ArrayList<String>)application.getAttribute("addrbook");
	if (sadd == null){
		sadd = new ArrayList<String>();
	}
	else{
		sadd.add(p);
	}
	application.setAttribute("addrbook", sadd);
%>
</body>
</html>