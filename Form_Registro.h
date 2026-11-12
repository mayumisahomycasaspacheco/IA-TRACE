#pragma once
#include <msclr/marshal_cppstd.h>
#include "Bitacora.h"
#include "Form_Analizis.h"
namespace IATRACE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Registrar
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
			editar = false;
			idEd = -1;
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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cboCategoria;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtIA;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtConsulta;


	private: System::Windows::Forms::TextBox^ txtCambio;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ cboIA;
	private: System::Windows::Forms::ComboBox^ cboCurso;


	private: System::Windows::Forms::ComboBox^ cboValido;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnLimpiar;

	private: System::Windows::Forms::Button^ btnDetalle;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

		int idEd;
		bool editar;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Button^ btnEliminar;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ btnEditar;
		   void limpiarCampos() {
			   editar = false;
			   idEd = -1;
			   dtpFecha->Value = DateTime::Today;

			   cboCurso->SelectedIndex = 0;
			   cboCategoria->SelectedIndex = 0;
			   cboIA->SelectedIndex = 0;
			   cboValido->SelectedIndex = 0;

			   txtConsulta->Clear();
			   txtIA->Clear();
			   txtCambio->Clear();
			   txtId->Clear();
			   btnGuardar->Text = "Save";
		   }
		   std::string Convertir(System::String^ texto) {
			   return msclr::interop::marshal_as<std::string>(texto);
		   }
		   void registrarDatos() {

			   if (cboCurso->SelectedIndex == -1 ||
				   cboCategoria->SelectedIndex == -1 ||
				   cboIA->SelectedIndex == -1 ||
				   cboValido->SelectedIndex == -1 ||
				   String::IsNullOrWhiteSpace(txtConsulta->Text) ||
				   String::IsNullOrWhiteSpace(txtIA->Text) ||
				   String::IsNullOrWhiteSpace(txtCambio->Text)) {

				   MessageBox::Show("Please complete all fields.");
				   return;
			   }
			   String^ fechaTexto = dtpFecha->Value.ToString("dd/MM/yyyy", System::Globalization::CultureInfo::InvariantCulture);
			   std::string curso = Convertir(
				   cboCurso->SelectedItem->ToString()
			   );
			   Categoria_Consultada categoria =
				   static_cast<Categoria_Consultada>(
					   cboCategoria->SelectedIndex
					   );
			   std::string herramienta = Convertir(
				   cboIA->SelectedItem->ToString()
			   );
			   std::string consulta = Convertir(txtConsulta->Text);
			   std::string resultado = Convertir(txtIA->Text);

			   std::string cambio = Convertir(txtCambio->Text);
			   std::string validacion;

			   if (cboValido->SelectedIndex == 3) {
				   validacion = "No";
			   }
			   else {
				   validacion = "Yes";
			   }
			   Registro registro(
				   0,
				   Convertir(fechaTexto),
				   curso,
				   categoria,
				   herramienta,
				   consulta,
				   resultado,
				   cambio,
				   validacion
			   );

			   if (editar) {

				   if (gestor->editar(idEd, registro)) {

					   MessageBox::Show("Record updated successfully.");

					   editar = false;
					   idEd = -1;

					   btnGuardar->Text = "Save";

					   limpiarCampos();
				   }
				   else {
					   MessageBox::Show("The record could not be updated.");
				   }

			   }
			   else {

				   int idGenerado = gestor->registrar(registro);

				   MessageBox::Show(
					   String::Format("Record created successfully. ID: {0}", idGenerado)
				   );

				   limpiarCampos();
			   }
		   }

		   void cargarRegistro(Registro registro) {

			   dtpFecha->Value = DateTime::ParseExact(
				   gcnew String(registro.getfecha().c_str()),
				   "dd/MM/yyyy",
				   Globalization::CultureInfo::InvariantCulture
			   );

			   cboCurso->SelectedItem =
				   gcnew String(registro.getcurso().c_str());

			   cboCategoria->SelectedIndex =
				   static_cast<int>(registro.getcategoria());

			   cboIA->SelectedItem =
				   gcnew String(registro.getherramienta_IA().c_str());
			   txtConsulta->Text =
				   gcnew String(registro.getque_consultamos().c_str());

			   txtIA->Text =
				   gcnew String(registro.getresultado_IA().c_str());

			   txtCambio->Text =
				   gcnew String(registro.getque_se_cambio().c_str());

			   if (registro.getcomo_se_valido() == "No") {
				   cboValido->SelectedIndex = 3;
			   }
			   else {
				   cboValido->SelectedIndex = 0;
			   }
		   }
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->txtId = (gcnew System::Windows::Forms::TextBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->cboIA = (gcnew System::Windows::Forms::ComboBox());
			   this->cboCurso = (gcnew System::Windows::Forms::ComboBox());
			   this->cboValido = (gcnew System::Windows::Forms::ComboBox());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->txtCambio = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->txtIA = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->txtConsulta = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->cboCategoria = (gcnew System::Windows::Forms::ComboBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			   this->btnGuardar = (gcnew System::Windows::Forms::Button());
			   this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			   this->btnDetalle = (gcnew System::Windows::Forms::Button());
			   this->btnEditar = (gcnew System::Windows::Forms::Button());
			   this->btnEliminar = (gcnew System::Windows::Forms::Button());
			   this->groupBox1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->txtId);
			   this->groupBox1->Controls->Add(this->label9);
			   this->groupBox1->Controls->Add(this->cboIA);
			   this->groupBox1->Controls->Add(this->cboCurso);
			   this->groupBox1->Controls->Add(this->cboValido);
			   this->groupBox1->Controls->Add(this->label8);
			   this->groupBox1->Controls->Add(this->label7);
			   this->groupBox1->Controls->Add(this->label6);
			   this->groupBox1->Controls->Add(this->txtCambio);
			   this->groupBox1->Controls->Add(this->label5);
			   this->groupBox1->Controls->Add(this->txtIA);
			   this->groupBox1->Controls->Add(this->label4);
			   this->groupBox1->Controls->Add(this->txtConsulta);
			   this->groupBox1->Controls->Add(this->label3);
			   this->groupBox1->Controls->Add(this->cboCategoria);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->dtpFecha);
			   this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->groupBox1->Location = System::Drawing::Point(16, 15);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox1->Size = System::Drawing::Size(1151, 563);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"New Record";
			   // 
			   // txtId
			   // 
			   this->txtId->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->txtId->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->txtId->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtId->Location = System::Drawing::Point(523, 67);
			   this->txtId->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->txtId->Name = L"txtId";
			   this->txtId->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txtId->Size = System::Drawing::Size(205, 32);
			   this->txtId->TabIndex = 20;
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label9->Location = System::Drawing::Point(518, 39);
			   this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(32, 25);
			   this->label9->TabIndex = 19;
			   this->label9->Text = L"ID";
			   this->label9->Click += gcnew System::EventHandler(this, &Form_Registro::label9_Click);
			   // 
			   // cboIA
			   // 
			   this->cboIA->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->cboIA->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cboIA->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cboIA->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cboIA->FormattingEnabled = true;
			   this->cboIA->Location = System::Drawing::Point(844, 143);
			   this->cboIA->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->cboIA->Name = L"cboIA";
			   this->cboIA->Size = System::Drawing::Size(265, 33);
			   this->cboIA->TabIndex = 18;
			   // 
			   // cboCurso
			   // 
			   this->cboCurso->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->cboCurso->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cboCurso->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cboCurso->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cboCurso->FormattingEnabled = true;
			   this->cboCurso->Location = System::Drawing::Point(844, 65);
			   this->cboCurso->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->cboCurso->Name = L"cboCurso";
			   this->cboCurso->Size = System::Drawing::Size(265, 33);
			   this->cboCurso->TabIndex = 17;
			   // 
			   // cboValido
			   // 
			   this->cboValido->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->cboValido->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cboValido->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cboValido->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cboValido->FormattingEnabled = true;
			   this->cboValido->Location = System::Drawing::Point(745, 505);
			   this->cboValido->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->cboValido->Name = L"cboValido";
			   this->cboValido->Size = System::Drawing::Size(372, 33);
			   this->cboValido->TabIndex = 16;
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label8->Location = System::Drawing::Point(839, 116);
			   this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(73, 25);
			   this->label8->TabIndex = 14;
			   this->label8->Text = L"AI tool";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->Location = System::Drawing::Point(839, 39);
			   this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(76, 25);
			   this->label7->TabIndex = 12;
			   this->label7->Text = L"Course";
			   this->label7->Click += gcnew System::EventHandler(this, &Form_Registro::label7_Click);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(739, 478);
			   this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(187, 25);
			   this->label6->TabIndex = 10;
			   this->label6->Text = L"How it was verified";
			   // 
			   // txtCambio
			   // 
			   this->txtCambio->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->txtCambio->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->txtCambio->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtCambio->Location = System::Drawing::Point(37, 507);
			   this->txtCambio->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->txtCambio->Name = L"txtCambio";
			   this->txtCambio->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txtCambio->Size = System::Drawing::Size(691, 32);
			   this->txtCambio->TabIndex = 9;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(31, 478);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(188, 25);
			   this->label5->TabIndex = 8;
			   this->label5->Text = L"What was changed";
			   this->label5->Click += gcnew System::EventHandler(this, &Form_Registro::label5_Click);
			   // 
			   // txtIA
			   // 
			   this->txtIA->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->txtIA->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->txtIA->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtIA->Location = System::Drawing::Point(37, 366);
			   this->txtIA->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->txtIA->Multiline = true;
			   this->txtIA->Name = L"txtIA";
			   this->txtIA->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txtIA->Size = System::Drawing::Size(1080, 98);
			   this->txtIA->TabIndex = 7;
			   this->txtIA->TextChanged += gcnew System::EventHandler(this, &Form_Registro::textBox2_TextChanged);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(31, 338);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(191, 25);
			   this->label4->TabIndex = 6;
			   this->label4->Text = L"AI result (summary)";
			   // 
			   // txtConsulta
			   // 
			   this->txtConsulta->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->txtConsulta->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->txtConsulta->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtConsulta->Location = System::Drawing::Point(37, 223);
			   this->txtConsulta->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->txtConsulta->Multiline = true;
			   this->txtConsulta->Name = L"txtConsulta";
			   this->txtConsulta->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txtConsulta->Size = System::Drawing::Size(1080, 98);
			   this->txtConsulta->TabIndex = 5;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(31, 195);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(152, 25);
			   this->label3->TabIndex = 4;
			   this->label3->Text = L"What we asked";
			   // 
			   // cboCategoria
			   // 
			   this->cboCategoria->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->cboCategoria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cboCategoria->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cboCategoria->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cboCategoria->FormattingEnabled = true;
			   this->cboCategoria->Location = System::Drawing::Point(37, 143);
			   this->cboCategoria->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->cboCategoria->Name = L"cboCategoria";
			   this->cboCategoria->Size = System::Drawing::Size(265, 33);
			   this->cboCategoria->TabIndex = 3;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(31, 116);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(153, 25);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"Query category";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(31, 39);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(55, 25);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Date";
			   // 
			   // dtpFecha
			   // 
			   this->dtpFecha->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->dtpFecha->CustomFormat = L"dd/MM/yyyy";
			   this->dtpFecha->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			   this->dtpFecha->Location = System::Drawing::Point(37, 66);
			   this->dtpFecha->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->dtpFecha->Name = L"dtpFecha";
			   this->dtpFecha->Size = System::Drawing::Size(265, 32);
			   this->dtpFecha->TabIndex = 0;
			   // 
			   // btnGuardar
			   // 
			   this->btnGuardar->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnGuardar->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			   this->btnGuardar->FlatAppearance->BorderSize = 3;
			   this->btnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnGuardar->Location = System::Drawing::Point(14, 598);
			   this->btnGuardar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->btnGuardar->Name = L"btnGuardar";
			   this->btnGuardar->Size = System::Drawing::Size(237, 48);
			   this->btnGuardar->TabIndex = 1;
			   this->btnGuardar->Text = L"Save";
			   this->btnGuardar->UseVisualStyleBackColor = true;
			   this->btnGuardar->Click += gcnew System::EventHandler(this, &Form_Registro::btnGuardar_Click);
			   // 
			   // btnLimpiar
			   // 
			   this->btnLimpiar->BackColor = System::Drawing::Color::Silver;
			   this->btnLimpiar->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnLimpiar->FlatAppearance->BorderColor = System::Drawing::Color::White;
			   this->btnLimpiar->FlatAppearance->BorderSize = 3;
			   this->btnLimpiar->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnLimpiar->Location = System::Drawing::Point(272, 598);
			   this->btnLimpiar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->btnLimpiar->Name = L"btnLimpiar";
			   this->btnLimpiar->Size = System::Drawing::Size(237, 48);
			   this->btnLimpiar->TabIndex = 2;
			   this->btnLimpiar->Text = L"Clear";
			   this->btnLimpiar->UseVisualStyleBackColor = false;
			   this->btnLimpiar->Click += gcnew System::EventHandler(this, &Form_Registro::btnLimpiar_Click);
			   // 
			   // btnDetalle
			   // 
			   this->btnDetalle->BackColor = System::Drawing::Color::DarkSlateBlue;
			   this->btnDetalle->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnDetalle->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			   this->btnDetalle->FlatAppearance->BorderSize = 3;
			   this->btnDetalle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnDetalle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnDetalle->ForeColor = System::Drawing::Color::White;
			   this->btnDetalle->Location = System::Drawing::Point(896, 609);
			   this->btnDetalle->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->btnDetalle->Name = L"btnDetalle";
			   this->btnDetalle->Size = System::Drawing::Size(237, 48);
			   this->btnDetalle->TabIndex = 4;
			   this->btnDetalle->Text = L"View Details ->";
			   this->btnDetalle->UseVisualStyleBackColor = false;
			   this->btnDetalle->Click += gcnew System::EventHandler(this, &Form_Registro::btnDetalle_Click);
			   // 
			   // btnEditar
			   // 
			   this->btnEditar->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnEditar->FlatAppearance->BorderColor = System::Drawing::Color::Cyan;
			   this->btnEditar->FlatAppearance->BorderSize = 3;
			   this->btnEditar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnEditar->Location = System::Drawing::Point(14, 653);
			   this->btnEditar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->btnEditar->Name = L"btnEditar";
			   this->btnEditar->Size = System::Drawing::Size(237, 48);
			   this->btnEditar->TabIndex = 5;
			   this->btnEditar->Text = L"Edit";
			   this->btnEditar->UseVisualStyleBackColor = true;
			   this->btnEditar->Click += gcnew System::EventHandler(this, &Form_Registro::btnEditar_Click);
			   // 
			   // btnEliminar
			   // 
			   this->btnEliminar->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			   this->btnEliminar->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnEliminar->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			   this->btnEliminar->FlatAppearance->BorderSize = 3;
			   this->btnEliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnEliminar->Location = System::Drawing::Point(272, 653);
			   this->btnEliminar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnEliminar->Name = L"btnEliminar";
			   this->btnEliminar->Size = System::Drawing::Size(237, 48);
			   this->btnEliminar->TabIndex = 6;
			   this->btnEliminar->Text = L"Delete";
			   this->btnEliminar->UseVisualStyleBackColor = true;
			   this->btnEliminar->Click += gcnew System::EventHandler(this, &Form_Registro::btnEliminar_Click);
			   // 
			   // Form_Registrar
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1180, 720);
			   this->Controls->Add(this->btnEditar);
			   this->Controls->Add(this->btnDetalle);
			   this->Controls->Add(this->btnLimpiar);
			   this->Controls->Add(this->btnGuardar);
			   this->Controls->Add(this->btnEliminar);
			   this->Controls->Add(this->groupBox1);
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Name = L"Form_Registrar";
			   this->Text = L"IA-TRACE - New Record";
			   this->Load += gcnew System::EventHandler(this, &Form_Registro::Form_Registrar_Load);
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void Form_Registrar_Load(System::Object^ sender, System::EventArgs^ e) {

		// El orden de las categorias debe ser el mismo que el del enum Categoria_Consultada
		cboCategoria->Items->Add("Task");
		cboCategoria->Items->Add("Exam");
		cboCategoria->Items->Add("LB1");
		cboCategoria->Items->Add("EA1");
		cboCategoria->Items->Add("Challenge");
		cboCategoria->Items->Add("Project");
		cboCategoria->Items->Add("Theory");
		cboCategoria->Items->Add("Debugging");
		cboCategoria->Items->Add("Other");
		cboCurso->Items->Add("Algorithms");
		cboCurso->Items->Add("Mathematics");
		cboCurso->Items->Add("Physics");
		cboCurso->Items->Add("Language");
		cboCurso->Items->Add("Other");
		cboIA->Items->Add("ChatGPT");
		cboIA->Items->Add("Claude");
		cboIA->Items->Add("Gemini");
		cboIA->Items->Add("DeepSeek");
		cboIA->Items->Add("Grok");
		cboIA->Items->Add("Copilot");
		// La ultima opcion (indice 3) es la unica que cuenta como "No verificada"
		cboValido->Items->Add("I ran it and checked the result");
		cboValido->Items->Add("I checked it against reliable sources");
		cboValido->Items->Add("I reviewed it with course material");
		cboValido->Items->Add("I did not verify the answer");
		cboCategoria->SelectedIndex = 0;
		cboCurso->SelectedIndex = 0;
		cboIA->SelectedIndex = 0;
		cboValido->SelectedIndex = 0;
		editar = false;
		idEd = -1;

		btnGuardar->Text = "Save";

		groupBox1->Text = "New Record";
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarCampos();
	}
	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		registrarDatos();
	}

	private: System::Void btnGenerarDatos_Click(System::Object^ sender, System::EventArgs^ e) {
		if (gestor->obtener_cantidad() > 0) {
			MessageBox::Show("Records already exist in the logbook.");
			return;
		}

		gestor->generar_registros_aleatorios(100);

		MessageBox::Show(
			String::Format(
				"{0} records were generated successfully.",
				gestor->obtener_cantidad()
			)
		);
	}
	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (String::IsNullOrWhiteSpace(txtId->Text)) {
			MessageBox::Show("Please enter an ID.");
			return;
		}

		int idBuscado;
		if (!Int32::TryParse(txtId->Text, idBuscado)) {
			MessageBox::Show("The ID must be a number.");
			return;
		}

		Registro recuperado(0, "", "", Tarea, "", "", "", "", "");

		if (gestor->obtener_id(idBuscado, recuperado)) {
			cargarRegistro(recuperado);

			idEd = recuperado.getid();
			editar = true;

			btnGuardar->Text = "Save changes";

			MessageBox::Show("Record found. You can edit it now.");
		}
		else {
			MessageBox::Show("Record not found.");
		}
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnDetalle_Click(System::Object^ sender, System::EventArgs^ e) {
		GameJam::Form_Analizis^ detalles = gcnew GameJam::Form_Analizis(gestor);
		detalles->Show();
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtId->Text)) {
			MessageBox::Show("Please enter the ID of the record you want to delete.");
			return;
		}

		int idBuscado;
		if (!Int32::TryParse(txtId->Text, idBuscado)) {
			MessageBox::Show("The ID must be a number.");
			return;
		}

		if (gestor->eliminar(idBuscado)) {
			MessageBox::Show("Record deleted successfully.");

			if (editar && idEd == idBuscado) {
				limpiarCampos();
			}
			else
			{
				txtId->Clear();
			}
		}
		else {
			MessageBox::Show("No record was found with that ID.");
		}
	}
	};
}