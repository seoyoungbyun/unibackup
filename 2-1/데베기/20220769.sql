create database ott;
use ott;
create table account
	(account_id		varchar(8), 
	 account_name	varchar(10), 
	 email			varchar(20),
	 primary key (account_id)
	);
create table profile
	(account_id varchar(8),
	profile_name varchar(40),
    profilepic_num varchar(30),
    repaccount_id varchar(8),
    primary key (account_id, profile_name),
    foreign key (account_id) references account(account_id)
		on delete cascade,
	foreign key (repaccount_id) references account(account_id) on delete cascade
	);
create table genre
	(genre_id varchar(8),
    genre_name varchar(15),
    primary key (genre_id)
    );
create table object
	(object_id varchar(8),
    object_name varchar(30),
    score numeric(6,1),
    recommendObj_id varchar(8),
    primary key(object_id),
    foreign key (recommendObj_id) references object(object_id) on delete cascade
    );
create table thumbnail
	(object_id varchar(8),
    thumbnail_id integer,
    primary key(object_id, thumbnail_id),
    foreign key (object_id) references object(object_id)
		on delete cascade
	);
create table belong
	(belong_id varchar(8),
    object_id varchar(8),
    genre_id varchar(8),
    primary key(belong_id),
    foreign key (object_id) references object(object_id)
		on delete set null,
	foreign key (genre_id) references genre(genre_id)
		on delete set null
	);
