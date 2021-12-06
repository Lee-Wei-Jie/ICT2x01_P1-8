<p align="center">
  <img src="https://thumbs.gfycat.com/IdenticalFarawayAfricangoldencat-size_restricted.gif" alt="Car" />
</p>

# ICT2x01 Intro. to Software Engineering
Singapore Institute of Technology
## Meet the Team
- Crystal Choo Jia Xian (BS006)
- Koh Jia Cheng (BS005)
- Lee Wei Jie (BS005)
- Mohammad Shahmizan Bin Sham Affandi (BS006)

## Car Demonstration
![Car Demo](/img/tests/P2_T7_DemoNew.mp4)

# Getting Started
## Dependencies
- Flask 
- Python >= 3.7.1

### Installation Guide 
1. Clone the repository
```
git clone https://github.com/Guthixo/ICT2x01_P1-8.git
```
![GitClone - git clone the repository](/img/tests/gitClone.gif)

2. Download the necessary python version available
3. In the command prompt, enter "pip install flask" followed by enter key
```
pip install flask
```
4. hange the directory of the cloned project in command prompt and enter "cd Webpage" to go into the directory of the Webpage. To start hosting the webpage, enter "python .\main.py" OR click on the "run" button.
```
cd Webpage
python .\main.py
```

# Workflow
1. `master` branch will be our *baseline* branch for pull request of both `mastercar` and `masterwebpage`
2. `mastercar` branch and `masterwebpage` branch are the *baseline* branches for both the car development and web development
3. Any developments to either the `mastercar` or `masterwebpage` will mean that you need to first branch off from them respectively. Then when your branch is working, you can merge it into the `mastercar` or `masterwebpage`.
   1. Every member shall branch off of each parent from both `devcar` and `devwebpage` respectively (illustrated below)
   2. Off the branch, the any development of code and project shall branched if necessary
4. At any time, the latest commit to `mastercar` and `masterwebpage` will be the baseline of the branch. Both of which shall only be the working copies and same iteration
5. Hierarchy breakdown are as such:
   1. `master`
      1. `mastercar`
            1. `devcar`
      2. `masterwebpage`
         1. `devwebpage`

### Branches

1. Branch Naming Conventions
The branch name must follow hierarchical branch that the team have already worked out on in the WORKFLOW.md

2. Branching Conventions
New features / fixes should be **branched off** the respective development branches if needed

1. Merging Conventions
*Code committed -> Code reviewed -> Code merged into `master` branch -> Baseline* 
Committed code should be properly reviewed by another party of the team. 
Request for a pull, before merging from the new branch to the respective development branches.

# Testing
- Black Box Testing
   - UAT
   - Login
      - No Pin Specified
      - Wrong PIN Specified
      - Maximum Limit Exhausted (PIN Lockout)
      - Login Attempt After Maximum Limit Exhausted (PIN Lockout)
      - Clear Field
      - Successfully Logged-in


- White Box Testing
   - A full test suite using pytest library testing for 
     - Accessing 
       - Home page
       - Play page
         - Splitline function
         - Splitline adapter design function
         - With wrong instructions
         - With correct instructions
         - Witn no instructions
       - Challenge page
       - Design page
       - List page


## Black Box Testing

### USER ACCEPTANCE TESTING
---
<table>
  <tr>
    <td>ID</td>
    <td>State Test</td>
    <td>Actual Results</td>
    <td>Pass✔ / N.A.</td>
  </tr>
  <tr>
    <td>1</td>
    <td><img src="/img/tests/ST1.jpg"/></td>
    <td><img src="/img/tests/ST1.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>2</td>
    <td><img src="/img/tests/ST2.jpg"/></td>
    <td><img src="/"/></td>
    <td>N.A.</td>
  </tr><tr>
    <td>3</td>
    <td><img src="/img/tests/ST3.jpg"/></td>
    <td><img src="/"/></td>
    <td>N.A.</td>
  </tr><tr>
    <td>4</td>
    <td><img src="/img/tests/ST4.jpg"/></td>
    <td><img src="/"/></td>
    <td>N.A.</td>
  </tr><tr>
    <td>5</td>
    <td><img src="/img/tests/ST5.jpg"/></td>
    <td><img src="/img/tests/ST5.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>6</td>
    <td><img src="/img/tests/ST6.jpg"/></td>
    <td><img src="/img/tests/ST6.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>7</td>
    <td><img src="/img/tests/ST7.jpg"/></td>
    <td><img src="/img/tests/ST7.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>8</td>
    <td><img src="/img/tests/ST8.jpg"/></td>
    <td><img src="/img/tests/ST8.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>9</td>
    <td><img src="/img/tests/ST9.jpg"/></td>
    <td><img src="/img/tests/ST9.gif"/></td>
    <td>✔</td>
  </tr>
