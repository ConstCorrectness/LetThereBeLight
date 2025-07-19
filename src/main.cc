#include "webgpu/webgpu.h"

#include <iostream>
#include <string_view>
#include <concepts>


int main(int argc, char const **argv) {
  WGPUInstanceDescriptor desc { };
  desc.nextInChain = nullptr;

  WGPUInstance instance = wgpuCreateInstance(&desc);

  if (!instance) {
    std::cerr << "[ERROR]: wgpuCreateInstance()\n";
    return 1;
  }


  std::cout << "WGPU instance: " << instance << std::endl;

  return EXIT_SUCCESS;
}