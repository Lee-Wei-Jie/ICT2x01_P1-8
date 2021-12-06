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

# Getting Started
### Car

### Webpage

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

- Car Demonstration


## Black Box Testing

### USER ACCEPTANCE TESTING
---
<table>
  <tr>
    <td>ID</td>
    <td>State Test</td>
    <td>Actual Results</td>
    <td>Pass✔/Fail❌</td>
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
    <td>❌</td>
  </tr><tr>
    <td>3</td>
    <td><img src="/img/tests/ST3.jpg"/></td>
    <td><img src="/"/></td>
    <td>❌</td>
  </tr><tr>
    <td>4</td>
    <td><img src="/img/tests/ST4.jpg"/></td>
    <td><img src="/"/></td>
    <td>❌</td>
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
    <td>Pass✔/Fail❌</td>
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

Alternatively, you can use to get the coverage whereby you can then view it in a html file by opening it on a browser:
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
- GET (with data)
  - Line ```53-55```
- GET (without data)
  - Line ```56```







<p align="center">
  <img src="https://thumbs.gfycat.com/UltimateBlandCrane-size_restricted.gif" alt="Car" />
</p>

# Issues Identified
Some issues identified throughout the entire project were due to the scheduling (timetable) of both Information Security and Software Engineering students. As both courses were very busy with each of their relative assessments and assignments, it is very difficult to meet up and complete the project. The timings of both of our classes were also clashing, making it even more difficulty to hold weekly in person meetings to complete the project. As the main objective of this project is to include commands to send to the web page to guide users to solve challenges while teaching critical problem solving and computational thinking skills, our main focus was to ensure commands can be sent from the webpage to the car, which was completed. 

## Car Demonstration
![Car Demo](/img/tests/P2_P7_Demo(New).avi)

# Reflections
## Crystal Choo Jia Xian (BS006)
<to do>
  
## Koh Jia Cheng (BS005)
<to do>
  
## Lee Wei Jie (BS005)
<to do>
  
## Mohammad Shahmizan Bin Sham Affandi (BS006)
<to do>

