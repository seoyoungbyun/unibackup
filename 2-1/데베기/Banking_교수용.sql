create database bank;
use bank;

create table account
   (account_number 	varchar(15)	not null unique,
    branch_name		varchar(15)	not null,
    balance 		int		not null,
    primary key(account_number));

create table branch
   (branch_name 	varchar(15)	not null unique,
    branch_city 	varchar(15)	not null,
    assets 		int		not null,
    primary key(branch_name));

create table customer
   (customer_name 	varchar(15)	not null unique,
    customer_street 	varchar(12)	not null,
    customer_city 	varchar(15)	not null,
    primary key(customer_name));

create table loan
   (loan_number 	varchar(15)	not null unique,
    branch_name		varchar(15)	not null,
    amount 		int		not null,
    primary key(loan_number));

create table depositor
   (customer_name 	varchar(15)	not null,
    account_number 	varchar(15)	not null,
    primary key(customer_name, account_number),
    foreign key(account_number) references account(account_number),
    foreign key(customer_name) references customer(customer_name));

create table borrower
   (customer_name 	varchar(15)	not null,
    loan_number 	varchar(15)	not null,
    primary key(customer_name, loan_number),
    foreign key(customer_name) references customer(customer_name),
    foreign key(loan_number) references loan(loan_number));

/* populate relations */

insert into customer	values ('Jones',	'Main',		'Harrison');
insert into customer	values ('Smith',	'Main',		'Rye');
insert into customer	values ('Hayes',	'Main',		'Harrison');
insert into customer	values ('Curry',	'North',	'Rye');
insert into customer	values ('Lindsay',	'Park',		'Pittsfield');
insert into customer	values ('Turner',	'Putnam',	'Stamford');
insert into customer	values ('Williams',	'Nassau',	'Princeton');
insert into customer	values ('Adams',	'Spring',	'Pittsfield');
insert into customer	values ('Johnson',	'Alma',		'Palo Alto');
insert into customer	values ('Glenn',	'Sand Hill',	'Woodside');
insert into customer	values ('Brooks',	'Senator',	'Brooklyn');
insert into customer	values ('Green',	'Walnut',	'Stamford');
insert into customer	values ('Jackson',	'University',	'Salt Lake');
insert into customer	values ('Majeris',	'First',	'Rye');
insert into customer	values ('McBride',	'Safety',	'Rye');

insert into branch	values ('Downtown',	'Brooklyn',	 900000);
insert into branch	values ('Redwood',	'Palo Alto',	2100000);
insert into branch	values ('Perryridge',	'Horseneck',	1700000);
insert into branch	values ('Mianus',	'Horseneck',	 400200);
insert into branch	values ('Round Hill',	'Horseneck',	8000000);
insert into branch	values ('Pownal',	'Bennington',	 400000);
insert into branch	values ('North Town',	'Rye',		3700000);
insert into branch	values ('Brighton',	'Brooklyn',	7000000);
insert into branch	values ('Central',	'Rye',		 400280);

insert into account	values ('A-101',	'Downtown',	500);
insert into account	values ('A-215',	'Mianus',	700);
insert into account	values ('A-102',	'Perryridge',	400);
insert into account	values ('A-305',	'Round Hill',	350);
insert into account	values ('A-201',	'Perryridge',	900);
insert into account	values ('A-222',	'Redwood',	700);
insert into account	values ('A-217',	'Brighton',	750);
insert into account	values ('A-333',	'Central',	850);
insert into account	values ('A-444',	'North Town',	625);

insert into depositor values ('Johnson','A-101');
insert into depositor values ('Smith',	'A-215');
insert into depositor values ('Hayes',	'A-102');
insert into depositor values ('Hayes',	'A-101');
insert into depositor values ('Turner',	'A-305');
insert into depositor values ('Johnson','A-201');
insert into depositor values ('Johnson','A-217');
insert into depositor values ('Lindsay','A-222');
insert into depositor values ('Majeris','A-333');
insert into depositor values ('Smith',	'A-444');

