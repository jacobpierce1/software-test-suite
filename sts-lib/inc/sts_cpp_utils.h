#ifndef STS_UTILS_H
#define STS_UTILS_H

#include <time.h>
#include <sys/time.h>

typedef struct {
	struct timeval startTime;
	struct timeval stopTime;
}StopWatch_t;

void startTimer(StopWatch_t *);

void stopTimer(StopWatch_t *);

double getElapsedTime(StopWatch_t *);

#endif /* STOPWATCH_H_ */



#define PRINT( str ) printf( "%s\n", (str) )
#define PRINT_INT( var ) printf( "%s = %d\n", (#var), (var) )
#define PRINT_LONG( var ) printf( "%s = %ld\n", (#var), (var) )
#define PRINT_ULONG( var ) printf( "%s = %lu\n", (#var), (var) )
#define PRINT_PTR( var ) printf( "%s = %p\n", (#var), (var) )
#define PRINT_STR( var ) printf( "%s = %s\n", (#var), (var) )
#define PRINT_SCI( var ) printf( "%s = %.3e\n", (#var), (var) )

#define REACHED() printf( "reached\n" )

int sleep_ns( long ns );




#endif 
