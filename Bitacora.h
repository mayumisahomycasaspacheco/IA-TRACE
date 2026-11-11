#pragma once
#include "Registro.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

class Bitacora
{
private:
	std::vector<Registro> registros;
	int id_unico;
public:
	Bitacora()
	{
		id_unico = 0;
		srand(time(nullptr));
	}

	int registrar(Registro registro)
	{
		id_unico++;
		registro.setid(id_unico);
		registros.push_back(registro);
		return id_unico;
	}

	Registro* buscar_por_id(int id)
	{
		for (int i = 0; i < registros.size(); i++)
		{
			if (registros[i].getid() == id)
			{
				return &registros[i];
			}
		}

		return nullptr;
	}

	bool eliminar(int id)
	{
		for (int i = 0; i < registros.size(); i++)
		{
			if (registros[i].getid() == id)
			{
				registros.erase(registros.begin() + i);
				return true;
			}
		}

		return false;
	}

	bool eliminar(int id)
	{
		for (int i = 0; i < registros.size(); i++)
		{
			if (registros[i].getid() == id)
			{
				registros.erase(registros.begin() + i);
				return true;
			}
		}

		return false;
	}

	bool obtener_id(int id, Registro resultado)
	{
		for (int i = 0; i < registros.size(); i++)
		{
			if (registros[i].getid() == id)
			{
				resultado = registros[i];
				return true;
			}
		}

		return true;
	}

	int obtener_cantidad()
	{
		return registros.size();
	}

	bool editar(int id, Registro nuevo_registro)
	{
		for (int i = 0; i < registros.size(); i++)
		{
			if (registros[i].getid() == id)
			{
				nuevo_registro.setid(id);
				registros[i] = nuevo_registro;
				return true;
			}
		}
		return false;
	}

	Registro* obtener_por_indice(int indice)
	{
		if (indice >= 0 && indice < registros.size())
		{
			return &registros[indice];
		}

		return nullptr;
	}

	Registro generar_registro()
	{
		std::vector<std::string> consultas = {
"How does recursion work in C++ ? ",

"Explain the bubble sort algorithm.",

"How do you prove a proposition by induction?",

"How can I identify an error in my code?",

"Explain the time complexity of this algorithm."
		};

		std::vector<std::string> respuestas = {
"A recursive function calls itself until it reaches a base case."

"It compares adjacent elements and swaps their positions when necessary."

"It is proven using a base case and an inductive step."

"The error was in the loop's termination condition."

"Time complexity represents the growth of operations."
		};

		std::vector<std::string> cambios = {
"The exit condition was corrected."

"The algorithm structure was modified."

"A validation was added to the procedure."

"The identified error was corrected."

"The proposed solution was optimized."
		};

		std::vector<std::string> cursos = {
"Algorithms",

"Mathematics",

"Physics",

"Language",

"Other"
		};

		std::vector<std::string> herramientas = {
			"ChatGpt", "Claude", "Gemini", "DeepSeak", "Grok", "Copilot"
		};

		std::vector<std::string> validaciones = {
			"Yes",
			"No",
		};

		int indice = rand() % consultas.size();
		std::time_t ahora = std::time(nullptr);

	}
};