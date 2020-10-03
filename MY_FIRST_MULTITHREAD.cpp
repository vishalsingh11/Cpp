#include <iostream>
#include <thread>

using namespace std;

void loop()
{
    for(int i; i<10; i++)
    {
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
