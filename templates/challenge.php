<style>
    #instructionsList {				
        list-style-type: none; 		/* Removes the list dot */
    } 
    li{
        margin-top: 10px;
    }

</style>
<!--
<html>
	<head>
		<title>ICT2x01 Challenge</title>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
		<link rel="stylesheet" href="static/assets/css/main.css" />
		<noscript><link rel="stylesheet" href="static/assets/css/noscript.css" /></noscript>
	</head>
        <body style="padding: 15px;">
            <div style="position: relative; top: 350px;">
                <table id="instructionsList" style="font-size: 20px;">
					<tr><td value="F" style="border: 1px solid black;">Move Forward</td></tr>
					<tr><td value="B" style="border: 1px solid black;">Move Backward</td></tr>
					<tr><td value="R" style="border: 1px solid black;">Turn Right</td></tr>
					<tr><td value="L" style="border: 1px solid black;">Turn Left</td></tr>
					<tr><td value="Loop" style="border: 1px solid black;">Loop</td></tr>
                </table>
				<table id="instructionsContainer" style="font-size: 20px;">
					<tr><td value="F" style="border: 1px solid black;">Move Forward</td></tr>
					<tr><td value="B" style="border: 1px solid black;">Move Backward</td></tr>
					<tr><td value="R" style="border: 1px solid black;">Turn Right</td></tr>
					<tr><td value="L" style="border: 1px solid black;">Turn Left</td></tr>
					<tr><td value="Loop" style="border: 1px solid black;">Loop</td></tr>
                </table>
            </div>
            <div>
                <div id = "instructionsContainer2" style="position: relative; margin-left: 300px; margin-top: 100px;">
                    <textarea id="instructions" style="width: 300px; height: 400px; resize:none;">
                        
                    </textarea>
                </div>
            </div>
            
            <script src="static/jquery.min.js"></script>
            <script src="static/copy.js"></script>
            
        </body>

</html> -->



<html>
	<head>
		<title>ICT2x01 Challenge</title>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
		<link rel="stylesheet" href="static/assets/css/main.css" />
		<noscript><link rel="stylesheet" href="static/assets/css/noscript.css" /></noscript>
	</head>
        <body style="padding: 15px;">
            <div style="position: relative; top: 350px;">
                <ul id = "instructionsList" style="font-size: 20px;">
                    <li draggable="true">Move Forward</li>
                    <li draggable="true">Move Backward</li>
                    <li draggable="true">Turn Right</li>
                    <li draggable="true">Turn Left</li>
                    <li draggable="true">Loop</li>
                </ul>
            </div>
            <div style="display:flex;">
                <div id = "fullNamesContainer" style="position: relative; margin-left: 300px;">
                    <form action="sendInstructions.php" method="post">
                        <textarea id="instructions" style="width: 300px; height: 400px; resize:none;">
                        </textarea>
                        <input type="submit" class="button primary" value="Send!">
                        <input type="button" value="Clear" onclick="javascript:eraseText();">
                    </form>
                </div>
                <img src="static/mazes/440011.png" align="middle" style="margin-left:auto; margin-right: auto; margin-top: auto; margin-bottom: auto; display:block;"/>
            </div>
            
            <script src="static/jquery.min.js"></script>
            <script src="static/copy.js"></script>
            
        </body>

</html>