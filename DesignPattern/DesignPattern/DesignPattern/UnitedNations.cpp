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
中介者UnitedNationsSecurityCouncil中的两个Country（colleague1和colleague2），
一个发送消息Decalre，另一个接收消息GetMessage
************************************************************************/
void UnitedNationsSecurityCouncil::Declare(string message,Country* colleague){
	if(colleague==this->colleague1)
		colleague2->GetMessage(message);  
	else  
		colleague1->GetMessage(message);
}