#ifndef FLIGHTGEARINTERPRETER_VARCOMMAND_H
#define FLIGHTGEARINTERPRETER_VARCOMMAND_H

#include <string>
#include "Command.h"
#include "Expression.h"
#include "SymbolsTable.h"

class VarCommand: public Command{

    std::string name;

public:

    VarCommand(std::string name, std::string bindToSymbol) {
        this->name = name;
        SymbolsTable::getInstance()->bindNewSymbolToExistSymbol(name, bindToSymbol);
    }

    VarCommand(std::string name, Expression* value):name(name) {
        double val = value->calculate();
        SymbolsTable::getInstance()->setSymbol(name, val);
    }

    double execute() override {
        return SymbolsTable::getInstance()->getSymbolValue(name);
    }

};


#endif //FLIGHTGEARINTERPRETER_VARCOMMAND_H
