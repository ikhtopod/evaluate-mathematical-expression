#include <gtest/gtest.h>
#include "calc.hpp"


using reclue::calc;


TEST(calc, NoFatalFailure) {
    ASSERT_NO_FATAL_FAILURE(calc(""));
    ASSERT_NO_FATAL_FAILURE(calc(" ( ( ) ) "));

    ASSERT_NO_FATAL_FAILURE(calc("10 * ("));
    ASSERT_NO_FATAL_FAILURE(calc(") * 10"));
    ASSERT_NO_FATAL_FAILURE(calc(" ( 10 *  ) ) "));

    ASSERT_NO_FATAL_FAILURE(calc("10 * ()"));
    ASSERT_NO_FATAL_FAILURE(calc("() * 10"));
    ASSERT_NO_FATAL_FAILURE(calc(" ( 10 * ( ) ) "));

    ASSERT_NO_FATAL_FAILURE(calc("(2 / (2 + 3.33) * 4) - -6"));

    ASSERT_NO_FATAL_FAILURE(calc("-(2.3) + -7 - (-2) * -(6 / 3)"));
    ASSERT_NO_FATAL_FAILURE(calc("(-(2.3) + -7 - (-2)) * -(6 / 3)"));
    ASSERT_NO_FATAL_FAILURE(calc("-(2.3) + (-7 - (-2)) * -(6 / 3)"));
}

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

TEST(calc, Zero) {
    ASSERT_DOUBLE_EQ(0.0, calc("10 * ("));
    ASSERT_DOUBLE_EQ(0.0, calc(") * 10"));
    ASSERT_DOUBLE_EQ(0.0, calc(" ( 10 *  ) ) "));

    ASSERT_DOUBLE_EQ(0.0, calc("10 * ()"));
    ASSERT_DOUBLE_EQ(0.0, calc("() * 10"));
    ASSERT_DOUBLE_EQ(0.0, calc(" ( 10 * ( ) ) "));
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
}

TEST(calc, SplitComplexExample) {
    ASSERT_DOUBLE_EQ(-7.0, calc("-7"));
    ASSERT_DOUBLE_EQ(-2.0, calc("(-2)"));
    ASSERT_DOUBLE_EQ(-23.0, calc("-(23)"));
    ASSERT_DOUBLE_EQ(2.0, calc("6 / 3"));
    ASSERT_DOUBLE_EQ(-2.0, calc("-(6 / 3)"));
    ASSERT_DOUBLE_EQ(-30.0, calc("-(23) + -7"));
    ASSERT_DOUBLE_EQ(-5.0, calc("-7 - (-2)"));
    ASSERT_DOUBLE_EQ(-28.0, calc("-(23) + -7 - (-2)"));
    //ASSERT_DOUBLE_EQ(4.0, calc("(-2) * -(6 / 3)"));
    //ASSERT_DOUBLE_EQ(-11.0, calc("-7 - (-2) * -(6 / 3)"));
    //ASSERT_DOUBLE_EQ(-34.0, calc("-(23) + -7 - (-2) * -(6 / 3)"));
}

/*TEST(calc, ComplexExamples) {
    ASSERT_DOUBLE_EQ(-13.3, calc("-(2.3) + -7 - (-2) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(14.6, calc("(-(2.3) + -7 - (-2)) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(7.7, calc("-(2.3) + (-7 - (-2)) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(7.500938086, calc("(2 / (2 + 3.33) * 4) - -6"));
}*/

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
