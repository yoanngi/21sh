<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>bpajot-yoginet</title>
</head>
<body class="body_admin">
    <form method="GET" action="new_user.php" name="create.php">
    </form>
	<!-- Header -->
	<!-- Body -->
	<div class="actions_client">
        <div class="menu_client" title="add client">
            <img class="imgclient" src="./img/add.png" title="add a customer" alt="add a customer">
                <div class="form_client">
                <?php
                    require('./admin/add_client.php');
                    print_form();
                    
                    function print_form() {
                        echo '
                            <p> Inscription nouvel utilisateur </p>
                            <form method="POST" action="./new_user.php" name="add_clients">
                                <p>login</p>
                                <input type="text" name="login" value=""><br>
                                <p>mot de passe</p>
                                <input type="password" name="passwd" value=""><br>
                                <p>nom</p>
                                <input type="text" name="name" value=""><br>
                                <p>adresse</p>
                                <input type="text" name="adress" value=""><br>
                                <p>tel</p>
                                <input type="text" name="tel" value=""><br>
                                <p>email</p>
                                <input type="text" name="email" value=""><br>
                                <input type="submit" name="addclient" value="OK">
                            </form>';
                            include_once("user_function.php");
                            if (isset($_POST['addclient']))
                                $_POST['addclient'] = htmlspecialchars($_POST['addclient']);
                            if (isset($_POST['login']))
                                $_POST['login'] = htmlspecialchars($_POST['login']);
                            if (isset($_POST['passwd']))
                                $_POST['passwd'] = htmlspecialchars($_POST['passwd']);
                            if (isset($_POST['name']))
                                $_POST['name'] = htmlspecialchars($_POST['name']);
                            if (isset($_POST['adress']))
                                $_POST['adress'] = htmlspecialchars($_POST['adress']);
                            if (isset($_POST['tel']))
                                $_POST['tel'] = htmlspecialchars($_POST['tel']);
                            if (isset($_POST['email']))
                                $_POST['email'] = htmlspecialchars($_POST['email']);
                            if (isset($_POST['addclient'],$_POST['login'], $_POST['passwd']) && $_POST['addclient']=='OK') {
                                if (add_client_front($_POST['name'], $_POST['adress'], $_POST['tel'], $_POST['email'], "") == TRUE && 
                                create_user($_POST['login'], $_POST['passwd'])) {
                                    $_SESSION['login'] = $_POST['login'];
                                    echo "<div class=\"msgsuc\">Nouveau client ajouté !</div>";
                                    header("refresh:3;url=index.php");
                                    //header('Location: ./index.php');
                                } else {
                                    echo "<div class=\"msgerr\">Erreur</div>";
                                }
                            }
                        }
                    ?>
            </div>
            </div>
        </div>
    </div>