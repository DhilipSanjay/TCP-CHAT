#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){

char *result;

create(1);
create(2);
result = print();
printf("%s", result);

findandremove(2);
result = print();
printf("%s", result);

findandremove(3);
result = print();
printf("%s", result);

return 0;
}
