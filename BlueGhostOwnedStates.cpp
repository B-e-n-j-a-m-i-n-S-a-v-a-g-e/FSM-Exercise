#include "stdafx.h"

#ifndef BLUE_GHOST_OWNED_STATES_H
#define BLUE_GHOST_OWNED_STATES_H


#include "BlueGhostOwnedStates.h"
#include "BlueGhost.h"
#include "Locations.h"
#include "EntityNames.h"
#include <iostream>
#include <cstdio>
#include <iostream>

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

BlueGhostGlobalState* BlueGhostGlobalState::Instance()
{

	static BlueGhostGlobalState instance;

	return &instance;
}

void BlueGhostGlobalState::Execute(BlueGhost* blueGhost)
{

	if (RandFloat() < 0.1)
	{

		blueGhost->GetFSM()->ChangeState(RechargeSpritualEnergy::Instance());
	}
}

ScareCastleInhabitants* ScareCastleInhabitants::Instance()
{
	static ScareCastleInhabitants instance;

	return &instance;
}

void ScareCastleInhabitants::Enter(BlueGhost* blueGhost)
{
}

void ScareCastleInhabitants::Execute(BlueGhost* blueGhost)
{
	switch (RandInt(0, 2))
	{
	case 0:
		std::cout << "\n" << GetEntityName(blueGhost->ID()) << "Moppin' the floor";
		break;
	case 1:
		std::cout << "\n" << GetEntityName(blueGhost->ID()) << "Washin' the dishes";
		break;
	case 2:
		std::cout << "\n" << GetEntityName(blueGhost->ID()) << "Makin' the bed";
		break;

	}
}

void ScareCastleInhabitants::Exit(BlueGhost* blueGhost)
{
}

RechargeSpritualEnergy* RechargeSpritualEnergy::Instance()
{
	static RechargeSpritualEnergy instance;

	return &instance;
}

void RechargeSpritualEnergy::Enter(BlueGhost* blueGhost)
{

	std::cout << "\n" << GetEntityName(blueGhost->ID()) << ": Preparing to Charge Spiritual Energy";
 }

void RechargeSpritualEnergy::Execute(BlueGhost* blueGhost)
{

	std::cout << "\n" << GetEntityName(blueGhost->ID()) << ": Recharging Spiritual Energy!";

	blueGhost->GetFSM()->RevertToPreviousState();
}

void RechargeSpritualEnergy::Exit(BlueGhost* blueGhost)
{

	std::cout << "\n" << GetEntityName(blueGhost->ID()) << ": Spritual Energy Recharging Complete";
}
#endif