<link rel="stylesheet" type="text/css" href="../css/rush00.css">
<?php
if (!isset($_SESSION['login']))
    header('Location: ./access_denied.php');
?>
<div class="admin_connect">
			<?php echo "<p>Hello " . $_SESSION['login'] . "</p>\n" ?>
		</div>
		<div class="admin_info">
			<?php echo "<p>" . date("H:i") . "</p>" ?>
			<?php echo "<p>" . date("Y-m-d") . "</p><br/>"?>
		</div>
</div>