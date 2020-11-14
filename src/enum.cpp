#include <iostream>
#include <cassert>

/*
 NOTE: Do NOT actually use enums in your own code. Use the modern "enum class" instead.
 NOTE: But you should be able to understand "enum" in order to read others' code.
*/

enum LogLevel
{
    // * Enum variants are represented as integers.
    // * By default, it starts from 0.
    // * You can also write `Debug = 2, Info = 4` etc.
    Debug,   // 0
    Info,    // 1
    Warning, // 2
    Error    // 3
};

int main()
{
    {
        // * A plain `enum` does not create a namespace
        LogLevel lvl = Info;
        // * A enum is implicitly converted to an integer. Which means:
        // * - It can be directly pushed to std::cout
        std::cout << lvl << std::endl;
        // * - and can be directly compared to an integer.
        assert(Info == 1);
        assert(Warning > 1);
        assert(Error > Debug);
    }
    {
        // ! However, an integer cannot be converted implicitly into an enum.
        // LogLevel lvl = 2;
        // * But can be done so explicitly:
        LogLevel lvl = (LogLevel)2;
    }
    {
        // * You can reassign the identifier `Info` to another value
        int Info = 999;
        // ? but can you set another `LogLevel` to `Info`?
        // LogLevel m = Info;
        // std::cout << m << std::endl;
        // ! No you can't. C++ generally disallows re-defining variables,
        // ! but in the case of enums you are allowed to re-bind a enum
        // ! variant identifier to another value, then you just can't use
        // ! that enum variant.
        // * To avoid this and other kinds of conflicts, it had been a common practice to
        // * enum variants with part of the enum name. For example, the `LogLevel` enum
        // * may be rewritten as:
        // *
        // *     enum LogLevel
        // *     {
        // *         LevelDebug,
        // *         LevelInfo,
        // *         LevelWarning,
        // *         LevelError
        // *     };
        // *
        // * ...which is yet another way C++ has been promoting the violation of the DRY rule
        // * To solve this problem. Instead of allowing using enum variant either with or
        // * without a namespace (which MSVC allows), the C++ committee invented yet another
        // * way to deal with enums, known as the `enum class`.
    }
}