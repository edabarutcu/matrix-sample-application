#include <iostream>

using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;
  void Swap(int *x,int *y);

public:
  Array()
  {
    size = 10;
    A = new int[size];
    length = 0;
  }
  Array(int sz)
  {
    size =sz;
    length = 0;
    A = new int[size];
  }

  ~Array()
  {
    delete [] A;

  }

void Display( );
void Append(int x);
void Insert(int index,int x);
int DeleteElement(int index);
int LinearSearch(int key);
int BinarySearch(int key);
int RBinSearch(int a[],int l,int h,int key);
int Get(int index);
void Set(int index,int x);
int Max( );
int Min( );
int Sum( );
int RSum(int n);
float Avg();
void Reverse();
void Reverse2();
void InsertSort(int x);
int isSorted();
void Rearrange();
Array *Merge(Array arr2);
Array *Union(Array arr2);
Array *Intersection(Array arr2);
Array *Difference(Array arr2);

};

//O(n)
void Array::Display()
{
  int i {0};
  cout<<"Elements of array\n\n";
  for(i = 0 ;i<length;i++)
  {
    cout<<A[i] <<" ";
  }
}

//O(1)
void Array::Append(int x)
{
  if(length < size)
  {
    A[length++] = x;

  }
}

//Min : O(1)  Max : O(n)
void Array::Insert(int index,int x)
{
  if(index >= 0 && index <= length)
  {
    for(size_t i = length;i>index;i--)
    {
      A[i] = A[i-1];
    }
    A[index] = x;
    length++;
  }
}
//Min : O(1)  Max : O(n)
int Array::DeleteElement(int index)
{
  int x{0};

  if(index>=0 && index < length)
  {
    x = A[index];

    for(int i = index;i<length-1;i++)
    {
        A[i] = A[i+1];
    }
    length--;
    return x;
  }

return 0;

}

