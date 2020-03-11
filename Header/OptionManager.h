#pragma once 
#ifndef _OptionManager_h_
#define _OptionManager_h_
#include <string>

class OptionManager {
public:
	OptionManager(int argc, char* argv[]);
	std::string mRegle;
	bool mRegleValide;
	bool evaluationOption();
private:
	int mArgc;
	char **mArgv;
};








#endif