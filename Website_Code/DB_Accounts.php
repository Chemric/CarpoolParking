<?php
require_once('navbar.php');
?>
<!doctype html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <!-- Font Awesome-->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

    <link rel="stylesheet" type="text/css" href="tabelstyle.css">
</head>
<body>
<?php
renderNavbar("DB_Accounts");
?>

<table style="border: 1px solid white;">
    <tr>
        <th style="border: 1px solid white;">ID</th>
        <th style="border: 1px solid white;">StudentenNummer</th>
        <th style="border: 1px solid white;">NummerPlaat</th>
        <th style="border: 1px solid white;">hash</th>
        <th style="border: 1px solid white;">Aanvraag</th>
    </tr>
    <tbody id="data"></tbody>
</table>



<?php
//login information
$Pass = "ohFacJR7mMAUpywl";
$User = "pxleai1q_jungleb";
$servername = "localhost";
$DB = "pxleai1q_jungleb";

$conn = mysqli_connect($servername, $User, $Pass, $DB);

//show values in a table
$sql = "SELECT * FROM Accounts";
$result = $conn->query($sql);

if($result -> num_rows < 0)
{
    echo "0 results";
}
mysqli_close($conn);
?>


<!-- Optional JavaScript -->
<script>
    var ajax =  new XMLHttpRequest();
    var method = "GET";
    var url = "getdata_Accounts.php";
    var asynchronous = true;

    ajax.open(method, url, asynchronous);
    ajax.send();

    ajax.onreadystatechange = function ()
    {
        if (this.readyState == 4 && this.status == 200)
        {
            var data = JSON.parse(this.responseText);
            console.log(data);
            var html = "";

            for (var i = 0; i < data.length; i++)
            {
                html += "<tr>";
                html += "<td style='font-weight: normal;'>" + data[i].ID; + "</td>";
                html += "<td style='font-weight: normal;'>" + data[i].StudentenNummer + "</td>";
                html += "<td style='font-weight: normal;'>" + data[i].NummerPlaat + "</td>";
                html += "<td style='font-weight: normal;'>" + data[i].hash + "</td>";
                html += "<td style='font-weight: normal;'>" + data[i].Aanvraag + "</td>";
                html += "</tr>";
            }
            document.getElementById("data").innerHTML = html;
        }
    }
</script>
<!-- jQuery first, then Popper.js, then Bootstrap JS -->
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>
</html>