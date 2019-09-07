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
		String[] name = {"stark","peter","steven","bruce"};
		
		for(String n:name){
			if(id.equals(n)){
				session.setAttribute("id",id);
				session.setMaxInactiveInterval(60*60);
				response.sendRedirect("menu.jsp");
			}
		}
	%>

	<script>
	   alert("등록되지 않은 회원입니다.");
	   location.href="login.html";
	   </script>
</body>
</html>