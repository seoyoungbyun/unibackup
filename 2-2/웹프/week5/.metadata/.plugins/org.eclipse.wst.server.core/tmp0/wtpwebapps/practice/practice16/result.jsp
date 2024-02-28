<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Enumeration" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 20</title>
</head>
<body>
<h2>전달된 파라미터 이름들</h2>
<%
	Enumeration<String> e = request.getParameterNames();

	while(e.hasMoreElements()){
		String name = e.nextElement();
		out.println(name + "<br>");
	}
	out.println("<hr>");
	
	e = request.getParameterNames();
	while(e.hasMoreElements()){
		String name = e.nextElement();
		String data = request.getParameter(name);
		
		switch(name){
			case "type":
				name = "타입";
				break;
			case "strID":
				name = "아이디";
				break;
			case "strPwd":
				name = "패스워드";
				break;
		}
		if (data != null){
			out.println(name + ":" + data + "<br>");
		}
	}
%>
</body>
</html>