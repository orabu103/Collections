#pragma once
using namespace std;
#include <iostream>

namespace itertools{
    template <typename T,typename U >

    class chain{
        public:
        T _TypeA;
        U _TypeB;

        chain(const T& TypeA,const U& TypeB): _TypeA(TypeA), _TypeB(TypeB) {}
        
        struct iterator {
            
            decltype(_TypeA.begin()) t1_begin;
            decltype(_TypeA.end()) t1_end;

            decltype(_TypeB.begin()) t2_begin;
            decltype(_TypeB.end()) t2_end;
            
            public:
            iterator(T& _TypeA, U& _TypeB) 
            : t1_begin(_TypeA.begin()), t1_end(_TypeA.end()),
            t2_begin(_TypeB.begin()), t2_end(_TypeB.end()) {} 
            
            iterator(T& _TypeA, U& _TypeB, bool) 
            : t1_begin(_TypeA.end()), t1_end(_TypeA.end()),
            t2_begin(_TypeB.end()), t2_end(_TypeB.end()) {} 
            
            private:
            iterator& operator++(){
                if(t1_begin != t1_end) ++ t1_begin;
                else ++ t2_begin;
                return *this; 
            }
            auto operator*() { 
                if(t1_begin != t1_end) return *t1_begin;
                else return *t2_begin;
            }
            bool operator!=(const iterator& iter) {
                if(t1_begin != iter.t1_begin || t2_begin != iter.t2_begin) return true;
                else return false;
            }
        };
        private:
        iterator begin() { return iterator(_TypeA,_TypeB); }
        iterator end() { return iterator(_TypeA,_TypeB,false); }
    };
}

