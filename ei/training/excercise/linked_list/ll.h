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
struct pointer
{
	int no;
	FILE *f;
	struct student *head;
	struct student *tail;
};

int add_record(struct pointer *);
int delete_record(struct pointer *);
int update_info(struct student *);
int update_student(struct pointer *);
int view_all_head(struct pointer *);
int view_all_tail(struct pointer *);
int calc_avg(struct pointer *);
int show_max(struct pointer *);
int show_min(struct pointer *);
int find_by_id(struct pointer *);
int sort_all(struct pointer *);

