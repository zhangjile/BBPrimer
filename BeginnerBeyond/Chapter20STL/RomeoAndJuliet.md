## problem: display RomeoAndJuliet with each line numbered, leave out the blank lines.

There's a bug in the first implementation, in which the blank lines are also numbered, even though the logic to check blank lines are deployed.
The reason for that is, there's loophole somewhere in the logic which results that the blank lines are actually not correctly checked.
This bug has remained for half a year. I blamed imperfection of Mobile C for it. Days ago when I ran the code in CodeLite and VS code on desktop USING Ubuntu OS, the problem persisted. I know the bug exists in the os.