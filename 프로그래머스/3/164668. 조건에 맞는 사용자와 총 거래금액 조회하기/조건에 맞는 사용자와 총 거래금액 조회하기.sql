select b.user_id, b.nickname, sum(a.price) as TOTAL_SALES
from used_goods_board a inner join used_goods_user b on a.writer_id = b.user_id
where a.status = 'DONE'
group by b.user_id
having TOTAL_SALES >= 700000
order by TOTAL_SALES asc