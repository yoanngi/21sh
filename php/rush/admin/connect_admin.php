<?php
    
    function admin_ok($login, $pass) {
        if (file_exists("../private/") == TRUE) {
            $data = file_get_contents("../private/passwd");
            $val = unserialize($data);
            foreach ($val as $elem) {
                print_r($val);
                if ($elem[0] == $login) {
                    $hash = hash('whirlpool', $pass);
                    if ($elem[1] == $hash) {
                        return (TRUE);
                    } else {
                        return (FALSE);
                    }
                }
            }
        }
        return (FALSE);
    }

    function ft_test_vide($login, $pass) {
        if ($login == "")
            return (TRUE);
        if ($pass == "")
            return (TRUE);
        return (FALSE);
    }

    function connect_admin($login, $pass) {
        if (isset($_SESSION['login'])) {
            return (TRUE);
        }
        if (isset($_POST['submit'])) {
            if ($_POST['submit'] == "OK") {
                $login = htmlspecialchars($_POST['login']);
                $pass = htmlspecialchars($_POST['passwd']);
            }
        }
        if (ft_test_vide($login, $pass) == TRUE) {
            return (FALSE);
        }
        if (admin_ok($login, $pass) == TRUE) {
            $_SESSION['login'] = $login;
            return (TRUE);
        }
        return (FALSE);
    }
?>