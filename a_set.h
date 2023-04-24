#ifndef a_set_h
#define a_set_h 1
#include <iostream>
class a_set_t{
private:
    int data_count;
    int *data_pool;
    int data_max;
    void reallocPool();
public:
    void add(int);
    void remove(int);
    int count(){
        return data_count;
    };
    a_set_t& intersect(a_set_t &p);
    a_set_t& disjoin(a_set_t &p);
    a_set_t combine(a_set_t &p);
	
    int findIndex(int);
    void printData();
public:
    a_set_t(); //constructor
    ~a_set_t(); //destructor

	//assignment operator overload
    a_set_t& operator = (const a_set_t&);
	//copy constructor
    a_set_t(const a_set_t&);
	//friend operator
	friend std::ostream& operator<<(std::ostream& os, const a_set_t&);
};
#endif
