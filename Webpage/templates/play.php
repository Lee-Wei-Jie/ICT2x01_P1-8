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
                list-style-type: none;      /* Removes the list dot */
                padding-left: 0px;          /* ADDED - SHAHMIZAN */
            }
            li{
                margin-top:10px;
            }   
            #homeBtn{                       /* ADDED - SHAHMIZAN */
                display: flex;
                align-items: center;
                justify-content: center;
            }
        </style>
    </head>
    <h2 class="major" style="padding: 15px;">Control the Car!</h2>      <!-- MODIFIED - SHAHMIZAN -->
    <body style="padding: 15px; float:none;">                           <!-- MODIFIED - SHAHMIZAN -->

        <div class="container">

            <!-- 1st Column -->
            <div style="position: relative; float:left;">
                <ul id = "instructionsList" style="font-size: 20px;">
                    <li draggable="true">Move Forward</li>
                    <li draggable="true">Move Backward</li>
                    <li draggable="true">Turn Right</li>
                    <li draggable="true">Turn Left</li>
                    <li draggable="true">Loop</li>
                </ul>
		        <a href="/" id="homeBtn" class="button primary" draggable="false">☰ Home</a>   <!-- ADDED - SHAHMIZAN -->
            </div>

            <!-- 2nd Column -->
            <div name = "fullNamesContainer" style="position: relative; margin-left: 50px; float:left;">
                <form action="/sendInstructions" method="post">
                    <form action="/action_page.php">
                    <textarea id="instructions" name="message" rows="10" cols="30"></textarea>      <!-- ADDED (id) - SHAHMIZAN -->
                    <input type="submit" class="button primary" value="Send!">
                    <input type="button" value="Clear" onclick="eraseText();">                      <!-- MODIFIED (onclick) - SHAHMIZAN -->
                </form>
            </div>

            <!-- 3rd Column -->                                                                     <!-- OMITTED - SHAHMIZAN -->
            <!--<div style="float:left;">
                <img src="static/mazes/440011.png" align="middle" style="margin-left:auto; margin-right: auto; margin-top: auto; margin-bottom: auto;"/>
            </div>-->

            <script type="text/javascript" src="{{ url_for('static', filename='jquery.min.js') }}"></script>
            <script type="text/javascript" src="{{ url_for('static', filename='copy.js') }}"></script>

        </div>
    </body>
</html>
