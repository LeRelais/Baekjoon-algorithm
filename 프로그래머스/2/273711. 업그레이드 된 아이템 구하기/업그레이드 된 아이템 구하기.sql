-- 코드를 작성해주세요
select i.item_id, i.item_name, i.rarity
from item_info i join (select distinct t.parent_item_id, t.item_id, i.rarity
                        from item_tree t join item_info i on t.parent_item_id = i.item_id
                        where i.rarity = 'RARE') b
on i.item_id = b.item_id
order by i.item_id desc