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
---

### USER ACCEPTANCE TESTING

### System Test Case 1

### System Test Case 5
- ST5 test for page redirection after a user enters the webpage and click on the play button, the page will redirct user to the play state, which should show the game screen.

![ST5 - Redirect Page to Play](/img/tests/ST5.gif)

### System Test Case 6

### System Test Case 7

### System Test Case 8

### System Test Case 9

### Login
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


## White-box Testing
---

First, ensure that you are in the ```Webpage``` folder.

Ensure that the virtual environment is activated to be used as pytest is saved in venv.

You can run the test using this command:
```
pytest -v
```

### Full Test Suite testing all endpoints and functions

![Whitebox Testing - Success](/img/tests/whitebox-testing-allfunctions.gif)



<p align="center">
  <img src="https://thumbs.gfycat.com/UltimateBlandCrane-size_restricted.gif" alt="Car" />
</p>


# Reflections
## Crystal Choo Jia Xian (BS006)
<to do>
  
## Koh Jia Cheng (BS005)
<to do>
  
## Lee Wei Jie (BS005)
<to do>
  
## Mohammad Shahmizan Bin Sham Affandi (BS006)
<to do>

