#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include <memory>
#include <thread>
#include <vector>

#include "EntityObject.h"

/*
A class meant to "manage entities"
It has:
  * a queue of Entities to manage
  * an interface to add elements to queue // todo remove
  * a thread handle for workthread
  * a pure virtual function that will be do the work on the workthread handle
  * a mechanism to start and stop work thread execution
*/

class EntityManager {
protected:
  std::vector<std::shared_ptr<Entity>> entity_queue_;
  std::thread work_thread_;
  virtual void WorkThread() = 0;
  
public:
  void EnqueueEntity(std::shared_ptr<Entity> entity) {entity_queue_.push_back(entity);}
  void StartWork() {work_thread_ = std::thread(&EntityManager::WorkThread, this);}
};



#endif /* __ENTITY_MANAGER_H__ */