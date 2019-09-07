<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		String sent = request.getParameter("sent");
		ArrayList<String> arr = (ArrayList<String>) session.getAttribute("arr");

		if (sent != null) {
			arr.add(sent);
			session.setAttribute("arr", arr);
		}
	%>
	<fieldset>
		<legend>수집된 의견 목록</legend>
		<form method="post" action="d.jsp">
			<table border="1">
				<tr>
					<th>의견</th>
					<th>삭제</th>
				</tr>
				<%
					for (int i = 0; i < arr.size(); i++) {
				%>
				<tr>
					<td><%=arr.get(i)%></td>
					<td><input type="radio" name="del" value="<%=i%>"></td>
				</tr>
				<%
					}
				%>
			</table>
			<p>
				<input type="submit" value="선택항목삭제">
		</form>
	</fieldset><br>
	<a href="b.jsp">의견 계속 작성하기</a>
</body>
</html>