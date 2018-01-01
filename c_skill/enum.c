// An example program to demonstrate working
// // of enum in C
 #include<stdio.h>

 enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};

 int main()
 {
  enum week day;
    day = Wed;
      enum week *p=&day;
        printf("%p\n",&day);
          printf("%d\n",*p);
            return 0;
            } 

