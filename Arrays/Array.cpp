#include <iostream>
using namespace std;

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swapping:" << endl;
    cout << "Min = " << a << endl;
    cout << "Max = " << b << endl;
}

void minMax(int *nums, int size){
    int min = nums[0];
    int max = nums[0];

    for(int i = 1; i < size; i++){
        if(nums[i] < min) min = nums[i];
        if(nums[i] > max) max = nums[i];
    }

    cout << "Original Min = " << min << endl;
    cout << "Original Max = " << max << endl;

    swap(min, max);
}

void sum(int *nums, int size){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += nums[i];
    }
    cout << "Sum of array = " << total << endl;
}

void product(int *nums, int size){
    int prod = 1;
    for(int i = 0; i < size; i++){
        prod *= nums[i];
    }
    cout << "Product of array = " << prod << endl;
}

void unique(int *nums, int size){
    cout << "Unique Elements:" << endl;
    for(int i = 0; i < size; i++){
        bool isUnique = true;
        for(int j = 0; j < size; j++){
            if(i != j && nums[i] == nums[j]){
                isUnique = false;
                break;
            }
        }
        if(isUnique){
            cout << "Element " << i << " (" << nums[i] << ") is Unique." << endl;
        }
    }
}

void intersection(int *nums, int size){
    cout << "Common Elements:" << endl;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(nums[i] == nums[j]){
                cout << "Element " << i << " (" << nums[i] << ") is common." << endl;
                break; // Avoid printing duplicates multiple times
            }
        }
    }
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    if(size <= 0){
        cout << "Invalid size. Exiting." << endl;
        return 1;
    }

    int *nums = new int[size];
    cout << "Enter elements of array:" << endl;
    for(int i = 0; i < size; i++){
        cout << "Element " << (i + 1) << ": ";
        cin >> nums[i];
    }

    minMax(nums, size);
    sum(nums, size);
    product(nums, size);
    unique(nums, size);
    intersection(nums, size);

    delete[] nums;
    return 0;
}