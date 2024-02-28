-- 1. SQL로 인덱스 생성
/*** 1. 테이블 생성후 자료 입력 사용된 파일은? *************/
CREATE TABLE userTbl1
(	userID char(8) NOT NULL,
	name nvarchar(10) NOT NULL,
	birthYear int NOT NULL,
	addr nchar(2) NOT NULL
);

INSERT INTO userTbl1 VALUES('LSG', '이승기', 1987, '서울');
INSERT INTO userTbl1 VALUES('KBS', '김범수', 1979, '경남');
INSERT INTO userTbl1 VALUES('KKH', '김경호', 1971, '전남');
INSERT INTO userTbl1 VALUES('JYP', '조용필', 1950, '경기');
INSERT INTO userTbl1 VALUES('SSK', '성시경', 1979, '서울');

SELECT * FROM userTbl1;


/*** 2. 테이블 생성후 자료 입력 사용된 파일은? *************/
CREATE TABLE userTbl2
(	userID char(8) NOT NULL primary key,
	name nvarchar(10) NOT NULL,
	birthYear int NOT NULL,
	addr nchar(2) NOT NULL
);

INSERT INTO userTbl2 VALUES('LSG', '이승기', 1987, '서울');
INSERT INTO userTbl2 VALUES('KBS', '김범수', 1979, '경남');
INSERT INTO userTbl2 VALUES('KKH', '김경호', 1971, '전남');
INSERT INTO userTbl2 VALUES('JYP', '조용필', 1950, '경기');
INSERT INTO userTbl2 VALUES('SSK', '성시경', 1979, '서울');

SELECT * FROM userTbl2;


/*** 3. heap 파일에 클러스터링 인덱스 생성****/
ALTER TABLE userTbl1
	ADD CONSTRAINT PK_userID
		PRIMARY KEY (userID);

select * from userTbl1;


/*** 4. heap 파일에 비클러스터링 인덱스 생성 *****/
CREATE TABLE userTbl3
(	userID char(8) NOT NULL,
	name nvarchar(10) NOT NULL,
	birthYear int NOT NULL,
	addr nchar(2) NOT NULL
);

INSERT INTO userTbl3 VALUES('LSG', '이승기', 1987, '서울');
INSERT INTO userTbl3 VALUES('KBS', '김범수', 1979, '경남');
INSERT INTO userTbl3 VALUES('KKH', '김경호', 1971, '전남');
INSERT INTO userTbl3 VALUES('JYP', '조용필', 1950, '경기');
INSERT INTO userTbl3 VALUES('SSK', '성시경', 1979, '서울');

create index index_userID on userTbl3(userID);
select * from userTbl3;


/***5. sequential file + clustering index + nunclustering index ****/
create index index_name on userTbl2(name);
select * from userTbl2;

/**테이블 생성/변경 문으로 인덱스 생성 ***/

CREATE TABLE clusterTbl
(	userID char(8) NOT NULL ,
	name nvarchar(10) NOT NULL
);

INSERT INTO clusterTbl VALUES('LSG', '이승기');
INSERT INTO clusterTbl VALUES('KBS', '김범수');
INSERT INTO clusterTbl VALUES('KKH', '김경호');
INSERT INTO clusterTbl VALUES('JYP', '조용필');
INSERT INTO clusterTbl VALUES('SSK', '성시경');
INSERT INTO clusterTbl VALUES('LJB', '임재범');
INSERT INTO clusterTbl VALUES('YJS', '윤종신');
INSERT INTO clusterTbl VALUES('EJW', '은지원');
INSERT INTO clusterTbl VALUES('JKW', '조관우');
INSERT INTO clusterTbl VALUES('BBK', '바비킴');

SELECT * FROM clusterTbl;


ALTER TABLE clusterTbl
	ADD CONSTRAINT PK_clusterTbl_userID
		PRIMARY KEY (userID);

INSERT INTO clusterTbl VALUES('FNT', '푸니타');
INSERT INTO clusterTbl VALUES('KAI', '카아이');

SELECT * FROM clusterTbl;

/***2. 비클러스터링 인덱스 생성****/
CREATE TABLE nonclusterTbl
(	userID char(8) NOT NULL ,
	name nvarchar(10) NOT NULL
);

INSERT INTO nonclusterTbl VALUES('LSG', '이승기');
INSERT INTO nonclusterTbl VALUES('KBS', '김범수');
INSERT INTO nonclusterTbl VALUES('KKH', '김경호');
INSERT INTO nonclusterTbl VALUES('JYP', '조용필');
INSERT INTO nonclusterTbl VALUES('SSK', '성시경');
INSERT INTO nonclusterTbl VALUES('LJB', '임재범');
INSERT INTO nonclusterTbl VALUES('YJS', '윤종신');
INSERT INTO nonclusterTbl VALUES('EJW', '은지원');
INSERT INTO nonclusterTbl VALUES('JKW', '조관우');
INSERT INTO nonclusterTbl VALUES('BBK', '바비킴');

ALTER TABLE nonclusterTbl
	ADD CONSTRAINT UK_nonclusterTbl_userID
		UNIQUE (userID);

SELECT * FROM nonclusterTbl;

INSERT INTO nonclusterTbl VALUES('FNT', '푸니타');
INSERT INTO nonclusterTbl VALUES('KAI', '카아이');

/****3. 복합 인덱스 *****/
CREATE TABLE mixedTbl
(	userID char(8) NOT NULL ,
	name nvarchar(10) NOT NULL,
	addr nchar(2)
);

INSERT INTO mixedTbl VALUES('LSG', '이승기', '서울');
INSERT INTO mixedTbl VALUES('KBS', '김범수', '경남');
INSERT INTO mixedTbl VALUES('KKH', '김경호', '전남');
INSERT INTO mixedTbl VALUES('JYP', '조용필', '경기');
INSERT INTO mixedTbl VALUES('SSK', '성시경', '서울');
INSERT INTO mixedTbl VALUES('LJB', '임재범', '서울');
INSERT INTO mixedTbl VALUES('YJS', '윤종신', '경남');
INSERT INTO mixedTbl VALUES('EJW', '은지원', '경북');
INSERT INTO mixedTbl VALUES('JKW', '조관우', '경기');
INSERT INTO mixedTbl VALUES('BBK', '바비킴', '서울');


ALTER TABLE mixedTbl
	ADD CONSTRAINT PK_mixedTbl_userID
		PRIMARY KEY (userID);


ALTER TABLE mixedTbl
	ADD CONSTRAINT UK_mixedTbl_name
		UNIQUE (name) ;

SELECT * FROM mixedTbl;

INSERT INTO mixedTbl VALUES('FNT', '푸니타','부산');
INSERT INTO mixedTbl VALUES('KAI', '카아이', '서울');
