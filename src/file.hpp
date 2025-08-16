#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>


class File
{
private:
    std::string filename_;
    int fd_;
public:
    File(const std::string filename);
    File();
    ~File();

    bool exists() const;

};