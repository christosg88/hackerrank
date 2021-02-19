<?php
    // Forward reference is only available by JGsoft, .NET, Java, Perl, PCRE, PHP, Delphi and Ruby

    $Regex_Pattern = '/^(tac)+(tac|tactic)*$/'; //Do not delete '/'. Replace __________ with your regex.

    $handle = fopen ("php://stdin","r");
    $Test_String = fgets($handle);
    if(preg_match($Regex_Pattern, $Test_String, $output_array)){
        print ("true");
    } else {
        print ("false");
    }

    fclose($handle);
?>
