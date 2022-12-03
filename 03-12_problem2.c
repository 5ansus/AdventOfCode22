#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 65
#define a 97

#define BufferSize 512
#define MAX_SIZE 100

int main(){
    FILE *p;
    char line[BufferSize], doubles[53], doubles2[53];
    int i = 0, num, len, sum = 0, j = 0/*, debug = 0*/;
    p = fopen("03-12_input.txt", "r");
    while (!feof(p)){
        if(fgets(line, BufferSize, p) != NULL){
            /*debug++;*/
            if(j == 0){
                len = strlen(line)/2;
                memset(doubles, 0, sizeof(doubles));
                for(i = 0; i < len*2; i++){
                    /*printf("%c\n", line[i]);*/
                    if(line[i] >= a){
                        num = line[i] - 96;
                    }else{
                        num = line[i] - 38;
                    }
                    doubles[num] = 1;
                }
                j++;
            }else if(j == 1){
                len = strlen(line)/2;
                memset(doubles2, 0, sizeof(doubles2));
                for(i = 0; i < len*2; i++){
                    /*printf("%c\n", line[i]);*/
                    if(line[i] >= a){
                        num = line[i] - 96;
                    }else{
                        num = line[i] - 38;
                    }
                    if (doubles[num] == 1) doubles2[num] = 1;
                }
                j++;
            }else if(j == 2){
                len = strlen(line)/2;
                for(i = 0; i < len*2; i++){
                    /*printf("%c\n", line[i]);*/
                    if(line[i] >= a){
                        num = line[i] - 96;
                    }else{
                        num = line[i] - 38;
                    }
                    if (doubles2[num] == 1){
                        /*printf("Sumando %d\n", num);*/
                        sum += num;
                        j = 0;
                        break;
                    }
                }
            }
            /*printf("%d . %d ejecución %d\n", j, debug, sum);*/
        }
    }
    printf("Resultado %d\n", sum);
    fclose(p);
    return 0;
}
