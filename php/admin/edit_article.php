<?php
   session_start();
    if (!isset($_SESSION['login']))
        header('Location: ./access_denied.php');
    if (isset($_GET['des'], $_GET['img'], $_GET['price'], $_GET['cat1'], $_GET['cat2'])) {
        if ($_GET['des'] == "" || $_GET['img'] == "" || $_GET['price'] == "" || $_GET['cat1'] == "")
            header('Location: ./articles.php');
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" type="text/css" href="../css/rush00.css">
	<title>modifie article</title>
</head>
<body class="body_admin">
	<!-- Header -->
	<div class="header_admin">
        <?php include "headeradmin.php"; ?>
	</div>
	<!-- Body -->
    <div class="back" title="Back">
        <a href="articles.php"><img class="imgclient" src="../img/back.png"></a>
        <h3>Back</h3>
    </div>
    <div class="actions_client">
        <h2>Modification Article</h2>
    </div>
	<div class="actions_client">
        <div class="menu_client" title="add client">
            <img class="imgclient" src="../img/add.png" title="add a customer" alt="add a customer">
                <div class="form_client">
<?php
        require('add_article.php');
        require('valid_enter.php');
        print_form();

        function mod_article() {
            var_dump($_POST['img']);
            $_POST['designation'] = htmlspecialchars($_POST['designation']);
            $_POST['prix'] = htmlspecialchars($_POST['prix']);
            $_POST['categorie1'] = htmlspecialchars($_POST['categorie1']);
            $_POST['categorie2'] = htmlspecialchars($_POST['categorie2']);
            if (isset($_POST['designation'], $_POST['prix'], $_POST['categorie1']))
            {
                if ($_POST['designation'] != "" && $_POST['prix'] != "" && $_POST['categorie1'] != "")
                {
                    $desErr = "";
                    $prixErr = "";
                    $cat1Err = "";
                    $cat2Err = "";
                    $_POST['designation'] = trim($_POST['designation']);
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
                    if ($desErr != "" || $prixErr != "" || $cat1Err != "" || $cat2Err != "") {
                        return (FALSE);
                    }
                    if (modi_article($_POST['designation'], $_POST['prix'], $_POST['image'], $_POST['categorie1'], $_POST['categorie2'], $_POST['id']) == TRUE)
                        return (TRUE);
                } else {
                    return (FALSE);
                }
            }
            return (FALSE);
        }

        function print_form() {
            echo '
                <form method="POST" action="./edit_article.php" name="modarticles">
                <label for="fname">Designation</label>';
            if (isset($_GET['des']))
                echo "<input type=\"text\" name=\"designation\" value=\"" . $_GET['des'] . "\">";
            else
                echo "<input type=\"text\" name=\"designation\" value=\"\">";
            echo '<label for="fname">Numero id</label>';
            if (isset($_GET['id']))
                echo "<input type=\"text\" disabled=\"disabled\" name=\"id\" value=\"" . $_GET['id'] . "\">";
            else
                echo "<input type=\"text\" disabled=\"disabled\" name=\"id\" value=\"\">";
            echo    '<label for="fname">Name image</label>';
            if (isset($_GET['img']))
                echo "<input type=\"text\" disabled=\"disabled\" name=\"image\" value=\"" . $_GET['img'] . "\">";
            else
                echo "<input type=\"text\" disabled=\"disabled\" name=\"image\" value=\"\">";
            echo    '<label for="fname">Prix</label>' ;
            if (isset($_GET['price']))
                echo "<input type=\"text\" name=\"prix\" value=\"" . $_GET['price'] . "\">";
            else
                echo "<input type=\"text\" name=\"prix\" value=\"\">";
            echo    '<label for="fname">Categorie1</label>';
            if (isset($_GET['cat1']))
                echo "<input type=\"text\" name=\"categorie1\" value=\"" . $_GET['cat1'] . "\">";
            else
                echo    "<input type=\"text\" name=\"categorie1\" value=\"\">";
            echo    '<label for="fname">Categorie2</label>';
            if (isset($_GET['cat2']))
                echo    "<input type=\"text\" name=\"categorie2\" value=\"" . $_GET['cat2'] . "\">";
            else
                echo    "<input type=\"text\" name=\"categorie2\" value=\"\">";
            echo    '<input type="submit" name="modarticles" value="MODIFIE">
                </form>';
                
                if (isset($_POST['modarticles'])) {
                    if ($_POST['modarticles'] == "MODIFIE") {
                            if (mod_article() == TRUE) {
                                echo "<div class=\"msgsucc\">SUCCESS</div>";
                                header("refresh:3;url=./articles.php");
                            } else {
                                echo "<div class=\"msgerr\">ERROR</div>";
                                header("refresh:3;url=./articles.php");
                            }
                        }
                    }
                }
?>
	</div>
</body>
</html>