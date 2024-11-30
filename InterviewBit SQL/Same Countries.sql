SELECT   l1.Name as Labourer1, l2.Name as Labourer2, l1.Country as Country
FROM     LABOURERS l1, LABOURERS l2
WHERE    l1.Country = l2.Country and l1.Name <> l2.Name
ORDER BY 1, 2, 3
