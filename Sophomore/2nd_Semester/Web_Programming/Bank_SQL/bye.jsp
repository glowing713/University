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
		String id = (String) session.getAttribute("id");
		String uid = "james"; String pass = "james";
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String sql = "select balance from bankmember where id=?";
		
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql);
			pre.setString(1,id);
			ResultSet rs = pre.executeQuery();
			
			if(rs.next()){
				int bal = rs.getInt("balance");
				if(bal != 0){%>
					<div align="center">
					<font color="blue"><%=id%></font>님의 잔액이 아직 <%=bal%>원 남아있습니다.
					</div>
				<%}%>
				<div align="center">
				<h2>정말 회원 탈퇴를 원하십니까?</h2><br>
				<a href="menu.jsp">취소 (메뉴로 돌아가기)</a> &nbsp; &nbsp;<a href="bye_delete.jsp">탈퇴 처리 즉시 진행 요청</a>
				</div>
			<%}
		}catch(Exception e){
			out.print("서비스 접속 중 오류 <p>" + e.getMessage());
		}
	%>
</body>
</html>