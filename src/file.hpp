#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>


class File
{
private:
    std::string filename_;
public:
    File(const std::string filename);
    File() {}
    bool exists() const;

};