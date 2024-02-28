use madang_02;
SHOW TABLES;

select * from Customer;
select * from Orders;
select * from Book;

-- [뷰질의 1] 주소에 ‘대한민국’을 포함하는 고객들로 구성된 뷰를 만들고 조회하시오. 단, 뷰의 이름은 vw_Customer로 한다.
CREATE VIEW vw_Customer
AS SELECT *
	FROM Customer
	WHERE address LIKE '%대한민국%';

-- 뷰 질의 속도    
select * from vw_Customer;
select * from Customer where address like '%대한민국%';

-- 뷰와 테이블의 조인
select * from vw_Customer v, Orders o where v.custid = o.custid and saleprice >10000;
select * from Customer c, Orders o where c.custid = o.custid and address like '%대한민국%' and saleprice > 10000;

-- 뷰를 통한 업데이트
set sql_safe_updates=0;

update vw_Customer set name = "김현아" where name = "김연아";
select * from vw_Customer;
select * from Customer;

update customer set name="김연아" where name="김현아";
select * from customer;

-- 뷰의 업데이트
ALTER VIEW vw_Customer (custid, name, address)
AS SELECT custid, name, address
	FROM Customer
	WHERE address LIKE '%영국%';
    
select * from vw_Customer;

-- 뷰의 삭제 
DROP VIEW vw_Customer;

-- [뷰질의 2] Orders 테이블에 고객이름과 도서이름을 바로 확인할 수 있는 뷰를 생성 
CREATE VIEW vw_Orders (orderid, custid, name, bookid, bookname, saleprice, orderdate)
AS SELECT od.orderid, od.custid, cs.name,
		od.bookid, bk.bookname, od.saleprice, od.orderdate
FROM Orders od, Customer cs, Book bk
WHERE od.custid =cs.custid AND od.bookid =bk.bookid;

-- ‘김연아’ 고객이 구입한 도서의 주문번호, 도서이름, 주문액을 보이시오.
select orderid, bookname, saleprice from vw_Orders where name="김연아";

-- [뷰질의 3] 판매가격이 20,000원인 도서의 도서번호, 도서이름, 고객이름, 판매가격을 보여주는 highorders 뷰를 생성하시오.
-- 테이블로 뷰생성
CREATE VIEW Highorders 
	AS	SELECT b.bookid, b.bookname, c.name, o.saleprice
		FROM Book b, Orders o, Customer c
		WHERE b.bookid=o.bookid AND o.custid=c.custid AND saleprice = 20000; 
        

select * from Highorders;
 
 -- 뷰로 뷰생성
CREATE VIEW Highorders2 
	AS	SELECT bookid, bookname, name, saleprice
		FROM vw_Orders
		WHERE saleprice = 20000;
   
select * from Highorders2;

-- 생성한 뷰를 이용하여 판매된 도서의 이름과 고객의 이름을 출력하는 SQL 문을 작성하시오.
SELECT bookname, name FROM Highorders;
SELECT bookname, name FROM Highorders2;

-- 뷰를 삭제하고 나면 다른 뷰들은 어떻게 될까?
drop view vw_Orders;

-- highorders 뷰를 변경하고자 한다. 판매가격 속성을 삭제하고 출판사를 추가하는 명령을 수행하시오.
ALTER VIEW Highorders 
	AS	SELECT b.bookid, b.bookname, c.name, b.publisher
		FROM Book b, Orders o, Customer c
		WHERE b.bookid=o.bookid AND o.custid=c.custid AND saleprice > 15000; 
        
select * from Highorders;

