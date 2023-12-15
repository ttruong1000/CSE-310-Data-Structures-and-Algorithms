/* This program generates a list of n random integers. 
   First, it reads an integer n. Then, it then generates 
   a sequence n random integers. */

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <omp.h>

using namespace std;

int sumOfDivisibleBy3WithLoop(int * A, int n);
int sumOfDivisibleBy3WithLoop_OMP(int * A, int n);

int main() {
  double wtime;
  int n;
  printf ( "How many random numbers do you want to generate?\n" );
  scanf ( "%d", &n );
  int * A;
  A = new int[n];
    
  //generate n of random numbers
  srand( (unsigned) time(NULL) );
    
  for(int i = 0; i < n; i++) {
    A[i] = rand() % 100;
  }

  int num_procs = omp_get_num_procs ( );
  int max_threads = omp_get_max_threads ( );
  printf ( " Number of processors available = %d\n", num_procs ); 
  printf ( " Number of threads = %d\n", max_threads );
    
  //executing sumOfDivisibleBy3WithLoop and also mesuring its execution time
  wtime = omp_get_wtime ( );
  int sum1 = sumOfDivisibleBy3WithLoop(A, n);
  wtime = omp_get_wtime ( ) - wtime;
  printf( "\n The first sum is %d\n", sum1 );
  printf ( " time  %14f\n\n", wtime );

  //executing sumOfDivisibleBy3WithLoop_OMP and also mesuring its execution time
  wtime = omp_get_wtime ( );
  int sum2 = sumOfDivisibleBy3WithLoop_OMP(A, n);
  wtime = omp_get_wtime ( ) - wtime;
  printf( " The second sum is %d\n", sum2 );
  printf ( " time  %14f\n\n", wtime );
}

int sumOfDivisibleBy3WithLoop(int * A, int n) {
  int divisibleBy3Sum = 0;
  for(int i = 0; i < n; i++) {
    if (A[i] % 3 == 0) {
      divisibleBy3Sum += A[i];
    }
  }
  return divisibleBy3Sum;
}

int sumOfDivisibleBy3WithLoop_OMP(int * A, int n) {
  int max_threads = omp_get_max_threads();
  int divisibleBy3Sum = 0;

  # pragma omp parallel for shared (n) num_threads(max_threads) reduction (+: divisibleBy3Sum)
  for(int i = 0; i < n; i++) {
    if (A[i] % 3 == 0) {
      divisibleBy3Sum += A[i];
    }
  }
  return divisibleBy3Sum;
}