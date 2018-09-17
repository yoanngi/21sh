<?php

function data_existe($login) {
    if (file_exists("../private/") == TRUE) {
        $data = file_get_contents("../private/passwd");
        $val = unserialize($data);
        foreach ($val as $elem1) {
            if ($elem1[0] == $login) {
                return (TRUE);
            }
        }
        return (FALSE);
    } else {
        return (FALSE);
    }
    return (TRUE);
}

function add_content($file_exist, $login, $passwd) {
    if ($file_exist == 1) {
        $content = file_get_contents("../private/passwd");
        $tab = unserialize($content);
        $data = array($login, $passwd);
        $tab[] = $data;
        $data2 = serialize($tab);
    } else {
        $data = array($login, $passwd);
        $tab[] = $data;
        $data2 = serialize($tab);
    }
    if (file_put_contents("../private/passwd", $data2) == FALSE)
        return (FALSE);
    else
        return (TRUE);
}

function add_in_file($login, $passwd) {
    $file_exist = 0;
    if (file_exists("../private/passwd") == TRUE) {
        $file_exist = 1;
        add_content($file_exist, $login, $passwd);
        return (TRUE);
    } else {
        if (mkdir("../private/", 0700) == TRUE) {
            $ret = add_content($file_exist);
            return ($ret);
        } else {
            return (FALSE);
        }
    }
}
    function add_editor($name, $passwd) {
        $passwd = hash('whirlpool', $_POST['passwd']);
        if (data_existe($name) == FALSE) {
            $ret = add_in_file($name, $passwd);
            return ($ret);
        } else {
            return (FALSE);
        }
    }
?>