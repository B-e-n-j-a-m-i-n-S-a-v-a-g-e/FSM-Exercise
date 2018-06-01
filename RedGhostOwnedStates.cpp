#include "stdafx.h"
#include "RedGhostOwnedStates.h"
#include "State.h"
#include "RedGhost.h"
#include "Locations.h"
#include "EntityNames.h"
#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

EnterCreepyForest* EnterCreepyForest::Instance()
{

	static EnterCreepyForest instance;
	return &instance;
}

void EnterCreepyForest::Enter(RedGhost* pRedGhost)
{

	if (pRedGhost->Location() != creepyForest)
	{
		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Now entering the creepy forest";

		pRedGhost->ChangeLocation(creepyForest);
	}

}

void EnterCreepyForest::Execute(RedGhost* pRedGhost)
{

	pRedGhost->IncreaseScarePoints(1);
	pRedGhost->IncreaseFatigue();

	cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Scare Points Have Increased";

	if (pRedGhost->MaxScarePointsReached())
	{

		pRedGhost->GetFSM()->ChangeState(EnterCreepyForest::Instance());
	}
	if (pRedGhost->ScareRequirements())
	{
		pRedGhost->GetFSM()->ChangeState(EnterMysteriousMountain::Instance());
		
	}
}
	
	void EnterCreepyForest::Exit(RedGhost* pRedGhost)
	{

		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": "
			<< "Leaving Creepy Forest with Increased Scare Points";
	}
	

	EnterSpookySwamp* EnterSpookySwamp::Instance()
	{

		static EnterSpookySwamp instance;

		return &instance;
	}

	void EnterSpookySwamp::Enter(RedGhost* pRedGhost)
	{

		if (pRedGhost->Location() != spookySwamp)
		{

			cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Entering the spooky swamp.";

			pRedGhost->ChangeLocation(spookySwamp);
		}
	}

	void EnterSpookySwamp::Execute(RedGhost* pRedGhost)
	{

		pRedGhost->IncreaseMana(pRedGhost->ScarePoints());

		pRedGhost->SetScarePoints(0);

		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": "
			<< "Converting Scare Points to Mana. Mana has increased to: " << pRedGhost->Mana();

		if (pRedGhost->Mana() >= ScarePoints)
		{

			cout << "\n" << GetEntityName(pRedGhost->ID()) << ": "
				<< "Mana has been sufficiently increased. Returning to Haunted Castle";

			pRedGhost->GetFSM()->ChangeState(ReturnToHauntedCastle::Instance());
		}

		else {

			pRedGhost->GetFSM()->ChangeState(EnterCreepyForest::Instance());
		}
	}

	void EnterSpookySwamp::Exit(RedGhost* pRedGhost)
	{

		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Leaving the Spooky Swamp";
	}

	ReturnToHauntedCastle* ReturnToHauntedCastle::Instance()
	{

		static ReturnToHauntedCastle instance;

		return &instance;
	}

	void ReturnToHauntedCastle::Enter(RedGhost* pRedGhost)
	{
		if (pRedGhost->Location() != hauntedCastle)
		{
			cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Returning to Haunted Castle";

			pRedGhost->ChangeLocation(hauntedCastle);
		}
	}

	void ReturnToHauntedCastle::Execute(RedGhost* pRedGhost)
	{
		if (!pRedGhost->Fatigued())
		{
			cout << "\n" << GetEntityName(pRedGhost->ID()) << ": "
				<< "Energy Levels Replenished. Returning to Spooky Swamp";

			pRedGhost->GetFSM()->ChangeState(EnterSpookySwamp::Instance());
		}

		else 
		{
			pRedGhost->DecreaseFatigue();

			cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Resting and Replenishing energy";
		}
	}

	void ReturnToHauntedCastle::Exit(RedGhost* pRedGhost)
	{
		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Now Departing Haunted Castle";
	}

	EnterMysteriousMountain*  EnterMysteriousMountain::Instance()
	{

		static EnterMysteriousMountain instance;

		return &instance;
	}

	void EnterMysteriousMountain::Enter(RedGhost* pRedGhost)
	{
		if (pRedGhost->Location() != mysteriousMountain)
		{
			pRedGhost->ChangeLocation(mysteriousMountain);

			cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Visiting Mysterious Mountain";
		}
	}

	void EnterMysteriousMountain::Execute(RedGhost* pRedGhost)
	{
	if (pRedGhost->ScareRequirements()) {
		
		pRedGhost->DevourHumanSoul();

		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Human Soul Devoured";

		pRedGhost->GetFSM()->ChangeState(EnterCreepyForest::Instance());
	}
}

	void EnterMysteriousMountain::Exit(RedGhost* pRedGhost)
	{
		cout << "\n" << GetEntityName(pRedGhost->ID()) << ": " << "Departing from Mysterious Mountain";
	}