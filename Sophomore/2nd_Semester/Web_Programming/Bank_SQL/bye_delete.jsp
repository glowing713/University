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
		String id = (String)session.getAttribute("id");
		String uid = "james"; String pass = "james";
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String sql1 = "select *from bankmember where id=?";
		String sql2 = "delete from bankmember where id=?";
		String sql3 = "insert into bankmember_del values(?,?,?,?,?,?)";
		
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url,uid,pass);
			PreparedStatement pre = conn.prepareStatement(sql1);
			pre.setString(1,id);
			ResultSet rs = pre.executeQuery();
			if(rs.next()){
				String a = rs.getString("id"); String b = rs.getString("pw");
				String c = rs.getString("name"); int d = rs.getInt("age");
				String e = rs.getString("phone"); int f = rs.getInt("balance");
				pre = conn.prepareStatement(sql2);
				pre.setString(1,id);
				pre.executeUpdate();
				pre = conn.prepareStatement(sql3);
				pre.setString(1,a); pre.setString(2,b);
				pre.setString(3,c); pre.setInt(4,d);
				pre.setString(5,e); pre.setInt(6,f);
				pre.executeUpdate();
				session.invalidate();%>
				<script>
					alert("탈퇴처리 완료되었습니다. 신분증 지참하여 인근 은행 방문 시 잔액 인출 가능하십니다."+
							"다음에 또 뵙길 기대합니다. 감사합니다:)(첫 화면으로 이동합니다.)");
					location.href = "login.jsp";
				</script>
			<%}
		}catch(Exception e){
			out.print("탈퇴 처리 중 오류 발생"+e.getMessage());
		}
	%>
</body>
</html>