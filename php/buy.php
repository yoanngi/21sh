<?php
session_start();
include_once("basket_function.php");
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
<body class=body_admin>
	<!-- Header -->
<div class =header_admin>
	<?php include "header.php"; ?>
</div>
<!-- Body -->
<div class=header_user>
	<?php include "basket.php"; ?>
</div>
<div class=commande>
<?php
	$num_buy = uniqid();
	save_buy($num_buy);
	echo "Numero de commande : ".$num_buy." réalisé par <b>".$_SESSION['login']."</b> enregistrée dans la base de donnée<br><br>
	Merci pour votre commande";
    header("refresh:10;url=index.php");
?>
</div>
<div class=footer_admin>
	<?php include "footer.php"; ?>
</div>
</body>
</html>