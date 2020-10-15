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
}

/**
 * The function called by the SECOND child.
 */
void child2()
{
	fprintf(stderr, "I am child pid=%d; my parent is pid=%d\n", getpid(), getppid());
	
	//TODO: Fill me in	

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
	
}


/**
 * The main function
 */
int main()
{
	parent();	
}
