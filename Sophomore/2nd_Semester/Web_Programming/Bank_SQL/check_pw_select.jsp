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
	String id = (String)session.getAttribute("id"); String pw = request.getParameter("pw");
	String url = "jdbc:oracle:thin:@localhost:1521:XE";
	String uid = "james"; String pass = "james";
	String sql = "select * from bankmember where id = ?";
	try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url, uid, pass);
	PreparedStatement pre = conn.prepareStatement(sql);
	pre.setString(1,id);
	ResultSet rs = pre.executeQuery();
	rs.next();
	if(pw.equals(rs.getString("pw"))) {
	response.sendRedirect("myinfo.jsp");}
	%>
	<script>
		alert("비밀번호를 잘못 입력하셨어요~");
		location.href = "check_pw.jsp";
	</script>
	<%}catch (Exception e) {
		out.print("비번 확인 중 문제 발생했어요 고객센터로 문의 바랍니다! <p>" + e.getMessage());
	}%>
</body>
</html>