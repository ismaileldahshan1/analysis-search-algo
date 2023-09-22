
//Jump Search
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;


const int MAX_SIZE = 10000;


int arr[MAX_SIZE];


void generate_array(int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10001;
    }
    sort(arr, arr + size);
}


int jumpsearch(int arr[], int size, int target)
{
    int m = sqrt(size);
    int low = 0;
    int high = 0;


    for(int i=0;i<size/m;i++)
    {
        if(arr[high] == target)
            return high;
        else if(arr[high] > target)
        {
            for(int j=low;j<high;j++)
            {
                if(arr[j]==target)
                    return j;
            }
        }
        else
        {
            low = high;
            high += m;
        }
    }
    return -1;
}
long long run_experiment(int size) {
    // Create a sorted array of size elements
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }


    // Generate a random key to search for
    int key = rand() % size;


    // Measure the execution time of binary search
    auto start = std::chrono::high_resolution_clock::now();
    int index = jumpsearch(arr, size, key);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();


    // Clean up the array and return the execution time
    delete[] arr;
    return duration;
}


int main()
{
    long long time1 = run_experiment(100);
    long long time2 = run_experiment(1000);
    long long time3 = run_experiment(10000);


    cout << "Execution time for 100 elements: " << time1 << " nanoseconds" << endl;
    cout << "Execution time for 1000 elements: " << time2 << " nanoseconds" << endl;
    cout << "Execution time for 10000 elements: " << time3 << " nanoseconds" << endl;


    return 0;
}