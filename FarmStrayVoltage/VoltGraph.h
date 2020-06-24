#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Gigasoft::ProEssentials::Enums;
#include "InfoBox.h"

namespace FarmStrayVoltage {

	/// <summary>
	/// Summary for VoltGraph
	/// </summary>
	public ref class VoltGraph : public System::Windows::Forms::UserControl
	{
	public:

		VoltGraph(int num)
		{
			InitializeComponent();

			a=0;
			this->Controls->Add (tipper1);
			tipper1->BringToFront();
			whichForm = num;		
			this->Resize += gcnew EventHandler (this, &VoltGraph::Resizing);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VoltGraph()
		{
			if (components)
			{
				delete components;
			}
		}

	private: InfoBox^  tipper1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		public: Gigasoft::ProEssentials::Pesgo^  pesgo1;
		System::ComponentModel::Container ^components;
		public: int a;
		private: DateTime before;
		private: int numRecord;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: int whichForm;
	private: System::Windows::Forms::CheckBox^  vccCheck;
	private: System::Windows::Forms::CheckBox^  vpCheck;
	private: System::Windows::Forms::CheckBox^  vsCheck;
	private: System::Windows::Forms::CheckBox^  vpsCheck;

	private: int activeTip;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VoltGraph::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->vccCheck = (gcnew System::Windows::Forms::CheckBox());
			this->vpCheck = (gcnew System::Windows::Forms::CheckBox());
			this->vsCheck = (gcnew System::Windows::Forms::CheckBox());
			this->vpsCheck = (gcnew System::Windows::Forms::CheckBox());
			this->tipper1 = (gcnew FarmStrayVoltage::InfoBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 30);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VoltGraph::button1_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(39, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 3;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &VoltGraph::button2_Click);
			// 
			// vccCheck
			// 
			this->vccCheck->AutoSize = true;
			this->vccCheck->Checked = true;
			this->vccCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->vccCheck->Location = System::Drawing::Point(88, 10);
			this->vccCheck->Name = L"vccCheck";
			this->vccCheck->Size = System::Drawing::Size(45, 17);
			this->vccCheck->TabIndex = 4;
			this->vccCheck->Text = L"Vcc";
			this->vccCheck->UseVisualStyleBackColor = true;
			this->vccCheck->CheckedChanged += gcnew System::EventHandler(this, &VoltGraph::vccCheck_CheckedChanged);
			// 
			// vpCheck
			// 
			this->vpCheck->AutoSize = true;
			this->vpCheck->Checked = true;
			this->vpCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->vpCheck->Location = System::Drawing::Point(139, 10);
			this->vpCheck->Name = L"vpCheck";
			this->vpCheck->Size = System::Drawing::Size(39, 17);
			this->vpCheck->TabIndex = 4;
			this->vpCheck->Text = L"Vp";
			this->vpCheck->UseVisualStyleBackColor = true;
			this->vpCheck->CheckedChanged += gcnew System::EventHandler(this, &VoltGraph::vpCheck_CheckedChanged);
			// 
			// vsCheck
			// 
			this->vsCheck->AutoSize = true;
			this->vsCheck->Checked = true;
			this->vsCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->vsCheck->Location = System::Drawing::Point(190, 11);
			this->vsCheck->Name = L"vsCheck";
			this->vsCheck->Size = System::Drawing::Size(38, 17);
			this->vsCheck->TabIndex = 4;
			this->vsCheck->Text = L"Vs";
			this->vsCheck->UseVisualStyleBackColor = true;
			this->vsCheck->CheckedChanged += gcnew System::EventHandler(this, &VoltGraph::vsCheck_CheckedChanged);
			// 
			// vpsCheck
			// 
			this->vpsCheck->AutoSize = true;
			this->vpsCheck->Checked = true;
			this->vpsCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->vpsCheck->Location = System::Drawing::Point(241, 11);
			this->vpsCheck->Name = L"vpsCheck";
			this->vpsCheck->Size = System::Drawing::Size(44, 17);
			this->vpsCheck->TabIndex = 4;
			this->vpsCheck->Text = L"Vps";
			this->vpsCheck->UseVisualStyleBackColor = true;
			this->vpsCheck->CheckedChanged += gcnew System::EventHandler(this, &VoltGraph::vpsCheck_CheckedChanged);
			// 
			// tipper1
			// 
			this->tipper1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->tipper1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->tipper1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tipper1->Location = System::Drawing::Point(494, 190);
			this->tipper1->Name = L"tipper1";
			this->tipper1->Size = System::Drawing::Size(123, 107);
			this->tipper1->TabIndex = 1;
			this->tipper1->Visible = false;
			// 
			// VoltGraph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->vpsCheck);
			this->Controls->Add(this->vsCheck);
			this->Controls->Add(this->vpCheck);
			this->Controls->Add(this->vccCheck);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tipper1);
			this->Name = L"VoltGraph";
			this->Size = System::Drawing::Size(701, 348);
			this->Load += gcnew System::EventHandler(this, &VoltGraph::VoltGraph_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		
		public: System::Void VoltGraph_Load(System::Object^  sender, System::EventArgs^  e)
		{
			this->InitializeComponent();	
			tipper1->Controls->Remove(tipper1->esc);
			tipper1->Visible = false;		
		}
		
private: System::Void pesgo1_MouseEnter (System::Object^ sender, System::EventArgs^ e) 
		{
			tipper1->Visible = true;
			tipper1->Location = this->MousePosition;
			tipper1->BringToFront();
			tipper1->Show();
		}
		//If the mouse leaves the graph, make tipper invisible
		private: System::Void graph1_mouseLeave (System::Object^ sender, System::EventArgs^ e)
		{
			this->tipper1->Visible = false;
					 
		}//MouseLeave

		//This function will activate when the mouse moves inside the graph		 
		private: System::Void graph1_mouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			System::Drawing::Point tp; //point of tipper (tp)
			this->pesgo1->Focus();		
			tp.X = e->Location.X+20;
			tp.Y = e->Location.Y + 5;
			tipper1->Location = tp; 
			TipperMan ();
		}//MouseMove

		//TipperMan gets the mouse's location, and then will convert it to graphical coordinates and change the tipper's values
		private: System::Void TipperMan ()
		{
			System::Drawing::Point p; //Point of mouse
			Int32 nA, nX, nY;
			Double fX=0, fY=0;
			p = this->pesgo1->PeUserInterface->Cursor->LastMouseMove; //Where the mouse is located
			nA=0;
			nX=p.X;
			nY=p.Y;
			this->pesgo1->PeFunction->ConvPixelToGraph( *&nA, *&nX, *&nY, *&fX, *&fY, false, false, false); //Converting the coordinates to grid x&y values
			//Y values for all 4 channels;
			float sub1Y, sub2Y, sub3Y, sub4Y;
			float normalX; //The normalized x-axis length

			//Normalizes the X values to increase by one
			normalX = (float)((this->pesgo1->PeData->Xii[0,(numRecord*this->pesgo1->PeData->Subsets-1)] - this->pesgo1->PeData->Xii[0,0])/numRecord);
			
			//Finding where the mouse is in terms of time since first record (uses normalized x-axis numbers
			fX = fX - this->pesgo1->PeData->Xii[0,0]; //
			fX = fX / normalX;
			//If the mouse is in the grid

			if (fX >=0 && fX<=numRecord)
			{
			
			//Set all 18 subsets with their Y values respective to where the mouse is
			sub1Y = Math::Round(this->pesgo1->PeData->Y[0,fX],2);
			sub2Y = Math::Round(this->pesgo1->PeData->Y[1,fX],2);
			sub3Y = Math::Round(this->pesgo1->PeData->Y[2,fX],2);
			sub4Y = Math::Round(this->pesgo1->PeData->Y[3,fX],2);

			//Put all the subsets in the correct channel
			String^ s1v = System::String::Concat (sub1Y, " V");
			String^ s2v = System::String::Concat (sub2Y, " V");
			String^ s3v = System::String::Concat (sub3Y, " V");
			String^ s1i = System::String::Concat (sub4Y, " V");

			//Change the tipper text to show the values of all the different channels
			this->tipper1->ch1v->Text = s1v;
			this->tipper1->ch2v->Text = s2v;
			this->tipper1->ch3v->Text = s3v;
			this->tipper1->ch1i->Text = s1i;
			DateTime xDate = DateTime(1899,12,30);
			xDate = xDate.AddDays(this->pesgo1->PeData->Xii[0,fX]);
			this->tipper1->dateText->Text = xDate.ToString("MM/dd HH:mm:ss");
			}
		}//TipperMan
		//Accepts in two arrays of data and enters it into the graph to plot
		public: System::Void DrawGraph (array<double>^ xVal,array<float>^ yVal)
		{
			Gigasoft::ProEssentials::Api::PEvsetW(this->pesgo1->PeSpecial->HObject, Gigasoft::ProEssentials::DllProperties::YData, yVal, numRecord * this->pesgo1->PeData->Subsets);
			Gigasoft::ProEssentials::Api::PEvsetW(this->pesgo1->PeSpecial->HObject, Gigasoft::ProEssentials::DllProperties::XDataII, xVal, numRecord * this->pesgo1->PeData->Subsets);

		}
		//This method is for other classes to set the private integer number of records
		public: System::Void SetNumRecord (int num)
		{
			numRecord = num;
			
			this->pesgo1 = (gcnew Gigasoft::ProEssentials::Pesgo());
			// 
			// pesgo1
			// 
			this->pesgo1->PeData->DateTimeMode = true; //So X Axis will have times
			this->pesgo1->PeData->UsingXDataii = true; //Using double precision XDataii
			this->pesgo1->Location = System::Drawing::Point(3, 3);
			this->pesgo1->Name = L"pesgo1";

			this->pesgo1->SetBounds (0,0,this->Width, this->Height-20);
			this->pesgo1->TabIndex = 0;
			this->pesgo1->Text = L"pesgo1";
			//Line Graph
			pesgo1->PePlot->Method = Gigasoft::ProEssentials::Enums::SGraphPlottingMethod::Line;
			pesgo1->PeFont->FontSize = Gigasoft::ProEssentials::Enums::FontSize::Large;
			pesgo1->PeColor->GraphForeground = System::Drawing::Color::LightGray;
			pesgo1->PeGrid->Style = GridStyle::Dot;
			//Zoom zoom
			pesgo1->PeUserInterface->Allow->Zooming = Gigasoft::ProEssentials::Enums::AllowZooming::HorzAndVert;
			pesgo1->PeUserInterface->Allow->ZoomStyle = Gigasoft::ProEssentials::Enums::ZoomStyle::FramedRect;

			this->pesgo1->MouseEnter += gcnew System::EventHandler(this, &VoltGraph::pesgo1_MouseEnter);
			this->pesgo1->MouseLeave += gcnew System::EventHandler(this, &VoltGraph::graph1_mouseLeave);

			this->pesgo1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VoltGraph::graph1_mouseMove);
			this->pesgo1->AllowDrop = true;
			this->pesgo1->PeAnnotation->Show = true;
			this->pesgo1->Cursor = System::Windows::Forms::Cursors::Cross;							
			this->pesgo1->PeData->NullDataValueX = -1;
			this->pesgo1->PeData->NullDataValue = -1;

			this->pesgo1->PePlot->SubsetColors[0] = Color::Red;
			this->pesgo1->PePlot->SubsetColors[1] = Color::Blue;
			this->pesgo1->PePlot->SubsetColors[2] = Color::Yellow;
			this->pesgo1->PePlot->SubsetColors[3] = Color::Green;
			this->pesgo1->PeUserInterface->Dialog->Page1 = false;
			this->pesgo1->PeUserInterface->Dialog->Page2 = false;
            this->pesgo1->PeUserInterface->Dialog->PlotCustomization = false;
            this->pesgo1->PeUserInterface->Dialog->Style = false;
            this->pesgo1->PeUserInterface->Dialog->Font = false;
            this->pesgo1->PeUserInterface->Dialog->Subsets = false;
            this->pesgo1->PeUserInterface->Dialog->Color = false;
			this->pesgo1->PeUserInterface->Dialog->Axis = false;
            this->pesgo1->PeUserInterface->Menu->Show = false;
			this->pesgo1->PeZoomIn += gcnew Gigasoft::ProEssentials::Pesgo::ZoomInEventHandler (this, &VoltGraph::peZoomIn);
			this->pesgo1->PeZoomOut += gcnew Gigasoft::ProEssentials::Pesgo::ZoomOutEventHandler (this, &VoltGraph::peZoomOut);
						pesgo1->PeData->Subsets = 4;
						pesgo1->PePlot->SubsetLineTypes[0] = Gigasoft::ProEssentials::Enums::LineType::ThinSolid;
						pesgo1->PePlot->SubsetLineTypes[1] = Gigasoft::ProEssentials::Enums::LineType::ThinSolid;
			pesgo1->PePlot->SubsetLineTypes[2] = Gigasoft::ProEssentials::Enums::LineType::ThinSolid;
			pesgo1->PePlot->SubsetLineTypes[3] = Gigasoft::ProEssentials::Enums::LineType::ThinSolid;
			pesgo1->PeConfigure->PrepareImages = true;
			pesgo1->PeConfigure->CacheBmp = true;
			pesgo1->PeConfigure->RenderEngine = Gigasoft::ProEssentials::Enums::RenderEngine::GdiPlus;
					 pesgo1->PeData->SubsetsToShow[0] = 1;
			 pesgo1->PeData->SubsetsToShow[1] = 1;
			  pesgo1->PeData->SubsetsToShow[2] = 1;
			  pesgo1->PeData->SubsetsToShow[3] = 1;
			pesgo1->PeData->DateTimeMilliSeconds = true;
			this->Controls->Add(this->pesgo1);			
			pesgo1->PeData->Points = num;
			pesgo1->SendToBack();
		}
		private: System::Void peZoomIn (Object^ sender, EventArgs^ e)
		{
			this->button2->Enabled = true;
			this->button2->BringToFront();
		}
		private: System::Void peZoomOut (Object^ sender, EventArgs^ e)
		{
			this->button2->Enabled = false;
			this->button2->BringToFront();
		}
		public: System::Void saveBitmap (int w, int h)
		{

			pesgo1->PeString->SubTitle = "";

			String^ filePath = System::Windows::Forms::Application::ExecutablePath->Remove(System::Windows::Forms::Application::ExecutablePath->LastIndexOf('\\')+1);	

			if (whichForm == 0)
			{
				pesgo1->PeFunction->Image->BitmapToFile(w,h,filePath+"bitmap\\Form2Graph.bmp");
			}
			else if (whichForm == 1)
			{
				pesgo1->PeFunction->Image->BitmapToFile(w,h,filePath+"bitmap\\Form6Graph.bmp");
			}

		}
		public: System::Void saveBitmap (String^ filename)
		{
			pesgo1->BringToFront();
			String^ filePath = System::Windows::Forms::Application::ExecutablePath->Remove(System::Windows::Forms::Application::ExecutablePath->LastIndexOf('\\')+1);	

			//Save the file
			pesgo1->PeFunction->Image->BitmapToFile(pesgo1->Width,pesgo1->Height,filename);
		}

