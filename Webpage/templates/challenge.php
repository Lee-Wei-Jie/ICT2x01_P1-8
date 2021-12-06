
<html>
	<head>
		<title>Challenge Page</title>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
		<link rel="stylesheet" href="static/assets/css/main.css" />
		<noscript><link rel="stylesheet" href="static/assets/css/noscript.css" /></noscript>
		<style>
		    #instructionsList {
			list-style-type: none;
                	padding-left: 0px;
		    }
		    li{
			margin-top: 10px;
		    }
		</style>
	</head>
	<h2 class="major" style="padding: 15px;">Beat the Challenge!</h2>
        <body style="padding: 15px; float:none;">

	<!-- Container -->
	<div class="container" style="display: flex; flex-wrap: wrap;">

            <!-- 1st Column -->
            <div style="flex-grow:0; align-self:auto; margin-right: 50px;">
                <ul id = "instructionsList" style="font-size: 20px;">
                    <li draggable="true">Move Forward</li>
                    <li draggable="true">Move Backward</li>
                    <li draggable="true">Turn Right</li>
                    <li draggable="true">Turn Left</li>
                </ul>
                <a href="/" id="homeBtn" class="button primary" draggable="false">☰ Home</a>
            </div>

            <!-- 2nd Column -->
            <div name = "fullNamesContainer" style="flex-grow:0; align-self:auto;">
                <form action="/sendInstructions" method="post">
                    <form action="/action_page.php">
                    <textarea id="instructions" name="message" rows="10" cols="30"></textarea>
                    <input type="submit" class="button primary" value="Send!">
                    <input type="button" value="Clear" onclick="eraseText();">
                </form>
            </div>

            <!-- 3rd Column -->
            <img src="static/mazes/440011.png" style="margin-left:auto; margin-right: auto; margin-top: auto; margin-bottom: auto; display:block; vertical-align: middle;"/>

            <script src="static/jquery.min.js"></script>
            <script src="static/copy.js"></script>

        </div>

	</body>

</html>
