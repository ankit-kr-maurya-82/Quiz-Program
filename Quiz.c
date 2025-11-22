#include <stdio.h>

struct Question
{
    char text[200];
    char a[20], b[20], c[20], d[20];
    char correct;
};

int askQuestion(struct Question q);

int main()
{
    struct Question quiz[] = {
        {"1. What is an input device?",
         "Drum",
         "Dot Matrix",
         "LCD",
         "Joystick",
         'd'},            

        {"2. What is an output device?",
         "scanner",
         "Keyboard",
         "Plotter",
         "Joystick",
         'c'},         

        {"3. Which one is a programming language?",
         "HTML",
         "Python",
         "CSS",
         "Photoshop",
         'b'}        
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;

    printf("========== QUIZ START ==========\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        score += askQuestion(quiz[i]);
    }

    printf("\n================================\n");
    printf("Your Score: %d / %d\n", score, totalQuestions);
    printf("================================\n");

    return 0;
}

int askQuestion(struct Question q)
{
    char answer;

    printf("%s\n", q.text);
    printf("a) %s\n", q.a);
    printf("b) %s\n", q.b);
    printf("c) %s\n", q.c);
    printf("d) %s\n", q.d);
    printf("Your answer: ");

    scanf(" %c", &answer);  // FIXED: ignores previous newline

    if (answer == q.correct || answer == q.correct - 32)
    {
        printf(" Correct!\n\n");
        return 1;
    }
    else
    {
        printf(" Wrong! Correct answer is '%c'\n\n", q.correct);
        return 0;
    }
}
