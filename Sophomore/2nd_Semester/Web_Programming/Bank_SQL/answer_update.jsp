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
		int seq = Integer.parseInt(request.getParameter("seq"));
		String answer = request.getParameter("answer");
		String url="jdbc:oracle:thin:@localhost:1521:XE";
		String uid="james"; String pass="james";
		String sql1="select * from qanda where seq=?";
		String sql2="update qanda set answer=? where seq=?";
		
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setInt(1,seq);
			ResultSet rs = pre.executeQuery();
			if(rs.next()){
				pre = conn.prepareStatement(sql2);
				pre.setString(1,answer);
				pre.setInt(2,seq);
				pre.executeUpdate();
				response.sendRedirect("question.jsp");
			}else{%>
				<script>
					alert("seq를 다시 확인하세요.");
					location.href="question.jsp";
				</script>
			<%}
		}catch(Exception e){
			out.print("죄송합니다. 문제가생겼습니다."+e.getMessage());
		}
	%>
</body>
</html>