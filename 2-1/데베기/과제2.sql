use Univ1;

--- (1) To find all instructors in Comp. Sci. dept with salary > 80000
	select id from instructor where salary > 80000 AND dept_name = 'Comp. Sci.';
--- (2) Find the names of all instructors in the Art  department who have taught some course and the course_id
	select distinct instructor.name, teaches.course_id from instructor, course, teaches 
    where instructor.id = teaches.id and teaches.course_id = course.course_id and course.dept_name = 'Art';
--- (3) Find the names of all instructors who have a higher salary than some instructor in 'Comp. Sci'.
	select distinct T.name from instructor T, instructor S where T.salary > S.salary and S.dept_name = 'Comp. Sci.';
--- (4) Find courses that ran in spring 2010  and in Fall 2009
    /*(select course_id  from takes where semester = 'Spring' AND year = 2010) 
    intersect (select course_id  from takes where semester = 'Fall' AND year = 2009);*/
    select a.course_id from takes a, takes b 
    where a.course_id = b.course_id and (a.semester = 'Spring' and a.year = 2010) and (b.semester = 'Fall' and b.year = 2009);
--- (5) Find the average salary of instructors in the Computer Science department 
	select avg(salary) from instructor where dept_name = 'Comp. Sci.' group by dept_name;
--- (6) Find the total number of instructors who teach a course in the Spring 2010 semester
    select count(distinct id) from teaches where semester = 'Spring' AND year = 2010;
--- (7) Find the names and average salaries of all departments whose average salary is greater than 42000
	select dept_name, avg(salary) from instructor group by dept_name having avg(salary) > 42000;
--- (8) Find the total number of (distinct) students who have taken course sections taught by the instructor with ID 10101
	select count(distinct id) from takes 
    where (course_id, sec_id, semester, year) in (select course_id, sec_id, semester, year from teaches where id = 10101);
--- (9) Find the names of all instructors whose salary is greater than the salary of all instructors in the Comp. Sci. department.
    select T.name from instructor T where T.salary > all(select salary from instructor where dept_name = 'Comp. Sci.');
--- (10) Find all students who have taken all courses offered in the Biology department.
	select s.id from student s where not exists 
    (select teaches.course_id from course, teaches where course.course_id = teaches.course_id and course.dept_name = 'Biology' and teaches.course_id not in 
    (select t.course_id from takes as t where s.id = t.id));
--- (11) Delete all instructors from the Finance department
	delete from instructor where dept_name = 'Finance';
--- (12) Increase salaries of instructors whose salary is over $100,000 by 3%, and all others by a 5% 
	/*set sql_safe_updates = 0;
	update instructor set salary = salary * 1.03 where salary > 100000;
	update instructor set salary = salary * 1.05 where salary <= 100000;*/
	/*순서 상관있음-50프로 인상 후 30프로 인상 가능*/
	update instructor 
	set salary = case 
		when salary > 100000 then salary * 1.03 
		else salary * 1.05
	end;
          

