<?php
    session_start();
    if (!isset($_SESSION['login']))
       header('Location: ./access_denied.php');
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" type="text/css" href="../css/rush00.css">
	<title>Articles</title>
</head>
<body class="body_admin">
	<!-- Header -->
	<div class="header_admin">
        <?php include "headeradmin.php"; ?>
	</div>
	<!-- Body -->
    <div class="back" title="Back">
        <a href="admin.php"><img class="imgclient" src="../img/back.png"></a>
        <h3>Back</h3>
    </div>
    <div class="actions_client">
        <h2>Commandes client</h2>
    </div>
    <div class="views_commandes">
        <table>
            <?php

                function search_target() {
                    $dossier = opendir("../private/");
                    $target = array();
                    while (false !== ($fichier = readdir($dossier))) {
                        if ($fichier != "." && $fichier != ".." && strncmp($fichier, "commande", 7) == 0) {
                            array_push($target, $fichier);
                        }
                    }
                    closedir($dossier);
                    return ($target);
                }

                $target = search_target();
                if(isset($target)) {
                    $test = 0;
                    foreach ($target as $elem) {
                        $test++;
                        $targetcontent = "../private/" . $elem;
                        @$content = fopen($targetcontent, "r");
                        $i = 0;
                        if (isset($content) && $content != FALSE) {
                            while ($tab = fgetcsv($content, 1024, ";")) {
                                if ($i == 0) {
                                echo "<tr>";
                                echo "<td><strong>Reference Commande</strong></td>";
                                echo "<td><strong>Designation</strong></td>";
                                echo "<td><strong>Nombre</strong></td>";
                                echo "<td><strong>Prix</strong></td>";
                                echo "<td><strong>Action</strong></td>";
                                echo "</tr>";
                                }
                                if (count($tab) > 1) {
                                    echo "<tr>";
                                    echo "<td>" . $elem . "</td>";
                                    if (strlen($tab[0]) > 25)
                                        $tab[0] = substr($tab[0], 0, 25);
                                    echo "<td>" . $tab[0] . "</td>";
                                    if (strlen($tab[1]) > 25)
                                        $tab[1] = substr($tab[1], 0, 25);
                                    echo "<td>" . $tab[1] . "</td>";
                                    if (strlen($tab[2]) > 25)
                                        $tab[2] = substr($tab[2], 0, 25);
                                    echo "<td>" . $tab[2] . "</td>";
                                    echo "<td><a href=\"delete.php?secu=123456&page=articles&file=2&id=$i\"><img class=\"delete\" src=\"../img/delete.png\"></a></td>";
                                    echo "</tr>";
                                }
                                $i++;
                            }
                        } else {
                            echo "<div class=\"tabvide\">";
                            echo "<h3>No article registred</h3>";
                            echo "</div>";
                        }
                    }
                    if ($test == 0) {
                        echo "<div class=\"tabvide\">";
                        echo "<h3>No article registred</h3>";
                        echo "</div>";
                    }
                }
            ?>
        </table>
	</div>
</body>
</html>