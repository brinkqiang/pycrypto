/********************************************************************
**       This cc file is generated by program,                     **
**            Please do not change it directly.                    **
**                   Auther: brinkqiang                            **
********************************************************************/
// source: pycrypto.pkg

#include "pycrypto.pybind11.h"


#include "dmrc.hpp"

#include "dmmd5.h"

#include "dmbase64.h"


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <algorithm>

PYBIND11_MODULE(pycrypto, m) {

    pybind11::class_<CDMRC>(m, "CDMRC")
    .def(pybind11::init<>())
    .def("SetKey", &CDMRC::SetKey)
    .def("SetEncryptKey", &CDMRC::SetEncryptKey)
    .def("SetDecryptKey", &CDMRC::SetDecryptKey)
    .def("Encrypt", &CDMRC::Encrypt)
    .def("Decrypt", &CDMRC::Decrypt);

    pybind11::class_<CDMMD5>(m, "CDMMD5")
    .def(pybind11::init<>())
    .def("GetMD5", &CDMMD5::GetMD5);

    pybind11::class_<CDMBase64>(m, "CDMBase64")
    .def(pybind11::init<>())
    .def("Base64Encode", &CDMBase64::Base64Encode)
    .def("Base64Decode", &CDMBase64::Base64Decode)
    .def("hex2bin", &CDMBase64::hex2bin)
    .def("bin2hex", &CDMBase64::bin2hex);

}
