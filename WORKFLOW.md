# WORKFLOW OF PROJECT
1. `master` branch will be our *baseline* branch for pull request of both `mastercar` and `masterwebpage`
2. `mastercar` branch and `masterwebpage` branch are the *baseline* branches for both the car development and web development
3. Any developments to either the `mastercar` or `masterwebpage` will mean that you need to first branch off from them respectively. Then when your branch is working, you can merge it into the `mastercar` or `masterwebpage`.
   1. Every member shall branch off of each parent from both `devcar` and `devwebpage` respectively (illustrated below)
   2. Off the branch, the any development of code and project shall branched if necessary
4. At any time, the latest commit to `mastercar` and `masterwebpage` will be the baseline of the branch. Both of which shall only be the working copies and same iteration
   1. It the contents of these files should be in a folder to facilitate merging of both the branch later during a pull request into the `master`
5. Hierarchy breakdown are as such:
   1. `master`
      1. `mastercar`
            1. `devcarmember`
            2. `devcarmember`
      2. `masterwebpage`
         1. `devwebpage`
            1. `devcarmember`
            2. `devcarmember`

