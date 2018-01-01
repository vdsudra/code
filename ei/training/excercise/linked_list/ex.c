#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"ll.h"
int main()
{
	struct pointer ptr;
	int op;
	system("clear");
	printf("\t\t\t\tWelcome\n");
	printf("\t\t=============================================\n");
	ptr.no=1;
	ptr.head=NULL;
	ptr.tail=NULL;
	ptr.f=fopen("id_record","r");
	if(ptr.f!=NULL)
	{
		remove("id_record");		
		fclose(ptr.f);
	}
	ptr.f=fopen("id_record","w");
	if(ptr.f==NULL)
	{
		perror("error");
		return 0;
	}
	fclose(ptr.f);
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
					add_record(&ptr);
					break;
				}
			case 2:
				{
					delete_record(&ptr);
					view_all_head(&ptr);
					break;
				}
			case 3:
				{
					update_student(&ptr);
					break;
				}
			case 4:
				{
					view_all_head(&ptr);
					break;
				}
			case 5:
				{
					calc_avg(&ptr);					
					break;
				}
			case 6:
				{
					show_max(&ptr);
					break;
				}
			case 7:
				{
					show_min(&ptr);	
					break;
				}
			case 8:
				{
					find_by_id(&ptr);
					break;
				}
			case 9:
				{
					sort_all(&ptr);
					view_all_head(&ptr);
					break;
				}
			case 10:
				{
					view_all_tail(&ptr);
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
int add_record(struct pointer *ptr)
{
	int op;
	int id,idf;
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
here:	printf("Enter Id:");
	scanf(" %d",&id);
	ptr->f=fopen("id_record","r");
	if(ptr->f==NULL)
	{
		free(tmp);
		perror("Error");
		return 0;
	}

	while((fscanf(ptr->f,"%d",&idf))!=EOF)
	{
		if(idf==id)
		{
			printf("ID already available choose different id and try again\n");
			goto here;
		}
	}
	fclose(ptr->f);
	ptr->f=fopen("id_record","a");
	if(ptr->f==NULL)
	{
		free(tmp);
		perror("Error");
		return 0;
	}
	fprintf(ptr->f,"%d\n",id);
	fclose(ptr->f);
	tmp->id=id;
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
		if(ptr->tail==NULL)
		{
			ptr->tail=tmp;
		}
		tmp->prev=NULL;
		if((ptr->head)!=NULL)	
			(ptr->head)->prev=tmp;
		tmp->next=(ptr->head);
		(ptr->head)=tmp;
		printf("\n");	
		(ptr->no)++;	
		return 1;
	}
	if(op==2)
	{
		if((ptr->head)==NULL)
		{
			(ptr->head)=tmp;
		}
		tmp->next=NULL;
		if((ptr->tail)!=NULL)	
			(ptr->tail)->next=tmp;
		tmp->prev=(ptr->tail);
		(ptr->tail)=tmp;
		printf("\n");	
		(ptr->no)++;	
		return 1;
	}
	free(tmp);
	return 0;
}
/*************************************DELETE*********************************/
/*
Delete student detail of given id.
*/
int delete_record(struct pointer *ptr)
{
	int id;
	printf("Enter Student Id:");
	scanf("%d",&id);
	struct student *tmp=ptr->head;
	if(tmp->id==id)
	{
		tmp->next->prev=NULL;
		(ptr->head)=tmp->next;
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
		(ptr->tail)=tmp->prev;
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
int update_student(struct pointer *ptr)
{
	int op;
	struct student *tmp=ptr->head;
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
int view_all_head(struct pointer *ptr)
{
	system("clear");
	struct student *tmp=ptr->head;
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
int view_all_tail(struct pointer *ptr)
{
	system("clear");
	struct student *tmp=ptr->tail;
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
int calc_avg(struct pointer *ptr)
{
	int id;
	printf("Enter Id:");
	scanf("%d",&id);
	struct student *tmp=ptr->head;
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
int find_by_id(struct pointer *ptr)
{
	int op;
	printf("Enter Id:");
	scanf("%d",&op);
	struct student *tmp=ptr->head;
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
int show_max(struct pointer *ptr)
{
	float temp=0.0;
	struct student *max_temp=NULL;
	struct student *tmp=ptr->head;
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
int show_min(struct pointer *ptr)
{
	float temp;
	struct student *min_temp;
	struct student *tmp=ptr->head;
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
int sort_all(struct pointer *ptr)
{
	int i,j;
	struct student *t;
	struct student *w;
	struct student *head;
	struct student *tmp;
	head=ptr->head;
	tmp=head->next;
	w=tmp;
	for(i=1;i<((ptr->no)-1);i++)
	{
		for(j=1;j<((ptr->no)-i);j++)
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
