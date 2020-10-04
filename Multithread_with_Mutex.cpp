#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>


void work(int &count, mutex &mtx)
{
    for(int i; i < 1E6; i++)
    {
        mtx.lock();
        count++;
        mtx.unlock();
    }
}


int main()
{
    mutex mtx;
    int count = 0;
    
    thread t1(work, ref(count), ref(mtx));
    thread t2(work, ref(count), ref(mtx));
    
    t1.join();
    t2.join();
    
    cout << count << endl;
    
    return 0;
}

