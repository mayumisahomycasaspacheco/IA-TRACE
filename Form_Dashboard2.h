#pragma once
#include "Bitacora.h"
namespace IATRACE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Dashboard2
	/// </summary>
	public ref class Form_Dashboard2 : public System::Windows::Forms::Form
	{
	public:
		Form_Dashboard2(Bitacora* gestorBitacora)
		{
			InitializeComponent();
			gestor = gestorBitacora;

			colores = gcnew array<Color>{
				Color::FromArgb(37, 12, 82),
					Color::FromArgb(14, 122, 140),
					Color::FromArgb(245, 166, 35),
					Color::FromArgb(214, 0, 153),
					Color::FromArgb(94, 60, 153),
					Color::FromArgb(58, 140, 90)
			};

			calcular_indicadores();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form_Dashboard2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
		Bitacora* gestor;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form_Dashboard2
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form_Dashboard2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IA-TRACE - Dashboard 2: Metrics and Indicators";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_Dashboard2::Form_Dashboard2_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
		array<String^>^ nombres_herramientas;
		array<int>^ total_herramienta;
		array<int>^ verificadas_herramienta;
		array<double>^ porcentaje_herramienta; //Llenarse con calcular_indicadores()

		array<int>^ conteo_semana;
		array<Color>^ colores;

		int total_registros;
		int total_verificadas;
		double porcentaje_verificadas;

		double promedio_semana;
		String^ herramienta_menor;
		double porcentaje_herramienta_menor;

	private:
	private: void calcular_indicadores()
	{
		total_registros = 0;
		total_verificadas = 0;
		porcentaje_verificadas = 0;
		promedio_semana = 0;
		herramienta_menor = "";
		porcentaje_herramienta_menor = 0;

		int cantidad = gestor->obtener_cantidad();

		// El curso no permite List<T>: uso arreglos con espacio para "cantidad"
		// elementos y un contador manual (n_nombres, n_fechas) de los que ya se usaron.
		array<String^>^ nombres = gcnew array<String^>(cantidad);
		array<int>^ totales = gcnew array<int>(cantidad);
		array<int>^ verificadas = gcnew array<int>(cantidad);
		array<double>^ segundos = gcnew array<double>(cantidad);
		int n_nombres = 0;
		int n_fechas = 0;

		for (int i = 0; i < cantidad; i++)
		{
			Registro* r = gestor->obtener_por_indice(i);
			if (r == nullptr) continue;

			String^ herramienta = gcnew String(r->getherramienta_IA().c_str());
			bool verificada = (r->getcomo_se_valido() == "Yes");

			// Buscar la herramienta recorriendo las que ya se guardaron
			int idx = -1;
			for (int j = 0; j < n_nombres; j++)
			{
				if (nombres[j] == herramienta)
				{
					idx = j;
					break;
				}
			}
			if (idx < 0)
			{
				idx = n_nombres;
				nombres[idx] = herramienta;
				n_nombres++;
			}
			totales[idx]++;
			if (verificada)
			{
				verificadas[idx]++;
				total_verificadas++;
			}
			total_registros++;

			std::string f = r->getfecha();
			if (f.length() >= 10)
			{
				std::tm t = {};
				t.tm_mday = std::stoi(f.substr(0, 2));
				t.tm_mon = std::stoi(f.substr(3, 2)) - 1;
				t.tm_year = std::stoi(f.substr(6, 4)) - 1900;
				t.tm_hour = 12;
				segundos[n_fechas] = (double)std::mktime(&t);
				n_fechas++;
			}
		}

		if (total_registros == 0)
		{
			nombres_herramientas = gcnew array<String^>(0);
			total_herramienta = gcnew array<int>(0);
			verificadas_herramienta = gcnew array<int>(0);
			porcentaje_herramienta = gcnew array<double>(0);
			conteo_semana = gcnew array<int>(0);
			return;
		}

		// Pasar a arreglos del tamano exacto
		int n = n_nombres;
		nombres_herramientas = gcnew array<String^>(n);
		total_herramienta = gcnew array<int>(n);
		verificadas_herramienta = gcnew array<int>(n);
		porcentaje_herramienta = gcnew array<double>(n);

		for (int i = 0; i < n; i++)
		{
			nombres_herramientas[i] = nombres[i];
			total_herramienta[i] = totales[i];
			verificadas_herramienta[i] = verificadas[i];
			porcentaje_herramienta[i] = (total_herramienta[i] > 0)
				? verificadas_herramienta[i] * 100.0 / total_herramienta[i]
				: 0;
		}

		// ---- consultas por semana ----
		if (n_fechas > 0)
		{
			double minimo = segundos[0];
			for (int i = 1; i < n_fechas; i++)
				if (segundos[i] < minimo) minimo = segundos[i];

			int max_semana = 0;
			array<int>^ semana_de = gcnew array<int>(n_fechas);
			for (int i = 0; i < n_fechas; i++)
			{
				int dias = (int)((segundos[i] - minimo) / 86400.0 + 0.5);
				semana_de[i] = dias / 7;
				if (semana_de[i] > max_semana) max_semana = semana_de[i];
			}

			conteo_semana = gcnew array<int>(max_semana + 1);
			for (int i = 0; i < n_fechas; i++)
				conteo_semana[semana_de[i]]++;
		}
		else
		{
			conteo_semana = gcnew array<int>(0);
		}

		// ---- KPIs ----
		porcentaje_verificadas = total_verificadas * 100.0 / total_registros;
		if (conteo_semana->Length > 0)
			promedio_semana = (double)total_registros / conteo_semana->Length;

		// ---- herramienta menos verificada ----
		int indice_menor = 0;
		double menor_valor = 101.0;
		for (int i = 0; i < n; i++)
		{
			if (total_herramienta[i] > 0 && porcentaje_herramienta[i] < menor_valor)
			{
				menor_valor = porcentaje_herramienta[i];
				indice_menor = i;
			}
		}
		herramienta_menor = nombres_herramientas[indice_menor];
		porcentaje_herramienta_menor = porcentaje_herramienta[indice_menor];
	}
	private: System::Void Form_Dashboard2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ graphics = e->Graphics;

		System::Drawing::Font^ fuente_titulo = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
		System::Drawing::Font^ fuente_etiqueta = gcnew System::Drawing::Font("Segoe UI", 11);
		System::Drawing::Font^ fuente_pequena = gcnew System::Drawing::Font("Segoe UI", 9);
		System::Drawing::Font^ fuente_kpi = gcnew System::Drawing::Font("Segoe UI", 32, FontStyle::Bold);
		System::Drawing::Font^ fuente_hallazgo = gcnew System::Drawing::Font("Segoe UI", 13, FontStyle::Bold);

		if (total_registros == 0)
		{
			graphics->DrawString("No records: register or generate data to see the metrics.", fuente_hallazgo, Brushes::Indigo, 40.0f, 60.0f);
			return;
		}

		IATRACE::Rectangle rectangulo_kpi_izquierdo = IATRACE::Rectangle(20, 40, 560, 130);
		IATRACE::Rectangle rectangulo_kpi_derecho = IATRACE::Rectangle(600, 40, 560, 130);
		IATRACE::Rectangle rectangulo_izquierdo = IATRACE::Rectangle(20, 200, 560, 330);
		IATRACE::Rectangle rectangulo_derecho = IATRACE::Rectangle(600, 200, 560, 330);
		IATRACE::Rectangle rectangulo_abajo = IATRACE::Rectangle(20, 560, 1140, 120);

		dibujar_marco(graphics, rectangulo_kpi_izquierdo, "Verified answers (overall)", fuente_titulo);
		dibujar_marco(graphics, rectangulo_kpi_derecho, "Average queries per week", fuente_titulo);
		dibujar_marco(graphics, rectangulo_izquierdo, "% verified by AI tool", fuente_titulo);
		dibujar_marco(graphics, rectangulo_derecho, "Weekly query trend", fuente_titulo);
		dibujar_marco(graphics, rectangulo_abajo, "Finding", fuente_titulo);

		SolidBrush^ pincel_turquesa = gcnew SolidBrush(colores[1]);
		SolidBrush^ pincel_naranja = gcnew SolidBrush(colores[2]);

		String^ texto_porcentaje = String::Format("{0:F1}%", porcentaje_verificadas);
		graphics->DrawString(texto_porcentaje, fuente_kpi, pincel_turquesa, (float)(rectangulo_kpi_izquierdo.X + 20), (float)(rectangulo_kpi_izquierdo.Y + 8));

		String^ texto_detalle = String::Format("{0} of {1} queries have verification evidence", total_verificadas, total_registros);
		graphics->DrawString(texto_detalle, fuente_etiqueta, Brushes::Black, (float)(rectangulo_kpi_izquierdo.X + 20), (float)(rectangulo_kpi_izquierdo.Y + 70));

		int ancho_barra_total = rectangulo_kpi_izquierdo.Width - 40;
		int ancho_relleno = (int)(porcentaje_verificadas / 100.0 * ancho_barra_total);

		graphics->DrawRectangle(Pens::Silver, rectangulo_kpi_izquierdo.X + 20, rectangulo_kpi_izquierdo.Y + 102, ancho_barra_total, 14);
		graphics->FillRectangle(pincel_turquesa, rectangulo_kpi_izquierdo.X + 20, rectangulo_kpi_izquierdo.Y + 102, ancho_relleno, 14);

		String^ texto_promedio = String::Format("{0:F1}", promedio_semana);
		graphics->DrawString(texto_promedio, fuente_kpi, pincel_naranja, (float)(rectangulo_kpi_derecho.X + 20), (float)(rectangulo_kpi_derecho.Y + 8));

		String^ texto_promedio_detalle = String::Format("queries per week, on average");
		graphics->DrawString(texto_promedio_detalle, fuente_etiqueta, Brushes::Black, (float)(rectangulo_kpi_derecho.X + 20), (float)(rectangulo_kpi_derecho.Y + 70));

		String^ texto_formula = String::Format("{0} records / {1} weeks", total_registros, conteo_semana->Length);
		graphics->DrawString(texto_formula, fuente_pequena, Brushes::Gray, (float)(rectangulo_kpi_derecho.X + 20), (float)(rectangulo_kpi_derecho.Y + 100));

		int n_herramientas = nombres_herramientas->Length;
		int x_barra = rectangulo_izquierdo.X + 110;
		int ancho_maximo = 300;
		int alto_barra = 28;
		int separacion = Math::Min(60, (rectangulo_izquierdo.Height - 60) / Math::Max(1, n_herramientas));

		for (int i = 0; i < n_herramientas; i++)
		{
			int y_barra = rectangulo_izquierdo.Y + 45 + i * separacion;
			int ancho_relleno_herramienta = (int)(porcentaje_herramienta[i] / 100.0 * ancho_maximo);
			SolidBrush^ pincel = gcnew SolidBrush(colores[i % colores->Length]);
			graphics->DrawString(nombres_herramientas[i], fuente_etiqueta, Brushes::Black, (float)(rectangulo_izquierdo.X + 15), (float)(y_barra + 4));
			graphics->DrawRectangle(Pens::Silver, x_barra, y_barra, ancho_maximo, alto_barra);
			graphics->FillRectangle(pincel, x_barra, y_barra, ancho_relleno_herramienta, alto_barra);

			String^ texto_barra = String::Format("{0:F0}% ({1}/{2})", porcentaje_herramienta[i], verificadas_herramienta[i], total_herramienta[i]);
			graphics->DrawString(texto_barra, fuente_etiqueta, Brushes::Black, (float)(x_barra + ancho_maximo + 8), (float)(y_barra + 4));
		}

		int n_semanas = conteo_semana->Length;
		int maximo_semana = 0;

		for (int i = 0; i < n_semanas; i++)
		{
			if (conteo_semana[i] > maximo_semana)
			{
				maximo_semana = conteo_semana[i];
			}
		}

		if (maximo_semana == 0)
		{
			maximo_semana = 1;
		}

		int origen_x = rectangulo_derecho.X + 50;
		int origen_y = rectangulo_derecho.Bottom - 50;
		int ancho_grafico = rectangulo_derecho.Width - 90;
		int alto_grafico = rectangulo_derecho.Height - 110;

		graphics->DrawLine(Pens::Black, origen_x, origen_y, origen_x + ancho_grafico, origen_y);
		graphics->DrawLine(Pens::Black, origen_x, origen_y - alto_grafico, origen_x, origen_y);
		graphics->DrawString(maximo_semana.ToString(), fuente_pequena, Brushes::Black, (float)(origen_x - 30), (float)(origen_y - alto_grafico - 8));
		graphics->DrawString("0", fuente_pequena, Brushes::Black, (float)(origen_x - 20), (float)(origen_y - 8));
		graphics->DrawString("Week of the cycle", fuente_pequena, Brushes::Gray, (float)(origen_x + ancho_grafico / 2 - 40), (float)(origen_y + 26));

		Pen^ lapiz_linea = gcnew Pen(colores[1], 3);
		int x_anterior = 0;
		int y_anterior = 0;

		for (int i = 0; i < n_semanas; i++)
		{
			int x_punto = origen_x;

			if (n_semanas > 1)
			{
				x_punto = origen_x + i * ancho_grafico / (n_semanas - 1);
			}

			int y_punto = origen_y - (int)((double)conteo_semana[i] / maximo_semana * alto_grafico);

			if (i > 0)
			{
				graphics->DrawLine(lapiz_linea, x_anterior, y_anterior, x_punto, y_punto);
			}

			graphics->FillEllipse(pincel_naranja, x_punto - 4, y_punto - 4, 8, 8);

			String^ etiqueta_semana = String::Format("W{0}", i + 1);
			graphics->DrawString(etiqueta_semana, fuente_pequena, Brushes::Black, (float)(x_punto - 10), (float)(origen_y + 6));

			x_anterior = x_punto;
			y_anterior = y_punto;
		}

		String^ texto_hallazgo = String::Format("Least verified tool: {0} ({1:F0}% of its answers were verified)", herramienta_menor, porcentaje_herramienta_menor);
		graphics->DrawString(texto_hallazgo, fuente_hallazgo, Brushes::Indigo, (float)(rectangulo_abajo.X + 15), (float)(rectangulo_abajo.Y + 25));

		String^ texto_interpretacion = "A low percentage means answers were used without checking them: there is a higher risk of relying on AI without learning.";
		graphics->DrawString(texto_interpretacion, fuente_etiqueta, Brushes::Black, (float)(rectangulo_abajo.X + 15), (float)(rectangulo_abajo.Y + 65));
	}
	private: void dibujar_marco(Graphics^ graphics, IATRACE::Rectangle marco, String^ titulo, System::Drawing::Font^ fuente)
	{
		graphics->DrawRectangle(Pens::Silver, marco);

		SizeF tamano = graphics->MeasureString(titulo, fuente);
		float x = (float)(marco.X + 10);
		float y = marco.Y - tamano.Height / 2;

		SolidBrush^ pincel_fondo = gcnew SolidBrush(this->BackColor);
		graphics->FillRectangle(pincel_fondo, x, y, tamano.Width, tamano.Height);
		graphics->DrawString(titulo, fuente, Brushes::Indigo, x, y);
	}
	};
}