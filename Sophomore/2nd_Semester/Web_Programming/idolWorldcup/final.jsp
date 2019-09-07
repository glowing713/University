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
		String player1 = request.getParameter("player1");
		String player2 = request.getParameter("player2");
	%>
	<form method="post" action="winner.jsp">
		<div align="center">
			<h1>Who's your favorite player? (결승)</h1>
			<table>
				<tr>
					<td><img src=<%=player1%> width="400" height="250"
						alt="!image load fail!"></td>
					<td><img src=<%=player2%> width="400" height="250"
						alt="!image load fail!"></td>
				</tr>
				<tr>
					<th><input type="radio" name="winner" value=<%=player1%>><%=player1%></th>
					<th><input type="radio" name="winner" value=<%=player2%>><%=player2%></th>
				</tr>
			</table>
			<input type="submit" value="선택">
		</div>
	</form>
</body>
</html>