#include <time.h>
#include <sys/time.h>

// ------------------ stopwatch ----------------
typedef struct {
	struct timeval startTime;
	struct timeval stopTime;
}StopWatch_t;



void startTimer(StopWatch_t * watch){
	gettimeofday(&watch->startTime, NULL);
}

void stopTimer(StopWatch_t * watch) {
	gettimeofday(&watch->stopTime, NULL);
}

 double getElapsedTime(StopWatch_t * watch) {
	return ((watch->stopTime.tv_sec-watch->startTime.tv_sec)*1000000LL + watch->stopTime.tv_usec-watch->startTime.tv_usec)/1000.0f;
}

// ---------------------------------------


void saxpy_cpu(int n, float a, float * x, float * y, float *z )
{
  for (int i = 0; i < n; ++i)
      z[i] = a*x[i] + y[i];
}

// void test_cublas( void ) 
// {
// 	int N = 1<<20; 
// 	cublasInit();
// 	cublasSetVector(N, sizeof(x[0]), x, 1, d_x, 1);
// 	cublasSetVector(N, sizeof(y[0]), y, 1, d_y, 1);

// 	// Perform SAXPY on 1M elements
// 	cublasSaxpy(N, 2.0, d_x, 1, d_y, 1);

// 	cublasGetVector(N, sizeof(y[0]), d_y, 1, y, 1);
// 	cublasShutdown();
// }

const int N = 1<<20;

int main( int argc, char **argv )
{
	float x[ N ] = { 4 };
	float y[ N ] = { 5 };
	float z[ N ];

	// Perform SAXPY on 1M elements
	saxpy_cpu( N, 2.0, x, y, z);

	// test_cublas();
	return 0;
}