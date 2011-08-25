/*
$ gcc -o dns-discovery dns-discovery.c -Wall -Wextra
$ ./dns-discovery google.com hosts.txt 

DNS Discovery
  by m0nad [at] email.com

academico.google.com
accounts.google.com
ads.google.com
alerts.google.com
ap.google.com
apps.google.com
...
*/

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#define TAM 256
#define MAX 512
#define SAY puts
FILE *
ck_fopen (char * arq, char * perm)
{
  FILE * file = fopen (arq, perm);
  if (file == NULL) {
    perror ("fopen ");
    exit (1);
  }
  return file;
}
void
banner ()
{
  SAY ("\nDNS Discovery\n  by m0nad [at] email.com\n");
}
int
usage ()
{
  SAY (" usage\n ./dns-discovery domain hosts.txt");
  exit (1);
}
void
chomp (char * str)
{
  while (*str) {
    if (*str == '\n' || *str == '\r') {
      *str = 0;
      return;
    }
    str++;
  }
}
void
dns_discovery (char * host)
{
  struct hostent * hostip;
  if ((hostip = gethostbyname (host)) != NULL) {
    SAY (host);
  } 
}

int
main (int argc, char ** argv) 
{
  FILE * file;
  char line [TAM];
  char host [MAX];
  banner();
  if (argc < 3) 
    usage();
 
  file = ck_fopen (argv[2], "r");
  while (fgets (line, sizeof line, file) != NULL) {
    chomp (line);
    snprintf  (host, sizeof host, "%s.%s", line, argv[1]);
    dns_discovery (host);
  }
  fclose (file);
//  free (hostip);
  return 0;
}
