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
		int seq;
		String id = (String) session.getAttribute("id");
		String question = request.getParameter("question");
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uid = "james"; String pass = "james";
		String sql1 = "select max(seq) from qanda";
		String sql2 = "insert into qanda values(?,sysdate,?,?,'(preparing)')";

		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url, uid, pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			ResultSet rs = pre.executeQuery();
			if(rs.next()){
				seq = rs.getInt(1) + 1;
				pre = conn.prepareStatement(sql2);
				pre.setInt(1, seq);
				pre.setString(2, id);
				pre.setString(3, question);
				pre.executeUpdate();
				response.sendRedirect("question.jsp");
			}
		} catch (Exception e) {
			out.print("죄송합니다. 문제가생겼습니다." + e.getMessage());
		}
	%>
</body>
</html>