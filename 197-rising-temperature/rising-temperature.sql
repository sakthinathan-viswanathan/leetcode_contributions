
select 
    t.id
from Weather y
left join Weather  t
on date_add(y.recordDate,interval 1 day) = t.recordDate
where y.temperature < t.temperature;