insert into loan	values ('L-17',		'Downtown',	1000);
insert into loan	values ('L-23',		'Redwood',	2000);
insert into loan	values ('L-15',		'Perryridge',	1500);
insert into loan	values ('L-14',		'Downtown',	1500);
insert into loan	values ('L-93',		'Mianus',	500);
insert into loan	values ('L-11',		'Round Hill',	900);
insert into loan	values ('L-16',		'Perryridge',	1300);
insert into loan	values ('L-20',		'North Town',	7500);
insert into loan	values ('L-21',		'Central',	570);

insert into borrower values ('Jones',	'L-17');
insert into borrower values ('Smith',	'L-23');
insert into borrower values ('Hayes',	'L-15');
insert into borrower values ('Jackson',	'L-14');
insert into borrower values ('Curry',	'L-93');
insert into borrower values ('Smith',	'L-11');
insert into borrower values ('Williams','L-17');
insert into borrower values ('Adams',	'L-16');
insert into borrower values ('McBride',	'L-20');
insert into borrower values ('Smith',	'L-21');


-- 1. 대출 고객의 이름, 도시
select distinct customer.customer_name, customer_city
from borrower, customer
where borrower.customer_name = customer.customer_name
;

--- 2. 'Perryridge'지점에서 대출한 고객의 이름, 도시
select distinct C.customer_name, customer_city
from customer C, borrower B, loan L
where C.customer_name = B.customer_name and B.loan_number = L.loan_number and branch_name = 'Perryridge'
;
--- 3 'Perryridge'지점에서 대출만 하고 예금은 하지 않은 고객의 이름, 도시
select distinct customer_name
from borrower, loan
where borrower.loan_number = loan.loan_number and
    branch_name = 'Perryridge' and
	customer_name in (select customer_name
				from account, depositor
				where account.account_number =
					depositor.account_number and
					   branch_name = 'Perryridge')
;

--- 4. 'Hayes' 씨가 예금한 지점에 예금한 고객명
select distinct D.customer_name
from depositor D, account A
where D.account_number = A.account_number and
    branch_name in
	(select branch_name
	from depositor Dh, account Ah
	where Dh.account_number = Ah.account_number and
	    D.customer_name = 'Hayes');

--- 5. 'Brooklyn'시에 있는 지점들의 자산보다 큰 자산을 갖는 지점
select distinct T.branch_name
from branch T, branch S
where T.assets > S.assets and
	S.branch_city = 'Brooklyn';

select branch_name
from branch
where assets > all
	(select assets
	from branch
	where branch_city = 'Brooklyn');

--- 6. 'Perryridge' 지점의 평균 예금액
select avg(balance)
from account
where branch_name='Perryridge';

---- 7. 지점별 평균 예금액이 700 이상인 지점과 평균 예금액
select branch_name, avg(balance)
from account
group by branch_name
having avg(balance) > 700;

--- 8. 지점별 평균 예금액보다 평균 예금액이 큰 지점
select branch_name
from account
group by branch_name
having avg(balance) >= all(select avg(balance)
				from account
				group by branch_name);

--- 9. Brooklyn 시에 있는 모든 지점에 예금 계좌를 가지고 있는 고객명
select distinct S.customer_name
from depositor as S	
where not exists (		
    select branch_name
		from branch
		where branch_city ='Brooklyn' and branch_name not in        		
		(select R.branch_name
		from depositor as T, account as R
		where T.account_number = R.account_number and
			S.customer_name = T.customer_name ));

--- 10. 최대 예금액을 갖는 예금 계좌
with max_balance (value) as 
(select max(balance)
from account)
select account_number
from account, max_balance   
where account.balance = max_balance.value;

--- 11. 'Needham' 시에 위치한 모든 지점의 모든 예금 계좌 삭제
set sql_safe_updates=0;

delete from account
where branch_name in 
       (select branch_name
      from branch
       where branch_city = 'Needham');


--- 12. 은행의 평균 예금액보다 적은 예금 계좌 삭제
delete from account                
where balance < (select avg (balance ) from account );

--- 13. $10,000 보다 예금액이 큰 예금계좌는 6% 이자 지급, 이외의 계좌는 5% 이자를 지급
update account
	set balance = balance * 1.06
	where balance > 10000;
update account
	set balance = balance * 1.05
	where balance <= 10000;
