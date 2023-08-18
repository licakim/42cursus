
#include <iostream>

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
				if(97 <= *argv[n] && *argv[n] <= 122)
					*argv[n] -=32;
				std::cout << *argv[n];
				argv[n]++;
			}
		}
		std::cout<<std::endl;
	}
}