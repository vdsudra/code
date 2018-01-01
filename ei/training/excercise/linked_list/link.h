struct subject
{
	float s1;
	float s2;
	float s3;
	float s4;
	float sem_total;
};
struct student
{
//	unsigned int srno;
	int id;
	char name[20];
	char sex[2];
	struct subject midsem;
	struct subject final;
	float total;
	struct student *next;
	struct student *prev;
};
int add_record(struct student **,struct student **,int *);
int delete_record(struct student **,struct student **);
int update_info(struct student *);
int update_student(struct student **,struct student **);
int view_all_head(struct student **);
int view_all_tail(struct student **);
int calc_avg(struct student **,struct student **);
int show_max(struct student **,struct student **);
int show_min(struct student **,struct student **);
int find_by_id(struct student **,struct student **);
int sort_all(struct student **,struct student **,int *);

