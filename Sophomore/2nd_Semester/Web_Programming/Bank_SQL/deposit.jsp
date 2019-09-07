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
		request.setCharacterEncoding("UTF-8");
		String id = (String) session.getAttribute("id");
	%>
	<div align="center">
		<form method="post" action="deposit_insert.jsp">
			<h2>이 체</h2>
			<hr><font color="blue"><%=id%></font>님, 얼마를 이체하시겠습니까?<hr><p>
			입금: <input type="number" name="deposit">원<p>
				<input type="submit" value="입금진행">
		</form>
		<a href="menu.jsp">메뉴로 돌아가기</a>
	</div>
</body>
</html>