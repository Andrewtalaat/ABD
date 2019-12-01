#include "EXIT.h"
#include "..\ApplicationManager.h"

EXIT::EXIT(ApplicationManager* pApp) :Action(pApp)
{
}

EXIT::~EXIT(void)
{
}

void EXIT::Execute()
{
	for (int i = 0; i < pManager->CompCount; i++) {
		delete pManager->CompList[i];
		pManager->CompList[i] = NULL;
}

}
void EXIT::Undo()
{}

void EXIT::Redo()
{}


