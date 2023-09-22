
//Exponential Search:
#include <iostream>
#include <chrono>
using namespace std;
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) {
        return 0;
    }


    int i = 1;
    while (i < size && arr[i] <= target) {
        i *= 2;
    }


    int left = i / 2;
    int right = std::min(i, size - 1);


    // Perform exponential search within the identified range
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }


    return -1;  // Target not found
}


long long run_experiment(int size) {
    // Create a sorted array of size elements
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }


    // Generate a random key to search for
    int key = rand() % size;



    auto start = std::chrono::high_resolution_clock::now();
    int index = exponentialSearch(arr, size, key);
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
