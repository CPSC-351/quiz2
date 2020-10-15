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

/**
 * The function called by the FIRST child.
 */
void child1()
{
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
	
	//TODO: Fill me in
	//Create child processes child 3 and child 4
	//Wait for them to terminate	
	if(fork()==0)
	{
	 child3();
	 child4();
 	}

	/* Wait for the child to exit */
		if(wait(NULL) < 0)
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
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
	
	//TODO: Fill me in
	//Create child processes child 5 and child 6	
	if(fork()==0)
	{
	 child5();
	 child6();
	}
	/* Wait for the child to exit */
		if(wait(NULL) < 0)
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
	fprintf(stderr, "I am the original parent; my process ID is pid=%d\n", getpid());
	if (fork() == 0)
	{
	 child1();
	 child2();
	}
	else 
	{
	  if(wait(NULL)<0)
	  {
		perror("wait);
		exit(-1);
	  }
	}
}


/**
 * The main function
 */
int main()
{
	parent();	
}
