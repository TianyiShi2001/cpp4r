
#include <iostream>

constexpr char NAME[] = "Hideyo";
constexpr char NAME_UTF8[] = "英世";

int main()
{
    const std::string NAME_STRING(NAME);
    const std::string NAME_UTF8_STRING(NAME_UTF8);
    // thank god UTF8 works! If you were in C you would have a hard time.
    std::cout << NAME_UTF8_STRING << " " << NAME_STRING << std::endl;
}