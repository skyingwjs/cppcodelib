#include <string>
#include "UnitedNations.h"
#include "Country.h"

void UnitedNationsSecurityCouncil::SetColleague1(Country* c){
	this->colleague1=c;
}

void UnitedNationsSecurityCouncil::SetColleague2(Country* c){
	this->colleague2=c;
}

/************************************************************************
�н���UnitedNationsSecurityCouncil�е�����Country��colleague1��colleague2����
һ��������ϢDecalre����һ��������ϢGetMessage
************************************************************************/
void UnitedNationsSecurityCouncil::Declare(string message,Country* colleague){
	if(colleague==this->colleague1)
		colleague2->GetMessage(message);  
	else  
		colleague1->GetMessage(message);
}