#include <iostream>
#include <cstdlib>
#include "a_set.h"

int main(int ac, char* av[]){
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

	std::cout << "A [" << A << "]\n";	
	std::cout << "B [" << B << "]\n";	

    a_set_t *C;
    C = &A.intersect(B);
    //C->printData();
	std::cout << "C [" << *C << "]\n";	

    //std::cout << C << std::endl;
    
    a_set_t *D;
    D = &A.disjoin(B);
    //D->printData();
	std::cout << "D [" << *D << "]\n";	

	a_set_t E = A.combine(B);
	std::cout << "E [" << E << "]\n";	
	//E.printData();

    delete C;
    delete D;

    return 0;
}
