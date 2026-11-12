#pragma once
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
	/// Resumen de Form_Registro
	/// </summary>
	public ref class Form_Registro : public System::Windows::Forms::Form
	{
	public:
		Form_Registro(Bitacora* bitacora)
		{
			InitializeComponent();
			//
			// Guarda la bitacora que le pasa el menu (la misma para toda la aplicacion).
			//
			gestor = bitacora;
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

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

		int idEd;
		bool editar;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Button^ brnEliminar;
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
			// Form_Registro
			// 
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->Name = L"Form_Registro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IA-TRACE - New Record";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
