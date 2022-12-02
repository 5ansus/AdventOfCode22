#include <stdio.h>
#include <stdlib.h>

#define rROCK 65
#define rPAPER 66
#define rSCISSORS 67

#define mROCK 88
#define mPAPER 89
#define mSCISSORS 90

#define BufferSize 512
#define MAX_SIZE 100

int main(){
    FILE *p;
    char string[BufferSize], rival, me;
    int result = 0, rivalChoice = 0, myChoice = 0;
    p = fopen("02-12_input.txt", "r");
    while (!feof(p)){
        fgets(string, BufferSize, p);
        fscanf(p, "%c %c", &rival, &me);

        rivalChoice = (rival == rROCK) * 1 + (rival == rPAPER) * 2 + (rival == rSCISSORS) * 3;
        myChoice = (me == mROCK) * 1 + (me == mPAPER) * 2 + (me == mSCISSORS) * 3;
        /*printf("%c, %c, %d, %d: %d\n", rival, me, rivalChoice, myChoice, result);*/

        myChoice += (((myChoice - rivalChoice) == 1) || ((myChoice+3 - rivalChoice) == 1)) * 6;
        myChoice += (myChoice == rivalChoice)*3;
        result += myChoice;
    }
    fclose(p);
    printf("%d\n", result);
    return 0;
}
