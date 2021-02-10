#include "../../include/framerat/Framerat.hpp"
#include <memory>

using namespace framerat;
using namespace framerat::core;
using namespace framerat::core::windowing;
using namespace framerat::core::windowing::factory;
using namespace framerat::core::windowing::factory::glfw;

int main() {
    std::shared_ptr<GLFWWindowFactory> windowFactory = GLFWWindowFactory::create();
    std::shared_ptr<Window> window = windowFactory->spawn();
    windowFactory->shutdown();
    return 0;
}
