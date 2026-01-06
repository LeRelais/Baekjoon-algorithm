-- 코드를 입력하세요
select MCDP_CD as `진료과코드`, count(pt_no) as `5월예약건수`
from appointment
where YEAR(APNT_YMD) = '2022' and MONTH(APNT_YMD) = '5'
group by MCDP_CD
order by count(pt_no) asc, MCDP_CD asc