#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char string1[100], string2[100], userAnswer[200], correctAnswer[200];
    int choice;
    int score = 0;

    // Set predefined questions and answers
    strcpy(string1, "alphabet");
    strcpy(string2, "education");

    printf("Welcome to the String Operations Quiz!\n");
    printf("Solve the following challenges to test your string manipulation skills.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Count vowels in a string\n");
        printf("2. Compare strings\n");
        printf("3. Copy one string into another\n");
        printf("4. Find the length of a string\n");
        printf("5. Concatenate strings\n");
        printf("6. View Score and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1: // Count vowels
                printf("Question: How many vowels are there in the string \"%s\"? ", string1);
                int correctCount = countVowels(string1);
                int userCount;
                scanf("%d", &userCount);
                getchar(); // Clear input buffer

                if (userCount == correctCount) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is: %d\n", correctCount);
                }
                break;

            case 2: // Compare strings
                printf("Question: Are the strings \"%s\" and \"%s\" equal? (yes/no): ", string1, string2);
                fgets(userAnswer, sizeof(userAnswer), stdin);
                userAnswer[strcspn(userAnswer, "\n")] = '\0'; // Remove newline

                if (strcmp(string1, string2) == 0) {
                    strcpy(correctAnswer, "yes");
                } else {
                    strcpy(correctAnswer, "no");
                }

                if (strcmp(userAnswer, correctAnswer) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is: %s\n", correctAnswer);
                }
                break;

            case 3: 
                printf("Question: If you copy \"%s\" into String1, what will String2 become? ", string2);
                fgets(userAnswer, sizeof(userAnswer), stdin);
                userAnswer[strcspn(userAnswer, "\n")] = '\0'; 

                strcpy(correctAnswer, string1);

                if (strcmp(userAnswer, correctAnswer) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is: %s\n", correctAnswer);
                }
                break;

            case 4: // Find the length of strings
                printf("Question: What is the length of the string \"%s\"? ", string1);
                int length = strlen(string1);
                int userLength;
                scanf("%d", &userLength);
                getchar(); // Clear input buffer

                if (userLength == length) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is: %d\n", length);
                }
                break;

            case 5: // Concatenate strings
                printf("Question: If you concatenate \"%s\" and \"%s\", what is the result? ", string1, string2);
                fgets(userAnswer, sizeof(userAnswer), stdin);
                userAnswer[strcspn(userAnswer, "\n")] = '\0'; // Remove newline

                strcpy(correctAnswer, string1);
                strcat(correctAnswer, string2);

                if (strcmp(userAnswer, correctAnswer) == 0) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is: %s\n", correctAnswer);
                }
                break;

            case 6: // Exit and show score
                printf("Quiz Over! Your total score is: %d/5\n", score);
                printf("Thank you for playing!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
} 