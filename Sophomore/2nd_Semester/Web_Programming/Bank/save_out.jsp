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
		int out_cnt = (Integer) session.getAttribute("out_cnt");
		int account = (Integer) session.getAttribute("account");
		int getMoney = Integer.parseInt(request.getParameter("money_Out"));
		if (account >= getMoney) {
			account -= getMoney;
			out_cnt++;
			session.setAttribute("account", account);
			session.setAttribute("out_cnt", out_cnt);
			%>
			<script>
			alert("출금완료되었습니다.");
			location.href = "menu.jsp";
			</script>
	<%} else {%>
	<script>
		alert("잔액이 부족합니다!");
		location.href = "out.jsp";
	</script>
	<%}%>

</body>
</html>