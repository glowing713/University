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
		String receiver = (String) session.getAttribute("receiver");
		int transfer = (Integer) session.getAttribute("transfer");
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql1 = "insert into banktrade values(?,sysdate,0,?,1,?)";
		String sql2 = "insert into banktrade values(?,sysdate,?,0,2,?)";
		String sql3 = "update bankmember set balance=balance-? where id=?";
		String sql4 = "update bankmember set balance=balance+? where id=?";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setString(1,id); pre.setInt(2,transfer); pre.setString(3,receiver);
			pre.executeUpdate();
			pre = conn.prepareStatement(sql2);
			pre.setString(1,receiver); pre.setInt(2,transfer); pre.setString(3,id);
			pre.executeUpdate();
			pre = conn.prepareStatement(sql3);
			pre.setInt(1,transfer); pre.setString(2,id);
			pre.executeUpdate();
			pre = conn.prepareStatement(sql4);
			pre.setInt(1,transfer); pre.setString(2,receiver);
			pre.executeUpdate();
		%>
		<script>
			alert("<%=transfer%>원이 송금 완료되었습니다.\n메뉴로 이동합니다.");
			location.href="menu.jsp";
		</script>
	<%}catch (Exception e){
			out.print("이체 진행 중 오류가 발생했습니다.<p>"+e.getMessage());
		}
	%>
</body>
</html>