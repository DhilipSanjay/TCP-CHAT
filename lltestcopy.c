#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){

create(1);
create(2);
print();
findandremove(2);
print();
findandremove(3);
print();

return 0;
}
