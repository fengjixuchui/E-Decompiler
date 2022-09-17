#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include "ELib.h"

//�����Է�����Ϣ

struct EVENT_INFO
{
	unsigned int m_lpszName;       //�¼�����
	unsigned int m_lpszExplain;    //�¼���ϸ����
	unsigned int m_dwState;        //�¼������־
	int  m_nArgCount;      //�¼��Ĳ�����Ŀ
	unsigned int m_lpEventArgInfo; //����
};

#pragma pack(push,1)



// �������崰�ڵ�Ԫ����
struct UNIT_PROPERTY
{
	unsigned int m_lpszName;      //��������
	unsigned int m_lpszEGName;    //Ӣ������
	unsigned int m_lpszExplain;   //���Խ���
	short  m_shtType;       //���Ե���������
	unsigned short m_wState;        //���Ե�������
	unsigned int m_lpszzPickStr;  //��ѡ�ı�
};

struct LIB_DATA_TYPE_INFO   //�ⶨ���������ͽṹ
{
	unsigned int m_lpszName;     //����
	unsigned int m_lpszEGName;   //Ӣ������,��Ϊ��
	unsigned int m_szExplain;    //��ϸ����,��Ϊ��
	int  m_nCmdCount;    //���������ͳ�Ա��������Ŀ(��Ϊ0)
	unsigned int m_lpnCmdsIndex; //ָ�����г�Ա����������֧�ֿ�������е�����ֵָ��,��������ݱ�Ĩ��
	unsigned int m_dwState;      //�������͵���������

	 ////////////////////////////////////////////
	// ���³�Աֻ����Ϊ���ڵ�Ԫ���˵�ʱ����Ч��

	unsigned int m_dwUnitBmpID;     //ָ����֧�ֿ��еĵ�Ԫͼ����ԴID
	int  m_nEventCount;     //����Ԫ���¼���Ŀ
	unsigned int m_lpEventBegin;    //ָ��Ԫ�������¼���ָ��,EVENT_INFO,��������ݱ�Ĩ��
	int m_nPropertyCount;   //����Ԫ��������Ŀ
	unsigned int m_lpPropertyBegin; //ָ��Ԫ���������Ե�ָ��,UNIT_PROPERTY

	unsigned int m_lpfnGetInterface; //�����ṩ�����ڵ�Ԫ�����нӿڡ�

	////////////////////////////////////////////
	// ���³�Աֻ���ڲ�Ϊ���ڵ�Ԫ���˵�ʱ����Ч��

	int m_nElementCount;    //�������������ӳ�Ա����Ŀ(��Ϊ0)
	unsigned int m_lpElementBegin;   //ָ���ӳ�Ա������׵�ַ,LIB_DATA_TYPE_ELEMENT
};

struct LIB_INFO
{
	unsigned int m_dwLibFormatVer;    //֧�ֿ��ʽ�汾��,Ӧ��Ϊ0x1312D65
	unsigned int m_lpGuid;            //��Ӧ֧�ֿ��GUIDָ�롣
	int  m_nMajorVersion;     //֧�ֿ�����汾�ţ��������0��
	int  m_nMinorVersion;     //֧�ֿ�Ĵΰ汾�š�
	int  m_nBuildNumber;      //�����汾��
	int  m_nRqSysMajorVer;    //����Ҫ������ϵͳ�����汾��
	int  m_nRqSysMinorVer;    //����Ҫ������ϵͳ�Ĵΰ汾��
	int  m_nRqSysKrnlLibMajorVer;   //����Ҫ��ϵͳ����֧�ֿ�����汾��
	int  m_nRqSysKrnlLibMinorVer;   //����Ҫ��ϵͳ����֧�ֿ�Ĵΰ汾��
	unsigned int m_lpName;            //֧�ֿ�����ָ��
	int  m_nLanguage;         //֧�ֿ���֧�ֵ�����,Ӧ����1
	unsigned int m_lpExplain;         //֧�ֿ��������ָ��,��Ϊ��
	unsigned int m_dwState;           //֧�ֿ�����״̬˵��
	unsigned int m_lpszAuthor;        //���������Ϣ
	unsigned int m_lpszZipCode;       //���������Ϣ
	unsigned int m_lpszAddress;       //���������Ϣ
	unsigned int m_lpszPhone;         //���������Ϣ
	unsigned int m_lpszFax;           //���������Ϣ
	unsigned int m_lpszEmail;         //���������Ϣ
	unsigned int m_lpszHomePage;      //���������Ϣ
	unsigned int m_lpszOther;         //���������Ϣ

//////////////////
	int m_nDataTypeCount;     //֧�ֿ�ȫ�����������͸���
	unsigned int m_lpDataType;        //ָ������õ�������������Ϣ��ָ��,LIB_DATA_TYPE_INFO

