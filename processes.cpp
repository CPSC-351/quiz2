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
	pid_t c3, c4;
	fprintf(stderr, "I am child1 pid=%d; my parent is pid=%d\n", getpid(), getppid());

  c3 = fork();

	if (c3 == 0)
	{
		sleep(3);
		child3();
		exit(0);
	}

  c4 = fork();

	if (c4 == 0)
	{
		sleep(4);
		child4();
		//exit(0);
	}

	else
	{
		wait(NULL);
		sleep(1);
	}

}
/**
 * The function called by the SECOND child.
 */
void child2()
{
	pid_t c5, c6;
	fprintf(stderr, "I am child2 pid=%d; my parent is pid=%d\n", getpid(), getppid());

	c5 = fork();

	if (c5 == 0)
	{
		sleep(5);
		child5();
		exit(0);
	}

	c6 = fork();
	sleep(1);

	if (c6 == 0)
	{
		sleep(5);
		child6();
		//exit(0);
	}

	else
	{
		wait(NULL);
		sleep(1);
	}
}

/**
 * The function called by the THIRD child.
 */
void child3()
{
	//pid_t c3pid;
	//c3pid = fork();
	fprintf(stderr, "I am child3 pid=%d; my parent is pid=%d\n", getpid(), getppid());
	wait(NULL);
	sleep(1);
}

/**
 * The function called by the FOURTH child.
 */
void child4()
{
	getpid();
	//pid_t c4pid;
	//c4pid = fork();
	fprintf(stderr, "I am child4 pid=%d; my parent is pid=%d\n", getpid(), getppid());
	wait(NULL);
	sleep(1);
}


/**
 * The function called by the FIFTH child.
 */
void child5()
{

	fprintf(stderr, "I am child5 pid=%d; my parent is pid=%d\n", getpid(), getppid());
}
/**
 * The function called by the SIXTH child.
 */
void child6()
{
	fprintf(stderr, "I am child6 pid=%d; my parent is pid=%d\n", getpid(), getppid());
}
/**
 * The function called by the parent
 */
void parent()
{
	pid_t c1, c2;
	fprintf(stderr, "I am the original parent; my process ID is pid=%d\n", getpid());
  c1 = fork();

	if (c1 == 0)
	{
		sleep(1);
		child1();
		sleep(1);
		exit(0);
	}

  c2 = fork();
	sleep(2);

	if (c2 == 0)
	{
		child2();
	}


	else
	{
		wait(NULL);
		sleep(1);
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
