<?php
if (!file_exists("private"))
    mkdir("private");
$path_com = "./private/commande/";
if (!file_exists($path_com))
    mkdir($path_com);
$account[0][0] = "admin";
$account[0][1] = "6a4e012bd9583858a5a6fa15f58bd86a25af266d3a4344f1ec2018b778f29ba83be86eb45e6dc204e11276f4a99eff4e2144fbe15e756c2c88e999649aae7d94";
file_put_contents("private/passwd", serialize($account));
header('Location: index.php');
?>