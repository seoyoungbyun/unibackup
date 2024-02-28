<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Calendar" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Calendar</title>
</head>
<body>
<%
	int year = 1919;
	int month = 3;
	
	out.println("<h1>" + year + "년 " + month + "월</h1><hr>");
	Calendar cal = Calendar.getInstance();
	cal.set(year, (month - 1), 1);
	int day = cal.get(Calendar.DAY_OF_WEEK);
	
	int cnt = 0;
	for (int i = 0; i < (day - 1); i++){
		out.print(" &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
		cnt++;
	}
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	for (int i = day; i < (day + end); i++){
		out.print((i - day + 1) + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
		if (cnt % 7 == 6)
			out.print("<br>");
		cnt++;
	}
%>
</body>
</html>