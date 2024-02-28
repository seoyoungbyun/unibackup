<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.List" %>
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
	String[] typeNames = {"전공필수","전공선택","교양","자유선택"};
	String[] titleNames = {"웹프로그래밍","운영체제","소프트웨어프로그래밍","데이터베이스개론","자료구조","네트워크","창의와감성","사회봉사"};
	String[] days = {"월","화","수","목","금"};
	
	String sType = request.getParameter("lectureType");
	String sTitle = request.getParameter("lectureTitle");
	String sday = request.getParameter("day");
	String stime = request.getParameter("time");
	String sconsecutive = request.getParameter("consecutive");
	
	if (sType != null && sTitle != null && sday != null && stime != null && sconsecutive != null){
		int type = Integer.parseInt(sType);
		int title = Integer.parseInt(sTitle);
		int day = Integer.parseInt(sday);
		
		String s = typeNames[type] + "/" + titleNames[title] + "/" + days[day] + "/" + stime + "/" + sconsecutive;
		ArrayList<String> sadd = (ArrayList<String>)session.getAttribute("timetable");
		if (sadd == null){
			sadd = new ArrayList<String>();
		}
		sadd.add(s);
		session.setAttribute("timetable", sadd);
	}
%>
	<form action="practice29.jsp">
		과목타입 : <select name=lectureType>
		<option value=0>전공필수</option>
		<option value=1>전공선택</option>
		<option value=2>교양</option>
		<option value=3>자유선택</option>
		</select>
		과목명 : <select name=lectureTitle>
		<option value=0>웹프로그래밍</option>
		<option value=1>운영체제</option>
		<option value=2>소프트웨어프로그래밍</option>
		<option value=3>데이터베이스개론</option>
		<option value=4>자료구조</option>
		<option value=5>네트워크</option>
		<option value=6>창의와감성</option>
		<option value=7>사회봉사</option>
		</select>
		요일 : <select name=day>
		<option value=0>월</option>
		<option value=1>화</option>
		<option value=2>수</option>
		<option value=3>목</option>
		<option value=4>금</option> 
		</select>
		시간 : <select name=time>
		<option value=1>1</option>
		<option value=2>2</option>
		<option value=3>3</option>
		<option value=4>4</option>
		<option value=5>5</option>
		<option value=6>6</option>
		</select>
		연강여부 : <select name=consecutive>
		<option value=1>1</option>
		<option value=2>2</option>
		<option value=3>3</option>
		<option value=4>4</option>
		<option value=5>5</option>
		<option value=6>6</option>
		</select>
		&nbsp;&nbsp;
		<input type=submit value="등록">
		<hr>
	</form>
<%
	ArrayList<String> list = (ArrayList<String>)session.getAttribute("timetable");
	if (list != null){
		out.println("<div align=center>");
		for (int i = 0; i < list.size(); i++){
			out.println(list.get(i) + "<br>");
		}
		out.println("</div>");
	}
%>
</body>
</html>