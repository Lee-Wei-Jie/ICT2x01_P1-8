# WORKFLOW OF PROJECT
1. `master` branch will be our *baseline* branch for pull request of both `mastercar` and `masterwebpage`
2. `mastercar` branch and `masterwebpage` branch are the *baseline* branches for both the car development and web development
3. Any developments to either the `mastercar` or `masterwebpage` will mean that you need to first branch off from them respectively. Then when your branch is working, you can merge it into the `mastercar` or `masterwebpage`.
   1. We will only be doing 1 branch off of each parent into both `devcar` and `devwebpage` respectively (illustrated below)
4. At any time, there should be the same number of pull request to `mastercar` and `masterwebpage`. Both of which shall only be the working copies and same iteration (and finalized to be baseline).
5. Hierarchy breakdown are as such:
   1. `master`
      1. `mastercar`
         1. `devcar`
      2. `masterwebpage`
         1. `devwebpage`

