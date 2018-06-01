#include "stdafx.h"
#include "RedGhost.h"
#include "ConsoleUtils.h"


void RedGhost::Update()
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	m_scareRequirements += 1;

	m_pStateMachine->Update();
}

void RedGhost::IncreaseScarePoints(const int val)
{
	m_scarePoints += val;

	if (m_scarePoints < 0) m_scarePoints = 0;
}

void RedGhost::IncreaseMana(const int val)
{
	m_mana += val;
	if (m_mana < 0) m_mana = 0;
}

bool RedGhost::ScareRequirements() const
{
	if (m_scareRequirements >= ScareRequirementLevel) { return true; }

	return false;

}

bool RedGhost::Fatigued() const
{
	if (m_fatigue > FatigueThreshold)
	{
		return true;
	}

	return false;
}



