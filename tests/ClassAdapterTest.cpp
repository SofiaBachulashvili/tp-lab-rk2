#include <gtest/gtest.h>
#include "adapter/ClassAdapter.cpp"

// Тест для класса Adapter
TEST(AdapterTest, RequestTest) {
  Adapter adapter;
  
  // Проверяем, что метод request делегирует вызов метода specificRequest объекту Adaptee
  testing::internal::CaptureStdout();
  adapter.request();
  std::string output = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output, "specific request\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
