
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMRC_HPP_INCLUDE__
#define __DMRC_HPP_INCLUDE__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <string>

#include "dmrc.h"
#include "pybind11/pybind11.h"
class CDMRC
{
public:
    // export_begin
    CDMRC()
    {
        SetEncryptKey(m_strEncryptKey);
        SetDecryptKey(m_strDecryptKey);
    }

    void SetKey(const std::string& strtKey)
    {
        SetEncryptKey(strtKey);
        SetDecryptKey(strtKey);
    }

    void SetEncryptKey(const std::string& strEncryptKey)
    {
        m_strEncryptKey = strEncryptKey;
        m_strEncryptKey.resize(256);
        arc4_setup(&m_oEncryptContext, (const unsigned char*)m_strEncryptKey.c_str(), (unsigned int)m_strEncryptKey.size());
    }

    void SetDecryptKey(const std::string& strDecryptKey)
    {
        m_strDecryptKey = strDecryptKey;
        m_strDecryptKey.resize(256);
        arc4_setup(&m_oDecryptContext, (const unsigned char*)m_strDecryptKey.c_str(), (unsigned int)m_strDecryptKey.size());
    }

    pybind11::bytes Encrypt(const std::string& strBuf)
    {
        std::string strOut;
        strOut.resize(strBuf.size());
        arc4_crypt(&m_oEncryptContext, strBuf.size(), (const unsigned char*)strBuf.data(), (unsigned char*)strOut.data());
        return pybind11::bytes(strOut);
    }

    pybind11::bytes Decrypt(const std::string& strBuf)
    {
        std::string strOut;
        strOut.resize(strBuf.size());
        arc4_crypt(&m_oDecryptContext, strBuf.size(), (const unsigned char*)strBuf.data(), (unsigned char*)strOut.data());
        return pybind11::bytes(strOut);
    }
    // export_end

    char* Encryptc(char* pBuf, size_t len)
    {
        arc4_crypt(&m_oEncryptContext, len, (unsigned char*)pBuf, (unsigned char*)pBuf);
        return pBuf;
    }

    char* Decryptc(char* pBuf, size_t len)
    {
        arc4_crypt(&m_oDecryptContext, len, (const unsigned char*)pBuf, (unsigned char*)pBuf);
        return pBuf;
    }

    unsigned char* Encryptcu(unsigned char* pBuf, size_t len)
    {
        arc4_crypt(&m_oEncryptContext, len, pBuf, pBuf);
        return pBuf;
    }


    unsigned char* Decryptcu(unsigned char* pBuf, size_t len)
    {
        arc4_crypt(&m_oDecryptContext, len, pBuf, pBuf);
        return pBuf;
    }


private:
    std::string m_strEncryptKey;
    std::string m_strDecryptKey;

    arc4_context m_oEncryptContext;
    arc4_context m_oDecryptContext;
};

#endif // __DMRC_HPP_INCLUDE__
