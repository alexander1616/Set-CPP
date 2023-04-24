#include <iostream>
#include <cstdlib>
#include "./a_set.h"

void a_set_t::reallocPool(){
    int *newDataPool;
    int incrSize = 5;
    newDataPool = new int[data_max + incrSize];
    if (data_count){
        int i;
        for (i = 0; i < data_count; i++){
            newDataPool[i] = data_pool[i];
        }        
        delete [] data_pool;
    }
    data_pool = newDataPool;
    data_max += incrSize;
}

//constructor
a_set_t::a_set_t(){
    data_count = 0;
    data_max = 0;
    reallocPool();
}

//copy constructor
a_set_t::a_set_t(const a_set_t& p){
	data_count = 0;
	data_max = 0;
	reallocPool();
	int i;
	for (i = 0; i < p.data_count; i++){
		add(p.data_pool[i]);
	}
}

//assignment operator
a_set_t& a_set_t::operator = (const a_set_t& p){
	delete [] data_pool;
	data_count = 0;
	data_max = 0;
	int i;
	for (i = 0; i < p.data_count; i++){
		add(p.data_pool[i]);
	}
	return *this;
}

//destructor
a_set_t::~a_set_t(){
    delete [] data_pool;
}

int a_set_t::operator [] (int idx){
	if (idx < 0 || idx > data_count){
		throw std::invalid_argument("bad idx");
	}
	return data_pool[idx];
}

a_set_t a_set_t::operator + (a_set_t& p){
	a_set_t x(p);
	int i;
	for (i = 0; i < data_count; i++){
		x.add(data_pool[i]);
	}
	return x;
}

a_set_t a_set_t::operator - (a_set_t& p){
	a_set_t x(*this);
	int i;
	for (i = 0; i < p.data_count; i++){
		x.remove(p.data_pool[i]);
	}
	return x;
}

int a_set_t::findIndex(int x){
    int idx;
    for (idx = 0; idx < data_count; idx++){
        if (data_pool[idx] == x){
            return idx;
        }
    }
    return -1;
}

void a_set_t::add(int x){
    if (findIndex(x) > 0){
        return;
    }
    if (data_count >= data_max){
        reallocPool();
    }
    data_pool[data_count++] = x;
}

void a_set_t::remove(int x){
    int idx = findIndex(x);
    if (idx < 0){
        return;
    }
    for (; idx < data_count -1; idx++){
        data_pool[idx] = data_pool[idx + 1];
    }
    data_count--;
}

a_set_t& a_set_t::intersect(a_set_t &p){
    a_set_t *newSet = new a_set_t;
    int i;
    for (i = 0; i < data_count; i++){
        if (p.findIndex(data_pool[i]) >= 0){
            newSet->add(data_pool[i]);
        };
    }
    return *newSet;
}

a_set_t& a_set_t::disjoin(a_set_t &p){
    a_set_t *newSet = new a_set_t;
    int i;
    for (i = 0; i < data_count; i++){
        if (p.findIndex(data_pool[i]) < 0){
            newSet->add(data_pool[i]);
        };
    }

    for (i = 0; i < p.data_count; i++){
        if (findIndex(p.data_pool[i]) < 0){
            newSet->add(p.data_pool[i]);
        };
    }
    return *newSet;
}

a_set_t a_set_t::combine(a_set_t &p){
    //a_set_t *newSet = new a_set_t(p);
	
	a_set_t newSet(p);
	
    int i;
    for (i = 0; i < data_count; i++){
        newSet.add(data_pool[i]);
    }
	/*
    for (i = 0; i < p.data_count; i++){
        newSet->add(p.data_pool[i]);
    }
	*/
    return newSet;
}

void a_set_t::printData(){
    int i;
    for (i = 0; i < data_count; i++){
        std::cout << data_pool[i] << '\n';
    } 
    std::cout << '\n';
}

//friend
std::ostream& operator << (std::ostream& os, const a_set_t& p){
    int i;
    for (i = 0; i < p.data_count; i++){
        os << p.data_pool[i] << ' ';
    } 
    return os;
}
