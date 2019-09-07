<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>설문조사 결과</title>
</head>
<body style="background-color: #3E92CC">
	<%
		request.setCharacterEncoding("UTF-8");
		String ch = request.getParameter("choice");
		session.setAttribute("choice", ch);
	%>
	<%
		String id = (String) session.getAttribute("id");
		String root = (String) session.getAttribute("root");
		String reason = (String) session.getAttribute("reason");
		String choice = (String) session.getAttribute("choice");
	%>
	
	<%
		request.setCharacterEncoding("UTF-8");

		if (choice.equals("네")){
			out.println("<b>" + id + "</b>" + "님은 서비스를 연장하셨습니다." + "<p>" + "감사합니다!!");
		} else if (choice.equals("아니요")) {
			out.println("<b>" + id + "</b>" + "님은 " + "<b>" + root + "</b>" + "을(를) 통해 이 서비스에 등록하셨고," + "<br>"
					+ "<b>" + reason + "</b>" + "(으)로 불편함을 느끼셨습니다." + "<br>"
					+ "최종 선택에서 " + "<b>" + choice + "</b>" + "를 선택하셨으므로" + "<br>" + "회원탈퇴신청 접수되었습니다." + "<p>"
					+ "그동안 서비스를 이용해주셔서 감사합니다!");
		}
	%>
</body>
</html>