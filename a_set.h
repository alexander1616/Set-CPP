#ifndef a_set_h
#define a_set_h 1
#include <iostream>

class a_set_t{
public:
    a_set_t(); //constructor
    ~a_set_t(); //destructor

    a_set_t& operator = (const a_set_t&);
    a_set_t(const a_set_t&);
	friend std::ostream& operator<<(std::ostream& os, const a_set_t&);
    int operator [] (int);
	a_set_t operator + (a_set_t&);
	a_set_t operator - (a_set_t&);
	

public:
    void 		add(int);
    void 		remove(int);
    int 		count(){
        return data_count;
    };
    a_set_t & 	intersect(a_set_t &p);
    a_set_t & 	disjoin(a_set_t &p);
    a_set_t 	combine(a_set_t &p);
	
    int 		findIndex(int);
    void 		printData();

private:
    int 		data_count;
    int 		*data_pool;
    int 		data_max;
    void 		reallocPool();
};
#endif
