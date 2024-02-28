<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<%@ page import="jspbook.pr32.AddrBean" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="manager" class="jspbook.pr32.AddrManager" scope="application"/>
	<div align=center>
		<h2>주소록(그룹별 보기)</h2>
		<hr>
		<a href="addr_form.jsp">주소 추가</a> &nbsp;<a href="addr_list.jsp">전체 목록 보기</a>
		<h2>그룹:가족</h2>
		<table border=1>
			<tr>
				<td>이름</td>
				<td>전화번호</td>
				<td>이메일</td>
				<td>성별</td>
				<td>그룹</td>
			</tr>
				<%
					
					ArrayList<AddrBean> list = manager.getFamily();
					for (int i = 0; i < list.size(); i++){
						out.println("<tr>");
						out.println("<td>" + list.get(i).getUsername() + "</td>");
						out.println("<td>" + list.get(i).getTel() + "</td>");
						out.println("<td>" + list.get(i).getEmail() + "</td>");
						out.println("<td>" + list.get(i).getGender() + "</td>");
						out.println("<td>" + list.get(i).getGroup() + "</td>");
						out.println("</tr>");
					}
				%>
		</table>
		<h2>그룹:친구</h2>
		<table border=1>
			<tr>
				<td>이름</td>
				<td>전화번호</td>
				<td>이메일</td>
				<td>성별</td>
				<td>그룹</td>
			</tr>
				<%
					
					list = manager.getFriend();
					for (int i = 0; i < list.size(); i++){
						out.println("<tr>");
						out.println("<td>" + list.get(i).getUsername() + "</td>");
						out.println("<td>" + list.get(i).getTel() + "</td>");
						out.println("<td>" + list.get(i).getEmail() + "</td>");
						out.println("<td>" + list.get(i).getGender() + "</td>");
						out.println("<td>" + list.get(i).getGroup() + "</td>");
						out.println("</tr>");
					}
				%>
		</table>
		<h2>그룹:직장</h2>
		<table border=1>
			<tr>
				<td>이름</td>
				<td>전화번호</td>
				<td>이메일</td>
				<td>성별</td>
				<td>그룹</td>
			</tr>
				<%
					
					list = manager.getWork();
					for (int i = 0; i < list.size(); i++){
						out.println("<tr>");
						out.println("<td>" + list.get(i).getUsername() + "</td>");
						out.println("<td>" + list.get(i).getTel() + "</td>");
						out.println("<td>" + list.get(i).getEmail() + "</td>");
						out.println("<td>" + list.get(i).getGender() + "</td>");
						out.println("<td>" + list.get(i).getGroup() + "</td>");
						out.println("</tr>");
					}
				%>
		</table>
	</div>
</body>
</html>