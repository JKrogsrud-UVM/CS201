// jdh CS201 Spring 2023

#include <string.h>
#include <stdio.h>

#define MAXNAMELEN 64

int main() {
  char s1[MAXNAMELEN], s2[MAXNAMELEN];
  int res;

  strcpy(s1, "I Can't Stand The Rain");
  strcpy(s2, "I Can't Stand The Rain");
  res = strcmp(s1, s2);
  printf("compare '%s' to '%s': result is %d\n", s1, s2, res);

  strcpy(s1, "Missy Elliott");
  strcpy(s2, "Ann Peebles");
  res = strcmp(s1, s2);
  printf("compare '%s' to '%s': result is %d\n", s1, s2, res);

  strcpy(s1, "Windows");
  strcpy(s2, "windows");
  res = strcmp(s1, s2);
  printf("compare '%s' to '%s': result is %d\n", s1, s2, res);

  return 0;
}
