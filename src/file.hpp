#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <iostream>

class File
{
private:
    std::string filename_;
    int fd_;
public:
    File(const std::string filename);
    File();
    ~File();

    void open(const std::string filename);
    void remove(const std::string filename);
    void write(const std::string msg);
    std::string read();
    void rename(const std::string filename,const std::string new_filename);

    bool exists() const;

};