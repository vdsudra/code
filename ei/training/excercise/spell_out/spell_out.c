#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*******************************************************************************/
/*!   \fn     void SortData(int i, int *f_data) 
 *
 *    \brief    To sort the file data
 *
 *    \param    [IN]  i- number of elements in array
 *    \param    [IN]  f_data - data array
 */
/*******************************************************************************/
void SortData(int i, int *f_data);
/*******************************************************************************/
/*!   \fn    int CheckDigit(char num[10]) 
 *
 *    \brief    Check for integer data
 *
 *    \param    [IN]  num - number string from file
 */
/*******************************************************************************/
int CheckDigit(char num[10]);
/*******************************************************************************/
/*!   \fn  void Separate_Digit(unsigned int dig,char *ip) 
 *
 *    \brief    seperate each digit from string and fill in char array
 *
 *    \param    [IN]  dig- number to be seperate
 *    \param    [IN]  ip - store seperated number in equivalent string 
 */  
/*******************************************************************************/
void Separate_Digit(unsigned int dig,char *ip);
/*******************************************************************************/
/*!   \fn  void Spell_Out(char data[4][10][10],char ip[10],int len) 
 *
 *    \brief   print the numbers into their equivalent english text 
 *
 *    \param    [IN]  data- array of english text
 *    \param    [IN]  ip- number to be print
 *    \param    [IN]  len- lengtht of string 
 */  
/*******************************************************************************/
void Spell_Out(char data[4][10][10],char ip[10],int len);
/*******************************************************************************/
/*!   \fn 	void Show_Hundred(char ele1[1][10],char ele2[1][10],char dig0,char dig1) 
 *
 *    \brief   print  numbers into their equivalent english text if digit place is hundred
 *
 *    \param    [IN]  ele1- array of english text
 *    \param    [IN]  ele2- array of english text
 *    \param    [IN]  dig0- digit to print
 *    \param    [IN]  dig1- place to print
 */  
/*******************************************************************************/
void Show_Hundred(char ele1[1][10],char ele2[1][10],char dig0,char dig1);
/*******************************************************************************/
/*!   \fn	void showten1(char ele1[1][10],char ele2[1][10],char dig0,char dig1) 
 *
 *    \brief   print  numbers into their equivalent english text if number between 20 to 99
 *
 *    \param    [IN]  ele1- array of english text
 *    \param    [IN]  ele2- array of english text
 *    \param    [IN]  dig0- digit to print
 *    \param    [IN]  dig1- place to print
 */  
/*******************************************************************************/
void showten1(char ele1[1][10],char ele2[1][10],char dig0,char dig1);
/*******************************************************************************/
/*!   \fn	void showten(char ele[1][10],char dig)	
 *
 *    \brief   print  numbers into their equivalent english text if number between 10 to 19
 *
 *    \param    [IN]  ele- array of english text
 *    \param    [IN]  dig- digit to print
 */  
/*******************************************************************************/
void showten(char ele[1][10],char dig);
/*******************************************************************************/
/*!   \fn	void Show_One(char ele[1][10],int dig )	
 *
 *    \brief   print  numbers into their equivalent english text if number between 1 to 9
 *
 *    \param    [IN]  ele- array of english text
 *    \param    [IN]  dig- digit to print
 */  
/*******************************************************************************/
void Show_One(char ele[1][10],int dig );

/*******************************************************************************/
/*!   \fn       int main()
 *
 *    \brief    main function
 *
 *    \param    [IN] network_name - name of network
 *    \param    [IN] networkRoutes - routes of network
 */
