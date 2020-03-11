#include "../Header/OptionManager.h"
#include "../Header/Regle.h"



OptionManager::OptionManager(int argc, char * argv[])
	:mArgc{argc}, mArgv{argv}
{

}

bool OptionManager::evaluationOption()
{
	bool valid = true;
	
	if (mArgc > 2) {
		for (int i{ 1 }; i < mArgc; ++i) {
			char *arg = mArgv[i];
			if (arg == "-r") {
				if (i + 1 < mArgc) {
					mRegle = mArgv[i++];
					mRegleValide = Regle::confirmRegle(mRegle);
				}
				else valid = false;
			}
		}
	}
	else valid = false;

	return valid;
}
