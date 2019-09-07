<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Main Menu</title>
</head>
<body style="background-color: #284B63">
	<%
		request.setCharacterEncoding("UTF-8");
		String id = (String) session.getAttribute("id");
	%>
		<h1>MENU</h1>
		<hr>
		<font color="white"><%=id%></font>님, 반가워요~!
		<hr>
		<p>
		<ol start = "1">
			<li><a href="phone.jsp"><font color="white">Phones</font></a></li>
			<li><a href="tablet.jsp"><font color="white">Tablets</font></a></li>
			<li><a href="basket.jsp"><font color="white">장바구니</font></a></li>
			<li><a href="logout.jsp"><font color="white">로그아웃</font></a></li>
		</ol>
</body>
</html>