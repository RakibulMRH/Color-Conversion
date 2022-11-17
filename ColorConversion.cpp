#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>

struct Color
{
	int r;
	int g;
	int b;
};


void SetBackgroundColor(const Color& aColor)
{
	std::string modifier = "\x1b[48;2;" + std::to_string(aColor.r) + ";" + std::to_string(aColor.g) + ";" + std::to_string(aColor.b) + "m";
	printf(modifier.c_str());
}

void SetForegroundColor(const Color& aColor)
{
	std::string modifier = "\x1b[38;2;" + std::to_string(aColor.r) + ";" + std::to_string(aColor.g) + ";" + std::to_string(aColor.b) + "m";
	printf(modifier.c_str());
}
long float max_value(long float i, long float j, long float k)
{
	if (i > j && i > k)
	{
		return i;
	}
	else if (j > k)
	{
		return j;
	}
	else
	{
		return k;
	}
}
void rgb_cmyk(int R, int G, int B)
{
	if (R <= 255 && G <= 255 && B <= 255)
	{
		double C, M, Y, K;
		long float RR = R / 255.0;
		long float GG = G / 255.0;
		long float BB = B / 255.0;
		long float x = 1, y = 100;
		//std::cout << RR << "\n" << GG << "\n" << BB<<"\n" << max_value(RR, GG, BB) <<"\n";

		K = ((x - max_value(RR, GG, BB)));
		C = ((x - RR - K) / (x - K));
		M = ((x - GG - K) / (x - K));
		Y = ((x - BB - K) / (x - K));

		std::cout << "\t Converted to \033[1;46mC\033[1;45mM\033[1;43mY\033[1;100mK\033[0m(" << C << "," << M << "," << Y << "," << K << ")" << "\n";
		std::cout << "Color sample";
		SetForegroundColor({ R,G,B });
		SetBackgroundColor({ R,G,B });
		std::cout << "\nColor sample\n";
		std::cout << "Color sample\n";
		std::cout << "Color sample\n";
	}
	else
	{
		std::cout << "\033[1;31mInvalid Input\033[0m\n";
	}
}

void rgb_cmy(int R, int G, int B)
{
	if (R <= 255 && G <= 255 && B <= 255)
	{
		double C, M, Y;
		long float RR = R / 255.0;
		long float GG = G / 255.0;
		long float BB = B / 255.0;
		long float x = 1;

		C = x - RR;
		M = x - GG;
		Y = x - BB;

		std::cout << "\t Converted to \033[1;46mC\033[1;45mM\033[1;43mY\033[0m(" << C << "," << M << "," << Y << ")" << "\n";
		std::cout << "Color sample";
		SetForegroundColor({ R,G,B });
		SetBackgroundColor({ R,G,B });
		std::cout << "\nColor sample\n";
		std::cout << "Color sample\n";
		std::cout << "Color sample\n";
	}
	else
	{
		std::cout << "\033[1;31mInput range must be 0 to 255\033[0m\n";
	}
}

void cmyk_rgb(float C, float M, float Y, float K)
{
	if (C <= 100 && M <= 100 && Y <= 100)
	{
		int R, G, B;
		R = 255 * (1 - C / 100) * (1 - K / 100);
		G = 255 * (1 - M / 100) * (1 - K / 100);
		B = 255 * (1 - Y / 100) * (1 - K / 100);
		std::cout << "\t Converted to \033[1;31mR\033[1;32mG\033[1;34mB\033[0m(" << R << "," << G << "," << B << ")" << "\n";
		std::cout << "Color sample";
		SetForegroundColor({ R,G,B });
		SetBackgroundColor({ R,G,B });
		std::cout << "\nColor sample\n";
		std::cout << "Color sample\n";
		std::cout << "Color sample\n";
	}
	else
	{
		std::cout << "\033[1;31mInput range must be 0.00 to 100.00\033[0m\n";
	}
}

void cmy_rgb(float C, float M, float Y)
{
	if (C <= 100 && M <= 100 && Y <= 100 )
	{
		int R, G, B;
		R = (1 - C / 100) * 255.0;
		G = (1 - M / 100) * 255.0;
		B = (1 - Y / 100) * 255.0;
		std::cout << "\t Converted to \033[1;31mR\033[1;32mG\033[1;34mB\033[0m(" << R << "," << G << "," << B << ")" << "\n";
		std::cout << "Color sample";
		SetForegroundColor({ R,G,B });
		SetBackgroundColor({ R,G,B });
		std::cout << "\nColor sample\n";
		std::cout << "Color sample\n";
		std::cout << "Color sample\n";
	}
	else
	{
		std::cout << "\033[1;31mInput range must be 0.00 to 100.00\033[0m\n";
	}
}

void vertexgen()
{
	int width;
	int length;
	int wid;
	int len;
	std::cout << "Enter photo dimensions (width and length): ";
	std::cin >> width >> length;
	std::cout << "Enter pixel position: ";
	std::cin >> wid >> len;
	float gradx = width / 2;
	float grady = length / 2;
	float squareX = (1 / gradx);
	float squareY = (1 / grady);
	float x = 0, y = 0;
	//std::cout << squareX << " " << squareY << " " << len << " " << grady << " " << y;
	if (wid > gradx)
	{
		x = (wid - gradx) * (squareX);
	}
	else if (wid < gradx)
	{
		x = (gradx - wid) * (-1 * squareX);
	}

	if (len > grady)
	{
		y = (len - grady) * (-1 * squareY);
	}
	else if (len < grady)
	{
		y = (grady - len) * (squareY);
	}
	else if (wid == gradx)
	{
		x = 0;
	}
	else if (len == grady)
	{
		y = 0;
	}

	std::cout << "(x,y) is (" << x << "," << y << ")\n";
}


