#include<iostream>
using namespace std;

class matrix
{
   private:
      int a[4][4];

   public:
      void read()
      {
         int i,j;
         for(i=0 ;i<4;i++)
         {
            for(j=0;j<4;j++)
            {
               cin >> a[i][j];
            }
         }
      };

      void show()
      {
         int i,j;
         for(i=0 ;i<4;i++)
         {
            for(j=0;j<4;j++)
            {
               cout << a[i][j] << " ";
            }
            cout << endl;
         }
      };

      matrix operator * (matrix m)
      {
         matrix tmp;
         int i,j;
         for(i=0 ;i<4;i++)
         {
            for(j=0;j<4;j++)
            {
               tmp.a[i][j]=0;
               for(int k=0;k<4;k++)
               {
                  tmp.a[i][j] +=a[i][k]*m.a[k][j];
               }
            }
         }
      return tmp;
      };
};

int main()
{

   matrix m1,m2,m3;
   cout << "Enter m1 data\n";
   m1.read();

   cout << "Enter m2 data\n";
   m2.read();

   cout<< "*******************************\n";
   m3=m1*m2;
   m3.show();
}
