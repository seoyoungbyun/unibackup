<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<%@ page import="jspbook.pr36.LectureBean" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean id="info" class="jspbook.pr36.LectureBean"/>
	<jsp:useBean id="manage" class="jspbook.pr36.LectureManager" scope="session"/>
	<jsp:setProperty name="info" property="*"/>
	<jsp:setProperty name="manage" property="*"/>
<%
	if (info.getTitle() != -1){
		manage.add(info);
	}
%>
	
	<form action="practice36.jsp">
		과목타입 : <select name=type>
		<option value=0>전공필수</option>
		<option value=1>전공선택</option>
		<option value=2>교양</option>
		<option value=3>자유선택</option>
		</select>
		과목명 : <select name=title>
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
	ArrayList<LectureBean> list = (ArrayList<LectureBean>)manage.getLectureList();
	String slist = "";
	if (list != null){
		for (int i = 0; i < list.size(); i++){
			slist += list.get(i).toString() + "<br>";
		}
	}
%>
	<div align=center><%=slist %></div>
</body>
</html>