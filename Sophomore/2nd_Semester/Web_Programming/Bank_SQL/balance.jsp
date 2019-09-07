<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body style="background-color: #F8ECE0">
	<%
		request.setCharacterEncoding("UTF-8");
		String id = (String) session.getAttribute("id");
		int bal = 0;
		String date = null;
		String uid = "james"; String pass = "james";
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String sql1 = "select balance from bankmember where id=?";
		String sql2 = "select max(tradedate) from banktrade where id=?";
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url, uid, pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setString(1, id);
			ResultSet rs = pre.executeQuery();
			if (rs.next()) {
				bal = rs.getInt(1);
			}
			pre = conn.prepareStatement(sql2);
			pre.setString(1, id);
			rs = pre.executeQuery();
			if (rs.next()) {
				date = rs.getString(1);
			}
		} catch (Exception e) {
			out.print("조회 중 문제가 발생했습니다! <p>" + e.getMessage());
		}
	%>
	<h3><font color="blue"><%=id%></font>님의 잔액은 <%=bal%> 원입니다.</h3><br>
	최근 거래일은 <%=date%>입니다.<p>
	<a href="menu.jsp">메뉴로 돌아가기</a>
</body>
</html>