#include "HelloTriangleApplication.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation",
};

#if defined(DEBUG) || defined(FAST_DEBUG)
    const bool enableValidationLayers = true;
#else
    const bool enableValidationLayers = false;
#endif

void HelloTriangleApplication::Run() {
    InitVulkan();
    MainLoop();
    Cleanup();
}

void HelloTriangleApplication::InitWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

void HelloTriangleApplication::InitVulkan() {
    CreateInstance();
}

bool HelloTriangleApplication::CheckValidationLayerSupport() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char* layerName : validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                return false;
            }
        }

    return true;
}

void HelloTriangleApplication::CreateInstance() {
    DEBUG_COUT_FUNC("[LOG]: Started creating vulkan instance...");

    if (enableValidationLayers || !CheckValidationLayerSupport()) {
        throw std::runtime_error("[ERR]: Validation layers requested, but not available!");
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    if (enableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();
    }
    else {
        createInfo.enabledLayerCount = 0;
    }

    VkResult vulkanInstanceCreationResult = vkCreateInstance(&createInfo, nullptr, &instance);
    /* VKResult checking */ {
        if (vulkanInstanceCreationResult != VK_SUCCESS) {
            DEBUG_CERR_FUNC("Failed to create instance, VkResult: " << vulkanInstanceCreationResult);
            throw std::runtime_error("Failed to create vulkan instance!");
        }
        else if (vulkanInstanceCreationResult == VK_SUCCESS) {
            DEBUG_COUT_FUNC("Vulkan instance sucessfully created!");
        }
        else {
            DEBUG_CERR_FUNC("Something REALLY went wrong when creating vulkan instance.\n"
                         << "The VkResult wasn't == VK_SUCCESS || !equal.\n"
                         << "Like the great Technoblade would have said: \"HE?!?\"");
            throw std::runtime_error("Failed to create vulkan instance?!?");
        }
    }

    DEBUG_COUT_FUNC("Finished creating vulkan instance.");
}

void HelloTriangleApplication::MainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void HelloTriangleApplication::Cleanup() {
    vkDestroyInstance(instance, nullptr);

    glfwDestroyWindow(window);
    glfwTerminate();
}
