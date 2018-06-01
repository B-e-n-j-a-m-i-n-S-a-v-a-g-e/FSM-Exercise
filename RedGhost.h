#pragma once

#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "RedGhostOwnedStates.h"
#include "StateMachine.h"


const int ScarePoints	= 5;
const int MaxScarePoints = 3;
const int ScareRequirementLevel = 5;
const int FatigueThreshold = 5;

class RedGhost: public BaseGameEntity
{
private:
	StateMachine<RedGhost>* m_pStateMachine;
	location_type	m_location;

	int m_scarePoints;
	int m_mana;
	int m_scareRequirements;
	int m_fatigue;

public:
	RedGhost(int id) : BaseGameEntity(id),
		m_location(hauntedCastle),
		m_scarePoints(0),
		m_mana(0),
		m_scareRequirements(0),
		m_fatigue(0)
	{
		m_pStateMachine = new StateMachine<RedGhost>(this);

		m_pStateMachine->SetCurrentState(ReturnToHauntedCastle::Instance());
	}

	~RedGhost() { delete m_pStateMachine; }

	void Update();

	StateMachine<RedGhost>* GetFSM() const { return m_pStateMachine; }

	location_type Location() const { return m_location; }
	void ChangeLocation(const location_type loc) { m_location = loc; }

	int ScarePoints() const { return m_scarePoints; }
	void SetScarePoints(const int val) { m_scarePoints = val; }
	void IncreaseScarePoints(const int val);
	bool MaxScarePointsReached() const { return m_scarePoints >= MaxScarePoints; }

	bool Fatigued() const;
	void IncreaseFatigue() { m_fatigue++; }
	void DecreaseFatigue() { m_fatigue--; }

	int Mana() const { return m_mana; }
	void SetMana(const int val) { m_mana = val; }
	void IncreaseMana(const int val);

	bool ScareRequirements()const;
	void DevourHumanSoul() { m_scareRequirements = 0; m_mana -= 2; }
};