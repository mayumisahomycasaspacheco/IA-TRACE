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
};