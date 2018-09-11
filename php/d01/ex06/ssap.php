#!/usr/bin/php
<?php

    function ft_split($arg) {
        if ($arg == null)
            return (null);
    	$tab = explode(" ", $arg);
    	$new = array_filter($tab);
    	sort($new);
    	return($new);
    }

    function print_tab($tab, $i) {
        while ($tab[$i]) {
            echo $tab[$i] . "\n";
            $i++;
        }
    }

    if (count($argv) == 1) {
        echo $argv[1] . "\n";
        return ;
    }

    $i = 1;
    while ($argv[$i])
    {
        if (strstr($argv[$i], " ") != FALSE) {
            $tab = ft_split($argv[$i]);
            $count = count($tab);
            sort($tab);
            unset($argv[$i]);
            sort($argv);
            $argv = array_merge($argv, $tab);
            $i = 0;
        }
        $i++;
    }
    sort($argv);
    print_tab($argv, 1);
?>