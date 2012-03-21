<?php session_start();
$username=$_POST['username'];
$password=$_POST['pwd'];
if($username&&$password)
{	$connect=mysql_connect("localhost","root","")or die("Couldn't connect");
	mysql_select_db("secure")or die("Couldn't find db");
	$query=mysql_query("select * from login where Username='$username'") ;
	$no_rows=mysql_num_rows($query);
	if($no_rows!=0)
	{	$record=mysql_fetch_assoc($query);
		$dbpassword=$record['Password'];	
		$id=$record['ID'];
		if($dbpassword==$password)
		{
		
		$_SESSION['username']=$username;
		$_SESSION['id']=$id;
		mysql_query("update users set online=1 where Username='$username'");
		echo "Welcome ".$_SESSION['username'];
		echo "<a href='profile.php'>click here</a> to go to profile page ";
		}		
		else
		die("Incorrect Password");
		
	}
	else
		die("Incorrect Username/Password");

} 
else
die( "Please enter both username and password");
?>
