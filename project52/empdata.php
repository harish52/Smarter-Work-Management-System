<?php
?>
<html>
<head>
<script type="text/javascript">

function checkIt(evt) {
    evt = (evt) ? evt : window.event
    var charCode = (evt.which) ? evt.which : evt.keyCode
    if (charCode > 31 && (charCode < 48 || charCode > 57)) {
        status = "This field accepts numbers only."
        return false
    }
    status = ""
    return true
}


function validate()
{
    var err_msg='';
    var empname=document.form1.empname.value;
    var empaddr=document.form1.empaddr.value;
   
   
    if(empname==null || empname=='')
    {
        err_msg="name required";
       document.getElementById("rs").innerHTML=err_msg;
      
    }
   
    if(empaddr==null || empaddr=='')
    {
        err_msg=err_msg+"<br/>addr required";
       document.getElementById("rs").innerHTML=err_msg;
      
    }

    var empphoto=document.form1.empphoto.value;
     if(empphoto==null || empphoto=='')
    {
       
        err_msg=err_msg+"<br/>empphoto required";
       document.getElementById("rs").innerHTML=err_msg;
      
    }
   
 

 var empmob=document.form1.empmob.value;
 if(empmob==null || empmob=='')
    {
       
        err_msg=err_msg+"<br/>empmob required";
       document.getElementById("rs").innerHTML=err_msg;
      
    }
   
    var email=document.form1.email.value;
    var atpos=email.indexOf("@");
    var dotpos=email.lastIndexOf(".");
    if (atpos<1 || dotpos<atpos+2 || dotpos+2>=email.length)
    {
        err_msg=err_msg+"<br/>pls enter email id in correct format";
         document.getElementById("rs").innerHTML=err_msg;
    }
  
 if(err_msg=='')
    {
        return true;
       
    }
    else
    {
        return false;
    }
}



</script>
<style type="text/css">
body
{
    background-color:#789944;
}
</style>
<title>employee details</title>
<body>


<form name="form1" action="in_array.php" method="post" enctype="multipart/form-data" onsubmit="return validate();">

<table  align="center" border="1" cellpadding="14" width="50%">



<tr>
<td align="center" colspan="2"><b>employee details</b></td></td>

</tr>
<tr>
<td colspan="2" id="rs">  </td>
</tr>

<tr>
<td><b>Empid</b></td><td><input type="text" name="empid"/></td>

</tr>
<tr>
<td><b>Empname</b></td><td><input type="text" name="empname"/></td>

</tr>
<tr>
<td><b>addr</b></td><td><input type="text" name="empaddr"/></td>

</tr>
<tr>
<td><b>Empphoto</b></td><td><input type="file" name="empphoto"/></td>

</tr>
<tr>
<td><b>Email</b></td><td><input type="text" name="email"/></td>

</tr>
<tr>
<tr>
<td><b>mobile</b></td><td><input type="text" name="empmob" maxlength="10" onkeypress="return checkIt(event)"/></td>

</tr>
<tr>
<td align="center" colspan="2"><input type="submit" value="insert"/></td></form>

</tr>

</table>

<table align="center" border="1" cellpadding="14" width="50%">
<form action="empdetdel.php" method="post">
<tr>
<td colspan="2" align="center"><input type="text" name="del"/><input type="submit" value="delete"/></td>
</tr>
</form>
</table>

<table align="center" border="1" cellpadding="14" width="50%">
<form action="empupdate.php" method="post">
<tr>
<td colspan="2" align="center"><input type="text" name="upid"/><input type="submit" value="update"/></td>
</tr>
</form>
</table>

<table align="center" border="1" cellpadding="14" width="50%">
<form action="empview.php" method="post">
<tr><td colspan="2" align="center"><input type="submit" value="view records"/></td>

</tr>

</form>

</table>

</body>

</head>

</html>