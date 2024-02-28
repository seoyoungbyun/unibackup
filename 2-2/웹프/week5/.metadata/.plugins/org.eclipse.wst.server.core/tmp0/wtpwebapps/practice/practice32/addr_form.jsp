<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<style>
	table{width: 60%;}
	th>input {width: 90%}
	th, td{height: 30px;}
</style>
</head>
<body>
	<div align=center>
		<h2>주소록 등록</h2><hr>
		<form action="addr_add.jsp">
			<table border = 1>
				<tr>
					<td>이름</td>
					<th><input type=text class="text" name=username></th>
				</tr>
				<tr>
					<td>전화번호</td>
					<th class="text"><input type=text class="text" name=tel></th>
				</tr>
				<tr>
					<td>이메일</td>
					<th class="text"><input type=text class="text" name=email></th>
				</tr>
				<tr>
					<td>성별</td>
					<td> 
						<select name=gender>
							<option value="남" selected>남</option>
							<option value="여">여</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>그룹</td>
					<td> 
						<select name=group>
							<option value="가족">가족</option>
							<option value="친구">친구</option>
							<option value="직장">직장</option>
						</select>
					</td>
				</tr>
				<tr>
					<td colspan="2" id="exception"><div align=center><input type=submit value="확인"> <input type=reset value="취소"></div></td>
				</tr>
			</table>
		</form>
	</div>
</body>
</html>