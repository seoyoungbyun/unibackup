<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>이클래스 로그인</title>
    <style>
        #title {
            width: 98%;
        }
        #logo, #table, h5 {
            display: inline-block;
        }
        .input {
            width: 180px;
            background-color: #fdfea7;
            box-shadow: -2px -2px #a1a1a1;
            border-color: #ebebdd;
        }
        td{
            height: 40px;
        }
        #string {
            height: 10px;
        }
    </style>
</head>
<body>
    <div align = "center">
        <img src="pic/eclass_title.jpg" id = "title">
        <h2>로그인</h2>
        <hr>
    </div>
    <div align = "center">
        <img src = "pic/eclass_logo.png" id = "logo">
        <div id = "table">
            <form name = "frm1" method = "post" action = "result.jsp">
                <table>
                    <tr id = "string">
                        <th colspan = "2">회원님의 아이디와 비밀번호를 정확히 입력하세요.</th>
                    </tr>
                    <tr>
                        <td></td>
                        <td>
                            <select name="type" style = "width: 80px;">
                                <option value="학부생" selected>학부생</option>
                                <option value="대학원생">대학원생</option>
                                <option value="교직원">교직원</option>
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td style = "font-weight: bold;">아이디</td>
                        <td><input type = "text" name = "strID" class = "input" maxlength="20"></td>
                    </tr>
                    <tr>
                        <td style = "font-weight: bold">비밀번호</td>
                        <td><input type = "password" name = "strPwd" class = "input" maxlength="20"></td>
                    </tr>
                    <tr>
                        <td colspan = "2">
                            <input type = "submit" value = "로그인">
                            <input type = "button" value = "가입하기">
                        </td>
                    </tr>
                </table>
            </form>
        </div>
    </div>
</body>
</html>