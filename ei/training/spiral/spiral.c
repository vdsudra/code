#include<stdio.h>
int MaxCln;
int MaxRow;
int ittr=0;
int n=0;
int matrix[1][1];

void fill_matrix(int s_r,int s_c,int s_f,int matrix[n][n],int val,int mod);
void P_matrix(int matrix[n][n]);
int find_prime(int num);
int main()
{
   int mod=0;
   int flag=0;
   int val=0;
   int start_row=0;
   int start_col=0;
   FILE *fp=NULL;
   do
   {
      if((fp=fopen("my_file","r"))==NULL)
      {
         perror("Error");
         break;
      }
      fscanf(fp,"%d",&n);
      if((n <1) || (n >100))
      {
         printf("Please Enter Integer value between 1 to 100\n");
         break;
      }

      int matrix[n][n];
      MaxCln=n;
      MaxRow=n;

      if((n%2) ==0)
      {
         flag=2;//left
         start_row=0;
         start_col=0;
         mod=1;
      }
      else
      {
         flag=1;//right
         start_row=n-1;
         start_col=n-1;
      }
      val=n*n;
      fill_matrix(start_row,start_col,flag,matrix,val,mod);
      P_matrix(matrix);
   }
   while(0);

   if(fp!=NULL)
   {
      fclose(fp);
      fp=NULL;
   }
   return 0;
}

void P_matrix(int matrix[n][n])
{
   int row,cln;
   int i,j;
   int temp=0;
   int sum =0;
   int step= 0;
   int num=0;
   for(row=0;row<n;row++)
   {
      for(cln=0;cln<n;cln++)
      {
         printf("%d\t",matrix[row][cln]);
      }
      printf("\n");
   }

   for(row=0;row<n;row++)
   {
      temp=0;
      for(i=row,j=0;i<n ;i++,j++)
      {
         if(find_prime(matrix[i][j]))
         {
            temp=temp+matrix[i][j];
         }
      }
      if(temp > sum)
         sum=temp;
   }

   for(cln=1;cln<n;cln++)
   {
      temp=0;
      for(i=0,j=cln;j<n ;i++,j++)
      {  
         if(find_prime(matrix[i][j]))
         {
            temp=temp+matrix[i][j];
         }
      }
      if(temp > sum)
         sum=temp;
   }

   for(cln=n-1;cln>=0;cln--)
   {
      temp=0;
      for(i=0,j=cln;j>=0 ;i++,j--)
      {
         if(find_prime(matrix[i][j]))
         {
            temp=temp+matrix[i][j];
         }
      }
      if(temp > sum)
         sum=temp;
   }

   for(row=1;row<n;row++)
   {
      temp=0;
      for(i=row,j=n-1;i<n ;i++,j--)
      {
         if(find_prime(matrix[i][j]))
         {
            temp=temp+matrix[i][j];
         }
      }
      if(temp > sum)
         sum=temp;
   }
   printf("Max Sum:%d\n",sum);
}

int find_prime(int num)
{
   int result=1;
   int tmp;
   do
   {
      if((num == 1) || (num == 2))
      {
         result= 1;
         break;
      }
      for(tmp=2;tmp<num;tmp++)
      {
         if(num % tmp == 0 )
         {
            result =0;
            break;
         }
      }

   }while(0);
   return result;
}

void fill_matrix(int s_r,int s_c,int s_f,int matrix[n][n],int val,int mod)
{
   int row,cln;
   int r_size,c_size;

   if(s_f == 2)//left
   {
      for(row=s_r,cln=s_c,c_size=MaxCln;c_size>0;c_size--,cln++)
      {
         matrix[row][cln]=val;
         val--;
      }
      cln--;
      s_c=cln;
      s_r++;

      for(row=s_r,r_size=MaxRow-2;r_size>0;row++,r_size--)
      {
         matrix[row][cln]=val;
         val--;

      }
      ittr++;
      if (mod !=1)
      { 
         cln--;
         row--;
      }
      if(ittr==2)
      {
         MaxCln=MaxCln-2;
         MaxRow=MaxRow-2;
         ittr=0;
      }
      if(val>0)
      {
         fill_matrix(row,cln,1,matrix,val,mod);
      }

   }

   else//r8
   {
      for(row=s_r,cln=s_c,c_size=MaxCln;c_size>0;c_size--,cln--)
      {
         matrix[row][cln]=val;
         val--;
      }
      cln++;
      s_c=cln;
      s_r--;
      for(row=s_r,r_size=MaxRow-2;r_size>0 ;r_size--,row--)
      {
         matrix[row][cln]=val;
         val--;
      }
      ittr++;
      if(ittr==2)
      {
         MaxCln=MaxCln-2;
         MaxRow=MaxRow-2;
         ittr=0;
      }
      if(mod == 1)
      {
         row++;
         cln++;
      }
      if(val>0)
      {
         fill_matrix(row,cln,2,matrix,val,mod);
      }
   }
}




