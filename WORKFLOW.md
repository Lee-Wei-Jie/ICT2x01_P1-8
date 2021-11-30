# WORKFLOW OF PROJECT
1. `master` branch will be our *baseline* branch for pull request of both `mastercar` and `masterwebpage`
2. `mastercar` branch and `masterwebpage` branch are the *baseline* branches for both the car development and web development
3. Any developments to either the `mastercar` or `masterwebpage` will mean that you need to first branch off from them respectively. Then when your branch is working, you can merge it into the `mastercar` or `masterwebpage`.
   1. Every member shall branch off of each parent from both `devcar` and `devwebpage` respectively (illustrated below)
   2. Off the branch, the any development of code and project shall be placed into a single folder
      1. This is because later on when merging into the `master`, we can have them separate as 2 folders so there will not be anything conflicting
4. At any time, there should be the same number of pull request to `mastercar` and `masterwebpage`. Both of which shall only be the working copies and same iteration (and finalized to be baseline).
5. Hierarchy breakdown are as such:
   1. `master`
      1. `mastercar`
         1. `devcar`
            1. member branch
            2. member branch
      2. `masterwebpage`
         1. `devwebpage`
            1. member branch
            2. member branch

