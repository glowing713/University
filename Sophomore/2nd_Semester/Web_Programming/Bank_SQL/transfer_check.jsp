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
		String receiver = request.getParameter("receiver");
		int transfer = Integer.parseInt(request.getParameter("transfer"));
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql1 = "select * from bankmember where id=?";
		String sql2 = "select balance from bankmember where id=?";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setString(1,receiver);
			ResultSet rs = pre.executeQuery();
			rs.next();
			pre = conn.prepareStatement(sql2);
			pre.setString(1,id);
			rs = pre.executeQuery();
			rs.next();
			int balance = rs.getInt("balance");
			if(balance >= transfer){
				session.setAttribute("receiver",receiver);
				session.setAttribute("transfer",transfer);
				response.sendRedirect("transfer_insert.jsp");
			}
	%>
		<script>
			alert("잔액이 부족합니다.\n(현재잔액: <%=balance%>원)");
			location.href="transfer.jsp";
		</script>
	<%}catch(Exception e){
			out.print("송금액 확인 중 문제 발생! <p>"+e.getMessage());
		}
	%>
</body>
</html>