<?php
function data_existe()
{
    if (file_exists("../private/") == true) {
        $content = file_get_contents("../private/passwd");
        $tab = unserialize($content);
        $oldhash = hash('whirlpool', $_POST['oldpwd']);
        $newhash = hash('whirlpool', $_POST['newpwd']);
        foreach ($tab as &$elem1) {
            if ($elem1[0] == $_POST['login']) {
                if ($elem1[1] == $oldhash) {
                    $elem1[1] = $newhash;
                } else {
                    echo "Oldpwd False !";
                    return (false);
                }
            }
            $final = serialize($tab);
            if (file_put_contents("../private/passwd", $final) == false)
                return (false);
            return (true);
        }
    }
    return (false);
}

if (!isset($_POST['name']) && !isset($_POST['newpwd']) && !isset($_POST['oldpwd']) && !isset($_POST['submit'])) {
    echo "1";
    header('Location: ./admin.php');
} else {
    if ($_POST['submit'] != "OK" || $_POST['login'] == "" || $_POST['newpwd'] == "" || $_POST['oldpwd'] == "") {
        echo "2";
            //    header('Location: ./admin.php');
    } else {
        if (data_existe() == false) {
            echo "Error ssss!";
                    //header('Location: ./admin.php');
        } else {
            echo "password changer !";
                    //sleep(10);
                    //header('Location: ./admin.php');
        }
    }
}
?>