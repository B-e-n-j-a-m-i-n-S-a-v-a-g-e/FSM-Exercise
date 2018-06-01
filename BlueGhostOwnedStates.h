#pragma once
//#ifndef BLUE_GHOST_OWNED_STATES_H
//#define BLUE_GHOST_OWNED_STATES_H

#include "State.h"

class BlueGhost;

class BlueGhostGlobalState : public State<BlueGhost>
{
private:

	BlueGhostGlobalState() {}
	BlueGhostGlobalState(const BlueGhostGlobalState&);
	BlueGhostGlobalState& operator=(const BlueGhostGlobalState&);

public:

	static BlueGhostGlobalState* Instance();

	virtual void Enter(BlueGhost* blueGhost) {}
	virtual void Execute(BlueGhost* blueGhost) {}
	virtual void Exit(BlueGhost* blueGhost) {}
};

class ScareCastleInhabitants : public State<BlueGhost>
{

private:
	ScareCastleInhabitants() {}
	ScareCastleInhabitants(const ScareCastleInhabitants&);
	ScareCastleInhabitants& operator=(const ScareCastleInhabitants&);

public:
	static ScareCastleInhabitants* Instance();

	virtual void Enter(BlueGhost* blueGhost) {}
	virtual void Execute(BlueGhost* blueGhost) {}
	virtual void Exit(BlueGhost* blueGhost) {}
};


class RechargeSpritualEnergy : public State<BlueGhost>
{
private:

	RechargeSpritualEnergy() {}

	RechargeSpritualEnergy(const RechargeSpritualEnergy&);
	RechargeSpritualEnergy& operator=(const RechargeSpritualEnergy&);

public:

	static RechargeSpritualEnergy* Instance();

	virtual void Enter(BlueGhost* blueGhost);
	virtual void Execute(BlueGhost* blueGhost);
	virtual void Exit(BlueGhost* blueGhost);
};


//#endif