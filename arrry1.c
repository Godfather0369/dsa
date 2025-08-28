#include<stdio.h>
int main(){
    int marks[5];
    int i;

    printf("Enter the Marks: ");
    for(i=0;i<5;i++){
        scanf("%d",&marks[i]);
    }
 printf("\nthe Marks: \n");
    for(i=0;i<5;i++){
        printf("%d\n",marks[i]);
    }
}