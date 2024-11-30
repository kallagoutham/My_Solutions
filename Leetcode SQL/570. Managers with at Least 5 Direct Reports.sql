/* Write your MySQL query statement below */
select e.name from Employee e where e.id in (select e2.managerId from Employee e2 group by e2.managerId having count(*)>=5 );
