<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Basket</title>
</head>
<body style = "background-color: #994065">
	<%
		request.setCharacterEncoding("UTF-8");
		ArrayList<String> phnlist = (ArrayList) session.getAttribute("phnlist");
		ArrayList<String> tbllist = (ArrayList) session.getAttribute("tbllist");
		String name = (String) session.getAttribute("id");
		int prd_num = phnlist.size() + tbllist.size();
	%>
	<h2><font color="white"> <%=name%></font>님이 선택하신 품목은
	총 <font color="white"> <%=prd_num%></font>개 입니다.</h2>
	
	<form method = "post" action = "purchase.jsp">
	<font color="white">
		<%if(phnlist.size()>0){
			for (int i = 0; i < phnlist.size(); i++) {%>
			<input type = "checkbox" name = "goods" value = <%=phnlist.get(i)%>><%=phnlist.get(i)%><br>
			<%}
		}%>
		
		<%if(tbllist.size()>0){
			for (int i = 0; i < tbllist.size(); i++) {%>
			<input type = "checkbox" name = "goods" value = <%=tbllist.get(i)%>><%=tbllist.get(i)%><br>
			<%}
		}%>
	</font>
	<br>
	<input type = "submit" value = "구매하기"> &nbsp; <a href = "menu.jsp"><font color = "white">메뉴</font></a>
	</form>
</body>
</html>