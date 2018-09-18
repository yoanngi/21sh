<link rel="stylesheet" type="text/css" href="rush00.css">
<?php
if (!isset($_SESSION['login']))
    header('Location: ./admin/access_denied.php');

?>
<div class="body_admin">
  <div class="center">
    <div class="gallery">
      <a target="" href="clients.php">
        <img src="../img/client.png" alt="clients" width="300" height="200">
      </a>
      <div class="desc">Clients</div>
    </div>
    <div class="gallery">
      <a target="" href="articles.php">
        <img src="../img/article.png" alt="articles" width="300" height="200">
      </a>
      <div class="desc">Articles</div>
    </div>
    <div class="gallery">
      <a target="" href="commandes.php">
        <img src="../img/commandes.png" alt="commandes" width="300" height="200">
      </a>
      <div class="desc">Commandes</div>
    </div>
    <?php
      if (isset($_SESSION['login'])) {
        if ($_SESSION['login'] == "admin") {
          echo '
            <div class="gallery">
            <a target="" href="add_editor.php">
            <img src="../img/editor.png" alt="editor" width="300" height="200">
            </a>
            <div class="desc">Add an Editor</div>
            </div>
          ';
        }
      }
    ?>
    <div class="gallery">
      <a target="" href="logout.php">
        <img src="../img/editor.png" alt="editor" width="300" height="200">
      </a>
      <div class="desc">LOGOUT</div>
    </div>
    <div class="gallery">
      <a target="" href="edit_password.php">
        <img src="../img/editor.png" alt="editor" width="300" height="200">
      </a>
    <div class="desc">change passwd</div>
    <div>  
    </div>
</div>
</div>
