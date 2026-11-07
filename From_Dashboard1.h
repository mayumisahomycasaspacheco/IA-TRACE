#pragma once

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
		From_Dashboard1(void)
		{
			InitializeComponent();
			
			//Usaremos valores de prurba por ahora skibidi

			categoria_top = "Tarea";
			cantidad_categoria_top = 38;

			curso_top = "Algoritmos";
			porcentaje_curso_top = 41;

			mes_top = "Septiembre";
			cantidad_mes_top = 52;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
			// From_Dashboard1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"From_Dashboard1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IA-TRACE - Dashboard 1: Hallazgos Principales";
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

	private: System::Void From_Dashboard1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		Graphics^ graphics = e->Graphics;

		Rectangle rectangulo_izquierdo = Rectangle(20, 40, 560, 480);
		Rectangle rectangulo_derecho = Rectangle(600, 40, 560, 480);
		Rectangle rectangulo_abajo = Rectangle(20, 550, 1140, 120);

		System::Drawing::Font^ fuente_titulo = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);

		dibujar_marco(graphics, rectangulo_izquierdo, "Registros por categoría", fuente_titulo);
		dibujar_marco(graphics, rectangulo_derecho, "Uso de IA por curso", fuente_titulo);
		graphics->DrawRectangle(Pens::Silver, rectangulo_abajo);

		String^ texto = String::Format("Categoria más usada: {0} ({1} registros)", categoria_top, cantidad_categoria_top);
		String^ texto1 = String::Format("Curso con mayor uso: {0} ({1}%)", curso_top, porcentaje_curso_top);
		String^ texto2 = String::Format("Mes de mayor uso: {0} ({1} registros)", mes_top, cantidad_mes_top);
		System::Drawing::Font^ fuente_hallazgo = gcnew System::Drawing::Font("Segoe UI", 13, FontStyle::Bold);
		graphics->DrawString(texto, fuente_hallazgo, Brushes::Indigo, (float)(rectangulo_izquierdo.X + 15), (float)(rectangulo_izquierdo.Bottom - 40));
		graphics->DrawString(texto1, fuente_hallazgo, Brushes::Indigo, (float)(rectangulo_derecho.X + 15), (float)(rectangulo_derecho.Bottom - 40));
		graphics->DrawString(texto2, fuente_hallazgo, Brushes::Indigo, (float)(rectangulo_abajo.X + 15), (float)(rectangulo_abajo.Bottom - 110));
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
