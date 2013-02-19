<?php
$connect=mysql_connect("localhost","root","");
$db=mysql_selectdb("secure") or die("couldn't find database");
$a=mysql_query("select * from data where ID=$ID");
$ui=mysql_fetch_assoc($a);
?>