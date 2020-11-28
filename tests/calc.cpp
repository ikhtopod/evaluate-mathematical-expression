#include <gtest/gtest.h>
#include "calc.hpp"


using reclue::calc;


TEST(calc, SimpleTests) {
    ASSERT_DOUBLE_EQ(0.0, calc(""));
    ASSERT_DOUBLE_EQ(5.0, calc("5"));
    ASSERT_DOUBLE_EQ(7.0, calc("5+2"));
    ASSERT_DOUBLE_EQ(3.0, calc("5-2"));
    ASSERT_DOUBLE_EQ(10.0, calc("5*2"));
    ASSERT_DOUBLE_EQ(2.5, calc("5/2"));
    ASSERT_DOUBLE_EQ(10.0, calc("5+2+3"));
}

TEST(calc, ScopeTests) {
    ASSERT_DOUBLE_EQ(0.0, calc("()"));
    ASSERT_DOUBLE_EQ(2.0, calc("(2)"));

    ASSERT_DOUBLE_EQ(5.0, calc("(2+3)"));
    ASSERT_DOUBLE_EQ(5.0, calc("(2)+3"));

    ASSERT_DOUBLE_EQ(28.0, calc("(2+5)*(7 - 3)"));
    ASSERT_DOUBLE_EQ(14.0, calc("(2*5)+(7 - 3)"));

    ASSERT_DOUBLE_EQ(34.0, calc("(2+5*7) - 3"));
    ASSERT_DOUBLE_EQ(34.0, calc("(2+(5*7)) - 3"));

    ASSERT_DOUBLE_EQ(46.0, calc("((2+5)*7) - 3"));

    ASSERT_DOUBLE_EQ(5.0, calc("2+(3)"));
    ASSERT_DOUBLE_EQ(5.0, calc("(2)+(3)"));
    ASSERT_DOUBLE_EQ(5.0, calc("((2)+(3))"));
    ASSERT_DOUBLE_EQ(10.0, calc("(5+2)+3"));
    ASSERT_DOUBLE_EQ(10.0, calc("5+(2+3)"));
}

TEST(calc, UnaryTests) {
    ASSERT_DOUBLE_EQ(-2.0, calc("-2"));

    ASSERT_DOUBLE_EQ(12.0, calc("2 + 10"));
    ASSERT_DOUBLE_EQ(8.0, calc("-2 + 10"));
    ASSERT_DOUBLE_EQ(-8.0, calc("2 + -10"));
    ASSERT_DOUBLE_EQ(-12.0, calc("-2 + -10"));

    ASSERT_DOUBLE_EQ(8.0, calc("-2 + --10"));

    ASSERT_DOUBLE_EQ(-5.0, calc("10 / -2"));
}

TEST(calc, UnaryAndScopeTests) {
    ASSERT_DOUBLE_EQ(-2.0, calc("(-2)"));
    ASSERT_DOUBLE_EQ(-2.0, calc("-(2)"));
    ASSERT_DOUBLE_EQ(-2.0, calc("(-(2))"));
    ASSERT_DOUBLE_EQ(-12.0, calc("(-2) + -10"));
    ASSERT_DOUBLE_EQ(-12.0, calc("-2 + (-10)"));
    ASSERT_DOUBLE_EQ(-12.0, calc("(-2) + (-10)"));
    ASSERT_DOUBLE_EQ(-12.0, calc("(-2) + (-(10))"));
    ASSERT_DOUBLE_EQ(-12.0, calc("((-2) + (-10))"));
}


