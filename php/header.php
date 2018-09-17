<link rel="stylesheet" type="text/css" href="./css/rush00.css">
<div class="admin_connect">
<?php
if (isset($_SESSION['login']) && !empty($_SESSION['login'])) 
    echo "Hello ".$_SESSION['login']."<br>";
else
    echo "Hello inconnu(e) !!!<br>";
?>
</div>
<div>
<?php
if (isset($_SESSION['login']) && !empty($_SESSION['login']))
        echo "<a href='./logout.php'>Déconnexion</a>";
else
{
		echo "<a href='./connect_user.php'>Connexion</a><br>";
        echo "<a href='./new_user.php'>S'inscrire</a>";
}
?>
</div>