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
request.setCharacterEncoding("UTF-8"); String id = request.getParameter("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE";
String uid = "james"; String pass = "james";
String sql1 = "select*from bankmember where id=?";
String sql2 = "update visit set login_count=login_count+1";
try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url, uid, pass);
	PreparedStatement pre = conn.prepareStatement(sql1);
	pre.setString(1,id);
	ResultSet rs = pre.executeQuery();
	if(rs.next()){
		session.setAttribute("id", id);
		session.setMaxInactiveInterval(60*60);
		pre=conn.prepareStatement(sql2);
		pre.executeUpdate();
		response.sendRedirect("menu.jsp");
	}
	%>
	<script>
	alert("미등록 아이디입니다~");
	location.href="login.jsp";
	</script>
<%}catch(Exception e){
	out.print("죄송합니다. 문제가생겼습니다."+e.getMessage());
}
%>
</body>
</html>