#include <stdio.h>
#include <stdlib.h>

#define STDIN_FILENO 0

int main(int argc, char *argv[])
{

  char* l = NULL;
  size_t n;
  //While there are data, read one line at a time from the standard in (piped data)
  while (getline(&l,&n, stdin) != -1 )
    {
      printf("Hello %s",l);
    }
  free(l);

  printf("Hello World\n");

  //Read the second onwards arguments (the first is the program name)
  for (int i = 1; i < argc; i++) {
    printf("Hello %s\n", argv[i]);
  }
  return 0;
}
