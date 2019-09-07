<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form method="post" action="wc2.jsp">
		<div align="center">
			<h1>Who's your favorite player? (4강)</h1>
			<table>
				<tr>
					<td><img src="garethbale.jpg" width="400" height="250"
						alt="!image load fail!"></td>
					<td><img src="sonheungmin.jpg" width="400" height="250"
						alt="!image load fail!"></td>
				</tr>
				<tr>
					<th><input type="radio" name="player1" value="garethbale.jpg">Gareth Bale</th>
					<th><input type="radio" name="player1" value="sonheungmin.jpg">Son heung min</th>
				</tr>
			</table>
			<input type="submit" value="선택">
		</div>
	</form>
</body>
</html>