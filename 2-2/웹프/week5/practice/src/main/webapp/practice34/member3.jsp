<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
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
        <form method = "post" action = "practice34.jsp">
            <table>
                <tr>
                    <th colspan = "2" class = "len">회원 가입</th>
                </tr>
                <tr>
                    <th class = "gray">아이디</th>
                    <td>
                        <input type = text name = id>
                        <input type = image src = "pic/check.gif" style = "vertical-align: middle">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">패스워드</th>
                    <td><input type = password name=pw></td>
                </tr>
                <tr>
                    <th class = "gray">성별</th>
                    <td>
                        <input type = radio name = gender value = "남성">남
                        <input type = radio name = gender value = "여성" checked>여
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
                        <select name = phone1>
                            <option value = "010" selected>010</option>
                            <option value = "011">011</option>
                            <option value = "017">017</option>
                            <option value = "070">070</option>
                        </select>
                        -
                        <input type = tel name = phone2 size = 5px maxlength = "4">
                        -
                        <input type = tel name = phone3 size = 5px maxlength = "4">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">이메일</th>
                    <td>
                        <input type = text name=email size = 40px style = "width: 300px;">
                    </td>
                </tr>
                <tr>
                    <th class = "gray">생일</th>
                    <td>
                        <input type = date name=birth>
                    </td>
                </tr>
                <tr>
                    <th class = "gray">관심분야</th>
                    <td>
                        <input type = checkbox name = hobby value = "뉴스">뉴스
                        <input type = checkbox name = hobby value = "맛집" checked>맛집
                        <input type = checkbox name = hobby value = "책">책
                        <input type = checkbox name = hobby value = "영화">영화
                        <input type = checkbox name = hobby value = "여행">여행
                    </td>
                </tr>
                <tr>
                    <th class = "gray">가입인사</th>
                    <td>
                        <textarea name=memo>회원들에게 간단한 가입인사를 남겨주세요</textarea>
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