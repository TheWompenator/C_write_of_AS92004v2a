#include <stdio.h>
#include <string.h>

const static char QUESTIONS[5][200] = {
    "What is the name of the stretch of water that separates the North and South islands?\nA) Wellington Strait B) Tasman Channel\nC) Cook Strait D) Kaikoura Strait",
    "Which New Zealand city houses the Beehive?\nA) Wellington B) Christchurch\nC) Paeroa D) Auckland",
    "Which town has a giant carrot as a landmark?\nA) Taihape B) Waihi\nC) Paeroa D) Ohakune",
    "Where is 90 mile beach?\nA) Top of the North Island B) Bottom of the South Island\nC) Bottom of the North Island D) Top of the South Island",
    "When was the treaty of Waitangi signed?\nA) 1815 B) 1840\nC) 1855 D) 1875"
};

const static char ANSWERS[5] = {
    'C',
    'A',
    'D',
    'A',
    'B'
};

static char getValidCharInput(char validChars[]) {
    for (;;) {
        char inputChar[3];
        fgets(inputChar, sizeof(inputChar), stdin);
        if (inputChar[0] != '\n' && strchr(validChars, inputChar[0]) != NULL) {
            return inputChar[0];
        }
        printf("Invalid input. Please try again.\n");
    }
}

int main(void) {
    char name[100];
    int score = 0;

    printf("Hello! Welcome to the NZ Trivia Quiz.\n\nPlease enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Hello %s!\nWelcome to the NZ Trivia Quiz, In this Quiz you will be prompted with a question and then 4 answers labled A, B, C, or D. Simply type in the letter corrosponding to the correct answer and press enter.\nYou get one point for every question you get right. Good luck!", name);

    for (int i = 0; i < sizeof(ANSWERS) / sizeof(ANSWERS[0]); i++) {
        printf("%s\n", QUESTIONS[i]);
        char givenAnswer = getValidCharInput("ABCD");
        if (givenAnswer == ANSWERS[i])
        {
            printf("Correct! +1 point!\n");
            score++;
            continue;
        }
        printf("Incorrect! the correct answer was: %c.\n", ANSWERS[i]);
    }

    printf("Congrats you finished the quiz! your final score was %d / 5.\n", score);

    return 0;
}