		private: System::Void Resizing (Object^ sender, EventArgs^ e)
		{
			this->pesgo1->SetBounds(0,0,this->Width,this->Height-20);
			
			button2->SetBounds(39,3,30,30);
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			SaveFileDialog^ savefile = gcnew SaveFileDialog();
			savefile->Filter = L"Bitmaps|*.bmp";

			if (savefile->ShowDialog() == DialogResult::OK)
				saveBitmap (savefile->FileName);
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->pesgo1->PeFunction->UndoZoom();
		 }
		
private: System::Void vccCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			pesgo1->PeData->SubsetsToShow[0] = System::Convert::ToInt16(pesgo1->PeData->SubsetsToShow[0]==0);
			 pesgo1->PeData->SubsetsToShow[1] = pesgo1->PeData->SubsetsToShow[1];
			  pesgo1->PeData->SubsetsToShow[2] =pesgo1->PeData->SubsetsToShow[2];
			  pesgo1->PeData->SubsetsToShow[3] = pesgo1->PeData->SubsetsToShow[3];

			 pesgo1->Refresh();

		 }
private: System::Void vpCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {


			 pesgo1->PeData->SubsetsToShow[0] = pesgo1->PeData->SubsetsToShow[0];
			 pesgo1->PeData->SubsetsToShow[1] = System::Convert::ToInt16(pesgo1->PeData->SubsetsToShow[1]==0);
			  pesgo1->PeData->SubsetsToShow[2] = pesgo1->PeData->SubsetsToShow[2];
			  pesgo1->PeData->SubsetsToShow[3] = pesgo1->PeData->SubsetsToShow[3];

			   pesgo1->Refresh();
		 }
private: System::Void vsCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 pesgo1->PeData->SubsetsToShow[0] = pesgo1->PeData->SubsetsToShow[0];
			 pesgo1->PeData->SubsetsToShow[1] = pesgo1->PeData->SubsetsToShow[1];
			  pesgo1->PeData->SubsetsToShow[2] = System::Convert::ToInt16(pesgo1->PeData->SubsetsToShow[2]==0);
			  pesgo1->PeData->SubsetsToShow[3] = pesgo1->PeData->SubsetsToShow[3];

			 pesgo1->Refresh();
		 }
private: System::Void vpsCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 pesgo1->PeData->SubsetsToShow[0] = pesgo1->PeData->SubsetsToShow[0];
			 pesgo1->PeData->SubsetsToShow[1] = pesgo1->PeData->SubsetsToShow[1];
			  pesgo1->PeData->SubsetsToShow[2] = pesgo1->PeData->SubsetsToShow[2];
			  pesgo1->PeData->SubsetsToShow[3] = System::Convert::ToInt16(pesgo1->PeData->SubsetsToShow[3]==0);

			   pesgo1->Refresh();
		 }
};
}