	int m_nCategoryCount;     //ȫ�����������Ŀ
	unsigned int m_lpszzCategory;     //ȫ���������˵����ÿ��Ϊһ�ַ�����ǰ��λ���ֱ�ʾͼ�������ţ���1��ʼ��0��ʾ�ޣ���
								// ��һ���ֵΪָ��֧�ֿ�����Ϊ"LIB_BITMAP"��BITMAP��Դ��ĳһ����16X13λͼ������

	int m_nCmdCount;          //�������ṩ����������(ȫ��������󷽷�)����Ŀ(������Ϊ0)��
	unsigned int m_lpBeginCmdInfo;    //ָ��������������Ķ�����Ϣ����(��m_nCmdCountΪ0,��ΪNULL),CMD_INFO
	unsigned int m_lpCmdsFunc;        //ָ��ÿ�������ʵ�ִ����׵�ַ��(��m_nCmdCountΪ0, ��ΪNULL)��

	unsigned int m_lpfnRunAddInFn;    //��ΪNULL������Ϊ������IDE�ṩ���ӹ���
	unsigned int m_szzAddInFnInfo;    //�й�AddIn���ܵ�˵���������ַ���˵��һ������

	unsigned int m_lpfnNotify;        //����ΪNULL���ṩ��������������IDE�����л���֪ͨ��Ϣ�ĺ�����

	// ����ģ����ʱ�������á�
	unsigned int m_lpfnSuperTemplate;       //Ϊ��
	unsigned int m_lpszzSuperTemplateInfo;  //Ϊ��

	// ���ⶨ������г�����
	int m_nLibConstCount;   //��������
	unsigned int m_lpLibConst;      //ָ�������������ָ��

	unsigned int m_lpszzDependFiles; //����������������Ҫ�����������ļ�����������װ���ʱ�����Զ�������Щ�ļ�,��Ϊ��
};

#pragma pack(pop)



struct eSymbol_EDataTypeInfo
{
	std::string m_Name;  //������������
};

struct eSymbol_ELibInfo
{
	std::string m_Name;         //֧�ֿ�����
	std::string m_Guid;         //֧�ֿ��GUID
	int  m_nMajorVersion;       //֧�ֿ�����汾�ţ��������0��
	int  m_nMinorVersion;       //֧�ֿ�Ĵΰ汾�š�

	std::vector<eSymbol_EDataTypeInfo> mVec_DataTypeInfo;      //����������Ϣ
};

struct eSymbol_KrnlCall
{
	unsigned int krnl_MReportError;               //����ص�
	unsigned int krnl_MCallDllCmd;                //DLL����
	unsigned int krnl_MCallLibCmd;                //����֧�ֿ�����
	unsigned int krnl_MCallKrnlLibCmd;            //����֧�ֿ�����
	unsigned int krnl_MReadProperty;              //��ȡ�������
	unsigned int krnl_MWriteProperty;             //�����������
	unsigned int krnl_MMalloc;                    //�����ڴ�
	unsigned int krnl_MRealloc;                   //���·����ڴ�
	unsigned int krnl_MFree;                      //�ͷ��ڴ�
	unsigned int krnl_MExitProcess;               //����
	unsigned int krnl_MMessageLoop;               //������Ϣѭ��
	unsigned int krnl_MLoadBeginWin;              //������������
	unsigned int krnl_MOtherHelp;                 //��������
};

struct eSymbol_KrnlJmp
{
	unsigned int Jmp_MReportError;               //����ص�
	unsigned int Jmp_MCallDllCmd;                //DLL����
	unsigned int Jmp_MCallLibCmd;                //����֧�ֿ�����
	unsigned int Jmp_MCallKrnlLibCmd;            //����֧�ֿ�����
	unsigned int Jmp_MReadProperty;              //��ȡ�������
	unsigned int Jmp_MWriteProperty;             //�����������
	unsigned int Jmp_MMalloc;                    //�����ڴ�
	unsigned int Jmp_MRealloc;                   //���·����ڴ�
	unsigned int Jmp_MFree;                      //�ͷ��ڴ�
	unsigned int Jmp_MExitProcess;               //����
	unsigned int Jmp_MMessageLoop;               //������Ϣѭ��
	unsigned int Jmp_MLoadBeginWin;              //������������
	unsigned int Jmp_MOtherHelp;                 //��������
};

