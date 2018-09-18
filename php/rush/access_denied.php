<?php
    header("HTTP/1.1 401 Unauthorized ");
    echo "<html><body>Accès refusé</body></html>";
    header("refresh:3;url=index.php");
?>