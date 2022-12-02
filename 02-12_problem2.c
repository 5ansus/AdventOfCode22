#include <stdio.h>
#include <stdlib.h>

#define ROCK 65
#define PAPER 66
#define SCISSORS 67

#define LOSE 88
#define DRAW 89
#define WIN 90

#define BufferSize 512
#define MAX_SIZE 100

int main(){
    FILE *p;
    char string[BufferSize], rival, cond;
    int result = 0, myChoice = 0;
    p = fopen("02-12_input.txt", "r");
    while (!feof(p)){
        
        fgets(string, BufferSize, p);
        fscanf(p, "%c %c", &rival, &cond);
        /*printf("%c, %c: %d\n", rival, cond, result);*/

        if (cond == LOSE) myChoice = ((rival == ROCK) * 3 + (rival == PAPER) * 1 + (rival == SCISSORS) * 2);
        if (cond == DRAW) myChoice = ((rival == ROCK) * 1 + (rival == PAPER) * 2 + (rival == SCISSORS) * 3) + 3;
        if (cond == WIN) myChoice = ((rival == ROCK) * 2 + (rival == PAPER) * 3 + (rival == SCISSORS) * 1) + 6;
        
        result += myChoice;
    }
    fclose(p);
    printf("%d\n", result);
    return 0;
}
