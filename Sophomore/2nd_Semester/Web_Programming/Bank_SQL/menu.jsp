<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<%
	request.setCharacterEncoding("UTF-8");
	String id = (String) session.getAttribute("id");
%>
<body style="background-color: grey">
	<h2>전체메뉴</h2>
	<hr>
	<font color="blue"><%=id%></font>님, 어떤 업무를 하시겠습니까?
	<br>
	<hr>
	<p>
	<ul>
		<li><a href="deposit.jsp">입금</a></li>
		<li><a href="withdraw.jsp">출금</a></li>
		<li><a href="balance.jsp">잔액조회</a></li>
		<li><a href="transfer.jsp">이체</a></li>
		<li><a href="mytradelist.jsp">나의거래내역</a></li>
		<li><a href="check_pw.jsp">회원정보조회및변경</a></li>
		<li><a href="bye.jsp">회원탈퇴</a></li>
		<li><a href="question.jsp">질문과 답변</a></li>
		<li><a href="logout.jsp">로그아웃</a></li>
		<%if(id!=null){ 
			if(id.equals("admin")){%>
				<li><a href="alldatalist.jsp">전체 데이터(관리자용)</a>
			<%}}%>
	</ul>
</body>
</html>