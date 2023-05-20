#include "myvec.h"
#include <iostream> 
#include <vector> 

using std::cout;
using std::endl;
using std::vector;

int main()
{
    std::vector<int> v1={1,2};
    Vector <int> v2={1,2};
    
            cout<<"\n================================= PUSH_BACK ==========================\nPRIEŠ: "<<endl;
            cout<<"---------------------------------------------------------------"<<endl;
            cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
            for (auto&i:v1) {cout<<i<< " ";} cout<<"|"<<endl;

            cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
            for (auto&i:v2) {cout<<i<<" ";}cout<<"|"<<endl;
            cout<<"---------------------------------------------------------------"<<endl<<endl;

            cout<<"VEIKSMAI: \nv1.push_back(6); v1.push_back(7); v1.push_back(8);\nv2.push_back(6); v2.push_back(7); v2.push_back(8);\n\n";

            v1.push_back(6); v1.push_back(7); v1.push_back(8);
            v2.push_back(6); v2.push_back(7); v2.push_back(8);
            
            cout<<"PO: "<<endl;
            cout<<"---------------------------------------------------------------------"<<endl;
            cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
            for (auto& i:v1) {cout<<i<<" ";}cout<<"|"<<endl;

            cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
            for (auto& i:v2) {cout<<i<<" ";} cout<<"|"<<endl;
            cout<<"---------------------------------------------------------------------"<<endl; 
    


    cout<<"\n================================= POP BACK ========================== \nPRIEŠ: "<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
    for (auto&i:v1) {cout<<i<<" ";} cout<<"|"<<endl;

    cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
    for (auto& i : v2) {cout<<i<<" ";}cout<<"|"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl<<endl;

    cout<<"VEIKSMAI:\nv1.pop_back(); v2.pop_back();\n\n";
    v1.pop_back(); v2.pop_back();

    cout<<"PO: "<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
    for (auto&i:v1) {cout<<i<<" ";} cout<<"|"<<endl;

    cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
    for (auto&i:v2) {cout<<i<<" ";} cout<<"|"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl<<endl; 
    
    
            cout<<"\n================================= RESERVE ========================== \nPRIEŠ: "<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
            for (auto&i:v1) {cout<<i<<" ";} cout<<"|"<<endl;

            cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
            for (auto&i:v2) {cout<<i<<" ";} cout<<"|"<<endl;
            cout<<"--------------------------------------------------------------------"<<endl<<endl;

            cout<<"VEIKSMAI:\nv1.reserve(10); v2.reserve(10);\n\n";
            v1.reserve(10); v2.reserve(10);

            cout<<"PO: "<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
            for (auto&i:v1) {cout<<i<<" ";} cout<<"|"<<endl;

            cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
            for (auto& i : v2) {cout<<i<<" ";}cout<<"|"<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
    

    cout<<"\n================================= SHRINK TO FIT ========================== \nPRIEŠ: "<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
    for (auto&i:v1) {cout<<i<<" ";} cout<<"|"<<endl;

    cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
    for (auto& i : v2) {cout<<i<<" ";} cout<<"|"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl<<endl;

    cout<<"VEIKSMAI:\nv1.shrink_to_fit(); v2.shrink_to_fit();\n\n";
    v1.shrink_to_fit(); v2.shrink_to_fit();

    cout<<"PO: "<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"| std::vector (v1)     | size: "<<v1.size()<<" | capacity: "<<v1.capacity()<<" | elements: ";
    for (auto&i:v1) {cout<<i<<" ";} cout<<"|"<<endl;

    cout<<"| Vector(custom) (v2)  | size: "<<v2.size()<<" | capacity: "<<v2.capacity()<<" | elements: ";
    for (auto& i : v2) {cout<<i<<" ";} cout<<"|"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl<<endl;
    
   
            cout<<"================================= FRONT ========================== "<<endl;
            cout<<"std::vector    (v1) front():  "<<v1.front()<<endl;
            cout<<"Vector(custom) (v2) front():  "<<v2.front()<<endl<<endl;

    




    
}
