// adapted from  https://devblogs.nvidia.com/even-easier-introduction-cuda/

#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

#include "jacob/timer.hpp"


using namespace std;

const int NUM_ITERATIONS = 1000;


#ifdef USE_CUDA 
__global__ 
#endif 
// function to add the elements of two arrays
void add(int n, float *x, float *y)
{
    for (int i = 0; i < n; i++)
	y[i] = x[i] + y[i];
}




int main(void)
{
    int N = 1<<5; // 2^22 elements 
    cout << N << endl;
    
#ifdef USE_CUDA
    float *x, *y;
    cudaMallocManaged(&x, N*sizeof(float));
    cudaMallocManaged(&y, N*sizeof(float));
#else
    float *x = new float[N];
    float *y = new float[N];
#endif

    
    // initialize x and y arrays on the host
    for (int i = 0; i < N; i++) {
	x[i] = 1.0f;
	y[i] = 2.0f;
    }
    
	
    Timer timer; 

    // test the timer 
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    for( int j = 0; j < NUM_ITERATIONS; j++ )
    {
	
	// <<<x,y>>> : y is the numbre of threads, must be multiple of 32
#ifdef USE_CUDA
	add<<<1, 1>>>(N, x, y);
	cudaDeviceSynchronize();
#else
	add(N, x, y);
#endif
    
	// // Check for errors (all values should be 3.0f)
	// float maxError = 0.0f;
	// for (int i = 0; i < N; i++)
	//     maxError = fmax(maxError, fabs(y[i]-3.0f));
	// std::cout << "Max error: " << maxError << std::endl;

	
    }

    // Free memory
#ifdef USE_CUDA
    cudaFree( x );
    cudaFree( y );
#else
    delete [] x;
    delete [] y;
#endif
	
    double elapsed = timer.elapsed();
    // cout << elapsed / NUM_ITERATIONS << " s" << endl; 

    printf( "%.3e seconds \n", elapsed / NUM_ITERATIONS );
    
    return 0;
}
