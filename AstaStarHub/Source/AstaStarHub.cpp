#include <AstaStar.h>
#include <GLFW/glfw3.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

int main(int argc, char** argv)
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "AstaStarHub", NULL, NULL);

    bgfx::PlatformData pd;
    pd.nwh = glfwGetWin32Window(window);

    bgfx::Init bgfxInit;
    bgfxInit.platformData      = pd;
    bgfxInit.type              = bgfx::RendererType::Count;
    bgfxInit.resolution.width  = 1920;
    bgfxInit.resolution.height = 1080;
    bgfxInit.resolution.reset  = BGFX_RESET_VSYNC;

    bgfx::init(bgfxInit);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, 1920, 1080);

    unsigned int counter = 0;
    while (!glfwWindowShouldClose(window))
    {
        bgfx::touch(0);
        bgfx::frame();
        counter++;
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}