<!DOCTYPE HTML>

<html>
    <head>
        <title>Play Page</title>
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
                margin-top:10px;
            }   
            #homeBtn{
                display: flex;
                align-items: center;
                justify-content: center;
            }
        </style>
    </head>
    <h2 class="major" style="padding: 15px;">Control the Car!</h2>
    <body style="padding: 15px; float:none;">
        <div class="container">

            <!-- 1st Column -->
            <div style="position: relative; float: left; margin-right: 50px;">
                <ul id = "instructionsList" style="font-size: 20px;">
                    <li draggable="true">Move Forward</li>
                    <li draggable="true">Move Backward</li>
                    <li draggable="true">Turn Right</li>
                    <li draggable="true">Turn Left</li>
                </ul>
		<a href="/" id="homeBtn" class="button primary" draggable="false">☰ Home</a>
            </div>

            <!-- 2nd Column -->
            <div name = "fullNamesContainer" style="position: relative; float:left;">
                <form action="/sendInstructions" method="post">
                    <!--<form action="/action_page.php">-->
                    <textarea id="instructions" name="message" rows="10" cols="30" style='resize:none'></textarea>
                    <br>
                    <input type="submit" class="button primary" value="Send!">
                    <input type="button" value="Clear" onclick="eraseText();">
                </form>
            </div>

            <script type="text/javascript" src="{{ url_for('static', filename='jquery.min.js') }}"></script>
            <script type="text/javascript" src="{{ url_for('static', filename='copy.js') }}"></script>

        </div>
    </body>
</html>
