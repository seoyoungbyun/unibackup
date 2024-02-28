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
<title>Calendar</title>
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
	if (sYear != null && sYear != ""){
		y = Integer.parseInt(sYear);
	}
	
	int m = month;
	String sMonth = request.getParameter("MONTH");
	if (sMonth != null && !sMonth.equals("")){
		m = Integer.parseInt(sMonth);
	}
	
	if (ipDate != null && ipDate != ""){
		String[] input = ipDate.split("-");
		y = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]) - 1;
	}
	
	pageContext.setAttribute("m", m);
%>
	<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
	<form action='calendar.jsp'>
		이동할 날짜 선택: <input type='date' name="input_date"> <input type="submit" value="입력">
	</form>
	<div align = center>
		<form method=get action='calendar.jsp'>
		<table>
			<tr>
				<td>
					<a href="calendar.jsp?YEAR=<%=y-1 %>&MONTH=<%=m %>">◀ </a>
					<%=y %>년
					<a href="calendar.jsp?YEAR=<%=y+1%>&MONTH=<%=m %>"> ▶</a>
				</td> 
				<td>&nbsp;</td>
				<td>
					<c:choose>
						<c:when test="${m == 0 }">
							<td>
								◀ <%=m+1 %>월<a href="calendar.jsp?YEAR=<%=y %>&MONTH=<%=m+1 %>"> ▶</a>
							</td> 
						</c:when>
						<c:when test="${m == 11 }">
							<td>
								<a href="calendar.jsp?YEAR=<%=y %>&MONTH=${m-1 }">◀ </a><%=m+1 %>월 ▶
							</td> 
						</c:when>
						<c:otherwise>
							<td>
								<a href="calendar.jsp?YEAR=<%=y %>&MONTH=<%=m-1 %>">◀ </a>
								<%=m+1 %>월
								<a href="calendar.jsp?YEAR=<%=y%>&MONTH=<%=m+1 %>"> ▶</a>
							</td> 
						</c:otherwise>
					</c:choose>
				</td>
				<td>&nbsp;</td>
				<td>&nbsp;</td>
				<td>
					<h4><%=year%>-<%=month + 1%>-<%=date%></h4>
				</td>
			</tr>
		</table>
		</form>
	</div>
<%
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