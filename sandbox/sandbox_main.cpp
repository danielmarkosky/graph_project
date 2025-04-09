#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

std::counting_semaphore semaphore(
    90);  // Allows up to 3 threads to access the resource

void worker(int id) {
    std::cout << "Thread " << id << " waiting to enter...\n";
    semaphore.acquire();  // Decrement the semaphore count
    std::cout << "Thread " << id << " entered.\n";

    // Simulate work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << id << " leaving.\n";
    semaphore.release();  // Increment the semaphore count
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;

    // Create 5 threads
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(worker, i);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "All threads completed in " << duration.count()
              << " seconds.\n";
}