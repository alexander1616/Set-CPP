#include <iostream>
#include <cstdlib>
#include "a_set.h"

int main(int ac, char* av[]){
    std::cout << "hello" << std::endl; 
    a_set_t A;
    a_set_t B;
    A.add(10);
    A.add(40);
    A.add(50);
    A.add(60);
    A.add(70);
    B.add(20);
    B.add(40);
    B.add(50);
    B.add(80);

    a_set_t *C;
    C = &A.intersect(B);
    C->printData();
    a_set_t *D;
    D = &A.disjoin(B);
    D->printData();

    delete C;
    delete D;
    return 0;
}