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

<center>My Fraternity</center>
<?php
$username=$_SESSION['username'];
$connect=mysql_connect("localhost","root","")or die("Couldn't connect");
mysql_select_db("secure")or die("Couldn't find db");
$query=mysql_query("select $username from friends");
while($row=mysql_fetch_assoc($query))
{$qry=mysql_query("select * from users where username='$row[$username]'");
$rw=mysql_fetch_assoc($qry);
$dir="members/".$rw[id];
if($open=opendir($dir))
{while(($file=readdir($open))!=FALSE)
{if($file=="ppic.jpeg")
	$flag=1;
}
}
if($flag==1)
echo "<img src='$dir/ppic.jpg'/>";
else if($rw['Gender']==0)
echo "<img src='members/mppic.jpg'/>"; 
else
echo "<img src='members/fppic.jpg'/>";
$user=$rw['Username']; 
echo "<a href='view.php?member=$user'>Firstname:".$rw['Firstname']."</a><br>";
echo "Lastname:".$rw['Lastname']."<br>";
echo "Semester:".$rw['Semester']."<br>";
echo "Branch:".$rw['Branch']."<br>";
echo "Gender:";
if($rw['gender']==0)
echo "MALE<br/>";
else
echo "FEMALE<br>";
echo "Date Of Birth:".$rw['DOB']."<br>";
echo "Place: ",$rw['Place']."<br>";
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