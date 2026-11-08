#pragma once

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
		Form_Dashboard2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
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
		System::ComponentModel::Container ^components;

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
			this->ClientSize = System::Drawing::Size(1162, 673);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form_Dashboard2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form_Dashboard2";
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

	private: void calculra_indicadores()
	{
		total_registros = 0;
		total_verificadas = 0;

		int n = nombres_herramientas->Length;
		porcentaje_herramienta = gcnew array<double>(n);

		for (int i = 0; i < n; i++)
		{
			total_registros += total_herramienta[i];
			total_verificadas += verificadas_herramienta[i];

			if (total_herramienta[i] > 0)
			{
				porcentaje_herramienta[i] = verificadas_herramienta[i] * 100.0 / total_herramienta[i];
			}

			else
			{
				porcentaje_herramienta[i] = 0;
			}
		}

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
			graphics->DrawString("Sin registros: registra o genera datos para ver las métricas.", fuente_hallazgo, Brushes::Indigo, 40.0f, 60.0f);
			return;
		}

		Rectangle rectangulo_kpi_izquierdo = Rectangle(20, 40, 560, 130);
		Rectangle rectangulo_kpi_derecho = Rectangle(600, 40, 560, 130);
		Rectangle rectangulo_izquierdo = Rectangle(20, 200, 560, 330);
		Rectangle rectangulo_derecho = Rectangle(600, 200, 560, 330);
		Rectangle rectangulo_abajo = Rectangle(20, 560, 1140, 120);

		dibujar_marco(graphics, rectangulo_kpi_izquierdo, "Respuestas verificadas (global)", fuente_titulo);
		dibujar_marco(graphics, rectangulo_kpi_derecho, "Promedio de consultas por semana", fuente_titulo);
		dibujar_marco(graphics, rectangulo_izquierdo, "% verificadas por herramienta de IA", fuente_titulo);
		dibujar_marco(graphics, rectangulo_abajo, "Hallazgo", fuente_titulo);
	}

	 private: void dibujar_marco(Graphics^ graphics, Rectangle marco, String^ titulo, System::Drawing::Font^ fuente)
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