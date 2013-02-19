<?php session_start();
$id=$_SESSION['id'];
$username=$_SESSION['username'];
?>
<!DOCTYPE HTML>
<html>
<head>
<title>
</title>
</head>
<link type="text/css" rel="stylesheet" href="style1.css">
<link type="text/css" rel="stylesheet" media="all" href="css/chat.css" />
<link type="text/css" rel="stylesheet" media="all" href="css/screen.css" />
<body>

<div id=center>
What's up??
<form action='status.php' method='POST'>
<input type="text" name="status" class='box'>
<input type="submit" class='btn' value="Share">

</form>

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
if($flag==1)
echo "<img src='$dir/ppic.jpg'/>";
else if($row['Gender']==0)
echo "<img src='members/mppic.jpg'/>"; 
else
echo "<img src='members/fppic.jpg'/>"; 
echo "Firstname:".$row['Firstname']."<br>";
echo "Lastname:".$row['Lastname']."<br>";
echo "Semester:".$row['Semester']."<br>";
echo "Branch:".$row['Branch']."<br>";
echo "Gender:";
if($row['gender']==0)
echo "MALE<br/>";
else
echo "FEMALE<br>";
echo "Date Of Birth:".$row['DOB']."<br>";
echo "Place: ",$row['place'];
?>
</div>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript"> 
$(document).ready(function(){

	//Adjust panel height
	$.fn.adjustPanel = function(){ 
		$(this).find("ul, .subpanel").css({ 'height' : 'auto'}); //Reset subpanel and ul height
		
		var windowHeight = $(window).height(); //Get the height of the browser viewport
		var panelsub = $(this).find(".subpanel").height(); //Get the height of subpanel	
		var panelAdjust = windowHeight - 100; //Viewport height - 100px (Sets max height of subpanel)
		var ulAdjust =  panelAdjust - 25; //Calculate ul size after adjusting sub-panel (27px is the height of the base panel)
		
		if ( panelsub >= panelAdjust ) {	 //If subpanel is taller than max height...
			$(this).find(".subpanel").css({ 'height' : panelAdjust }); //Adjust subpanel to max height
			$(this).find("ul").css({ 'height' : ulAdjust}); //Adjust subpanel ul to new size
		}
		else if ( panelsub < panelAdjust ) { //If subpanel is smaller than max height...
			$(this).find("ul").css({ 'height' : 'auto'}); //Set subpanel ul to auto (default size)
		}
	};
	
	//Execute function on load
	$("#chatpanel").adjustPanel(); //Run the adjustPanel function on #chatpanel

	
	//Each time the viewport is adjusted/resized, execute the function
	$(window).resize(function () { 
		$("#chatpanel").adjustPanel();
		
	});
	
	//Click event on Chat Panel	
	$("#chatpanel a:first").click(function() { //If clicked on the first link of #chatpanel 
		if($(this).next(".subpanel").is(':visible')){ //If subpanel is already active...
			$(this).next(".subpanel").hide(); //Hide active subpanel
			$("#footpanel li a").removeClass('active'); //Remove active class on the subpanel trigger
		}
		else { //if subpanel is not active...
			$(".subpanel").hide(); //Hide all subpanels
			$(this).next(".subpanel").toggle(); //Toggle the subpanel to make active
			$("#footpanel li a").removeClass('active'); //Remove active class on all subpanel trigger
			$(this).toggleClass('active'); //Toggle the active class on the subpanel trigger
		}
		return false; //Prevent browser jump to link anchor
	});
	
	//Click event outside of subpanel
	$(document).click(function() { //Click anywhere and...
		$(".subpanel").hide(); //hide subpanel
		$("#footpanel li a").removeClass('active'); //remove active class on subpanel trigger
	});
	$('.subpanel ul').click(function(e) { 
		e.stopPropagation(); //Prevents the subpanel ul from closing on click
	});
	
});
</script>
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
              <li id="chatpanel">
        	<a href="#" class="chat">Fraternity</a>
            <div class="subpanel">
            	<?php
				mysql_connect("localhost","root","");
				mysql_select_db("secure");
				$query=mysql_query("select $username from friends");
				$num_rows=mysql_num_rows($query);
				while($friends=mysql_fetch_assoc($query))
				{
				$a=mysql_query("select Online from users where Username='$friends[$username]'");
				$b=mysql_fetch_assoc($a);
				if($b['Online']==1)
            	echo "<li><a href=\"javascript:void(0)\" onClick=\"javascript:chatWith('$friends[$username]')\">$friends[$username]</a></li>";
                }
				?>
            </div>
        </li>
    </ul>
</div>

<script type="text/javascript" src="js/chat.js"></script>

</body>
</html>