<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Calendar" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>calendar.jsp</title>
<%
	out.println("<style>");
	out.println("th, td { width: 90px; height: 30px; text-align: center;}");
	out.println("</style>");
%>
</head>
<body>
<%!
	public String parseDay(int cnt, String day)
	{
		if (cnt % 7 == 0){
			return "<font color='red'>" + day + "</font>";
		}
		else if (cnt % 7 == 6){
			return "<font color='blue'>" + day + "</font>";
		}
		else{
			return day;
		}
	}
%>
<%
	Calendar today = Calendar.getInstance();

	int year = today.get(Calendar.YEAR);
	int month = today.get(Calendar.MONTH);
	int date = today.get(Calendar.DATE);
	Calendar cal = Calendar.getInstance();
	out.println("<div align = center>");
	out.println("<table>");
	out.println("<tr>");
	for (int i = 0; i < 6; i++){
		out.println("<td></td>");
	}
	out.println("<td><h4>" + year + "-" + (month + 1) + "-" + date + "</h4></td></tr></table></div>");
	cal.set(year, month, 1);
	
	int cnt = 0;
	out.println("<div align = center>");
	out.println("<table border=1 style='border-collapse: collapse;'>");
	out.println("<tr>");
	out.println("<th>" + parseDay(cnt++, "일") + "</th>");
	out.println("<th>" + parseDay(cnt++, "월") + "</th>");
	out.println("<th>" + parseDay(cnt++, "화") + "</th>");
	out.println("<th>" + parseDay(cnt++, "수") + "</th>");
	out.println("<th>" + parseDay(cnt++, "목") + "</th>");
	out.println("<th>" + parseDay(cnt++, "금") + "</th>");
	out.println("<th>" + parseDay(cnt++, "토") + "</th>");
	out.println("</tr>");
	
	out.println("<tr>");
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
	out.println("</tr>");
	out.println("</table>");
	out.println("</div>");
%>
</body>
</html>