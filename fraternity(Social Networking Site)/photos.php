<?php session_start();
$id=$_SESSION['id'];
$name=$_FILES['pfile']['name'];
if($name)
{
	$type=$_FILES['pfile']['type'];
	$size=$_FILES['pfile']['size'];
	$tmp=$_FILES['pfile']['tmp_name'];
	$error=$_FILES['pfile']['error'];
	echo "<br><br><br><br>$type";
	if($error)
	echo "Couldn't upload file....Please try again";
	else
	{	$temp=explode('/',$type);

		if($temp[0]=='image')
		{	move_uploaded_file($tmp,"members/".$id."/".$name);
			echo "File uploaded";
		}
		else
		echo "<br>Invalid file type";
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
<p>Upload images</p>
<form action='photos.php' method='POST' enctype='multipart/form-data'>
<input type='file' name='pfile'>
<input type='submit' value='Upload'>
</form>
<?php
$dir='members/'.$id;
if($open=opendir($dir))
{	while(($file=readdir($open))!=FALSE)
	{	if($file!='.'&&$file!='..'&&$file!='Documents')
		{
		echo "<img src='$dir/$file'>";}
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