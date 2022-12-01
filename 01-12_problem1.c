#include <stdio.h>
#include <stdlib.h>

#define BufferSize 512
#define MAX_SIZE 100


int main(){
    FILE *p;
    char string[BufferSize];
    int num[MAX_SIZE], i = 0, value, j, sum, maxValue = 0, record = 0 , k = 0;
    p = fopen("01-12_input.txt", "r");
    while (!feof(p)){
        value = 0;
        fgets(string,BufferSize, p);
        sscanf(string, "%d",  &value);
        /*printf("%d: %d\n", i, value);*/
        num[i] = value;
        i++;
        /*Could be optimizated suming on interation and only checking on this if*/
        if(value == 0){
            sum = 0;
            for(j = 0; j < i; j++){
                sum += num[j];
            }
            i = 0;
            k++;
            if (maxValue < sum){
                maxValue = sum;
                record = k;
            }
        }
    }
    fclose(p);
    printf("%d: %d\n", record, maxValue);
    return 0;
}
