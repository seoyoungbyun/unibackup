<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>계산기</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Bona+Nova&display=swap');
        .blue{
            height: 40px;
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
    <script type="text/javascript">
        function calc(){
            var exp = prompt("계산할 수식을 입력하세요")
            if (exp != null){
                var result = eval(exp)
                alert(result)
            }
        }
    </script>
</head>
<body>
	<jsp:useBean id="calc" class="jspbook.pr31.Calculator"/>
	<jsp:setProperty name="calc" property="*"/>
    <div align = center>
    <form method=post action="calc_result.jsp">
	    <table width = 400px>
	        <tr>
	            <td colspan = "2" class = "blue">CalCuLaTor</td>
	        </tr>
	        <tr>
	            <td style = "border: 2px solid #f0f0f0;"><input type = image src = "pic/cal.jpg"></td>
	            <th width = 200 style="border: 2px solid #f0f0f0;">
	            	<input type="text" name="num1" value="<%=calc.getNum1() %>" style="text-align:center"><p>
	            	<jsp:getProperty name="calc" property="op"/><p>
	            	<input type="text" name="num2" value="<%=calc.getNum2() %>" style="text-align:center"><p>
	            	=<p>
	            	<input type="text" value="<%=calc.calc() %>" style="text-align:center">
	            </th>
	        </tr>
	        <tr>
	            <td colspan = "2" class = "blue"></td>
	        </tr>
	    </table>
    </form>
    <%int result = calc.calc();
    	out.println(result);%>
    </div>
</body>
</html>