int main()
{

	int r, g, b;
	float c, m, y, k;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	int choice;
	bool t = true;
	while (t)
	{
		std::cout << "\033[0m\033[1;32m-------------------------------------------\n";
		std::cout << "\033[0m\033[1;31m\t  C\033[1;32mO\033[1;33mL\033[1;34mO\033[1;35mR \033[1;31mC\033[1;32mO\033[1;33mN\033[1;34mV\033[1;35mE\033[1;36mR\033[1;37mS\033[1;38mI\033[1;33mO\033[1;32mN\033[0m\n";
		std::cout << "\033[0m\033[1;32m-------------------------------------------\033[0m\n";
		std::cout << "\t1. \033[1;31mR\033[1;32mG\033[1;34mB\033[0m to \033[1;46mC\033[1;45mM\033[1;43mY\033[1;100mK\033[0m\n";
		std::cout << "\t2. \033[1;31mR\033[1;32mG\033[1;34mB\033[0m to \033[1;46mC\033[1;45mM\033[1;43mY\033[0m\n";
		std::cout << "\t3. \033[1;46mC\033[1;45mM\033[1;43mY\033[1;100mK\033[0m to \033[1;31mR\033[1;32mG\033[1;34mB\033[0m\n";
		std::cout << "\t4. \033[1;46mC\033[1;45mM\033[1;43mY\033[0m to \033[1;31mR\033[1;32mG\033[1;34mB\033[0m\n";
		std::cout << "\t5. Read Manual\n";
		std::cout << "\t6. Find OpenGL vertices from pixel numbers! \033[1;41mNew Feature\033[0m\n";
		std::cout << "\t7. \033[1;41mExit\033[0m\n";
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			std::cout << "-------------------------------------------\n";
			std::cout << "Color conversion \033[1;31mR\033[1;32mG\033[1;34mB\033[0m to \033[1;46mC\033[1;45mM\033[1;43mY\033[0mK\n";
			std::cout << "-------------------------------------------\n";
			std::cout << "Enter your \033[1;31mR\033[1;32mG\033[1;34mB\033[0m color code (in \033[1;31mXXX XXX XXX\033[0m format)\n";
			std::cin >> r >> g >> b;
			rgb_cmyk(r, g, b);
			break;
		case 2:
			std::cout << "-------------------------------------------\n";
			std::cout << "Color conversion \033[1;31mR\033[1;32mG\033[1;34mB\033[0m to \033[1;46mC\033[1;45mM\033[1;43mY\033[0m\n";
			std::cout << "-------------------------------------------\n";
			std::cout << "Enter your \033[1;31mR\033[1;32mG\033[1;34mB\033[0m color code (in \033[1;31mXXX XXX XXX\033[0m format)\n";
			std::cin >> r >> g >> b;
			rgb_cmy(r, g, b);
			break;
		case 3:
			std::cout << "-------------------------------------------\n";
			std::cout << "Color conversion \033[1;46mC\033[1;45mM\033[1;43mY\033[1;100mK\033[0m to \033[1;31mR\033[1;32mG\033[1;34mB\033[0m\n";
			std::cout << "-------------------------------------------\n";
			std::cout << "Enter the percentage of your \033[1;46mC\033[1;45mM\033[1;43mY\033[1;100mK\033[0m color code (in \033[1;31mX X X X\033[0m format)\n";
			std::cin >> c >> m >> y >> k;
			cmyk_rgb(c, m, y, k);
			break;
		case 4:
			std::cout << "-------------------------------------------\n";
			std::cout << "Color conversion \033[1;46mC\033[1;45mM\033[1;43mY\033[0m to \033[1;31mR\033[1;32mG\033[1;34mB\033[0m\n";
			std::cout << "-------------------------------------------\n";
			std::cout << "Enter the percentage of your \033[1;46mC\033[1;45mM\033[1;43mY\033[0m color code (in \033[1;31mX X X\033[0m format)\n";
			std::cin >> c >> m >> y;
			cmy_rgb(c, m, y);
			break;
		case 5:
			std::cout << "\033[0m\033[1;32m-------------------------------------------\n";
			std::cout << "\033[1;31m\t\tMANUAL\n";
			std::cout << "\033[1;32m-------------------------------------------\033[0m\n";
			std::cout << "This app can be used to make different conversions from the listed cases. \nChoose your option by entering the number from the list and then press enter.\nWhile giving data inputs maintain space according to the format, which will appear beforehand in red. \nNB: *For RGB inputs must be integers from \033[1;31m0-255\033[0m\n    *For CMY/CMYK, inputs must be decimal from \033[1;31m0.00-100.00\033[0m \n\033[1;46mThank you for using this app!\033[0m\n";
			break;
		case 6:
			vertexgen();
			break;

		case 7:
			t = false;
			break;

		default:
			std::cout << "\033[1;31mxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
			std::cout << "\033[1;31m\t\tInvalid Option\n";
			std::cout << "\033[1;31mxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\033[0m\n";
			break;
		}
	}
}
