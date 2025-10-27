#include <iostream>
#include <omp.h>

using namespace std;

int main() 
{
  // Задание 1

  // int sum_ = 0;
  // int n;
  // int result_ = 0;

  // int thread_0_sum = 0;
  // int thread_1_sum = 0;

  // cout << "Введите число n: " << endl;
  // cin >> n;

  // #pragma omp parallel num_threads(2) reduction(+: result_)
  // for (int i = 0; i <= n; i += 2) 
  // {
  //   int tid_ = omp_get_thread_num();

  //   if (tid_ == 1)
  //   {
  //     thread_0_sum += i;
  //     result_ += i;
  //   } 
  //   else 
  //   {
  //     thread_1_sum += i+1;
  //     result_ += i+1;
  //   }
  // }

  // cout << "[o] : Sum = " << thread_0_sum << endl;
  // cout << "[1] : Sum = " << thread_1_sum << endl;
  // cout << "Sum = " << result_ << endl ;

  // Задание 2

  int sum_ = 0;
  int n;
  int result_ = 0;

  int k;

  cout << "Введите число n: " << endl;
  cin >> n;

  cout << "Введите число потоков k: " << endl;
  cin >> k;

  int[k] results_per_t = new int[k];

  #pragma omp parallel num_threads(2) reduction(+: result_)
  for (int i = 0; i <= n; i = i + k) 
  {
    int tid_ = omp_get_thread_num();

    results_per_t[tid_ - 1] += i + tid_ -1;
  }

  for (int i = 1; i < k; i++) 
  {
    cout << "[o] : Sum = " << results_per_t[i] << endl;
  }

  cout << "Sum = " << result_ << endl ;
}
