#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void loop()
{
    for(int i; i<10; i++)
    {
	this_thread::sleep_for(chrono::milliseconds(500));
        cout << i << endl;
    }
}


int main() {
	
	thread t1(loop);

    cout << endl ;

	thread t2(loop);
    
    t1.join();
    t2.join();

	return 0;
}
