<?php
class Color {

    public $red = 0;
    public $green = 0;
    public $blue = 0;
    public $verbose = FALSE;

    static function doc()
    {
        echo "<- Color ----------------------------------------------------------------------\n";
        echo "The Color class handles RGB colors.\n\n";

        echo "An instance can be contructed from either a RGB value:\n";
        echo "new Color( array( 'rgb' => 12345 ) );\n\n";

        echo "Or from distinct red, green, blue constitutives:\n";
        echo "new Color( array( 'red' => 255, 'green' => 255, 'blue' => 255 ) );\n\n";

        echo "Red, green, blue constitutives and RGB values are converted to intergers.\n";
        echo "Negative or > to 255 color constitutives are left as is.\n";
        echo "Any other use is undefined behaviour.\n\n";

        echo "The class provides the following methods :\n\n";

        echo "Color   add( Color \$rhs );\n";
        echo "Adds each color constitutive and returns a new Color instance.\n\n";

        echo "Color   sub( Color \$rhs );\n";
        echo "Substracts each color constitutive and returns a new Color instance.\n\n";

        echo "Color   mult( \$f );\n";
        echo "Multiplies each color constitutive by factor \$f and returns a new Color\n";
        echo "instance\n";
        echo "---------------------------------------------------------------------- Color ->\n";
    }

    function __construct( array $kwarg )
    {
        if ($kwarg['red'])
            $this->$red = $kwarg['red'];
        if ($kwarg['green'])
            $this->$red = $kwarg['red'];
        if ($kwarg['blue'])
            $this->$red = $kwarg['red'];
        if ($verbose == TRUE)
            echo "verbose TRUE\n";
    }

    function __destruct()
    {
        if ($verbose == TRUE)
            echo "verbose TRUE\n";
        return ;
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