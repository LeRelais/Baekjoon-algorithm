-- 코드를 입력하세요
SELECT category, price as max_price, product_name
from food_product
where price in (
    select max(price)
    from food_product
    group by category
) and category in ('식용유', '과자', '국', '김치')
order by max_price desc