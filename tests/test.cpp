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

TEST(File,open_passed)
{
    File f("file.txt");
    EXPECT_NO_THROW(f.open("file.txt"));
    unlink("file.txt");
}

TEST(File,open_failed)
{
    File f("file.txt");
    EXPECT_THROW({f.open("file1.txt");},std::runtime_error);
    unlink("file.txt");
}

TEST(File,remove_passed)
{
    File f("file.txt");
    EXPECT_NO_THROW(f.remove("file.txt"));
    unlink("file.txt");
}


TEST(File,remove_failed)
{
    File f("file.txt");
    EXPECT_THROW({f.remove("file1.txt");},std::runtime_error);
    unlink("file.txt");
}

TEST(File,write_read)
{
    File f("file.txt");
    std::string msg = "something";
    f.write("file.txt",msg);
    std::cout << msg << std::endl;
    std::string result = f.read("file.txt");
    EXPECT_EQ(result,msg);
    unlink("file.txt");
}
