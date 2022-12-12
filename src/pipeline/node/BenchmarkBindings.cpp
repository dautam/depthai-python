#include "Common.hpp"
#include "NodeBindings.hpp"
#include "depthai/pipeline/Node.hpp"
#include "depthai/pipeline/Pipeline.hpp"
#include "depthai/pipeline/node/BenchmarkIn.hpp"
#include "depthai/pipeline/node/BenchmarkOut.hpp"

void bind_benchmark(pybind11::module& m, void* pCallstack) {
    using namespace dai;
    using namespace dai::node;

    // Node and Properties declare upfront
    // py::class_<BenchmarkProperties> benchmarkOutProperties(m, "benchmarkOutProperties", DOC(dai, benchmarkOutProperties));
    auto benchmarkOut = ADD_NODE(BenchmarkOut);
    auto benchmarkIn = ADD_NODE(BenchmarkIn);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    // Call the rest of the type defines, then perform the actual bindings
    Callstack* callstack = (Callstack*)pCallstack;
    auto cb = callstack->top();
    callstack->pop();
    cb(m, pCallstack);
    // Actual bindings
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    // Node
    benchmarkOut.def_readonly("out", &BenchmarkOut::out, DOC(dai, node, BenchmarkOut, out))
        .def_readonly("input", &BenchmarkOut::input, DOC(dai, node, BenchmarkOut, input))
        .def("setNumMessagesToSend", &BenchmarkOut::setNumMessagesToSend, py::arg("num"), DOC(dai, node, BenchmarkOut, setNumMessagesToSend));
    benchmarkIn.def_readonly("input", &BenchmarkIn::input, DOC(dai, node, BenchmarkIn, input))
        .def("setNumMessagesToGet", &BenchmarkIn::setNumMessagesToGet, py::arg("num"), DOC(dai, node, BenchmarkIn, setNumMessagesToGet));
}
