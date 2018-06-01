#include "stdafx.h"
#include "BlueGhost.h"


void BlueGhost::Update()
{

	SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}