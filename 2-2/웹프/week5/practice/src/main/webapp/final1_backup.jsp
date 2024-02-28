<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Calendar" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>calendar.jsp</title>
<style>
	th, td { width: 100px; height: 30px; text-align: center;}

</style>
</head>
<body>
<%!
	public String parseDay(int cnt, String day)
	{
		if (cnt % 7 == 0){
			return "<font color='red'>" + day + "</font>";
		}
		else{
			return day;
		}
	}
%>
<!--  <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<c:set var="today" value="<%= Calendar.getInstance() %>" />
<c:set var="ipDate" value="${param.input_date}" />
<c:set var="year" value="${today.get(Calendar.YEAR)}" />
<c:set var="month" value="${today.get(Calendar.MONTH)}" />
<c:set var="date" value="${today.get(Calendar.DATE)}" />

<c:set var="cnt" value="0" />

<c:set var="cal" value="<%= Calendar.getInstance() %>" />
<c:set var="y" value="${year}" />

<c:choose>
    <c:when test="${param.YEAR != null}">
        <c:set var="y" value="${param.YEAR}" />
    </c:when>
</c:choose>

<c:set var="m" value="${month}" />

<c:choose>
    <c:when test="${param.MONTH != null}">
        <c:set var="m" value="${param.MONTH}" />
    </c:when>
</c:choose>

<c:choose>
    <c:when test="${ipDate != null && ipDate != ''}">
        <c:set var="input" value="${ipDate.split('-')}" />
        <c:set var="y" value="${input[0]}" />
        <c:set var="m" value="${input[1] - 1}" />
    </c:when>
</c:choose>
-->
<%
	Calendar today = Calendar.getInstance();
	String ipDate = request.getParameter("input_date");
	int year = today.get(Calendar.YEAR);
	int month = today.get(Calendar.MONTH);
	int date = today.get(Calendar.DATE);
	
	int cnt = 0;
	
	Calendar cal = Calendar.getInstance();
	int y = year;
	String sYear = request.getParameter("YEAR");
	if (sYear != null){
		y = Integer.parseInt(sYear);
	}
	
	int m = month;
	String sMonth = request.getParameter("MONTH");
	if (sMonth != null){
		m = Integer.parseInt(sMonth);
	}
	
	if (ipDate != null && ipDate != ""){
		String[] input = ipDate.split("-");
		y = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]) - 1;
	}
%>

	<form action='calendar.jsp'>
		이동할 날짜 선택: <input type='date' name="input_date"> <input type="submit" value="입력">
	</form>
	
	<div align = center>
		<form method=get action='calendar.jsp'>
		<table>
			<tr>
				<td></td> 
				<td>&nbsp;</td>
				<td>&nbsp;</td>
<%
	
	if (m == 0)
	{
		out.print("<td>◀ ");
		out.print((m + 1) + "월");
		out.print("<a href=\'calendar.jsp?YEAR=" + y);
		out.println("&MONTH=" + (m + 1) + "\'>" + " ▶</a></td>"); 
	}
	else if (m == 11){
		out.print("<td><a href=\'calendar.jsp?YEAR=" + y);
		out.print("&MONTH=" + (m - 1) + "\'>" + "◀ </a>"); 
		out.print((m + 1) + "월");
		out.println(" ▶</td>"); 
	}
	else{
		out.print("<td><a href=\'calendar.jsp?YEAR=" + y);
		out.print("&MONTH=" + (m - 1) + "\'>" + "◀ </a>"); 
		out.print((m + 1) + "월");
		out.print("<a href=\'calendar.jsp?YEAR=" + y);
		out.println("&MONTH=" + (m + 1) + "\'>" + " ▶</a></td>"); 
	}
	
	out.println("<td>&nbsp;</td>");
	out.println("<td>&nbsp;</td>");
	
	out.println("<td><h4>" + year + "-" + (month + 1) + "-" + date + "</h4></td></tr></table></form></div>");
	cal.set(y, m, 1);
	
%>
	<div align = center>
	<table border=1 style='border-collapse: collapse;'>
		<tr>
			<td><%=parseDay(cnt++, "일")%></td>
			<td><%=parseDay(cnt++, "월")%></td>
			<td><%=parseDay(cnt++, "화")%></td>
			<td><%=parseDay(cnt++, "수")%></td>
			<td><%=parseDay(cnt++, "목")%></td>
			<td><%=parseDay(cnt++, "금")%></td>
			<td><%=parseDay(cnt++, "토")%></td>
		</tr>
		<tr>
<%
	int day = cal.get(Calendar.DAY_OF_WEEK);
	for (int i = 0; i < day - 1; i++){
		out.print("<td>&nbsp;</td>");
		cnt++;
	}
	
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	for (int i = day; i < (day + end); i++){
		out.print("<td>" + parseDay(cnt++, Integer.toString(i - day + 1)) + "</td>");
		if (i % 7 == 0){
			out.println("</tr>");
			out.println("<tr>");
		}
	}
	while (cnt % 7 != 0)
	{
		out.print("<td>&nbsp;</td>");
		cnt++;
	}
%>
	</tr>
	</table>
	</div>
</body>
</html>