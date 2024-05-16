#ifndef OBJECTADAPTER_HPP
#define OBJECTADAPTER_HPP

#include <iostream>

class Target
{
public:
  virtual ~Target() {}
  
  virtual void request() = 0;
};

class Adaptee
{
public:
  void specificRequest();
};

class Adapter : public Target
{
public:
  Adapter();
  ~Adapter();
  
  void request();

private:
  Adaptee *adaptee;
};

#endif
