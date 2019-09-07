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
		ArrayList<String> arr_set = new ArrayList<String>();
		session.setAttribute("arr", arr_set);
		response.sendRedirect("bc.jsp");
	%>
</body>
</html>