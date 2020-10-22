# CPSC 351-Quiz 2
<b>Team Members:</b><br>
 Robert Kenny - rlkenny@csu.fullerton.edu<br>
 Dustin Vuong - dhvuong@csu.fullerton.edu<br>
 Tiffanny Hernaez - tiffannyhernaez@csu.fullerton.edu<br>
 Sagar Joshi - sagar0698@csu.fullerton.edu<br>
 Stephanie Casillas - stepc25@csu.fullerton.edu<br>
 
 We utilized fork() and wait() UNIX process management system calls by creating seven processes that have the parent-child relationships shown in the diagram below:
 ![image](https://user-images.githubusercontent.com/55200206/96838907-55149d00-13fd-11eb-8f12-73658fcca24f.png)

<b>For this program we used: C++<b>
 
 In this diagram:
 * the parent process creates child processes <b>Child1<b> and <b>Child2<b> (using fork()) and then waits for both to terminate (using wait())
 * <b>Child1<b> creates child processes <b>Child3<b> and <b>Child4<b> and waits for both to terminate
 * <b>Child2<b> creates child processes <b>Child5<b> and <b>Child6<b> and waits for boht to terminate

## Execution, copy and paste this:
`git clone https://github.com/CPSC-351/quiz2.git`

## Then run the program on Tuffix using:
`g++ processes.cpp -o process`

`./process`
