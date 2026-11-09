#pragma once
#include <iostream>
enum Categoria_Consultada
{
	Tarea,
	Examen,
	LB1,
	EA1,
	Reto,
	Proyecto,
	Teoria,
	Depuracion,
	Otro,
};

class Registro
{
private:
	int id;
	std::string fecha;
	std::string curso;
	Categoria_Consultada categoria;
	std::string herramienta_IA;
	std::string que_consultamos;
	std::string resultado_IA;
	std::string que_se_cambio;
	std::string como_se_valido;
public:
	Registro(int id, std::string fecha, std::string curso, Categoria_Consultada categoria, std::string herramientaIA, std::string que_consultamos, std::string resultado_IA, std::string que_se_cambio, std::string como_se_valido)
	{
		this->id = id;
		this->fecha = fecha;
		this->curso = curso;
		this->categoria = categoria;
		this->herramienta_IA = herramienta_IA;
		this->que_consultamos = que_consultamos;
		this->resultado_IA = resultado_IA;
		this->que_se_cambio = que_se_cambio;
		this->como_se_valido = como_se_valido;
	}

	int getid()
	{
		return id;
	}

	std::string getfecha()
	{
		return fecha;
	}

	std::string getcurso()
	{
		return curso;
	}

	Categoria_Consultada getcategoria()
	{
		return categoria;
	}

	std::string getherramienta_IA()
	{
		return herramienta_IA;
	}

	std::string getque_consultamos()
	{
		return que_consultamos;
	}

	std::string getresultado_IA()
	{
		return resultado_IA;
	}

	std::string que_se_cambio()
	{
		return que_se_cambio;
	}

	std::string getcomo_se_valido()
	{
		return como_se_valido;
	}

	void setcategoria(Categoria_Consultada categoria)
	{
		this->categoria = categoria;
	}

	int setId(int id)
	{
		this->id = id;
		return id;
	}
};
