#include <gtest/gtest.h>
#include "../adapter/ClassAdapter.cpp"

// Тест для класса Adaptee
TEST(AdapteeTest, SpecificRequestTest) {
  Adaptee adaptee;

  // Проверяем, что метод specificRequest выводит правильное сообщение
  testing::internal::CaptureStdout();
  adaptee.specificRequest();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "specific request\n");
}

// Тест для класса Adapter
TEST(AdapterTest, RequestTest) {
  Adapter adapter;

  // Проверяем, что метод request делегирует вызов метода specificRequest объекту Adaptee
  testing::internal::CaptureStdout();
  adapter.request();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "specific request\n");
}

// Тест для проверки взаимодействия Target с Adapter
TEST(TargetAndAdapterTest, RequestTest) {
  class FakeTarget : public Target {
  public:
    void request() override {
      std::cout << "fake request\n";
    }
  };
  
  FakeTarget fakeTarget;
  Adapter adapter;

  // Проверяем, что метод request вызывает метод request у Target
  testing::internal::CaptureStdout();
  fakeTarget.request();
  std::string targetOutput = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  adapter.request();
  std::string adapterOutput = testing::internal::GetCapturedStdout();

  EXPECT_EQ(targetOutput, "fake request\n");
  EXPECT_EQ(adapterOutput, "specific request\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
