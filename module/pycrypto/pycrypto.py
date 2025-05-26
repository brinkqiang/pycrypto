# -*- coding: utf-8 -*-
import pycrypto

rc = pycrypto.CDMRC()
rc.SetKey("123456")
enbuf = rc.Encrypt("hello world")
print(enbuf)
debuf = rc.Decrypt(enbuf)
print(debuf)

md5 = pycrypto.CDMMD5()
print(md5.GetMD5("hello world"))

base64 = pycrypto.CDMBase64()
base64_encode = base64.Base64Encode("hello world")
print(base64_encode)
base64_decode = base64.Base64Decode(base64_encode)
print(base64_decode)


aes = pycrypto.CDMAES()

plain = "hello world12345" # Plaintext length must be divisible by 16
iv = "hello world"
key = "hello world"

aes_encode = aes.EncodeECB(plain, key)
print(f"aes_ecb_encode -> {aes_encode}") # Added a more descriptive print
aes_decode = aes.DecodeECB(aes_encode, key)
print(f"aes_ecb_decode -> {aes_decode}") # Added a more descriptive print

aes_encode2 = aes.EncodeCFB(plain, key, iv)
print(f"aes_cfb_encode -> {aes_encode2}") # Added a more descriptive print
aes_decode2 = aes.DecodeCFB(aes_encode2, key, iv)
print(f"aes_cfb_decode -> {aes_decode2}") # Added a more descriptive print

# Added CBC Example
aes_encode_cbc = aes.EncodeCBC(plain, key, iv)
print(f"aes_cbc_encode -> {aes_encode_cbc}")

aes_decode_cbc = aes.DecodeCBC(aes_encode_cbc, key, iv)
print(f"aes_cbc_decode -> {aes_decode_cbc}")