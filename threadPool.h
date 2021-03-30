#pragma once

/**
 * @file      threadPool.h
 *
 * @brief     simple example of Thread Pool
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include <vector>
#include <functional> 
#include <thread>
#include <atomic>

#include "threadSafeQueue.h"


class ThreadPool
{
public:
    /**
     * @brief                  Creates the specified number of threads  
     * 
     * @param thread_count     Number of threads to be created
     */
    ThreadPool(const size_t thread_count);
    ~ThreadPool();

    // ThreadPoool is not copyable
    // ThreadPoool is not movable
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    /**
     * @brief               Add function to the execution queue 
     * 
     * @param funct         Function that is added to the execution queue
     */
    void submit(std::function<void()> funct);

private:

    /**
     * @brief       Runs functions from the queue
     * 
     */
    void workingThreads();

    /**
     * @brief stops all joinable threads
     *
     */
    void stopThreads();

private:
    // Vector of working threads
    std::vector<std::thread> threads;

    // Flag that indicate the
    // Possibility of obtaining a task
    std::atomic_bool run{true};

    // Thread-safe queue of tasks
    ThreadSafeQueue workQueue;
};
