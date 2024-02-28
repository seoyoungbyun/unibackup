<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Calculator</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Bona+Nova&display=swap');
        .blue{
            height: 40px;
        }
        table {
        	width: 400px;
        }
        td.blue {
            font-family: 'Bona Nova';
            font-size: 35px;
            font-style: italic;
            text-align: center;
            background-color: #7bcaf9;
            font-weight: 580;
        }
    </style>
</head>
<body>
    <div align = center>
    <form method = "post" action = calc_result.jsp>
	    <table>
	        <tr>
	            <td colspan = "2" class = "blue">CalCuLaTor</td>
	        </tr>
	        <tr>
	            <td style = "border: 2px solid #f0f0f0;"><input type = image src = "pic/cal.jpg"></td>
	            <th width = 200 style="border: 2px solid #f0f0f0;">
	            	<input type = text value = "0" name = num1 style="text-align:center;width:100px;"><br><br>
	            	<select name = op>
	            		<option value = "+" selected>+</option>
	            		<option value = "-">-</option>
	            		<option value = "*">*</option>
	            		<option value = "/">/</option>
	            	</select><br><br>
	            	<input type = text value = "0" name = num2 style="text-align:center;width:100px;"><br><br>
	            	<input type = submit value="="><br><br>
	            	<input type = text disabled style="width:100px;">
	            </th>
	        </tr>
	        <tr>
	            <td colspan = "2" class = "blue"></td>
	        </tr>
	    </table>
    </form>
    </div>
</body>
</html>