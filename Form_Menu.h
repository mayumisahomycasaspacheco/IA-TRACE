#pragma once
#include "From_Dashboard1.h"

namespace IATRACE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Menu
	/// </summary>
	public ref class Form_Menu : public System::Windows::Forms::Form
	{
	public:
		Form_Menu(void)
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
		~Form_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_registro;
	private: System::Windows::Forms::Button^ button_detalle;
	private: System::Windows::Forms::Button^ button_dashboard1;

	private: System::Windows::Forms::Button^ button_dashboard2;
	private: System::Windows::Forms::Button^ button_dashboard3;
	private: System::Windows::Forms::Button^ button_generar;
	private: System::Windows::Forms::Button^ button_instrucciones;
	private: System::Windows::Forms::Button^ button_creadores;
	private: System::Windows::Forms::Button^ button_salir;

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_Menu::typeid));
			this->button_registro = (gcnew System::Windows::Forms::Button());
			this->button_detalle = (gcnew System::Windows::Forms::Button());
			this->button_dashboard1 = (gcnew System::Windows::Forms::Button());
			this->button_dashboard2 = (gcnew System::Windows::Forms::Button());
			this->button_dashboard3 = (gcnew System::Windows::Forms::Button());
			this->button_generar = (gcnew System::Windows::Forms::Button());
			this->button_instrucciones = (gcnew System::Windows::Forms::Button());
			this->button_creadores = (gcnew System::Windows::Forms::Button());
			this->button_salir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_registro
			// 
			this->button_registro->BackColor = System::Drawing::Color::Black;
			this->button_registro->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_registro->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_registro->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_registro->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_registro->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_registro->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_registro->Location = System::Drawing::Point(50, 76);
			this->button_registro->Name = L"button_registro";
			this->button_registro->Size = System::Drawing::Size(325, 53);
			this->button_registro->TabIndex = 0;
			this->button_registro->Text = L"Registro de bitácora";
			this->button_registro->UseVisualStyleBackColor = false;
			this->button_registro->Click += gcnew System::EventHandler(this, &Form_Menu::button_registro_Click);
			// 
			// button_detalle
			// 
			this->button_detalle->BackColor = System::Drawing::Color::Black;
			this->button_detalle->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_detalle->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_detalle->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_detalle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_detalle->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_detalle->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_detalle->Location = System::Drawing::Point(50, 135);
			this->button_detalle->Name = L"button_detalle";
			this->button_detalle->Size = System::Drawing::Size(325, 53);
			this->button_detalle->TabIndex = 1;
			this->button_detalle->Text = L"Detalle y análisis";
			this->button_detalle->UseVisualStyleBackColor = false;
			this->button_detalle->Click += gcnew System::EventHandler(this, &Form_Menu::button_detalle_Click);
			// 
			// button_dashboard1
			// 
			this->button_dashboard1->BackColor = System::Drawing::Color::Black;
			this->button_dashboard1->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_dashboard1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_dashboard1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_dashboard1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_dashboard1->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_dashboard1->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_dashboard1->Location = System::Drawing::Point(50, 194);
			this->button_dashboard1->Name = L"button_dashboard1";
			this->button_dashboard1->Size = System::Drawing::Size(325, 53);
			this->button_dashboard1->TabIndex = 2;
			this->button_dashboard1->Text = L"Dashboard 1";
			this->button_dashboard1->UseVisualStyleBackColor = false;
			this->button_dashboard1->Click += gcnew System::EventHandler(this, &Form_Menu::button_dashboard1_Click);
			// 
			// button_dashboard2
			// 
			this->button_dashboard2->BackColor = System::Drawing::Color::Black;
			this->button_dashboard2->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_dashboard2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_dashboard2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_dashboard2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_dashboard2->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_dashboard2->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_dashboard2->Location = System::Drawing::Point(50, 253);
			this->button_dashboard2->Name = L"button_dashboard2";
			this->button_dashboard2->Size = System::Drawing::Size(325, 53);
			this->button_dashboard2->TabIndex = 3;
			this->button_dashboard2->Text = L"Dashboard 2";
			this->button_dashboard2->UseVisualStyleBackColor = false;
			this->button_dashboard2->Click += gcnew System::EventHandler(this, &Form_Menu::button_dashboard2_Click);
			// 
			// button_dashboard3
			// 
			this->button_dashboard3->BackColor = System::Drawing::Color::Black;
			this->button_dashboard3->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_dashboard3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_dashboard3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_dashboard3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_dashboard3->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_dashboard3->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_dashboard3->Location = System::Drawing::Point(50, 312);
			this->button_dashboard3->Name = L"button_dashboard3";
			this->button_dashboard3->Size = System::Drawing::Size(325, 53);
			this->button_dashboard3->TabIndex = 4;
			this->button_dashboard3->Text = L"Dashboard 3";
			this->button_dashboard3->UseVisualStyleBackColor = false;
			this->button_dashboard3->Click += gcnew System::EventHandler(this, &Form_Menu::button_dashboard3_Click);
			// 
			// button_generar
			// 
			this->button_generar->BackColor = System::Drawing::Color::Black;
			this->button_generar->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_generar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_generar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_generar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_generar->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_generar->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_generar->Location = System::Drawing::Point(50, 371);
			this->button_generar->Name = L"button_generar";
			this->button_generar->Size = System::Drawing::Size(325, 53);
			this->button_generar->TabIndex = 5;
			this->button_generar->Text = L"Generar datos de prueba";
			this->button_generar->UseVisualStyleBackColor = false;
			this->button_generar->Click += gcnew System::EventHandler(this, &Form_Menu::button_generar_Click);
			// 
			// button_instrucciones
			// 
			this->button_instrucciones->BackColor = System::Drawing::Color::Black;
			this->button_instrucciones->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_instrucciones->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_instrucciones->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_instrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_instrucciones->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_instrucciones->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_instrucciones->Location = System::Drawing::Point(50, 430);
			this->button_instrucciones->Name = L"button_instrucciones";
			this->button_instrucciones->Size = System::Drawing::Size(325, 53);
			this->button_instrucciones->TabIndex = 6;
			this->button_instrucciones->Text = L"Instrucciones";
			this->button_instrucciones->UseVisualStyleBackColor = false;
			this->button_instrucciones->Click += gcnew System::EventHandler(this, &Form_Menu::button_instrucciones_Click);
			// 
			// button_creadores
			// 
			this->button_creadores->BackColor = System::Drawing::Color::Black;
			this->button_creadores->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_creadores->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_creadores->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_creadores->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_creadores->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_creadores->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_creadores->Location = System::Drawing::Point(50, 489);
			this->button_creadores->Name = L"button_creadores";
			this->button_creadores->Size = System::Drawing::Size(325, 53);
			this->button_creadores->TabIndex = 7;
			this->button_creadores->Text = L"Creadores";
			this->button_creadores->UseVisualStyleBackColor = false;
			this->button_creadores->Click += gcnew System::EventHandler(this, &Form_Menu::button_creadores_Click);
			// 
			// button_salir
			// 
			this->button_salir->BackColor = System::Drawing::Color::Black;
			this->button_salir->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button_salir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button_salir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button_salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_salir->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_salir->ForeColor = System::Drawing::Color::PaleGoldenrod;
			this->button_salir->Location = System::Drawing::Point(50, 548);
			this->button_salir->Name = L"button_salir";
			this->button_salir->Size = System::Drawing::Size(325, 53);
			this->button_salir->TabIndex = 8;
			this->button_salir->Text = L"Salir";
			this->button_salir->UseVisualStyleBackColor = false;
			this->button_salir->Click += gcnew System::EventHandler(this, &Form_Menu::button_salir_Click);
			// 
			// Form_Menu
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1162, 673);
			this->Controls->Add(this->button_salir);
			this->Controls->Add(this->button_creadores);
			this->Controls->Add(this->button_instrucciones);
			this->Controls->Add(this->button_generar);
			this->Controls->Add(this->button_dashboard3);
			this->Controls->Add(this->button_dashboard2);
			this->Controls->Add(this->button_dashboard1);
			this->Controls->Add(this->button_detalle);
			this->Controls->Add(this->button_registro);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form_Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IA-TRACE - Menú principal";
			this->ResumeLayout(false);

		}
#pragma endregion

//Cambiar con el nombre de su form segun corresponda

private: System::Void button_registro_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_detalle_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_dashboard1_Click(System::Object^ sender, System::EventArgs^ e)
{
	From_Dashboard1^ ventana = gcnew From_Dashboard1();
	ventana->ShowDialog();
}
private: System::Void button_dashboard2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_dashboard3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_generar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_instrucciones_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_creadores_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Modulo en construccion");
}
private: System::Void button_salir_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
};
}
