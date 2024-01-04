select sp.name from SalesPerson sp where sp.sales_id not in (Select o.sales_id from Orders o where
o.com_id in (Select c.com_id from Company c where c.name='RED'));
