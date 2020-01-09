<!DOCTYPE HTML>
<html>  

	<body>

		<?php
			include 'connect';
			$studentenNummer= $_REQUEST["studentenNummer"];
			$nummerPlaat= $_REQUEST["nummerPlaat"];
			$hash= $_REQUEST["hash"];
			
			if(empty($studentenNummer)){ die(" studentenNummer niet beschikbaar " . $conn->connect_error); }
			if(empty($nummerPlaat)){ die(" nummerPlaat niet beschikbaar " . $conn->connect_error); }
			if(empty($hash)){ die(" hash niet beschikbaar " . $conn->connect_error); }
			
			$sql1 = "SELECT * FROM Accounts WHERE StudentenNummer = '$studentenNummer' AND hash=$hash AND Aanvraag!=0";
			$result1 = $conn->query($sql1);
			
			if ($result1 ){
				
				echo "error verzend een nieuwe aanvraag";
				$sql3 = "UPDATE Accounts SET Aanvraag=0 WHERE StudentenNummer = $studentenNummer;";
				$result3 = $conn->query($sql3);
			}
			else{

				$sql2 = "UPDATE Accounts SET NummerPlaat ='$nummerPlaat',Aanvraag=0 WHERE StudentenNummer = $studentenNummer;";
				$result2 = $conn->query($sql2);
		
				if ($conn->query($sql2) === TRUE) {
			
					echo "true" ;
					echo "<br>";
			
				} else {

					echo "Error: " . $sql2 . "<br>" . $conn->error;
					echo "<br>";

				}
			}
		?>
	</body>

</html>