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
		String id = (String) session.getAttribute("id");
		int withdraw = (Integer) session.getAttribute("withdraw");
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql1 = "insert into banktrade values(?,sysdate,0,?,0,'*')";
		String sql2 = "update bankmember set balance=balance-? where id=?";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url, uid, pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setString(1,id); pre.setInt(2,withdraw);
			pre.executeUpdate();
			pre = conn.prepareStatement(sql2);
			pre.setInt(1,withdraw); pre.setString(2,id);
			pre.executeUpdate();
			%>
			<script>
			alert("<%=withdraw%>원이 출금되었습니다.\n메뉴로 이동합니다.");
			location.href="menu.jsp";
			</script>
		<%}catch(Exception e){
			out.print("출금 진행 중 오류가 발생했습니다.<p>"+e.getMessage());
		}
	%>
</body>
</html>