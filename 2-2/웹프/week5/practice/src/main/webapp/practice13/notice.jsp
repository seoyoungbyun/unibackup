<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isErrorPage="true" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>오류 메시지</title>
<style>
        #title {
            width: 98%;
        }
        table, td {
        	width: 650px;
        	height: 300px;
        }
        th {
            background-color: #f5dbbd;
            height: 40px;
        }
        td {
            background-color: #faefd8;
        }
    </style>
</head>
<body>
	<div align = "center">
        <img src="pic/eclass_title.jpg" id = "title">
    </div>
    <div align = "center">
        <form name = "frm2">
            <table>
                <tr>
                    <th>오류가 발생했습니다</th>
                </tr>
                <tr>
                    <td>
                        <div align = "center">
                            <img src = "pic/flower.gif">
                            <p style = "font-weight: bold;">
                            오류 발생시간: <%= new java.util.Date() %><br>최대한 빨리 조치하겠습니다.
                            </p>
                        </div>
                    </td>
                </tr>
            </table>
        </form>
    </div>
</body>
</html>