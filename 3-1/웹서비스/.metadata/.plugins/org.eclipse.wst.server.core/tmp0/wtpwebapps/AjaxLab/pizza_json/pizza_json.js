function getCustomerInfo() {
	var phone = $("#phone").val();
	if (phone == "") {
		$("#address").val("");
		$("#order").val("");
	}
	else {
		$.ajax({
	 		type: "GET",
			url: "lookupCustomer_json.jsp?phone=" + phone,
			/* 또는 url: "lookupCustomer_xml.jsp", 
				data: {"phone": phone}, */  
			dataType: "json",
			success: updatePage,
			error: function(jqXHR) {
				var message = jqXHR.getResponseHeader("Status");
				if ((message == null) || (message.length <= 0)) {
					alert("Error! Request status is " + jqXHR.status);
				} else {
					alert(message);	
				}
			}
		});
	}
}

function updatePage(json) {
	alert("response: " + json);
	/* Update the HTML web form */
	//console.log(customer.name);
	$("#greeting").append("Hi, " + json.name + "!");
	$("#order").val(json.recentOrder);
	$("#address").val(json.address.street + "\n" + json.address.city + ", " + json.address.state + " " + json.address.zipCode);
}

function submitOrder() {
	var data = {
		phone: $("#phone").val(), 
		address: {street: $("#address").val()}, 
		recentOrder: $("#order").val()
	};
	
	var jsonStr = JSON.stringify(data);
	
	$.ajax({
 		type: "POST",
		url: "placeOrder_json.jsp",
		contentType: "application/json; charset=UTF-8", // default(생략 가능)
		data: jsonStr,	
		dataType: "json",
		success: showConfirmation,
		error: function(jqXHR) {
			var message = jqXHR.getResponseHeader("Status");
			if ((message == null) || (message.length <= 0)) {
				alert("Error! Request status is " + jqXHR.status);
			} else {
				alert(message);	
			}
		}
	});
}

function showConfirmation(response) {
	// Create some confirmation text
	var p = document.createElement("p");
	p.innerHTML = `Your order should arrive within ${response} minutes. Enjoy your pizza!`;
	var span = document.createElement("span");
	$(span).append(p);
	$("#main-page > span").remove();
	$("#main-page").append(span);
	
	// Or you can replace the form with the confirmation as below:
	// $("#order-form").replaceWith(p);	
}