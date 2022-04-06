//O(n)
#include <iostream>

using namespace std;

int main()
{

  int A[]  {6,7,8,8,9,12,13};
  int i;
  int H[14];
  int max = 13;//max number of array A
  for(i = 0 ;i < 7 ;i++)
  {
    H[A[i]]++;
  }
  for(i = 0 ;i <=max ;i++)
  {
    if(H[i] > 1)
    {
      cout<<i<<" appeared "<<H[i]<<" times\n";
    }
  }


return 0;
}
