#pragma once
#include <string>
#include <vector>

unsigned int ReadUInt(unsigned char* pBuf);
int ReadInt(unsigned char* pBuf);
unsigned char ReadUChar(unsigned char* pBuf);
unsigned char ReadUChar(char* pBuf);
std::string ReadStr(unsigned char* pBuf);


//ʮ����ʮ,a -> 10
unsigned char HexToBin(unsigned char HexCode);

//ö��Ŀ¼�ļ�

std::vector<std::string> enumDirectoryFiles(const char *dir);

const char* UCharToStr(unsigned char c);