


#ifndef _CODEC_H_
#define _CODEC_H_

#pragma warning(disable:4786)
#include <comutil.h>
#include <string>
#pragma comment(lib, "comsupp.lib")

//编码解码


	std::wstring bm_utf8_to_utf16( const char* str );
	std::string  bm_utf16_to_utf8( const wchar_t *str );

	// 	std::string src = "a?@大色";
	// 	std::string utf8 = bm_ascii_to_utf8(src);
	// 	std::string des  = bm_utf8_to_ascii(utf8);
	// 	if (src != des)
	// 	{
	// 		return 0;
	// 	}
	std::string  bm_utf8_to_ascii(std::string strUTF8);
	std::string  bm_ascii_to_utf8(std::string str);

	std::string  bm_utf16_to_ascii(std::wstring wsz);
	std::wstring bm_ascii_to_utf16(std::string sz);

	std::string UrlEncode(const std::string& str);
	std::string UrlDecode(const std::string& str);

	//16进制字符串转二进制
	DWORD HexString2Bits(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);
	//二进制转16进制
	DWORD Bits2HexString(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);
	//成功返回 NO_ERROR
	DWORD HexString2Hex(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);
	DWORD Hex2HexString(PBYTE lpSrc,DWORD dwSrcLenth,PBYTE lpDes);

	//下面这两个是对上面 的进行封装
	std::string Hex2HexString(PBYTE lpSrc,DWORD dwSrcLenth);
	std::string Bits2HexString(PBYTE lpSrc,DWORD dwSrcLenth);


#endif