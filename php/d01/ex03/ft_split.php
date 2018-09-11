<?php
function ft_split($arg)
{
    if ($arg == null)
        return (null);
	$tab = explode(" ", $arg);
	$new = array_filter($tab);
	sort($new);
	return($new);
}
?>