</table>

<!--
### System Test Case 1
![ST1 - Starting the Webpage](/img/tests/ST1.jpg)
- ST1 tests if user are able to access the localhost webpage.

![ST1 - Starting the Webpage](/img/tests/ST1.gif)

### System Test Case 5
- ST5 test for page redirection after a user enters the webpage and click on the play button, the page will redirct user to the play state, which should show the game screen.

![ST5 - Redirect Page to Play](/img/tests/ST5.gif)

### System Test Case 6
- ST6 test for the ability to drag and drop commands to a provided dropbox to send to the car on the webpage. Once user hits 'Send!', commands in the dropbox would be sent to the car.

![ST6 - Drag & Drop Commands to send to Car](/img/tests/ST6.gif)

### System Test Case 7
- ST7 test for user setting up instructions to send to the car. When the user press 'Sent!', the screen is suppose to be the commands sending through.

![ST7 - Set Instructions to send to the Car](/img/tests/ST7.gif)

### System Test Case 8
- ST8 test if user is able to enter the homapage using dedicated home button.

![ST9 - Terminated the web application](/img/tests/ST8.gif)

### System Test Case 9
- ST9 test if user is able to exit the app.

![ST9 - Terminated the web application](/img/tests/ST9.gif)
-->

### LOGIN
---
<table>
  <tr>
    <td>Test Case</td>
    <td>Actual Results</td>
    <td>Pass✔ / Fail❌</td>
  </tr>
  <tr>
    <td>No PIN Specified</td>
    <td><img src="/img/tests/login-no-pin.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>Wrong PIN Specified</td>
    <td><img src="/img/tests/login-wrong-pin.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>Maximum Limit Exhausted (PIN Lockout)</td>
    <td><img src="/img/tests/login-max-attempts.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>Login Attempt After Maximum Limit Exhausted (PIN Lockout)</td>
    <td><img src="/img/tests/login-post-limit-attempt.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>Clear Field</td>
    <td><img src="/img/tests/login-clear-fields.gif"/></td>
    <td>✔</td>
  </tr><tr>
    <td>Successfully Logged-in</td>
    <td><img src="/img/tests/login-success.gif"/></td>
    <td>✔</td>
</table>

<!--
- No PIN Specified

![Login Test - No PIN](/img/tests/login-no-pin.gif)

- Wrong PIN Specified

![Login Test - Wrong PIN](/img/tests/login-wrong-pin.gif)

- Maximum Limit Exhausted (PIN Lockout)

![Login Test - Max Attempts](/img/tests/login-max-attempts.gif)

- Login Attempt After Maximum Limit Exhausted (PIN Lockout)

![Login Test - Post Max Attempts](/img/tests/login-post-limit-attempt.gif)

- Clear Field

![Login Test - Clearing Field](/img/tests/login-clear-fields.gif)

- Successfully Logged-in

![Login Test - Success](/img/tests/login-success.gif)
-->

## White-box Testing

First, ensure that you are in the ```Webpage``` folder.

Ensure that the virtual environment is activated to be used as pytest is saved in venv.
![Whitebox Testing venv](/img/tests/whitebox-testing-venv.PNG)

All the test are run through in this python file: ```Webpage/test_fullsuite.py```

