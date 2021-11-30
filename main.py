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


@app.route('/sendInstructions', methods = ['POST','GET'])
def getdata():
   if request.method == 'POST':
      command = request.form['message']
      mylist.append(str(command))
      return "Command==" + mylist[-1] + ".\r\n"
   else:
      return "Command==" + mylist[-1] + ".\r\n"

#pc have to be connected to same network as wifi module, 192.168.43.241 is my ipv4 address aka ip for hosted app.(to test sending of command to car)
# app.run(host="192.168.43.241",port="80",debug=True)

#for local testing purposes(testing for web only)
app.run(debug=True)



