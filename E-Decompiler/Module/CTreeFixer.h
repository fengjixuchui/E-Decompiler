#pragma once

//�޸������Է�������

class ESymbol;
class CTreeFixer
{
public:
	CTreeFixer(ESymbol& symbol);
	~CTreeFixer();
	void Install();
	void UnInstall();
private:
	ESymbol& eSymbol;
};