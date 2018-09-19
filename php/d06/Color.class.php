<?php
class Color {

    public $red = 0;
    public $green = 0;
    public $blue = 0;
    public $verbose = FALSE;

    static function doc()
    {
        return (file_get_contents('Color.doc.txt'));
    }

    function __construct( array $kwarg )
    {
        if (array_key_exists('rgb', $kwarg))
        {

        }
        else if ($kwarg['red'])
            $this->$red = $kwarg['red'];
        else if ($kwarg['green'])
            $this->$red = $kwarg['red'];
        else if ($kwarg['blue'])
            $this->$red = $kwarg['red'];
        if (self::$verbose === True)
			print('Color( red: '.sprintf("%3s",$this->red).', green: '.sprintf("%3s",$this->green).', blue: '.sprintf("%3s", $this->blue).' ) constructed.'.PHP_EOL);
    }

    function __destruct()
    {
        if (self::$verbose === True)
			print('Color( red: '.sprintf("%3s", $this->red).', green: '.sprintf("%3s", $this->green).', blue: '.sprintf("%3s", $this->blue).' ) destructed.'.PHP_EOL);
    }

    function __toString()
    {

    }

    function add ()
    {
        $color = ;
        return ($color)
    }

    function sub ()
    {
        $color = ;
        return ($color)
    }

    function mult ()
    {
        $color = ;
        return ($color)
    }
}
?>