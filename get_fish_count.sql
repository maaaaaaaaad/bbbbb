SELECT count(*) AS FISH_COUNT FROM fish_info as f WHERE
    EXISTS(SELECT *FROM fish_name_info as n WHERE(f.fish_type = n.fish_type)
               AND(n.fish_name IN('BASS', 'SNAPPER')));