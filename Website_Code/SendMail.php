<?php
	$studentenNummer= $_REQUEST["studentenNummer"];
	$nummerPlaat= $_REQUEST["nummerPlaat"];
	include 'connect';
	ini_set('SMTP','myserver');
	ini_set('smtp_port',25);
	
	$hash = md5( rand(0,1000) );
	$sql = "UPDATE Accounts SET hash ='$hash',Aanvraag=1 WHERE StudentenNummer = $studentenNummer;";
	$result = $conn->query($sql);
	
	if ($conn->query($sql) === TRUE) {
		
		echo "true" ;
		echo "<br>";
		
	} else {

		echo "Error: " . $sql . "<br>" . $conn->error;
		echo "<br>";

	}
	
	$to=$studentenNummer."@student.pxl.be";
	echo $to ;
	echo "<br>";
	$subject = 'Nieuwe nummerplaat';
	echo $hash;	
	$message = '
		Verander uw email via de link:
		http://jungleboogie.pxl-ea-ict.be/ChangeNummerplaat.php?studentenNummer='.$studentenNummer.'&nummerPlaat='.$nummerPlaat.'&hash='.$hash.'
	';
	$headers = 'From:noreply@jungleboogie.pxl-ea-ict.be' . "\r\n";
	$errorMail=mail($to, $subject, $message, $headers);
	echo "<br>";
	echo $errorMail;
	
	
?>