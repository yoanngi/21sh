<?php
    function ft_is_sort($tab) {
        $other = array($tab);
        sort($other);
        $i = 0;
        while($tab[$i]) {
            if ($tab[$i] != $oher[$i])
                return (FALSE);
        }
        return (TRUE);
    }
?>