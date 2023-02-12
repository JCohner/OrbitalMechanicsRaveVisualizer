#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <thread>

#include "entities/EntityManager.h"

class Engine : public EntityManager {
private:
  void WorkThread() override;
public:

};


#endif /* __ENGINE_H__ */