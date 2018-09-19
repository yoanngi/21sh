<?php
class Color {

    public $red = 0;
    public $green = 0;
    public $blue = 0;
    static public $verbose = FALSE;

    function doc()
    {
        return (file_get_contents('Color.doc.txt'));
    }

    function __construct( array $kwarg )
    {
        if (array_key_exists('rgb', $kwarg))
        {
            // ?;
        }
        if (array_key_exists('red', $kwarg) && array_key_exists('green', $kwarg) && array_key_exists('blue', $kwarg))
        {
            if ($kwarg['red'] != "" && $kwarg['green'] != "" && $kwarg['blue'] != "")
            {
                $this->$red = intval($kwarg['red']);
                $this->$green = intval($kwarg['green']);
                $this->$blue = intval($kwarg['blue']);
            }
        }
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
        return ('Color( red: '.sprintf("%3s", $this->red).', green: '.sprintf("%3s", $this->green).', blue: '.sprintf("%3s", $this->blue).' ) destructed.'.PHP_EOL);
    }

    function add ($param)
    {
        $color = new Color($param);
        return ($color);
    }

    function sub ($param)
    {
        $color = new Color($param);
        return ($color);
    }

    function mult ($param)
    {
        $color = new Color($param);
        return ($color);
    }
}
?>