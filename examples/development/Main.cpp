#include "../../include/framerat/Framerat.hpp"
#include <memory>

using namespace framerat;
using namespace framerat::core;
using namespace framerat::core::windowing;
using namespace framerat::core::windowing::factory;
using namespace framerat::core::windowing::factory::glfw;

int main() {
    std::shared_ptr<GLFWWindowFactory> windowFactory(new GLFWWindowFactory());
    std::shared_ptr<Window> window = windowFactory->create();
    return 0;
}
