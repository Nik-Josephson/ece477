#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


	FILE * fp;
	FILE * fd;

	int junk = 0;
	int memfree = 0;
	int alarm_count;
	float LAone;
	float LAfive;
	float LAten;
	int Prun;
	int Ptotal;

/*Define for user-made alarm*/
void program_alarm(int sig);



int main()
{

	fp=fopen("output.csv","w+");
	printf("Creating and opening output.csv\n");
	fprintf(fp,"IdNum FreeMem LAone LAfive LAten Prun Ptotal");

	alarm_count = 0;
	signal(SIGALRM, program_alarm);
	alarm(2);
	while(1) sleep(10);

}

void program_alarm(int sig)
{
	printf("Collecting data for alarm_count %d\n", alarm_count);

	fd=fopen("/proc/meminfo","rt");
	if(!fd) printf("Error opening meminfo\n");
	fscanf(fd, "%s %d %s %s %d", &junk, &junk,  &junk, &junk, &memfree);
	printf("memfree is %d\n", memfree);
	fclose(fd);

	fopen("/proc/loadavg", "rt");
	if(!fd) printf("Error opening loadavg\n");
	fscanf(fd,"%f %f %f %d/%d",&LAone,&LAfive,&LAten,&Prun,&Ptotal);
	printf("LAone is %f\n", LAone);
	printf("LAfive is %f\n", LAfive);
	printf("LAten is %f\n", LAten);
	printf("Prun is %d\n", Prun);
	printf("Ptotal is %d\n", Ptotal);
	fclose(fd);
	

	fflush(fp);
	fprintf(fp,"\n %d %d %f %f %f %d %d", alarm_count, memfree, LAone, LAfive, LAten, Prun, Ptotal);

	alarm(2);
	alarm_count = 1+alarm_count;
	printf("Data Collection Complete!\n");
}