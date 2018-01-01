#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_DATA 100
void SortData(int i, int *f_data, char sort_data[100][7]);
int CheckDigit(char num[10]);
void Separate_Digit(unsigned int dig,char *ip);
//void Spell_Out(char data[4][10][10],char ip[10],int len);
void Show_Hundred(char ele1[1][10],char ele2[1][10],char dig0,char dig1);
void showten1(char ele1[1][10],char ele2[1][10],char dig0,char dig1);
//void showten(char ele[1][10],char dig);
//void Show_One(char ele[1][10],int dig );
int main()
{
	int len=0, j=0, i=0;
	FILE *fp = NULL;
	char  ip[10] = {0};
	char buff[10] = {0};
   char sort_data[MAX_DATA][7] = {0};
	int f_ip = 0, res = 0;
	int f_data[MAX_DATA] = {0};
	char data[4][10][10] = {{"one" ,"two","three" ,"four" ,"five" ,"six" ,"seven" ,"eight" , "nine" , "ten"},
		{"eleven" ,"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,"sixteen" , "seventeen", "eighteen", "nineteen","twenty"},
		{"ten","twenty", "thirty", "forty", "fifty", "sixty", "seventy","eighty", "ninety","hundred" },
		{"thousand"}};


	do{
		fp = fopen("myfile","r");
		if(fp == NULL)
		{
			break;
		}
		while(fscanf(fp, "%s", buff) > 0)
		{
			if(0 == strcmp(buff, "-1"))
				break;
			res = CheckDigit(buff);
			if(res == -1)
			{
				continue;
			}
			f_ip=atoi(buff);
			f_data[i]=f_ip;
         strcpy(sort_data[i],buff);
			i++;
		}
		fclose(fp);
		SortData(i,f_data,sort_data);
		for(j=0;j<i;j++)
		{
			//Separate_Digit(f_data[j],ip);		
			//len=strlen(ip);
			printf("%s :",sort_data[j]);
			Spell_Out(data,sort_data[j]);
			printf("\n");

		}	
	}while(0);
	return 1;
}
void Separate_Digit(unsigned int dig,char *ip)
{
	int num=0,j=0;
	int i=0;
	char buff[10]={0};
	do
	{
		num=dig % 10;
		ip[i]=num+'0';
		i++;
	}
	while((dig=dig/10)!=0);
	i--;
	for(j=0;j<=i;j++)
	{
		buff[j]=ip[i-j];
	}
	snprintf(ip,7,"%s",buff);
}

void Spell_Out(char data[4][10][10],char ip[10])
{
	int num=0;
int len=0;
len=strlen(ip);
	switch (len)
	{	
		case 1:
			{
				num=atoi(ip);
				Show_One(data[0],num);
				break;
			}
		case 2: 
			{
//				if(ip[0]=='1')
				{
					showten(data,ip);
				}
//				else
				{
//					showten1(data[0],data[2],ip[0],ip[1]);
				}
				break;
			}
/*
		case 3:
			{
				Show_Hundred(data[3],data[0],ip[0],'0');
				if((ip[1]=='0') && (ip[2]=='0'))
				{
					break;
				}
				else
				{
					if(ip[1]=='1')
					{
						showten(data[1],ip[2]);
					}
					else
					{
						showten1(data[0],data[2],ip[1],ip[2]);
					}

				}
				break;
			}
		case 4:
			{
				Show_Hundred(data[3],data[0],ip[0],'1');
				if((ip[1]=='0') && (ip[2]=='0') && (ip[3]== '0'))
				{
					break;
				}
				else
				{
					Show_Hundred(data[3],data[0],ip[1],'0');
					if((ip[3]=='0') && (ip[2]=='0'))
					{
						break;
					}
					else
					{
						if(ip[2]=='1')
						{
							showten(data[1],ip[3]);
						}
						else
						{
							showten1(data[0],data[2],ip[2],ip[3]);
						}

					}

				}
				break;
			}
		case 5:
			{
				if(ip[0]=='1')
				{
					showten(data[1],ip[1]);
					printf("thousand ");

				}
				else
				{
					showten1(data[0],data[2],ip[0],ip[1]);
					printf("thousand ");
				}
				if((ip[4]=='0') && (ip[2]=='0') && (ip[3]== '0'))
				{
					break;
				}
				Show_Hundred(data[3],data[0],ip[2],'0');
				if((ip[3]=='0') && (ip[4]=='0'))
				{
					break;
				}
				else
				{
					if(ip[3]=='1')
					{
						showten(data[1],ip[4]);
					}
					else
					{
						showten1(data[0],data[2],ip[3],ip[4]);
					}

				}
				break;
			}
		case 6:
			{
				Show_Hundred(data[3],data[0],ip[0],'0');
				if((ip[1]=='0') && (ip[2]=='0'))
				{
					printf("thousand ");
				}

				else
				{
					if(ip[1]=='1')
					{
						showten(data[1],ip[2]);
					}
					else
					{
						showten1(data[0],data[2],ip[1],ip[2]);
					}

					printf("thousand ");
				}
				if((ip[4]=='0') && (ip[5]=='0') && (ip[3]== '0'))
				{
					break;
				}
				Show_Hundred(data[3],data[0],ip[3],'0');
				if((ip[4]=='0') && (ip[5]=='0'))
				{
					break;
				}
				else
				{
					if(ip[4]=='1')
					{
						showten(data[1],ip[5]);
					}
					else
					{
						showten1(data[0],data[2],ip[4],ip[5]);
					}
				}
				break;
			}
*/
	}
}

void Show_One(char ele[1][10],int dig )
{
if(dig==0)
{
return ;
}
	printf("%s ",ele[dig-1]);
}

void showten(char data[4][10][10],char dig[10])
{
   int num1,num2;
   char buff[2]={0};
   char ch1,ch2;
//printf("%s\n",dig);
   ch1=dig[0];
   ch2=dig[1];
   if(dig[1] == '0')
   {
   snprintf(buff,2,"%c",ch1);
   num1=atoi(buff);
      printf("%s",data[2][num1-1]);
   }
else if(dig[0]== '1')
{
   snprintf(buff,2,"%c",ch2);
   num2=atoi(buff);
   printf("%s",data[1][num2-1]);
}
else
{
   snprintf(buff,2,"%c",ch1);
   num1=atoi(buff);
   snprintf(buff,2,"%c",ch2);
   num2=atoi(buff);
   printf("%s %s",data[2][num2-1],data[0][num1-1]);
}
   //	snprintf(buff,2,"%c",dig);
   //	num=atoi(buff);
   //	printf("%s ",ele[num]);
}

void showten1(char ele1[1][10],char ele2[1][10],char dig0,char dig1)
{
	int num0=0,num1=0;
	char buff[2]={0};
	snprintf(buff,2,"%c",dig0);
	num0=atoi(buff);
	snprintf(buff,2,"%c",dig1);
	num1=atoi(buff);
	if(num1==0)
	{
		printf("%s ",ele2[num0]);
	}
	else
	{
		printf("%s %s ",ele2[num0],ele1[num1]);
	}
}

void Show_Hundred(char ele1[1][10],char ele2[1][10],char dig0,char dig1)
{
	int num0=0,num1=0;
	char buff[2]={0};
	snprintf(buff,2,"%c",dig0);
	num0=atoi(buff);
	snprintf(buff,2,"%c",dig1);
	num1=atoi(buff);
	printf("%s %s ",ele2[num0],ele1[num1]);
}

int CheckDigit(char num[10])
{
	int len=0, i=0;
	len = strlen(num);
	for(i=0; i<len; i++)
	{
		if(num[i]<48 || num[i]>57 || len>6 )
		{
			return -1;
		}
	}
	return 1;
}

void SortData(int i, int *f_data, char sort_data[100][7])
{
	int j=0,k=0,tmp=0;
   char tmp_buff[7]={0};
	for(k=0;k<(i-1);k++)
	{
		for(j=k;j<(i-1);j++)
		{
			if(f_data[k] > f_data[j+1])
			{
            strcpy(tmp_buff,sort_data[k]);
            tmp=f_data[k];
            f_data[k]=f_data[j+1];
            strcpy(sort_data[k],sort_data[j+1]);
            f_data[j+1]=tmp;
            strcpy(sort_data[j+1],tmp_buff);
			}
		}
	}		
}
