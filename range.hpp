#pragma once
using namespace std;
#include <iostream>


namespace itertools{
    template<typename T>
    class range{
    
        public:
        T _begin;
        T _end;

        range(const T& begin,const T& end): _begin(begin), _end(end) {}
        
        struct iterator {
            T type;  
            iterator(const T& p) :type(p) {} 
            iterator& operator++(){ ++type; return *this; } 
            T& operator*() { return type; } 
            bool operator!=(const iterator& iter) { return type != iter.type; }  
        };
        iterator begin(){ return _begin; }
        iterator end(){ return _end; }
    };
}
