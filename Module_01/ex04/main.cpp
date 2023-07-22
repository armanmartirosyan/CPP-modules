#include <fstream>
#include <iostream>
#include <string>

void	replaceString(std::string& original,const std::string& toFind, const std::string& replace, size_t pos){
	if (pos == std::string::npos)
		return ;
	original = original.substr(0, pos) + replace + original.substr(pos + toFind.length());
	replaceString(original, toFind, replace, original.find(toFind, pos + 1));
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Wrong arguments number" << std::endl;
		return (1);
	}
	std::string 	fileName(argv[1]);
	std::string 	toFind(argv[2]);
	std::string		replace(argv[3]);
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	size_t			pos;

	inputFile.open(fileName);
	if (inputFile.is_open()) {
		outputFile.open(fileName + ".replace");
		std::string line;
		while (std::getline(inputFile, line)) {
			pos = line.find(toFind);
			if (pos != std::string::npos)
				replaceString(line, toFind, replace, pos);
			outputFile << line << std::endl;
		}
		inputFile.close();
	}
	else {
		std::cerr << "Error opening the file." << std::endl;
		return (1);
	}
	return (0);
}
