<?php
echo "<br>";
$path = "./private/articles.csv";
echo "<b>Boutique</b>";
if (file_exists($path) == FALSE)
	echo "<p> La boutique est vide </p>";
else {
    @$content = fopen($path, "r");
    $i = 0;
    if (isset($content) && $content != FALSE) {
		echo "<table>";
        while ($tab = fgetcsv($content, 1024, ";")) {
            if ($i == 0) {
        	    echo "<tr>";
                echo "<td width=30%><strong>Designation</strong></td>";
                echo "<td width=10%><strong>Prix</strong></td>";
                echo "<td with=20%><strong>Image</strong></td>";
                echo "<td width=10%><strong>Ajouter</strong></td>";
                echo "</tr>";
            }
            if (count($tab) > 1) {
                if (isset($tab[3]) && !empty($tab[3]))
                    $categ[] = $tab[3];
                if (isset($tab[4]) && !empty($tab[4]))
                    $categ[] = $tab[4];
            }
            if (isset($_GET['filter']))
                $_GET['filter'] = htmlspecialchars($_GET['filter']); 
            if (count($tab) > 1 && (!isset($_GET['filter']) || ($_GET['filter'] == $tab[3]) || $_GET['filter'] == $tab[4])) {
                echo "<tr>";
                if (strlen ($tab[0]) > 22)
                    $design = substr($tab[0], 0, 22)."...";
                else
                    $design = $tab[0];
                echo "<td>" .str_replace('"', "", $design). "</td>";
                if (strlen ($tab[1]) > 22)
                    $pri = substr($tab[1], 0, 22)."...";
                else
                    $pri = $tab[1];
                echo "<td>" .$pri. " &#8364</td>";
                $path_img = "./uploads/".$tab[2];
                echo "<td><img src='".$path_img."'width=90%></td>";
                echo "<td><a href='index.php?action=add&amp;i=".$i."&amp;name=".str_replace('"', "", $tab[0])."&amp;qty=1&amp;price=".$tab[1]."'><img src='./img/add-basket.png' width='50'></a></td>";
                echo "</tr>";
            }
            $i++;
        }
        echo "</table>";
        echo "<br><br><p> Filtrer par catégorie : </p>";
        $categ = array_unique($categ);
        echo "<a href='index.php'>Sans filtre</a><br>";
        foreach ($categ as $elem) {
            if (strlen ($elem) > 22)
                $fil = substr($elem, 0, 22)."...";
            else
                $fil = $elem;
            echo "<a href='index.php?filter=".$elem."'>".$fil."</a><br>";
        }
    }
    else
		echo "<p> La boutique est vide </p>";
}
?>  