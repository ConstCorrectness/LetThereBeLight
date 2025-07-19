#include "webgpu/webgpu.h"

#include <iostream>
#include <string_view>
#include <concepts>

namespace horrible::utils {


template<typename T, size_t SIZE = sizeof(T), size_t ALIGN = alignof(T)>
class type_info {
public:
  constexpr static size_t const size  = SIZE;
  constexpr static size_t const align = ALIGN;
};

// FL macro
#define TYPE_INFO(T) std::cout << "sizeof(" #T ") = " << sizeof(T) << ", alignof(" #T << ") = " << alignof(T) << std::endl;


}       // end namespace horrible::utils




WGPUInstanceDescriptor desc { };
WGPURequestAdapterOptions opts { .nextInChain = nullptr };
WGPUAdapter adapter { };



int main(int argc, char const **argv) {
  desc.nextInChain = nullptr;

#ifdef WEBGPU_BACKEND_EMSCRIPTEN
  // TODO.
#else
  WGPUInstance instance = wgpuCreateInstance(&desc);
#endif
  if (!instance) {
    std::cerr << "[ERROR]: wgpuCreateInstance()\n";
    return 1;
  }

  std::cout << "WGPU instance: " << instance << std::endl;


  TYPE_INFO(int);
  static_assert(horrible::utils::type_info<int>::align == alignof(int) && horrible::utils::type_info<int>::size == sizeof(int), "horrible::utils::type_info<>");

  return EXIT_SUCCESS;
}