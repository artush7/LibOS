#include "file.hpp"
#include <stdexcept>

File::File(const std::string filename) : filename_(filename)
{
    fd_ = ::open(filename_.c_str(), O_CREAT | O_EXCL | O_RDWR, 0666);
    if (fd_ == -1)
    {
        perror("failed to create file");
        throw std::runtime_error("");
    }
}

void File::open(const std::string filename)
{
    filename_ = filename;
    struct stat buffer;
    int stat_result = stat(filename_.c_str(),&buffer);
    if (stat_result == -1)
    {
        perror("file does not exist");
        throw std::runtime_error("");
    }
    else
    {
        fd_ = ::open(filename_.c_str(),O_RDWR);
        if (fd_ == -1)
        {
            perror("failed to open file");
            throw std::runtime_error("");
        }
    }

}

void File::remove(const std::string filename)
{
    filename_ = filename;
    struct stat buffer;
    int stat_result = stat(filename_.c_str(),&buffer);
    if (stat_result == -1)
    {
        perror("file does not exist");
        throw std::runtime_error("");
    }
    else
    {
        auto remove_res = ::unlink(filename_.c_str());
        if (remove_res == -1)
        {
            perror("failed to remove file");
            throw std::runtime_error("");
        }
    }

}

void File::write(const std::string filename,const std::string msg)
{
    filename_ = filename;
    if (fd_ == -1)
    {
        perror("file does not exist");
        throw std::runtime_error("");
    }
    else
    {
        
        auto write_res = ::write(fd_,msg.data(),msg.size());
        if (write_res == -1)
        {
            perror("failed to write in file");
            throw std::runtime_error("");
        }
    }

}

std::string File::read(const std::string filename)
{
    filename_ = filename;
    struct stat buffer_str;
    int stat_result = stat(filename_.c_str(),&buffer_str);
    if (stat_result == -1)
    {
        perror("file does not exist");
        throw std::runtime_error("");
    }
    else
    {
        std::vector<char> buffer(buffer_str.st_size);
        auto read_res = ::read(fd_,buffer.data(),buffer.size());
        if (read_res == -1)
        {
            perror("failed to remove file");
            throw std::runtime_error("");
        }
        else
        {
            return std::string(buffer.begin(),buffer.end());
        }

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
     if (fd_ != -1)
        ::close(fd_);
}