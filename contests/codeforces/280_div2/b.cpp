#include <bits/stdc++.h>
using namespace std;

// straight street of length l, lit by n lanterns
// coordinate system with the beginning of the street at point 0
// and its end to the point l
// the i-th lantern is at point ai
// the lantern lights all points at the street that are at most at
// a d distance from it d > 0
//
// what is the minimun d should the lanters light the whole stree?
//
// input n, l (1 <= n <= 1000) 1  <= l <= 10e9
// the next line contains n integers ai (0 <= ai <= l)
// multiple lanterns can be located at the same point
// the lanterns may be at the end of the street
//
// output: the minimun light radius d 
// the answer will be correct if the absolute or relative
// error does not exceed 10e-9
//
int arr[1123];

int main() {
  int n, l;
  cin >> n >> l;
  for(int i = 0; i<n;i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);

  double interval_size = arr[0];
  double new_interval;

  for(int i=1;i<n;i++) {
    new_interval = (arr[i] + arr[i-1]) / 2.0;
    new_interval -= arr[i-1];
    //cout << new_interval << endl;
    if(new_interval > interval_size) interval_size = new_interval;
  } 

  new_interval = l - arr[n-1] ;
  if(new_interval > interval_size) interval_size = new_interval;

  cout << setprecision(10) << interval_size << endl;


}
