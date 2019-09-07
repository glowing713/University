<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body style="background-color: #F8ECE0">
	<%
		request.setCharacterEncoding("UTF-8");
		String id=(String)session.getAttribute("id");
		String url="jdbc:oracle:thin:@localhost:1521:XE";
		String uid="james"; String pass="james";
		String sql="select *from qanda order by seq asc";
	%>
	<font color="blue"><%=id%></font>님,
	<%if(id.equals("admin")){ %>
	답변을 작성해주세요.<p>
	<%}else{ %>
	궁금하신 점이 있으십니까? 질문을 입력해주세요.<p>
	<%} %>
	
	<table border="1">
		<tr>
			<th>seq</th> <th>질문일자</th> <th>ID</th> <th>Question</th> <th>Answer</th>
		</tr>
		<%
			try{
				Class.forName("oracle.jdbc.driver.OracleDriver");
				Connection conn = DriverManager.getConnection(url,uid,pass);
				PreparedStatement pre = conn.prepareStatement(sql);
				ResultSet rs = pre.executeQuery();
				while(rs.next()){%>
					<tr>
						<td><%=rs.getInt("seq")%></td>
						<td><%=rs.getString("qdate")%></td>
						<td><%=rs.getString("id")%></td>
						<td><%=rs.getString("question")%></td>
						<td><%=rs.getString("answer")%></td>
					</tr>
				<%}
			}catch (Exception e){
				out.print("죄송합니다. 문제가생겼습니다."+e.getMessage());
			}
		%>
	</table>
	<p>
	<form method="post" action="question_insert.jsp">
	질문 입력:<br>
	<textarea name="question" rows="5" cols="50"></textarea>
	<input type="submit" value="질문등록">
	</form>
	<p>
	<%if(id.equals("admin")){ %>
	<jsp:include page="answer.jsp"></jsp:include>
	<%} %>
	<a href="menu.jsp">메뉴로 돌아가기</a>
</body>
</html>