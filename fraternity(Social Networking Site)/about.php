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
   <li><a href="home.php">Home</a></li>
   <li><a href="registration.php">Registration</a></li>
   <li><a href="about.php">About</a></li>
   <li><a href="creaters.php">The Creaters</a></li>
   </ul>
 </div>
<form action='search.php' method='GET'>
<fieldset class=search>
<input type="text" name="search" value="search for members" class='box'>
<button type="submit" class='btn'>
</fieldset>
</form>
</div>
<script type="text/javascript">
var d=new Date()
var weekday=new Array("Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday")
var monthname=new Array("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec")
document.write(weekday[d.getDay()] + " ")
document.write(d.getDate() + ". ")
document.write(monthname[d.getMonth()] + " ")
document.write(d.getFullYear())
</script>
<div id=center>
<br><br>
To use fraternity every user needs to register.<br>
To register click on the registration tab on the main page and provide the necessary details.<br>
Once registered u can login with your username and password.<br>
The profile page offers a lot of functionality like:<br>
1)Add new fraternity members<br>
2)Upload photos<br>
3)Upload Documents<br>
4)Manage your Events<br>
5)Chat with Friends<br>
6)View Updates<br>
7)View Messages<br>
8)Edit Settings<br>
</div>
<div id=sidebar>
<form action="login.php" method =post>
Username:<input type="text" name="username" class="bar"><br>
Password:<input type="password" name="pwd" class="bar"><br>
<input type="submit" value="Sign-in" class="bar">
</form>
<div>
</body>
</html>