create table watch
	(watch_id varchar(20),
    rate varchar(10),
    watchdate date,
    account_id varchar(8),
    profile_name varchar(40),
    object_id varchar(8),
    primary key (watch_id),
    foreign key (account_id) references account(account_id) on delete cascade,
    foreign key (account_id, profile_name) references profile(account_id, profile_name)
		on delete cascade,
    foreign key (object_id) references object(object_id)
		on delete cascade
	);
    
    insert into account values("10001", "홍길동", "dong@gmail.com");
    insert into account values("10002", "김솜솜", "som@gmail.com");
    insert into account values("10003", "최동덕", "dong@gmail.com");
    insert into account values("10004", "변서영", "young@gmail.com");
    insert into account values("10005", "김지민", "dong@gmail.com");
    insert into account values("10006", "김동덕", "dongduck@gmail.com");
    insert into account values("10007", "강백호", "kang@gmail.com");
    insert into account values("10008", "김고은", "beauty@gmail.com");
    insert into account values("10009", "김솜솜", "som@gmail.com");
    insert into account values("10010", "정하라", "choose@gmail.com");
    select * from account;
	
    insert into profile values("10001", "홍홍", "11001", "10001");
    insert into profile values("10001", "아부지", "11002", null);
    insert into profile values("10001", "형", "11003", null);
    insert into profile values("10002", "솜솜", "12001", "10002");
    insert into profile values("10002", "솜", "12002", null);
    insert into profile values("10003", "동덕", "13001", "10003");
    insert into profile values("10004", "서영", "14001", "10004");
    insert into profile values("10004", "엄마", "14002", null);
    insert into profile values("10004", "아빠", "14003", null);
    insert into profile values("10004", "동그리", "14004", null);
    insert into profile values("10005", "지민", "15001", "10005");
    insert into profile values("10005", "채령", "15002", null);
	insert into profile values("10005", "비비", "15003", null);
    insert into profile values("10006", "동덕", "16001", "10006");
    insert into profile values("10006", "성신", "16002", null);
    insert into profile values("10007", "천재", "17001", "10007");
    insert into profile values("10007", "냐옹", "17002", null);
    insert into profile values("10007", "고릴라", "17003", null);
    insert into profile values("10007", "푸들", "17001", null);
    insert into profile values("10008", "낭랑18세", "18001", "10008");
    insert into profile values("10008", "저승사자", "18002", null);
    insert into profile values("10008", "도깨비", "18003", null);
    insert into profile values("10009", "김솜솜", "19001", "10009");
    insert into profile values("10009", "김동덕", "19002", null);
    insert into profile values("10010", "정하라", "20001", "10010");
    select * from profile;
    
    insert into genre values("20001", "드라마");
    insert into genre values("20002", "예능");
    insert into genre values("20003", "애니");
    insert into genre values("20004", "영화");
    insert into genre values("20005", "액션");
    insert into genre values("20006", "스릴러");
    insert into genre values("20007", "SF&판타지");
    insert into genre values("20008", "호러");
    insert into genre values("20009", "다큐");
    insert into genre values("20010", "코미디");
    insert into genre values("20011", "드라마 장르");
    insert into genre values("20012", "음악");
    insert into genre values("20013", "사극");
    insert into genre values("20014", "범죄");
    insert into genre values("20015", "미스터리");
    insert into genre values("20016", "로맨스");
    select * from genre;

    insert into object values("30001", "귀멸의 칼날", 4.8, null);
    update object set recommendObj_id = "30016" where object_id = "30001";
    insert into object values("30002", "더글로리", 3.6, null);
    update object set recommendObj_id = "30021" where object_id = "30002";
    insert into object values("30003", "나의나라", 3.2, null);
    update object set recommendObj_id = "30019" where object_id = "30003";
    insert into object values("30004", "하트시그널2", 4.3, null);
    update object set recommendObj_id = "30010" where object_id = "30004";
    insert into object values("30005", "헤어질 결심", 4.8, null);
    update object set recommendObj_id = "30011" where object_id = "30005";
    insert into object values("30006", "너의 이름은", 4.6, null);
    update object set recommendObj_id = "30020" where object_id = "30006";
    insert into object values("30007", "위플래쉬", 3.8, null);
	update object set recommendObj_id = "30022" where object_id = "30007";
    insert into object values("30008", "스물다섯 스물하나", 2.9, null);
    update object set recommendObj_id = "30011" where object_id = "30008";
    insert into object values("30009", "복수는 나의 것", 3.3, null);
    update object set recommendObj_id = "30005" where object_id = "30009";
    insert into object values("30010", "환승연애2", 4.3, null);
    update object set recommendObj_id = "30004" where object_id = "30010";
    insert into object values("30011", "이터널 선샤인", 4.9, null);
    update object set recommendObj_id = "30005" where object_id = "30011";
    insert into object values("30012", "킹덤", 3.5, null);
    update object set recommendObj_id = "30015" where object_id = "30012";
    insert into object values("30013", "스위트홈", 2.8, null);
    update object set recommendObj_id = "30012" where object_id = "30013";
    insert into object values("30014", "원령공주", 4.6, null);
    update object set recommendObj_id = "30023" where object_id = "30014";
    insert into object values("30015", "월드워Z", 3.3, null);
    update object set recommendObj_id = "30012" where object_id = "30015";
    insert into object values("30016", "주술회전", 3.7, null);
    update object set recommendObj_id = "30001" where object_id = "30016";
    insert into object values("30017", "메멘토", 4.6, null);
    update object set recommendObj_id = "30002" where object_id = "30017";
    insert into object values("30018", "1박2일", 4.2, null);
    update object set recommendObj_id = "30024" where object_id = "30018";
    insert into object values("30019", "선덕여왕", 4.7, null);
    update object set recommendObj_id = "30003" where object_id = "30019";
    insert into object values("30020", "날씨의 아이", 2.4, null);
    update object set recommendObj_id = "30006" where object_id = "30020";
    insert into object values("30021", "친절한 금자씨", 4.6, null);
    update object set recommendObj_id = "30009" where object_id = "30021";
    insert into object values("30022", "라라랜드", 3.9, null);
    update object set recommendObj_id = "30008" where object_id = "30022";
    insert into object values("30023", "나의 문어 선생님", 4.1, null);
    update object set recommendObj_id = "30025" where object_id = "30023";
    insert into object values("30024", "무한도전", 3.5, null);
    update object set recommendObj_id = "30018" where object_id = "30024";
    insert into object values("30025", "우리의 지구", 3.3, null);
    update object set recommendObj_id = "30023" where object_id = "30025";
    select * from object;

    insert into thumbnail values("30001", 1);
    insert into thumbnail values("30001", 2);
    insert into thumbnail values("30001", 3);
    insert into thumbnail values("30002", 1);
    insert into thumbnail values("30002", 2);
    insert into thumbnail values("30002", 3);
    insert into thumbnail values("30002", 4);
    insert into thumbnail values("30002", 5);
    insert into thumbnail values("30003", 1);
    insert into thumbnail values("30003", 2);
    insert into thumbnail values("30004", 1);
    insert into thumbnail values("30004", 2);
    insert into thumbnail values("30004", 3);
    insert into thumbnail values("30004", 4);
    insert into thumbnail values("30005", 1);
    insert into thumbnail values("30006", 1);
    insert into thumbnail values("30006", 2);
    insert into thumbnail values("30006", 3);
    insert into thumbnail values("30007", 1);
    insert into thumbnail values("30007", 2);
    insert into thumbnail values("30008", 1);
    insert into thumbnail values("30008", 2);
    insert into thumbnail values("30008", 3);
    insert into thumbnail values("30008", 4);
    insert into thumbnail values("30008", 5);
    insert into thumbnail values("30009", 1);
    insert into thumbnail values("30009", 2);
    insert into thumbnail values("30009", 3);
    insert into thumbnail values("30010", 1);
    insert into thumbnail values("30011", 1);
    insert into thumbnail values("30011", 2);
    insert into thumbnail values("30012", 1);
    insert into thumbnail values("30012", 2);
    insert into thumbnail values("30012", 3);
    insert into thumbnail values("30012", 4);
    insert into thumbnail values("30012", 5);
    insert into thumbnail values("30013", 1);
    insert into thumbnail values("30013", 2);
    insert into thumbnail values("30013", 3);
    insert into thumbnail values("30014", 1);
    insert into thumbnail values("30014", 2);
    insert into thumbnail values("30014", 3);
    insert into thumbnail values("30014", 4);
    insert into thumbnail values("30015", 1);
    insert into thumbnail values("30015", 2);
    insert into thumbnail values("30015", 3);
    insert into thumbnail values("30016", 1);
    insert into thumbnail values("30016", 2);
    insert into thumbnail values("30017", 1);
    insert into thumbnail values("30017", 2);
    insert into thumbnail values("30017", 3);
    insert into thumbnail values("30018", 1);
    insert into thumbnail values("30018", 2);
    insert into thumbnail values("30019", 1);
    insert into thumbnail values("30019", 2);
    insert into thumbnail values("30020", 1);
    insert into thumbnail values("30020", 2);
    insert into thumbnail values("30020", 3);
    insert into thumbnail values("30020", 4);
    insert into thumbnail values("30021", 1);
    insert into thumbnail values("30021", 2);
    insert into thumbnail values("30021", 3);
    insert into thumbnail values("30022", 1);
    insert into thumbnail values("30022", 2);
    insert into thumbnail values("30022", 3);
    insert into thumbnail values("30022", 4);
    insert into thumbnail values("30023", 1);
    insert into thumbnail values("30023", 2);
    insert into thumbnail values("30024", 1);
    insert into thumbnail values("30024", 2);
    insert into thumbnail values("30024", 3);
    insert into thumbnail values("30025", 1);
    insert into thumbnail values("30025", 2);
    select * from thumbnail;
    
    insert into belong values("40001", "30001", "20003");
    insert into belong values("40002", "30001", "20005");
    insert into belong values("40003", "30002", "20001");
    insert into belong values("40004", "30002", "20005");
    insert into belong values("40005", "30002", "20006");
    insert into belong values("40006", "30002", "20014");
    insert into belong values("40007", "30003", "20001");
    insert into belong values("40008", "30003", "20005");
    insert into belong values("40009", "30003", "20013");
    insert into belong values("40010", "30004", "20002");
    insert into belong values("40011", "30004", "20016");
    insert into belong values("40012", "30005", "20004");
    insert into belong values("40013", "30005", "20011");
    insert into belong values("40014", "30005", "20014");
    insert into belong values("40015", "30005", "20015");
    insert into belong values("40016", "30005", "20016");
    insert into belong values("40017", "30006", "20004");
    insert into belong values("40018", "30006", "20003");
    insert into belong values("40019", "30006", "20016");
    insert into belong values("40020", "30006", "20011");
    insert into belong values("40021", "30007", "20004");
    insert into belong values("40022", "30007", "20012");
    insert into belong values("40023", "30007", "20011");
    insert into belong values("40024", "30008", "20001");
    insert into belong values("40025", "30008", "20011");
    insert into belong values("40026", "30008", "20016");
    insert into belong values("40027", "30009", "20004");
    insert into belong values("40028", "30009", "20014");
    insert into belong values("40029", "30010", "20002");
    insert into belong values("40030", "30010", "20016");
    insert into belong values("40031", "30011", "20004");
    insert into belong values("40032", "30011", "20016");
    insert into belong values("40033", "30011", "20011");
    insert into belong values("40034", "30011", "20007");
    insert into belong values("40035", "30012", "20001");
    insert into belong values("40036", "30012", "20013");
    insert into belong values("40037", "30012", "20007");
    insert into belong values("40038", "30012", "20005");
    insert into belong values("40039", "30013", "20001");
    insert into belong values("40040", "30013", "20005");
    insert into belong values("40041", "30013", "20007");
    insert into belong values("40042", "30014", "20004");
    insert into belong values("40043", "30014", "20003");
    insert into belong values("40044", "30014", "20005");
    insert into belong values("40045", "30014", "20011");
    insert into belong values("40046", "30015", "20004");
    insert into belong values("40047", "30015", "20005");
    insert into belong values("40048", "30015", "20007");
    insert into belong values("40049", "30015", "20006");
    insert into belong values("40050", "30015", "20011");
    insert into belong values("40051", "30016", "20003");
    insert into belong values("40052", "30016", "20005");
    insert into belong values("40053", "30017", "20004");
    insert into belong values("40054", "30017", "20005");
    insert into belong values("40055", "30017", "20006");
    insert into belong values("40056", "30017", "20014");
    insert into belong values("40057", "30017", "20015");
    insert into belong values("40058", "30018", "20002");
    insert into belong values("40059", "30018", "20010");
    insert into belong values("40060", "30019", "20001");
    insert into belong values("40061", "30019", "20013");
    insert into belong values("40062", "30019", "20005");
    insert into belong values("40063", "30019", "20011");
    insert into belong values("40064", "30020", "20004");
    insert into belong values("40065", "30020", "20003");
    insert into belong values("40066", "30020", "20016");
    insert into belong values("40067", "30020", "20011");
    insert into belong values("40068", "30021", "20004");
    insert into belong values("40069", "30021", "20006");
    insert into belong values("40070", "30021", "20011");
    insert into belong values("40071", "30021", "20014");
    insert into belong values("40072", "30022", "20004");
    insert into belong values("40073", "30022", "20012");
    insert into belong values("40074", "30022", "20011");
    insert into belong values("40075", "30022", "20016");
    insert into belong values("40076", "30023", "20009");
    insert into belong values("40077", "30024", "20002");
    insert into belong values("40078", "30024", "20010");
    insert into belong values("40079", "30025", "20009");
    select * from belong;
	
    insert into watch values("50001", "good", "2023-04-24", "10001", "홍홍", "30003");
    insert into watch values("50002", "good", "2023-04-25", "10001", "홍홍", "30019");
    insert into watch values("50003", "good", "2023-01-04", "10001", "형", "30003");
    insert into watch values("50004", "good", "2023-03-28", "10001", "형", "30007");
    insert into watch values("50005", "bad", "2023-01-22", "10001", "아부지", "30012");
    insert into watch values("50006", "bad", "2023-04-21", "10002", "솜솜", "30020");
    insert into watch values("50007", "good", "2023-04-25", "10003", "동덕", "30023");
    insert into watch values("50008", "good", "2023-04-25", "10003", "동덕", "30025");
    insert into watch values("50009", "good", "2023-04-03", "10004", "서영", "30001");
    insert into watch values("50010", "bad", "2023-04-03", "10004", "서영", "30022");
    insert into watch values("50011", "good", "2023-04-03", "10004", "서영", "30024");
    insert into watch values("50012", "bad", "2023-04-07", "10004", "서영", "30014");
    insert into watch values("50013", "good", "2023-05-19", "10004", "엄마", "30002");
    insert into watch values("50014", "bad", "2023-05-19", "10004", "엄마", "30018");
    insert into watch values("50015", "good", "2023-05-06", "10005", "채령", "30001");
    insert into watch values("50016", "good", "2023-05-06", "10005", "채령", "30016");
    insert into watch values("50017", "bad", "2023-04-29", "10005", "지민", "30025");
    insert into watch values("50018", "good", "2023-04-30", "10005", "지민", "30023");
    insert into watch values("50019", "good", "2023-05-27", "10006", "동덕", "30012");
    insert into watch values("50020", "good", "2023-05-27", "10006", "동덕", "30010");
    insert into watch values("50021", "good", "2023-05-14", "10006", "성신", "30005");
    insert into watch values("50022", "bad", "2023-05-27", "10007", "천재", "30001");
    insert into watch values("50023", "bad", "2023-05-27", "10007", "천재", "30003");
    insert into watch values("50024", "good", "2023-05-29", "10007", "천재", "30008");
    insert into watch values("50025", "good", "2023-05-14", "10007", "냐옹", "30017");
    insert into watch values("50026", "good", "2023-04-18", "10007", "고릴라", "30023");
    insert into watch values("50027", "bad", "2023-05-27", "10007", "고릴라", "30022");
    insert into watch values("50028", "good", "2023-03-16", "10007", "푸들", "30011");
    insert into watch values("50029", "bad", "2023-02-11", "10008", "저승사자", "30011");
    insert into watch values("50030", "bad", "2023-04-24", "10008", "저승사자", "30019");
    insert into watch values("50031", "good", "2023-03-23", "10008", "낭랑18세", "30005");
    insert into watch values("50032", "good", "2023-03-17", "10008", "낭랑18세", "30010");
    insert into watch values("50033", "good", "2023-03-17", "10008", "도깨비", "30010");
    insert into watch values("50034", "bad", "2023-05-07", "10009", "김솜솜", "30009");
    insert into watch values("50035", "good", "2023-05-07", "10009", "김솜솜", "30021");
    insert into watch values("50036", "bad", "2023-04-12", "10010", "정하라", "30015");
    insert into watch values("50037", "good", "2023-04-12", "10010", "정하라", "30013");
    insert into watch values("50038", "bad", "2023-04-15", "10010", "정하라", "30017");
    select * from watch;
    
	-- (1)’이터널 선샤인’의 썸네일 개수를 구해라
    select count(thumbnail.thumbnail_id) as thumbniail_num 
    from object, thumbnail 
    where object.object_id = thumbnail.object_id and object.object_name = "이터널 선샤인";
    
    -- (2)'변서영' 계정에 소속된 프로필 개수를 구해라
    select count(profile.profile_name) profile_num
    from account, profile 
    where account.account_id = profile.account_id and account.account_name = "변서영";
    
    -- (3)'영화' 장르에 소속된 작품의 이름을 찾아라
    select object.object_name 
    from object, belong, genre 
    where object.object_id = belong.object_id and belong.genre_id = genre.genre_id 
		and genre_name = "영화";
        
	-- (4)전체평균평점보다 더 평점이 높은 작품을 찾아라
    select o.object_id, o.object_name, o.score 
    from object o 
    where o.score > (select avg(score) from object);
    
	-- (5)'다큐' 장르에 소속된 작품을 모두 본 프로필의 계정id와 프로필 이름을 찾아라
    select p1.account_id, p1.profile_name 
    from profile p1 
    where not exists(select b.object_id 
					from belong b, genre g 
                    where b.genre_id = g.genre_id and g.genre_name = "다큐" and b.object_id not in 
												(select w.object_id 
                                                from profile as p2, watch w 
                                                where p2.account_id = w.account_id 
													and p2.profile_name = w.profile_name 
													and p1.account_id = p2.account_id 
													and p1.profile_name = p2.profile_name));
                                                    
    -- (6)소속된 작품이 3개 이상인 장르의 이름을 찾아라
    select genre_name 
    from genre a 
    where a.genre_id = (select genre_id 
						from belong b 
                        where a.genre_id = b.genre_id 
                        group by genre_id 
                        having count(*) > 2);
    
    -- (7)각 계정의 대표 프로필을 구해라
    select a.account_id, a.account_name, p.profile_name repprofile_name
    from profile p, account a 
    where a.account_id = p.account_id 
		and p.profile_name in (select p.profile_name 
								from account a2 
								where a2.account_id = p.account_id and p.repaccount_id = a2.account_id 
								group by a2.account_id);
		
    -- (8)'코미디'보다 더 많은 작품이 소속된 장르의 이름을 찾아라
    select g.genre_name 
    from genre g, belong b 
    where g.genre_id = b.genre_id 
    group by g.genre_id 
    having count(b.object_id) > (select count(b2.object_id) 
								from genre g2, belong b2 
                                where g2.genre_id = b2.genre_id and g2.genre_name = '코미디');
    
    -- (9)장르별 최고평점 작품을 구해라
    select g.genre_name, o.object_id, o.object_name, o.score 
    from object o, genre g, belong b 
    where g.genre_id = b.genre_id and o.object_id = b.object_id 
		and (g.genre_id, o.score) in(select b2.genre_id, max(o2.score) 
									from object o2, belong b2 
									where o2.object_id = b2.object_id 
									group by b2.genre_id);
    
    -- (10)2번 이상 추천된 작품을 구해라
    select o.object_id, o.object_name, o.score 
    from object o where o.object_id in (select recommendObj_id 
										from object 
                                        group by recommendObj_id 
                                        having count(recommendObj_id) >= 2);
                                
	 -- (11)프로필이 2개 이상인 계정이름과 프로필 개수를 구해라
    select account_name, count(profile.profile_name) as profile_num 
    from account, profile 
    where account.account_id = profile.account_id 
    group by profile.account_id 
    having count(profile.profile_name) >= 2;
    