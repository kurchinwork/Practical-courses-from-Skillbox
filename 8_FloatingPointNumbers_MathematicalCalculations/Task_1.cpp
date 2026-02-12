#include <iostream>
#include <cmath>

int	main() {
	while (true) {
		float f, m, t, a;
		std::cout << "\nВведите F:= "; std::cin >> f;
		std::cout << "\nВведите m:= "; std::cin >> m;
		std::cout << "\nВведите t:= "; std::cin >> t;

		bool logic = false;
		while (!logic) {
			std::cout << "\nПовторите ввод, ранее он был некорректен\n";
			std::cout << "\nВведите F:= "; std::cin >> f;
			std::cout << "\nВведите m:= "; std::cin >> m;
			std::cout << "\nВведите t:= "; std::cin >> t;

			if (f > 0 && m > 0 && t > 0) {
				logic = true; 
			}
			else {
				logic = false; 
			}
		}

		a = f / m;
		a = a * (std::pow(t, 2)) / 2;

		std::cout << "\n На расстоянии = " << a << " от первоначального положения окажется космический корабль через " << t << " секунд.";
		std::cout << "\n\n***************************************";
		std::string go;

		std::cout << "\n Желаете повторить программу?: "; std::cin >> go;
		if (!(go == "Y" || go == "y")) {
			break;
		}
	}
}
