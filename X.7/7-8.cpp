#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout<<"the smallest values of type bool is  "<<std::numeric_limits<bool>::lowest()<<endl;
    cout<<"the largest values of type bool is  "<<std::numeric_limits<bool>::max()<<endl;

    cout<<"the smallest values of type char is  "<<std::numeric_limits<char>::lowest()<<endl;
    cout<<"the largest values of type char is  "<<std::numeric_limits<char>::max()<<endl;

    cout<<"the smallest values of type short is "<<std::numeric_limits<short>::lowest()<<endl;
    cout<<"the largest values of type short is "<<std::numeric_limits<short>::max()<<endl;
    
    cout<<"the smallest values of type int is   "<<std::numeric_limits<int>::lowest()<<endl;
    cout<<"the largest values of type int is   "<<std::numeric_limits<int>::max()<<endl;
    
    cout<<"the smallest values of type long is  "<<std::numeric_limits<long>::lowest()<<endl;
    cout<<"the largest values of type long is  "<<std::numeric_limits<long>::max()<<endl;
    
    cout<<"the smallest values of type long long is "<<std::numeric_limits<long long>::lowest()<<endl;
    cout<<"the largest values of type long long is "<<std::numeric_limits<long long>::max()<<endl;
    
    cout<<"the smallest values of type float is "<<std::numeric_limits<float>::lowest()<<endl;
    cout<<"the largest values of type float is "<<std::numeric_limits<float>::max()<<endl;
    
    cout<<"the smallest values of type double is    "<<std::numeric_limits<double>::lowest()<<endl;
    cout<<"the largest values of type double is    "<<std::numeric_limits<double>::max()<<endl;
    
    cout<<"the smallest values of type long double is   "<<std::numeric_limits<long double>::lowest()<<endl;
    cout<<"the largest values of type long double is   "<<std::numeric_limits<long double>::max()<<endl;
    
    cout<<"the smallest values of type unsigned is  "<<std::numeric_limits<unsigned>::lowest()<<endl;
    cout<<"the largest values of type unsigned is  "<<std::numeric_limits<unsigned>::max()<<endl;
    
    cout<<"the smallest values of type unsigned long is "<<std::numeric_limits<unsigned long>::lowest()<<endl;
    cout<<"the largest values of type unsigned long is "<<std::numeric_limits<unsigned long>::max()<<endl;
    
    return 0;
}
