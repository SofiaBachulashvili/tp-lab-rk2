#include <gtest/gtest.h>
#include "../adapter/ClassAdapter.cpp"

// Тест для класса Adapter
TEST(AdapterTest, RequestTest) {
  Adapter adapter;
  
  // Проверяем, что метод request делегирует вызов метода specificRequest объекту Adaptee
  testing::internal::CaptureStdout();
  adapter.request();
  std::string output = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output, "specific request\n");
}

TEST(AdapteeTest, SpecificRequestPrintsCorrectMessage) {
  Adaptee adaptee;
  testing::internal::CaptureStdout();
  adaptee.specificRequest();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "specific request\n");
}

TEST(AdapterTest, AdapterCreation) {
  Adapter adapter;

  // Поскольку класс Adapter наследует класс Adaptee приватно, нам нельзя напрямую вызвать метод specificRequest здесь.
  // Для тестирования мы будем использовать макетный объект, чтобы проверить вызов метода.
  MockAdapter mockAdapter;
  EXPECT_CALL(mockAdapter, specificRequest());

  adapter.request();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
