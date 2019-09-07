<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>설문조사 3</title>
</head>
<body style="background-color: #4ECDC4">
	<%
		request.setCharacterEncoding("UTF-8");
		String name = (String) session.getAttribute("id");
		String reason = request.getParameter("reason");
		session.setAttribute("reason", reason);
	%>
	<form method="post" action="f.jsp">
		<h2>지금 서비스를 연장하시면 50% 할인된 금액에 서비스를 이용하실 수 있습니다.</h2>
		<div align = "right"><b><%=name %></b> 님</div>
		<h3>회원 연장하시겠습니까?</h3>
		
		<input type="checkbox" name="choice" value="네" />네<br>
		<input type="checkbox" name="choice" value="아니요" />아니요
		<p>
			<input type="submit" value="제출">
	</form>
</body>
</html>