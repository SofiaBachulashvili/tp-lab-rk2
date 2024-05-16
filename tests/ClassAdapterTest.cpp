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

// Mock класс для тестирования Adapter
class MockAdapter : public Adapter
{
public:
  MOCK_METHOD(void, specificRequest, (), (override));
};

TEST(AdapterTest, RequestCallsSpecificRequest)
{
  MockAdapter adapter;
  EXPECT_CALL(adapter, specificRequest());

  adapter.request();
}

TEST(AdapteeTest, SpecificRequestPrintsCorrectMessage)
{
  Adaptee adaptee;
  testing::internal::CaptureStdout();
  adaptee.specificRequest();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "specific request\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
