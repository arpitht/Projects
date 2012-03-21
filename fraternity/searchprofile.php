<?php session_start();
?>
<!DOCTYPE HTML>
<html>
<head>
<title>
</title>
</head>
<link type="text/css" rel="stylesheet" href="style1.css">
<body>

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
<div id="toppanel">
    <ul id="mainpanel">
       
        <li><a href="profile.php" class="profile">Profile <small>Profile</small></a></li>
        
        <li><a href="fraternity.php" class="fraternity">Fraternity <small>Fraternity</small></a></li>
        <li><a href="messages.php" class="messages">Messages (10) <small>Messages</small></a></li>
        <li><a href="photos.php" class="photos">Photos <small>Photos</small></a></li>
        <li><a href="updates.php" class="updates">Updates <small>Updates</small></a></li> 
	<li><a href="documents.php" class="documents">Documents <small>Documents</small></a></li>
	<li><a href="editprofile.php" class="editprofile">Edit Profile <small>Edit Profile</small></a></li>
	<li><a href="logout.php" class="logout">Logout <small>Logout</small></a></li>
	<li><form action='search.php' method='GET'>
<div class=search>
<input type="text" name="search" value="search for members" class='box'>
<button type="submit" class='btn'>
<li>
</form>
</div>
        <li id="chatpanel"><a href="#" class="chat">Friends (<strong>18</strong>)</a></li>
    </ul>
</div>
</body>
</html>
