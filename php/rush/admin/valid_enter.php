<?php
    function    check_name($name) {
        $nameErr = "";
        if (!preg_match("/^[a-zA-Z]*$/",$name)) {
            $nameErr = "Only letters allowed"; 
        }
          return ($nameErr);
    }

    function check_des($name) {
        $desErr = "";
        return ($desErr);
    }

    function    check_adress($adress) {
        $nameErr = "";
        if (!preg_match("/^[a-zA-Z0-9 ]*$/",$adress)) {
            $nameErr = "Only letters, numbers and white space allowed"; 
        }
          return ($nameErr);
    }

    function    check_email ($email) {
        $nameErr = "";
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $nameErr = "Invalid email format"; 
        }
        return ($nameErr);
    }

    function    check_tel($tel) {
        $nameErr = "";
        if (!preg_match("/^((\+\d{1,3}(-| )?\(?\d\)?(-| )?\d{1,5})|(\(?\d{2,6}\)?))(-| )?(\d{3,4})(-| )?(\d{4})(( x| ext)\d{1,5}){0,1}$/", $tel)) {
            $nameErr = "Invalid telephone format"; 
        }
        return ($nameErr);
    }

    function    check_prix($prix) {
        $nameErr = "";
        if (!preg_match("/^[0-9,]*$/", $prix)) {
            $nameErr = "Invalid price format"; 
        }
        if ($prix > 10000000)
            $nameErr = "Price to long !"; 
        return ($nameErr);
    }
?>