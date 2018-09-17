<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta http-equiv="X-UA-Compatible" content="ie=edge">
	<link rel="stylesheet" type="text/css" href="../css/rush00.css">
	<title>Boutique en ligne yoginet bpajot</title>
</head>
<body>
    <p> Connexion utilisateur </p>
    <form method="post" action="connect_user.php">
        <p>Your login</p>
        <input type="text" name="login" value="">
        <br />
        <p>Your Pass</p>
        <input type="password" name="passwd" value="">
        <br />
        <input type="submit" name="submit" value="OK">
    </form>
</body>
</html>
<?php
    include_once("user_function.php");
    if (isset($_POST['login']))
        $_POST['login'] = htmlspecialchars($_POST['login']);
    if (isset($_POST['passwd']))
        $_POST['passwd'] = htmlspecialchars($_POST['passwd']);
    if (isset($_POST['login'], $_POST['passwd']) && !empty($_POST['login']) && !empty($_POST['passwd'])) {
	    if (connect_user($_POST['login'], $_POST['passwd'])) {
            $_SESSION['login'] = $_POST['login'];
        	header('Location: ./index.php');
	    }
	    else
            header('Location: ./access_denied.php');
    }
?>