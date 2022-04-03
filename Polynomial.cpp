
//Coordinate List representation is used
#include <iostream>
#include <cmath>
using namespace std;

class Term
{
public:
  int coeff;
  int exp;
};

class Polynomial
{
private:
  int number; // number of terms in a func => 3x2+2x1+7 => 3 terms
  Term *t;

public:
  Polynomial (int n)
  {
    this->number = n;
    t = new Term[n];
  }
  ~Polynomial()
  {
    delete [] t;
  }


  friend ostream &operator<<(ostream &os,Polynomial &p);
  friend istream &operator>>(istream &is,Polynomial &p);


  Polynomial &operator+(Polynomial &p);
  // void ReadData();
  // int Evaluation(int);

};

istream &operator>>(istream &is,  Polynomial &p)
 {
   int i;
   for(i = 0; i < p.number;i++)
   {
     cout<<"Enter coefficient : ";
     is>>p.t[i].coeff;
     cout<<"Enter power : ";
     is>>p.t[i].exp;
   }
   return is;
 }

 ostream &operator<<(ostream &os, Polynomial &p)
 {
     int i;
     for(i=0;i<p.number;i++)
     {
       os << p.t[i].coeff<<"x"<<p.t[i].exp<<" + ";
     }
   return os;
 }

  Polynomial &Polynomial::operator+(Polynomial &p)
  {
      int i{0};
      int j{0};
      int k{0};
      Polynomial *sum = new Polynomial(number + p.number);
      while(i < number && j < p.number)
       {
         if(t[i].exp > p.t[j].exp)
          {
            sum->t[k++]=t[i++];
          }
         else if(t[i].exp < p.t[j].exp)
          {
            sum->t[k++]=p.t[j++];
          }
         else
          {
            sum->t[k].exp=t[i].exp;
            sum->t[k++].coeff=t[i++].coeff + p.t[j++].coeff;
          }
       }
      for (; i<number; i++)
      {
        sum->t[k++] = t[i];
      }

      for (; j<p.number; j++)
      {
        sum->t[k++] = p.t[j];
      }

    sum->number = k;

    return *sum;
  }



  // int Polynomial::Evaluation(int x)
  // {
  //   int i;
  //   int sum{0};
  //   for(i=0;i<this->number;i++)
  //   {
  //       sum += pow(x,term[i].exp)*term[i].coeff;
  //   }
  //   return sum;
  // }


int main()
{
  Polynomial p1(3);
  Polynomial p2(5);
  cin >> p1;
  cin >> p2;

  Polynomial p3 = p1 + p2;
  cout<<"Result : " << p3;


  // p.ReadData();
  // cout<<"Result : "<<p.Evaluation(2);

  return 0;
}
