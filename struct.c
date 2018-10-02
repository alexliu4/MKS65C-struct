#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct location{char *name; char *leader; };

void rand_location() {
  char *array[5];
  array[0] = "America";
  array[1] = "Hogwarts";
  array[3] = "Stuyvesant";
  time_t t = time(NULL);
  srand(t);
  printf("%s\n", array[rand() % 3]);
}

struct location take_over_location(struct location f, char *new_leader) {
  f.leader = new_leader;
  return f;
}
void print_location(struct location f) {
  printf("%s is led by %s\n", f.name, f.leader);
}

int main() {
  struct location p;
  p.name = "Galaxy";
  p.leader = "Darth Vader";
  print_location(p);
  p = take_over_location(p, "Thanos");
  print_location(p);

  rand_location();
  return 0;
}
