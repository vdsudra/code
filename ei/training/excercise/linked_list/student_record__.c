#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link.h"
int main()
{
	struct student *root=NULL;
	unsigned int op;
	int no=1;
	system("clear");
	printf("\t\t\t\tWelcome\n");
	printf("\t\t=============================================\n");
	while(1)
	{
		printf("Select Your Option\n");
		printf("1. Add student records\n2. Delete student records\n3. Update student records\n"
				"4. View all student records\n5. Calculate an average of a selected student’s scores\n"
				"6. Show student who gets the max total score\n7. Show student who gets the min total score\n"
				"8. Find student by ID\n9. Sort records by total scores\n0.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					add_record(&root,&no);
					break;
				}
			case 2:
				{
					delete_record(&root);
					break;
				}
			case 3:
				{
					update_student(&root);
					break;
				}
			case 4:
				{
					view_all(&root);
					break;
				}
			case 5:
				{
					calc_avg(&root);					
					break;
				}
			case 6:
				{
					show_max(&root);
					break;
				}
			case 7:
				{
					show_min(&root);	
					break;
				}
			case 8:
				{
					find_by_id(&root);
					break;
				}
			case 9:
				{
					sort_all(&root,&no);
					break;
				}
			case 0:
				{
					return 0;
				}
			default :
				{
					printf("Invalid Option selected\n");
				}
		}
	}
}

/*******************ADD***************************************************/
int add_record(struct student **r,int *no)
{
	char ch;
	struct student *tmp=NULL;
	int op;
	tmp=(struct student *)malloc(sizeof(struct student));
	if(tmp==NULL)
	{
		perror("Error");
		return 0;
	}
	memset(tmp,0,sizeof(struct student));
	printf("Enter Name:");
	scanf(" %s",tmp->name);
	printf("Enter Id:");
	scanf(" %d",&tmp->id);
	while(getchar()!='\n');
	printf("Enter sex 'm' for Male and 'f' for Female:");
	scanf("%c",&ch);
	if(ch=='m' || ch== 'M')
	{
		strcpy(tmp->sex,"M");
	}
	else if(ch=='f' || ch=='F')
	{
		strcpy(tmp->sex,"F");
	}
	else 
	{
		printf("Invalid option\n");
		free(tmp);
		return 0;
	}
	tmp->next=*r;
	*r=tmp;
	printf("\n");	
	(*no)++;	
	return 1;
}
/*************************************DELETE*********************************/
int delete_record(struct student **r)
{
	int id;
	struct student *t;
	printf("Enter Student Id:");
	scanf("%d",&id);
	struct student *tmp=*r;
	if(tmp->id==id)
	{
		*r=tmp->next;
		free(tmp);
		return 1;
	}
	t=tmp;
	tmp=tmp->next;
	while(tmp->next!=NULL)
	{
		if(tmp->id==id)
		{
			t->next=tmp->next;
			free(tmp);
			return 0;
		}
		t=tmp;
		tmp=tmp->next;
	}
	if(tmp->id==id)
	{
		t->next=NULL;
		free(tmp);
	}
	else
		printf("Invalid Id\n");
	return 1;
}


/****************************UPDATE******************************************/
int update_student(struct student **r)
{
	int op;
	struct student *tmp=*r;
	printf("Enter Student Id\n");
	scanf("%d",&op);
	while(tmp!=NULL)
	{
		if(tmp->id==op)
		{
			update_info(tmp);
			return 1;
		}
		tmp=tmp->next;
	}
	printf("Invalid Student id\n");
	return 0;
}

int update_info(struct student *tmp)
{
	float gross=0.00;
	int op;
	printf("Enter 1 for mid-sem marks & 2 for final marks\n");
	scanf("%d",&op);
	if(op==1)
	{
		printf("Enter Subject 1 marks:");
		scanf(" %f",&tmp->midsem.s1);
		printf("Enter Subject 2 marks:");
		scanf(" %f",&tmp->midsem.s2);
		printf("Enter Subject 3 marks:");
		scanf(" %f",&tmp->midsem.s3);
		printf("Enter Subject 4 marks:");
		scanf(" %f",&tmp->midsem.s4);
		gross=tmp->midsem.s1+tmp->midsem.s2+tmp->midsem.s3+tmp->midsem.s4;
		tmp->midsem.sem_total=gross;
	}
	else if(op==2)
	{
		printf("Enter Subject 1 marks:");
		scanf(" %f",&tmp->final.s1);
		printf("Enter Subject 2 marks:");
		scanf(" %f",&tmp->final.s2);
		printf("Enter Subject 3 marks:");
		scanf(" %f",&tmp->final.s3);
		printf("Enter Subject 4 marks:");
		scanf(" %f",&tmp->final.s4);
		gross=tmp->final.s1 + tmp->final.s2+tmp->final.s3+tmp->final.s4;
		tmp->final.sem_total=gross;
	}
	else
	{
		printf("Invalid choice\n");
		return 0;
	}
	tmp->total=tmp->final.sem_total+tmp->midsem.sem_total;
	return 1;
}

