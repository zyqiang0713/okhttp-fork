#include <catch.hpp>
#include "exception_matcher.hpp"
#include <ohf/TimeUnit.hpp>

using namespace ohf;

TEST_CASE("TimeUnit") {
    TimeUnit seconds = TimeUnit::seconds(10.5);
    REQUIRE(seconds.seconds() == 10.5);
    REQUIRE(seconds.milliseconds() == 10500);
    REQUIRE(seconds.microseconds() == 10500000);
    REQUIRE(seconds.std_time() == 10);

    REQUIRE(seconds.type() == TimeUnit::Type::SECONDS);
    REQUIRE(seconds.value() == 10);
    REQUIRE(seconds.floatValue() == 10.5f);

    REQUIRE(seconds.sec() == 10);
    REQUIRE(seconds.usec() == 500000);

    TimeUnit milliseconds = TimeUnit::milliseconds(988);
    REQUIRE(milliseconds.milliseconds() == 988);
    REQUIRE(milliseconds.type() == TimeUnit::Type::MILLISECONDS);
    REQUIRE(milliseconds.std_time() == 0);
    REQUIRE(milliseconds.usec() == 988);
}
