#pragma once
using namespace std;

#include <iostream>
 
namespace itertools{
    template<typename T , typename U>

    class zip{
        public:
        T _TypeA;
        U _TypeB;

        zip(const T& TypeA , const U& TypeB): _TypeA(TypeA) , _TypeB(TypeB) {}

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

            decltype(_TypeB.begin()) t2_begin;
            decltype(_TypeB.end()) t2_end;

            public:   
            iterator(T& _TypeA, U& _TypeB) 
            : t1_begin(_TypeA.begin()), t1_end(_TypeA.end()),
            t2_begin(_TypeB.begin()), t2_end(_TypeB.end()) {} 
            
            iterator(T& _TypeA, U& _TypeB, bool) 
            : t1_begin(_TypeA.end()), t1_end(_TypeA.end()),
            t2_begin(_TypeB.end()), t2_end(_TypeB.end()) {} 
            
            iterator& operator++(){
                ++ t1_begin;
                ++ t2_begin;
                return *this; 
            }

            MyPair<decltype(*t1_begin),decltype(*t2_begin)> operator*() { 
            return MyPair<decltype(*t1_begin),decltype(*t2_begin)> (*t1_begin,*t2_begin);
            } 

            bool operator!=(const iterator& iter) {
                if( t1_begin != iter.t1_begin && t2_begin != iter.t2_begin) return true;
                else return false;
            }
        };
        iterator begin() { return iterator(_TypeA,_TypeB); }
        iterator end() { return iterator(_TypeA,_TypeB,false); }

    };
}
