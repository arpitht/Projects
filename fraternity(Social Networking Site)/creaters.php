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
<h1>Arpith:</h1> Senior Software Engineer && Web Developer<br>
	CSE,NIT Calicut<br>
	arpiththomas@gmail.com<br>
<h1>Arif:</h1>Senior Programmer && Web Developer<br>
	CSE,NIT Calicut<br>
	@gmail.com<br>
<h1>Maltus:</h1>Senior Programming && Web Developer<br>
	CSE,NIT Calicut<br>
	@gmail.com<br>
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