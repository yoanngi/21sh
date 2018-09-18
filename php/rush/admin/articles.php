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
        <div class="menu_client" title="add client">
            <img class="imgclient" src="../img/add.png" title="add a customer" alt="add a customer">
                <div class="form_client">
                <?php
                    require('add_article.php');
                    require('valid_enter.php');
                    print_form();
                    function add_new_article() {
                        $_POST['designation'] = htmlspecialchars($_POST['designation']);
                        $_POST['prix'] = htmlspecialchars($_POST['prix']);
                        $_POST['categorie1'] = htmlspecialchars($_POST['categorie1']);
                        $_POST['categorie2'] = htmlspecialchars($_POST['categorie2']);
                        if (isset($_POST['designation'], $_POST['prix'], $_POST['image'], $_POST['categorie1']))
                        {
                            if ($_POST['designation'] != "" && $_POST['prix'] != "" && $_POST['image'] != "" && $_POST['categorie1'] != "")
                            {
                                $desErr = "";
                                $prixErr = "";
                                $cat1Err = "";
                                $cat2Err = "";
                                $desErr = check_des($_POST['designation']);
                                $prixErr = check_prix($_POST['prix']);
                                $cat1Err = check_name($_POST['categorie1']);
                                $cat2Err = check_name($_POST['categorie2']);
                                if ($desErr != "")
                                    echo "<p>Designation: " . $desErr . "</p>";
                                if ($prixErr != "")
                                    echo "<p>Prix: " . $prixErr . "</p>";
                                if ($cat1Err != "")
                                    echo "<p>Categorie1: " . $cat1Err . "</p>";
                                if ($cat2Err != "")
                                    echo "<p>Categorie2: " . $cat2Err . "</p>";
                                if ($desErr != "" || $prixErr != "" || $cat1Err != "" || $cat2Err != "")
                                    return (FALSE);
                                if (add_article($_POST['designation'], $_POST['prix'], $_POST['image'], $_POST['categorie1'], $_POST['categorie2']) == TRUE)
                                    return (TRUE);
                                else
                                    return (FALSE);
                            } else {
                                return (FALSE);
                            }
                        }
                        else
                        {
                            return (FALSE);
                        }
                        return (FALSE);
                    }

                    function print_form() {
                        echo '
                            <form method="POST" action="./articles.php" name="addarticles" enctype="multipart/form-data">
                                <label for="fname">Designation</label>
                                <input type="text" name="designation" value="">
                                <label for="fname">Prix</label>
                                <input type="text" name="prix" value="">
                                <label for="fname">Categorie1</label>
                                <input type="text" name="categorie1" value="">
                                <label for="fname">Categorie2</label>
                                <input type="text" name="categorie2" value="">
                                <label for="fname">Image</label>
                                <input type="file" name="image" value="">
                                <input type="submit" name="addarticles" value="OK">
                            </form>';
                            
                            if (isset($_POST['addarticles'])) {
                                if ($_POST['addarticles'] == "OK") {
                                    $target_dir = "../uploads/";
                                    $target_file = $target_dir . basename($_FILES["image"]["name"]);
                                    $check = @getimagesize($_FILES["image"]["tmp_name"]);
                                    if($check !== false) {
                                        $uploadOk = 1;
                                    } else {
                                        echo "<div class=\"msgerr\">File is not an image</p>";
                                        $uploadOk = 0;
                                    }
                                    if ($uploadOk == 1) {
                                        if ($_FILES["image"]["size"] > 500000) {
                                            echo "<div class=\"msgerr\">Sorry, your file is too large.</p>";
                                            $uploadOk = 0;
                                        }
                                    }
                                    if (move_uploaded_file($_FILES["image"]["tmp_name"], $target_file) == FALSE)
                                        $uploadOk = 0;
                                    else
                                    {
                                        $imagedata = file_get_contents($target_file);
                                        $base64 = base64_encode($imagedata);
                                        $_POST['image'] = $_FILES['image']['name'];
                                    }
                                    if ($uploadOk == 1) {
                                        if (add_new_article() == TRUE) {
                                                echo "<div class=\"msgsuc\">New article Added !</div>";
                                        } else {
                                            echo "<div class=\"msgerr\">ERROR</div>";
                                        }
                                    } else {
                                        $name_file = $_FILES['image']['name'];
                                        $target = $target_dir . $name_file;
                                        if (@file_exists($target)) {
                                            @unlink($target);
                                        }
                                    }
                                }
                            }
                    }
            ?>
            </div>
            </div>
        </div>
    </div>
    <div class="views_client">
        <table>
            <?php
                @$content = fopen("../private/articles.csv", "r");
                $id = 0;
                if (isset($content) && $content != FALSE) {
                    while ($tab = fgetcsv($content, 1024, ";")) {
                        if ($id == 0) {
                        echo "<tr>";
                        echo "<td><strong>Id</strong></td>";
                        echo "<td><strong>Designation</strong></td>";
                        echo "<td><strong>Prix</strong></td>";
                        echo "<td><strong>Image</strong></td>";
                        echo "<td><strong>Categorie1</strong></td>";
                        echo "<td><strong>Categorie2</strong></td>";
                        echo "<td><strong>Action</strong></td>";
                        echo "</tr>";
                        }
                        if (count($tab) > 1) {
                            echo "<tr>";
                            echo "<td>" . $id . "</td>";
                            if (strlen($tab[0]) > 25)
                                $tab[0] = substr($tab[0], 0, 25);
                            echo "<td>" . $tab[0] . "</td>";
                            if (strlen($tab[1]) > 25)
                                $tab[1] = substr($tab[1], 0, 25);
                            echo "<td>" . $tab[1] . "</td>";
                            if (strlen($tab[2]) > 25)
                                $tab[2] = substr($tab[2], 0, 25);
                            echo "<td>" . $tab[2] . "</td>";
                            if (strlen($tab[3]) > 25)
                                $tab[3] = substr($tab[3], 0, 25);
                            echo "<td>" . $tab[3] . "</td>";
                            if (strlen($tab[4]) > 25)
                                $tab[4] = substr($tab[4], 0, 25);
                            echo "<td>" . $tab[4] . "</td>";
                            echo "<td><a href=\"delete.php?secu=123456&page=articles&file=2&id=$id\"><img class=\"delete\" src=\"../img/delete.png\"></a>";
                            if (isset($tab[4]) && $tab[4] != "")
                                echo "<a href=\"edit_article.php?id=$id&des=$tab[0]&price=$tab[1]&img=$tab[2]&cat1=$tab[3]&cat2=$tab[4]\"><img class=\"delete\" src=\"../img/edit.png\"></a></td>";
                            else
                                echo "<a href=\"edit_article.php?id=$id&des=$tab[0]&price=$tab[1]&img=$tab[2]&cat1=$tab[3]\"><img class=\"delete\" src=\"../img/edit.png\"></a></td>";
                            echo "</tr>";
                        }
                        $id++;
                    }
                }
                else
                {
                    echo "<div class=\"tabvide\">";
                    echo "<h3>No article registred</h3>";
                    echo "</div>";
                }
            ?>
        </table>
	</div>
</body>
</html>