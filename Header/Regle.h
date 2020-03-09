#pragma once
#include <vector>
#include <stdlib.h>

class Regle {

private: 
	std::vector<int> mRegleBorn;
	std::vector<int> mRegleSurvive;

public:

	Regle(std::string regleEntree);
	Regle(std::vector<int> regleBorn, std::vector<int> regleSurvive);

	~Regle() = default;

	std::string regleBorn() const;
	std::string regleSurvive() const;
	static bool confirmRegle(std::string mRegleEntree);
	static std::vector<int> genRegleBorn(std::string mRegleEntree);
	static std::vector<int> genRegleSurvive(std::string mRegleEntree);
};