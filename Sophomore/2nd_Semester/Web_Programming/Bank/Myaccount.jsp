<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.text.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		String name = (String) session.getAttribute("id");
		int account = (Integer) session.getAttribute("account");
		int in_cnt = (Integer) session.getAttribute("in_cnt");
		int out_cnt = (Integer) session.getAttribute("out_cnt");
		DecimalFormat df = new DecimalFormat("###,###");
	%>
		<h2><font color="blue"><%=name%></font>님의 거래 현황</h2>			
		<p>
		<hr>
		<p>
		<ul>
			<li>현재 잔액:  <%=df.format(account)%>원
			<li>총 입금횟수: <%=in_cnt%>번
			<li>총 출금횟수: <%=out_cnt%>번
		</ul>
		<p>
		<font color="blue"><a href = "menu.jsp">메뉴</a></font>로 가기
</body>
</html>