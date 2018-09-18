<?php
    if (isset($_SESSION['login'])) {
        if ($_SESSION['login'] != "")
            header('Location: ./admin.php');  
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" type="text/css" href="../css/rush00.css"> 
    <title>Administration</title>
</head>
<body class="body_index_admin">
    <div class="access_reserved">
        <h2> Area Reserved </h2>
        <form method="POST" action="admin.php" name="administration">
                <label for="fname">Login</label>
                <input type="text" name="login" value="" placeholder="Your login..">
                <br />
                <label for="fname">Password</label>
                <input type="password" name="passwd" value="" placeholder="Your password..">
                <br />
                <input type="submit" name="submit" value="OK">
        </form>
    </div>
</body>
</html>