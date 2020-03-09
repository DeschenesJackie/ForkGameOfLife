#include "..\Header\Facade.h"

Facade::Facade(std::vector<Cellule>::iterator iterateurPosition, Regle regle, bool wrap)
	:mRegle{regle}, mIterateur{iterateurPosition}, mWrap{wrap}
{

}

bool Facade::applyRegle()
{

	return false;
}

