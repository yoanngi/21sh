<?php

    ini_set("display_errors",0);error_reporting(0);
    function ft_check_valid($prix) {
        return (TRUE);
    }

    function add_article($designation, $prix, $image, $categorie1, $categorie2) {
        if (ft_check_valid($prix) == FALSE){
            return (FALSE);
        }
        $ret = TRUE;
        $new_client = array($designation, $prix, $image, $categorie1, $categorie2);
        $path = "../private/articles.csv";
        $delimiteur = ";";
        $fichier_csv = fopen($path, "a");
        fprintf($fichier_csv, chr(0xEF).chr(0xBB).chr(0xBF));
        if (fputcsv($fichier_csv, $new_client, $delimiteur) == FALSE)
            $ret = FALSE;
        fclose($fichier_csv);
        if ($ret == FALSE)
            return (FALSE);
        return (TRUE);
    }

    function modi_article($designation, $prix, $image, $categorie1, $categorie2, $id) {
        $new_client = array($designation, $prix, $image, $categorie1, $categorie2);
        $path = "../private/articles.csv";
        $delimiteur = ";";
        $fichier_csv = fopen($path, "r");
        $tab = array();
        fprintf($fichier_csv, chr(0xEF).chr(0xBB).chr(0xBF));
        $i = 0;
        while ($content = fgetcsv($fichier_csv, 1024, ";")) {
            if ($i != $id) {
                array_push($tab, $content);
            }
            $i++;
        }
        fclose($fichier_csv);
        $fichier_csv = fopen($path, "w");
        foreach ($tab as $elem) {
            fputcsv($fichier_csv, $elem, $delimiteur);
        }
        fputcsv($fichier_csv, $new_client, $delimiteur);
        fclose($fichier_csv);
        return (TRUE);
    }
?>