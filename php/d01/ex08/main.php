#!/usr/bin/php
<?php 
    include('ft_is_sort.php');

    $tab = array("pas", "trier", "DU", "tous", "1");
    $tab[] = "et encore";

    $tab2 = array("1", "2", "3", "4");

    if (ft_is_sort($tab))
        echo "trier\n";
    else
        echo "non trier\n";

    if (ft_is_sort($tab2))
        echo "trier\n";
    else
        echo "non trier\n";
?>