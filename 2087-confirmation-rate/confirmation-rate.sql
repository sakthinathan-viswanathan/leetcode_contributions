# Write your MySQL query statement below

select 
    s.user_id,
    ROUND(
        IFNULL(AVG(t.action = 'confirmed'), 0),
        2
    ) AS confirmation_rate 
from Signups s
left join Confirmations t
on s.user_id = t.user_id
group by s.user_id;