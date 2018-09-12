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

    function cmp($a, $b) {
        $alpha = "abcdefghijklmnopqrstuvwxyz0123456789 !\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
        $i = 0;
        if (strlen($a) > strlen($b))
            $len = strlen($a);
        else
            $len = strlen($b);
        $a = strtolower($a);
        $b = strtolower($b);
        while ($i < $len && $a[$i] == $b[$i])
            $i++;
        if (stripos($alpha, $a[$i]) == stripos($alpha, $b[$i]))
            return 0;
        if (stripos($alpha, $a[$i]) > stripos($alpha, $b[$i]))
            return 1;
        else
            return -1;
    }

    unset($argv[0]);
    $argv = array_filter($argv);
    sort($argv);
    $argv = sort_one($argv);
    usort($argv, "cmp");
    print_tab($argv, 0);
?>
