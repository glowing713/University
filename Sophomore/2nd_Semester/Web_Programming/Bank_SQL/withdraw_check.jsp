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
		int withdraw = Integer.parseInt(request.getParameter("withdraw"));
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql = "select balance from bankmember where id=?";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql);
			pre.setString(1,id);
			ResultSet rs = pre.executeQuery();
			rs.next();
			int balance = rs.getInt("balance");
			if(balance >= withdraw){
				session.setAttribute("withdraw", withdraw);
				response.sendRedirect("withdraw_insert.jsp");
			}
			%>
			<script>
			alert("잔액이 부족합니다 (현재 잔액: <%=balance%> 원)");
			location.href="withdraw.jsp";
			</script>
		<%} catch(Exception e){
			out.print("출금액 확인 중 문제 발생! <p>"+e.getMessage());
		}%>
</body>
</html>