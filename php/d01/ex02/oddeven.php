#!/usr/bin/php
<?php
	while (1)
	{
		echo "Entrez un nombre: ";
		$line = fgets(STDIN);
		$line = substr($line, 0, -1);
		if (TRUE == feof(STDIN)) {
			echo "\n";
			return ;
		}
		if (is_numeric($line)) {
			$line = (int)$line;
			if (($line % 2) == 0) {
				echo "Le chiffre " . $line . " est Pair";
			} else {
				echo "Le chiffre " . $line . " est Impair";
			}
			echo "\n";
		}
		else {
			echo "'" . $line . "' n'est pas un nombre";
			echo "\n";
		}
	}
?>