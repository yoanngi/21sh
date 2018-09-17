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
	<title>Clients</title>
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
                    require('add_client.php');
                    require('valid_enter.php');
                    print_form();
                    function add_new_user() {
                        $_POST['name'] = htmlspecialchars($_POST['name']);
                        $_POST['telephone'] = htmlspecialchars($_POST['telephone']);
                        $_POST['commentaire'] = htmlspecialchars($_POST['commentaire']);
                        $_POST['adresse'] = htmlspecialchars($_POST['adresse']);
                        $_POST['email'] = htmlspecialchars($_POST['email']);
                        if (isset($_POST['name'], $_POST['adresse'], $_POST['telephone'], $_POST['email']))
                        {
                            if ($_POST['name'] != "" && $_POST['adresse'] != "" && $_POST['telephone'] != "" && $_POST['email'] != "")
                            {
                                $nameErr = "";
                                $addErr = "";
                                $emailErr = "";
                                $telErr = "";
                                $nameErr = check_name($_POST['name']);
                                $addErr = check_adress($_POST['adresse']);
                                $emailErr = check_email($_POST['email']);
                                $telErr = check_tel($_POST['telephone']);
                                if ($nameErr != "")
                                    echo "<p>name: " . $nameErr . "</p>";
                                if ($addErr != "")
                                    echo "<p>Adresse: " . $addErr . "</p>";
                                if ($emailErr != "")
                                    echo "<p>Email: " . $emailErr . "</p>";
                                if ($telErr != "")
                                    echo "<p>Tel: " . $telErr . "</p>";
                                if ($nameErr != "" || $addErr != "" || $emailErr != "" || $telErr != "")
                                    return (FALSE);
                                if (add_client($_POST['name'], $_POST['adresse'], $_POST['telephone'], $_POST['email'], $_POST['commentaire']) == TRUE)
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
                            <form method="POST" action="./clients.php" name="add_clients">
                                <label for="fname">name</label>
                                <input type="text" name="name" value="">
                                <label for="fname">adresse</label>
                                <input type="text" name="adresse" value="">
                                <label for="fname">telephone</label>
                                <input type="text" name="telephone" value="">
                                <label for="fname">email</label>
                                <input type="text" name="email" value="">
                                <label for="fname">commentaire</label>
                                <input type="text" name="commentaire" value="">
                                <input type="submit" name="addclient" value="OK">
                            </form>';
                            if (isset($_POST['addclient'])) {
                                if ($_POST['addclient'] == "OK") {
                                    if (add_new_user() == TRUE) {
                                        echo "<div class=\"msgsuc\">new client add !</div>";
                                    } else {
                                        echo "<div class=\"msgerr\">ERROR</div>";
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
                @$content = fopen("../private/client.csv", "r");
                $i = 0;
                if (isset($content) && $content != FALSE) {
                    while ($tab = fgetcsv($content, 1024, ";")) {
                        if ($i == 0) {
                        echo "<tr>";
                        echo "<td><strong>Id</strong></td>";
                        echo "<td><strong>Name</strong></td>";
                        echo "<td><strong>Adresse</strong></td>";
                        echo "<td><strong>Tel</strong></td>";
                        echo "<td><strong>Email</strong></td>";
                        echo "<td><strong>Comment</strong></td>";
                        echo "<td><strong>Action</strong></td>";
                        echo "</tr>";
                        }
                        if (count($tab) > 1) {
                            echo "<tr>";
                            echo "<td>" . $i . "</td>";
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
                            echo "<td><a href=\"delete.php?secu=123456&page=client&file=1&id=$i\"><img class=\"delete\" src=\"../img/delete.png\"></a></td>";
                            echo "</tr>";
                        }
                        $i++;
                    }
                }
                else
                {
                    echo "<div class=\"tabvide\">";
                    echo "<h3>No client registred</h3>";
                    echo "</div>";
                }
            ?>
        </table>
	</div>
</body>
</html>