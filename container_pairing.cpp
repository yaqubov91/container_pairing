
//
using namespace std;
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <memory>
#include <set>
#include <deque>
#include<tuple>
#include<stack>

template<typename... T1,template <typename... Args> class Container1,typename... T2,template <typename... Args> class Container2>//,typename P1,typename P2>//,template<typename...> class Vect>
vector<pair<typename tuple_element<0, tuple<T1...> >::type,typename tuple_element<0, tuple<T2...> >::type>> combine(Container1<T1...> a,Container2<T2...> b){
    
    vector<pair<typename tuple_element<0, tuple<T1...> >::type,typename tuple_element<0, tuple<T2...> >::type>> out;  //holds ouput vector
    
    typename Container1<T1...>::iterator it1=a.begin();
    typename Container2<T2...>::iterator it2=b.begin();
    
    while(it2!=b.end() && it1!=a.end()){// iterate until one of the iterators reach to the end
        auto p=make_pair(*it1,*it2);
        out.push_back(p);
        it1++;
        it2++;
    }
    return out;
}


int main(int argc, const char * argv[]) {
    //vector<pair<int,char>> out;
    deque<int> a2;
    for (int i=1; i<=5; i++) a2.insert(a2.end(),i);
    //vector<int> a1={1, 2, 3, 4, 5, 6};
    list<int> a1={1,2,3,4,5,6};
    //vector<char> a2={'a','b','c','d'};
    //set<char> a1={'a','b','c','d'};
    
    auto out=combine(a1,a2);
    cout<<"output size is "<<out.size()<<endl;
    cout<<"First pair of elements are "<<out[0].first<<" and "<<out[2].second<<endl;
    return 0;
}



