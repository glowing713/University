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
String pw = request.getParameter("pw"); String name = request.getParameter("name");
int age = Integer.parseInt(request.getParameter("age")); String phone = request.getParameter("phone");
String url = "jdbc:oracle:thin:@localhost:1521:XE";
String uid = "james"; String pass = "james";
String sql = "insert into bankmember values(?,?,?,?,?,0)";
try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url, uid, pass);
	PreparedStatement pre = conn.prepareStatement(sql);
	pre.setString(1,id); pre.setString(2,pw);
	pre.setString(3,name); pre.setInt(4,age);
	pre.setString(5,phone);
	pre.executeUpdate();
	session.invalidate();
	%>
	<script>
	alert("환영합니다, <%=id%>님!!");
	location.href="login.jsp";
	</script>
<%} catch(Exception e){
	out.print("죄송합니다, 문제가 생겼습니다."+e.getMessage());
}%>
</body>
</html>