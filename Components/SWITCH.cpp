#include "SWITCH.h"

SWITCH::SWITCH(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
}


void SWITCH::Operate()
{
	if (state ==HIGH ) {
		m_OutputPin.setStatus(HIGH);
	}
	else m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws SWITCH ITEM
void SWITCH::Draw(UI* pUI)
{
	//Call output class AND pass gate drawing info to it.
	pUI->DrawSWITCH(*m_pGfxInfo);
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}
