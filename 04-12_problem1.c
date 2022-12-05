#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *p;
    int start1, end1, start2, end2, sum = 0;
    p = fopen("04-12_input.txt", "r");
    while (!feof(p)){
        fscanf(p, "%d-%d,%d-%d", &start1, &end1, &start2, &end2);
        /*printf("%d %d %d %d\n", start1, end1, start2, end2);*/
        if((start1 <= start2) && (end2 <= end1)) sum ++;
        else if((start2 <= start1) && (end1 <= end2)) sum ++;
    }
    printf("Total: %d\n", sum);
    fclose(p);
    return 0;
}
