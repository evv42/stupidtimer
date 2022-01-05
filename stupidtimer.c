#include <sys/time.h>
#include <stdio.h>

struct timeval start, actual, result;

int main(){
	gettimeofday(&start, NULL);

	while(1){
		gettimeofday(&actual, NULL);
		timersub(&actual, &start, &result);
		long int secs = (long int) result.tv_sec;
		long int mins = secs/60;
		long int hours = mins/60;
		long int subsecs = secs%60;
		printf("%02ld:%02ld:%02ld.%ld\r", hours, mins, subsecs, (long int)result.tv_usec);
		fflush(stdout);
	}
}
