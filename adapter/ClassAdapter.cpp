#include "ClassAdapter.hpp"

void Adaptee::specificRequest()
{
  std::cout << "specific request" << std::endl;
}

void Adapter::request()
{
  specificRequest();
}
