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
	String url = "jdbc:oracle:thin:@localhost:1521:XE";
	String uid = "james"; String pass = "james";
	String sql = "select login_count from visit";
%>
<body style="background-color: #F8ECE0">
누적 로그인 수:
	<%
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql);
			ResultSet rs = pre.executeQuery();
			if(rs.next()){%>
				<%=rs.getInt("login_count")%>
			<%}
		}catch (Exception e){
			out.print("카운트 확인 중 문제 발생! <p>"+e.getMessage());
		}
	%>
	<div align="center">
		<h1>DAU BANK</h1>
		<form method="post" action="check_id.jsp">
			ID: <input type="text" name="id" />
			<p>
				<input type="submit" value="login" /> &nbsp; &nbsp;
				<a href = "member.html">회원가입 </a>
			<p>
		</form>
		<img src = "ironman.jpg" width="500" height="300" alt="!image load fail!">
	</div>
</body>
</html>