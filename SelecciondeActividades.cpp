#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Actividad {
	int inicio;
	int fin;
};

bool compararAct(Actividad& a1, Actividad& a2) {
	return a1.fin < a2.fin;
}

vector<Actividad> SeleccionAct(std::vector<Actividad>& actividades) {

	sort(actividades.begin(), actividades.end(), compararAct);

	vector<Actividad> seleccionadas;

	seleccionadas.push_back(actividades[0]);

	int prev = 0;
	for (int i = 1; i < actividades.size(); ++i) {
		
		if (actividades[i].inicio >= actividades[prev].fin) {
			seleccionadas.push_back(actividades[i]);
			prev = i;
		}
	}

	return seleccionadas;
}

int main() {
	
	vector<Actividad> actividades = { {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16} };
	vector<Actividad> seleccionadas = SeleccionAct(actividades);

	cout << "Actividades seleccionadas:\n";
	for (int i{ 0 }; i< seleccionadas.size() ; i++) {
		cout << "Inicio: " << seleccionadas[i].inicio << ", Fin: " << seleccionadas[i].fin << "\n";
	}

	return 0;
}
