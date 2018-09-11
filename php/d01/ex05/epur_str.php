#!/usr/bin/php
<?php
    $i = 0;
    if ($argc != 2) {
        return ;
    } else {
        $tab = explode(" ", $argv[1]);
        $tab = array_filter($tab);
        foreach ($tab as $elem) {
            if ($i == 0 && $elem != " ") {
                echo $elem;
                $i++;
            } else if ($i != 0 && $elem != " ")
                echo " " . $elem;
        }
        echo "\n";
}
?>