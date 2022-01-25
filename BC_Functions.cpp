#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <boost/algorithm/string/erase.hpp>

inline void ignoreExtraInputs() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline std::string decimalToBinary(int decInput) {
	
	int exponent = 0;
	int previousExponent = 0;
	std::string binaryNum = "";
	
	while (pow(2, exponent) <= decInput) {
		previousExponent = exponent;
		exponent++;
	}
	while (previousExponent >= 0) {
		if (decInput - pow(2, previousExponent) >= 0) {
			decInput -= (int) pow(2, previousExponent);
			binaryNum.push_back('1');
		}
		else {
			binaryNum.push_back('0');
		}
		previousExponent--;
	}
	return binaryNum;
}

/*inline std::vector<std::string> decimalToBinaryReturningArray(int decInput) {

	int exponent = 0;
	int previousExponent = 0;
	std::vector<std::string> binaryNum = {};

	while (pow(2, exponent) <= decInput) {
		previousExponent = exponent;
		exponent++;
	}
	while (previousExponent >= 0) {
		if (decInput - pow(2, previousExponent) >= 0) {
			decInput -= (int)pow(2, previousExponent);
			binaryNum.push_back("1");
		}
		else {
			binaryNum.push_back("0");
		}
		previousExponent--;
	}
	return binaryNum;
}*/

inline std::string nibbleGuaranteeer(std::string sub_h_binInput)
{
	int binaryLength = sub_h_binInput.length();
	std::string newBinarySequ = "";

	if (binaryLength % 4 != 0) {
		for (unsigned int i = 0; i < (unsigned)(4 - (binaryLength % 4)); i++) {
			newBinarySequ.push_back('0');
		}
		binaryLength += (4 - (binaryLength % 4));
		newBinarySequ += sub_h_binInput;
	}
	else {
		newBinarySequ = sub_h_binInput;
	}
	return newBinarySequ;
}

/*inline std::vector<std::string> nibbleGuaranteeer(std::vector<std::string> sub_h_binInput, int requiredSize)
{
	int binaryLength = requiredSize;
	std::vector<std::string> newBinarySequ = {};

	if (binaryLength % 4 != 0) {
		for (unsigned int i = 0; i < (unsigned)(4 - (binaryLength % 4)); i++) {
			newBinarySequ.push_back("0");
		}
		binaryLength += (4 - (binaryLength % 4));
		//newBinarySequ += sub_h_binInput;
		for (unsigned int i = 0; i < sub_h_binInput.size(); i++) {
			newBinarySequ.push_back(sub_h_binInput[i]);
		}
	}
	else {
		newBinarySequ = sub_h_binInput;
	}
	return newBinarySequ;
}*/

inline std::string nibbleSpaceAparter(std::string sub_binInput) {

	int indexModifier = 4;
	int whiteSpaceAddedModifier = 0;

	for (unsigned int i = 0; i < (unsigned)((sub_binInput.length() / 4) - 1); i++) {
		sub_binInput.insert(indexModifier + whiteSpaceAddedModifier, " ");
		indexModifier += 4;
		whiteSpaceAddedModifier++;
	}
	return sub_binInput;
}

inline std::string binaryToHexa(std::string h_binInput) {

	int binaryLength = 0;
	int nibbleIndexBeginModifier = 0;
	int nibbleIndexEndModifier = 4;
	int nibbleCalculatedDecimalValue = 0;
	int nibbleHighestExponentValue = 8;
	std::string hexaValue = "";
	std::vector<std::string> nibbles;

	h_binInput = nibbleGuaranteeer(h_binInput);
	binaryLength = h_binInput.length() / 4;
	
	for (unsigned int i = 0; i < (unsigned) binaryLength; i++) {
		nibbles.push_back(h_binInput.substr(nibbleIndexBeginModifier, nibbleIndexEndModifier));
		nibbleIndexBeginModifier += 4;
		nibbleIndexEndModifier += 4;
	}

	for (std::string &nibbleValue : nibbles) {
		nibbleCalculatedDecimalValue = 0;
		nibbleHighestExponentValue = 8;
		for (unsigned int i = 0; i < 4; i++) {
			if (nibbleValue[i] == '1') {
				nibbleCalculatedDecimalValue += nibbleHighestExponentValue;
			}
			nibbleHighestExponentValue = (int) ((nibbleHighestExponentValue / 2) + 0.5);
		}
		if (nibbleCalculatedDecimalValue >= 0 && nibbleCalculatedDecimalValue <= 9) {
			hexaValue.push_back(nibbleCalculatedDecimalValue + 48);
		}
		else if (nibbleCalculatedDecimalValue >= 10 && nibbleCalculatedDecimalValue <= 15) {
			hexaValue.push_back(nibbleCalculatedDecimalValue + 55);
		}
	}
	return hexaValue;
}

