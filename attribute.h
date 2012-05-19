#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class attribute
{
public:
    attribute(std::string name, std::string value);
    std::string name;
    std::string value;
};

#endif // ATTRIBUTE_H
