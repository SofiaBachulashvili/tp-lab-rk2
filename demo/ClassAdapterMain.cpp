#include "../adapter/ClassAdapter.cpp"

int main()
{
  Target *t = new Adapter();
  t->request();
  delete t;
  
  return 0;
}
