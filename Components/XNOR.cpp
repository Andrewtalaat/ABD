#include "XNOR.h"

XNOR::XNOR(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void XNOR::Operate()
{
	if (m_InputPins[0].getStatus() == m_InputPins[1].getStatus() ) {
		m_OutputPin.setStatus(HIGH);
	}
	else m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input XNOR gate
void XNOR::Draw(UI* pUI)
{
	//Call output class XNOR pass gate drawing info to it.
	pUI->DrawXNOR(*m_pGfxInfo);
}

//returns status of outputpin
int XNOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
