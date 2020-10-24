
#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "templ/templ.h"

class TemplTest : public ::testing::Test {
public:
    typedef templ::Templ Templ;

};

TEST_F(TemplTest, templ_instantiation) {
    Templ a;
    a.helloWorld();
    EXPECT_EQ(0, 0);
}