/************************VIEWALL**********************************************/
int view_all(struct student **r)
{
	struct student *tmp=*r;
	while(tmp != NULL)
	{
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\nName:%s",tmp->name);
		printf("\nId:%d",tmp->id);
		printf("\nSex:%s",tmp->sex);
		printf("\nMidsem marks:");
		printf("Subject1:%4.2f\tSubjectr2:%4.2f\tSubject3:%4.2f\tSubject4:%4.2f\n",tmp->midsem.s1,tmp->midsem.s2,tmp->midsem.s3,tmp->midsem.s4);
		printf("\nFinal  marks:");
		printf("Subject1:%4.2f\tSubjectr2:%4.2f\tSubject3:%4.2f\tSubject4:%4.2f\n",tmp->final.s1,tmp->final.s2,tmp->final.s3,tmp->final.s4);
		printf("\nTotal Marks:%f\n",tmp->total);
		tmp=tmp->next;
	}
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	return 1;
}
/******************************AVG****************************************/
int calc_avg(struct student **r)
{
	int id;
	printf("Enter Id:");
	scanf("%d",&id);
	struct student *tmp=*r;
	while(tmp!=NULL)
	{
		if(tmp->id==id)
		{
			printf("Average score:%f\n",(tmp->midsem.sem_total+tmp->final.sem_total)/8);
			return 1;
		}
		tmp=tmp->next;
	}
	printf("Invalid Id\n");
	return 1;
}

/**************************************FINDBYID***********************************/
int find_by_id(struct student **r)
{
	int op;
	printf("Enter Id:");
	scanf("%d",&op);
	struct student *tmp=*r;
	while(tmp!=NULL)
	{
		if(tmp->id==op)
		{
			printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\nName:%s",tmp->name);
			printf("\nId:%d",tmp->id);
			printf("\nSex:%s",tmp->sex);
			printf("\nMidsem marks:");
			printf("Subject1:%4.2f\tSubjectr2:%4.2f\tSubject3:%4.2f\tSubject4:%4.2f\n",tmp->midsem.s1,tmp->midsem.s2,tmp->midsem.s3,tmp->midsem.s4);
			printf("\nFinal  marks:");
			printf("Subject1:%4.2f\tSubjectr2:%4.2f\tSubject3:%4.2f\tSubject4:%4.2f\n",tmp->final.s1,tmp->final.s2,tmp->final.s3,tmp->final.s4);
			printf("\nTotal Marks:%f\n",tmp->total);
			return 1;
		}
		tmp=tmp->next;
	}
	printf("Invalid Id\n");
	return 1;
}

/***************************************MAX************************/
int show_max(struct student **r)
{
	float temp=0.0;
	struct student *m_temp=NULL;
	struct student *tmp=*r;
	while(tmp!=NULL)
	{
		if((tmp->total) > temp)
		{
			temp=tmp->total;
			m_temp=tmp;
		}
		tmp=tmp->next;
	}
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\nName:%s",m_temp->name);
	printf("\nId:%d",m_temp->id);
	printf("\nTotal Marks:%f\n",m_temp->total);
	return 1;
}

/****************************************MIN***************/
int show_min(struct student **r)
{
	float temp;
	struct student *min_temp=NULL;
	struct student *tmp=*r;
	temp=tmp->total;
	while(tmp!=NULL)
	{
		if((tmp->total) < temp)
		{
			temp=tmp->total;
			min_temp=tmp;
		}
		tmp=tmp->next;
	}

	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\nName:%s",min_temp->name);
	printf("\nId:%d",min_temp->id);
	printf("\nTotal Marks:%f\n",min_temp->total);
	return 1;
}

/***************************************SORT**************************/

int sort_all(struct student **r,int *no)
{
	int i,j;
	struct student *t;
	struct student *root;
	struct student *tmp;
	tmp=(*r)->next;
	root=*r;
	for(i=1;i<=*no;i++)
	{
		for(j=1;j<=i;j++)
		{
			while(tmp!=NULL)
			{
				if((root->total) > (tmp->total))
				{
					t=tmp->next;
					tmp->next=root;
					root->next=t;
					root=tmp;
					*r=tmp;
					tmp=t;
					break;
				}
				tmp=tmp->next;
				break;
			}
		}
	}	
	return 1;
}
