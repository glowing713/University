<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
  	   <%
		request.setCharacterEncoding("UTF-8");
		String id = request.getParameter("id");
		String pw = request.getParameter("pw");
		String members[][] = {{"a","1"}, {"b","2"}, {"c","3"}, {"d","4"}, {"james","1234"}};
		session.setAttribute("account", 0);
		session.setAttribute("in_cnt", 0);
		session.setAttribute("out_cnt", 0);

		for(int i = 0;i < members.length;i++){
			if(id.equals(members[i][0])){
				if(pw.equals(members[i][1])){
					session.setAttribute("id",id);
					session.setMaxInactiveInterval(60*60);
					response.sendRedirect("menu.jsp");
				}%>
				<script>
					alert("패스워드가 틀렸습니다!");
					location.href = "login.html";
				</script>
			<%}
			}%>
		<script>
			alert("미가입 회원입니다!");
			location.href = "login.html";
		</script>
</body>
</html>