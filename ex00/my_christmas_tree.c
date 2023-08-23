#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_final_tree_width(int num) {
  int initial = 1;
  int buffer = 6;
  int i = 0;
  while (i < num) {
    if (i != 0 && i % 2 == 0) {
      buffer += 2;
    }
    initial += buffer;
    i++;
  }
  return initial;
}

void my_christmas_tree(int num) {
  int buffer = get_final_tree_width(num);
  int rounds = 4;
  int iteration = 0;
  int decreaser = 2;
  char string[buffer + 1];
  memset(string, 0, sizeof(string));
  int to_remove = 2;
  strncat(string, "*", buffer);
  int halfway = buffer / 2;
  for (int i = 0; i < buffer / 2; i++) {
    printf(" ");
  }
  int asterisk_count = 1;
  int trimmer = 2;
  while (iteration < num) {
    int is_even_iteration = iteration % 2 == 1;
    int round_iteration = 1;

    if (iteration > 0) {
      rounds++;
      int current_length = strlen(string);
      int new_length = current_length - 2;
      memset(string, 0, sizeof(string));
      while (new_length > 0) {
        strncat(string, "*", buffer);
        new_length--;
      }
      if (is_even_iteration && iteration > 2) {
        decreaser += 1;
      }
      halfway += decreaser;
    }

    while (round_iteration <= rounds) {
      if (round_iteration == 1 && iteration == 0) {
        printf("%s\n", string);
      } else {

        strncat(string, "**", buffer);
        halfway -= 1;
        for (int i = 0; i < halfway; i++) {
          printf(" ");
        }
        if (round_iteration == 1 && iteration > 2) {
          if (is_even_iteration && iteration > 3) {
            trimmer+=2;
          }
          string[strlen(string) - trimmer] = '\0';
        }
        string[sizeof(string) - 1] = '\0';
        printf("%s\n", string);
      }
      round_iteration++;
    }
    string[strlen(string) - to_remove] = '\0';
    iteration++;
  }
  int trunk_iterator = num;
  int value = ((buffer) / 2);

  int trunk_width = num;
  int limit = (buffer - trunk_width) / 2;

  int is_even = num % 2 == 0;
  int reduction = is_even && num > 3 ? ((num - 2) / 2) : 0;
  // printf("reduction: %d\n", reduction);
  limit = is_even ? (limit + 1) : limit;

  while (trunk_iterator > 0) {
    for (int i = 0; i < limit; i++) {
      printf(" ");
      // printf("%d", i);
    }
    for (int i = 0; i < num; i++) {
      if (i + 1 == num) {
        printf("|\n");
      } else {
        printf("|");
      }
    }
    trunk_iterator--;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <num>\n", argv[0]);
    return 1;
  }

  int num = atoi(argv[1]);

  my_christmas_tree(num);

  return 0;
}