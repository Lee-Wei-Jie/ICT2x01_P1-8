<!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>Maze Generator</title>

  <style>
	body{
	  margin: 0;
	  background: #222a33;
	  text-align: center;
	}
	div{
	  display: inline-block;
	  margin: 20px auto 0 auto;
	  position: relative;
	}
	ul{
	  position: absolute;
	  right: 0;
	  width: 220px;
	  height: 100%;
	  float: left;
	  list-style: none;
	  padding: 0;
	  margin: 0;
	  text-align: left;
	  color: #eee;
	  font-family: helvetica;
	}
	li{
	  padding: 5px 5px 5px 5px;
	}
	label{
	  width: 50%;
	  display: inline-block;
	  box-sizing: border-box;
	  text-align: right;
	  padding-right: 5px;
	  text-shadow: 2px 2px 0px rgba(0,0,0,0.2);
	}
	input{
	  width: 50%;
	  height: 24px;
	  box-sizing: border-box;
	  padding: 0;
	  margin: 0;
	  border: none;
	  background: #ccc;
	  color: #333;
	  font-weight: bold;
	  text-align: center;
	  border-radius: 2px;
	  transition: background 200ms;
	  box-shadow: 2px 2px 0px rgba(0,0,0,0.2);
	}
	input:focus{
	  outline: none;
	  background: #fff;
	  color: #222;
	}
	input[type=button]{
	  background: #111;
	  color: #eee;
	  margin-left: 50%;
	  font-weight: normal;
	  cursor: pointer;
	}
	input[type=button]:active{
	  transform: translate(2px,2px);
	  box-shadow: 0px 0px 0px rgba(0,0,0,0.2);
	}
	canvas{
	  margin-right: 220px;
	  display: block;
	  float: left;
	}
  </style>

</head>
<body>
	<div>
	  <canvas></canvas>
	  <ul>
		<li><label>Width:</label><input id=width type="text"/></li>
		<li><label>Height:</label><input id=height type="text"/></li>
		<li><label>Path Width:</label><input id=pathwidth type="text"/></li>
		<li><label>Wall Width:</label><input id=wallwidth type="text"/></li>
		<li><label>Outer Width:</label><input id=outerwidth type="text"/></li>
		<li><label>Path Color:</label><input id=pathcolor type="text"/></li>
		<li><label>Wall Color:</label><input id=wallcolor type="text"/></li>
		<li><label>Seed:</label><input id=seed type="text"/></li>
		<li><input id=randomseed type="button" value="Random Seed"/></li>
	  </ul>
	</div>
	<!-- partial -->
	  <script  src="static/mazegenerator.js"></script>

</body>
</html>
