
//Hash Tables:
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <ctime>
#include "hash.h"
#include "implementation.cpp"
using namespace std;
int main()
{
    int N=10000,Counter=0;        // Change N to change the array size
    hashTable<int,int> H(N,-1);
    srand(time(0));
    for(int i=0;i<N;i+=4)      // To have a full array use (i++)
//To have a 50% full array use (i+=2)
//To have a 25% full array use (i+=4)
    {
        H.insert(rand()%(N/4),i);
    }
    auto start_time = std::chrono::high_resolution_clock::now(); // get start time
    H.search(rand()%(N/4),Counter);
    auto end_time = std::chrono::high_resolution_clock::now(); // get end time
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time); // calculate time duration in nanoseconds
    cout << "Time taken: " << duration_ns.count() << " ns" << std::endl;
    cout<<"Number  of Comparisons is : "<<Counter<<endl;
}
