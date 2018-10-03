#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct location {
    char name[30];
    char villian[30];
    unsigned int population;
};

char names[10][30] = 
  {"America", "Hogwarts", "Stuyvesant", "Nakatomi Plaza", "Area 51", "Middle Earth", "Gondor", "Gotham", "Asgard", "Brooklyn 99 Precint"};
char villians[10][30] = 
  {"Darth Vader", "Donald Trump", "Mr. Konstantinovich", "Bernie Sanders", "Sauron", "Hans Gruber", "Joker", "Loki", "Bane", "Chief Deputy Wuntch"};

struct location rand_location() {
  struct location temp;
  strcpy(temp.name, names[rand() % 10]);
  strcpy(temp.villian, villians[rand() % 10]); 
  temp.population = rand() % 10000;
  return temp;
}

void conquer(struct location *p, char *new_villian) {
  strcpy(p->villian, new_villian);
  p->population *= ((float)rand() / RAND_MAX);
}

void rename_location(struct location *p) {
  p->name[0] = 'A';
}

void print_location(struct location loc) {
  printf("%s is controlled by %s and has a population of %d\n",
          loc.name, loc.villian, loc.population);
}

int main() {
  srand(time(NULL));
  struct location p = rand_location();
  print_location(p);
  conquer(&p, "Mr. Peanut");
  print_location(p);
  conquer(&p, "Paul McCartney"); 
  rename_location(&p);
  print_location(p);
  return 0;
}
