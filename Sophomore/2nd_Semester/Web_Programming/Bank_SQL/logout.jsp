<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		String id = (String) session.getAttribute("id");
		session.invalidate();
	%>
	<div align="center">
	<h3>로그아웃하셨습니다. <font color="blue"><%=id%></font>님, 또 방문해 주세요!</h3><p>
	첫 화면으로 가시려면 아래 그림을 클릭해 주세요~ <br>
	<a href="login.jsp"><img src = "ironman.jpg" width="500" height="300" alt="!image load fail!"></a>
	</div>
</body>
</html>