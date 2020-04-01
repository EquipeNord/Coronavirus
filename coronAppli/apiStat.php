<?php
session_start();

include("dbConnect.php");
$req="select distinct stade.humId, etatLibelle, stade.date from stade natural join etat natural join humain natural join date";
$res=mysqli_query($lien,$req);

$rows = array();
while ($r = mysqli_fetch_assoc($result))
{
  $rows['object_name'][] = $r;
}

print json_encode($rows);

// $tabInfo=mysqli_fetch_array($res);

// $json=json_encode($tabInfo);
// echo $json;

?>
