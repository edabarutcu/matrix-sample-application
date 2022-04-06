
#include <iostream>

using namespace std;

int main()
{

  int A[]  {6,7,8,8,9,12,13,13,13,17,19,19,19,19};
  int lastduplicate {0};
  int i;
  for(i = 0 ;i < 14;i++)
  {
    if(A[i]==A[i+1] && A[i]!=lastduplicate)
    {
      cout<<A[i]<< " ";
      lastduplicate = A[i];
    }
  }

return 0;
}
