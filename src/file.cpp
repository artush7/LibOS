#include "file.hpp"
#include <stdexcept>

File::File(const std::string filename) : filename_(filename)
{
    fd_ = open(filename_.c_str(),O_CREAT | O_EXCL,0664);
    if (fd_ == -1)
    {
        perror("failed to create file");
        throw std::runtime_error("");
    }
}

File::File() 
{
    fd_ = -1;
}

bool File::exists() const
{
    struct stat buffer;
    return(stat(filename_.c_str(),&buffer) == 0);
}


File::~File()
{
    close(fd_);
}