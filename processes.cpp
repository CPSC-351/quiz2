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
	pid_t child1pid;
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
	child1pid = fork();
	//TODO: Fill me in
	//Create child processes child 3 and child 4
	//Wait for them to terminate
	if(child1pid<0)
	{
		perror("fork");
		exit(-1);
	}
	if(child1pid==0)
	{
	 child3();
	 //child4();
 	}
	else
	if(wait(NULL)<0)
	{
		perror("wait");
		exit(-1);
	}
}
/**
 * The function called by the SECOND child.
 */
void child2()
{
	pid_t child2pid;
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
	child2pid = fork();

	//TODO: Fill me in
	//Create child processes child 3 and child 4
	//Wait for them to terminate
	if(child2pid<0)
	{
		perror("fork");
		exit(-1);
	}
	if(child2pid==0)
	{
	 child5();
	 //child6();
	}
	else
		if(wait(NULL)<0)
		{
		perror("wait");
		exit(-1);
		}
}

/**
 * The function called by the THIRD child.
 */
void child3()
{
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
}

/**
 * The function called by the FOURTH child.
 */
void child4()
{
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
}


/**
 * The function called by the FIFTH child.
 */
void child5()
{

	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
}
/**
 * The function called by the SIXTH child.
 */
void child6()
{
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
}
/**
 * The function called by the parent
 */
void parent()
{
	pid_t pid;
	fprintf(stderr, "I am the original parent; my process ID is pid=%d\n", getpid());

  pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(-1);
	}

	if (pid == 0)
	{
	 child1();
	}
	//if (pid == 0)
	 //child2();

	else
	 if(wait(NULL)<0)
	 {
		 perror("wait");
		 exit(-1);
	 }
	//else
   //wait(NULL);
}
/**
 * The main function
 */
int main()
{
	parent();
	return 0;
}
