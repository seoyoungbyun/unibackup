<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<div align=center>
		<h2>주소록</h2>
		<hr>
		<ol>
			<%
				ArrayList<String> list = (ArrayList<String>)application.getAttribute("addrbook");
				for (int i = 0; i < list.size(); i++){
					out.println("<li>" + list.get(i) + "</li>");
				}
			%>
		</ol>
		<hr>
		<a href="addr_form.jsp">주소추가</a>
	</div>
</body>
</html>