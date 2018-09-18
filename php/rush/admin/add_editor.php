<?php
    session_start();
    if (!isset($_SESSION['login']))
       header('Location: ./access_denied.php');
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" type="text/css" href="../css/rush00.css">
	<title>Editor</title>
</head>
<body class="body_admin">
	<!-- Header -->
	<div class="header_admin">
        <?php include "headeradmin.php"; ?>
	</div>
	<!-- Body -->
    <div class="back" title="Back">
        <a href="admin.php"><img class="imgclient" src="../img/back.png"></a>
        <h3>Back</h3>
    </div>
	<div class="actions_client">
        <div class="menu_client" title="add client">
            <img class="imgclient" src="../img/add.png" title="add a customer" alt="add a customer">
                <div class="form_client">
                <?php
                    require('editor.php');
                    require('valid_enter.php');
                    print_form();
                    function add_new_editor() {
                        $_POST['name'] = htmlspecialchars($_POST['name']);
                        $_POST['passwd'] = htmlspecialchars($_POST['passwd']);
                        if (isset($_POST['name'], $_POST['passwd']))
                        {
                            if ($_POST['name'] != "" && $_POST['passwd'] != "")
                            {
                                $nameErr = "";
                                $passErr = "";
                                $nameErr = check_name($_POST['name']);
                                $passErr = check_name($_POST['passwd']);
                                if ($nameErr != "")
                                    echo "<p>Name: " . $nameErr . "</p>";
                                if ($passErr != "")
                                    echo "<p>Password: " . $passErr . "</p>";
                                if ($nameErr != "" || $passErr != "")
                                    return (FALSE);
                                if (add_editor($_POST['name'], $_POST['passwd']) == TRUE)
                                    return (TRUE);
                                else
                                    return (FALSE);
                            } else {
                                return (FALSE);
                            }
                        }
                        else
                            return (FALSE);
                        return (FALSE);
                    }

                    function print_form() {
                        echo '
                            <form method="POST" action="./add_editor.php" name="add_editor">
                                <label for="fname">name</label>
                                <input type="text" name="name" value="">
                                <label for="fname">password</label>
                                <input type="password" name="passwd" value="">
                                <input type="submit" name="addeditor" value="OK">
                            </form>';
                            if (isset($_POST['addeditor'])) {
                                if ($_POST['addeditor'] == "OK") {
                                    if (add_new_editor() == TRUE) {
                                        echo "<div class=\"msgsuc\">new editor add !</div>";
                                    } else {
                                        echo "<div class=\"msgerr\">ERROR</div>";
                                    }
                                }
                            }
                    }
            ?>
            </div>
            </div>
        </div>
    </div>
    <div class="views_client">
        <table>
            <?php
                $i = 0;
                if (file_exists("../private/") == TRUE) {
                    $data = file_get_contents("../private/passwd");
                    $val = unserialize($data);
                    foreach ($val as $elem) {
                        if ($i == 0) {
                            echo "<tr>";
                            echo "<td><strong>Id</strong></td>";
                            echo "<td><strong>Name</strong></td>";
                            echo "<td><strong>Action</strong></td>";
                            echo "</tr>";
                        }
                        echo "<tr>";
                        echo "<td>" . $i . "</td>";
                        echo "<td>" . $elem[0] . "</td>";
                        if ($i != 0) {
                            echo "<td><a href=\"delete.php?secu=123456&page=add_editor&file=3&id=$i\"><img class=\"delete\" src=\"../img/delete.png\"></a></td>";
                        }
                        else
                            echo "<td>No action possible</td>";
                        echo "</tr>";
                        $i++;
                    }
                }
                else
                {
                    echo "<div class=\"tabvide\">";
                    echo "<h3>No Editor</h3>";
                    echo "</div>";
                }
            ?>
        </table>
	</div>
</body>
</html>