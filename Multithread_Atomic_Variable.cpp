#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

int main() {

    int count;

    thread t1([&]()
    {
        for(int i; i<1000000; i++)
        {
            ++count;
        }
    });

    thread t2([&]()
    {
        for(int i; i<1000000; i++)
        {
            ++count;
        }
    });

    t1.join();
    t2.join();

    cout << count << endl;

	return 0;
}
