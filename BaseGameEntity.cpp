#include "stdafx.h"
#include "BaseGameEntity.h"


int BaseGameEntity::m_nextValidID = 0;

void BaseGameEntity::SetID(int val)
{
	m_ID = val;
	m_nextValidID = m_ID + 1;
}
