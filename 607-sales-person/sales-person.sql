SELECT
    s.name
FROM SalesPerson s
LEFT JOIN Orders o
    ON s.sales_id = o.sales_id
LEFT JOIN Company c
    ON o.com_id = c.com_id
GROUP BY s.sales_id, s.name
HAVING COALESCE(SUM(c.name = 'RED'), 0) = 0;