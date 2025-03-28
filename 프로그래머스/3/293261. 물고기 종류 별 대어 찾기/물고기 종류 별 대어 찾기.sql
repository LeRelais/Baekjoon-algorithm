select c.id, d.fish_name, c.length
from fish_info c join fish_name_info d on c.fish_type = d.fish_type
where (c.fish_type, c.length ) in (select fish_type, max(length)
             from fish_info
             group by fish_type
            )