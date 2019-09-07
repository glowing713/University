<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
		ArrayList<String> list = (ArrayList) session.getAttribute("phnlist");
		String phonename = request.getParameter("phone");
		if(list == null){
			list = new ArrayList<String>();
			session.setAttribute("phnlist", list);
		}
	%>
	<%if(phonename == null){%>
			<script>
			alert("제품을 선택하세요.");
			history.go(-1);
			</script>
	<%}else{
		list.add(phonename);
	%>
		<script>
		alert("<%=phonename%> 이(가) 추가되었습니다.");
		history.go(-1);
		</script>
	<%}%>
</body>
</html>