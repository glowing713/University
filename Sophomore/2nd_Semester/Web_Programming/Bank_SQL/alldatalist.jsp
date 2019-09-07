<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
	<%
		request.setCharacterEncoding("UTF-8");
		String url="jdbc:oracle:thin:@localhost:1521:XE";
		String uid="james"; String pass="james";
		String sql1="select*from bankmember order by age desc";
		String sql2="select*from bankmember_del order by balance desc";
		String sql3="select*from banktrade order by tradedate desc";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			ResultSet rs = pre.executeQuery();
	%>
		<body style="background-color:#FBF8EF">
		<div align="center">
		<h2>||관리자용 전체 데이터 조회 화면||</h2><br>
		<h3>||전체 회원 목록||</h3>
		<table border="1"  width="750">
		<tr>
		<th>아이디</th><th>비밀번호</th><th>이름</th><th>나이</th><th>전화번호</th><th>잔액</th>
		</tr>
			<%while(rs.next()){%>
				<tr>
				<td><%=rs.getString("id")%></td><td><%=rs.getString("pw")%></td><td><%=rs.getString("name")%></td>
				<td><%=rs.getString("age")%></td><td><%=rs.getString("phone")%></td><td><%=rs.getInt("balance")%></td>
				</tr>
			<%}%>
		</table>
		
	<%pre=conn.prepareStatement(sql2); rs=pre.executeQuery();%>
		<h3>||탈퇴 회원 목록||</h3>
		<table border="1"  width="750">
		<tr>
		<th>아이디</th><th>비밀번호</th><th>이름</th><th>나이</th><th>전화번호</th><th>잔액</th>
		</tr>
			<%while(rs.next()){%>
				<tr>
				<td><%=rs.getString("id")%></td><td><%=rs.getString("pw")%></td><td><%=rs.getString("name")%></td>
				<td><%=rs.getString("age")%></td><td><%=rs.getString("phone")%></td><td><%=rs.getInt("balance")%></td>
				</tr>
			<%}%>
		</table>
		
	<%pre=conn.prepareStatement(sql3); rs=pre.executeQuery();%>
		<br><br>
		<h3>||전체 거래 내역||</h3>
		<table border="1" width="750">
		<tr>
			<th>거래일자(최근일순)</th><th>아이디</th><th>입금액</th><th>출금액</th><th>이체여부</th><th>이체상대</th>
		</tr>
			<%while(rs.next()){%>
				<tr>
					<td><%=rs.getString("tradedate")%></td>
					<td><%=rs.getString("id")%></td>
					<td><%=rs.getString("deposit")%></td>
					<td><%=rs.getString("withdraw")%></td>
					<td><%=rs.getInt("trans")==1?"이체보냄":rs.getInt("trans")==2?"이체받음":""%></td>
					<td><%=rs.getString("trade_id")%></td>
				</tr>
			<%}%>
		</table><br><br>
		<a href="menu.jsp">메뉴로 돌아가기</a>
		</div>
		</body>
		<%}catch(Exception e){
			out.print("조회 중 문제 발생!<p>"+e.getMessage());
		}
		%>
</html>