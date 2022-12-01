#include <stdio.h>
#include <stdlib.h>

#define BufferSize 512
#define MAX_SIZE 100
#define REQUESTED_VALUES 3

/*See the problem 1 for easier optimization*/
int main(){
    FILE *p;
    char string[BufferSize];
    int num[MAX_SIZE], i = 0, value, j, sum, maxValue[REQUESTED_VALUES], k = 0;
    p = fopen("01-12_input.txt", "r");
    maxValue[0] = 0;
    maxValue[1] = 0;
    maxValue[2] = 0;
    while (!feof(p)){
        value = 0;
        fgets(string,BufferSize, p);
        sscanf(string, "%d",  &value);
        num[i] = value;
        i++;
        if(value == 0){
            sum = 0;
            for(j = 0; j < i; j++){
                sum += num[j];
            }
            i = 0;
            k++;
            
            /*printf("SUM:%d, %d, %d, %d\n", sum, maxValue[2], maxValue[1], maxValue[0]);*/
            if (maxValue[2] < sum){
                maxValue[0] = maxValue[1];
                maxValue[1] = maxValue[2];
                maxValue[2] = sum;
                /*printf("%d, %d, %d\n", maxValue[2], maxValue[1], maxValue[0]);*/
            }else if (maxValue[1] < sum){
                maxValue[0] = maxValue[1];
                maxValue[1] = sum;
                /*printf("%d, %d, %d\n", maxValue[2], maxValue[1], maxValue[0]);*/
            }else if (maxValue[0] < sum){
                maxValue[0] = sum;
                /*printf("%d, %d, %d\n", maxValue[2], maxValue[1], maxValue[0]);*/
            }
        }
    }
    fclose(p);
    sum = maxValue[2] + maxValue[1] + maxValue[0];
    printf("%d\n", sum);
    return 0;
}
