<?php
session_start();
include_once("basket_function.php");
$error = false;

$action = (isset($_POST['action'])? $_POST['action']:  (isset($_GET['action'])? $_GET['action']:null )) ;
if($action !== null)
{
	if(!in_array($action,array('add', 'delete', 'more', 'less')))
	$error=true;

   $i = (isset($_GET['i'])) ? htmlspecialchars($_GET['i']) : null ;
   $name = (isset($_GET['name'])) ? htmlspecialchars($_GET['name']):null ;
   $price = (isset($_GET['price'])) ? htmlspecialchars($_GET['price']):null ;
   $qty = (isset($_GET['qty'])) ? htmlspecialchars($_GET['qty']):null ;
   $price = floatval($price);
}

if (!$error){
	switch($action){
		Case "add":
			addArticle($i, $name, $qty, $price);
			break;

		Case "delete":
			deleteArticle($i);
			break;
	
		Case "more":
			addQuantity($i);
			break;
	
		Case "less":
			removeQuantity($i);
			break;
	
	  Default:
		 break;
   }
}
?>
<!-- modele: https://goo.gl/images/GfxEwL -->
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
<form method="post" action="buy.php">
<?php
if (isset($_SESSION['login']) && !empty($_SESSION['login']) && totalAmount()>0)
	echo "<input type='submit' name='submit' value='Commander'/>";
?>
</form>
<?php include "shop.php"; ?>
</div>
</body>
</html>