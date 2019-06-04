#pragma once
#include <Windows.h>
#include "TBaseClass.h"
#include "TRandom.h"
#include "../ValkyraEngine/DataStructure/TArray.h"
typedef void*(*getRadomGeneFunction)();
typedef float(*FitnessFunction)(int);
class TDNA:public TBaseClass
{
private:
	float m_fMutationRate;
public:
	float m_fFitness;
	TArray* _genes;
	TRandom* m_Rnd;
	getRadomGeneFunction _fpGetRandomGene;
	FitnessFunction _fpFitnessFunction;
	TDNA(int iSize, TRandom* rnd, getRadomGeneFunction fpRndGene, FitnessFunction fpFitnessFnc, bool shouldInitGenes);
	TDNA* TDNA::Crossover(TDNA* otherParent);
	float TDNA::CalculateFitness(int index);
	void TDNA::Mutate(float MutationRate);
	~TDNA();

};

