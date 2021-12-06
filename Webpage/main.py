from flask import Flask, redirect, url_for, render_template, request
from flask_restful import Resource, Api
app = Flask(__name__)
mylist = []

@app.route('/')
def home():
   return render_template('index.php')

@app.route('/play')
def play():
   return render_template('play.php')

@app.route('/challenge')
def challenge():
   return render_template('challenge.php')

@app.route('/design')
def design():
   return render_template('design.php')

@app.route('/list')
def list():
   return render_template('list.php')

#function to split lines  
def splitLines(instr):
   lines = instr.split('\r\n')
   string = " "
   for i in lines:
      if i == 'Move Forward':
         string += "F"
      if i == 'Move Backward':
         string += "B"
      if i == 'Turn Right':
         string += "R"
      if i == 'Turn Left':
         string += "L"
   if string == " ":
      return "invalid"
   return string

@app.route('/sendInstructions', methods = ['POST','GET'])
def getdata():
   global getflag
   if request.method == 'POST':
      instructions = request.form['message']
      commands = splitLines(instructions)
      mylist.append(str(instructions))
      #print(mylist, file=sys.stderr)
      return "Command==" + commands + "."
   else:
      if getflag == 1:
         getflag = 0
         return "Command==" + mylist[-1] + ".\r\n" # I cant print commands here unless I call the function so I leave it as myList
      return "Command== None."

#pc have to be connected to same network as wifi module, 192.168.43.241 is my ipv4 address aka ip for hosted app.(to test sending of command to car)
# app.run(host="192.168.43.241",port="80",debug=True)

#for local testing purposes(testing for web only)
app.run(debug=True)



