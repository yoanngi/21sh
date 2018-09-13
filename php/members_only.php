<?php

    function error() {
        header("HTTP/1.1 401 Unauthorized");
    }

    if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW'])) {
        $user = $_SERVER['PHP_AUTH_USER'];
        $pass = $_SERVER['PHP_AUTH_PW'];
        if ($user == "test" && $pass == "test") {
            echo "ok";
        } else {
            error();
        }
    } else {
        error();
    }
?>