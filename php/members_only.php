<?php

function error() {
        header("WWW-Authenticate: Basic realm=''Espace membres''");
        header("HTTP/1.1 401 Unauthorized");
        echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
    }

    function good() {
        echo "<html><body>\n";
        echo "Bonjour Zaz<br />\n";
        //echo "<img src='data:image/png;base64,";
        //$file = base64_encode(file_get_contents("../img/42.png"));
        //echo $file;
        echo "</body></html>\n";


    }

    if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW'])) {
        $user = $_SERVER['PHP_AUTH_USER'];
        $pass = $_SERVER['PHP_AUTH_PW'];
        if ($user == "zaz" && $pass == "jaimelespetitsponeys") {
            good();
        } else {
            error();
        }
    } else {
        error();
    }
?>
