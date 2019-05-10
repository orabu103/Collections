#pragma once
using namespace std;
#include <iostream>

namespace itertools{
    template<typename T , typename U>
    
    class product{
        public:
        T _TypeA ;
        U _TypeB;

        product(const T& TypeA , const U& TypeB): _TypeA(TypeA) , _TypeB(TypeB) {}

        
        class iterator {
            template <typename V,typename K >
            class MyPair {
                V v;
                K k;
                public:
                MyPair(const V& v, const K& k) : v(v), k(k) {}
                MyPair() {}

                friend std::ostream& operator<<(std::ostream& os,const MyPair<V,K>& pair)
                {
                    return os << pair.v << "," << pair.k;
                }
            }; // End Class MyPair

            decltype(_TypeA.begin()) t1_begin;
            decltype(_TypeA.end()) t1_end;

            decltype(_TypeB.begin()) temp;
            decltype(_TypeB.begin()) t2_begin;
            decltype(_TypeB.end()) t2_end;

            public:   
            iterator(T& _TypeA, U& _TypeB) 
            : t1_begin(_TypeA.begin()), t1_end(_TypeA.end()),
            t2_begin(_TypeB.begin()), t2_end(_TypeB.end()),temp(_TypeB.begin()) {} 
            
            iterator(T& _TypeA, U& _TypeB, bool) 
            : t1_begin(_TypeA.end()), t1_end(_TypeA.end()),
            t2_begin(_TypeB.end()), t2_end(_TypeB.end()),temp(_TypeB.begin()) {} 
            
            iterator& operator++(){
                if(temp == t2_end-1){ ++t1_begin; temp = t2_begin; } 
                else
                ++temp;
                return *this; 
            }
            MyPair<decltype(*t1_begin),decltype(*temp)> operator*() { 
            return MyPair<decltype(*t1_begin),decltype(*temp)> (*t1_begin,*temp);
            } 

            bool operator!=(const iterator& iter) {
                if( t1_begin != iter.t1_begin ) return true;
                else return false;
            }
        };
        iterator begin() { return iterator(_TypeA,_TypeB); }
        iterator end() { return iterator(_TypeA,_TypeB,false); }
    };
}
        
