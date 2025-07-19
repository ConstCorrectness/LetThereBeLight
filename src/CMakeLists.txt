

add_executable(HorribleGPU 
  main.cc
)

add_subdirectory(webgpu)

target_link_libraries(HorribleGPU PRIVATE webgpu)
target_copy_webgpu_binaries(HorribleGPU)


if(EMSCRIPTEN)
  set_target_properties(HorribleGPU PROPERTIES SUFFIX ".html")
endif()


