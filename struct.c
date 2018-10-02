#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct foo{int x; char* p; };

time_t t = time(NULL);
//printf("current time: %lu\n \n", t );

srand(t);



int main() {
  return 0;
}
