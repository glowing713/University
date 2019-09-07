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
		int in_cnt = (Integer)session.getAttribute("in_cnt");
		int account = (Integer)session.getAttribute("account");
		int getMoney = Integer.parseInt(request.getParameter("money_In"));
		account += getMoney;
		in_cnt++;
		session.setAttribute("account", account);
		session.setAttribute("in_cnt", in_cnt);
	%>
	<script>
		alert("입금완료되었습니다.");
		location.href = "menu.jsp";
	</script>
</body>
</html>