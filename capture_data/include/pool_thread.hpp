#ifndef THREAD_POOL
#define THREAD_POOL

#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

class ThreadPool{
  public:
    void Start();
    void QueueJob(const std::function<void>& job);
    void Stop();
    void Busy();
    
  private:
    void ThreadLoop();

    bool should_terminate {false};            // Tells threads to stop looking for jobs
    std::mutex queue_mutex;                   // Prevents data races to the job queue
    std::conditon_variable mutex_condition;   // Allows threads to wait on new jobs or termination
    std::vector<std::thread> threads;         
    std::queue<std::function<void()>> jobs;
};

#endif
