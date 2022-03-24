#include "BC_Functions.cpp"

void menuOptions() {

	bool quitOrNaw = true;
	int choiceInput = -1, intInput = -1, decimalValue = -1,
		comparedValueA = -1, comparedValueB = -1, resultantValueC = -1, resultantDecimal = -1, decimalA = -1, decimalB = -1;
	std::string stringInput = "", binaryValue = "", FirstArithmeticValue = "", SecArithmeticValue = "";
	// TODO: Ask the user or Check if both inputs for the arthmetic are the same type (Decimal, Binary, or Hexa)

	do {

		choiceInput = -1;

		std::cout << " Select an Option from the choices below:\n"
			<< "   1) Conversion from Decimal --> Binary --> Hexa\n"
			<< "   2) Conversion from Hexa --> Binary & Decimal\n"
			<< "   3) Conversion from Binary --> Hexa & Decimal\n"
			<< "   4) Addition\n"
			<< "   5) Subtraction\n"
			<< "   6) Multiplication\n"
			<< "   7) Division\n"
			<< "   8) OR Operation\n"
			<< "   9) AND Operation\n"
			<< "   10) XOR Operation\n"
			<< "   11) NOR Operation\n"
			<< "   12) NAND Operation\n"
			<< "   0) Exit\n";
		std::cin >> choiceInput;
		std::cout << "\n\n";

		switch (choiceInput) {

		case 0:
			ignoreExtraInputs();
			quitOrNaw = false;
			break;
		case 1:
			ignoreExtraInputs();
			std::cout << " Enter a Decimal Value:\n";
			std::cin >> intInput;
			std::cout << "------------------------------------"
				<< '\n' << std::setw(20) << "Decimal: " << intInput << '\n';
			// Decimal --> Binary --> Hexa function
			binaryValue = decimalToBinary(intInput);
			std::cout << '\n' << std::setw(20) << "Binary: " << nibbleSpaceAparter(nibbleGuaranteeer(binaryValue)) << '\n';
			std::cout << '\n' << std::setw(20) << "Hexdecimal: " << binaryToHexa(binaryValue) << '\n';
			std::cout << "\n------------------------------------\n\n\n";
			break;
		case 2:
			ignoreExtraInputs();
			std::cout << " Enter a Hexadecimal Value:\n";
			getline(std::cin, stringInput);
			boost::erase_all(stringInput, " ");
			boost::to_upper(stringInput);
			std::cout << "------------------------------------"
				<< '\n' << std::setw(20) << "Hexadecimal: " << stringInput << '\n';
			// Hexa --> Binary & Decimal function
			decimalValue = hexaToDecimal(stringInput);
			std::cout << '\n' << std::setw(20) << "Decimal: " << decimalValue << "\n";
			std::cout << '\n' << std::setw(20) << "Binary: " << nibbleSpaceAparter(nibbleGuaranteeer(decimalToBinary(decimalValue))) << '\n';
			std::cout << "------------------------------------\n\n\n";
			break;
		case 3:
			ignoreExtraInputs();
			std::cout << " Enter a Binary Value:\n";
			getline(std::cin, stringInput);
			boost::erase_all(stringInput, " ");
			std::cout << "------------------------------------"
				<< '\n' << std::setw(20) << "Binary: " << nibbleSpaceAparter(nibbleGuaranteeer(stringInput)) << '\n';
			// Binary --> Hexa & Decimal function
			std::cout << '\n' << std::setw(20) << "Hexadecimal: " << binaryToHexa(stringInput) << '\n';
			std::cout << '\n' << std::setw(20) << "Decimal: " << binaryToDecimal(stringInput);
			std::cout << "\n------------------------------------\n\n\n";
			break;
		case 4:
			ignoreExtraInputs();
			std::cout << " Enter 2 values - separated by a space - you would like to preform an 'ADD' Operation on:\n"
				<< " NOTE: Input binary values without any spaces in between!\n"
				<< "       Specify what base the number is in by adding an 'B' or an 'H' in front of the value (without quotes)\n"
				<< "       This only works with Binary & Hexa values!\n";
			std::cin >> FirstArithmeticValue >> SecArithmeticValue;
			boost::to_upper(FirstArithmeticValue);
			boost::to_upper(SecArithmeticValue);
			std::cout << "\n------------------------------------"
				<< '\n' << std::setw(20) << "Inputed Values: " << FirstArithmeticValue << " and " << SecArithmeticValue << '\n';

			if (FirstArithmeticValue.at(0) == 'B') {
				decimalA = binaryToDecimal(FirstArithmeticValue.substr(1, std::string::npos));
				if (SecArithmeticValue.at(0) == 'B') {
					decimalB = binaryToDecimal(SecArithmeticValue.substr(1, std::string::npos));
				}
				else {
					decimalB = hexaToDecimal(SecArithmeticValue.substr(1, std::string::npos));
				}
			}
			else if (FirstArithmeticValue.at(0) == 'H') {
				decimalA = hexaToDecimal(FirstArithmeticValue.substr(1, std::string::npos));
				if (SecArithmeticValue.at(0) == 'H') {
					decimalB = hexaToDecimal(SecArithmeticValue.substr(1, std::string::npos));
				}
				else {
					decimalB = binaryToDecimal(SecArithmeticValue.substr(1, std::string::npos));
				}
			}
			else {
				std::cout << "\nSomething went wrong in the 'Addition' Option\n";
			}
			resultantDecimal = decimalA + decimalB;
			std::cout << '\n' << std::setw(20) << "Decimal: " << resultantDecimal << '\n'
				<< '\n' << std::setw(20) << "Hexadecimal: " << binaryToHexa(decimalToBinary(resultantDecimal)) << '\n'
				<< '\n' << std::setw(20) << "Binary: " << nibbleSpaceAparter(nibbleGuaranteeer(decimalToBinary(resultantDecimal)));
			std::cout << "\n------------------------------------\n\n\n";
			break;
		case 5:
			ignoreExtraInputs();
			
			// Subtraction function
			break;
		case 6:
			ignoreExtraInputs();
			std::cout << " Multiplication Case Incomplete; Still needs to be finished\n\n\n";
			// Multiplication function
			break;
		case 7:
			ignoreExtraInputs();
			std::cout << " Division Case Incomplete; Still needs to be finished\n\n\n";
			// Division function
			break;
		case 8:
			ignoreExtraInputs();
			std::cout << " Enter 2 Decimal values - separated by a space - you would like to perfrom the 'OR' Operation on:\n";
			std::cin >> comparedValueA >> comparedValueB;
			resultantValueC = comparedValueA | comparedValueB;
			std::cout << "------------------------------------\n";
			std::cout << std::setw(10) << "'" << comparedValueA << "' OR '" << comparedValueB << "' =\n\n"
				<< std::setw(20) << resultantValueC << "\n------------------------------------\n\n\n";
			break;
		case 9:
			ignoreExtraInputs();
			std::cout << " Enter 2 Decimal values - separated by a space - you would like to perfrom the 'AND' Operation on:\n";
			std::cin >> comparedValueA >> comparedValueB;
			resultantValueC = comparedValueA & comparedValueB;
			std::cout << "------------------------------------\n";
			std::cout << std::setw(10) << "'" << comparedValueA << "' AND '" << comparedValueB << "' =\n\n"
				<< std::setw(20) << resultantValueC << "\n------------------------------------\n\n\n";
			break;
		case 10:
			ignoreExtraInputs();
			std::cout << " Enter 2 Decimal values - separated by a space - you would like to perfrom the 'XOR' Operation on:\n";
			std::cin >> comparedValueA >> comparedValueB;
			resultantValueC = comparedValueA ^ comparedValueB;
			std::cout << "------------------------------------\n";
			std::cout << std::setw(10) << "'" << comparedValueA << "' XOR '" << comparedValueB << "' =\n\n"
				<< std::setw(20) << resultantValueC << "\n------------------------------------\n\n\n";
			break;
		case 11:
			ignoreExtraInputs();
			std::cout << " Enter 2 Decimal values - separated by a space - you would like to perfrom the 'NOR' Operation on:\n";
			std::cin >> comparedValueA >> comparedValueB;
			resultantValueC = comparedValueA | comparedValueB;
			std::cout << "------------------------------------\n";
			std::cout << std::setw(10) << "'" << comparedValueA << "' NOR '" << comparedValueB << "' =\n\n"
				<< std::setw(20) << ~resultantValueC << "\n------------------------------------\n\n\n";
			break;
		case 12:
			ignoreExtraInputs();
			std::cout << " Enter 2 Decimal values - separated by a space - you would like to perfrom the 'NAND' Operation on:\n";
			std::cin >> comparedValueA >> comparedValueB;
			resultantValueC = comparedValueA & comparedValueB;
			std::cout << "------------------------------------\n";
			std::cout << std::setw(10) << "'" << comparedValueA << "' NAND '" << comparedValueB << "' =\n\n"
				<< std::setw(20) << ~resultantValueC << "\n------------------------------------\n\n\n";
			break;
		/*case 999:
		{
			ignoreExtraInputs();
			std::string input1 = "";
			std::cout << " Enter a binary number:\n";
			std::cin >> input1;
			binaryToDecimal(input1);
		}
			break;*/
		default:
			ignoreExtraInputs();
			std::cout << " SOMETHING WENT WRONG IN THE MENU SWITCH STATEMENT YOU DONKEY!\n";
			break;

		}

	} while (quitOrNaw);
}

int main() {
	
	menuOptions();

	std::cout << " Press enter or return to continue...";
	ignoreExtraInputs();

	return 0;
}

/*
*	TODO: BCD (Binary coded Decimal) Option (Pending Approval)
*/