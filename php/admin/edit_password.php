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
    <title>Edit password</title>
</head>
<body class="body_index_admin">
    <div class="access_reserved">
        <h2>Edit Password</h2>
        <form method="POST" action="modifie_pass.php" name="modifiepass">
                <label for="fname">Login</label>
                <input type="text" name="login" value="<?php if (isset($_GET['login'])) { echo $_GET['login']; } ?>" placeholder="<?php if (isset($_GET['login'])) { echo $_GET['login']; } ?>">
                <br />
                <label for="fname">Old Password</label>
                <input type="password" name="oldpwd" value="" placeholder="Old password...">
                <br />
                <label for="fname">New Password</label>
                <input type="password" name="newpwd" value="" placeholder="new password...">
                <br />
                <input type="submit" name="submit" value="OK">
        </form>
    </div>
</body>
</html>