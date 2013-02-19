<?php session_start();
$id=$_SESSION['id'];
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

<center>My Messages</center>
<?php
$username=$_SESSION['username'];
$connect=mysql_connect("localhost","root","")or die("Couldn't connect");
mysql_select_db("secure")or die("Couldn't find db");
$query=mysql_query("select $username from messages");
while($row=mysql_fetch_assoc($query))
{echo "$row[$username]";
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
	<li><a href="event.php" class="events">Event <small>Event</small></a></li>
	<li><a href="editprofile.php" class="editprofile">Edit Profile <small>Edit Profile</small></a></li>
	<li><a href="logout.php" class="logout">Logout <small>Logout</small></a></li>
	<li>
<div class=search>
<form action='searchprofile.php' method='GET'>
<input type="text" name="search" value="search for members" class='box'>
<button type="submit" class='btn'>
<li>
</form>
</div>
        <li id="chatpanel"><a href="#" class="chat">Chat</a></li>
    </ul>
</div>
</body>
</html>