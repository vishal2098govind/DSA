#include <iostream>
#define ll long long
using namespace std;

// void prime_sieve(int *p)
// {

//   //Mark All the odd no.s as prime
//   for (int i = 3; i <= 100000; i += 2)
//   {
//     p[i] = 1;
//   }

//   //Sieve
//   //loop through all the odd numbers and mark the multiples of marked numbers as not prime

//   for (ll i = 3; i <= 100000; i += 2)
//   {
//     //check if it is marked , if marked then mark all its multiples as not prime
//     if (p[i] == 1)
//     {
//       for (ll j = i * i; j <= 100000; j = j + i)
//       {
//         p[j] = 0; //marked as not prime
//       }
//     }
//   }

//   //special case:
//   p[2] = 1;
//   p[0] = p[1] = 0;
// }

int main()
{
  int n;
  cout << "hello";
  cin >> n;

  int p[100] = {0};
  // // prime_sieve(p);

  // for (int i = 0; i <= n; i++)
  // {
  //   if (p[i] == 1)
  //   {
  //     cout << i << " ";
  //   }
  // }
  return 0;
}