#!/usr/bin/php


// PAS OK
<?php
	echo "Entrez un nombre: ";
	$line = fgets(STDIN);
	if (is_int($line) == true) {
		echo $line . " est un nombre";
	}
	else {
		echo $line . " n'est pas un nombre";
	}
?>