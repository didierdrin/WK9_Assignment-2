#include <stdio.h>
#include <string.h>

#define MAX_NAMES 20
#define NAME_LENGTH 50

// Function to swap two strings
void swap(char *str1, char *str2) {
  char temp[NAME_LENGTH];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

// Function for ascending order sorting
void sortAscending(char names[][NAME_LENGTH], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(names[j], names[j + 1]) > 0) {
        swap(names[j], names[j + 1]);
      }
    }
  }
}

// Function for descending order sorting
void sortDescending(char names[][NAME_LENGTH], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(names[j], names[j + 1]) < 0) {
        swap(names[j], names[j + 1]);
      }
    }
  }
}

int main() {
  char names[MAX_NAMES][NAME_LENGTH] = {
      "John Smith",    "Alice Johnson", "Bob Williams",    "Carol Brown",
      "David Jones",   "Eva Davis",     "Frank Miller",    "Grace Wilson",
      "Henry Moore",   "Ivy Taylor",    "Jack Anderson",   "Karen Thomas",
      "Leo Jackson",   "Mia White",     "Nick Harris",     "Olivia Martin",
      "Paul Thompson", "Queen Garcia",  "Robert Martinez", "Sarah Robinson"};

  char order[5];
  printf("Enter sort order (asc/desc): ");
  scanf("%s", order);

  // Function pointer declaration
  void (*sortFunction)(char[][NAME_LENGTH], int);

  // Assign function to pointer based on user choice
  if (strcmp(order, "asc") == 0) {
    sortFunction = sortAscending;
  } else if (strcmp(order, "desc") == 0) {
    sortFunction = sortDescending;
  } else {
    printf("Invalid order! Using ascending by default.\n");
    sortFunction = sortAscending;
  }

  // Call sorting function through pointer
  sortFunction(names, MAX_NAMES);

  printf("\nSorted Names:\n");
  for (int i = 0; i < MAX_NAMES; i++) {
    printf("%d. %s\n", i + 1, names[i]);
  }

  return 0;
}
