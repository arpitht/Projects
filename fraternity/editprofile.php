<?php session_start();
$id=$_SESSION['id'];
$username=$_SESSION['username'];
$firstname=$_POST['firstname'];
$lastname=$_POST['lastname'];
$semester=$_POST['semester'];
$branch=$_POST['branch'];
$DOB=$_POST['DOB'];
$place=$_POST['place'];
$name=$_FILES['file']['name'];
mysql_connect("localhost","root","")or die("Couldn't connect");
mysql_select_db("secure")or die("Couldn't find db");
if(isset($firstname))
mysql_query("update users set Firstname as $firstname where Username='$username'" );
if(isset($lastname))
mysql_query("update users set  Lastname as $lastname where Username='$username'" );
if(isset($semester))
mysql_query("update users set Semester as $semester where Username='$username'" );
if(isset($branch))
mysql_query("update users set  Branch as $branch where Username='$username'" );
if(isset($DOB))
mysql_query("update users set  DOB as $DOB where Username='$username'" );
if(isset($place))
mysql_query("update users set  Place as $place where Username='$username'" );
if($name)
{
$type=$_FILES['file']['type'];
$size=$_FILES['file']['size'];
$tmp=$_FILES['file']['tmp_name'];
$error=$_FILES['file']['error'];
echo "<br><br><br><br>$type";
if($error)
echo "Couldn't upload file....Please try again";
else
{if($type=='image/jpeg')
{move_uploaded_file($tmp,"members/".$id."/ppic.jpg");
echo "file uploaded";
}
else
echo "<br>Invalid file";
}
}
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

$connect=mysql_connect("localhost","root","")or die("Couldn't connect");
mysql_select_db("secure")or die("Couldn't find db");
$query=mysql_query("select * from users where Username='$username'");
$row=mysql_fetch_assoc($query);
$dir="members/".$id;
if($open=opendir($dir))
{while(($file=readdir($open))!=FALSE)
{if($file=="ppic.jpeg")
	$flag=1;
}
}
echo "<form action='editprofile.php' method='POST' enctype='multipart/form-data'>";
if($flag==1)
echo "<img src='$dir/ppic.jpg'/>";
else if($row['Gender']==0)
echo "<img src='members/mppic.jpg'/>"; 
else
echo "<img src='members/fppic.jpg'/>"; 
echo "Change Profile Pic";
echo "<input type='file' name='nfile'>";
echo "<br>Firstname:";
echo "<input type='text' name='firstname' value='$row[Firstname]'><br>";
echo "Lastname:";
echo "<input type='text' name='lastname' value='$row[Lastname]'><br>";
echo "Semester:";
echo "<input type='text' name='semester' value='$row[Semester]'><br>";
echo "Branch:";
echo "<input type='text' name='branch' value='$row[Branch]'><br>";
echo "Gender:";
if($row['gender']==0)
echo "MALE<br/>";
else
echo "FEMALE<br>";
echo "Date Of Birth:";
echo "<input type='text' name='DOB' value='$row[DOB]'><br>";
echo "Place: ";
echo "<input type='text' name='place' value='$row[Place]'><br>";
echo "<input type='submit' value='Submit'>";
echo "</form>";
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