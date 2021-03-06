/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CONSOLE_PRINTER_
#define CONSOLE_PRINTER_

#include "Graphic.h"
#include "Checker.h"
#include "Matrix.h"

class ConsolePrinter :
	public Graphic
{
public:
	ConsolePrinter();
	virtual ~ConsolePrinter();
	//print who turn is that
	virtual void PrintTurnOf(Checker player) const;
	//print board
	virtual void PrintBoard(const Matrix<Checker>& board, int size) const;
	//print available in board
	virtual void PrintAvilable(const Matrix<Checker>& board, int size, Checker avilable_to_print) const;
	//print recived messgae
	virtual void PrintMessage(std::string s) const;
	//print winner messgae
	virtual void PrintWinnerMessage(Checker winner);
	//ask for data from user
	virtual std::string GetDataFromUser();
private:
	//get letter from checker
	char ReturnLetterToPrint(Checker checker) const;
};
#endif