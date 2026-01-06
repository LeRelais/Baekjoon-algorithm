-- 코드를 입력하세요
SELECT book_id, DATE_FORMAT(published_date, '%Y-%m-%d') as published_date
from book
where category = '인문' and year(published_date) = '2021'
order by published_date asc