#pragma once
#include "TBaseClass.h"
#include "TDNA.h"
#include "TArray.h"
typedef void*(*getRadomGeneFunction)();
typedef float(*FitnessFunction)(int);
class TGeneticAlgorithm: public TBaseClass
{
private:
	float m_fFitnessSum;
	TArray* m_oNewPopulation;
	void CalculateFitness();
	TDNA* ChooseParent();
protected:
	int m_iGeneration;
	float m_fFitnesss;
	float m_fMutationRate;
	TRandom* m_Rnd;
	getRadomGeneFunction _fpGetRandomGene;
	FitnessFunction _fpFitnessFunction;
public:
	TArray* m_oBestGenes;
	TArray* m_oPopulation;
	int GetGeneration() { return m_iGeneration; }
	float GetFitness() { return m_fFitnesss; }
	void NewGeneration();
	TGeneticAlgorithm(int iPopulationSize, int iDnaSize, TRandom* rnd, getRadomGeneFunction fpGetRandomGeneFunc, FitnessFunction fpFitnessFunc, float fMutationRate);
	~TGeneticAlgorithm();
};

