create database madangDB;
USE madangDB;

Create Table Book(
	bookid integer primary key, 
    bookname varchar(40),
    publisher varchar(40),
    price integer
    );

Create table customer(
	custid integer primary key,
    name varchar(40),
    address varchar(50),
    phone varchar(20)
    );
Create table orders(
	orderid integer primary key,
    custid integer,
    bookid integer,
    saleprice integer,
    orderdate date,
    foreign key (custid) references customer(custid),
    foreign key (bookid) references Book(bookid)
    );
    
    insert INTO BOOK VALUES (1, '축구의 역사', '굿스포츠', 7000);
    insert INTO BOOK VALUES(2, '축구아는 여자', '나무수', 13000);
    insert INTO BOOK VALUES(3, '축구의 이해', '대한미디어', 22000);
    insert INTO BOOK VALUES(4, '골프 바이블', '대한미디어', 35000);
    insert INTO BOOK VALUES(5, '피겨 교본', '굿스포츠', 8000);
    insert INTO BOOK VALUES(6, '역도 단계별기술', '굿스포츠', 6000);
    insert INTO BOOK VALUES(7, '야구의 추억', '이상미디어', 20000);
    insert INTO BOOK VALUES(8, '야구를 부탁해', '이상미디어', 13000);
    insert INTO BOOK VALUES(9, '올림픽 이야기', '삼성당', 7500);
    insert INTO BOOK VALUES(10, 'Olympic Champions', 'Pearson', 13000);
    SELECT * FROM Book;
    
    INSERT INTO Customer values (1, '박지성', '영국 맨체스터', '000-5000-0001');
    INSERT INTO Customer values(2, '김연아', '대한민국 서울', '000-6000-0001');
    INSERT INTO Customer values(3, '장미란', '대한민국 강원도', '000-7000-0001');
    INSERT INTO Customer values(4, '추신수', '미국 클리블랜드', '000-8000-0001');
    INSERT INTO Customer values(5, '박세리', '대한민국 대전', NULL);
    SELECT * FROM Customer;
    
    insert into orders values (1, 1, 1, 6000, '2014-07-01');
    insert into orders values (2, 1, 3, 21000, '2014-07-03');
    insert into orders values (3, 2, 5, 8000, '2014-07-03');
    insert into orders values (4, 3, 6, 6000, '2014-07-01');
    insert into orders values (5, 4, 7, 20000, '2014-07-01');
    insert into orders values (6, 1, 2, 12000, '2014-07-01');
    insert into orders values (7, 4, 8, 6000, '2014-07-01');
    insert into orders values (8, 3, 10, 6000, '2014-07-01');
    insert into orders values (9, 2, 10, 6000, '2014-07-01');
    insert into orders values (10, 3, 8, 6000, '2014-07-01');
    SELECT * FROM orders;