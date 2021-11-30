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
            }
            li{
                margin-top:10px;
            }
        </style>
    </head>
    <h2 class="major">Control the Car!</h2>
    <body style="padding: 15px;">
        
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
            </div>

            <!-- 2nd Column -->
            <div name = "fullNamesContainer" style="position: relative; margin-left: 50px; float:left;">
                <form action="/sendInstructions" method="post">
                    <form action="/action_page.php">
                    <textarea name="message" rows="10" cols="30">
                    </textarea>
                    <input type="submit" class="button primary" value="Send!">
                    <input type="button" value="Clear" onclick="javascript:eraseText();">
                </form>
            </div>

            <!-- 3rd Column -->
            <div style="float:left;">
                <img src="static/mazes/440011.png" align="middle" style="margin-left:auto; margin-right: auto; margin-top: auto; margin-bottom: auto;"/>
            </div>


            <script type="text/javascript" src="{{ url_for('static', filename='jquery.min.js') }}"></script>
            <script type="text/javascript" src="{{ url_for('static', filename='copy.js') }}"></script>
            
        </div>
    </body>
</html>