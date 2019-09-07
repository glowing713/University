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
		ArrayList<String> arr = (ArrayList<String>) session.getAttribute("arr");
		if (arr == null) {
			arr = new ArrayList<String>();
			session.setAttribute("arr", arr);
		}
		
		request.setCharacterEncoding("UTF-8");
		String choice = request.getParameter("choice");
		String msg = request.getParameter("msg");
		
		if(choice!=null){
			if(choice.equals("1")){
				arr.add(msg);
			}else{
				arr.remove(msg);
			}
		}
		for(String m:arr){
			out.print(m + "<br>");
		}
	%>
	<form method="post" action="honja.jsp?choice=1">
		<input type="text" name="msg"> &nbsp; &nbsp;
		<input type="submit" value="추가">
	</form>
	
	<form method="post" action="honja.jsp?choice=2">
		<input type="text" name="msg"> &nbsp; &nbsp;
		<input type="submit" value="제거">
 	</form>
</body>
</html>