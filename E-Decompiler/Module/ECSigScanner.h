#pragma once
#include <string>
#include <map>
#include <vector>
#include <list>

class ESymbol;

enum SIG_TYPE
{
	SIG_NORMAL = 0x0,
	SIG_CALL = 0x1,
	SIG_DATA = 0x2,
};

struct SigElement
{
	SIG_TYPE type;
	unsigned int insAddr;
	unsigned short insType;
	std::vector<unsigned char> sig;
};

class op_t;
class insn_t;
class ECSigScanner
{
public:
	static ECSigScanner& Instance();
public:
	bool ScanECSigFunction(ESymbol* s);
	//��ȡ������MD5,bFuzzy��ʾ�Ƿ�Ϊģ������
	std::string GetFunctionMD5(unsigned int funcAddr, bool bFuzzy = false);
private:
	//bUseCache��ʾ�Ƿ�ʹ�û���,bSubFunc��ʾ�Ƿ�Ϊ�Ӻ���
	std::string calFunctionMD5(unsigned int funcAddr, bool bUseCache = false, bool bSubFunc = false);
	//��һ�º����Ľ�����ַ
	unsigned int guessFuncEndAddr(unsigned int funcAddr);
	//����ԭʼ��������,����true��ʾ��������
	bool genSig_rawBinary();
	bool genSig_main(insn_t& tmpIns, bool bSubFunc);

	//�������ĵ�������ָ��,����true��ʾ��������
	bool genSig_flexSingleInst(insn_t& ins);
	//��������˫������ָ��,����true��ʾ��������
	bool genSig_flexDoubleInst(insn_t& ins);

	//������������
	void genSig_PerfectOp(op_t& op, SigElement& outSig);
	//����ģ������
	void genSig_FuzzyOp(op_t& op,SigElement& outSig);

private:
	//key�Ǻ�����ַ,value�Ǻ���MD5����
	std::map<unsigned int, std::string> sigCacheMap;

	//key�Ǻ�����ַ,value�Ǻ�������
	std::map<unsigned int, unsigned int> funcIndexMap;
	//��ǰ����������С
	unsigned int funcIndex;

	//��ǰ���ɽ��
	std::vector<SigElement> sigResult;


	unsigned int currentEA;
	unsigned int endEA;
	bool bFuzzyFlag;
};