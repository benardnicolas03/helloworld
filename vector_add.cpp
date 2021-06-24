//For CPU or GPU

#include <CL/sycl.hpp>
#include <array>
#include <iostream>
using namespace sycl;

//For FPGA

#include <CL/sycl.hpp>
#include <array>
#include <iostream>
#if FPGA || FPGA_EMULATOR
#include <CL/sycl/INTEL/fpga_extensions.hpp>
#endif
using namespace sycl;

// Use this to create an exception handler with catch async exceptions.

static auto exception_handler = [](cl::sycl::exception_list eList) {
	for (std::exception_ptr const &e : eList) {
		try {
			std::rethrow_exception(e);
		}
		catch (std::exception const &e) {
#if _DEBUG
			std::cout << "Failure" << std::endl;
#endif
			std::terminate();
		}
	}
};
… … 
try {
    queue q(d_selector, exception_handler);
    … … 
} catch (exception const &e) {
    … … 
}