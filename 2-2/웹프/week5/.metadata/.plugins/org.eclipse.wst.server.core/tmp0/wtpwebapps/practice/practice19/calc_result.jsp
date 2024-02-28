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
	            <%
	            	String num1 = request.getParameter("num1");
	            	int n1 = Integer.parseInt(num1);
	            	String op = request.getParameter("op");
	            	String num2 = request.getParameter("num2");
	            	int n2 = Integer.parseInt(num2);
	            	int result = 0;
	            	switch(op){
	            		case "+":
	            			result = n1 + n2;
	            			break;
	            		case "-":
	            			result = n1 - n2;
	            			break;
	            		case "*":
	            			result = n1 * n2;
	            			break;
	            		case "/":
	            			result = n1 / n2;
	            			break;
	            	}
	            	
	            	out.println("<input type = text value =" + num1 + " style='text-align:center;width:100px;' readonly><br><br>");
	            	out.println(op + "<br><br>");
	            	out.println("<input type = text value =" + num2 + " style='text-align:center;width:100px;' readonly><br><br>");
            		out.println("=<br><br>");
            		out.println("<input type = text value = " + result + " style='text-align:center;width:100px;' readonly>");
	            %>
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