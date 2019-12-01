#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddNORgate.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddSWITCH.h"
#include "Actions\AddLED.h"
#include "Actions\EXIT.h"



ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_OR2_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_INV:
			pAct = new AddNOTgate(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_Switch:
			pAct = new AddSWITCH(this);
			break;
		case EXIT_THIS:
			pAct = new EXIT(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}