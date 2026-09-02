#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *end;

const char QUESTIONS_A[5][200] = {
    "What is the capital of New Zealand?\nA) Auckland B) Wellington\nC)Christchurch D) Hamilton",
    "Which city is known as 'The Garden City'?\nA) Wellington B) Christchurch\nC) Paeroa D) Auckland",
    "Where did L&P soda originally come from?\nA) Putaruru B) Waihi\nC) Paeroa D) Auckland",
    "In what month is Matariki celebrated?\nA) April B) May\nC) June D) July",
    "What colour is Kakariki?\nA) Green B) Blue\nC) Black D) Grey"
};

const char ANSWERS_A[5] = {
    'B',
    'B',
    'C',
    'C',
    'A'
};

const char QUESTIONS_B[5][200] = {
    "What is the name of the stretch of water that separates the North and South islands?\nA) Wellington Strait B) Tasman Channel\nC) Cook Strait D) Kaikoura Strait",
    "Which New Zealand city houses the Beehive?\nA) Wellington B) Christchurch\nC) Paeroa D) Auckland", "Which town has a giant carrot as a landmark?\nA) Taihape B) Waihi\nC) Paeroa D) Ohakune",
    "Where is 90 mile beach?\nA) Top of the North Island B) Bottom of the South Island\nC) Bottom of the North Island D) Top of the South Island",
    "When was the treaty of Waitangi signed?\nA) 1815 B) 1840\nC) 1855 D) 1875"
};

const char ANSWERS_B[5] = {
    'C',
    'A',
    'D',
    'A',
    'B'
};

char getValidCharInput(char validChars[]) {
    for (;;) {
        char inputChar[100];
        fgets(inputChar, sizeof(inputChar), stdin);
        if (inputChar[0] != '\n' && strchr(validChars, inputChar[0]) != NULL) {
            return inputChar[0];
        }
        printf("Invalid input. Please try again.\n");
    }
}

long getValidIntInput(long lowerBound, long upperBound) {
    for (;;) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        long returnValue = strtol(input, &end, 10);
        if (end != input) {
            if (returnValue >= lowerBound && returnValue <= upperBound) {
                return returnValue;
            }
        }
        printf("Invalid input. Please try again.\n");
    }
}

int main(void) {
    char name[100];
    int score = 0;

    printf("Welcome to the NZ Trivia Quiz.\n\nPlease enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Hello %s! Please enter your age: ", name);
    long age = getValidIntInput(5, 11);

    printf("\nWelcome to the NZ Trivia Quiz, In this Quiz you will be prompted with a question and then 4 answers labled A, B, C, or D. Simply type in the letter corrosponding to the correct answer and press enter.\nYou get one point for every question you get right. Good luck!\n\n");

    if (age <= 7) {
        for (int i = 0; i < sizeof(ANSWERS_A) / sizeof(ANSWERS_A[0]); i++) {
            printf("Q%d) %s\n", i+1, QUESTIONS_A[i]);
            char givenAnswer = getValidCharInput("ABCD");
            if (givenAnswer == ANSWERS_A[i])
            {
                printf("Correct! +1 point!\n");
                score++;
                continue;
            }
            printf("Incorrect! the correct answer was: %c.\n", ANSWERS_A[i]);
        }
    } else {
        for (int i = 0; i < sizeof(ANSWERS_B) / sizeof(ANSWERS_B[0]); i++) {
            printf("Q%d) %s\n", i+1, QUESTIONS_B[i]);
            char givenAnswer = getValidCharInput("ABCD");
            if (givenAnswer == ANSWERS_B[i])
            {
                printf("Correct! +1 point!\n");
                score++;
                continue;
            }
            printf("Incorrect! the correct answer was: %c.\n", ANSWERS_B[i]);
        }
    }


    printf("Congrats, you finished the quiz! your final score was %d / 5.\n", score);

    return 0;
}
