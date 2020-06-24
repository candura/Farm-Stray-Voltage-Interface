#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FarmStrayVoltage {

	/// <summary>
	/// Summary for InfoBox
	/// </summary>
	public ref class InfoBox : public System::Windows::Forms::UserControl
	{
	public:
		InfoBox(void)
		{
			InitializeComponent();
			onRight = true;
			//
			//TODO: Add the constructor code here
			//
		}
		InfoBox(double xVal)
		{
			InitializeComponent();
			x = xVal;
			grabbed = false;
			onRight = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InfoBox()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  ch1i;
	protected: 
	public: System::Windows::Forms::Label^  ch3v;
	public: System::Windows::Forms::Label^  ch2v;
	public: System::Windows::Forms::Label^  ch1v;
	private: System::Windows::Forms::Label^  label4;
	public: 
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Button^  esc;
	private: System::Boolean onRight;
	private: 

	private: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		double x; //x is the graphical X value where the tipper is located and showing the corresponding Y values

	public: System::Windows::Forms::Label^  dateText;
	private: 

			 System::Boolean grabbed; //Whether or not the user has gabbed the tipper

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoBox::typeid));
			this->ch1i = (gcnew System::Windows::Forms::Label());
			this->ch3v = (gcnew System::Windows::Forms::Label());
			this->ch2v = (gcnew System::Windows::Forms::Label());
			this->ch1v = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->esc = (gcnew System::Windows::Forms::Button());
			this->dateText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ch1i
			// 
			this->ch1i->AutoSize = true;
			this->ch1i->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ch1i->Location = System::Drawing::Point(40, 88);
			this->ch1i->Name = L"ch1i";
			this->ch1i->Size = System::Drawing::Size(0, 12);
			this->ch1i->TabIndex = 15;
			// 
			// ch3v
			// 
			this->ch3v->AutoSize = true;
			this->ch3v->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ch3v->Location = System::Drawing::Point(40, 67);
			this->ch3v->Name = L"ch3v";
			this->ch3v->Size = System::Drawing::Size(0, 12);
			this->ch3v->TabIndex = 16;
			// 
			// ch2v
			// 
			this->ch2v->AutoSize = true;
			this->ch2v->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ch2v->Location = System::Drawing::Point(40, 46);
			this->ch2v->Name = L"ch2v";
			this->ch2v->Size = System::Drawing::Size(0, 12);
			this->ch2v->TabIndex = 13;
			// 
			// ch1v
			// 
			this->ch1v->AutoSize = true;
			this->ch1v->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ch1v->Location = System::Drawing::Point(40, 25);
			this->ch1v->Name = L"ch1v";
			this->ch1v->Size = System::Drawing::Size(0, 12);
			this->ch1v->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 12);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Vps:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 12);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Vs:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 12);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Vp:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 12);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Vcc:";
			// 
			// esc
			// 
			this->esc->AutoSize = true;
			this->esc->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"esc.Image")));
			this->esc->Location = System::Drawing::Point(100, 0);
			this->esc->Name = L"esc";
			this->esc->Size = System::Drawing::Size(20, 17);
			this->esc->TabIndex = 17;
			this->esc->Click += gcnew System::EventHandler(this, &InfoBox::esc_Click);
			// 
			// dateText
			// 
			this->dateText->AutoSize = true;
			this->dateText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dateText->Location = System::Drawing::Point(3, 4);
			this->dateText->Name = L"dateText";
			this->dateText->Size = System::Drawing::Size(0, 12);
			this->dateText->TabIndex = 14;
			// 
			// InfoBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->esc);
			this->Controls->Add(this->ch1i);
			this->Controls->Add(this->ch3v);
			this->Controls->Add(this->ch2v);
			this->Controls->Add(this->dateText);
			this->Controls->Add(this->ch1v);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"InfoBox";
			this->Size = System::Drawing::Size(122, 107);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: System::Double getX ()
		{
			return x;
		}
		public: System::Boolean isGrabbed()
		{
			return grabbed;
		}
		public: System::Void gotGrabbed()
		{
			grabbed = true;
		}
		public: System::Void gotDropped()
		{
			grabbed = false;
		}
		private: System::Void esc_Click (System:: Object^ sender, System::EventArgs^ e)
		{
			this->Enabled = false;
			this->Visible = false;
		}
		public: System::Boolean isOnRight ()
		{
			return onRight;
		}
		public: System::Void switchOnRight ()
		{
			onRight = !onRight;
		}
};
}
