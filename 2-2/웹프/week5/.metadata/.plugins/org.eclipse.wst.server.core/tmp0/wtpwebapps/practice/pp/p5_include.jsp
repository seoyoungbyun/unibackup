<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<table align=center>
		<tr>
			<th colspan=2>include action</th>
		</tr>
		<tr>
			<td><jsp:include page="calendar.jsp"><jsp:param name="YEAR" value="2013"/><jsp:param name="MONTH" value="11"/></jsp:include></td>
			<td>
			<jsp:include page="new.jsp">
				<jsp:param name="TASK2" value="22"/>
			</jsp:include>
			</td>
		</tr>
	</table>
</body>
</html>