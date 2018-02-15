#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void program_alarm(int sig);

int main()
{
	FILE *fp;
	FILE *fd;
	int junk = 0;
	int memfree = 0;
	int alarm_count = 0;

	filename="output.csv";
	file_meminfo="/proc/meminfo";
	file_loadavg="/proc/loadavg";

	fp=fopen(filename,"w+");

	printf("Creating and opening output.csv\n");

	fprintf(fp,"Index Num, Free Memory, 1min Load Avg, 5min Load Avg, 10min Load Avg, Processes Running, Total Processes");
	
	fclose(fp);

	signal(SIGALRM, program_alarm);
	alarm(1);
	while(1) sleep(10);

}

void program_alarm(int sig)
{
	printf("Collecting data...\n");

	fd=fopen(file_meminfo,"rt");
	fscanf(fd, "MemTotal: %d MemFree:  %d", junk, memfree);
	fclose(fd);


	fopen(file_loadavg, "rt");
	fscanf(fd,"",);
	fclose(fd);


	fp=fopen(filename,"w+");
	fprintf(fp,"\n %d %d %d %d %d %d %d", alarm_count, memfree, LAone, LAfice, LAten, Prun, Ptotal);
	fclose(fp);


	alarm_count =+1;
	alarm(1);

	printf("Data Collection Complete!\n");
}