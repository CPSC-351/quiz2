#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/* The prototypes */
void parent();
void child1();
void child2();
void child3();
void child4();
void child5();
void child6();
/*
 * The function called by the FIRST child.
 */
void child1()
{
	pid_t c1pid1,c1pid2;
	fprintf(stderr, "I am child 1 pid=%d; my parent is pid=%d\n", getpid(), getppid());
	//TODO: Fill me in
	//Create child processes child 3 and child 4
	//Wait for them to terminate
	c1pid2 = fork();
	if(c1pid2==0){
		child4();
	}
	else if (c1pid2>0){
		c1pid1 = fork();
		if(c1pid1<0){
			perror("fork");
			exit(-1);
		}
		else if(c1pid1==0){
			//usleep(1000);
			child3();
		}
	}
}
/**
 * The function called by the SECOND child.
 */
void child2()
{
	pid_t c2pid1,c2pid2;
	fprintf(stderr, "I am child 2 pid=%d; my parent is pid=%d\n", getpid(), getppid());

	c2pid2 = fork();
	if(c2pid2==0){
		child6();
	}
	else if (c2pid2>0){
		c2pid1 = fork();
		if(c2pid1<0){
			perror("fork");
			exit(-1);
		}
		else if(c2pid1==0){
			//usleep(1000);
			child5();
		}
	}

}

/**
 * The function called by the THIRD child.
 */
void child3()
{
	fprintf(stderr, "I am child 3 pid=%d; my parent is pid=%d\n", getpid(), getppid());
}

/**
 * The function called by the FOURTH child.
 */
void child4()
{
	fprintf(stderr, "I am child 4 pid=%d; my parent is pid=%d\n", getpid(), getppid());
}


/**
 * The function called by the FIFTH child.
 */
void child5()
{

	fprintf(stderr, "I am child 5 pid=%d; my parent is pid=%d\n", getpid(), getppid());
}
/**
 * The function called by the SIXTH child.
 */
void child6()
{
	fprintf(stderr, "I am child 6 pid=%d; my parent is pid=%d\n", getpid(), getppid());
}
/**
 * The function called by the parent
 */
void parent()
{
	pid_t pid1, pid2;
  fprintf(stderr, "I am the original parent; my process ID is pid=%d\n", getpid());


	pid2 = fork();
	if(pid2==0){
		child2();
	}
	else if (pid2>0){
		pid1 = fork();
		if(pid1<0){
			perror("fork");
			exit(-1);
		}
		else if(pid1==0){
			child1();
		}
	}
}
/**
 * The main function
 */
int main()
{
	parent();
	return 0;
}
