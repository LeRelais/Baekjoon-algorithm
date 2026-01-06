-- 코드를 작성해주세요
# SELECT COUNT(a.ID) AS FISH_COUNT
# FROM FISH_INFO a INNER JOIN FISH_NAME_INFO b ON a.FISH_TYPE = b.FISH_TYPE
# WHERE b.FISH_NAME = "BASS" OR b.FISH_NAME = "SNAPPER"

select count(a.id) as fish_count
from fish_info a inner join fish_name_info b on a.fish_type = b.fish_type
where b.fish_name = "SNAPPER" or b.fish_name = "BASS"