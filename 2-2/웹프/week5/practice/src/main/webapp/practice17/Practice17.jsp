<%--컴퓨터학과 20220769 변서영 --%>
<%--Microsoft Edge에 최적화되어있습니다. --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Enumeration" %>
<%@ page import="java.util.ArrayList" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 22</title>
</head>
<body>
<%!
	String[] mChoices={"hobby"};
	String[] hobbyNames={"뉴스","맛집","책","영화","여행"};
	String[] telCompany={"010","011","017","070"};
	String[] gNames={"남","여"};
	
	public ArrayList<String> getParameterNames(HttpServletRequest request){
		ArrayList<String> list = new ArrayList<String>();
		Enumeration<String> e = request.getParameterNames();
		
		while(e.hasMoreElements()){
			list.add(e.nextElement());
		}
		return list;
	}
%>
<%
	ArrayList<String> e = getParameterNames(request);
	
	int i = 0;
	while(i != e.size()){
		String name = e.get(i);
		if (name.equals(mChoices[0])){
			String[] data = request.getParameterValues(name);
			out.print(name + ":");
			for (String eachdata:data)
				out.print(eachdata + "/");
			out.println("<br>");
		}
		else{
			String data = request.getParameter(name);
			out.println(name + " : " + data + "<br>");
		}
		i++;
	}
	
	out.println("<hr>");
	out.println("<h1>Processing Parameters</h1>");
	
	i = 0;
	while(i != e.size()){
		String name = e.get(i);
		out.print(name + " : ");
		if (name.equals(mChoices[0])){
			String[] data = request.getParameterValues(name);
			for (int j = 0; j < data.length; j++){
				int v = Integer.parseInt(data[j]);
				out.print(hobbyNames[v] + "/");
			}
		}
		else{
			String data = request.getParameter(name);
			if (name.equals("phone")){
				int v = Integer.parseInt(data);
				out.print(telCompany[v]);
			}
			else if (name.equals("gender")){
				int v = Integer.parseInt(data);
				out.print(gNames[v]);
			}
			else{
				out.print(data);
			}
		}
		out.println("<br>");
		i++;
	}
%>
</body>
</html>