<%@ page contentType="text/plain; charset=utf-8" %>
<%@ page import="example.ajax.pizza.*" %>
<%@ page import="java.util.*" %> 
<%@ page import="com.fasterxml.jackson.databind.*" %>
<%! @SuppressWarnings("unchecked") %>
<%
ObjectMapper mapper = new ObjectMapper();

Customer customer = mapper.readValue(request.getReader(), Customer.class);
String phone = customer.getPhone();
String order = customer.getRecentOrder();
Address address = customer.getAddress();
// application에서 "custMap" 객체를 검색하고 조회/수정 가능

Map<String, Customer> custMap = (Map<String, Customer>)application.getAttribute("custMap"); 
if (custMap == null || custMap.get(phone) == null) {	 
	response.setStatus(400);		// bad request
	response.addHeader("Status", "Unregistered customer");
	return;
} 
else {
	Customer c = custMap.get(phone);	// 고객 정보 검색
	System.out.println(c.getName());	// 이름 출력 
	c.setRecentOrder(order);
}


if (order.length() <= 0) {
	response.setStatus(400);		// bad request
  	response.addHeader("Status", "No order was received");
  	out.print(" ");
}
else if (address.toString().length() <= 0) {
	response.setStatus(400);		// bad request
  	response.addHeader("Status", "No address was received");
	out.print(" ");
} 
else { 
	// make pizza and compute delivery time ...
	int deliveryTime = (int)(Math.random()*8 + 2);
	System.out.println("delivery time: " + deliveryTime);
	out.print(deliveryTime);
}
%>