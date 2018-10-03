#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[30];
    char leader[30];
    unsigned int population;
} location;

char names[5][30] = 
  {"America", "Hogwarts", "Stuyvesant", "Nakatomi Plaza", "Area 51"};
char leaders[5][30] = 
  {"Darth Vader", "Donald Trump", "Mr. Konstantinovich", "Bernie Sanders", "Sauron"};

location rand_location() {
  location temp;
  strcpy(temp.name, names[rand() % 5]);
  strcpy(temp.leader, leaders[rand() % 5]); 
  temp.population = rand() % 10000;
  return temp;
}

location conquer(location *p, char *new_leader) {
  strcpy(p->leader, new_leader);
  p->population *= ((float)rand() / RAND_MAX);
  return *p;
}

void print_location(location loc) {
  printf("%s is controlled by %s and has a population of %d\n",
          loc.name, loc.leader, loc.population);
}

int main() {
  srand(time(NULL));
  location p = rand_location();
  print_location(p);
  print_location(conquer(&p, "Mr. Peanut"));
  print_location(conquer(&p, "Paul McCartney"));
  location q = rand_location();
  print_location(q);
  print_location(conquer(&q, "Barry Allen"));
  print_location(conquer(&q, "Phil Swift"));
  return 0;
}
