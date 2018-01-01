#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Sepdigit(unsigned int ,char *);

void showhun(char *[],char *[],char ,char );
void spell(char *[][][],char [],int );

void showten1(char *[],char *[],char ,char );
void showten(char *[],char );
void show1(char *[],int );
int main()
{
	int len,j;
	FILE *fp=NULL;
	char  ip[10];
	unsigned int f_ip;
	int i=0;
	char *data[4][10]={{"zero" ,"one" ,"two","three" ,"four" ,"five" ,"six" ,"seven" ,"eight" , "nine"},
		{"ten","eleven" ,"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,"sixteen" , "seventeen", "eighteen", "nineteen"},
		{"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy","eighty", "ninety" },
		{"hundred","thousand"}};

	fp=fopen("myfile","r");
	if(fp==NULL)
	{
		return 0;
	}
	int f_data[100];
	while(fscanf(fp,"%d",&f_ip)>0)
	{
		if(f_ip==-1)
			break;
		f_data[i]=f_ip;
		i++;
	}
	fclose(fp);
	int tmp,k;
	for(k=0;k<(i-1);k++)
	{
		for(j=k;j<(i-1);j++)
		{
			if(f_data[k] > f_data[j+1])
			{
				tmp=f_data[k];
				f_data[k]=f_data[j+1];
				f_data[j+1]=tmp;
			}
		}
	}

	for(j=0;j<i;j++)
	{
		Sepdigit(f_data[j],ip);		
		len=strlen(ip);
		printf("%d :",f_data[j]);
		spell(data,ip,len);
		printf("\n");

	}	
	return 1;
}

void Sepdigit(unsigned int dig,char *ip)
{
	int num=0;
	int i=0;
	int j;
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
	snprintf(ip,6,"%s",buff);
}

void spell(char *data[4][10],char ip[10],int len)
{
	int num;

	switch (len)
	{	
		case 1:
			{
				num=atoi(ip);
				show1(data[0],num);
				break;
			}
		case 2: 
			{
				if(ip[0]=='1')
				{
					showten(data[1],ip[1]);
				}
				else
				{
					showten1(data[0],data[2],ip[0],ip[1]);
				}
				break;
			}

		case 3:
			{
				showhun(data[3],data[0],ip[0],'0');
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
				showhun(data[3],data[0],ip[0],'1');
				if((ip[1]=='0') && (ip[2]=='0') && (ip[3]== '0'))
				{
					break;
				}
				else
				{
					showhun(data[3],data[0],ip[1],'0');
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
				showhun(data[3],data[0],ip[2],'0');
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
				showhun(data[3],data[0],ip[0],'0');
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
				showhun(data[3],data[0],ip[3],'0');
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

	}
	return 0;
}

void show1(char *ele[10],int tmp )
{
	printf("%s ",ele[tmp]);
}



void showten(char *ele[10],char dig)
{
	int num;
	char buff[2];
	snprintf(buff,2,"%c",dig);
	num=atoi(buff);
	printf("%s ",ele[num]);
}




void showten1(char *ele1[10],char *ele2[10],char dig0,char dig1)
{
	int num0;
	int num1;
	char buff[2];
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


void showhun(char *ele1[10],char *ele2[10],char dig0,char dig1)
{
	int num0;
	int num1;
	char buff[2];
	snprintf(buff,2,"%c",dig0);
	num0=atoi(buff);
	snprintf(buff,2,"%c",dig1);
	num1=atoi(buff);
	printf("%s %s ",ele2[num0],ele1[num1]);
}
