#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../trashukjuice.cpp"


class MockStreamProcessor : public StreamProcessor{
    public:
        MOCK_METHOD(void , Process , (Operation) , (override));
};

TEST(EncodeTesting , First_and_Last_Test_Encoding){
    MTF mtf;
    std::string res1 = mtf.encode("broood");
    std::string res2 = mtf.encode("bananaaa");
    std::string res3 = mtf.encode("hiphophiphop");

    EXPECT_EQ(res1 , "1 17 15 0 0 5 ");
    EXPECT_EQ(res2 ,"1 1 13 1 1 1 0 0 ");
    EXPECT_EQ(res3 , "7 8 15 2 15 2 2 3 2 2 3 2 ");
}

TEST(DecodeTesting , First_and_Last_Test_Encoding){
    MTF mtf;
    std::string res1 = mtf.decode("1 17 15 0 0 5");
    std::string res2 = mtf.decode("1 1 13 1 1 1 0 0 ");
    std::string res3 = mtf.decode(" 7 8 15 2 15 2 2 3 2 2 3 2");

    EXPECT_EQ(res1 , "broood");
    EXPECT_EQ(res2 ,"bananaaa");
    EXPECT_EQ(res3 , "hiphophiphop");
}


TEST(Jucii_juc , another_one){
    MockStreamProcessor mc;
    Jucii js(&mc);
    EXPECT_CALL(mc , Process(Operation::decoding)).Times(1);

    js.juc_juc("J_Juciii");
}