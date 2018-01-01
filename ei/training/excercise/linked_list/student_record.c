#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link.h"
int main()
{
	struct student *head=NULL;
	struct student *tail=NULL;
	unsigned int op;
	int no=1;
	system("clear");
	printf("\t\t\t\tWelcome\n");
	printf("\t\t=============================================\n");
	while(1)
	{	
		printf("Select Your Option\n");
		printf("1. Add student records\n2. Delete student records\n3. Update student records\n"
				"4. View all student records from head\n5. Calculate an average of a selected student’s scores\n"
				"6. Show student who gets the max total score\n7. Show student who gets the min total score\n"
				"8. Find student by ID\n9. Sort records by total scores\n10.view all student record from tail\n0.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					add_record(&head,&tail,&no);
					break;
				}
			case 2:
				{
					delete_record(&head,&tail);
					view_all_head(&head);
					break;
				}
			case 3:
				{
					update_student(&head,&tail);
					break;
				}
			case 4:
				{
					view_all_head(&head);
					break;
				}
			case 5:
				{
					calc_avg(&head,&tail);					
					break;
				}
			case 6:
				{
					show_max(&head,&tail);
					break;
				}
			case 7:
				{
					show_min(&head,&tail);	
					break;
				}
			case 8:
				{
					find_by_id(&head,&tail);
					break;
				}
			case 9:
				{
					sort_all(&head,&tail,&no);
					view_all_head(&head);
					break;
				}
			case 10:
				{
					view_all_tail(&tail);
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
/*
Add new student in record with name,id and sex detail.
*/
int add_record(struct student **h,struct student **t,int *no)
{
	int op;
	struct student *tmp=NULL;
	char ch;
	printf("Enter 1 to add At head or 2 to add at tail\n");	
	scanf(" %d",&op);
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
	if(ch=='m' || ch=='M')
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

	if(op==1)
	{

		if((*t)==NULL)
		{
			(*t)=tmp;
		}
		tmp->prev=NULL;
		if((*h)!=NULL)	
			(*h)->prev=tmp;
		tmp->next=(*h);
		(*h)=tmp;
		printf("\n");	
		(*no)++;	
		return 1;
	}
	if(op==2)
	{
		if((*h)==NULL)
		{
			(*h)=tmp;
		}
		tmp->next=NULL;
		if((*t)!=NULL)	
			(*t)->next=tmp;
		tmp->prev=(*t);
		(*t)=tmp;
		printf("\n");	
		(*no)++;	
		return 1;
	}
	free(tmp);
	return 0;
}
/*************************************DELETE*********************************/
/*
Delete student detail of given id.
*/
int delete_record(struct student **h,struct student **t)
{
	int id;
	printf("Enter Student Id:");
	scanf("%d",&id);
	struct student *tmp=*h;
	if(tmp->id==id)
	{
		tmp->next->prev=NULL;
		(*h)=tmp->next;
		free(tmp);
		return 1;
	}
	tmp=tmp->next;
	while(tmp->next!=NULL)
	{

		if(tmp->id==id)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return 0;
		}
		tmp=tmp->next;
	}
	if(tmp->id==id)
	{
		tmp->prev->next=NULL;
		(*t)=tmp->prev;
		free(tmp);
		return 1;
	}
	printf("Invalid Id\n");
	return 1;
}

/****************************UPDATE******************************************/
/*
Upadate the marks of student of given id.
*/
int update_student(struct student **h,struct student **t)
{
	int op;
	struct student *tmp=*h;
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
/************************VIEWALL  HEAD**********************************************/
/*
View all student record one by one from head.
*/
int view_all_head(struct student **h)
{
	system("clear");
	struct student *tmp=*h;
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


/************************VIEWALL  TAIL**********************************************/
/*
View all student record one by one from tail.
*/
int view_all_tail(struct student **t)
{
	system("clear");
	struct student *tmp=*t;
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
		tmp=tmp->prev;
	}
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	return 1;
}


/******************************AVG****************************************/
/*
Calculate the average marks of student .
*/
int calc_avg(struct student **h,struct student **t)
{
	int id;
	printf("Enter Id:");
	scanf("%d",&id);
	struct student *tmp=*h;
	system("clear");
	while(tmp!=NULL)
	{
		if(tmp->id==id)
		{
			printf("Average score:%f\n",((tmp->midsem.sem_total)/4)+((tmp->final.sem_total)/4));
			return 1;
		}
		tmp=tmp->next;
	}
	printf("Invalid Id\n");
	return 1;
}

/**************************************FINDBYID***********************************/
/*
Find student detail using id.
*/
int find_by_id(struct student **h,struct student **t)
{
	int op;
	printf("Enter Id:");
	scanf("%d",&op);
	struct student *tmp=*h;
	system("clear");
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
/*
Find student who get maximum marks.
*/
int show_max(struct student **h,struct student **t)
{
	float temp=0.0;
	struct student *max_temp=NULL;
	struct student *tmp=*h;
	system("clear");
	while(tmp!=NULL)
	{
		if((tmp->total) > temp)
		{
			temp=tmp->total;
			max_temp=tmp;
		}
		tmp=tmp->next;
	}

	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\nName:%s",max_temp->name);
	printf("\nId:%d",max_temp->id);
	printf("\nTotal Marks:%f\n",max_temp->total);
	return 1;
}


/****************************************MIN***************/
/*
Find student who get minimum marks.
*/
int show_min(struct student **h,struct student **t)
{
	float temp;
	struct student *min_temp;
	struct student *tmp=*h;
	min_temp=tmp;
	temp=tmp->total;
	system("clear");
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
/*
sort all students according to final marks.
*/
int sort_all(struct student **h,struct student **tp,int *no)
{
	int i,j;
	struct student *t;
	struct student *w;
	struct student *head;
	struct student *tmp;
	head=*h;
	tmp=head->next;
	w=tmp;
	for(i=1;i<(*no-1);i++)
	{
		for(j=1;j<(*no-i);j++)
		{
			if((head->total) > (tmp->total))
			{
				t=(struct student *)malloc(sizeof(struct student));
				memset(t,0,sizeof(struct student));
				t->id=tmp->id;
				strcpy(t->name,tmp->name);
				strcpy(t->sex,tmp->sex);
				t->midsem.s1=tmp->midsem.s1;
				t->midsem.s2=tmp->midsem.s2;
				t->midsem.s3=tmp->midsem.s3;
				t->midsem.s4=tmp->midsem.s4;
				t->final.s1=tmp->final.s1;
				t->final.s2=tmp->final.s2;
				t->final.s3=tmp->final.s3;
				t->final.s4=tmp->final.s4;
				t->midsem.sem_total=tmp->midsem.sem_total;
				t->final.sem_total=tmp->final.sem_total;
				t->total=tmp->total;
				/**/
				tmp->id=head->id;
				strcpy(tmp->name,head->name);
				strcpy(tmp->sex,head->sex);
				tmp->midsem.s1=head->midsem.s1;	
				tmp->midsem.s2=head->midsem.s2;
				tmp->midsem.s3=head->midsem.s3;
				tmp->midsem.s4=head->midsem.s4;
				tmp->final.s1=head->final.s1;
				tmp->final.s2=head->final.s2;
				tmp->final.s3=head->final.s3;
				tmp->final.s4=head->final.s4;
				tmp->midsem.sem_total=head->midsem.sem_total;
				tmp->final.sem_total=head->final.sem_total;
				tmp->total=head->total;
				/**/
				head->id=t->id;
				strcpy(head->name,t->name);
				strcpy(head->sex,t->sex);
				head->midsem.s1=t->midsem.s1;
				head->midsem.s2=t->midsem.s2;
				head->midsem.s3=t->midsem.s3;
				head->midsem.s4=t->midsem.s4;
				head->final.s1=t->final.s1;
				head->final.s2=t->final.s2;
				head->final.s3=t->final.s3;
				head->final.s4=t->final.s4;
				head->midsem.sem_total=t->midsem.sem_total;
				head->final.sem_total=t->final.sem_total;
				head->total=t->total;
			}
			tmp=tmp->next;
		}
		head=w;
		tmp=head->next;
		w=head->next;
	}
	return 1;
}
