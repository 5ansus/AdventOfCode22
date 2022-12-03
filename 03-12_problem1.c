#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 65
#define a 97

#define BufferSize 512
#define MAX_SIZE 100

int main(){
    FILE *p;
    char line[BufferSize], doubles[53];
    int i = 0, num, len, sum = 0/*, debug = 0*/;
    p = fopen("03-12_input.txt", "r");
    while (!feof(p)){
        if(fgets(line, BufferSize, p) != NULL){
            len = strlen(line)/2;
            memset(doubles, 0, sizeof(doubles));
            for(i = 0; i < len; i++){
                /*printf("%c\n", line[i]);*/
                if(line[i] >= a){
                    num = line[i] - 96;
                }else{
                    num = line[i] - 38;
                }
                doubles[num] = 1;
            }
            for(i = len; i < len*2; i++){
                /*printf("%c\n", line[i]);*/
                if(line[i] >= a){
                    num = line[i] - 96;
                }else{
                    num = line[i] - 38;
                }
                if(doubles[num] == 1){
                    /*debug++;*/
                    /*printf("Ronda %d, letra que coincide %d\n", debug, num);*/
                    sum += num;
                    break;
                }
            }
        }
    }
    printf("Resultado %d\n", sum);
    fclose(p);
    return 0;
}
