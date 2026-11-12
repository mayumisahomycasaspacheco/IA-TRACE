#pragma once

namespace IATRACE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Instrucciones
	/// </summary>
	public ref class Form_Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Form_Instrucciones(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se están usando.
		/// </summary>
		~Form_Instrucciones()
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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de codigo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_Instrucciones::typeid));
			this->SuspendLayout();
			// 
			// Form_Instrucciones
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form_Instrucciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IA-TRACE - Instructions";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}