TEST(calc, NoFatalFailure) {
    ASSERT_NO_FATAL_FAILURE(calc(""));
    ASSERT_NO_FATAL_FAILURE(calc(" ( ( ) ) "));
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


TEST(calc, UnaryOperator) {
    ASSERT_DOUBLE_EQ(-5.0, calc("-5"));
    ASSERT_DOUBLE_EQ(-10.0, calc("-5 -5"));
    ASSERT_DOUBLE_EQ(-15.0, calc("-5 -5 + -5"));
    ASSERT_DOUBLE_EQ(-15.0, calc("-5 -5 -5"));
    ASSERT_DOUBLE_EQ(-15.0, calc("-5 + -5 + -5"));
    ASSERT_DOUBLE_EQ(-15.0, calc("(-5 + -5) + -5"));
    ASSERT_DOUBLE_EQ(-15.0, calc("-5 + (-5 + -5)"));
    ASSERT_DOUBLE_EQ(-15.0, calc("-5 + -(5 - -5)"));
    ASSERT_DOUBLE_EQ(-5.0, calc("-5 + -(5 + -5)"));
    ASSERT_DOUBLE_EQ(-10.0, calc("-5 -5"));
    ASSERT_DOUBLE_EQ(-10.0, calc("-5 ---5"));
    ASSERT_DOUBLE_EQ(-10.0, calc("-5 -----5"));
    ASSERT_DOUBLE_EQ(0.0, calc("-5 ------5"));
    ASSERT_DOUBLE_EQ(0.0, calc("-5 --------5"));
}

TEST(calc, DivideByZero) {
    ASSERT_DOUBLE_EQ(0.0, calc("2 / 0.0"));
    ASSERT_DOUBLE_EQ(0.0, calc("2 / (3.0 - 3)"));
    ASSERT_DOUBLE_EQ(0.0, calc("2 / (5 -5)"));
    ASSERT_DOUBLE_EQ(0.0, calc("2 / (5 + -5)"));
    ASSERT_DOUBLE_EQ(0.0, calc("2 / (-5 + --5)"));
}

TEST(calc, DivideBySmallNumber) {
    ASSERT_DOUBLE_EQ(20.0, calc("2 / 0.1"));
    ASSERT_DOUBLE_EQ(20'000.0, calc("2 / 0.0001"));
}

TEST(calc, Standard) {
    ASSERT_DOUBLE_EQ(2.0, calc("1 + 1"));
    ASSERT_DOUBLE_EQ(0.5, calc("8/16"));
    ASSERT_DOUBLE_EQ(4.0, calc("3 -(-1)"));
    ASSERT_DOUBLE_EQ(0.0, calc("2 + -2"));
    ASSERT_DOUBLE_EQ(-1.0, calc("2 + -3"));
    ASSERT_DOUBLE_EQ(13.0, calc("10- 2- -5"));
    ASSERT_DOUBLE_EQ(10.0, calc("(((10)))"));
}

TEST(calc, Priority) {
    ASSERT_DOUBLE_EQ(15.0, calc("3 * 5"));
    ASSERT_DOUBLE_EQ(15.0, calc("5 * 3"));
    ASSERT_DOUBLE_EQ(14.0, calc("-7 * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(14.0, calc("-(6 / 3) * -7"));
    ASSERT_DOUBLE_EQ(27.0, calc("3 * 3 * 3"));
    ASSERT_DOUBLE_EQ(3.0, calc("3 / 3 * 3"));
    ASSERT_DOUBLE_EQ(3.0, calc("3 * 3 / 3"));
    ASSERT_DOUBLE_EQ(1.0, calc("2 / 6 * 3"));
    ASSERT_DOUBLE_EQ(4.0, calc("2 * 6 / 3"));
    ASSERT_DOUBLE_EQ(1.0 / 9.0, calc("2 / (6 * 3)"));
    ASSERT_DOUBLE_EQ(4.0, calc("2 * (6 / 3)"));
    ASSERT_DOUBLE_EQ(12.0, calc("2 * 3 / 2 * 4"));
    ASSERT_DOUBLE_EQ(12.0, calc("2 * (3 / 2) * 4"));
    ASSERT_DOUBLE_EQ(12.0, calc("2 * ((3 / 2) * 4)"));
    ASSERT_DOUBLE_EQ(-22.0, calc("(2 * 3) - (4 * 7)"));
    ASSERT_DOUBLE_EQ(0.75, calc("(2 * 3) / (2 * 4)"));
    ASSERT_DOUBLE_EQ(12.0, calc("(2 * (3 / 2)) * 4"));
    ASSERT_DOUBLE_EQ(-22.0, calc("2 * 3 - 4 * 7"));
    ASSERT_DOUBLE_EQ(7.0, calc("2 + 3 * 4 - 7"));
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
    ASSERT_DOUBLE_EQ(4.0, calc("(-2) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(-11.0, calc("-7 - (-2) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(-34.0, calc("-(23) + -7 - (-2) * -(6 / 3)"));
}

TEST(calc, ComplexExamples) {
    ASSERT_DOUBLE_EQ(-13.3, calc("-2.3 + -7 - -2 * -6 / 3"));

    ASSERT_DOUBLE_EQ(-13.3, calc("-(2.3) + -7 - (-2) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(14.6, calc("(-(2.3) + -7 - (-2)) * -(6 / 3)"));
    ASSERT_DOUBLE_EQ(7.7, calc("-(2.3) + (-7 - (-2)) * -(6 / 3)"));

    ASSERT_DOUBLE_EQ(((2.0 / (2.0 + 3.33) * 4.0) - -6.0), calc("(2 / (2 + 3.33) * 4) - -6"));
}

TEST(calc, MoreTests) {
    ASSERT_DOUBLE_EQ(-6221.0, calc("81-16+26-6255-57"));
    ASSERT_DOUBLE_EQ(-6733.0, calc("(-6)+(18+27/-1*(37))+(-96*-1*(((-1*(54+6))))--14)"));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
