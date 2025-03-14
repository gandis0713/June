#include "instance.h"
#include <iostream>

namespace june
{

Instance* Instance::create(JuneInstanceDescriptor const* descriptor)
{
    return new Instance(descriptor);
}

Instance::Instance(JuneInstanceDescriptor const* descriptor)
{
}

JuneApiContext Instance::createApiContext(JuneApiContextDescriptor const* descriptor)
{
    std::cout << "test" << std::endl;
    return nullptr;
}

} // namespace june