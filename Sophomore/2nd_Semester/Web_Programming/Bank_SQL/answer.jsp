<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title></title>
</head>
<body>
	<form method="post" action="answer_update.jsp">
		답변 입력:<br> seq: <input type="number" name="seq"><br>
		<textarea name="answer" rows="5" cols="50"></textarea>
		<input type="submit" value="답변등록">
	</form>
</body>
</html>