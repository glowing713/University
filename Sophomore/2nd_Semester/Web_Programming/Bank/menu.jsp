<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body style="background-color: #F79B65">
	<%
		request.setCharacterEncoding("UTF-8");
		String id = (String) session.getAttribute("id");
	%>
		<h1>MENU</h1>
		<hr>
		<font color="blue"><%=id%></font>님, 반가워요~!
		<hr>
		<p>
		<ol start = "1">
			<li><a href="in.jsp">입금</a></li>
			<li><a href="out.jsp">출금</a></li>
			<li><a href="Myaccount.jsp">나의 거래</a></li>
			<li><a href="logout.jsp">로그아웃</a></li>
		</ol>
</body>
</html>