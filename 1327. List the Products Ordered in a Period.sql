SELECT p.product_name,sum(o.unit)as unit
FROM Products p
JOIN Orders o ON p.product_id = o.product_id
WHERE o.order_date >= '2020-02-01' AND o.order_date < '2020-03-01' group by p.product_id having unit>=100;
