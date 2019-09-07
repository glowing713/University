<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body style="background-color: #E0F8F7">
	<%
		String id = (String) session.getAttribute("id");
	%>
	<div align="center">
	<h2>이 체</h2>
	<hr><font color="blue"><%=id%></font>님, 누구에게 얼마를 이체하시겠습니까?<hr><p>
	<form method="post" action="transfer_check.jsp">
	ID: <input type = "text" name = "receiver">
	<br>
	출금: <input type = "text" name = "transfer">원 <p>
	<input type = "submit" value = "송금진행">
	</form>
	<a href="menu.jsp">메뉴로 돌아가기</a>
	</div>
</body>
</html>