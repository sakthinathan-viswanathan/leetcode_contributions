# Write your MySQL query statement below

select 
    c.id
from Weather c
inner join Weather p
on c.recordDate = date_add(p.recordDate,interval 1 day)
where p.temperature < c.temperature;
