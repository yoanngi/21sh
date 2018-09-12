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

    function sort_one($argv) {
        $i = 0;
        while ($argv[$i]) {
            if (strstr($argv[$i], " ") != FALSE) {
                $tab = ft_split($argv[$i]);
                sort($tab);
                unset($argv[$i]);
                sort($argv);
                $argv = array_merge($argv, $tab);
                $i = -1;
            }
            $i++;
        }
        return ($argv);
    }

    unset($argv[0]);
    $argv = array_filter($argv);
    sort($argv);
    $argv = sort_one($argv);
    sort($argv);
    print_tab($argv, 0);
?>