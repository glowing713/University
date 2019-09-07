<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>설문조사 1</title>
</head>
<body style="background-color: #4ECDC4">
<%String name = (String) session.getAttribute("id");%>
	<form method="post" action="d.jsp">
		<h2>사이트를 알게 된 경로를 선택해주세요.</h2>
		<div align = "right"><b><%=name %></b> 님<br></div>
		<input type="radio" name="root" value="인터넷 검색" />인터넷 검색<br>
        <input type="radio" name="root" value="광고 홍보" />광고 홍보<br>
		<input type="radio" name="root" value="지인 추천" />지인 추천<br>
		<input type="radio" name="root" value="기타" />기타<p>
		<input type="submit" value="next">		
	</form>
</body>
</html>