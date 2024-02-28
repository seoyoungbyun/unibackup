package jspbook.pr31;

public class Calculator {
	private int num1, num2;
	private String op;
	
	public int getNum1() {
		return num1;
	}
	public void setNum1(int num1) {
		this.num1 = num1;
	}
	public int getNum2() {
		return num2;
	}
	public void setNum2(int num2) {
		this.num2 = num2;
	}
	public String getOp() {
		return op;
	}
	public void setOp(String op) {
		this.op = op;
	}
	
	public int calc() {
		int result = 0;
		switch (op) {
			case "+":
				result = add(num1, num2);
				break;
			case "-":
				result = sub(num1, num2);
				break;
			case "*":
				result = mult(num1, num2);
				break;
			case "/":
				result = div(num1, num2);
				break;
		}
		
		return result;
	}
	public int add(int a, int b) {
		return a + b;
	}
	public int sub(int a, int b) {
		return a - b;
	}
	public int mult(int a, int b) {
		return a * b;
	}
	public int div(int a, int b) {
		return a / b;
	}
}
