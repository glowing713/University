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
	%>
	<form method="post" action="tablet_dat.jsp">
		<div align="center">
			<h1>
				<font color="blue"><%=id%></font>님, 어떤 tablet을 원하시나요?
			</h1>
			<p>
			<table border="1">
				<tr>
					<td><input type="radio" name="tablet" value="아이패드" /></td>
					<td>iPad</td>
					<td><img src="pictures/ipad.jpg" alt="img load fail" width="100" height="145"/></td>
				</tr>
				<tr>
					<td><input type="radio" name="tablet" value="갤럭시탭" /></td>
					<td>Galaxy Tab</td>
					<td><img src="pictures/galaxytab.jpg" alt="img load fail" width="100" height="100"/></td>
				</tr>
				<tr>
					<td><input type="radio" name="tablet" value="미패드" /></td>
					<td>Mi Pad</td>
					<td><img src="pictures/mipad.jpg" alt="img load fail" width="110" height="135"/></td>
				</tr>
				<tr>
					<td><input type="radio" name="tablet" value="미디어패드" /></td>
					<td>Media Pad</td>
					<td><img src="pictures/mediapad.jpg" alt="img load fail" width="110" height="125"/></td>
				</tr>
			</table><p>
			<input type = "submit" value = "장바구니에 넣기"/> &nbsp;&nbsp; <a href="menu.jsp">메뉴</a>
		</div>
	</form>
</body>
</html>