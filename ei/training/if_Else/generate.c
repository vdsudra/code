#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct TiMe
{
int Hr;
int Mn;
};
void GetTimeForEvent(struct TiMe *TiMe1)
{
        char buf[50];
        time_t curtime;
        struct tm *loc_time;
        curtime = time (NULL);
        loc_time = localtime (&curtime);
        strftime (buf, 50, "%I",loc_time);
        TiMe1->Hr=atoi(buf);
        strftime (buf,50, "%M",loc_time);
        TiMe1->Mn=atoi(buf);
}
void main()
{
	int M1,M2;
	struct TiMe time1,CurTime;
	GetTimeForEvent(&time1);
	while(1)
	{
		GetTimeForEvent(&CurTime);
		M1=(time1.Mn)+((time1.Hr)*60);
		M2=(CurTime.Mn)+((CurTime.Hr)*60);
		if(M2 > (M1+1))
		{
			time1.Hr=CurTime.Hr;
			time1.Mn=CurTime.Mn;
			printf("1 Minute Over\n");
		}

	}


}
