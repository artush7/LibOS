#include <gtest/gtest.h>
#include "file.hpp"

TEST(File, create)
{
    File f("file.txt");
    EXPECT_TRUE(f.exists());
    unlink("file.txt");

}

TEST(File,create_false )
{
    File f;
    EXPECT_FALSE(f.exists());
}

TEST(File,create_throw)
{
    EXPECT_THROW({File f("/faddfad/dafa/fds");},std::runtime_error);
}

TEST(File,create_exclusive)
{
    File f("file.txt");
    EXPECT_THROW({File f1("file.txt");},std::runtime_error);
    unlink("file.txt");
}

