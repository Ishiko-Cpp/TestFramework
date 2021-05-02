/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/TestFramework/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TESTFRAMEWORK_CORE_TESTMACROSFORMATTER_H_
#define _ISHIKO_TESTFRAMEWORK_CORE_TESTMACROSFORMATTER_H_

#include <string>
#include <type_traits>

namespace Ishiko
{
namespace Tests
{

namespace Internal
{

template <typename T, typename Enable = void>
class UniversalFormatter
{
public:
    static bool Format(const T& value, std::string& output);
};

template <>
class UniversalFormatter<char*>
{
public:
    static bool Format(const char* value, std::string& output);
};

template <>
class UniversalFormatter<std::string>
{
public:
    static bool Format(const std::string& value, std::string& output);
};

template <>
class UniversalFormatter<bool>
{
public:
    static bool Format(bool value, std::string& output);
};

template <typename T>
class UniversalFormatter<T, typename std::enable_if<std::is_integral<T>::value>::type>
{
public:
    static bool Format(T value, std::string& output);
};

template <typename T>
class UniversalFormatter<T, typename std::enable_if<!std::is_integral<T>::value && std::is_convertible<T, int>::value>::type>
{
public:
    static bool Format(T value, std::string& output);
};

}

class TestMacrosFormatter
{
public:
    template <typename V>
    static std::string Format(const std::string& macro, const std::string& valueString, const V& value);

    template <typename V, typename R>
    static std::string Format(const std::string& macro, const std::string& valueString,
        const std::string& referenceString, const V& value, const R& reference);
};

template <typename V>
std::string TestMacrosFormatter::Format(const std::string& macro, const std::string& valueString, const V& value)
{
    std::string result;

    result += macro + "(" + valueString + ") failed with actual value (";

    std::string formattedValue;
    Internal::UniversalFormatter<typename std::decay<V>::type>::Format(value, formattedValue);
    result += formattedValue;

    result += ")";

    return result;
}

template <typename V, typename R>
std::string TestMacrosFormatter::Format(const std::string& macro, const std::string& valueString,
    const std::string& referenceString, const V& value, const R& reference)
{
    std::string result;

    result += macro + "(" + valueString + ", " + referenceString + ") failed with actual values (";

    std::string formattedValue;
    Internal::UniversalFormatter<typename std::decay<V>::type>::Format(value, formattedValue);
    result += formattedValue;

    result += ", ";

    std::string formattedReference;
    Internal::UniversalFormatter<typename std::decay<R>::type>::Format(reference, formattedReference);
    result += formattedReference;

    result += ")";

    return result;
}

template <typename T, typename Enable>
bool Internal::UniversalFormatter<T, Enable>::Format(const T& value, std::string& output)
{
    return false;
}

template <typename T>
bool Internal::UniversalFormatter<T, typename std::enable_if<std::is_integral<T>::value>::type>::Format(T value, std::string& output)
{
    output = std::to_string(value);
    return true;
}

template <typename T>
bool Internal::UniversalFormatter<T, typename std::enable_if<!std::is_integral<T>::value && std::is_convertible<T, int>::value>::type>::Format(T value, std::string& output)
{
    output = std::to_string(value);
    return true;
}

}
}

#endif
