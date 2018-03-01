#include "TDNA.h"

TDNA::TDNA(int iSize, TRandom* rnd, getRadomGeneFunction fpRndGene, FitnessFunction fpFitnessFnc, bool shouldInitGenes)
{
	m_szClassName = "TDNA";
	_genes = new TArray(iSize);
	m_fFitness = 0.0f;
	_fpGetRandomGene = fpRndGene;
	_fpFitnessFunction = fpFitnessFnc;
	m_Rnd = rnd;
	if (shouldInitGenes)
	{
		for (int i = 0; i < _genes->Lenght(); i++)
		{
			_genes->Add(_fpGetRandomGene());
		}
	}
};

float TDNA::CalculateFitness(int index)
{
	m_fFitness = _fpFitnessFunction(index);
	return m_fFitness;
};
void TDNA::Mutate(float MutationRate)
{
	for (int i = 0; i < _genes->Count(); i++)
	{
		if (m_Rnd->NextFloat() < MutationRate)
		{
			//_genes->RemoveAt(i);
			//_genes-> = _fpGetRandomGene();
			_genes->AddItemAt(_fpGetRandomGene(), i);
		}
	}
};
TDNA::~TDNA()
{

};

TDNA* TDNA::Crossover(TDNA* otherParent)
{
	TDNA* child = new TDNA(_genes->Count(), m_Rnd, _fpGetRandomGene, _fpFitnessFunction, false);
	for (int i = 0; i < _genes->Count(); i++)
	{
		if (otherParent)
		{
			if (m_Rnd->NextFloat() > 0.5f)
				child->_genes->Add(otherParent->_genes->GetItemAtIndex(i));
			else
				child->_genes->Add(_genes->GetItemAtIndex(i));
		}
	}
	return child;
};

