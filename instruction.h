#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>
#include <vector>
#include <map>
#include "symboltable.h"

class instruction{
	public:
        instruction(std::string lab,std::string op, std::string sta){
			opCode = op;
			label = lab;
			statement = sta;
			format4Check();
			markCheck();
			//assignSYMTAB();
		}
		instruction(std::string op, std::string sta) {
			opCode = op;
			statement = sta;
			format4Check();
			markCheck();
		}
	    instruction(std::string op){
            opCode = op;
	    }

		std::string label="";
		std::string opCode;
		char n='1',i='1',x='0',b='0',p='1',e='0';
		std::string statement = "";
		std::string address;//for format4, 4byte
		std::string loc;
		std::string objectCode;
		std::string r1 = "", r2 = "";
		int litlength = 0;
		int format = 3;//3byte
		void bpchange();
        void assignSYMTAB(std::map<std::string, SYMTAB> &symtab) {
                    SYMTAB sym = {"","",""};
                    sym.symbol = label;
                    //format4Check();
                    //markCheck();
                    sym.statement = statement;
                    symtab.insert(std::pair<std::string,SYMTAB>(label, sym));
                };


    protected:
        void format4Check();
		void markCheck();

	private:


};

//clear (X=B410;A=B400;S=B440;) TIXR T=B850;
//table 都用map存
//C'EOF'=>引號內有3個字元
//X'F1'=>每兩個hex為1byte=1
#endif
