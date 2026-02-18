-- 코드를 작성해주세요
# SELECT SUM(PRICE) AS TOTAL_PRICE FROM ITEM_INFO WHERE RARITY = "LEGEND"

select sum(price) as total_price from item_info where rarity = "LEGEND"