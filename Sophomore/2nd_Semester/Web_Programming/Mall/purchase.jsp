<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.Arrays, java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>purchse.jsp</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		String name = (String) session.getAttribute("id");
		String[] array = request.getParameterValues("goods");
		String goods = Arrays.toString(array);
		long lasttime = session.getLastAccessedTime();
		long createdtime = session.getCreationTime();
		long time_used = (lasttime - createdtime) / 1000;
	%>
	
	<script>
	alert("<%=goods%>을(를) 구매하셨습니다.\n오늘 쇼핑시간은 <%=time_used%>초 입니다.\n감사합니다. 또 오세요!");
	location.replace("menu.jsp");
	</script>
</body>
</html>