#include<stdio.h>
void oneQs();
char answer();
void allQs();
int main(){
    return 0;
}

void oneQs(){
    int x;
    printf("---------- Quiz------------");
    printf("1. What is input devices?");
    printf("a) Drum\n");
    printf("b) Dot matrix\n");
    printf("c) LCD\n");
    printf("d) Joystick\n");
}

char answer(){
    char ans;
    scanf("%c", &ans);
     if(ans == 'd' || ans == 'D') {
        printf("\n✔ Correct! Joystick is an input device.\n");
    } else {
        printf("\n✘ Wrong answer!\nCorrect answer: d) Joystick\n");
    }
}

void allQs(){
    oneQs();
}