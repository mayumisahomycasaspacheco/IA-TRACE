#pragma once
#include <msclr/marshal_cppstd.h>
#include "Bitacora.h"
#include "From_Dashboard1.h"
#include "Form_Dashboard2.h"

namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class Form_Registro : public System::Windows::Forms::Form
	{
	private:
		Bitacora* gestor;

	public:
		Form_Registro(Bitacora* adios)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gestor = adios;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form_Registro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Numero;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Fecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Curso;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Categoria;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Herramienta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ queConsultamos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Validado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Course;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Category;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Tool;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Validate;

	protected:

	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Course = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tool = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->queConsultamos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Validate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Todos", L"Algoritmos", L"Matematica", L"Fisica",
					L"Lenguaje", L"Otros"
			});
			this->comboBox1->Location = System::Drawing::Point(61, 42);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(223, 28);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"All";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_Registro::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Todos    ", L"Tarea", L"Examen", L"LB1", L"EA1",
					L"Reto", L"Proyecto Trabajo", L"Teoria Consulta Conceptual", L"Depuracion Errores"
			});
			this->comboBox2->Location = System::Drawing::Point(305, 42);
			this->comboBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(228, 28);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->Text = L"All";
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Todos", L"ChatGPT", L"Gemini", L"Claude", L"DeepSeak",
					L"Grok", L"Copilot"
			});
			this->comboBox3->Location = System::Drawing::Point(551, 42);
			this->comboBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(208, 28);
			this->comboBox3->TabIndex = 2;
			this->comboBox3->Text = L"All";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(57, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Course";
			this->label1->Click += gcnew System::EventHandler(this, &Form_Registro::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(301, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Category";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(547, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Tool";
			this->label3->Click += gcnew System::EventHandler(this, &Form_Registro::label3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->FlatAppearance->BorderSize = 2;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(809, 36);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 38);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Look";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Registro::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button2->FlatAppearance->BorderSize = 2;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(998, 36);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 39);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Clean";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form_Registro::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Indigo;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Number,
					this->Date, this->Course, this->Category, this->Tool, this->queConsultamos, this->Validate
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(25, 96);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1104, 502);
			this->dataGridView1->TabIndex = 8;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form_Registro::dataGridView1_CellContentClick);
			this->dataGridView1->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form_Registro::dataGridView1_CellContentDoubleClick);
			// 
			// Number
			// 
			this->Number->HeaderText = L"#";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->Width = 30;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Date";
			this->Date->MinimumWidth = 6;
			this->Date->Name = L"Date";
			this->Date->Width = 125;
			// 
			// Course
			// 
			this->Course->HeaderText = L"Course";
			this->Course->MinimumWidth = 6;
			this->Course->Name = L"Course";
			this->Course->Width = 125;
			// 
			// Category
			// 
			this->Category->HeaderText = L"Category";
			this->Category->MinimumWidth = 6;
			this->Category->Name = L"Category";
			this->Category->Width = 125;
			// 
			// Tool
			// 
			this->Tool->HeaderText = L"Tool";
			this->Tool->MinimumWidth = 6;
			this->Tool->Name = L"Tool";
			this->Tool->Width = 125;
			// 
			// queConsultamos
			// 
			this->queConsultamos->HeaderText = L"Query";
			this->queConsultamos->MinimumWidth = 6;
			this->queConsultamos->Name = L"queConsultamos";
			this->queConsultamos->Width = 125;
			// 
			// Validate
			// 
			this->Validate->HeaderText = L"Validate";
			this->Validate->MinimumWidth = 6;
			this->Validate->Name = L"Validate";
			this->Validate->Width = 125;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Gold;
			this->button3->FlatAppearance->BorderSize = 2;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(920, 629);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(209, 38);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Gonna Dashboards ->";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Indigo;
			this->label4->Location = System::Drawing::Point(67, 640);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Total records:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Indigo;
			this->label5->Location = System::Drawing::Point(217, 640);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 20);
			this->label5->TabIndex = 11;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Green;
			this->label6->Location = System::Drawing::Point(472, 640);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Green;
			this->label7->Location = System::Drawing::Point(368, 640);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(71, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Verified:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(717, 640);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(591, 640);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(99, 20);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Not verified:";
			// 
			// Form_Registro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form_Registro";
			this->Text = L"Form_Registro";
			this->Load += gcnew System::EventHandler(this, &Form_Registro::Form_Registro_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::String^ CategoriaToString(Categoria_Consultada hola) {
		switch (hola) {
		case Tarea: return "Task";
		case Examen: return "Exam";
		case LB1: return "LB1";
		case EA1: return "EA1";
		case Reto: return "Challenge";
		default: return "Other";
		}
	}
	private: void CargarDatos() {
		dataGridView1->Rows->Clear();

		int total = 0;
		int verificados = 0;
		int noVerificados = 0;

		String^ filtroCurso;
		filtroCurso = comboBox1->SelectedItem->ToString()->Trim();

		String^ filtroCategoria;
		filtroCategoria = comboBox2->SelectedItem->ToString()->Trim();

		String^ filtroHerramienta;
		filtroHerramienta = comboBox3->SelectedItem->ToString()->Trim();


		int tamaño = gestor->obtener_cantidad();
		for (int i = 0; i < tamaño; i++) {

			Registro* registro = gestor->obtener_por_indice(i);
			if (registro == nullptr) continue;

			//String^ curso = gcnew String(registro->getCurso().c_str());
			//String^ categoria = CategoriaToString(registro->getCategoria());
			//String^ herramienta = gcnew String(registro->getHerramientaIA().c_str());
			//
			////honestamente no estoy muy seguro de si esto se valida correctamente
			//String^ temp;
			//if (registro->getComoSeValido() == "Verificado") {
			//	temp = "Verificado";
			//}
			//else {
			//	temp = "No Verificado";
			//}
			////
			//String^ validado = gcnew String(registro->getComoSeValido().c_str());

			String^ curso = msclr::interop::marshal_as<String^>(registro->getcurso());
			String^ categoria = CategoriaToString(registro->getcategoria());
			String^ herramienta = msclr::interop::marshal_as<String^>(registro->getherramienta_IA());
			String^ validadoNativo = msclr::interop::marshal_as<String^>(registro->getcomo_se_valido());
			String^ textoValidado;
			if (validadoNativo->Equals("SI")) {
				textoValidado = "Verificado";
			}
			else {
				textoValidado = "No Verificado";
			}

			//se valida si se muestra en todos, o si se muestra dentro del filtro que se pueda aplicar
			bool coincideCurso = false;
			bool coincideCategoria = false;
			bool coincideHerramienta = false;


			//if (filtroCurso == "Todos" || curso == filtroCurso) {
			//	coincideCurso = true;
			//}
			//if (filtroCategoria == "Todos" || categoria == filtroCategoria) {
			//	coincideCategoria = true;
			//}
			//if (filtroHerramienta == "Todos" || herramienta == filtroHerramienta) {
			//	coincideHerramienta = true;
			//}

			if (filtroCurso->Equals("Todos") || curso->Equals(filtroCurso)) {
				coincideCurso = true;
			}
			if (filtroCategoria->Equals("Todos") || categoria->Equals(filtroCategoria)) {
				coincideCategoria = true;
			}
			if (filtroHerramienta->Equals("Todos") || herramienta->Equals(filtroHerramienta)) {
				coincideHerramienta = true;
			}

			//ahora q ya pasaron los filtros, recien se dibuja

			if (coincideCategoria && coincideCurso && coincideHerramienta) {
				dataGridView1->Rows->Add(
					registro->getid(),
					msclr::interop::marshal_as<String^>(registro->getfecha()),
					curso,
					categoria,
					herramienta,
					msclr::interop::marshal_as<String^>(registro->getque_consultamos()),
					textoValidado
				);
				total++;
				if (textoValidado->Equals("Verificado")) {
					verificados++;
				}
				else {
					noVerificados++;
				}
			}
		}
		label5->Text = total.ToString();
		label6->Text = verificados.ToString();
		label8->Text = noVerificados.ToString();
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
	private: System::Void Form_Registro_Load(System::Object^ sender, System::EventArgs^ e) {
		//para cuando se carguen los datos al inicio
		comboBox1->SelectedIndex = 0;
		comboBox2->SelectedIndex = 0;
		comboBox3->SelectedIndex = 0;
		CargarDatos();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CargarDatos();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->SelectedIndex = 0;
		comboBox2->SelectedIndex = 0;
		comboBox3->SelectedIndex = 0;
		CargarDatos();
		MessageBox::Show("Tamaño del gestor: " + gestor->obtener_cantidad().ToString(), "Debug");
	}
	private: System::Void dataGridView1_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}