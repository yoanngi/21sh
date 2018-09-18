<?php
    function createBasket(){
        if (!isset($_SESSION['basket'])){
           $_SESSION['basket']= array();
           $_SESSION['basket']['i'] = array();
           $_SESSION['basket']['name'] = array();
           $_SESSION['basket']['qty'] = array();
           $_SESSION['basket']['price'] = array();
        }
        return true;
    }

    function addArticle($i, $name,$qty,$price){

        if (createBasket()) {
           $posArticle = array_search($i,  $_SESSION['basket']['i']);
     
           if ($posArticle !== FALSE) {
              $_SESSION['basket']['qty'][$posArticle] += $qty;
           } else {
              array_push( $_SESSION['basket']['i'], $i);
              array_push( $_SESSION['basket']['name'], $name);
              array_push( $_SESSION['basket']['qty'], $qty);
              array_push( $_SESSION['basket']['price'], $price);
           }
        } else {
            echo "Un problème est survenu, veuillez contacter l'administrateur du site.";
        }
     }

    function deleteArticle($i){
        //Si le panier existe
        if (createBasket())
        {
           //Nous allons passer par un panier temporaire
           $tmp=array();
           $tmp['i'] = array();
           $tmp['name'] = array();
           $tmp['qty'] = array();
           $tmp['price'] = array();
     
           for($j = 0; $j < count($_SESSION['basket']['i']); $j++)
           {
              if ($_SESSION['basket']['i'][$j] !== $i)
              {
                 array_push( $tmp['i'],$_SESSION['basket']['i'][$j]);
                 array_push( $tmp['name'],$_SESSION['basket']['name'][$j]);
                 array_push( $tmp['qty'],$_SESSION['basket']['qty'][$j]);
                 array_push( $tmp['price'],$_SESSION['basket']['price'][$j]);
              }
     
           }
           //On remplace le panier en session par notre panier temporaire à jour
           $_SESSION['basket'] =  $tmp;
           //On efface notre panier temporaire
           unset($tmp);
        }
        else
        echo "Un problème est survenu veuillez contacter l'administrateur du site.";
    }
     
    function modifQuantity($i,$qty){
        //Si le panier éxiste
        if (createBasket()){
            //Si la quantité est positive on modifie sinon on supprime l'article
            if ($qty > 0){
                //Recharche du produit dans le panier
                $posArticle = array_search($i,  $_SESSION['basket']['i']);
                if ($posArticle !== false)
                    $_SESSION['basket']['qty'][$posArticle] = $qty ;
            }
        else
            deleteArticle($name);
        }
        else
            echo "Un problème est survenu veuillez contacter l'administrateur du site.";
    }

    function addQuantity($i){
        //Si le panier éxiste
        if (createBasket()){
            //Si la quantité est positive on modifie sinon on supprime l'article
            //Recharche du produit dans le panier
            $posArticle = array_search($i,  $_SESSION['basket']['i']);
            if ($posArticle !== false)
                $_SESSION['basket']['qty'][$posArticle]+=1;
        }
        else
            echo "Un problème est survenu veuillez contacter l'administrateur du site.";
    }

    function removeQuantity($i){
        //Si le panier éxiste
        if (createBasket()){
            //Si la quantité est positive on modifie sinon on supprime l'article
            //Recharche du produit dans le panier
            $posArticle = array_search($i,  $_SESSION['basket']['i']);
            if ($posArticle !== false){
                if ($_SESSION['basket']['qty'][$posArticle]> 1)
                    $_SESSION['basket']['qty'][$posArticle]--;
                else
                    deleteArticle($i);
            }
        }
        else
            echo "Un problème est survenu veuillez contacter l'administrateur du site.";
    }

    function totalAmount(){
       $total=0;
        for($i = 0; $i < count($_SESSION['basket']['name']); $i++)
        {
           $total += $_SESSION['basket']['qty'][$i] * $_SESSION['basket']['price'][$i];
        }
        return $total;
    }

    function compterArticles()
    {
       if (isset($_SESSION['panier']))
       return count($_SESSION['panier']['libelleProduit']);
       else
       return 0;
    }

    function countArticles()
    {
       if (isset($_SESSION['basket']))
        return count($_SESSION['basket']['name']);
       else
        return 0;
    }

    function deleteBasket(){
        unset($_SESSION['basket']);
    }
    
    function save_buy($num_buy){
        $path = "./private/commande/commande".$num_buy.".csv";
        $limit = ";";
        $ret = TRUE;
        $csv = fopen($path, "w");
        fprintf($csv, chr(0xEF).chr(0xBB).chr(0xBF));
        for($i = 0; $i < count($_SESSION['basket']['name']); $i++){
            $tmp[] = $_SESSION['basket']['name'][$i];
            $tmp[] = $_SESSION['basket']['qty'][$i];
            $tmp[] = $_SESSION['basket']['price'][$i];
            if (fputcsv($csv, $tmp, $limit) == FALSE)
               $ret = FALSE;
            unset($tmp);
        }
        unset($_SESSION['basket']);
        fclose($csv);
        if ($ret == FALSE)
            return (FALSE);
        return (TRUE);
    }
?>