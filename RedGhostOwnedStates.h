#pragma once

#include "State.h"

class RedGhost;

class EnterCreepyForest : public State<RedGhost>
{
private:
	EnterCreepyForest() {}

	EnterCreepyForest(const EnterCreepyForest&);
	EnterCreepyForest& operator=(const EnterCreepyForest);

public:

	static EnterCreepyForest* Instance();

public:

	virtual void Enter(RedGhost* redGhost);
	virtual void Execute(RedGhost* redGhost);
	virtual void Exit(RedGhost* redGhost);


};


class EnterSpookySwamp : public State<RedGhost>
{
private:

	EnterSpookySwamp() {}


	EnterSpookySwamp(const EnterSpookySwamp&);
	EnterSpookySwamp& operator=(const EnterSpookySwamp&);

public:

	static EnterSpookySwamp* Instance();

	virtual void Enter(RedGhost* redGhost);
	virtual void Execute(RedGhost* redGhost);
	virtual void Exit(RedGhost* redGhost);

};

class ReturnToHauntedCastle : public State<RedGhost>
{
private:

	ReturnToHauntedCastle() {}


	ReturnToHauntedCastle(const  ReturnToHauntedCastle&);
	ReturnToHauntedCastle& operator=(const  ReturnToHauntedCastle&);

public:

	static  ReturnToHauntedCastle* Instance();

	virtual void Enter(RedGhost* redGhost);
	virtual void Execute(RedGhost* redGhost);
	virtual void Exit(RedGhost* redGhost);

};

class EnterMysteriousMountain: public State<RedGhost>
{
private:

	EnterMysteriousMountain() {}


	EnterMysteriousMountain(const  EnterMysteriousMountain&);
	EnterMysteriousMountain& operator=(const  EnterMysteriousMountain&);

public:

	static  EnterMysteriousMountain* Instance();

	virtual void Enter(RedGhost* redGhost);
	virtual void Execute(RedGhost* redGhost);
	virtual void Exit(RedGhost* redGhost);

};