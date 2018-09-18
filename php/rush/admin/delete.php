<?php

    function ft_check_valid($secu) {
        if (strcmp($secu, "123456") == 0)
            return (TRUE);
        return (FALSE);
    }

    function delete_admin($id) {
        if (file_exists("../private/") == TRUE) {
            $data = file_get_contents("../private/passwd");
            $val = unserialize($data);
            array_splice($val, $id, $id);
            $val = array_filter($val);
            $final = serialize($val);
            if (file_put_contents("../private/passwd", $final) == FALSE)
                return (FALSE);
        }
    }

    function delete_id($secu, $file, $id) {
        if (ft_check_valid($secu) == FALSE){
            return (FALSE);
        }
        if ($file == 1)
            $file = "../private/client.csv";
        else if ($file == 2)
            $file = "../private/articles.csv";
        else if ($file == 3) {
            delete_admin($id);
            return (TRUE);
        }
        else
            return (FALSE);
        $fichier_csv = fopen($file, "r");
        $i = 0;
        $tab = array();
        if (isset($fichier_csv) && $fichier_csv != FALSE)
        {
            while ($content = fgetcsv($fichier_csv, 1024, ";"))
            {
                if ($i != $id)
                {
                    array_push($tab, $content);
                }
                $i++;
            }
            fclose($fichier_csv);
        }
        if ($id == 1 && $i == 1)
            return ;
        $fichier_csv = fopen($file, "w");
        $delimiteur = ";";
        fprintf($fichier_csv, chr(0xEF).chr(0xBB).chr(0xBF));
        foreach ($tab as $line)
        {
            fputcsv($fichier_csv, $line, $delimiteur);
        }
        fclose($fichier_csv);
    }

    if (isset($_GET['secu'], $_GET['file'], $_GET['id'])) {
        if ($_GET['secu'] != "" && $_GET['file'] != "" && $_GET['id'] != "") {
            delete_id($_GET['secu'], $_GET['file'], $_GET['id']);
        }
    }
    if (isset($_GET['page'])){
        if ($_GET['page'] != "") {
            $target = $_GET['page'];
            if ($target == "articles")
                header('Location: ./articles.php');
            if ($target == "client")
                header('Location: ./clients.php');
            if ($target == "commandes")
                header('Location: ./commandes.php');
            if ($target == "add_editor")
                header('Location: ./add_editor.php');
        }
    }else {
        header('Location: ../index.php');
    }
?>