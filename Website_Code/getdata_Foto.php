<?php
$Pass = "ohFacJR7mMAUpywl";
$User = "pxleai1q_jungleb";
$servername = "localhost";
$DB = "pxleai1q_jungleb";

session_start();

$conn = mysqli_connect($servername, $User, $Pass, $DB);

$result = mysqli_query($conn, "SELECT ID, PNG FROM Foto" );

$data = array();
while ($row = mysqli_fetch_assoc($result))
{
    $data [] = array( "ID" => $row["ID"], "PNG" => base64_encode( $row["PNG"] ) );
}

echo json_encode($data);
?>