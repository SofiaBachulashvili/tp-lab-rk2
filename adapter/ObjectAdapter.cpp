#include "ObjectAdapter.hpp"

void Adaptee::specificRequest()
{
  std::cout << "specific request" << std::endl;
}

Adapter::Adapter() : adaptee(new Adaptee()) {}

Adapter::~Adapter()
{
  delete adaptee;
}

void Adapter::request()
{
  adaptee->specificRequest();
}

/*
int main()
{
  Target *t = new Adapter();
  t->request();
  delete t;
  
  return 0;
}*/
