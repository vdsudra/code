#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>

struct message
{
  long int msg_type;
		  /*---------*/
  char text[100];
};

int
main ()
{
  int running = 1;
  int msgid;
  struct message recv_msg;
  struct message send_msg;
  long int msg_to_receive = 55;
			   /***********/

  msgid = msgget (123, 0644 | IPC_CREAT);
  if (msgid < 0) {
    printf ("msgget Failed\n");
    exit (0);
  }
  while (running) {
    if (msgrcv (msgid, (void *) &recv_msg, 100, msg_to_receive, 56) == -1) {
      fprintf (stderr, "message receive fail");
      exit (0);
    }
    printf ("hello\n");
    printf ("You wrote:%s", recv_msg.text);
    if (strncmp (recv_msg.text, "end", 3) == 0) {
      running = 0;
    }
  }
  if (msgctl (msgid, IPC_RMID, 0) == -1) {
    fprintf (stderr, "msgctl fail");
    exit (0);
  }
  exit (1);
}
