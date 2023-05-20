//myvec:Vector ir std::vector spartos analize naudojant push_back()
#include <vector>
#include "myvec.h"
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using namespace std::chrono;

void testavimas (unsigned int sz)
{
    duration<double> diff;
    int perskirstymai=0;
    auto s1=high_resolution_clock::now();
    Vector<int> v1;
    for (int i=1; i<=sz; i++)
    {
        if (v1.size()==v1.capacity()) {perskirstymai++;}
        v1.push_back(i);
    }
    auto e1=high_resolution_clock::now();
    diff=e1-s1; cout<<sz<<" dydžio Vector(custom) užpildymas užtruko: "<<diff.count()<<" s\n";
    cout<<"Perskirstymai: "<<perskirstymai<<endl;
    perskirstymai=0;
    v1.clear();
    auto s2=high_resolution_clock::now();
    vector<int> v2;
    for (int i=1; i<=sz; i++)
    {
        if (v2.size()==v2.capacity()) {perskirstymai++;}
        v2.push_back(i);
    }
    auto e2=high_resolution_clock::now();
    diff=e2-s2; cout<<sz<<" dydžio std:vector užpildymas užtruko: "<<diff.count()<<" s\n";
    cout<<"Perskirstymai: "<<perskirstymai<<endl<<endl;
    v2.clear();
    
}

int main()
{
    testavimas(10000);
    testavimas(100000);
    testavimas(1000000);
    testavimas(10000000);
    testavimas(100000000);


}