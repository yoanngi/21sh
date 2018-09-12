<?php
    function ft_is_sort($tab) {
        $other = $tab;
        sort($other);
        $i = 0;
        while($tab[$i]) {
            if (strcmp($tab[$i], $other[$i]) != 0) {
                return (FALSE);
            }
            $i++;
        }
        return (TRUE);
    }
?> 