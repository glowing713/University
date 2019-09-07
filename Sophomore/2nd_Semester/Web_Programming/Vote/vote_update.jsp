<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
	<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		String name = request.getParameter("idol");
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql = "update idol set pyo=pyo+1 where star=?";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql);
			pre.setString(1,name);
			pre.executeUpdate();
	%>
			<script>
			alert("<%=name%>에 투표하셨습니다.");
			location.href="vote.jsp";
			</script>
		<%} catch(Exception e){
			out.print("오류가 발생했습니다."+e.getMessage());
		}
		%>
</body>
</html>