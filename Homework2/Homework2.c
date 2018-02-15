#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void program_alarm(int sig);

int main()
{
	FILE *fp;
	filename="output.csv";
	fp=fopen(filename,"w+");

	printf("Creating and opening output.csv\n");

	fprintf(fp,"Index Num, Free Memory, 1min Load Avg, 5min Load Avg, 10min Load Avg, Processes Running, Total Processes");

	

	signal(SIGALRM, program_alarm);
	alarm(1);
	while(1) sleep(20);

}

void program_alarm(int sig)
{
	printf("Got an alarm\n");
	alarm(1);
}