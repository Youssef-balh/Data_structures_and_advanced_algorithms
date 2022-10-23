#include<stdio.h>
#include<stdlib.h>

int main(){
    typedef struct 
    {
        char *name;
        int age;
        char gender;
    }student;

    student *khalidPtr, khalid;

    khalidPtr = &khalid;

    (*khalidPtr).name = "khalid";
    khalidPtr->age = 21;
    khalidPtr->gender ='M';
    
    printf("name: %s \nage: %d \ngender: %c",(*khalidPtr).name,khalidPtr->age,khalidPtr->gender);


    return 0;
}