#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>

struct message
{
  long int msg_type;
  char text[100];
};

int
main ()
{
  int running = 1;
  int msgid;
  char buffer[100];
  struct message send_msg;
  struct message recv_msg;
  msgid = msgget (123, 0644 | IPC_CREAT);
  if (msgid < 0) {
    printf ("msgget Failed\n");
    exit (0);
  }
  while (running) {
    printf ("Enter some text:");
    fgets (buffer, 100, stdin);
    send_msg.msg_type = 5;
    strcpy (send_msg.text, buffer);
    if (msgsnd (msgid, (void *) &send_msg, 100, 0) == -1) {
      fprintf (stderr, "message sending fail");
      exit (0);
    }
    if (strncmp (buffer, "end", 3) == 0) {
      running = 0;
    }
  }
  exit (1);
}
