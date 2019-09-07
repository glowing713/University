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
		String id = (String)session.getAttribute("id");
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql = "select*from banktrade where id=? order by tradedate desc";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql);
			pre.setString(1,id);
			ResultSet rs = pre.executeQuery();
			%>
			<body style="background-color:#FBF8EF">
			<div align="center">
			<h3><font color="blue"><%=id%></font>님의 거래내역은 다음과 같습니다.</h3>
			<table border="1" width="500">
			<tr>
			<th>거래일자(최근일순)</th><th>입금액</th><th>출금액</th><th>이체여부</th><th>이체상대</th>
			<%while(rs.next()){%>
			</tr>
			<tr>
			<td><%=rs.getString("tradedate")%></td>
			<td><%=rs.getString("deposit")%></td>
			<td><%=rs.getString("withdraw")%></td>
			<td><%=rs.getInt("trans")==1?"이체보냄":rs.getInt("trans")==2?"이체받음":""%></td>
			<td><%=rs.getString("trade_id")%></td>
			</tr>
			<%}%>
			</table><br>
			<a href="menu.jsp">메뉴로 돌아가기</a>
			</div>
			</body>
		<%} catch(Exception e){
			out.print("거래내역 조회 중 문제 발생!<p>"+e.getMessage());
		}%>
</html>