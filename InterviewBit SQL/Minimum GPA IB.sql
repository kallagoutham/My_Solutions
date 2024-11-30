select concat(d.DepartmentName,’,’,t2.name,’,’,t2.GPA) as A
from Departments as d
join (select s2.name as name, s2.GPA as GPA, s2.DepartmentId as id
from Students as s2
join (select s.DepartmentId, min(s.GPA) as min_gpa
from Students as s
group by s.DepartmentId) as t1 on t1.DepartmentId = s2.DepartmentId and t1.min_gpa = s2.GPA) as t2 on t2.id = d.DepartmentId
order by d.DepartmentName;
