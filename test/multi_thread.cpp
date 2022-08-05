#include <vector>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex _mutex;
vector<int> arr(10, 0);

void read_thread() {
    cout << "read thread start" << endl;
    for (int i = 0; i < 10; i++) {
        {
            std::unique_lock<std::mutex> _lock(_mutex);
            cout << "read arr[i] = " << arr[i] << endl;
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    cout << "read thread end" << endl;
}

void write_thread() {
    cout << "write thread start" << endl;
    for (int i = 0; i < 10; i++) {
        {
            std::unique_lock<std::mutex> _lock(_mutex);
            arr[i] ++;
            cout << "set arr[i] = " << arr[i] << endl;;
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    cout << "write thread end" << endl;
}

int main() {
    std::thread t1(read_thread);
    std::thread t2(write_thread);

    t1.join();
    t2.join();

    return 0;
}