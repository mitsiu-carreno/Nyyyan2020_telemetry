/*
include "thread_pool.hpp"

void ThreadPool::Start(){
  const uint32_t num_threads = std::thread::hardware_concurrency() - 1; // Reserve one thread for graph drawing
  this->threads.resize(num_threads);
  
  for(uint32_t i=0; i < num_threads; ++i){
    threads.at(i) = std::thread(this->ThreadLoop);
  }
}

void ThreadPool::ThreadLoop(){
  while(true){
    std::function<void()> job;

    std::unique_lock<std::mutex> lock(this->queue_mutex);
    mutex_condition.wait(lock, [this]{
      return !jobs.empty || should_terminate;
    });
    if(should_terminate){
      return
    }
    job = jobs.front();
    jobs.pop();
    job();
  }
}

void ThreadPool::QueueJob(){
  
}
 
*/
