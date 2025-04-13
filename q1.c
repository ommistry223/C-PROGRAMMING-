#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to display welcome message
void welcome() {
    printf("******************************\n");
    printf("*       WELCOME TO THE       *\n");
    printf("*        QUIZ GAME           *\n");
    printf("******************************\n\n");
}

// Function to check answer (case insensitive)
int checkAnswer(char userAnswer, char correctAnswer) {
    return tolower(userAnswer) == tolower(correctAnswer);
}

int main() {
    // Quiz questions, options, and answers
    char questions[][100] = {
        "1. What is the capital of France?",
        "2. Which planet is known as the Red Planet?",
        "3. What is the largest mammal in the world?",
        "4. In which year did World War II end?",
        "5. What is the chemical symbol for gold?"
    };
    
    char options[][4][50] = {
        {"A. London", "B. Paris", "C. Berlin", "D. Madrid"},
        {"A. Venus", "B. Mars", "C. Jupiter", "D. Saturn"},
        {"A. Elephant", "B. Blue Whale", "C. Giraffe", "D. Polar Bear"},
        {"A. 1943", "B. 1944", "C. 1945", "D. 1946"},
        {"A. Au", "B. Ag", "C. Fe", "D. Hg"}
    };
    
    char answers[] = {'B', 'B', 'B', 'C', 'A'};
    
    int score = 0;
    char userAnswer;
    int totalQuestions = sizeof(questions)/sizeof(questions[0]);
    
    welcome(); // Display welcome message
    
    printf("The quiz contains %d questions. Let's begin!\n\n", totalQuestions);
    
    // Loop through each question
    for(int i = 0; i < totalQuestions; i++) {
        printf("%s\n", questions[i]);
        
        // Display all options for the current question
        for(int j = 0; j < 4; j++) {
            printf("%s\n", options[i][j]);
        }
        
        // Get user answer
        printf("\nYour answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);
        
        // Check if answer is valid
        while(toupper(userAnswer) < 'A' || toupper(userAnswer) > 'D') {
            printf("Invalid input! Please enter A, B, C, or D: ");
            scanf(" %c", &userAnswer);
        }
        
        // Check if answer is correct
        if(checkAnswer(userAnswer, answers[i])) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c.\n\n", answers[i]);
        }
    }
    
    // Display final score
    printf("******************************\n");
    printf("*         GAME OVER          *\n");
    printf("* Your final score: %d/%d    *\n", score, totalQuestions);
    printf("******************************\n");
    
    // Percentage calculation
    float percentage = (float)score / totalQuestions * 100;
    printf("\nYou got %.1f%% of the questions right.\n", percentage);
    
    // Simple feedback based on score
    if(percentage >= 80) {
        printf("Excellent job!\n");
    } else if(percentage >= 60) {
        printf("Good effort!\n");
    } else if(percentage >= 40) {
        printf("Keep practicing!\n");
    } else {
        printf("You might want to study more.\n");
    }
    
    return 0;
}