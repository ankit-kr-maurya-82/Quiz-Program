#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

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
        {  
            "Q. What is an input device?", //Q1
            "Drum",
            "Dot Matrix",
            "LCD",
            "Joystick",
            'd'
        },

        {
            "Q. What is an output device?", //Q2
            "scanner",
            "Keyboard",
            "Plotter",
            "Joystick",
            'c'
        },

        {
            "Q. Which one is a programming language?", //Q3
            "HTML",
            "Python",
            "CSS",
            "Photoshop",
            'b'
        },
        {
            "Q. What is correct terminator of C?", //Q4
            ".",
            ":",
            ";",
            ")",
            'c'
        },
        {
            "Q. What is function to start in C?", //Q5
            "main()",
            "start()",
            "function()",
            "None of these",
            'a'
        },
        {
            "Q. What is type of  (int stud[50]={12,32,43,54})", //Q6
            "string",
            "array",
            "function",
            "structure",
            'b'
        },
            {
        "Q. Which device is used to store data permanently?",  // Q7
        "RAM",
        "Hard Disk",
        "Cache",
        "Registers",
        'b'
    },

    {
        "Q. Which is NOT an operating system?",  // Q8
        "Windows",
        "Linux",
        "MS Word",
        "macOS",
        'c'
    },

    {
        "Q. Which symbol is used for comments in C?",  // Q9
        "//",
        "##",
        "--",
        "@@",
        'a'
    },

    {
        "Q. Which memory is volatile?",  // Q10
        "ROM",
        "Hard Disk",
        "RAM",
        "Pen Drive",
        'c'
    },

    {
        "Q. Which one is NOT a programming language?",  // Q11
        "Python",
        "C++",
        "Java",
        "Google",
        'd'
    },

    {
        "Q. Which device is used to print on paper?",  // Q12
        "Monitor",
        "Printer",
        "Scanner",
        "Keyboard",
        'b'
    },

    {
        "Q. Which shortcut key is used to copy?",  // Q13
        "Ctrl + C",
        "Ctrl + V",
        "Ctrl + X",
        "Ctrl + S",
        'a'
    },

    {
        "Q. Which number system uses base 2?",  // Q14
        "Decimal",
        "Binary",
        "Octal",
        "Hexadecimal",
        'b'
    },

    {
        "Q. Which tag is used for heading in HTML?",  // Q15
        "<p>",
        "<h1>",
        "<br>",
        "<title>",
        'b'
    },

    {
        "Q. Which company developed the C language?",  // Q16
        "Microsoft",
        "Apple",
        "Bell Labs",
        "Google",
        'c'
    },

        
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    srand(time(NULL));

    for(int i=totalQuestions-1; i>0; i--){
        int j=rand()%(i+1);

        struct Question temp = quiz[i];
        quiz[i]=quiz[j];
        quiz[j]=temp;
        
        
    }

    printf("========== QUIZ START ==========\n\n");

    for (int i = 0; i < totalQuestions; i++)
    {
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
    int timeLimit=20;

    printf("You have %d seconds to answer...\n", timeLimit);
    printf("%s\n", q.text);
    printf("a) %s\n", q.a);
    printf("b) %s\n", q.b);
    printf("c) %s\n", q.c);
    printf("d) %s\n", q.d);
    printf("Your answer: ");

    fflush(stdout);

    time_t start = time(NULL);
    answer = 0;

    while (difftime(time(NULL), start) < timeLimit) {
        if (kbhit()) {
            int c = getche();
            if (c == '\r') { // ignore carriage return
                continue;
            }
            answer = (char)c;
            break;
        }
        Sleep(100);
    }

    if (!answer) {
        printf("\nTime Up! You didn't answer.\n");
        printf("Correct answer was %c\n\n", q.correct);
        return 0;
    }

    if (isupper((unsigned char)answer)) answer = (char)tolower((unsigned char)answer);

    if (answer == q.correct)
    {
        printf("\nCorrect!\n\n");
        return 1;
    }
    else
    {
        printf("\nWrong! Correct answer is '%c'\n\n", q.correct);
        return 0;
    }
}
