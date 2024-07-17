set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE dynamic)

if(${PORT} MATCHES "glfw3")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()

if(${PORT} MATCHES "fmt")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()

if(${PORT} MATCHES "spdlog")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()

if(${PORT} MATCHES "tomlplusplus")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()

if(${PORT} MATCHES "glm")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()

if(${PORT} MATCHES "entt")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()

if(${PORT} MATCHES "box2d")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()