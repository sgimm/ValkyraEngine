#include "TGeneticAlgorithm.h"

TGeneticAlgorithm::TGeneticAlgorithm(int iPopulationSize, int iDnaSize, TRandom * rnd, getRadomGeneFunction fpGetRandomGeneFunc, FitnessFunction fpFitnessFunc, float fMutationRate)
{
	m_szClassName = "TGeneticAlgorithm";
	m_iGeneration = 1;
	m_fFitnessSum = 0.0f;
	m_fMutationRate = fMutationRate;
	m_Rnd = rnd;
	m_oPopulation = new TArray(iPopulationSize);
	m_oNewPopulation = new TArray(iPopulationSize);
	m_oBestGenes = new TArray(iDnaSize);
	_fpFitnessFunction = fpFitnessFunc;
	_fpGetRandomGene = fpGetRandomGeneFunc;

	for (int c = 0; c < iPopulationSize; c++)
	{
		TDNA* __t = new TDNA(iDnaSize, rnd, fpGetRandomGeneFunc, fpFitnessFunc, true);
		m_oPopulation->Add(__t);
	}
};

void TGeneticAlgorithm::NewGeneration()
{
	if (m_oPopulation->Count() <= 0)
		return;
	m_oNewPopulation->Destroy();
	m_oNewPopulation = new TArray(m_oPopulation->Count());
	CalculateFitness();
	for (int c = 0; c < m_oPopulation->Count(); c++)
	{
		TDNA* __parent1 = ChooseParent();
		TDNA* __parent2 = ChooseParent();
		TDNA* __child = nullptr;

		if(__parent1)
		{
			__child = __parent1->Crossover(__parent2);
		}
		else
		{
			__child = (TDNA*)m_oPopulation->GetItemAtIndex(c);
		}

		__child->Mutate(m_fMutationRate);
		m_oNewPopulation->Add(__child);
	}
	/*
	            List<DNA<T>> tmpList = Population;
            Population = newPopulation;
            newPopulation = tmpList;
	*/
	TArray* _t = m_oPopulation;
	m_oPopulation = m_oNewPopulation;
	m_oNewPopulation = _t;
	m_iGeneration++;
};

TGeneticAlgorithm::~TGeneticAlgorithm()
{
};

void TGeneticAlgorithm::CalculateFitness()
{
	m_fFitnessSum = 0.0f;
	TDNA* best = (TDNA*)m_oPopulation->GetItemAtIndex(0);
	for (int c = 0; c < m_oPopulation->Count(); c++)
	{
		m_fFitnessSum += ((TDNA*)m_oPopulation->GetItemAtIndex(c))->CalculateFitness(c);
		if (((TDNA*)m_oPopulation->GetItemAtIndex(c))->m_fFitness > best->m_fFitness)
		{
			best = (TDNA*)m_oPopulation->GetItemAtIndex(c);
		}
	}
	m_oBestGenes = new TArray(best->_genes->Count());
	m_fFitnesss = best->m_fFitness;
	//BestFitness = best.Fitness;
	for (int i = 0; i < best->_genes->Lenght(); i++)
	{
		m_oBestGenes->Add(best->_genes->GetItemAtIndex(i));
	}
};

TDNA* TGeneticAlgorithm::ChooseParent()
{
	float __randomNumber = m_Rnd->NextFloat()*m_fFitnessSum;
	for (int c = 0; c < m_oPopulation->Count(); c++)
	{
		if (__randomNumber < ((TDNA*)m_oPopulation->GetItemAtIndex(c))->m_fFitness)
		{
			return (TDNA*)m_oPopulation->GetItemAtIndex(c);
		}
		__randomNumber -= ((TDNA*)m_oPopulation->GetItemAtIndex(c))->m_fFitness;
	}
	return nullptr;
};