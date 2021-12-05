<!DOCTYPE HTML>
<!--
	Dimension by HTML5 UP
	html5up.net | @ajlkn
	Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
	Edited by: Mohammad Shahmizan
-->
<html>
	<head>
		<title>ICT2x01 Dashboard</title>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
		<link rel="stylesheet" href="static/assets/css/main.css" />
		<noscript><link rel="stylesheet" href="static/assets/css/noscript.css" /></noscript>
                
                <script src="static/jquery.min.js"></script>
                <script type="text/javascript">
                    function connectToNetwork(){
                        $.get("http://192.168.1.44:80/", {});
                    }
                </script>

	</head>
	<body class="is-preload">

		<!-- Wrapper -->
			<div id="wrapper">

				<!-- Header -->
					<header id="header">
						<div class="logo">
							<span class="icon fa-gem"></span>
						</div>
						<div class="content">
							<div class="inner">
								<h1>ICT2x01 Web Dashboard</h1>
								<p>The dashboard to control the car!</p>
							</div>
						</div>
						<nav>
                                                    <ul>
                                                        <li><a href="#play">Play</a></li>
                                                        <li><a href="#challenge">Challenge</a></li>
                                                        <li><a href="#design">Design</a></li>
                                                        <li><button class="button primary" onclick="connectToNetwork()">Connect</button></li>
                                                    </ul>
						</nav>
					</header>

				<!-- Main -->
					<div id="main">

						<!-- Play -->
							<article id="play">
								<h2 class="major">Let's Play!</h2>
								<!--<span class="image main"><img src="images/pic01.jpg" alt="" /></span>-->
								<p>Welcome to the webpage! </p>
								<p>This section refers to the first feature of the webpage, which allows free control over the car's movement! You may also take this opportunity as a form of a tutorial, to get to know the controls available for the car on the page, before tackling on the challenges!</p>
								<p><a href="/play" class="button">Play!</a></p>
							</article>

						<!-- Challenge -->
							<article id="challenge">
								<h2 class="major">Ready for a Challenge?</h2>
								<!--<span class="image main"><img src="images/pic02.jpg" alt="" /></span>-->
								<p>Let's get to work!</p>
								<p>In here, users will get the chance to put on your thinking cap, and try to take a shot on some challenges set by us, or even your teachers!</p>
								<p>What are you waiting for?</p>
								<a href="/challenge" class="button">Let's do this!</a>
							</article>

						<!-- Design -->
							<article id="design">
								<h2 class="major">Design</h2>
								<!--<span class="image main"><img src="images/pic03.jpg" alt="" /></span>-->
								<p>Have your own idea of a maze?</p>
								<p>This section is meant for teachers, testers and anyone eager to create their own set of challenges!</p>
								<div class="container">
									<a href="#login" class="button">Create your challenges here!</a>
								</div>
							</article>
							
                                                <!-- Connect  -->
							<article id="connect">
								<h2 class="major">Connect</h2>
								<!--<span class="image main"><img src="images/pic03.jpg" alt="" /></span>-->
								<p>Is the car powered on?</p>
								<p></p>
								<div class="container">
									<a href="#login" class="button">Connect!</a>
								</div>
							</article>
                                                
						<!-- Login -->
							<article id="login">
								<h2>Enter your Design PIN</h2>
								<form name="login">
									<input id="pin" type="password" name="pin" placeholder="Enter PIN"><br>
									<div style="text-align: center">
										<input id="submitBtn" type="button" class="button primary" onclick="check(this.form)" value="Login"/>
										<input id="resetBtn" type="reset" class="button" value="Clear fields"/>
									</div>
								</form>
							</article>
							<script language="javascript">
						        	var attempts = 5;
								
								function check(form) {
								    var pinObject = document.getElementById("pin")
								    var hashObject = new jsSHA("SHA-512", "TEXT", {numRounds: 1})
								    hashObject.update(pinObject.value);
								    var hash = hashObject.getHash("HEX")
								    pinObject.value = hash;

								    if(pinObject.value === "7fcf4ba391c48784edde599889d6e3f1e47a27db36ecc050cc92f259bfac38afad2c68a1ae804d77075e8fb722503f3eca2b2c1006ee6f6c7b7628cb45fffd1d") {
									window.location = '/design'
								    }
								    else {
									attempts--
									if (attempts > 0){
									    alert("Incorrect PIN. Attempts remaining: " +attempts+ ". Please re-enter.")
									}
									else {
									    alert("Access Denied! PIN is incorrect! 0 attempts left.")
									    document.getElementById("pin").disabled = true
									    document.getElementById("submitBtn").disabled = true
									    document.getElementById("resetBtn").disabled = true
									}
								    }
								}
						    	</script>
					</div>

				<!-- Footer -->
					<footer id="footer">
						<p class="copyright">&copy; P1 Team 8. Design: <a href="https://html5up.net">HTML5 UP</a>.</p>
					</footer>

			</div>

		<!-- BG -->
			<div id="bg"></div>

		<!-- Scripts -->
			<script src="static/assets/js/jquery.min.js"></script>
			<script src="static/assets/js/browser.min.js"></script>
			<script src="static/assets/js/breakpoints.min.js"></script>
			<script src="static/assets/js/util.js"></script>
			<script src="static/assets/js/main.js"></script>
			<script src="https://cdnjs.cloudflare.com/ajax/libs/jsSHA/2.0.2/sha.js"></script>

	</body>
</html>
