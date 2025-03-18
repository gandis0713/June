#pragma once

#include "june/common/cast.h"
#include "june/common/dylib.h"
#include "june/native/context.h"

#include "june/june.h"

#include "vulkan_api.h"

#include <memory>
#include <vector>

namespace june
{

struct VulkanInstanceInfo : VulkanInstanceKnobs
{
    std::vector<VkLayerProperties> layerProperties;
    std::vector<VkExtensionProperties> extensionProperties;
};

struct VulkanPhysicalDeviceInfo : VulkanDeviceKnobs
{
    VkPhysicalDeviceFeatures physicalDeviceFeatures{};
    VkPhysicalDeviceProperties physicalDeviceProperties{};

    std::vector<VkQueueFamilyProperties> queueFamilyProperties{};

    std::vector<VkLayerProperties> layerProperties;
    std::vector<VkExtensionProperties> extensionProperties;

    std::vector<VkMemoryType> memoryTypes;
    std::vector<VkMemoryHeap> memoryHeaps;
};

class Instance;
class VulkanContext : public Context
{
public:
    static Context* create(Instance* instance, JuneVulkanApiContextDescriptor const* descriptor);

public:
    VulkanContext() = delete;
    ~VulkanContext() override;

    VulkanContext(const VulkanContext&) = delete;
    VulkanContext& operator=(const VulkanContext&) = delete;

public: // June APi
    SharedMemory* createSharedMemory(JuneSharedMemoryDescriptor const* descriptor) override;
    Buffer* createBuffer(JuneBufferDescriptor const* descriptor) override;
    Texture* createTexture(JuneTextureDescriptor const* descriptor) override;

public:
    Instance* getInstance() const override;
    JuneApiType getApiType() const override;

public: // vulkan
    VkInstance getVkInstance() const;
    VkPhysicalDevice getVkPhysicalDevice() const;
    VkDevice getVkDevice() const;

    const VulkanInstanceInfo& getInstanceInfo() const;
    const VulkanPhysicalDeviceInfo& getPhysicalDeviceInfo() const;

public:
    VulkanAPI vkAPI{};

private:
    void gatherInstanceInfo();
    void gatherPhysicalDeviceInfo();
    bool checkInstanceExtensionSupport(const std::vector<const char*> requiredInstanceExtensions);
    const std::vector<const char*> getRequiredInstanceExtensions();
    bool checkInstanceLayerSupport(const std::vector<const char*> requiredInstanceLayers);
    const std::vector<const char*> getRequiredInstanceLayers();

private:
    Instance* m_instance = nullptr;

private:
    VkInstance m_vkInstance = VK_NULL_HANDLE;
    VkPhysicalDevice m_vkPhysicalDevice = VK_NULL_HANDLE;
    VkDevice m_vkDevice = VK_NULL_HANDLE;

    DyLib m_vulkanLib{};
    VulkanInstanceInfo m_instanceInfo{};
    VulkanPhysicalDeviceInfo m_physicalDeviceInfo{};

private:
    VulkanContext(Instance* instance, JuneVulkanApiContextDescriptor const* descriptor);
};

} // namespace june