/*******************************************************************************/
int main()
{
	int len=0,j=0,i=0;
	FILE *fp=NULL;
	char  ip[10]={0};
	char buff[10]={0};
	int f_ip=0,res=0;
	int f_data[100]={0};
	char data[4][10][10]={{"zero" ,"one" ,"two","three" ,"four" ,"five" ,"six" ,"seven" ,"eight" , "nine"},
		{"ten","eleven" ,"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,"sixteen" , "seventeen", "eighteen", "nineteen"},
		{"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy","eighty", "ninety" },
		{"hundred","thousand"}};

	do{
		fp=fopen("myfile","r");
		if(fp==NULL)
		{
			break;
		}
		while(fscanf(fp,"%s",buff)>0)
		{
			if(0==strcmp(buff,"-1"))
				break;
			res=CheckDigit(buff);
			if(res==-1)
			{
				continue;
			}
			f_ip=atoi(buff);
			f_data[i]=f_ip;
			i++;
		}
		fclose(fp);
		SortData(i,f_data);
		for(j=0;j<i;j++)
		{
			Separate_Digit(f_data[j],ip);		
			len=strlen(ip);
			printf("%d :",f_data[j]);
			Spell_Out(data,ip,len);
			printf("\n");

		}	
	}while(0);
	return 1;
}

/*******************************************************************************/
/*!   \fn  void Separate_Digit(unsigned int dig,char *ip) 
 *
 *    \brief    seperate each digit from string and fill in char array
 *
 *    \param    [IN]  dig- number to be seperate
 *    \param    [IN]  ip - store seperated number in equivalent string 
 */  
/*******************************************************************************/
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

/*******************************************************************************/
/*!   \fn  void Spell_Out(char data[4][10][10],char ip[10],int len) 
 *
 *    \brief   print the numbers into their equivalent english text 
 *
 *    \param    [IN]  data- array of english text
 *    \param    [IN]  ip- number to be print
 *    \param    [IN]  len- lengtht of string 
 */  
/*******************************************************************************/
void Spell_Out(char data[4][10][10],char ip[10],int len)
{
	int num=0;

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

	}
}

/*******************************************************************************/
/*!   \fn	void Show_One(char ele[1][10],int tmp )	
 *
 *    \brief   print  numbers into their equivalent english text if number between 1 to 9
 *
 *    \param    [IN]  ele- array of english text
 *    \param    [IN]  dig- digit to print
 */  
/*******************************************************************************/
void Show_One(char ele[1][10],int dig )
{
	printf("%s ",ele[dig]);
}
/*******************************************************************************/
/*!   \fn	void showten(char ele[1][10],char dig)	
 *
 *    \brief   print  numbers into their equivalent english text if number between 10 to 19
 *
 *    \param    [IN]  ele- array of english text
 *    \param    [IN]  dig- digit to print
 */  
/*******************************************************************************/

void showten(char ele[1][10],char dig)
{
	int num=0;
	char buff[2]={0};
	snprintf(buff,2,"%c",dig);
	num=atoi(buff);
	printf("%s ",ele[num]);
}

/*******************************************************************************/
/*!   \fn	void showten1(char ele1[1][10],char ele2[1][10],char dig0,char dig1) 
 *
 *    \brief   print  numbers into their equivalent english text if number between 20 to 99
 *
 *    \param    [IN]  ele1- array of english text
 *    \param    [IN]  ele2- array of english text
 *    \param    [IN]  dig0- digit to print
 *    \param    [IN]  dig1- place to print
 */  
/*******************************************************************************/
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

/*******************************************************************************/
/*!   \fn 	void Show_Hundred(char ele1[1][10],char ele2[1][10],char dig0,char dig1) 
 *
 *    \brief   print  numbers into their equivalent english text if digit place is hundred
 *
 *    \param    [IN]  ele1- array of english text
 *    \param    [IN]  ele2- array of english text
 *    \param    [IN]  dig0- digit to print
 *    \param    [IN]  dig1- place to print
 */  
/*******************************************************************************/
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

/*******************************************************************************/
/*!   \fn    int CheckDigit(char num[10]) 
 *
 *    \brief    Check for integer data
 *
 *    \param    [IN]  num - number string from file
 */
/*******************************************************************************/
int CheckDigit(char num[10])
{
	int len=0,i=0;
	len=strlen(num);
	for(i=0;i<len;i++)
	{
		if((num[i]<48 || num[i]>57))
		{
			return -1;
		}
	}
	return 1;
}

/*******************************************************************************/
/*!   \fn     void SortData(int i, int *f_data) 
 *
 *    \brief    To sort the file data
 *
 *    \param    [IN]  i- number of elements in array
 *    \param    [IN]  f_data - data array
 */
/*******************************************************************************/
void SortData(int i, int *f_data)
{
	int j=0,k=0,tmp=0;
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
}
