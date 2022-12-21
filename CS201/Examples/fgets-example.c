// jdh CS201 Spring 2023
// example of reading terminal input

#include <string.h>
#include <stdio.h>

#define INPUTBUFLEN 256

int main() {
  int done, len;
  char buffer[INPUTBUFLEN];
  char *chp;

  done = 0;
  while ( ! done ) {
    printf("> ");
    chp = fgets(buffer, INPUTBUFLEN, stdin);
    if (chp != NULL) {
      len = strlen(buffer);
      // strip off the newline char if it's present
      if (buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
        len = len - 1;
      }
      printf("|%s|\n", buffer);

      if ( ! strcmp(buffer, "quit") ) {
        done = 1;
      }
    }
  }

  return 0;
}