void Array::Swap(int *x,int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

//MoveFront Method
int Array::LinearSearch(int key)
{
  for(size_t i{0};i<length;i++)
  {
    if(key == A[i])
    {
      Swap(&A[i],&A[0]);
      return i;
    }
  }
  return -1;
}

// //Transposition Method
// int LinearSearch(Array *arr,int key)
// {
//   for(size_t i{0};i<arr->length;i++)
//   {
//     if(key == arr->A[i])
//     {
//       swap(&arr->A[i],&arr->A[i-1]);
//       return i-1;
//     }
//   }
//   return -1;
// }

// Search key element 1 by 1 through the list
// int LinearSearch(Array *arr,int key)
// {
//   for(size_t i{0};i<arr->length;i++)
//   {
//     if(key == arr->A[i])
//     {
//       return i;
//     }
//   }
//   return -1;
// }

//İterative Binary Search
int Array::BinarySearch(int key)
{
 int l;
 int mid
 int h;

 l = 0;
 h = length-1;

 while(l <= h)
 {
   mid=(l+h)/2;
   if(key==A[mid])
   {
     return mid;

   }
   else if(key<A[mid])
   {
     h=mid-1;
   }
   else
   {
     l=mid+1;
   }
 }

return -1;
}


//Recursive version,Tail recursion,döndükten sonra birşey yapmıyor.
int Array::RBinSearch(int a[],int l,int h,int key)
{
 int mid = 0;

 if(l <= h)
 {
   mid=(l+h)/2;

   if(key==a[mid])
   {
     return mid;

   }
   else if(key<a[mid])
   {
     return RBinSearch(a,l,mid-1,key);
   }

}
 else
 {
   return RBinSearch(a,mid+1,h,key);

 }

return -1;

}

//O(1)
int Array::Get(int index)
{
 if(index>=0 && index<length)
 {
   return A[index];

 }
 else
 {
   return -1;
 }
}

//O(1)
void Array::Set(int index,int x)
{
  if(index>=0 && index<length)
  {
    A[index] = x;
  }
}

//If unsorted O(n)
int Array::Max( )
{
 int max = A[0];
 int i{};

 for(i = 1;i < length;i++)
 {
   if(A[i]>max)
   {
     max=A[i];
   }
}
 return max;
}

//If unsorted O(n)
int Array::Min( )
{
 int min = A[0];
 int i{};

 for(i=1;i<length;i++)
 {
 if(A[i]<min)
   {
      min=A[i];
   }

 }
 return min;

}

//O(n)
int Array::Sum()
{
 int s=0;
 int i;
 for(i=0;i<length;i++)
 s+=A[i];
 return s;
}

//O(n)
int Array::RSum(int n)
{

 if(n < 0)
 return 0;
 else
 {
   return RSum(n-1) + A[n];
 }

}

float Array::Avg()
{
 return (float)Sum()/length;
}

//O(n)
void Array::Reverse()
{
  int i{0};
  int j{0};
  int *B =  new int[length];

  for(i=length-1 , j=0 ; i >= 0;i--,j++)
  {
    B[j] = A[i];
  }

  for(i=0;i<length;i++)
  {
    A[i] = B[i];
  }

}

void Array::Reverse2()
{
 int i{};
 int j{};

 for(i=0,j=length-1;i<j;i++,j--)
 {
 Swap(&A[i],&A[j]);
 }

}

//Min : O(1) Max : O(n)
void Array::InsertSort(int x)
{
  int i = length -1;

  if(length == size)
  {
    return;
  }

  while(i>=0 && A[i] > x)
  {
    A[i+1] = A[i];
    --i;
  }
  A[i+1] = x;
  length++;
}

//Min : O(1) Max : O(n)
int Array::isSorted()
{
int i;

for(i = 0;i<length-1;i++)
{

  if(A[i] > A[i+1])
  {
    return 0; //means false
  }
}

return 1;
}

//O(n)
void Array::Rearrange()
{
    int i {0};
    int j = length;
    while(i<j)
    {
      while(A[i]<0)
      {
        i++;
      }
      while(A[j]>0)
      {
        --j;
      }
      if(i<j)
      {
        Swap(&A[i],&A[j]);
      }
    }
}

//Arrays must be sorted lists
Array *Array::Merge(Array arr2)
{
  int i{0};
  int j{0};
  int k{0};

  Array *arr3 = new Array(length+arr2.length);

  while(i< length && j<arr2.length)
  {
    if(A[i] < arr2.A[j])
    {
      arr3->A[k++] = A[i++];
    }
    else
    {
      arr3->A[k++] = arr2.A[j++];
    }
  }


  for(;i<length;i++)
  {
    arr3->A[k++] = A[i];

  }

  for(;j<arr2.length;j++)
  {
    arr3->A[k++] = arr2.A[j];

  }

  arr3->length = length + arr2.length;

  return arr3;

}

//O(n)
Array *Array::Union(Array arr2)
{
  int i{0};
  int j{0};
  int k{0};

  Array *arr3 = new Array(length+arr2.length);
  while(i< length && j<arr2.length)
  {
    if(A[i] < arr2.A[j])
    {
      arr3->A[k++] = A[i++];
    }
    else if(arr2.A[j] < A[i])
    {
      arr3->A[k++] = arr2.A[j++];
    }
    else
    {
      arr3->A[k++] = A[i++];
      j++;
    }
  }

  for(;i<length;i++)
  {
    arr3->A[k++] = A[i];
  }

  for(;j<arr2.length;j++)
  {
    arr3->A[k++] = arr2.A[j];
  }

  arr3->length = k;

  return arr3;
}

Array *Array::Intersection(Array arr2)
{
  int i{0};
  int j{0};
  int k{0};

  Array *arr3 = new Array(length+arr2.length);
  while(i< length && j<arr2.length)
  {
    if(A[i] < arr2.A[j])
    {
      i++;
    }
    else if(arr2.A[j] < A[i])
    {
      j++;
    }
    else if(A[i] == arr2.A[j])
    {
      arr3->A[k++] = A[i++];
      j++;
    }
  }

  arr3->length = k;

  return arr3;

}

Array *Array::Difference(Array arr2)
{
  int i{0};
  int j{0};
  int k{0};

  Array *arr3 = new Array(length+arr2.length);
  while(i< length && j<arr2.length)
  {
    if(A[i] < arr2.A[j])
    {
      arr3->A[k++] = A[i++];
    }
    else if(arr2.A[j] < A[i])
    {
      j++;
    }
    else
    {
      i++;
      j++;
    }
  }


  for(;i<length;i++)
    arr3->A[k++] = A[i];

  arr3->length = k;
  arr3->size = 10;
  return arr3;

}





int main()
{
  int size{0};
  int c;
  int x;
  int index;

  cout<<"Enter Size of Array:";
  cin>>size;

  Array *arr3 = new Array(size);

  do {
      cout<<"\n\nMenu\n";
      cout<<"1.Insert\n";
      cout<<"2.Delete\n";
      cout<<"3.Search\n";
      cout<<"4.Sum\n";
      cout<<"5.Display\n";
      cout<<"6.Exit\n";

      cout<<"Enter your choice :";
      cin>>c;
      switch (c)
      {
        case 1:
          std::cout <<"Enter an element and index :";
          cin>>x>>index;
          arr3->Insert(index,x);
          break;
        case 2:
          cout<<"Enter index :";
          x =arr3->DeleteElement(index);
          cout<<"Deleted element is "<<x<<endl;
          break;
        case 3:
          cout<<"Enter element to search :";
          cin>>x;
          index = arr3->LinearSearch(x);
          cout<<"Element index "<<index;
          break;
        case 4:
            cout<<"Sum is "<<arr3->Sum();
            break;
        case 5:
          arr3->Display();
      }

  } while(c<6);

  return 0;

  }
