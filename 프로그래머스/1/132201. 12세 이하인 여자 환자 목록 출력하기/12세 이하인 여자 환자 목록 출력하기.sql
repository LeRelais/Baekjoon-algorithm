-- 코드를 입력하세요
SELECT pt_name, pt_no, gend_cd, age, case when tlno is NULL then 'NONE' else tlno end as tlno
from patient
where gend_cd = 'W' and age <= 12
order by age desc, pt_name asc