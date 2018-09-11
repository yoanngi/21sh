#!/usr/bin/php
<?php
    $tab = explode(" ", $argv[1]);
    $tab = array_filter($tab);
    $i = 0;
    foreach ($tab as $elem) {
        if ($i != 0) {
            echo $elem . " ";
        }
        $i++;
    }
    echo $tab[0] . "\n";
?>