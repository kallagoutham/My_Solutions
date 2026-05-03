SELECT MIN(ABS(x - next_x)) AS shortest
FROM (
    SELECT x, LEAD(x) OVER (ORDER BY x) AS next_x
    FROM Point
) t
WHERE next_x IS NOT NULL;
