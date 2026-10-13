# Write your MySQL query statement below

select distinct num as ConsecutiveNums
from
(
    select 
        num,
        lag(num,1) over(order by id) as pre1,
        lag(num,2) over(order by id) as pre2
    from Logs
) t
where num = pre1 and num = pre2;