You can refer to the pytest [documentation](https://docs.pytest.org/en/6.2.x/contents.html "here").

<add the env examples>

You can run the test using this command to:

```
pytest -v
```
![Whitebox Testing Pytest](/img/tests/whitebox-testing-allfunctions.gif)

----
You can refer to the pytest [documentation](https://coverage.readthedocs.io/en/6.2/) to get the coverage whereby you can then view it in a html file by opening it on a browser:
```
py.test test_fullsuite.py --cov=main --cov-report=html
```
![Whitebox Testing Coverage](/img/tests/whitebox-testing-coverage.gif)


### Coverage Report
---
![Whitebox Testing Coverage](/img/tests/whitebox-testing-coveragereport.PNG)

![Whitebox Testing Coverage 20](/img/tests/whitebox-testing-coveragereport-20.PNG)

For the ```getdata()```, we are unable to generate a test case using codes as because of the nature of the coding structure. The function utilizes variables **locally** to the function and is **not parametrized**, hence we are not able pass the correct information to perform a test.

We then used another application to test out this function's coverage. There are only ```3 branches``` to be covered. They are:
- POST 
  - Line ```46-51```
  - POST-ing data (can be any data)
- GET (with data)
  - Line ```53-55```
  - GET-ing the data (will retrieve the data POSTed before this)
- GET (without data)
  - Line ```56```
  - GET-ing the data again (will retrieve no data because it has been retrieved)

As seen below, we will use Postman for these final few coverage (all of which is reflected accordingly):

![Whitebox Testing Coverage 20](/img/tests/coverage%20report%2020%20postman.gif)


# Issues Identified
Some issues identified throughout the entire project were due to the scheduling (timetable) of both Information Security and Software Engineering students. As both courses were very busy with each of their relative assessments and assignments, it is very difficult to meet up and complete the project. The timings of both of our classes were also clashing, making it even more difficulty to hold weekly in person meetings to complete the project. As the main objective of this project is to include commands to send to the web page to guide users to solve challenges while teaching critical problem solving and computational thinking skills, our main focus was to ensure commands can be sent from the webpage to the car, which was completed. 


# Reflections
## Crystal Choo Jia Xian (BS006)
In Milestone 3, all the requirements for both Milestones 1 and 2 were put into consideration during the building process of the product for the client. In this Milestone 3, I learned that it is not easy to keep up with a SE project, satisfying all the requirements for a client within the client's deadline. Most of the requirements were difficult to fulfil due to the clashing of schedules SE and IS students. In addition, as the IS solely focuses on the software, we have no idea how the hardware is going to merge with the software created, thus making integrating very difficult. A lot of research had to be done in order to have a functional part in the project.

In conclusion, this project widens my knowledge on Software Engineering with all the detailed SRS that is needed with the estimation time and cost before the project even begins, and how all the details help in the implementation of the codes in the later part of the project to prevent wastage of time and cost, while cost was not part of this project, it is obvious that time was wasted in our project due to the lack of considering of merging software with the hardware.
  
## Koh Jia Cheng (BS005)
I have learnt many different technical abilities from this milestone. As I was the one who tackled the portion on the Whitebox Testing, so I had to incorporate all the different libraries into the current application and make sure I am able to run them in the virtual environment to test the different features and coverage of the code. The initial startup to learn and integrate all the different libraries and also to used them proved to be a very tedious challenge as I have to be able to stimulate the different test conditions for the functions that is in the main file. This mean scouring the internet for documenation, stackoverflow etc to search for some obscure errors.

This have made me learned the different competencies when it comes to whitebox testing such as using the libraries to perform comprehensive coverage for the system. These which I hope to remember in time to come for my future use next time when necessary because it was a lot of sequence of actions to do before I manage to get everything working.

The project has taught many other intricacies such as using github and also following a developmental flow to finally create this application. This could be applied to the real world scenarios next time where there is also a good chance that people use github and also follow similar workflow as well. Having a more familiar flow which I can look back to and grasp and idea of is really comforting in the grand scheme of things. Though we cannot be fully prepared for what's to come, I think this has shed quite some good light on how Software Engineering works.
  
## Lee Wei Jie (BS005)
For Milestone 3, we’ve worked together, and applied concepts learnt from various modules. From this milestone, we are given the opportunity to practise Blackbox testing, Whitebox testing, software configuration management through GitHub and many other techniques taught.
  
Through this project, I’ve learnt the importance of design planning, prototyping, timing estimation, software development techniques, testing methods and many more. It is crucial to apply all this techniques hand in hand when it comes to software development to ensure our plan is feasible and achievable.
  
Although this project is a good exposure for us to apply concepts taught and for us to develop a project in the manner we want, I felt that more guidance should be given to allow students to understand what is “not do-able”. By combining 2  modules together to develop a project is rather challenging as students are expected to know how to bridge connections between provided hardware to our developed webpage as well as tools required to ensure workability(which none are taught). As a result, most of us are left researching on our own to look for ways to meet the client’s requirements(and there are some that could not be met), which I feel is unfair to be graded based on it.
  
I personally feel that this project will be fun, enjoyable and a great learning experience if more help and time could be provided. 

  
## Mohammad Shahmizan Bin Sham Affandi (BS006)
The progress I made on this Milestone 3 was definitely not up to the standards of the previous Milestones. My expertise was lacking, the team's motivation was low, and with such high expectations, the stars were never aligned from the start.

Between conducting research on how to make something work, aligning to the Software Engineering principles taught, all while trying to satisfy the deliverables of the client, lies my team stretched thin.

Overall this project was truly an experience to show the strains of a typical Software Engineering project process. Making references back to the first few weeks of Professor Alex's lectures, I am finally able to wrap my head around the reality on the success, but more particularly the failure rates of high-profile SE projects. Whatever the outcome of this project / Milestone, it's all part of the learning process. <i> - Shahmizan </i>


<p align="center">
  <img src="https://thumbs.gfycat.com/UltimateBlandCrane-size_restricted.gif" alt="Car" />
</p>
