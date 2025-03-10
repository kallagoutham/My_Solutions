WITH percentage as(
select query_name, ROUND(AVG(rating<3)*100,2) as percent
from Queries 
GROUP BY query_name 
)

Select Queries.query_name,ROUND(SUM(Queries.rating/Queries.position)/count(Queries.query_name),2) as quality,percentage.percent as poor_query_percentage
from Queries JOIN percentage
ON Queries.query_name=percentage.query_name
Group BY query_name 
