#include "ClassAdapter.hpp"

void Adaptee::specificRequest()
{
  std::cout << "specific request" << std::endl;
}

void Adapter::request()
{
  specificRequest();
}

/*
int main()
{
  Target *t = new Adapter();
  t->request();
  delete t;
  
  return 0;
}*/
