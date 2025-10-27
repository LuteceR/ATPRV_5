#include <iostream>
#include <omp.h>

int main() 
{
  int usm = 0
  #pragma omp parallel num_threads(10) reduction(+: sum)
  {
    sum++;
  }
  cout << sum ;
}
