#ifndef CLASSADAPTER_HPP
#define CLASSADAPTER_HPP

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
  ~Adaptee() {}
  
  void specificRequest();
};

class Adapter : public Target, private Adaptee
{
public:
  virtual void request();
};

#endif
