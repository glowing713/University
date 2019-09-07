<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>

<body>
	<form method="post" action="save_out.jsp">
		<div align="center">
			<h1>출금화면</h1><p>
			 얼마를 출금하시겠습니까?<p>
				출금액: <input type="text" name="money_Out"/>원<p>
				<input type="submit" value="확인"> &nbsp;&nbsp;&nbsp;&nbsp;
				<a href="menu.jsp">메뉴</a>로 가기
		</div>
	</form>
</body>
</html>