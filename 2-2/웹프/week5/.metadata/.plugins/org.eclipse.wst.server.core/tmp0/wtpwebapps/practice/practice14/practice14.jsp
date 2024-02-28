<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Calendar" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 14</title>
</head>
<body>
<%! String[] dayString = {"", "일", "월", "화", "수", "목", "금", "토"}; %>
<%
	Calendar cal = Calendar.getInstance();
	int year = cal.get(Calendar.YEAR);
	int month = cal.get(Calendar.MONTH);
	int date = cal.get(Calendar.DATE);
	int day = cal.get(Calendar.DAY_OF_WEEK);
	
	out.print("오늘은 " + year + "년 " + (month + 1) + "월 " + date + "일 " + dayString[day] + "요일입니다.<br>");
	
	int start = cal.getMinimum(Calendar.DATE);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	out.println("이번 달은 " + start + "부터 시작하여 " + end + "일에 끝납니다.<br>");
	
	cal.set(2003, Calendar.NOVEMBER, 15);
	year = cal.get(Calendar.YEAR);
	month = cal.get(Calendar.MONTH);
	date = cal.get(Calendar.DATE);
	day = cal.get(Calendar.DAY_OF_WEEK);
	out.print("내 생일 " + year + "년 " + (month + 1) + "월 " + date + "일은 " + dayString[day] + "요일입니다.<br>");
%>
</body>
</html>