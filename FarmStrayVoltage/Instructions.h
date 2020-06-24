#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#include "VoltGraph.h"
namespace FarmStrayVoltage {

	/// <summary>
	/// Summary for Instructions
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Instructions : public System::Windows::Forms::Form
	{
	public:
		Instructions(Control^ thingToShow, int form)
		{
			InitializeComponent();
			thing = thingToShow;
			whichForm = form;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Instructions()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private:
		System::Windows::Forms::Control^ thing;
		Int32 whichForm;
	private: int numRecord;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::PrintDialog^  printDialog1;


			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Instructions::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripButton1});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(706, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			this->toolStrip1->Visible = false;
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->ToolTipText = L"Print Instructions";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Instructions::toolStripButton1_Click);
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Instructions::printDocument1_PrintPage);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// Instructions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 358);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"Instructions";
			this->Text = L"Instructions";
			this->Load += gcnew System::EventHandler(this, &Instructions::Instructions_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Instructions::Instructions_FormClosed);
			this->Resize += gcnew System::EventHandler(this, &Instructions::Resizing);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		private: System::Void Instructions_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			
			this->Controls->Add(thing);
			if (thing->GetType() == RichTextBox::typeid)
			{
				if (whichForm > 0)
					this->Text = ("Form " + whichForm + " Instructions");
				else if (whichForm == 0)
					this->Text = "Settings Instructions";
				else
				{
					this->Text = "Info Instructions";
				}

				this->toolStrip1->Visible = true;
				thing->SetBounds(5,30,this->Width-20,this->Height-60);
			}
			else
			{
				this->Text = ("Graph");
				this->WindowState = FormWindowState::Maximized;
				thing->SetBounds(5,5,this->Width-20,this->Height-45);
			}
		}
	//Fired when the window is closed
	private: System::Void Instructions_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			{
				//If the object being showed is a VoltGraph
				if (thing->GetType() == VoltGraph::typeid)
				{
					VoltGraph^ beluga = (VoltGraph^)thing;
					//Undo the zoom and save bitmap
					beluga->pesgo1->PeFunction->UndoZoom();
					beluga->saveBitmap(this->Width,this->Height);
				}
			}
	private: System::Void Resizing (Object^ sender, EventArgs^ e)
	{
		if (this->toolStrip1->Visible)
			thing->SetBounds (5,30,this->Width-20,this->Height-60);
		else
			thing->SetBounds (5,5,this->Width-20,this->Height-45);
	}
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				if (this->printDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					printDocument1->PrinterSettings->PrinterName = this->printDialog1->PrinterSettings->PrinterName;
					printDocument1->Print();
				}
			 }

private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) 
		 {
			 RichTextBox^ rtb = (RichTextBox^) thing;

			 RectangleF rf = RectangleF(0,0,750,1000);
			 if (whichForm > 0)
				e->Graphics->DrawString ("Form " + whichForm + " instructions:\n\n" +rtb->Text, gcnew System::Drawing::Font ("Arial", 12, FontStyle::Regular),Brushes::Black,rf);
			 else if (whichForm == 0)
				e->Graphics->DrawString ("Settings instructions:\n\n" +rtb->Text, gcnew System::Drawing::Font ("Arial", 12, FontStyle::Regular),Brushes::Black,rf);
			 else
			 {
				e->Graphics->DrawString ("Info instructions:\n\n" +rtb->Text, gcnew System::Drawing::Font ("Arial", 12, FontStyle::Regular),Brushes::Black,rf);
			}

		 }
};
}
