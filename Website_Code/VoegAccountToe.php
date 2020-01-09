<?php

$studentenNummer= $_REQUEST["studentenNummer"];
$nummerPlaat= $_REQUEST["nummerPlaat"];
include 'connect';

if(empty($studentenNummer)){ die(" studentenNummer niet beschikbaar " . $conn->connect_error); }
if(empty($nummerPlaat)){ die(" nummerPlaat niet beschikbaar " . $conn->connect_error); }

$sql1 = "SELECT * FROM Accounts WHERE StudentenNummer = '$studentenNummer' ";
$result1 = $conn->query($sql1);

if ( $result1->num_rows == 0 ){
	$sql2 = "INSERT INTO Accounts (StudentenNummer, NummerPlaat) VALUES ('$studentenNummer','$nummerPlaat')";

	if ($conn->query($sql2) === TRUE) {

		

		Redirect();

		

	} else {

		echo "Error: " . $sql2 . "<br>" . $conn->error;

	}

}
else {
	while($row = $result1->fetch_assoc()) {

		changeNummerplaat($studentenNummer,$nummerPlaat);
	}
}

$conn->close();



function Redirect()

{

	echo "<script type='text/javascript'>alert('New record created successfully!');

	window.location='CreateAccount';

	</script>";

	

    exit();

}

function changeNummerplaat($studentenNummer,$nummerPlaat)

{

	echo "<script type='text/javascript'>

	if (confirm('Wilt u de nummerplaat veranderen $nummerPlaat'))
	{
		self.location = 'SendMail.php?studentenNummer=$studentenNummer&nummerPlaat=$nummerPlaat';
	} 
	
	else {
		history.go(-1);
	}

	</script>";

	

    exit();

}
?>