//
//  Semaphore.h
//  Test2019
//
//  Created by Risukhin Denys on 3/9/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Semaphore_h
#define Semaphore_h

//Semaphore is another synchronization primitive commonly used in multithreaded programming to control access to a shared resource with a limited number of slots or permits.
//It allows multiple threads to access the resource concurrently(одновременно) up to a specified limit, thus regulating concurrent access. (тем самым регулируя одновременный доступ.)

//In C++, semaphores are not provided in the standard library (until C++20), but they can be implemented using other synchronization primitives like mutexes and condition variables. However, many C++ libraries and platforms offer semaphore implementations or equivalents.
//
//Here's a basic example of how you can implement a semaphore using mutex and condition variables in C++:

//In this example:
//
//We define a Semaphore class with acquire() and release() methods to respectively decrement and increment the semaphore count, along with a mutex and a condition variable for synchronization.
//Each thread acquires the semaphore before performing its work and releases it afterward.
//The semaphore ensures that at most three threads can concurrently acquire the semaphore, enforcing a limit on concurrent access to the shared resource.
//Semaphores are useful for scenarios where you need to control access to a limited resource, such as a connection pool, a bounded buffer, or a fixed-size thread pool. They provide a flexible and efficient mechanism for coordinating concurrent operations in multithreaded programs.

#include <mutex>
#include <condition_variable>
#include <iostream>

class Semaphore
{
public:
    Semaphore(int count = 1) : count_(count) {}

    void acquire() // получать
    {
        std::unique_lock<std::mutex> lock(mutex_);
    
        while (count_ == 0)
        {
            condition_.wait(lock);
        }
        --count_;
    }

    void release()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        ++count_;
        condition_.notify_one();
    }

private:
    int count_;
    std::mutex mutex_;
    std::condition_variable condition_;
};

Semaphore semaphore(3); // Example semaphore with 3 permits

void threadFunction(int id)
{
    semaphore.acquire();
    std::cout << "Thread " << id << " acquired semaphore\n";
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " releasing semaphore\n";
    semaphore.release();
}

int main()
{
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);
    std::thread t3(threadFunction, 3);
    std::thread t4(threadFunction, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}


#endif /* Semaphore_h */
