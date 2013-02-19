<?php
session_start();
session_destroy();
// Check to see if their session is in fact destroyed
if(!$_session['username']){ 
header("location: home.php"); // << makes the script send them to any page we set
} else {
print "Could not log you out, sorry the system encountered an error.";
exit();}
?>