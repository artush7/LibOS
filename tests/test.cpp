#include <gtest/gtest.h>
#include "file.hpp"

TEST(File, create)
{
    File f("file1.txt");
    EXPECT_TRUE(f.exists());
}

TEST(File,create_false )
{
    File f;
    EXPECT_FALSE(f.exists());
}

TEST(File,create_throw)
{

    EXPECT_THROW(File f("/faddfad/dafa/fds"),std::runtime_error);
}

