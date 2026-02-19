-- 코드를 작성해주세요
select ROUND(avg(len), 2) as AVERAGE_LENGTH
from (
    select case when length is null then 10 else length end as len 
    from fish_info
) as t1
