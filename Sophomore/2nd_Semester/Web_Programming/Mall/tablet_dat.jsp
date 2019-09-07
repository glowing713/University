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
		ArrayList<String> list = (ArrayList) session.getAttribute("tbllist");
		String tabletname = request.getParameter("tablet");
		if(list == null){
			list = new ArrayList<String>();
			session.setAttribute("tbllist", list);
		}
	%>
	<%if(tabletname == null){%>
			<script>
			alert("제품을 선택하세요.");
			history.go(-1);
			</script>
	<%}else{
		list.add(tabletname);
	%>
		<script>
		alert("<%=tabletname%> 이(가) 추가되었습니다.");
		history.go(-1);
		</script>
	<%}%>
</body>
</html>