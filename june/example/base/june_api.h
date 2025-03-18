#pragma once

#include "june/june.h"

namespace june
{

class DyLib;
struct JuneAPI
{
    bool loadProcs(DyLib* JuneLib);

    JuneProcGetProcAddress GetProcAddress = nullptr;
    JuneProcCreateInstance CreateInstance = nullptr;
    JuneProcInstanceCreateApiContext InstanceCreateApiContext = nullptr;
    JuneProcInstanceDestroy InstanceDestroy = nullptr;
    JuneProcApiContextCreateSharedMemory ApiContextCreateSharedMemory = nullptr;
    JuneProcApiContextCreateBuffer ApiContextCreateBuffer = nullptr;
    JuneProcApiContextCreateTexture ApiContextCreateTexture = nullptr;
    JuneProcApiContextDestroy ApiContextDestroy = nullptr;
    JuneProcSharedMemoryBeginAccess SharedMemoryBeginAccess = nullptr;
    JuneProcSharedMemoryEndAccess SharedMemoryEndAccess = nullptr;
    JuneProcSharedMemoryDestroy SharedMemoryDestroy = nullptr;
    JuneProcBufferDestroy BufferDestroy = nullptr;
    JuneProcBufferCreateFence BufferCreateFence = nullptr;
    JuneProcTextureCreateFence TextureCreateFence = nullptr;
    JuneProcTextureDestroy TextureDestroy = nullptr;
    JuneProcFenceDestroy FenceDestroy = nullptr;
};

} // namespace june