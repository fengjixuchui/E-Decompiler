#pragma once
#include <pro.h>
#include <idp.hpp>
#include "SectionManager.h"
#include "ESymbol.h"
#include "./Module/CTreeFixer.h"
#include "./Module/ECSigMaker.h"
#include "./Module/EAppControlXref.h"
#include "./Module/MicroCodeFixer.h"

enum EArchitectureType
{
	E_UNKNOWN = 0,  //δ֪����
	E_DYNAMIC,      //��̬�������
	E_STATIC,       //��̬�������
};

class IDAMenu;

class EDecompiler:public plugmod_t
{
public:
	EDecompiler();
	~EDecompiler();
public:
	bool idaapi run(size_t) override;
	//��ʼ�������Է���������
	bool InitDecompilerEngine();
private:
	//ɨ�������Ժ���
	void makeFunction(ea_t startAddr, ea_t endAddr);

	//̽�������Գ�������
	bool initEArchitectureType();

	bool Parse_EStatic(unsigned int eHeadAddr);

	//��������������
	void ImportsEStructure();
public:
	EArchitectureType arch;
	ESymbol eSymbol;
	CTreeFixer cTreeFixer;

	ECSigMaker ecSigMaker;
	EAppControlXref eControlXref;
private:
	IDAMenu* gMenu_ShowResource = nullptr;
	IDAMenu* gMenu_ShowGUIInfo = nullptr;
	IDAMenu* gMenu_ShowEventInfo = nullptr;
	IDAMenu* gMenu_ShowImportsInfo = nullptr;
};