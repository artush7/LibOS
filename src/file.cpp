#include "file.hpp"
#include <stdexcept>

File::File(const std::string filename) : filename_(filename)
{
    if (open(filename_.c_str(),O_CREAT | O_EXCL,0664) == -1)
    {
        throw std::runtime_error("failed to create file");
    }
}

File::File() {}

bool File::exists() const
{
    struct stat buffer;
    return(stat(filename_.c_str(),&buffer) == 0);
}


File::~File()
{
    unlink(filename_.c_str());
}