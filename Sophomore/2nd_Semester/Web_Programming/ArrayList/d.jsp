<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		int i = Integer.parseInt(request.getParameter("del"));
		ArrayList<String> arr = (ArrayList<String>)session.getAttribute("arr");
		
		arr.remove(i);
		session.setAttribute("arr",arr);
		
		response.sendRedirect("bc.jsp");
	%>
</body>
</html>