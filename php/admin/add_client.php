<?php
    function client_exist($telephone, $email, $path) {
        $content = fopen($path, "r");
        while ($tab = fgetcsv($content, 1024, ";")) {
            $cmp1 = $tab[2];
            $cmp2 = $telephone;
            if (strcmp($cmp1, $cmp2) == 0)
                return (FALSE);
            $cmp1 = $tab[3];
            $cmp2 = $email;
            if (strcmp($cmp1, $cmp2) == 0)
                return (FALSE);
        }
        @fclose($content);
        return (TRUE);
    }

    function add_client($name, $adresse, $telephone, $email, $comment) {
        $path = "../private/client.csv";
        if ((client_exist($telephone, $email, $path) == FALSE)){
            echo "Le client existe deja !\n";
            return (FALSE);
        }
        $ret = TRUE;
        $new_client = array($name, $adresse, $telephone, $email, $comment);
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

    function add_client_front($name, $adresse, $telephone, $email, $comment) {
        if (!preg_match("/^((\+\d{1,3}(-| )?\(?\d\)?(-| )?\d{1,5})|(\(?\d{2,6}\)?))(-| )?(\d{3,4})(-| )?(\d{4})(( x| ext)\d{1,5}){0,1}$/", $telephone)) {
            return (FALSE);
        }
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            return (FALSE);
        }
        $ret = TRUE;
        $new_client = array($name, $adresse, $telephone, $email, $comment);
        $path = "./private/client.csv";
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
?>