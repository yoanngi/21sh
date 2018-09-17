<?php
    function user_ok($login, $pass) {
		if (isset($login, $pass) && !empty($login) && !empty($pass)){
            $path = "./private/user_passwd";
        	if (file_exists("$path") == TRUE) {
        	    $data = file_get_contents($path);
        	    $val = unserialize($data);
        	    foreach ($val as $elem) {
        	        if ($elem['login'] == $login) {
        	            $hash = hash('whirlpool', $pass);
        	            if ($elem['passwd'] == $hash)
        	                return (TRUE);
        	            else
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

    function connect_user($login, $pass) {
        if (ft_test_vide($login, $pass) == TRUE)
            return (FALSE);
        if (user_ok($login, $pass) == TRUE) 
            return (TRUE);
        return (FALSE);
    }

    function create_user($login, $pass) {
        if (isset($login, $pass) && !empty($login) && !empty($pass))
        {
            $path = "./private/user_passwd";
			if (file_exists($path) == TRUE){
                $data = file_get_contents($path);
				$tab = unserialize($data);
			}
            else {
				$tab = NULL;
			}
            $user["login"] = $login;
            $user["passwd"] = hash("whirlpool", $pass);
            $doublon = FALSE;
            if (isset($tab))
            {
                foreach ($tab as $elem)
                {
                    if ($user["login"] == $elem["login"])
                        $doublon = TRUE;
                }
            }
            if ($doublon)
                return (FALSE);
            else
            {
                $tab[] = $user;
                file_put_contents($path, serialize($tab));
                return (TRUE);;
            }
        }
        else
            return (FALSE);
    }
?>