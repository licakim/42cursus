#include <fstream>
#include<iostream>

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		std::cout<<""<<std::endl;
		return 0;
	}
	std::ifstream in(argv[1]);
	if(!in.is_open())
	{
		std::cout<<"파일을 찾을 수 없습니다."<<std::endl;
		return 0;
	}
	std::ofstream out(std::string(argv[1]) + ".replace");
	std::string buf = "";
	int c;
	while( (c=in.get()) != EOF)
		buf+= static_cast<unsigned char>(c);
	int startIndex = 0;
	int findIndex = 0;
	int str1_length = std::string(argv[2]).length();
	int str2_length = std::string(argv[3]).length();
	while(1)
	{
		findIndex = buf.find(argv[2], startIndex);
		if(findIndex == std::string::npos)
			break;
		buf.erase(findIndex, str1_length);
		buf.insert(findIndex, argv[3]);
		startIndex = findIndex + str2_length ;
	}
	out << buf;
	return 0;
}

