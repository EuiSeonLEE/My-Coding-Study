#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int Number;
    char Name[10];
    int Age;
};

struct Student Input(){
    struct Student Temp;

    printf("Number : ");
    scanf("%d", &(Temp.Number));
    printf("Name : ");
    scanf("%s", &(Temp.Name));
    printf("Age : ");
    scanf("%d", &(Temp.Age));
    
    return Temp;

}
void Output(struct Student Temp, int Cnt){
    printf("Student[%d] : %d, %s, %d\n", Cnt, Temp.Number, Temp.Name, Temp.Age);
}
int main(void){
    struct Student S[10];
    for(int Cnt = 0; Cnt < 10; Cnt++){
        printf("input[%d]\n", Cnt);
        S[Cnt] = Input();
        Output(S[Cnt], Cnt);
    }
     return 0;
}