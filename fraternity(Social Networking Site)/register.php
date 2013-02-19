<?php
	 
	$username = preg_replace('#[^A-Za-z0-9]#i', '', $_POST['username']); // filter everything but letters and numbers
	$firstname = preg_replace('#[^A-Za-z0-9]#i', '', $_POST['firstname']);
	$lastname = preg_replace('#[^A-Za-z0-9]#i', '', $_POST['lastname']);
	$gender = preg_replace('#[^a-z]#i', '', $_POST['gender']); // filter everything but lowercase letters
	$pwd= $_POST['pwd'];
     	$repwd = $_POST['repwd'];
	$b_m = preg_replace('#[^A-Za-z0-9]#i', '', $_POST['DOB_month']); // filter everything but letters and numbers
     	$b_d = preg_replace('#[^0-9]#i', '', $_POST['DOB_day']); // filter everything but numbers
	$b_y = preg_replace('#[^0-9]#i', '', $_POST['DOB_year']); // filter everything but numbers      	
	$email = $_POST['email'];
	$email = stripslashes($email); 
     	$pwd = stripslashes($pwd); 
    	$repwd = stripslashes($repwd); 	 
    	$email = strip_tags($email);
     	$pwd = strip_tags($pwd);
	$repwd = strip_tags($repwd);
     		// Connect to database
   	$connect=mysql_connect("localhost","root","");
	mysql_selectdb("secure") or die("couldn't find database");

     	$emailCHecker = mysql_real_escape_string($email);
	$emailCHecker = str_replace("`", "", $emailCHecker);
		// Duplicate username check
	$sql_uname_check = mysql_query("SELECT Username FROM users WHERE Username='$username'"); 
     	$uname_check = mysql_num_rows($sql_uname_check);
     		// Database duplicate e-mail check setup for use below in the error handling if else conditionals
     	$sql_email_check = mysql_query("SELECT email FROM users WHERE email='$emailCHecker'");
    	$email_check = mysql_num_rows($sql_email_check);

	       // Error handling for missing data
     	if ((!$username) || (!$gender) || (!$b_m) || (!$b_d) || (!$b_y) || (!$email) || (!$pwd) || (!$repwd)||(!$firstname)||(!$lastname)) 
	{ 

     		echo "ERROR: Please Enter the following fields:<br />";
		if(!$username){ 
       					echo ' * User Name<br />';
     			      } 
		if(!$firstname){ 
       					echo ' * Firstname<br />';
   			       } 
 		if(!$lastname){ 
       					echo ' * Lastname<br />';
     			      } 
    		if(!$gender){ 
       					echo ' * Gender<br />';
   			  } 	
	 	if(!$b_m){ 
       					echo ' * Birth Month<br />';      
    			 }
	 	if(!$b_d){ 
       					echo ' * Birth Day<br />';        
    			} 
	 	if(!$b_y){ 
       					echo ' * Birth year<br />';        
     			} 		
	 	if(!$email){ 
      					 echo ' * Email Address<br />';      
    			 }
 		   
     				
	
		 if(!$pwd){ 
       					echo ' * Login Password<br />';      
     			}
	 	if(!$repwd){ 
       					echo ' * Confirm Login Password<br />';        
     			    } 	
	
}   
	  else	if ($pwd != $repwd) {
              				echo 'ERROR: Password fields below do not match<br />';
     				}		 
     	else	if (strlen($username) < 4) {
	           			echo "<u>ERROR:</u><br />Your User Name is too short. 4 - 20 characters 					please.<br />"; 
    					 }
	else	if (strlen($username) > 20) 
	          			 {echo "<u>ERROR:</u><br />Your User Name is too long. 4 - 20 characters 					please.<br />"; }
     	else	if ($uname_check > 0){ 
              echo "<u>ERROR:</u><br />Your User Name is already in use inside of our system. Please try another.<br/>"; 
     } 
	else	if ($email_check > 0){ 
              echo "<u>ERROR:</u><br />Your Email address is already in use inside of our system. Please use 		another.<br/>"; 
     } 


	else {	$DOB="$b_d-$b_m-$b_y";
		mysql_query("insert into login values('','$username','$pwd')");
		mysql_query("insert into users values('','$username','$firstname','$lastname','','','$DOB','$email','$gender','')");
mysql_query("alter table updates add column $username varchar(100)");
		$id=mysql_insert_id();
		mkdir("members/$id",0755);
		/*$to = "$email";									 
    	$from =fraternity.com ; 
    	$subject = 'Complete Your Registration';
    	//Begin HTML Email Message
   		 $message = "Hi $username,

   		Complete this step to activate your login identity at fraternity.com 

   		Click the line below to activate when ready

   		http://www.fraternity/activation.php?id=$id&sequence=$db_password
  		 If the URL above is not an active link, please copy and paste it into your browser address bar

  		Login after successful activation using your:  
   		E-mail Address: $email1 
   		Password: $pwd
		";
  		 //end of message
		$headers  = "From: $from\r\n";
    	$headers .= "Content-type: text\r\n";
    	mail($to, $subject, $message, $headers);*/
		}


?>
