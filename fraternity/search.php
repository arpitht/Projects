<!DOCTYPE HTML>
<html>
<head>
<title>
</title>
</head>
<link type="text/css" rel="stylesheet" href="style.css">
<body>
<img src="images/logo1.jpg" class=logo />
<div id=header>
<div id="tabnavigation" class="description">
  <ul>
   <li><a href="home.html">Home</a></li>
   <li><a href="registration.html">Registration</a></li>
   <li><a href="about.html">About</a></li>
   <li><a href="creaters.html">The Creaters</a></li>
   </ul>
 </div>
<form action='search.php' method='GET'>
<fieldset class=search>
<input type="text" name="search" value="search for members" class='box'>
<button type="submit" value="search" class='btn'>
</form>
</fieldset>
</div>
<div id=center>
<?php
$keyword=$_GET['search'];
if($keyword==NULL)
{die("Enter a keyword to be searched");}
mysql_connect("localhost","root","")or die("Couldn't connect");
mysql_select_db("secure")or die("Couldn't find db");
$part=explode(" ",$keyword);
foreach($part as $p)
{
$x++;
if($x==1)
$sub.="firstname like '%$p%'";
else
$sub.="or firstname like '%$p%'";
}
$query=mysql_query("select Firstname,Gender,Place from users where $sub");
$count=mysql_num_rows($query);
if(!$count)
{echo "No matching results";
}
else
{echo $count.' results found<br>';
while($row=mysql_fetch_assoc($query))
{
echo "<br>Name: ".$row['Firstname'];
if($row['Gender']==0)
echo "<br>Gender: Male";
else echo "<br>Gender: Female";
echo "<br>Place: ".$row['Place'];
}
}
?>
</div>
<div id=sidebar>
<form action="login.php" method=post>
Username:<input type="text" name="username" class="bar"><br>
Password:<input type="password" name="pwd" class="bar"><br>
<input type="submit" value="Sign-in" class="bar">
</form>
<div>
</body>
</html>