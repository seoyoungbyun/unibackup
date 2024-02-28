<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>include_action.jsp</title>
</head>
<body>
<div align="center">
	<h2>Include Action Practice</h2>
	<hr>
	<p>
	<table>
		<tr>
			<td style="width:300px;height:90px;"><font size=-1>
				<jsp:include page="calendar.jsp">
					<jsp:param name="YEAR" value="2017" />
					<jsp:param name="MONTH" value="10" />
				</jsp:include>
			</font></td>
			<td style="width:30px;"></td>
			<td style="width:100px;height:90px;">
				<jsp:include page="news.jsp">
					<jsp:param name="TASK1" value="첫 번째 일정" />
					<jsp:param name="TASK2" value="두 번째 일정" />
				</jsp:include>
			</td>
		</tr>
	</table>
	</div>
</body>
</html>