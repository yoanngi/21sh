<?php
	session_start();
	require "connect_admin.php";
	if (isset($_SESSION['login'])) {
        if ($_SESSION['login'] != "") {
			if (@connect_admin($_POST['login'], $_POST['passwd']) == FALSE) {
				header('Location: ./access_denied.php');
			}
		}
	}
	else if (connect_admin($_POST['login'], $_POST['passwd']) == FALSE) {
		header('Location: ./access_denied.php');
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
	<title>Area Reserved</title>
</head>
<body class="body_admin">
	<!-- Header -->
	<div class="header_admin">
		<?php include "headeradmin.php"; ?>
	</div>
	<!-- Body -->
	<div>
		<?php include "bodyadmin.php"; ?>
	</div>
</body>
</html>