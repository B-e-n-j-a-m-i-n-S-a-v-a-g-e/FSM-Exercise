#pragma once

#ifndef BLUE_GHOST_H
#define BLUE_GHOST_H

#include <string>

#include "State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "BlueGhostOwnedStates.h"
#include "ConsoleUtils.h"
#include "StateMachine.h"
#include "Utils.h"


class BlueGhost : public BaseGameEntity
{
private:
	StateMachine<BlueGhost>* m_pStateMachine;

	location_type m_location;

public:
	BlueGhost(int id) : BaseGameEntity(id), m_location(hauntedCastle)
	{
		m_pStateMachine = new StateMachine<BlueGhost>(this);
		m_pStateMachine->SetCurrentState(ScareCastleInhabitants::Instance());
		m_pStateMachine->SetGlobalState(BlueGhostGlobalState::Instance());
	}

	~BlueGhost() { delete m_pStateMachine; }

	void Update();

	StateMachine<BlueGhost>* GetFSM()const { return m_pStateMachine; }

	location_type Location()const { return m_location; }
	void ChangeLocation(const location_type loc) { m_location = loc; }
};

#endif