inline int binaryToDecimal(std::string d_binInput) {

	int nibbleHighestExponentValue = (int) pow(2, d_binInput.length() - 1);
	int nibbleCalculatedDecimalValue = 0;
	
	for (char &indexValue : d_binInput) {
		if (indexValue == '1') {
			nibbleCalculatedDecimalValue += nibbleHighestExponentValue;
		}
		nibbleHighestExponentValue = (int) ((nibbleHighestExponentValue / 2) + 0.5);
	}
	return nibbleCalculatedDecimalValue;
}

inline int hexaToDecimal(std::string hexaInput) {

	int hexaHighestExponentValue = (int) pow(16, hexaInput.length() - 1);
	int hexaToDecimalValue = 0;

	for (char &indexValue : hexaInput) {
		if (indexValue >= '0' && indexValue <= '9') {
			hexaToDecimalValue += (indexValue - 48) * hexaHighestExponentValue;
		}
		else if (indexValue >= 'A' && indexValue <= 'F') {
			hexaToDecimalValue += (indexValue - 55) * hexaHighestExponentValue;
		}
		else {
			std::cout << "\nSomething went wrong in the 'hexaToBinary' function\n";
		}
		hexaHighestExponentValue = hexaHighestExponentValue / 16;
	}
	return hexaToDecimalValue;
}

/*inline std::string addition(std::string binaryInputOne, std::string binaryInputTwo) {

	std::vector<std::string> indexedBinaryInput_One = {}, indexedBinaryInput_Two = {};
	std::string resultantBinaryValue = "", remainder = "0";
	int binaryLength = -1;

	indexedBinaryInput_One = decimalToBinaryReturningArray(binaryToDecimal(binaryInputOne));
	indexedBinaryInput_Two = decimalToBinaryReturningArray(binaryToDecimal(binaryInputTwo));

	if (indexedBinaryInput_One.size() > indexedBinaryInput_Two.size()) {
		binaryLength = indexedBinaryInput_One.size();
	}
	else {
		binaryLength = indexedBinaryInput_Two.size();
	}
	indexedBinaryInput_One = nibbleGuaranteeer(indexedBinaryInput_One, binaryLength);
	indexedBinaryInput_Two = nibbleGuaranteeer(indexedBinaryInput_Two, binaryLength);

	for (int i = (binaryLength-1); i >= 0; i--) {
		if (indexedBinaryInput_One[i] == "0" && indexedBinaryInput_Two[i] == "0" && remainder == "0") {
			resultantBinaryValue.push_back('0');
			remainder = "0";
		}
		else if ((indexedBinaryInput_One[i] == "1" && indexedBinaryInput_Two[i] == "0" && remainder == "0") ||
				 (indexedBinaryInput_One[i] == "0" && indexedBinaryInput_Two[i] == "1" && remainder == "0") ||
				 (indexedBinaryInput_One[i] == "0" && indexedBinaryInput_Two[i] == "0" && remainder == "1")) {
			resultantBinaryValue.push_back('1');
			remainder = "0";
		}
		else if ((indexedBinaryInput_One[i] == "1" && indexedBinaryInput_Two[i] == "1" && remainder == "0") ||
				 (indexedBinaryInput_One[i] == "1" && indexedBinaryInput_Two[i] == "0" && remainder == "1") ||
				 (indexedBinaryInput_One[i] == "0" && indexedBinaryInput_Two[i] == "1" && remainder == "1")) {
			resultantBinaryValue.push_back('0');
			remainder = "1";
		}
		else if (indexedBinaryInput_One[i] == "1" && indexedBinaryInput_Two[i] == "1" && remainder == "1") {
			resultantBinaryValue.push_back('1');
			remainder = "1";
		}
		else {
			std::cout << "\nThere happens to be something else occurring in the forloop in 'binaryAddition'\n";
		}
	}

	return resultantBinaryValue;
}*/