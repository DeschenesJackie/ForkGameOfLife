#include "..\Header\Facade.h"

Facade::Facade(std::vector<Cellule>& vecteur, std::vector<Cellule>::iterator iterateurPosition, Regle regle, bool wrap)
	:mVecteur{vecteur}, mRegle{regle}, mIterateur{iterateurPosition}, mWrap{wrap}
{

}

bool Facade::applyRegle()
{

	return false;
}

