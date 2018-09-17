<?php
echo '<?xml version="1.0" encoding="utf-8"?>';?>
<table>
	<tr>
		<td colspan="6">Votre panier</td>
	</tr>
	<tr>
		<td width=60%>Article</td>
		<td width=5%>Quantité</td>
		<td width=15%>Prix Unitaire</td>
		<td width=5%></td>
		<td width=5%></td>
		<td width=5%></td>
	</tr>
<?php
if (createBasket())
{
	$nbArticles=count($_SESSION['basket']['name']);
	if ($nbArticles <= 0)
		echo "<tr><td colspan='6'><b>Votre panier est vide</b></td></tr>";
	else
	{
		for ($i=0 ;$i < $nbArticles ; $i++)
		{
			echo "<tr>";
               if (strlen ($_SESSION['basket']['name'][$i]) > 22)
                   $nam = substr($_SESSION['basket']['name'][$i], 0, 22)."...";
               else
                   $nam = $_SESSION['basket']['name'][$i];
			echo "<td>".str_replace('"', "", $nam)."</td>";
			echo "<td>".$_SESSION['basket']['qty'][$i]."</td>";
			echo "<td>".$_SESSION['basket']['price'][$i]."€</td>";
			echo "<td><a href=\"".htmlspecialchars("index.php?action=more&i=".rawurlencode($_SESSION['basket']['i'][$i])
			)."\"><img width=30 src='./img/plus.png'</a></td>";
			echo "<td><a href=\"".htmlspecialchars("index.php?action=less&i=".rawurlencode($_SESSION['basket']['i'][$i])
			)."\"><img width=30 src='./img/less.png'></a></td>";
			echo "<td><a href=\"".htmlspecialchars("index.php?action=delete&i=".rawurlencode($_SESSION['basket']['i'][$i])
			)."\"><img width=30 src='./img/remove.png'></a></td>";
			echo "</tr>";
		}
		echo "<tr><td colspan=\"2\">Total</td>";
		echo "<td>";
		echo totalAmount()."€";
		echo "</td></tr>";
	}
}
?>
</table>