struct EComHead
{
	unsigned int dwMagic;  //δ֪,ֵ�̶�Ϊ3
	unsigned int szNone2;  //δ֪,ֵ�̶�Ϊ0
	unsigned int szNone3;  //δ֪,�����Ǹ������,�޸Ĳ�Ӱ�����
	unsigned int lpStartCode;   //��ʼ�û������ַ,�����޸�
	unsigned int lpEString;     //�ַ�����Դ,���û���ַ�����Դ,��Ϊ0
	unsigned int dwEStringSize; //�ַ�����Դ��С,���û���ַ�����Դ,��Ϊ0
	unsigned int lpEWindow;     //���������Ϣ
	unsigned int dwEWindowSize; //���������Ϣ��С
	unsigned int dwLibNum;      //֧�ֿ�����
	unsigned int lpLibEntry;    //֧�ֿ���Ϣ���
	unsigned int dwApiCount;    //Api����
	unsigned int lpModuleName;  //ָ��ģ������
	unsigned int lpApiName;     //ָ��Api����
};

enum eSymbolFuncType
{
	eFunc_Unknown = 0x0,
	//�����Կ⺯��
	eFunc_KrnlLibFunc,
	//��ȡ�������
	eFunc_KrnlReadProerty,
	//�����������
	eFunc_KrnlWriteProperty,
	//����DLL����
	eFunc_KrnlDllCmd,
	//����ص�
	eFunc_KrnlReportError,
	//�ͷ��ڴ�
	eFunc_KrnlFreeMem,
	//�ı����
	eFunc_Strcat,
	//����ʡ�Բ���
	eFunc_PushDefaultArg,
	//�����ά�����±�
	eFunc_CalMultiArrayIndex,
};

struct EAppControl;

struct eSymbol_ControlIndex
{
	unsigned int windowId;
	unsigned int controlId;
public:
	eSymbol_ControlIndex() {};
	eSymbol_ControlIndex(unsigned int w, unsigned int c)
	{
		windowId = w;
		controlId = c;
	}
	bool operator< (const eSymbol_ControlIndex& com)const
	{
		if (com.windowId != this->windowId) {
			return com.windowId < this->windowId;
		}
		return com.controlId < this->controlId;
	}
};


class ESymbol
{
public:
	ESymbol();
	~ESymbol();
public:
	//���������Ծ�̬�������
	bool LoadEStaticSymbol(unsigned int eHeadAddr, EComHead* eHead);

	//��ȡ������������
	eSymbolFuncType GetFuncSymbolType(unsigned int addr);
	//ͨ������ID�Ϳؼ�ID�������ؼ�
	EAppControl* GetEAppControl(unsigned int windowID,unsigned int controID);
private:
	//����֧�ֿ���Ϣ
	bool loadELibInfomation(unsigned int lpLibStartAddr, unsigned int dwLibCount);
	//ɨ�貢ʶ��֧�ֿ⺯��
	bool scanELibFunction(unsigned int lpLibStartAddr, unsigned int dwLibCount);
	//ɨ�貢ʶ�������Ի�������
	bool scanBasicFunction();
	//���������Ժ��ĺ���
	bool loadKrnlInterface(unsigned int lpKrnlEntry);
	//���ؽ�����Դ��Ϣ
	bool loadGUIResource(unsigned int lpGUIStart, unsigned int infoSize);
	//�����û������
	bool loadUserImports(unsigned int dwApiCount, unsigned int lpModuleName, unsigned int lpApiName);
	//��������ʡ�Բ���
	bool handleFuncPushDefaultArg(unsigned int callAddr);
	//ɨ�������������
	bool scanEClassTable();
	//�����ؼ���������
	void parseControlBasciProperty(unsigned char* lpControlInfo, EAppControl* outControl);
	//���ݲ˵�������ID���õ�����,0x10001 -> ����
	std::string getControlTypeName(unsigned int typeId);
	
	bool registerKrnlJmpAddr(unsigned int callAddr, unsigned int setAddr);

	//���ÿؼ����¼�����
	void setGuiEventName();
	//����ؼ�
	void clearControlData();
public:
	//֧�ֿ���Ϣ
	std::vector<eSymbol_ELibInfo> vec_ELibInfo;
	//���ĺ���
	eSymbol_KrnlCall krnlCall;
	eSymbol_KrnlJmp krnlJmp;
	//�û���ʼ��ַ
	unsigned int userCodeStartAddr;
	//�û�������ַ,Ŀǰ��ʱ��û��ʲô�ð취��ȡ�����ַ,����кõ��뷨��ӭ��issue
	unsigned int userCodeEndAddr;

	//�����,key������,value�ǵ�����Ϣ
	std::vector<eSymbol_ImportsApi> importsApiList;
	//��ʱ�����
	std::vector<std::string> tmpImportsApiList;

	//�洢���еĿؼ���Ϣ
	std::vector<EAppControl*> allControlList;
private:

	//��Ǻ�������
	std::map<unsigned int,eSymbolFuncType> eSymbolFuncTypeMap;
	//�洢���еĿؼ���Ϣ,���ݺ�allControlListһ��
	std::map<eSymbol_ControlIndex, EAppControl*> allControlMap;
};