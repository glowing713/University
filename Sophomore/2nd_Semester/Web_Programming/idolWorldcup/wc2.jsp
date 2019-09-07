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
		String select1 = request.getParameter("player1");
	%>
	<form method="post" action="final.jsp">
		<div align="center">
			<h1>Who's your favorite player? (4강)</h1>
			<table>
				<tr>
					<td><img src="hwanguijo.jpg" width="400" height="250"
						alt="!image load fail!"></td>
					<td><img src="kisungyong.jpg" width="400" height="250"
						alt="!image load fail!"></td>
				</tr>
				<tr>
					<th><input type="radio" name="player2" value="hwanguijo.jpg">Hwang ui jo</th>
					<th><input type="radio" name="player2" value="kisungyong.jpg">Ki sung yong</th>
				</tr>
			</table>
			<input type="submit" value="선택">
		</div>
		<input type="hidden" name="player1" value=<%=select1%>>
	</form>
</body>
</html>