#include "gmock/gmock.h"
#include "core_mapper/CoreMapper.h"

namespace {
    int pushlishOnFakeIndicatorViaStatic = 0;
}

class CoreMapperFake : public ICoreMapper {
public:
    CoreMapperFake(int *indicator) : indicator_{indicator} {}

    void parse(int version, const char *data) override {
        // ignore
    }

    void publishIfReady() override {
        std::cout << "yes" << std::endl;
        pushlishOnFakeIndicatorViaStatic = 12;
        *indicator_ = 21;
    }

private:
    int *indicator_;
};

class CoreMapperFixture : public ::testing::Test {
public:
    CoreMapper unit_;
};

TEST_F(CoreMapperFixture, oneDispatch) {
    int pushlishOnFakeIndicatorViaLocal = 0;
    unit_.addMapper(1, std::make_unique<CoreMapperFake>(&pushlishOnFakeIndicatorViaLocal));

    // act
    unit_.callback(1, 1, nullptr);

    // assert
    ASSERT_THAT(pushlishOnFakeIndicatorViaStatic, ::testing::Eq(12));
    ASSERT_THAT(pushlishOnFakeIndicatorViaLocal, ::testing::Eq(21));
}