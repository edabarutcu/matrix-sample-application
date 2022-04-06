//O(n)
#include <iostream>

using namespace std;

int main()
{

  int A[]  {6,7,8,8,9,12,13,13};
  int j{0};
  int i;
  int length = 8;
  for(i = 0 ;i < length -1;++i)
  {
    if(A[i]==A[i+1])
    {
        j = i+1;
        while(A[j] == A[i])
        {
          ++j;
        }
        cout<<A[i]<<" appeared "<<(j-i)<<" times.\n";
        i = j - 1;
    }
  }

return 0;
}
