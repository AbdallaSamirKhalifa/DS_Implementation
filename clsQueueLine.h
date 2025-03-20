#pragma once
#include"iostream"
#include"queue"
#include"stack"
#include"clsDate.h"
using namespace std;
class clsQueueLine
{
	class clsTicket {
		string _TicketTime;
		string _Prefix;
		short _Number = 0;
		short _ExepectedServeTime= 0;
		short _AVGServeTime = 0;
		short _WaitingClients = 0;
	public:
		clsTicket(string Prefix,short Number,short WaitingClients,short AvgServeTime){
			_TicketTime = clsDate::GetSystemDateTimeString();
			_Prefix = Prefix;
			_Number = Number;
			_WaitingClients = WaitingClients;
			_AVGServeTime = AvgServeTime;
		}

		string FullNumber() {
			return (_Prefix + to_string(_Number));
		}

		short ExpectedServeTime() {
			return _AVGServeTime * _WaitingClients;
		}

		string TicketTime() {
			return _TicketTime;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";


		}
	};
	string _Prefix;
	short _AVGServeTime=0;
	short _TotalTickets= 0;

public:
	queue<clsTicket>QueueLine;
	clsQueueLine(string Prefix, short AvgServeTime) {
		_Prefix = Prefix;
		_AVGServeTime = AvgServeTime;
		_TotalTickets = 0;
	}

	void IssueTicket() {
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AVGServeTime);
		QueueLine.push(Ticket);
	}

	short WaitingClients() {
		return QueueLine.size();
	}

	string WhoIsNext() {
		if (QueueLine.empty()) {
			return "No Clients Left.";
		}
		else
			return QueueLine.front().FullNumber();
	}

	bool ServeNextClient() {
		if (QueueLine.empty()) 
			return false;
		

		QueueLine.pop();
		return true;
	}

	short ServedClients() {
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";

	}

	void PrintTicketsLineLTR() {
		
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <clsTicket>TempQueue = QueueLine;

		while (!TempQueue.empty()) {
			cout << TempQueue.front().FullNumber() << " <-- ";
			TempQueue.pop();
		}
	}

	void PrintTicketsLineRTL() {
		
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <clsTicket>TempQueue = QueueLine;
		stack<clsTicket>TempStack;

		while (!TempQueue.empty()) {
			TempStack.push(TempQueue.front());
			TempQueue.pop();
		}

		while (!TempStack.empty()) {
			cout << " "<<TempStack.top().FullNumber()<<" --> ";
			TempStack.pop();

		}
	}
	
	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}

	}

};
//	class clsTicket{
//	public:
//	string _DateTime="";
//	string ClientNumber="";
//	int TimeInLine=0;
//	int WaitingClients=0;
//
//    };
//
//	string _Prefix;
//	int _ServedClients;
//	int _TimeInLine=0;
//	int _TimeToWait;
//	int _Clients;
//	
//	queue<clsTicket>Line;
//
//	clsTicket PrepareCLients() {
//		clsTicket c;
//		c.ClientNumber = _Prefix + to_string(_Clients+1);
//		c._DateTime = clsDate::GetSystemDateTimeString();
//		c.TimeInLine = _TimeInLine;
//		c.WaitingClients = _Clients;
//		return c;
//	}
//	
//public:
//	clsQueueLine(string preFix, int timeInLine) {
//		_Prefix = preFix;
//		_TimeToWait = timeInLine;
//	}
//
//	void IssueTicket() {
//		
//		Line.push(PrepareCLients());
//		_Clients++;
//		_TimeInLine += _TimeToWait;
//		
//	}
//	void PrintInfo() {
//		cout << "\t\t\t\t________________________________\n\n";
//
//		cout << "\t\t\t\t\tQueue Info\n\n";
//		cout << "\t\t\t\t________________________________\n\n";
//		cout << "\n\t\t\t\t    Prefix       = " << _Prefix;
//		cout << "\n\t\t\t\t    Total Tickets    = " << _Clients;
//		cout << "\n\t\t\t\t    Served Clients   = " << _ServedClients;
//		cout << "\n\t\t\t\t    Waiting Clients  = " << Line.size();
//		cout << "\n\t\t\t\t________________________________\n\n";
//
//	}
//
//	void PrintTicketsLineRTL() {
//		cout << "\n\nTickets:  ";
//		for (int Counter = 1; Counter <=_Clients; Counter++) {
//			cout << _Prefix << Counter << " <-- ";
//		}
//
//	}
//
//	void PrintTicketsLineLTR() {
//		cout << "\n\nTickets:  ";
//		for (int Counter = _Clients; Counter >=1; Counter--) {
//			cout << _Prefix << Counter << " --> ";
//		}
//
//	}
//	void PrintTicket(clsTicket C) {
//		cout << "\n\n__________________\n\n";
//		cout << "        " << C.ClientNumber<<endl;
//		cout << C._DateTime << endl;
//		cout << "Waiting Clients = " <<C.WaitingClients << endl;
//		cout << "  Serve Time In\n  ";
//		cout << C.TimeInLine << " Minuts\n";
//		cout << "__________________\n\n";
//	}
//	void PrintAllTickets() {
//		cout << "\n\n---Tickets---\n\n";
//		queue<clsTicket>temp = Line;
//
//		while(!temp.empty())
//		{
//			PrintTicket(temp.front());
//			temp.pop();
//		}
//		
//	}
//
//	void ServeNextClient() {
//		Line.pop();
//
//		_ServedClients++;
//		_TimeInLine -= _TimeToWait;
//	}
