#pragma once
#include "Bitacora.h"
#include "Registro.h"
namespace IATRACE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de From_Dashboard1
	/// </summary>
	public ref class From_Dashboard1 : public System::Windows::Forms::Form
	{
	public:
		From_Dashboard1(Bitacora* gestorC)
		{
			InitializeComponent();
			gestor = gestorC;
			nombres_categoria = gcnew array<String^> {
				"Task",
					"Exam",
					"LB1",
					"EA1",
					"Challenge",
					"Project",
					"Theory",
					"Debugging",
					"Other"
			};
			conteo_categoria = gcnew array<int>(9);

			nombres_curso = gcnew array<String^> {
				"Algorithms",
					"Mathematics",
					"Physics",
					"Language",
					"Other"
			};

			conteo_curso = gcnew array<int>(5);

			nombres_mes = gcnew array<String^> {
				"January", "February", "March", "April",
					"May", "June", "July", "August",
					"September", "October", "November", "December"
			};
			conteo_mes = gcnew array<int>(12);

			colores = gcnew array<Color> {
				Color::FromArgb(37, 12, 82),
					Color::FromArgb(14, 122, 140),
					Color::FromArgb(245, 166, 35),
					Color::FromArgb(214, 0, 153),
					Color::FromArgb(94, 60, 153),
					Color::FromArgb(58, 140, 90)
			};
			actualizarEstadisticas();


		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se est n usando.
		/// </summary>
		~From_Dashboard1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del dise ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
		Bitacora* gestor;
		int total_registros;
		void actualizarEstadisticas()
		{
			for (int i = 0; i < conteo_categoria->Length; i++)
				conteo_categoria[i] = 0;

			for (int i = 0; i < conteo_curso->Length; i++)
				conteo_curso[i] = 0;

			for (int i = 0; i < conteo_mes->Length; i++)
				conteo_mes[i] = 0;

			total_registros = 0;
			total_curso = 0;

			int cantidad = gestor->obtener_cantidad();

			for (int i = 0; i < cantidad; i++)
			{
				Registro* registro = gestor->obtener_por_indice(i);

				if (registro == nullptr)
					continue;

				total_registros++;
				// categorias
				int indice_categoria =
					static_cast<int>(registro->getcategoria());

				if (indice_categoria >= 0 &&
					indice_categoria < conteo_categoria->Length)
				{
					conteo_categoria[indice_categoria]++;
				}

				// Cursos
				String^ curso = gcnew String(registro->getcurso().c_str());

				bool encontrado = false;

				for (int j = 0; j < nombres_curso->Length - 1; j++)
				{
					if (curso == nombres_curso[j])
					{
						conteo_curso[j]++;
						encontrado = true;
						break;
					}
				}
				if (!encontrado)
					conteo_curso[nombres_curso->Length - 1]++;
				String^ fecha = gcnew String(registro->getfecha().c_str());

				DateTime fechaRegistro = DateTime::ParseExact(
					fecha,
					"dd/MM/yyyy",
					System::Globalization::CultureInfo::InvariantCulture
				);

				int indice_mes = fechaRegistro.Month - 1;
				conteo_mes[indice_mes]++;
			}
			for (int i = 0; i < conteo_curso->Length; i++) {
				if (conteo_curso[i] > 0)
					total_curso += conteo_curso[i];
			}

			int indice_mayor_categoria = 0;

			for (int i = 1; i < conteo_categoria->Length; i++)
			{
				if (conteo_categoria[i] >
					conteo_categoria[indice_mayor_categoria])
				{
					indice_mayor_categoria = i;
				}
			}

			categoria_top = nombres_categoria[indice_mayor_categoria];
			cantidad_categoria_top = conteo_categoria[indice_mayor_categoria];
			int indice_mayor_curso = 0;

			for (int i = 1; i < conteo_curso->Length; i++)
			{
				if (conteo_curso[i] > conteo_curso[indice_mayor_curso])
					indice_mayor_curso = i;
			}

			curso_top = nombres_curso[indice_mayor_curso];

			if (total_curso > 0)
				porcentaje_curso_top =
				conteo_curso[indice_mayor_curso] * 100.0 / total_curso;
			else
				porcentaje_curso_top = 0;

			int indice_mayor_mes = 0;

			for (int i = 1; i < conteo_mes->Length; i++)
			{
				if (conteo_mes[i] > conteo_mes[indice_mayor_mes])
					indice_mayor_mes = i;
			}

			mes_top = nombres_mes[indice_mayor_mes];
			cantidad_mes_top = conteo_mes[indice_mayor_mes];
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M todo necesario para admitir el Dise ador. No se puede modificar
		/// el contenido de este m todo con el editor de c digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			//
			// From_Dashboard1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1400, 800);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"From_Dashboard1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IA-TRACE - Dashboard 1: Key Findings";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &From_Dashboard1::From_Dashboard1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

		String^ categoria_top;
		int cantidad_categoria_top;
		String^ curso_top;
		double porcentaje_curso_top;
		String^ mes_top;
		int cantidad_mes_top;

		array<String^>^ nombres_categoria;
		array<int>^ conteo_categoria;
		array<Color>^ colores;

		array<String^>^ nombres_curso;
		array<int>^ conteo_curso;

		array<String^>^ nombres_mes;
		array<int>^ conteo_mes;

		int total_curso;

	private: System::Void From_Dashboard1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ graphics = e->Graphics;

		System::Drawing::Rectangle rectangulo_izquierdo =
			System::Drawing::Rectangle(20, 40, 670, 530);

		System::Drawing::Rectangle rectangulo_derecho =
			System::Drawing::Rectangle(710, 40, 670, 530);

		System::Drawing::Rectangle rectangulo_abajo =
			System::Drawing::Rectangle(20, 600, 1360, 150);

		if (total_registros == 0 || cantidad_categoria_top == 0)
		{
			graphics->DrawString(
				"No records available.",
				gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Bold),
				Brushes::Gray,
				400, 300
			);
			return;
		}

		int n = conteo_categoria->Length;
		int base_y = rectangulo_izquierdo.Bottom - 90;
		int alto_maximo = rectangulo_izquierdo.Height - 160;
		int ancho_barra = 50;

		int hueco = (rectangulo_izquierdo.Width - 40 - n * ancho_barra) / (n + 1);
		int x = rectangulo_izquierdo.X + 20 + hueco;

		System::Drawing::Font^ fuente_etiqueta =
			gcnew System::Drawing::Font("Segoe UI", 8);

		StringFormat^ formato = gcnew StringFormat();
		formato->Alignment = StringAlignment::Center;
		formato->LineAlignment = StringAlignment::Near;
		formato->Trimming = StringTrimming::Word;

		for (int i = 0; i < n; i++)
		{
			int alto = (int)((double)conteo_categoria[i] / cantidad_categoria_top * alto_maximo);

			SolidBrush^ pincel = gcnew SolidBrush(colores[i % colores->Length]);
			graphics->FillRectangle(pincel, x, base_y - alto, ancho_barra, alto);

			String^ valor = conteo_categoria[i].ToString();
			SizeF tam_valor = graphics->MeasureString(valor, fuente_etiqueta);
			graphics->DrawString(
				valor,
				fuente_etiqueta,
				Brushes::Black,
				x + (ancho_barra - tam_valor.Width) / 2,
				(float)(base_y - alto - 25)
			);
			RectangleF rect_etiqueta(
				(float)(x - hueco / 2),
				(float)(base_y + 8),
				(float)(ancho_barra + hueco),
				60.0f
			);
			graphics->DrawString(
				nombres_categoria[i],
				fuente_etiqueta,
				Brushes::Black,
				rect_etiqueta,
				formato
			);

			x += ancho_barra + hueco;
		}
		System::Drawing::Rectangle caja_pastel =
			System::Drawing::Rectangle(
				rectangulo_derecho.X + 40,
				rectangulo_derecho.Y + 90,
				320,
				320
			);
		float angulo_inicio = 0;

		System::Drawing::Font^ fuente_leyenda =
			gcnew System::Drawing::Font("Segoe UI", 9);

		for (int i = 0; i < conteo_curso->Length; i++)
		{
			if (conteo_curso[i] == 0)
				continue;

			float angulo = (float)conteo_curso[i] / total_curso * 360;
			SolidBrush^ pincel_pastel = gcnew SolidBrush(colores[i % colores->Length]);
			graphics->FillPie(pincel_pastel, caja_pastel, angulo_inicio, angulo);

			double porcentaje = conteo_curso[i] * 100.0 / total_curso;
			int y_leyenda = rectangulo_derecho.Y + 110 + i * 55;

			graphics->FillRectangle(
				pincel_pastel,
				rectangulo_derecho.X + 390,
				y_leyenda,
				20,
				20
			);

			String^ texto_leyenda = String::Format("{0} - {1:F0}%", nombres_curso[i], porcentaje);
			graphics->DrawString(
				texto_leyenda,
				fuente_leyenda,
				Brushes::Black,
				(float)(rectangulo_derecho.X + 425),
				(float)y_leyenda
			);

			angulo_inicio += angulo;
		}

		System::Drawing::Font^ fuente_titulo =
			gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);

		dibujar_marco(graphics, rectangulo_izquierdo, "Records by category", fuente_titulo);
		dibujar_marco(graphics, rectangulo_derecho, "AI usage by course", fuente_titulo);
		graphics->DrawRectangle(Pens::Silver, rectangulo_abajo);

		String^ texto = String::Format("Most used category: {0} ({1} records)", categoria_top, cantidad_categoria_top);
		String^ texto1 = String::Format("Course with the most usage: {0} ({1:F0}%)", curso_top, porcentaje_curso_top);
		String^ texto2 = String::Format("Month with the most usage: {0} ({1} records)", mes_top, cantidad_mes_top);
		System::Drawing::Font^ fuente_hallazgo =
			gcnew System::Drawing::Font("Segoe UI", 13, FontStyle::Bold);

		graphics->DrawString(texto, fuente_hallazgo, Brushes::Indigo,
			(float)(rectangulo_izquierdo.X + 15),
			(float)(rectangulo_izquierdo.Bottom - 40));

		graphics->DrawString(texto1, fuente_hallazgo, Brushes::Indigo,
			(float)(rectangulo_derecho.X + 15),
			(float)(rectangulo_derecho.Bottom - 40));

		graphics->DrawString(texto2, fuente_hallazgo, Brushes::Indigo,
			(float)(rectangulo_abajo.X + 15),
			(float)(rectangulo_abajo.Y + 15));
	}

	private: void dibujar_marco(Graphics^ graphics, System::Drawing::Rectangle marco, String^ titulo, System::Drawing::Font^ fuente)
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