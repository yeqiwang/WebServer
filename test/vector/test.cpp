#include <iostream>
#include <vector>
#include <memory>
#include <memory.h>
#include <algorithm>

using namespace std;

inline void show(vector<int>& arr) {
    for (const int& i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

int paritial(vector<int>& arr, int s, int e) {
    int i = s - 1;
    int j = s;

    while(j < e) {
        if (arr[j] < arr[e]) {
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }
    swap(arr[++i], arr[e]);
    return i;
}

void quick_sort(vector<int>& arr, int s, int e) {
    if (s < e) {
        int mid = paritial(arr, s, e);
        quick_sort(arr, s, mid-1);
        quick_sort(arr, mid+1, e);
    }
}


vector<int> temp(20, 0);

void merge(vector<int>& arr, int s, int mid, int e) {
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int i = s, j = mid + 1;
    int index = s;

    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            temp[index++] = arr[i++];
        }
        else {
            temp[index++] = arr[j++];
        }
    }

    int k = i == mid+1 ? j: i;
    while(index <= e) {
        temp[index++] = arr[k++];
    }

    for(int i = s; i <= e; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort(vector<int>& arr, int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
}



int main() {
    vector<int> arr(20, 0);
    for_each(arr.begin(), arr.end(), [](int& x){x = rand()%30;});
    
    show(arr);

    merge_sort(arr, 0, arr.size());
    show(arr); 

    return 0;
}