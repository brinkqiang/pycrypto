#include "gtest.h"
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <algorithm>
#include "dmformat.h"


class frame_dmpytest : public testing::Test
{
public:
    virtual void SetUp()
    {
        pycrypto = pybind11::module_::import("pycrypto");
        obj = pycrypto.attr("CDMRC")();
    }
    virtual void TearDown()
    {

    }
protected:
    pybind11::scoped_interpreter guard;
    pybind11::module_ pycrypto;
    pybind11::object obj;

    const int PERF_COUNT = (100 * 10000);
};


TEST_F(frame_dmpytest, dmpytest_pycrypto)
{
    auto SetKey = obj.attr("SetKey");
    auto Encrypt = obj.attr("Encrypt");
    auto Decrypt = obj.attr("Decrypt");

    obj.attr("SetKey")("123456");

    auto enbuf = obj.attr("Encrypt")("hello world").cast<pybind11::bytes>();

    auto debuf = obj.attr("Decrypt")(enbuf).cast<std::string>();
}
