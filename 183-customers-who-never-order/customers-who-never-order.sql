# Write your MySQL query statement below

select 
    c1.name as Customers
from Customers c1
left join Orders o1
on c1.id = o1.customerId 
where o1.CustomerId is  null; 