#include "pch.h"
#include "Class.h"
#include "Class.g.cpp"

namespace winrt::SimpleCustomComponent::implementation
{
    int32_t Class::MyProperty()
    {
        return _myProperty;
    }

    void Class::MyProperty(int32_t value)
    {
        _myProperty = value;
    }
}
