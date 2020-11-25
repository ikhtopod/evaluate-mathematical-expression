#include <gtest/gtest.h>
#include "calc.hpp"


using reclue::calc;

TEST(calc, Empty) {
    ASSERT_DOUBLE_EQ(0.0, calc(""));
    ASSERT_DOUBLE_EQ(0.0, calc(" "));
    ASSERT_DOUBLE_EQ(0.0, calc("  "));
    ASSERT_DOUBLE_EQ(0.0, calc("()"));
    ASSERT_DOUBLE_EQ(0.0, calc("(())"));
    ASSERT_DOUBLE_EQ(0.0, calc("( ())"));
    ASSERT_DOUBLE_EQ(0.0, calc("(() )"));
    ASSERT_DOUBLE_EQ(0.0, calc(" (() )"));
    ASSERT_DOUBLE_EQ(0.0, calc("(() ) "));
    ASSERT_DOUBLE_EQ(0.0, calc("( () ) "));
    ASSERT_DOUBLE_EQ(0.0, calc(" ( () ) "));
    ASSERT_DOUBLE_EQ(0.0, calc(" ( ( ) ) "));
}

TEST(calc, Standard) {
    ASSERT_DOUBLE_EQ(2.0, calc("1 + 1"));
    ASSERT_DOUBLE_EQ(0.5, calc("8/16"));
    ASSERT_DOUBLE_EQ(4.0, calc("3 -(-1)"));
    ASSERT_DOUBLE_EQ(0.0, calc("2 + -2"));
    ASSERT_DOUBLE_EQ(13.0, calc("10- 2- -5"));
    ASSERT_DOUBLE_EQ(10.0, calc("(((10)))"));
    ASSERT_DOUBLE_EQ(15.0, calc("3 * 5"));
    ASSERT_DOUBLE_EQ(14.0, calc("-7 * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(7.500938086, calc("(2 / (2 + 3.33) * 4) - -6"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
