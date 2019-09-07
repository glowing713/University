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
		String winner = request.getParameter("winner");
	%>
	<div align="center">
			<h1>Winner: <font color="blue"><%=winner.replace(".jpg","")%></font></h1><br>
			<table>
				<tr>
					<td><img src=<%=winner%> width="500" height="350"
						alt="!image load fail!"></td>
				</tr>
			</table>
			<br>
			<a href="wc1.jsp">처음으로 돌아가기</a>
	</div>
</body>
</html>