


int main() {
    char **emails;
    int currentSize = INITIAL_SIZE;
    
    // Allocate memory for email array using calloc
    emails = (char **)calloc(INITIAL_SIZE, sizeof(char *));
    if (emails == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Allocate memory for each email string
    for (int i = 0; i < INITIAL_SIZE; i++) {
        emails[i] = (char *)malloc(EMAIL_LENGTH * sizeof(char));
        if (emails[i] == NULL) {
            printf("Memory allocation failed for email %d!\n", i);
            return 1;
        }
    }
    
    // Store sample email addresses
    strcpy(emails[0], "student1@university.edu");
    strcpy(emails[1], "student2@university.edu");
    strcpy(emails[2], "student3@university.edu");
    strcpy(emails[3], "student4@university.edu");
    strcpy(emails[4], "student5@university.edu");
    strcpy(emails[5], "student1@university.edu"); // Duplicate
    strcpy(emails[6], "student6@university.edu");
    strcpy(emails[7], "student7@university.edu");
    strcpy(emails[8], "student8@university.edu");
    strcpy(emails[9], "student2@university.edu"); // Duplicate
    
    // Function pointer declaration
    void (*functionPtr)(char **, int *);
    
    // Display initial emails
    printf("Initial emails:\n");
    displayEmails(emails, currentSize);
    
    // Remove duplicates using function pointer
    functionPtr = removeDuplicates;
    functionPtr(emails, &currentSize);
    
    printf("\nAfter removing duplicates:\n");
    displayEmails(emails, currentSize);
    
    // Resize array to 6 students using realloc
    emails = (char **)realloc(emails, FINAL_SIZE * sizeof(char *));
    if (emails == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    
    currentSize = FINAL_SIZE;
    
    printf("\nAfter resizing to %d students:\n", FINAL_SIZE);
    displayEmails(emails, currentSize);
    
    // Free allocated memory
    for (int i = 0; i < FINAL_SIZE; i++) {
        free(emails[i]);
    }
    free(emails);
    
    printf("\nMemory successfully freed!\n");
    
    return 0;
}