<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>회원 가입</title>
    <style>
        table{
            border-collapse: collapse;
        }
        table, th, td{
            border: 1px solid black;
        }
        th {
            background-color: #ececec;
            text-align: center;
            font-weight: bold;
            width: 70px;
        }
        textarea{
            width: 98%;
            height: 70px;
        }
        .len {
            width: 530px;
        }
        #title {
            width: 98%;
        }
    </style>
</head>
<body>
    <div align = "center">
        <img src="pic/eclass_title.jpg" id = "title">
    </div>
    <div align = "center">
        <form action="register.jsp">
            <table>
                <tr>
                    <th colspan = "2" class = "len">회원 가입</th>
                </tr>
                <tr>
                    <th class = "gray">아이디</th>
                    <td>
                        <input type = text name="id">
                        <input type = image src = "pic/check.gif" style = "vertical-align: middle">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">패스워드</th>
                    <td><input type = password name="pw"></td>
                </tr>
                <tr>
                    <th class = "gray">성별</th>
                    <td>
                        <input type = radio name = gen value = 0 name="gender">남
                        <input type = radio name = gen value = 1 name="gender" checked>여
                    </td>
                </tr>
                <tr>
                    <th class = "gray">국적</th>
                    <td>
                        <input type = text value = "대한민국">
                        <input type = button value = "국적변경" disabled>
                    </td>
                </tr>
                <tr>
                    <th class = "gray">휴대폰</th>
                    <td>
                        <select name = phone>
                            <option value = 1 selected>010</option>
                            <option value = 2>011</option>
                            <option value = 3>017</option>
                            <option value = 4>070</option>
                            <option value = 5>080</option>
                        </select>
                        -
                        <input type = tel size = 5px maxlength = "4">
                        -
                        <input type = tel size = 5px maxlength = "4">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">이메일</th>
                    <td>
                        <input type = text name="email" size = 40px style = "width: 300px;">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">생일</th>
                    <td>
                        <input type = date name="birth">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">관심분야</th>
                    <td>
                        <input type = checkbox name = hobby value = 0>뉴스
                        <input type = checkbox name = hobby value = 1 checked>맛집
                        <input type = checkbox name = hobby value = 2>책
                        <input type = checkbox name = hobby value = 3>영화
                        <input type = checkbox name = hobby value = 4>여행
                    </td>
                </tr>
                <tr>
                    <th class = "gray">가입인사</th>
                    <td>
                        <textarea>회원들에게 간단한 가입인사를 남겨주세요</textarea>
                    </td>
                </tr>
                <tr>
                    <th class = "gray">증명사진</th>
                    <td><input type = file></td>
                </tr>
                <tr>
                    <th colspan = "2" class = "len">
                        <input type = "submit" value = "가입하기">
                        <input type = reset value = "다시작성">
                    </th>
                </tr>
            </table>
        </form>
    </div>
</body>
</html>