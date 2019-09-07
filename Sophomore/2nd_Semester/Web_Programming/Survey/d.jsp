<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>설문조사 2</title>
</head>
<body style="background-color: #4ECDC4">
	<%
		request.setCharacterEncoding("UTF-8");
		String name = (String) session.getAttribute("id");
		String root = request.getParameter("root");
		session.setAttribute("root",root);
	%>
	<form method="post" action="e.jsp">
		<h2>사이트를 탈퇴하시려는 사유를 골라주세요.</h2>
		<div align = "right"><b><%=name %></b> 님<br></div>
		
		<select name="reason">
			<option value="선택하세요" selected="selected">선택하세요</option>
			<option value="요금문제">요금문제</option>
			<option value="서비스부족">서비스부족</option>
			<option value="불친절한 직원">불친절한 직원</option>
			<option value="기타">기타</option>
		</select>
		<p>
			<input type="submit" value="next">
	</form>
</body>
</html>