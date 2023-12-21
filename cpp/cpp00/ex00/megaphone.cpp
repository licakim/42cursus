#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for(int n = 1; n < argc; n++)
		{
			while(*argv[n])
			{
				std::cout << static_cast<char>(toupper(*argv[n]));
				argv[n]++;
			}
		}
		std::cout<<std::endl;
	}
}