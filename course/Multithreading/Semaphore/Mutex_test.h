//
//  Mutex_test.h
//  Test2019
//
//  Created by Risukhin Denys on 3/9/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Mutex_test_h
#define Mutex_test_h

// Thread Creation:

#include <thread>
#include <iostream>

void threadFunction() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(threadFunction);
    t.join(); // Wait for the thread to finish
    return 0;
}

// Mutexes
#include <mutex>
#include <iostream>

std::mutex mtx;

void threadFunction() {
    mtx.lock();
    std::cout << "Hello from thread!\n";
    mtx.unlock();
}

int main() {
    std::thread t(threadFunction);
    t.join(); // Wait for the thread to finish
    return 0;
}

// Thread Communication

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void threadFunction() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(threadFunction);
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    t.join(); // Wait for the thread to finish
    return 0;
}

// std::condition_variable

//In this example:
//The worker thread waits on the condition variable cv until ready becomes true.
//The main thread sets ready to true and notifies the worker thread using cv.notify_one().
//Spurious Wake-ups:
//Spurious wake-ups are when a thread wakes up from wait() even though no thread called notify_one() or notify_all(). This can happen due to implementation details and should be handled by checking the condition after waking up.
//std::condition_variable provides a powerful mechanism for coordinating the execution of multiple threads based on certain conditions. It is commonly used in producer-consumer scenarios, thread synchronization, and other situations where threads need to wait for specific conditions to be met before proceeding.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker_thread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until ready is true
    std::cout << "Worker thread is processing\n";
}

int main() {
    std::thread worker(worker_thread);

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Main thread notifies\n";
    }
    cv.notify_one(); // Notify the worker thread

    worker.join();
    return 0;
}

#endif /* Mutex_test_h */
