<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		String id = (String)session.getAttribute("id");
		int deposit = Integer.parseInt(request.getParameter("deposit"));
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james";
		String pass = "james";
		String sql1 = "insert into banktrade values(?,sysdate,?,0,0,'*')";
		String sql2 = "update bankmember set balance=balance+? where id=?";
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url, uid, pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setString(1,id);
			pre.setInt(2, deposit);
			pre.executeUpdate();
			pre = conn.prepareStatement(sql2);
			pre.setInt(1,deposit); pre.setString(2,id);
			pre.executeUpdate();
	%>
	<script>
		alert("<%=deposit%>원이 입금완료되었습니다.");
		location.href = "menu.jsp";
	</script>
	<%} catch (Exception e) {
			out.print("죄송합니다! 문제가 생겼습니다." + e.getMessage());
	}
	%>
</body>

</html>