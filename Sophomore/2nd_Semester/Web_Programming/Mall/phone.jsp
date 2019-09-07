<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>phone purchase</title>
</head>
<body>
	<%
		String id = (String) session.getAttribute("id");
	%>
	<form method="post" action="phone_dat.jsp">
		<div align="center">
			<h1>
				<font color="blue"><%=id%></font>님, 어떤 phone을 원하시나요?
			</h1>
			<table border="1">
				<tr>
					<td><input type="radio" name="phone" value="아이폰" /></td>
					<td>아이폰</td>
					<td><img src="pictures/iphone.jpg" alt="img load fail" width="80" height="90"/></td>
				</tr>
				<tr>
					<td><input type="radio" name="phone" value="갤럭시" /></td>
					<td>갤럭시</td>
					<td><img src="pictures/galaxy.jpg" alt="img load fail" width="80" height="90"/></td>
				</tr>
				<tr>
					<td><input type="radio" name="phone" value="엑스페리아" /></td>
					<td>엑스페리아</td>
					<td><img src="pictures/xperia.jpg" alt="img load fail" width="80" height="70"/></td>
				</tr>
				<tr>
					<td><input type="radio" name="phone" value="블랙베리" /></td>
					<td>블랙베리</td>
					<td><img src="pictures/blackberry.jpg" alt="img load fail" width="80" height="100"/></td>
				</tr>
			</table>
			<p><input type = "submit" value = "장바구니에 넣기"/> &nbsp;&nbsp; <a href="menu.jsp">메뉴</a></p>
		</div>
	</form>
</body>
</html>