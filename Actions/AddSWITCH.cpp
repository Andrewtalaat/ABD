#include "AddSWITCH.h"
#include "..\ApplicationManager.h"

AddSWITCH::AddSWITCH(ApplicationManager* pApp) :Action(pApp)
{
}

AddSWITCH::~AddSWITCH(void)
{
}

void AddSWITCH::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("SWITCH component: Click to add the ITEM");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the SWITCH gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	SWITCH* pA = new SWITCH(pGInfo, SWITCH_FANOUT);
	pManager->AddComponent(pA);
}

void AddSWITCH::Undo()
{}

void AddSWITCH::Redo()
{}

