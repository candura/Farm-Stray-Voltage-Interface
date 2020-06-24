#pragma once

#include "Settings.h"
#include "Instructions.h"
#include "VoltGraph.h"
#include "Tablet.h"
#include "About.h"

namespace FarmStrayVoltage {

	using namespace System;
	using namespace System::Text;
	using namespace System::IO;
	using namespace Microsoft::Reporting::WinForms;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			filePath = System::Windows::Forms::Application::ExecutablePath->Remove(System::Windows::Forms::Application::ExecutablePath->LastIndexOf('\\')+1) + "bitmap\\";
			InitializeComponent();
			tipX2 = gcnew array<Point^>(10);
			tipX6 = gcnew array<Point^>(10);
			annoteX2 = gcnew array<double>(10);
			annoteX6 = gcnew array<double>(10);
			diagramText = "";
			madeDiagram = false;
			tablet = gcnew TabletForm();
			completeForms = gcnew array<bool>{false,true,false,false,false,false,false, false};
			this->Height = this->Height + 12;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				File::Delete(filePath + "Form6Graph.bmp");
				File::Delete(filePath + "Form2Graph.bmp");
				File::Delete(filePath + "Diagram.bmp");
				File::Delete(filePath + "form3.xml");
				File::Delete (filePath + "Diagram2.bmp");
				File::Delete (filePath + "barnDiagram.bmp");
				delete components;
			}
		}
	protected: 
	private:
private: System::Windows::Forms::TextBox^  form2StartText;
private: System::Windows::Forms::SaveFileDialog^  saveFormDialog;
private: System::Windows::Forms::OpenFileDialog^  openFormDialog;
private: System::Windows::Forms::GroupBox^  groupBox17;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::GroupBox^  groupBox18;
private: System::Windows::Forms::TabPage^  tabPage14;
private: System::Windows::Forms::Label^  label106;
private: System::Windows::Forms::ToolStripMenuItem^  instructionsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  form1ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  form2ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  form3ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  form4ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  form5ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  form6ToolStripMenuItem;
	private: Stray_Voltage_Report_Writer::Farm_Stray_Voltage_Data^  Farm_Stray_Voltage_Data;
	private: System::Windows::Forms::BindingSource^  form1DataBindingSource;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::DataGridView^  form1Grid;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::BindingSource^  form2DataBindingSource;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::BindingSource^  form3DataBindingSource;
	private: System::Windows::Forms::BindingSource^  form5DataBindingSource;
private: System::Windows::Forms::TabPage^  tabPage9;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::RichTextBox^  richTextBox8;
	private: System::Windows::Forms::Label^  vphalf;
	private: System::Windows::Forms::Label^  vpoff;
	private: System::Windows::Forms::Label^  vpfsv;
	private: System::Windows::Forms::RichTextBox^  richTextBox15;
	private: System::Windows::Forms::RichTextBox^  richTextBox12;
	private: System::Windows::Forms::RichTextBox^  richTextBox9;
	private: System::Windows::Forms::Label^  vcchalf;
	private: System::Windows::Forms::Label^  vccoff;
	private: System::Windows::Forms::Label^  vccfsv;
	private: System::Windows::Forms::RichTextBox^  richTextBox14;
	private: System::Windows::Forms::RichTextBox^  richTextBox11;
	private: System::Windows::Forms::Label^  vpfull;
	private: System::Windows::Forms::RichTextBox^  richTextBox18;
	private: System::Windows::Forms::Label^  vccfull;
	private: System::Windows::Forms::RichTextBox^  richTextBox17;
	private: System::Windows::Forms::Label^  SingleLabel;
	private: System::Windows::Forms::Label^  vccd3Phase;
	private: System::Windows::Forms::TabPage^  tabPage10;
	private: System::Windows::Forms::TabControl^  tabControl4;
	private: System::Windows::Forms::TabPage^  tabPage11;
	private: System::Windows::Forms::Label^  label68;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  step9Label;
private: System::Windows::Forms::Label^  step10Label;
private: System::Windows::Forms::Label^  step11Label;
	private: System::Windows::Forms::Label^  label73;
	private: System::Windows::Forms::Label^  label74;
	private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::Label^  step9Farm;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Label^  step9Load;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Label^  step10Load;
private: System::Windows::Forms::Label^  step11Load;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Label^  label89;
private: System::Windows::Forms::TextBox^  vcc6;
private: System::Windows::Forms::TextBox^  vp6;
private: System::Windows::Forms::TextBox^  vs6;
private: System::Windows::Forms::TextBox^  vps6;
private: System::Windows::Forms::TextBox^  vcc7;
private: System::Windows::Forms::TextBox^  vp7;
private: System::Windows::Forms::TextBox^  vs7;
private: System::Windows::Forms::TextBox^  vps7;
private: System::Windows::Forms::TextBox^  vps8;
private: System::Windows::Forms::TextBox^  vs8;
private: System::Windows::Forms::TextBox^  vp8;
private: System::Windows::Forms::TextBox^  vcc8;
private: System::Windows::Forms::TextBox^  vcc9;
private: System::Windows::Forms::TextBox^  vp9;
private: System::Windows::Forms::TextBox^  vs9;
private: System::Windows::Forms::TextBox^  vps9;
private: System::Windows::Forms::TextBox^  vps10;
private: System::Windows::Forms::TextBox^  vs10;
private: System::Windows::Forms::TextBox^  vp10;
private: System::Windows::Forms::TextBox^  vcc10;
private: System::Windows::Forms::MaskedTextBox^  time6;
private: System::Windows::Forms::MaskedTextBox^  time8;
private: System::Windows::Forms::MaskedTextBox^  time9;
private: System::Windows::Forms::MaskedTextBox^  time10;
private: System::Windows::Forms::MaskedTextBox^  time7;
private: System::Windows::Forms::Label^  label90;
private: System::Windows::Forms::Label^  label101;
private: System::Windows::Forms::TabPage^  tabPage12;
private: System::Windows::Forms::Label^  label102;
private: System::Windows::Forms::TabPage^  tabPage13;
private: System::Windows::Forms::DataGridView^  dataGridView3;
private: System::Windows::Forms::Label^  label123;
private: System::Windows::Forms::Label^  label124;
private: System::Windows::Forms::BindingSource^  form6DataBindingSource;
private: System::ComponentModel::IContainer^  components;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::RichTextBox^  richTextBox20;
private: System::Windows::Forms::RichTextBox^  richTextBox21;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::RichTextBox^  richTextBox22;
private: System::Windows::Forms::RichTextBox^  richTextBox23;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::TextBox^  textBox11;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::TextBox^  textBox12;
private: System::Windows::Forms::TextBox^  textBox13;
private: System::Windows::Forms::TextBox^  textBox14;
private: System::Windows::Forms::TextBox^  textBox17;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::TextBox^  textBox18;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::Label^  vccd3Phase5;
private: System::Windows::Forms::Label^  vccd1Phase5;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::GroupBox^  groupBox12;
private: System::Windows::Forms::RichTextBox^  richTextBox10;
private: System::Windows::Forms::Label^  vccfull5;
private: System::Windows::Forms::RichTextBox^  richTextBox13;
private: System::Windows::Forms::Label^  vpfull5;
private: System::Windows::Forms::GroupBox^  groupBox13;
private: System::Windows::Forms::RichTextBox^  richTextBox16;
private: System::Windows::Forms::Label^  vcchalf5;
private: System::Windows::Forms::RichTextBox^  richTextBox834;
private: System::Windows::Forms::Label^  vphalf5;
private: System::Windows::Forms::GroupBox^  groupBox14;
private: System::Windows::Forms::RichTextBox^  richTextBox24;
private: System::Windows::Forms::Label^  vccoff5;
private: System::Windows::Forms::RichTextBox^  richTextBox25;
private: System::Windows::Forms::Label^  vpoff5;
private: System::Windows::Forms::GroupBox^  groupBox15;
private: System::Windows::Forms::RichTextBox^  richTextBox26;
private: System::Windows::Forms::Label^  vccfsv5;
private: System::Windows::Forms::RichTextBox^  richTextBox27;
private: System::Windows::Forms::Label^  vpfsv5;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::RichTextBox^  richTextBox2;
private: System::Windows::Forms::RichTextBox^  richTextBox3;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::RichTextBox^  richTextBox4;
private: System::Windows::Forms::RichTextBox^  richTextBox5;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::TextBox^  vpri;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::TextBox^  ilbh;
private: System::Windows::Forms::TextBox^  vlbh;
private: System::Windows::Forms::TextBox^  ilbf;
private: System::Windows::Forms::TextBox^  vlbf;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::TextBox^  ip;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
private: System::Windows::Forms::Label^  step1Label;
private: System::Windows::Forms::Label^  step3Label;
private: System::Windows::Forms::Label^  step4Label;
private: System::Windows::Forms::Label^  step5Label;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  step5Farm;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Label^  step3Farm;
private: System::Windows::Forms::Label^  step4Farm;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Label^  step3Load;
private: System::Windows::Forms::Label^  label91;
private: System::Windows::Forms::Label^  step4Load;
private: System::Windows::Forms::Label^  step5Load;
private: System::Windows::Forms::Label^  label94;
private: System::Windows::Forms::Label^  label95;
private: System::Windows::Forms::Label^  label96;
private: System::Windows::Forms::Label^  label97;
private: System::Windows::Forms::Label^  label98;
private: System::Windows::Forms::TextBox^  vcc1;
private: System::Windows::Forms::TextBox^  vp1;
private: System::Windows::Forms::TextBox^  vs1;
private: System::Windows::Forms::TextBox^  vps1;
private: System::Windows::Forms::TextBox^  vcc2;
private: System::Windows::Forms::TextBox^  vp2;
private: System::Windows::Forms::TextBox^  vs2;
private: System::Windows::Forms::TextBox^  vps2;
private: System::Windows::Forms::TextBox^  vps3;
private: System::Windows::Forms::TextBox^  vs3;
private: System::Windows::Forms::TextBox^  vp3;
private: System::Windows::Forms::TextBox^  vcc3;
private: System::Windows::Forms::TextBox^  vcc4;
private: System::Windows::Forms::TextBox^  vp4;
private: System::Windows::Forms::TextBox^  vs4;
private: System::Windows::Forms::TextBox^  vps4;
private: System::Windows::Forms::TextBox^  vps5;
private: System::Windows::Forms::TextBox^  vs5;
private: System::Windows::Forms::TextBox^  vp5;
private: System::Windows::Forms::TextBox^  vcc5;
private: System::Windows::Forms::MaskedTextBox^  time1;
private: System::Windows::Forms::MaskedTextBox^  time3;
private: System::Windows::Forms::MaskedTextBox^  time4;
private: System::Windows::Forms::MaskedTextBox^  time5;
private: System::Windows::Forms::Label^  step2Label;
private: System::Windows::Forms::Button^  clearButton;
private: System::Windows::Forms::Button^  enterData;
private: System::Windows::Forms::Button^  clearButton5;
private: System::Windows::Forms::Button^  enterData5;
private: System::Windows::Forms::MaskedTextBox^  time2;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  saveFormsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  openExistingFormsToolStripMenuItem;

private: System::Windows::Forms::Label^  label103;
private: System::Windows::Forms::Label^  label104;
private: System::Windows::Forms::Label^  label105;
private: System::Windows::Forms::GroupBox^  groupBox16;
private: System::Windows::Forms::Button^  form3Open;
private: System::Windows::Forms::RadioButton^  userRadio;
private: System::Windows::Forms::RadioButton^  fileRadio;
private: System::Windows::Forms::Label^  label107;
private: System::Windows::Forms::OpenFileDialog^  form3OpenDialog;
private: System::Windows::Forms::Button^  openButt;
private: System::Windows::Forms::TextBox^  form2StopText;
private: System::Windows::Forms::Label^  vccd1Phase;
private: System::Windows::Forms::RichTextBox^  commentText;
private: System::Windows::Forms::Label^  form3File;
private: System::Windows::Forms::Label^  step6Load;
private: System::Windows::Forms::Label^  step6Farm;
private: System::Windows::Forms::Label^  step6Label;
private: System::Windows::Forms::MaskedTextBox^  time11;
private: System::Windows::Forms::TextBox^  vps11;
private: System::Windows::Forms::TextBox^  vs11;
private: System::Windows::Forms::TextBox^  vp11;
private: System::Windows::Forms::TextBox^  vcc11;
private: System::Windows::Forms::ToolStripMenuItem^  printToolStripMenuItem;
private: System::Windows::Forms::PrintDialog^  printDialog1;
private: System::Drawing::Printing::PrintDocument^  printDocument1;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Label^  form5File;
private: System::Windows::Forms::Button^  form5Open;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::OpenFileDialog^  form5OpenDialog;
private: System::Windows::Forms::MaskedTextBox^  time12;
private: System::Windows::Forms::TextBox^  vcc12;
private: System::Windows::Forms::TextBox^  vp12;
private: System::Windows::Forms::TextBox^  vs12;
private: System::Windows::Forms::TextBox^  vps12;
private: System::Windows::Forms::Label^  step12Load;
private: System::Windows::Forms::Label^  step12Farm;
private: System::Windows::Forms::Label^  step12Label;
private: System::Windows::Forms::Button^  form6Open;
		 	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox20;
	private: System::Windows::Forms::TextBox^  form6Start;
	private: System::Windows::Forms::TextBox^  form6Stop;
	private: array<float>^ graphDataY;
	private: array<double>^ graphDataX2;
	private: array<float>^ graphDataY6;
	private: array<double>^ graphDataX26;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::BindingSource^  RecordsBindingSource;
	private: String^ form3Date,^form5Date;
private: System::Windows::Forms::MaskedTextBox^  form1DateText;
private: System::Windows::Forms::Label^  form3StopTime;
private: System::Windows::Forms::Label^  form3StartTime;
private: System::Windows::Forms::Label^  form3Stop;
private: System::Windows::Forms::Label^  form3Start;
private: System::Windows::Forms::Label^  form5StopTime;
private: System::Windows::Forms::Label^  form5StartTime;
private: System::Windows::Forms::Label^  form5Stop;
private: System::Windows::Forms::Label^  form5Start;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  form2FileText;
private: System::Windows::Forms::Label^  form6FileText;
private: System::Windows::Forms::ToolStripMenuItem^  mainFormToolStripMenuItem;


private: System::Windows::Forms::ProgressBar^  Form2Progress;





private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
private: System::Windows::Forms::TabPage^  tabPage7;
private: System::Windows::Forms::GroupBox^  groupBox21;

private: System::Windows::Forms::RadioButton^  phaseRadio1;

private: System::Windows::Forms::RadioButton^  radio5Step;
private: System::Windows::Forms::RadioButton^  step2Radio;
private: System::Windows::Forms::RadioButton^  phaseRadio3;
private: System::Windows::Forms::GroupBox^  groupBox19;
private: System::Windows::Forms::RadioButton^  radioButton3;
private: System::Windows::Forms::RadioButton^  channel4I;
private: System::Windows::Forms::Label^  label109;
private: System::Windows::Forms::Label^  label108;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  cal3Text;
private: System::Windows::Forms::TextBox^  cal4Text;
private: System::Windows::Forms::TextBox^  cal5Text;
private: System::Windows::Forms::TextBox^  cal2Text;
private: System::Windows::Forms::TextBox^  cal1Text;
private: System::Windows::Forms::TextBox^  utilWebsite;
private: System::Windows::Forms::TextBox^  utilEmail;
private: System::Windows::Forms::TextBox^  utilPhone;
private: System::Windows::Forms::TextBox^  utilAddress2;
private: System::Windows::Forms::TextBox^  utilAddress1;
private: System::Windows::Forms::TextBox^  utilName;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::MonthCalendar^  calendar;
private: System::Windows::Forms::GroupBox^  groupBox22;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::TextBox^  investName;
private: System::Windows::Forms::MaskedTextBox^  investConclude;
private: System::Windows::Forms::MaskedTextBox^  investStart;
private: System::Windows::Forms::MaskedTextBox^  investVisit;
private: System::Windows::Forms::MaskedTextBox^  investReceive;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::GroupBox^  groupBox23;
private: System::Windows::Forms::TextBox^  farmEmail;
private: System::Windows::Forms::TextBox^  farmPhone;
private: System::Windows::Forms::TextBox^  farmAddress2;
private: System::Windows::Forms::TextBox^  farmAddress1;
private: System::Windows::Forms::TextBox^  farmName;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::TextBox^  custEmail;
private: System::Windows::Forms::TextBox^  custPhone;
private: System::Windows::Forms::TextBox^  custAddress2;
private: System::Windows::Forms::TextBox^  custAddress1;
private: System::Windows::Forms::TextBox^  custName;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::GroupBox^  groupBox25;
private: System::Windows::Forms::GroupBox^  groupBox24;
private: Microsoft::Reporting::WinForms::ReportViewer^  reportViewer1;







private: System::Windows::Forms::MonthCalendar^  calendar2;
	/// <summary>
	/// Required designer variable.
	/// </summary>
	private: float highestVcc,highestP2RV;
	private: float cal1, cal2, cal3, cal4, cal5;
	private: array<double>^ annoteX2;
	private: array<double>^ annoteX6;
	private: array<System::Drawing::Point^>^ tipX6;
	private: array<System::Drawing::Point^>^ tipX2;
	private: bool nonNumberEntered;
	private: int numRecord;
	private: array<VoltGraph^>^ graphs;
	private: System::Windows::Forms::Button^  viewGraph;
	private: array <float>^ graphVcc, ^graphVp, ^graphVs, ^graphVps;
	private: array <float>^ graphVcc6, ^graphVp6, ^graphVs6, ^graphVps6;
	private: array <double>^ graphDataX;
	private: FarmStrayVoltage::TabletForm^ tablet;
	private: Stray_Voltage_Report_Writer::Farm_Stray_Voltage_Data^ ds;
	private: String^ diagramText;
	private: bool madeDiagram;
	private: MaskedTextBox^ lastMTB;
			 List<Stream^>^ m_streams;
			 SaveFileDialog^ sfd;	private: bool openedFile;
	private: array<bool>^ completeForms;







private: System::Windows::Forms::TextBox^  investEmail;
private: System::Windows::Forms::TextBox^  investPhone;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::GroupBox^  groupBox26;
private: System::Windows::Forms::TextBox^  reportSummary;
private: System::Windows::Forms::TextBox^  fileNumber;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Label^  phases;
private: System::Windows::Forms::ComboBox^  phaseBox;
private: System::Windows::Forms::Label^  phase3ses;
private: System::Windows::Forms::Label^  phase3ses5;
private: System::Windows::Forms::Label^  phases5;
private: System::Windows::Forms::ComboBox^  phaseBox5;
private: System::Windows::Forms::TextBox^  custNameF1;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::TextBox^  farmLocationF1;
private: System::Windows::Forms::TextBox^  textBox3;
private: bool entered;


private: System::Windows::Forms::DataGridViewTextBoxColumn^  locIdDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  descriptionDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  vwoShuntDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  vwShuntDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  sourceResistanceDataGridViewTextBoxColumn;
private: System::Windows::Forms::ComboBox^  locCombo;
private: System::Windows::Forms::Label^  label59;
private: String^ filePath;
private: String^ form2FileName;
private: String^ form3FileName;
private: String^ form5FileName;
private: String^ form6FileName;

private: System::Windows::Forms::Button^  F3Graph;
private: System::Windows::Forms::Button^  F5Graph;
private: array<float>^ YData;
private: array<double>^ XData;
private: array<float>^ YData5;
private: System::Windows::Forms::Button^  reportButton;
private: System::Windows::Forms::ComboBox^  locCombo6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  locIdDataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  commentDataGridViewTextBoxColumn;

private: array<double>^ XData5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  hourDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  highestVccDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  aContactVoltDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  pN2RVoltDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  sN2RVoltDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  pN2SNVoltDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  timeVccExceedsDataGridViewTextBoxColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
private: System::Windows::Forms::ToolStripMenuItem^  infoToolStripMenuItem;
private: String^ barnDiagram;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			Microsoft::Reporting::WinForms::ReportDataSource^  reportDataSource6 = (gcnew Microsoft::Reporting::WinForms::ReportDataSource());
			Microsoft::Reporting::WinForms::ReportDataSource^  reportDataSource7 = (gcnew Microsoft::Reporting::WinForms::ReportDataSource());
			Microsoft::Reporting::WinForms::ReportDataSource^  reportDataSource8 = (gcnew Microsoft::Reporting::WinForms::ReportDataSource());
			Microsoft::Reporting::WinForms::ReportDataSource^  reportDataSource9 = (gcnew Microsoft::Reporting::WinForms::ReportDataSource());
			Microsoft::Reporting::WinForms::ReportDataSource^  reportDataSource10 = (gcnew Microsoft::Reporting::WinForms::ReportDataSource());
			this->form1DataBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->Farm_Stray_Voltage_Data = (gcnew Stray_Voltage_Report_Writer::Farm_Stray_Voltage_Data());
			this->form2DataBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->form3DataBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->form5DataBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->form6DataBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->RecordsBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage14 = (gcnew System::Windows::Forms::TabPage());
			this->calendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->reportButton = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox26 = (gcnew System::Windows::Forms::GroupBox());
			this->reportSummary = (gcnew System::Windows::Forms::TextBox());
			this->groupBox23 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->farmEmail = (gcnew System::Windows::Forms::TextBox());
			this->farmPhone = (gcnew System::Windows::Forms::TextBox());
			this->farmAddress2 = (gcnew System::Windows::Forms::TextBox());
			this->farmAddress1 = (gcnew System::Windows::Forms::TextBox());
			this->farmName = (gcnew System::Windows::Forms::TextBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->custEmail = (gcnew System::Windows::Forms::TextBox());
			this->custPhone = (gcnew System::Windows::Forms::TextBox());
			this->custAddress2 = (gcnew System::Windows::Forms::TextBox());
			this->custAddress1 = (gcnew System::Windows::Forms::TextBox());
			this->custName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
			this->fileNumber = (gcnew System::Windows::Forms::TextBox());
			this->investEmail = (gcnew System::Windows::Forms::TextBox());
			this->investPhone = (gcnew System::Windows::Forms::TextBox());
			this->investName = (gcnew System::Windows::Forms::TextBox());
			this->investConclude = (gcnew System::Windows::Forms::MaskedTextBox());
			this->investStart = (gcnew System::Windows::Forms::MaskedTextBox());
			this->investVisit = (gcnew System::Windows::Forms::MaskedTextBox());
			this->investReceive = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
			this->utilWebsite = (gcnew System::Windows::Forms::TextBox());
			this->utilEmail = (gcnew System::Windows::Forms::TextBox());
			this->utilPhone = (gcnew System::Windows::Forms::TextBox());
			this->utilAddress2 = (gcnew System::Windows::Forms::TextBox());
			this->utilAddress1 = (gcnew System::Windows::Forms::TextBox());
			this->utilName = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox25 = (gcnew System::Windows::Forms::GroupBox());
			this->channel4I = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox24 = (gcnew System::Windows::Forms::GroupBox());
			this->phaseRadio3 = (gcnew System::Windows::Forms::RadioButton());
			this->phaseRadio1 = (gcnew System::Windows::Forms::RadioButton());
			this->radio5Step = (gcnew System::Windows::Forms::RadioButton());
			this->step2Radio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->label108 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->cal3Text = (gcnew System::Windows::Forms::TextBox());
			this->cal4Text = (gcnew System::Windows::Forms::TextBox());
			this->cal5Text = (gcnew System::Windows::Forms::TextBox());
			this->cal2Text = (gcnew System::Windows::Forms::TextBox());
			this->cal1Text = (gcnew System::Windows::Forms::TextBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->calendar2 = (gcnew System::Windows::Forms::MonthCalendar());
			this->farmLocationF1 = (gcnew System::Windows::Forms::TextBox());
			this->custNameF1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->form1DateText = (gcnew System::Windows::Forms::MaskedTextBox());
			this->commentText = (gcnew System::Windows::Forms::RichTextBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label106 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->form1Grid = (gcnew System::Windows::Forms::DataGridView());
			this->locIdDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descriptionDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vwoShuntDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vwShuntDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sourceResistanceDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->locIdDataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->commentDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->form2FileText = (gcnew System::Windows::Forms::Label());
			this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
			this->locCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->form2StopText = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->form2StartText = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->viewGraph = (gcnew System::Windows::Forms::Button());
			this->openButt = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->hourDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->highestVccDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->aContactVoltDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pN2RVoltDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sN2RVoltDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pN2SNVoltDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timeVccExceedsDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->phase3ses = (gcnew System::Windows::Forms::Label());
			this->phases = (gcnew System::Windows::Forms::Label());
			this->phaseBox = (gcnew System::Windows::Forms::ComboBox());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->enterData = (gcnew System::Windows::Forms::Button());
			this->form3StopTime = (gcnew System::Windows::Forms::Label());
			this->form3StartTime = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->form3Stop = (gcnew System::Windows::Forms::Label());
			this->vcc11 = (gcnew System::Windows::Forms::TextBox());
			this->form3Start = (gcnew System::Windows::Forms::Label());
			this->vp11 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->step1Label = (gcnew System::Windows::Forms::Label());
			this->step3Label = (gcnew System::Windows::Forms::Label());
			this->step4Label = (gcnew System::Windows::Forms::Label());
			this->step5Label = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->step5Farm = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->step3Farm = (gcnew System::Windows::Forms::Label());
			this->step4Farm = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->step3Load = (gcnew System::Windows::Forms::Label());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->step4Load = (gcnew System::Windows::Forms::Label());
			this->step5Load = (gcnew System::Windows::Forms::Label());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->label98 = (gcnew System::Windows::Forms::Label());
			this->vcc1 = (gcnew System::Windows::Forms::TextBox());
			this->vp1 = (gcnew System::Windows::Forms::TextBox());
			this->vs1 = (gcnew System::Windows::Forms::TextBox());
			this->vps1 = (gcnew System::Windows::Forms::TextBox());
			this->vcc2 = (gcnew System::Windows::Forms::TextBox());
			this->vp2 = (gcnew System::Windows::Forms::TextBox());
			this->vs2 = (gcnew System::Windows::Forms::TextBox());
			this->vps2 = (gcnew System::Windows::Forms::TextBox());
			this->vps3 = (gcnew System::Windows::Forms::TextBox());
			this->vs3 = (gcnew System::Windows::Forms::TextBox());
			this->vp3 = (gcnew System::Windows::Forms::TextBox());
			this->vcc3 = (gcnew System::Windows::Forms::TextBox());
			this->vcc4 = (gcnew System::Windows::Forms::TextBox());
			this->vp4 = (gcnew System::Windows::Forms::TextBox());
			this->vs4 = (gcnew System::Windows::Forms::TextBox());
			this->vps4 = (gcnew System::Windows::Forms::TextBox());
			this->vps5 = (gcnew System::Windows::Forms::TextBox());
			this->vs5 = (gcnew System::Windows::Forms::TextBox());
			this->vp5 = (gcnew System::Windows::Forms::TextBox());
			this->vcc5 = (gcnew System::Windows::Forms::TextBox());
			this->time1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->time3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->time4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->time5 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->step2Label = (gcnew System::Windows::Forms::Label());
			this->time2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->vs11 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->F3Graph = (gcnew System::Windows::Forms::Button());
			this->form3File = (gcnew System::Windows::Forms::Label());
			this->form3Open = (gcnew System::Windows::Forms::Button());
			this->userRadio = (gcnew System::Windows::Forms::RadioButton());
			this->fileRadio = (gcnew System::Windows::Forms::RadioButton());
			this->label107 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->time11 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->vpri = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->ilbh = (gcnew System::Windows::Forms::TextBox());
			this->vlbh = (gcnew System::Windows::Forms::TextBox());
			this->ilbf = (gcnew System::Windows::Forms::TextBox());
			this->vlbf = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->ip = (gcnew System::Windows::Forms::TextBox());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->vccd1Phase = (gcnew System::Windows::Forms::Label());
			this->vccd3Phase = (gcnew System::Windows::Forms::Label());
			this->SingleLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox17 = (gcnew System::Windows::Forms::RichTextBox());
			this->vccfull = (gcnew System::Windows::Forms::Label());
			this->richTextBox18 = (gcnew System::Windows::Forms::RichTextBox());
			this->vpfull = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox14 = (gcnew System::Windows::Forms::RichTextBox());
			this->vcchalf = (gcnew System::Windows::Forms::Label());
			this->richTextBox15 = (gcnew System::Windows::Forms::RichTextBox());
			this->vphalf = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox11 = (gcnew System::Windows::Forms::RichTextBox());
			this->vccoff = (gcnew System::Windows::Forms::Label());
			this->richTextBox12 = (gcnew System::Windows::Forms::RichTextBox());
			this->vpoff = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox8 = (gcnew System::Windows::Forms::RichTextBox());
			this->vccfsv = (gcnew System::Windows::Forms::Label());
			this->richTextBox9 = (gcnew System::Windows::Forms::RichTextBox());
			this->vpfsv = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tabPage10 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl4 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage11 = (gcnew System::Windows::Forms::TabPage());
			this->phase3ses5 = (gcnew System::Windows::Forms::Label());
			this->phases5 = (gcnew System::Windows::Forms::Label());
			this->phaseBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->form5StopTime = (gcnew System::Windows::Forms::Label());
			this->form5StartTime = (gcnew System::Windows::Forms::Label());
			this->form5Stop = (gcnew System::Windows::Forms::Label());
			this->form5Start = (gcnew System::Windows::Forms::Label());
			this->step12Load = (gcnew System::Windows::Forms::Label());
			this->step12Farm = (gcnew System::Windows::Forms::Label());
			this->step12Label = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->step9Label = (gcnew System::Windows::Forms::Label());
			this->step10Label = (gcnew System::Windows::Forms::Label());
			this->step11Label = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->step9Farm = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->step9Load = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->step10Load = (gcnew System::Windows::Forms::Label());
			this->step11Load = (gcnew System::Windows::Forms::Label());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->vcc6 = (gcnew System::Windows::Forms::TextBox());
			this->vp6 = (gcnew System::Windows::Forms::TextBox());
			this->vs6 = (gcnew System::Windows::Forms::TextBox());
			this->vps6 = (gcnew System::Windows::Forms::TextBox());
			this->vcc7 = (gcnew System::Windows::Forms::TextBox());
			this->vp7 = (gcnew System::Windows::Forms::TextBox());
			this->vs7 = (gcnew System::Windows::Forms::TextBox());
			this->vps7 = (gcnew System::Windows::Forms::TextBox());
			this->vps8 = (gcnew System::Windows::Forms::TextBox());
			this->vs8 = (gcnew System::Windows::Forms::TextBox());
			this->vp8 = (gcnew System::Windows::Forms::TextBox());
			this->vcc8 = (gcnew System::Windows::Forms::TextBox());
			this->vcc9 = (gcnew System::Windows::Forms::TextBox());
			this->vp9 = (gcnew System::Windows::Forms::TextBox());
			this->vs9 = (gcnew System::Windows::Forms::TextBox());
			this->vps9 = (gcnew System::Windows::Forms::TextBox());
			this->vps10 = (gcnew System::Windows::Forms::TextBox());
			this->vs10 = (gcnew System::Windows::Forms::TextBox());
			this->vp10 = (gcnew System::Windows::Forms::TextBox());
			this->vcc10 = (gcnew System::Windows::Forms::TextBox());
			this->time6 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->time8 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->time9 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->time10 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->time7 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->F5Graph = (gcnew System::Windows::Forms::Button());
			this->form5File = (gcnew System::Windows::Forms::Label());
			this->form5Open = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->clearButton5 = (gcnew System::Windows::Forms::Button());
			this->enterData5 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox20 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox21 = (gcnew System::Windows::Forms::RichTextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->richTextBox22 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox23 = (gcnew System::Windows::Forms::RichTextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->time12 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->vcc12 = (gcnew System::Windows::Forms::TextBox());
			this->vp12 = (gcnew System::Windows::Forms::TextBox());
			this->vs12 = (gcnew System::Windows::Forms::TextBox());
			this->vps12 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage12 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->vccd3Phase5 = (gcnew System::Windows::Forms::Label());
			this->vccd1Phase5 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox10 = (gcnew System::Windows::Forms::RichTextBox());
			this->vccfull5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox13 = (gcnew System::Windows::Forms::RichTextBox());
			this->vpfull5 = (gcnew System::Windows::Forms::Label());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox16 = (gcnew System::Windows::Forms::RichTextBox());
			this->vcchalf5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox834 = (gcnew System::Windows::Forms::RichTextBox());
			this->vphalf5 = (gcnew System::Windows::Forms::Label());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox24 = (gcnew System::Windows::Forms::RichTextBox());
			this->vccoff5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox25 = (gcnew System::Windows::Forms::RichTextBox());
			this->vpoff5 = (gcnew System::Windows::Forms::Label());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox26 = (gcnew System::Windows::Forms::RichTextBox());
			this->vccfsv5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox27 = (gcnew System::Windows::Forms::RichTextBox());
			this->vpfsv5 = (gcnew System::Windows::Forms::Label());
			this->label102 = (gcnew System::Windows::Forms::Label());
			this->tabPage13 = (gcnew System::Windows::Forms::TabPage());
			this->form6FileText = (gcnew System::Windows::Forms::Label());
			this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
			this->locCombo6 = (gcnew System::Windows::Forms::ComboBox());
			this->form6Stop = (gcnew System::Windows::Forms::TextBox());
			this->form6Start = (gcnew System::Windows::Forms::TextBox());
			this->label105 = (gcnew System::Windows::Forms::Label());
			this->label104 = (gcnew System::Windows::Forms::Label());
			this->label103 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->form6Open = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label123 = (gcnew System::Windows::Forms::Label());
			this->label124 = (gcnew System::Windows::Forms::Label());
			this->reportViewer1 = (gcnew Microsoft::Reporting::WinForms::ReportViewer());
			this->Form2Progress = (gcnew System::Windows::Forms::ProgressBar());
			this->step6Label = (gcnew System::Windows::Forms::Label());
			this->step6Farm = (gcnew System::Windows::Forms::Label());
			this->step6Load = (gcnew System::Windows::Forms::Label());
			this->vps11 = (gcnew System::Windows::Forms::TextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFormsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openExistingFormsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instructionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form5ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form6ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainFormToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->form3OpenDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFormDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFormDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->form5OpenDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form1DataBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Farm_Stray_Voltage_Data))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form2DataBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form3DataBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form5DataBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form6DataBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RecordsBindingSource))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage14->SuspendLayout();
			this->groupBox26->SuspendLayout();
			this->groupBox23->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox22->SuspendLayout();
			this->groupBox21->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->groupBox25->SuspendLayout();
			this->groupBox24->SuspendLayout();
			this->groupBox19->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form1Grid))->BeginInit();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox18->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox17->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox16->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabPage9->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tabPage10->SuspendLayout();
			this->tabControl4->SuspendLayout();
			this->tabPage11->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tabPage12->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox13->SuspendLayout();
			this->groupBox14->SuspendLayout();
			this->groupBox15->SuspendLayout();
			this->tabPage13->SuspendLayout();
			this->groupBox20->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// form1DataBindingSource
			// 
			this->form1DataBindingSource->DataMember = L"Form 1 Data";
			this->form1DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data;
			// 
			// Farm_Stray_Voltage_Data
			// 
			this->Farm_Stray_Voltage_Data->DataSetName = L"Farm Stray Voltage Data";
			this->Farm_Stray_Voltage_Data->SchemaSerializationMode = System::Data::SchemaSerializationMode::IncludeSchema;
			// 
			// form2DataBindingSource
			// 
			this->form2DataBindingSource->DataMember = L"Form 2 Data";
			this->form2DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data;
			// 
			// form3DataBindingSource
			// 
			this->form3DataBindingSource->DataMember = L"Form 3 Data";
			this->form3DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data;
			// 
			// form5DataBindingSource
			// 
			this->form5DataBindingSource->DataMember = L"Form 5 Data";
			this->form5DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data;
			// 
			// form6DataBindingSource
			// 
			this->form6DataBindingSource->DataMember = L"Form 6 Data";
			this->form6DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data;
			// 
			// RecordsBindingSource
			// 
			this->RecordsBindingSource->DataMember = L"Farm Stray Voltage Data";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage14);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage9);
			this->tabControl1->Controls->Add(this->tabPage10);
			this->tabControl1->Controls->Add(this->tabPage13);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tabControl1->Location = System::Drawing::Point(0, 78);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1027, 637);
			this->tabControl1->TabIndex = 23;
			// 
			// tabPage14
			// 
			this->tabPage14->BackColor = System::Drawing::Color::White;
			this->tabPage14->Controls->Add(this->calendar);
			this->tabPage14->Controls->Add(this->reportButton);
			this->tabPage14->Controls->Add(this->button4);
			this->tabPage14->Controls->Add(this->button2);
			this->tabPage14->Controls->Add(this->groupBox26);
			this->tabPage14->Controls->Add(this->groupBox23);
			this->tabPage14->Controls->Add(this->groupBox1);
			this->tabPage14->Controls->Add(this->groupBox22);
			this->tabPage14->Controls->Add(this->groupBox21);
			this->tabPage14->Location = System::Drawing::Point(4, 22);
			this->tabPage14->Name = L"tabPage14";
			this->tabPage14->Padding = System::Windows::Forms::Padding(3);
			this->tabPage14->Size = System::Drawing::Size(1019, 611);
			this->tabPage14->TabIndex = 6;
			this->tabPage14->Text = L"Info";
			// 
			// calendar
			// 
			this->calendar->Location = System::Drawing::Point(827, 78);
			this->calendar->Name = L"calendar";
			this->calendar->ShowToday = false;
			this->calendar->TabIndex = 22;
			this->calendar->Visible = false;
			this->calendar->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Form1::calendar_DateSelected);
			this->calendar->Leave += gcnew System::EventHandler(this, &Form1::calendar_Leave);
			// 
			// reportButton
			// 
			this->reportButton->Location = System::Drawing::Point(875, 527);
			this->reportButton->Name = L"reportButton";
			this->reportButton->Size = System::Drawing::Size(112, 44);
			this->reportButton->TabIndex = 65;
			this->reportButton->Text = L"Generate Report";
			this->reportButton->UseVisualStyleBackColor = true;
			this->reportButton->Click += gcnew System::EventHandler(this, &Form1::reportButton_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(875, 429);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 44);
			this->button4->TabIndex = 62;
			this->button4->Text = L"Barn Diagram";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::barnDiagram_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(875, 479);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 44);
			this->button2->TabIndex = 62;
			this->button2->Text = L"Property Diagram";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBox26
			// 
			this->groupBox26->BackColor = System::Drawing::Color::Transparent;
			this->groupBox26->Controls->Add(this->reportSummary);
			this->groupBox26->Location = System::Drawing::Point(190, 429);
			this->groupBox26->Name = L"groupBox26";
			this->groupBox26->Size = System::Drawing::Size(638, 174);
			this->groupBox26->TabIndex = 31;
			this->groupBox26->TabStop = false;
			this->groupBox26->Text = L"Report Summary/Notes";
			// 
			// reportSummary
			// 
			this->reportSummary->Location = System::Drawing::Point(34, 26);
			this->reportSummary->MaximumSize = System::Drawing::Size(3000, 3000);
			this->reportSummary->Multiline = true;
			this->reportSummary->Name = L"reportSummary";
			this->reportSummary->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->reportSummary->Size = System::Drawing::Size(571, 135);
			this->reportSummary->TabIndex = 30;
			// 
			// groupBox23
			// 
			this->groupBox23->BackColor = System::Drawing::Color::Transparent;
			this->groupBox23->Controls->Add(this->checkBox1);
			this->groupBox23->Controls->Add(this->farmEmail);
			this->groupBox23->Controls->Add(this->farmPhone);
			this->groupBox23->Controls->Add(this->farmAddress2);
			this->groupBox23->Controls->Add(this->farmAddress1);
			this->groupBox23->Controls->Add(this->farmName);
			this->groupBox23->Controls->Add(this->label54);
			this->groupBox23->Controls->Add(this->label55);
			this->groupBox23->Controls->Add(this->label56);
			this->groupBox23->Controls->Add(this->label57);
			this->groupBox23->Location = System::Drawing::Point(31, 239);
			this->groupBox23->Name = L"groupBox23";
			this->groupBox23->Size = System::Drawing::Size(300, 184);
			this->groupBox23->TabIndex = 29;
			this->groupBox23->TabStop = false;
			this->groupBox23->Text = L"Farm Information";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(9, 27);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(114, 17);
			this->checkBox1->TabIndex = 25;
			this->checkBox1->Text = L"Same as Customer";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// farmEmail
			// 
			this->farmEmail->Location = System::Drawing::Point(80, 156);
			this->farmEmail->MaximumSize = System::Drawing::Size(3000, 3000);
			this->farmEmail->Name = L"farmEmail";
			this->farmEmail->Size = System::Drawing::Size(158, 20);
			this->farmEmail->TabIndex = 10;
			// 
			// farmPhone
			// 
			this->farmPhone->Location = System::Drawing::Point(80, 131);
			this->farmPhone->MaximumSize = System::Drawing::Size(3000, 3000);
			this->farmPhone->Name = L"farmPhone";
			this->farmPhone->Size = System::Drawing::Size(158, 20);
			this->farmPhone->TabIndex = 9;
			// 
			// farmAddress2
			// 
			this->farmAddress2->Location = System::Drawing::Point(80, 106);
			this->farmAddress2->MaximumSize = System::Drawing::Size(3000, 3000);
			this->farmAddress2->Name = L"farmAddress2";
			this->farmAddress2->Size = System::Drawing::Size(158, 20);
			this->farmAddress2->TabIndex = 8;
			// 
			// farmAddress1
			// 
			this->farmAddress1->Location = System::Drawing::Point(80, 81);
			this->farmAddress1->MaximumSize = System::Drawing::Size(3000, 3000);
			this->farmAddress1->Name = L"farmAddress1";
			this->farmAddress1->Size = System::Drawing::Size(158, 20);
			this->farmAddress1->TabIndex = 7;
			// 
			// farmName
			// 
			this->farmName->Location = System::Drawing::Point(80, 56);
			this->farmName->MaximumSize = System::Drawing::Size(3000, 3000);
			this->farmName->Name = L"farmName";
			this->farmName->Size = System::Drawing::Size(158, 20);
			this->farmName->TabIndex = 6;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(6, 159);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(35, 13);
			this->label54->TabIndex = 22;
			this->label54->Text = L"Email:";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(6, 134);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(61, 13);
			this->label55->TabIndex = 21;
			this->label55->Text = L"Telephone:";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(6, 84);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(48, 13);
			this->label56->TabIndex = 23;
			this->label56->Text = L"Address:";
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(6, 59);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(38, 13);
			this->label57->TabIndex = 24;
			this->label57->Text = L"Name:";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->custEmail);
			this->groupBox1->Controls->Add(this->custPhone);
			this->groupBox1->Controls->Add(this->custAddress2);
			this->groupBox1->Controls->Add(this->custAddress1);
			this->groupBox1->Controls->Add(this->custName);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label59);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label53);
			this->groupBox1->Location = System::Drawing::Point(31, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(300, 194);
			this->groupBox1->TabIndex = 29;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Customer Information";
			// 
			// custEmail
			// 
			this->custEmail->Location = System::Drawing::Point(80, 130);
			this->custEmail->MaximumSize = System::Drawing::Size(3000, 3000);
			this->custEmail->Name = L"custEmail";
			this->custEmail->Size = System::Drawing::Size(158, 20);
			this->custEmail->TabIndex = 5;
			// 
			// custPhone
			// 
			this->custPhone->Location = System::Drawing::Point(80, 105);
			this->custPhone->Name = L"custPhone";
			this->custPhone->Size = System::Drawing::Size(158, 20);
			this->custPhone->TabIndex = 4;
			// 
			// custAddress2
			// 
			this->custAddress2->Location = System::Drawing::Point(80, 80);
			this->custAddress2->Name = L"custAddress2";
			this->custAddress2->Size = System::Drawing::Size(158, 20);
			this->custAddress2->TabIndex = 3;
			// 
			// custAddress1
			// 
			this->custAddress1->Location = System::Drawing::Point(80, 55);
			this->custAddress1->Name = L"custAddress1";
			this->custAddress1->Size = System::Drawing::Size(158, 20);
			this->custAddress1->TabIndex = 2;
			// 
			// custName
			// 
			this->custName->Location = System::Drawing::Point(80, 30);
			this->custName->Name = L"custName";
			this->custName->Size = System::Drawing::Size(158, 20);
			this->custName->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Email:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Telephone: *";
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(50, 83);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(11, 13);
			this->label59->TabIndex = 23;
			this->label59->Text = L"*";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 58);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Address: *";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(6, 33);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(45, 13);
			this->label53->TabIndex = 24;
			this->label53->Text = L"Name: *";
			// 
			// groupBox22
			// 
			this->groupBox22->BackColor = System::Drawing::Color::Transparent;
			this->groupBox22->Controls->Add(this->fileNumber);
			this->groupBox22->Controls->Add(this->investEmail);
			this->groupBox22->Controls->Add(this->investPhone);
			this->groupBox22->Controls->Add(this->investName);
			this->groupBox22->Controls->Add(this->investConclude);
			this->groupBox22->Controls->Add(this->investStart);
			this->groupBox22->Controls->Add(this->investVisit);
			this->groupBox22->Controls->Add(this->investReceive);
			this->groupBox22->Controls->Add(this->label51);
			this->groupBox22->Controls->Add(this->label50);
			this->groupBox22->Controls->Add(this->label48);
			this->groupBox22->Controls->Add(this->label15);
			this->groupBox22->Controls->Add(this->label47);
			this->groupBox22->Controls->Add(this->label9);
			this->groupBox22->Controls->Add(this->label2);
			this->groupBox22->Controls->Add(this->label42);
			this->groupBox22->Location = System::Drawing::Point(377, 239);
			this->groupBox22->Name = L"groupBox22";
			this->groupBox22->Size = System::Drawing::Size(610, 161);
			this->groupBox22->TabIndex = 28;
			this->groupBox22->TabStop = false;
			this->groupBox22->Text = L"Investigation Information";
			// 
			// fileNumber
			// 
			this->fileNumber->Location = System::Drawing::Point(160, 108);
			this->fileNumber->MaximumSize = System::Drawing::Size(3000, 3000);
			this->fileNumber->Name = L"fileNumber";
			this->fileNumber->Size = System::Drawing::Size(132, 20);
			this->fileNumber->TabIndex = 22;
			// 
			// investEmail
			// 
			this->investEmail->Location = System::Drawing::Point(160, 80);
			this->investEmail->MaximumSize = System::Drawing::Size(3000, 3000);
			this->investEmail->Name = L"investEmail";
			this->investEmail->Size = System::Drawing::Size(132, 20);
			this->investEmail->TabIndex = 22;
			// 
			// investPhone
			// 
			this->investPhone->Location = System::Drawing::Point(160, 54);
			this->investPhone->Name = L"investPhone";
			this->investPhone->Size = System::Drawing::Size(132, 20);
			this->investPhone->TabIndex = 22;
			// 
			// investName
			// 
			this->investName->Location = System::Drawing::Point(160, 28);
			this->investName->Name = L"investName";
			this->investName->Size = System::Drawing::Size(132, 20);
			this->investName->TabIndex = 17;
			// 
			// investConclude
			// 
			this->investConclude->Location = System::Drawing::Point(452, 108);
			this->investConclude->Mask = L"0000/00/00";
			this->investConclude->Name = L"investConclude";
			this->investConclude->Size = System::Drawing::Size(132, 20);
			this->investConclude->TabIndex = 21;
			this->investConclude->Leave += gcnew System::EventHandler(this, &Form1::investReceive_Leave);
			this->investConclude->Enter += gcnew System::EventHandler(this, &Form1::investReceive_Enter);
			// 
			// investStart
			// 
			this->investStart->Location = System::Drawing::Point(452, 82);
			this->investStart->Mask = L"0000/00/00";
			this->investStart->Name = L"investStart";
			this->investStart->Size = System::Drawing::Size(132, 20);
			this->investStart->TabIndex = 20;
			this->investStart->Leave += gcnew System::EventHandler(this, &Form1::investReceive_Leave);
			this->investStart->Enter += gcnew System::EventHandler(this, &Form1::investReceive_Enter);
			// 
			// investVisit
			// 
			this->investVisit->Location = System::Drawing::Point(452, 56);
			this->investVisit->Mask = L"0000/00/00";
			this->investVisit->Name = L"investVisit";
			this->investVisit->Size = System::Drawing::Size(132, 20);
			this->investVisit->TabIndex = 19;
			this->investVisit->Leave += gcnew System::EventHandler(this, &Form1::investReceive_Leave);
			this->investVisit->Enter += gcnew System::EventHandler(this, &Form1::investReceive_Enter);
			// 
			// investReceive
			// 
			this->investReceive->Location = System::Drawing::Point(452, 30);
			this->investReceive->Mask = L"0000/00/00";
			this->investReceive->Name = L"investReceive";
			this->investReceive->Size = System::Drawing::Size(132, 20);
			this->investReceive->TabIndex = 18;
			this->investReceive->Leave += gcnew System::EventHandler(this, &Form1::investReceive_Leave);
			this->investReceive->Enter += gcnew System::EventHandler(this, &Form1::investReceive_Enter);
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(298, 111);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(157, 13);
			this->label51->TabIndex = 0;
			this->label51->Text = L"Date Investigation Concluded: *";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(298, 85);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(140, 13);
			this->label50->TabIndex = 0;
			this->label50->Text = L"Date Investigation Started: *";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(298, 59);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(122, 13);
			this->label48->TabIndex = 0;
			this->label48->Text = L"Date of Initial Site Visit: *";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 111);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(66, 13);
			this->label15->TabIndex = 0;
			this->label15->Text = L"File Number:";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(298, 33);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(138, 13);
			this->label47->TabIndex = 0;
			this->label47->Text = L"Date Complaint Received: *";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 83);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Investigator Email:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Investigator Telephone: *";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(6, 31);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(103, 13);
			this->label42->TabIndex = 0;
			this->label42->Text = L"Investigator Name: *";
			// 
			// groupBox21
			// 
			this->groupBox21->BackColor = System::Drawing::Color::Transparent;
			this->groupBox21->Controls->Add(this->utilWebsite);
			this->groupBox21->Controls->Add(this->utilEmail);
			this->groupBox21->Controls->Add(this->utilPhone);
			this->groupBox21->Controls->Add(this->utilAddress2);
			this->groupBox21->Controls->Add(this->utilAddress1);
			this->groupBox21->Controls->Add(this->utilName);
			this->groupBox21->Controls->Add(this->label39);
			this->groupBox21->Controls->Add(this->label38);
			this->groupBox21->Controls->Add(this->label23);
			this->groupBox21->Controls->Add(this->label22);
			this->groupBox21->Controls->Add(this->label1);
			this->groupBox21->Location = System::Drawing::Point(377, 39);
			this->groupBox21->Name = L"groupBox21";
			this->groupBox21->Size = System::Drawing::Size(300, 194);
			this->groupBox21->TabIndex = 27;
			this->groupBox21->TabStop = false;
			this->groupBox21->Text = L"Utility Information";
			// 
			// utilWebsite
			// 
			this->utilWebsite->BackColor = System::Drawing::Color::Gainsboro;
			this->utilWebsite->Location = System::Drawing::Point(80, 154);
			this->utilWebsite->MaximumSize = System::Drawing::Size(3000, 3000);
			this->utilWebsite->Name = L"utilWebsite";
			this->utilWebsite->ReadOnly = true;
			this->utilWebsite->Size = System::Drawing::Size(192, 20);
			this->utilWebsite->TabIndex = 16;
			this->utilWebsite->Text = L"www.wnhydro.com";
			// 
			// utilEmail
			// 
			this->utilEmail->BackColor = System::Drawing::Color::Gainsboro;
			this->utilEmail->Location = System::Drawing::Point(80, 129);
			this->utilEmail->MaximumSize = System::Drawing::Size(3000, 3000);
			this->utilEmail->Name = L"utilEmail";
			this->utilEmail->ReadOnly = true;
			this->utilEmail->Size = System::Drawing::Size(192, 20);
			this->utilEmail->TabIndex = 15;
			this->utilEmail->Text = L"metertechs@wnhydro.com";
			// 
			// utilPhone
			// 
			this->utilPhone->BackColor = System::Drawing::Color::Gainsboro;
			this->utilPhone->Location = System::Drawing::Point(80, 104);
			this->utilPhone->MaximumSize = System::Drawing::Size(3000, 3000);
			this->utilPhone->Name = L"utilPhone";
			this->utilPhone->ReadOnly = true;
			this->utilPhone->Size = System::Drawing::Size(192, 20);
			this->utilPhone->TabIndex = 14;
			this->utilPhone->Text = L"519-888-5557";
			this->utilPhone->TextChanged += gcnew System::EventHandler(this, &Form1::utilPhone_TextChanged);
			// 
			// utilAddress2
			// 
			this->utilAddress2->BackColor = System::Drawing::Color::Gainsboro;
			this->utilAddress2->Location = System::Drawing::Point(80, 79);
			this->utilAddress2->MaximumSize = System::Drawing::Size(3000, 3000);
			this->utilAddress2->Name = L"utilAddress2";
			this->utilAddress2->ReadOnly = true;
			this->utilAddress2->Size = System::Drawing::Size(192, 20);
			this->utilAddress2->TabIndex = 13;
			this->utilAddress2->Text = L"Waterloo, On, N2J 4A3";
			// 
			// utilAddress1
			// 
			this->utilAddress1->BackColor = System::Drawing::Color::Gainsboro;
			this->utilAddress1->Location = System::Drawing::Point(80, 54);
			this->utilAddress1->MaximumSize = System::Drawing::Size(3000, 3000);
			this->utilAddress1->Name = L"utilAddress1";
			this->utilAddress1->ReadOnly = true;
			this->utilAddress1->Size = System::Drawing::Size(192, 20);
			this->utilAddress1->TabIndex = 12;
			this->utilAddress1->Text = L"P.O. Box 640, 526 Country Squire Rd.";
			// 
			// utilName
			// 
			this->utilName->BackColor = System::Drawing::Color::Gainsboro;
			this->utilName->Location = System::Drawing::Point(80, 29);
			this->utilName->MaximumSize = System::Drawing::Size(3000, 3000);
			this->utilName->Name = L"utilName";
			this->utilName->ReadOnly = true;
			this->utilName->Size = System::Drawing::Size(192, 20);
			this->utilName->TabIndex = 11;
			this->utilName->Text = L"Waterloo North Hydro Inc.";
			this->utilName->TextChanged += gcnew System::EventHandler(this, &Form1::utilName_TextChanged);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(6, 157);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(46, 13);
			this->label39->TabIndex = 19;
			this->label39->Text = L"Website";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(6, 132);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(35, 13);
			this->label38->TabIndex = 19;
			this->label38->Text = L"Email:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 107);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(61, 13);
			this->label23->TabIndex = 19;
			this->label23->Text = L"Telephone:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(6, 57);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(48, 13);
			this->label22->TabIndex = 19;
			this->label22->Text = L"Address:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Name:";
			// 
			// tabPage7
			// 
			this->tabPage7->BackColor = System::Drawing::Color::White;
			this->tabPage7->Controls->Add(this->groupBox25);
			this->tabPage7->Controls->Add(this->groupBox24);
			this->tabPage7->Controls->Add(this->radio5Step);
			this->tabPage7->Controls->Add(this->step2Radio);
			this->tabPage7->Controls->Add(this->groupBox19);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(1019, 611);
			this->tabPage7->TabIndex = 7;
			this->tabPage7->Text = L"Settings";
			this->tabPage7->Leave += gcnew System::EventHandler(this, &Form1::tabPage14_Leave);
			// 
			// groupBox25
			// 
			this->groupBox25->Controls->Add(this->channel4I);
			this->groupBox25->Controls->Add(this->radioButton3);
			this->groupBox25->Location = System::Drawing::Point(546, 272);
			this->groupBox25->Name = L"groupBox25";
			this->groupBox25->Size = System::Drawing::Size(264, 70);
			this->groupBox25->TabIndex = 66;
			this->groupBox25->TabStop = false;
			this->groupBox25->Text = L"Vcc Input";
			// 
			// channel4I
			// 
			this->channel4I->AutoSize = true;
			this->channel4I->Checked = true;
			this->channel4I->Location = System::Drawing::Point(20, 35);
			this->channel4I->Name = L"channel4I";
			this->channel4I->Size = System::Drawing::Size(96, 17);
			this->channel4I->TabIndex = 7;
			this->channel4I->TabStop = true;
			this->channel4I->Text = L"Channel 4 (AC)";
			this->channel4I->UseVisualStyleBackColor = true;
			this->channel4I->CheckedChanged += gcnew System::EventHandler(this, &Form1::channel4I_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(149, 35);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(97, 17);
			this->radioButton3->TabIndex = 7;
			this->radioButton3->Text = L"Channel 5 (DC)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// groupBox24
			// 
			this->groupBox24->Controls->Add(this->phaseRadio3);
			this->groupBox24->Controls->Add(this->phaseRadio1);
			this->groupBox24->Location = System::Drawing::Point(208, 272);
			this->groupBox24->Name = L"groupBox24";
			this->groupBox24->Size = System::Drawing::Size(264, 70);
			this->groupBox24->TabIndex = 65;
			this->groupBox24->TabStop = false;
			this->groupBox24->Text = L"Service Type";
			// 
			// phaseRadio3
			// 
			this->phaseRadio3->AutoSize = true;
			this->phaseRadio3->Location = System::Drawing::Point(149, 35);
			this->phaseRadio3->Name = L"phaseRadio3";
			this->phaseRadio3->Size = System::Drawing::Size(86, 17);
			this->phaseRadio3->TabIndex = 59;
			this->phaseRadio3->TabStop = true;
			this->phaseRadio3->Text = L"Three Phase";
			this->phaseRadio3->UseVisualStyleBackColor = true;
			// 
			// phaseRadio1
			// 
			this->phaseRadio1->AutoSize = true;
			this->phaseRadio1->Checked = true;
			this->phaseRadio1->Location = System::Drawing::Point(21, 35);
			this->phaseRadio1->Name = L"phaseRadio1";
			this->phaseRadio1->Size = System::Drawing::Size(87, 17);
			this->phaseRadio1->TabIndex = 58;
			this->phaseRadio1->TabStop = true;
			this->phaseRadio1->Text = L"Single Phase";
			this->phaseRadio1->UseVisualStyleBackColor = true;
			this->phaseRadio1->CheckedChanged += gcnew System::EventHandler(this, &Form1::phaseRadio1_CheckedChanged);
			// 
			// radio5Step
			// 
			this->radio5Step->AutoSize = true;
			this->radio5Step->Checked = true;
			this->radio5Step->Location = System::Drawing::Point(357, 348);
			this->radio5Step->Name = L"radio5Step";
			this->radio5Step->Size = System::Drawing::Size(132, 17);
			this->radio5Step->TabIndex = 63;
			this->radio5Step->TabStop = true;
			this->radio5Step->Text = L"5 Steps on One Phase";
			this->radio5Step->UseVisualStyleBackColor = true;
			this->radio5Step->Visible = false;
			this->radio5Step->CheckedChanged += gcnew System::EventHandler(this, &Form1::radio5Step_CheckedChanged);
			// 
			// step2Radio
			// 
			this->step2Radio->AutoSize = true;
			this->step2Radio->Location = System::Drawing::Point(357, 369);
			this->step2Radio->Name = L"step2Radio";
			this->step2Radio->Size = System::Drawing::Size(145, 17);
			this->step2Radio->TabIndex = 62;
			this->step2Radio->Text = L"2 Steps on Three Phases";
			this->step2Radio->UseVisualStyleBackColor = true;
			this->step2Radio->Visible = false;
			// 
			// groupBox19
			// 
			this->groupBox19->Controls->Add(this->label109);
			this->groupBox19->Controls->Add(this->label108);
			this->groupBox19->Controls->Add(this->label10);
			this->groupBox19->Controls->Add(this->label63);
			this->groupBox19->Controls->Add(this->label33);
			this->groupBox19->Controls->Add(this->cal3Text);
			this->groupBox19->Controls->Add(this->cal4Text);
			this->groupBox19->Controls->Add(this->cal5Text);
			this->groupBox19->Controls->Add(this->cal2Text);
			this->groupBox19->Controls->Add(this->cal1Text);
			this->groupBox19->Location = System::Drawing::Point(208, 71);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(602, 184);
			this->groupBox19->TabIndex = 8;
			this->groupBox19->TabStop = false;
			this->groupBox19->Text = L"Channel Calibration";
			// 
			// label109
			// 
			this->label109->AutoSize = true;
			this->label109->Location = System::Drawing::Point(324, 66);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(58, 13);
			this->label109->TabIndex = 1;
			this->label109->Text = L"Channel 4:";
			// 
			// label108
			// 
			this->label108->AutoSize = true;
			this->label108->Location = System::Drawing::Point(83, 119);
			this->label108->Name = L"label108";
			this->label108->Size = System::Drawing::Size(58, 13);
			this->label108->TabIndex = 1;
			this->label108->Text = L"Channel 3:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(324, 103);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(58, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Channel 5:";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(83, 82);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(58, 13);
			this->label63->TabIndex = 1;
			this->label63->Text = L"Channel 2:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(83, 42);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(58, 13);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Channel 1:";
			// 
			// cal3Text
			// 
			this->cal3Text->Location = System::Drawing::Point(182, 116);
			this->cal3Text->Name = L"cal3Text";
			this->cal3Text->Size = System::Drawing::Size(100, 20);
			this->cal3Text->TabIndex = 5;
			this->cal3Text->Text = L"1";
			this->cal3Text->TextChanged += gcnew System::EventHandler(this, &Form1::cal3Text_TextChanged);
			this->cal3Text->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->cal3Text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// cal4Text
			// 
			this->cal4Text->Location = System::Drawing::Point(418, 63);
			this->cal4Text->Name = L"cal4Text";
			this->cal4Text->Size = System::Drawing::Size(100, 20);
			this->cal4Text->TabIndex = 6;
			this->cal4Text->Text = L"1";
			this->cal4Text->TextChanged += gcnew System::EventHandler(this, &Form1::cal4Text_TextChanged);
			this->cal4Text->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->cal4Text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// cal5Text
			// 
			this->cal5Text->Location = System::Drawing::Point(418, 100);
			this->cal5Text->Name = L"cal5Text";
			this->cal5Text->Size = System::Drawing::Size(100, 20);
			this->cal5Text->TabIndex = 4;
			this->cal5Text->Text = L"1";
			this->cal5Text->TextChanged += gcnew System::EventHandler(this, &Form1::cal5Text_TextChanged);
			this->cal5Text->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->cal5Text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// cal2Text
			// 
			this->cal2Text->Location = System::Drawing::Point(182, 79);
			this->cal2Text->Name = L"cal2Text";
			this->cal2Text->Size = System::Drawing::Size(100, 20);
			this->cal2Text->TabIndex = 4;
			this->cal2Text->Text = L"1";
			this->cal2Text->TextChanged += gcnew System::EventHandler(this, &Form1::cal2Text_TextChanged);
			this->cal2Text->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->cal2Text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// cal1Text
			// 
			this->cal1Text->BackColor = System::Drawing::SystemColors::Window;
			this->cal1Text->Location = System::Drawing::Point(182, 42);
			this->cal1Text->Name = L"cal1Text";
			this->cal1Text->Size = System::Drawing::Size(100, 20);
			this->cal1Text->TabIndex = 3;
			this->cal1Text->Text = L"1";
			this->cal1Text->TextChanged += gcnew System::EventHandler(this, &Form1::cal1Text_TextChanged);
			this->cal1Text->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->cal1Text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage1->Controls->Add(this->tabControl2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1019, 611);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Form 1";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Enter += gcnew System::EventHandler(this, &Form1::tabPage5_Enter);
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage5);
			this->tabControl2->Controls->Add(this->tabPage6);
			this->tabControl2->Location = System::Drawing::Point(6, 6);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(1013, 602);
			this->tabControl2->TabIndex = 15;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::White;
			this->tabPage5->Controls->Add(this->calendar2);
			this->tabPage5->Controls->Add(this->farmLocationF1);
			this->tabPage5->Controls->Add(this->custNameF1);
			this->tabPage5->Controls->Add(this->label5);
			this->tabPage5->Controls->Add(this->form1DateText);
			this->tabPage5->Controls->Add(this->commentText);
			this->tabPage5->Controls->Add(this->label58);
			this->tabPage5->Controls->Add(this->label21);
			this->tabPage5->Controls->Add(this->label106);
			this->tabPage5->Controls->Add(this->label16);
			this->tabPage5->Controls->Add(this->form1Grid);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1005, 576);
			this->tabPage5->TabIndex = 1;
			this->tabPage5->Text = L"Page 1";
			// 
			// calendar2
			// 
			this->calendar2->Location = System::Drawing::Point(299, 90);
			this->calendar2->Name = L"calendar2";
			this->calendar2->ShowToday = false;
			this->calendar2->TabIndex = 34;
			this->calendar2->Visible = false;
			this->calendar2->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Form1::calendar2_DateSelected);
			this->calendar2->Leave += gcnew System::EventHandler(this, &Form1::calendar2_Leave);
			// 
			// farmLocationF1
			// 
			this->farmLocationF1->Location = System::Drawing::Point(154, 147);
			this->farmLocationF1->Name = L"farmLocationF1";
			this->farmLocationF1->Size = System::Drawing::Size(133, 20);
			this->farmLocationF1->TabIndex = 35;
			// 
			// custNameF1
			// 
			this->custNameF1->Location = System::Drawing::Point(154, 122);
			this->custNameF1->Name = L"custNameF1";
			this->custNameF1->Size = System::Drawing::Size(133, 20);
			this->custNameF1->TabIndex = 35;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(878, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 13);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Input Commment:";
			this->label5->Visible = false;
			// 
			// form1DateText
			// 
			this->form1DateText->Location = System::Drawing::Point(154, 95);
			this->form1DateText->Mask = L"0000/00/00";
			this->form1DateText->Name = L"form1DateText";
			this->form1DateText->Size = System::Drawing::Size(133, 20);
			this->form1DateText->TabIndex = 32;
			this->form1DateText->Leave += gcnew System::EventHandler(this, &Form1::form1DateText_Leave);
			this->form1DateText->Enter += gcnew System::EventHandler(this, &Form1::form1DateText_Enter);
			// 
			// commentText
			// 
			this->commentText->BackColor = System::Drawing::Color::Moccasin;
			this->commentText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->commentText->Location = System::Drawing::Point(881, 192);
			this->commentText->Name = L"commentText";
			this->commentText->Size = System::Drawing::Size(121, 74);
			this->commentText->TabIndex = 31;
			this->commentText->Text = L"";
			this->commentText->Visible = false;
			this->commentText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::commentText_KeyDown);
			this->commentText->LostFocus += gcnew System::EventHandler(this, &Form1::commentText_LostFocus);
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(63, 150);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(77, 13);
			this->label58->TabIndex = 29;
			this->label58->Text = L"Farm Location:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(63, 125);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(85, 13);
			this->label21->TabIndex = 29;
			this->label21->Text = L"Customer Name:";
			// 
			// label106
			// 
			this->label106->AutoSize = true;
			this->label106->Location = System::Drawing::Point(63, 95);
			this->label106->Name = L"label106";
			this->label106->Size = System::Drawing::Size(33, 13);
			this->label106->TabIndex = 29;
			this->label106->Text = L"Date:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(363, 21);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(278, 60);
			this->label16->TabIndex = 17;
			this->label16->Text = L"Form 1\r\n\r\nAnimal Contact Test Data Record";
			this->label16->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// form1Grid
			// 
			this->form1Grid->AllowUserToResizeColumns = false;
			this->form1Grid->AllowUserToResizeRows = false;
			this->form1Grid->AutoGenerateColumns = false;
			this->form1Grid->BackgroundColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle22->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle22->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle22->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle22->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle22->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->form1Grid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle22;
			this->form1Grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->form1Grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->locIdDataGridViewTextBoxColumn, 
				this->descriptionDataGridViewTextBoxColumn, this->vwoShuntDataGridViewTextBoxColumn, this->vwShuntDataGridViewTextBoxColumn, 
				this->sourceResistanceDataGridViewTextBoxColumn});
			this->form1Grid->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->form1Grid->DataSource = this->form1DataBindingSource;
			this->form1Grid->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->form1Grid->Location = System::Drawing::Point(66, 176);
			this->form1Grid->Name = L"form1Grid";
			dataGridViewCellStyle24->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle24->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle24->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle24->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle24->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->form1Grid->RowHeadersDefaultCellStyle = dataGridViewCellStyle24;
			this->form1Grid->RowHeadersVisible = false;
			this->form1Grid->Size = System::Drawing::Size(806, 358);
			this->form1Grid->TabIndex = 5;
			this->form1Grid->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::form1Grid_CellMouseDoubleClick);
			this->form1Grid->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &Form1::dataError);
			this->form1Grid->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::form1Grid_KeyDown);
			// 
			// locIdDataGridViewTextBoxColumn
			// 
			this->locIdDataGridViewTextBoxColumn->DataPropertyName = L"locId";
			this->locIdDataGridViewTextBoxColumn->HeaderText = L"Animal Contact Location ID#";
			this->locIdDataGridViewTextBoxColumn->Name = L"locIdDataGridViewTextBoxColumn";
			this->locIdDataGridViewTextBoxColumn->ReadOnly = true;
			// 
			// descriptionDataGridViewTextBoxColumn
			// 
			this->descriptionDataGridViewTextBoxColumn->DataPropertyName = L"description";
			this->descriptionDataGridViewTextBoxColumn->HeaderText = L"Description of Location & Animal Contact Points";
			this->descriptionDataGridViewTextBoxColumn->Name = L"descriptionDataGridViewTextBoxColumn";
			this->descriptionDataGridViewTextBoxColumn->Width = 400;
			// 
			// vwoShuntDataGridViewTextBoxColumn
			// 
			this->vwoShuntDataGridViewTextBoxColumn->DataPropertyName = L"vwoShunt";
			this->vwoShuntDataGridViewTextBoxColumn->HeaderText = L"Voltage w/o 500 Ohm Shunt Resistor (Vcc)";
			this->vwoShuntDataGridViewTextBoxColumn->Name = L"vwoShuntDataGridViewTextBoxColumn";
			// 
			// vwShuntDataGridViewTextBoxColumn
			// 
			this->vwShuntDataGridViewTextBoxColumn->DataPropertyName = L"vwShunt";
			this->vwShuntDataGridViewTextBoxColumn->HeaderText = L"Voltage w/ 500 Ohm Shunt Resistor (Vcc)";
			this->vwShuntDataGridViewTextBoxColumn->Name = L"vwShuntDataGridViewTextBoxColumn";
			// 
			// sourceResistanceDataGridViewTextBoxColumn
			// 
			this->sourceResistanceDataGridViewTextBoxColumn->DataPropertyName = L"sourceResistance";
			dataGridViewCellStyle23->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle23->Format = L"N2";
			dataGridViewCellStyle23->NullValue = nullptr;
			this->sourceResistanceDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle23;
			this->sourceResistanceDataGridViewTextBoxColumn->HeaderText = L"Source Resistance (Rsource)";
			this->sourceResistanceDataGridViewTextBoxColumn->Name = L"sourceResistanceDataGridViewTextBoxColumn";
			this->sourceResistanceDataGridViewTextBoxColumn->ReadOnly = true;
			this->sourceResistanceDataGridViewTextBoxColumn->ToolTipText = L"Rsource = (Voc - Vcc) / Vcc x Rshunt";
			// 
			// tabPage6
			// 
			this->tabPage6->BackColor = System::Drawing::Color::White;
			this->tabPage6->Controls->Add(this->dataGridView1);
			this->tabPage6->Controls->Add(this->label17);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(1005, 576);
			this->tabPage6->TabIndex = 2;
			this->tabPage6->Text = L"Page 2";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle25->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle25->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle25->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle25->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle25->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle25;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->locIdDataGridViewTextBoxColumn1, 
				this->commentDataGridViewTextBoxColumn});
			this->dataGridView1->DataSource = this->form1DataBindingSource;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->GridColor = System::Drawing::Color::DarkGray;
			this->dataGridView1->Location = System::Drawing::Point(111, 102);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			dataGridViewCellStyle26->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle26->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle26->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle26->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle26->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle26;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(782, 436);
			this->dataGridView1->TabIndex = 19;
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &Form1::dataError);
			// 
			// locIdDataGridViewTextBoxColumn1
			// 
			this->locIdDataGridViewTextBoxColumn1->DataPropertyName = L"locId";
			this->locIdDataGridViewTextBoxColumn1->HeaderText = L"Animal Contact Location ID #";
			this->locIdDataGridViewTextBoxColumn1->Name = L"locIdDataGridViewTextBoxColumn1";
			this->locIdDataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// commentDataGridViewTextBoxColumn
			// 
			this->commentDataGridViewTextBoxColumn->DataPropertyName = L"comment";
			this->commentDataGridViewTextBoxColumn->HeaderText = L"Comment";
			this->commentDataGridViewTextBoxColumn->Name = L"commentDataGridViewTextBoxColumn";
			this->commentDataGridViewTextBoxColumn->Width = 675;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(372, 21);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(261, 60);
			this->label17->TabIndex = 18;
			this->label17->Text = L"Form 1 (concluded)\r\n\r\nAnimal Contact Test Comments";
			this->label17->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::White;
			this->tabPage2->Controls->Add(this->form2FileText);
			this->tabPage2->Controls->Add(this->groupBox18);
			this->tabPage2->Controls->Add(this->viewGraph);
			this->tabPage2->Controls->Add(this->openButt);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1019, 611);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Form 2";
			// 
			// form2FileText
			// 
			this->form2FileText->AutoSize = true;
			this->form2FileText->ForeColor = System::Drawing::Color::Red;
			this->form2FileText->Location = System::Drawing::Point(98, 153);
			this->form2FileText->Name = L"form2FileText";
			this->form2FileText->Size = System::Drawing::Size(100, 13);
			this->form2FileText->TabIndex = 56;
			this->form2FileText->Text = L"Please open a file...";
			// 
			// groupBox18
			// 
			this->groupBox18->BackColor = System::Drawing::Color::Transparent;
			this->groupBox18->Controls->Add(this->locCombo);
			this->groupBox18->Controls->Add(this->label12);
			this->groupBox18->Controls->Add(this->form2StopText);
			this->groupBox18->Controls->Add(this->label13);
			this->groupBox18->Controls->Add(this->form2StartText);
			this->groupBox18->Controls->Add(this->label14);
			this->groupBox18->Location = System::Drawing::Point(250, 77);
			this->groupBox18->Name = L"groupBox18";
			this->groupBox18->Size = System::Drawing::Size(518, 106);
			this->groupBox18->TabIndex = 15;
			this->groupBox18->TabStop = false;
			this->groupBox18->Text = L"Test Information";
			// 
			// locCombo
			// 
			this->locCombo->DataSource = this->form1DataBindingSource;
			this->locCombo->DisplayMember = L"locId";
			this->locCombo->FormattingEnabled = true;
			this->locCombo->Location = System::Drawing::Point(161, 73);
			this->locCombo->Name = L"locCombo";
			this->locCombo->Size = System::Drawing::Size(82, 21);
			this->locCombo->TabIndex = 15;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 41);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(86, 13);
			this->label12->TabIndex = 6;
			this->label12->Text = L"Start Date/Time:";
			// 
			// form2StopText
			// 
			this->form2StopText->BackColor = System::Drawing::Color::Gainsboro;
			this->form2StopText->Location = System::Drawing::Point(374, 38);
			this->form2StopText->Name = L"form2StopText";
			this->form2StopText->ReadOnly = true;
			this->form2StopText->Size = System::Drawing::Size(130, 20);
			this->form2StopText->TabIndex = 14;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 67);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(125, 26);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Animal Contact Location \r\nIdentification No:";
			// 
			// form2StartText
			// 
			this->form2StartText->BackColor = System::Drawing::Color::Gainsboro;
			this->form2StartText->Location = System::Drawing::Point(113, 38);
			this->form2StartText->Name = L"form2StartText";
			this->form2StartText->ReadOnly = true;
			this->form2StartText->Size = System::Drawing::Size(130, 20);
			this->form2StartText->TabIndex = 14;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(267, 41);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(86, 13);
			this->label14->TabIndex = 8;
			this->label14->Text = L"Stop Date/Time:";
			// 
			// viewGraph
			// 
			this->viewGraph->BackColor = System::Drawing::Color::AliceBlue;
			this->viewGraph->Enabled = false;
			this->viewGraph->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"viewGraph.Image")));
			this->viewGraph->Location = System::Drawing::Point(159, 169);
			this->viewGraph->Name = L"viewGraph";
			this->viewGraph->Size = System::Drawing::Size(52, 37);
			this->viewGraph->TabIndex = 13;
			this->viewGraph->UseVisualStyleBackColor = false;
			this->viewGraph->Click += gcnew System::EventHandler(this, &Form1::viewGraph_Click);
			// 
			// openButt
			// 
			this->openButt->BackColor = System::Drawing::Color::AliceBlue;
			this->openButt->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openButt.Image")));
			this->openButt->Location = System::Drawing::Point(101, 169);
			this->openButt->Name = L"openButt";
			this->openButt->Size = System::Drawing::Size(52, 37);
			this->openButt->TabIndex = 13;
			this->openButt->UseVisualStyleBackColor = false;
			this->openButt->Click += gcnew System::EventHandler(this, &Form1::openButt_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->AutoGenerateColumns = false;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle27->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle27->Format = L"N2";
			dataGridViewCellStyle27->NullValue = nullptr;
			dataGridViewCellStyle27->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle27->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle27;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->hourDataGridViewTextBoxColumn, 
				this->highestVccDataGridViewTextBoxColumn, this->aContactVoltDataGridViewTextBoxColumn, this->pN2RVoltDataGridViewTextBoxColumn, 
				this->sN2RVoltDataGridViewTextBoxColumn, this->pN2SNVoltDataGridViewTextBoxColumn, this->timeVccExceedsDataGridViewTextBoxColumn});
			this->dataGridView2->DataSource = this->form2DataBindingSource;
			this->dataGridView2->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView2->Location = System::Drawing::Point(101, 212);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(817, 386);
			this->dataGridView2->TabIndex = 11;
			// 
			// hourDataGridViewTextBoxColumn
			// 
			this->hourDataGridViewTextBoxColumn->DataPropertyName = L"hour";
			dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->hourDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle28;
			this->hourDataGridViewTextBoxColumn->HeaderText = L"Hour";
			this->hourDataGridViewTextBoxColumn->Name = L"hourDataGridViewTextBoxColumn";
			this->hourDataGridViewTextBoxColumn->ReadOnly = true;
			this->hourDataGridViewTextBoxColumn->Width = 50;
			// 
			// highestVccDataGridViewTextBoxColumn
			// 
			this->highestVccDataGridViewTextBoxColumn->DataPropertyName = L"highestVcc";
			dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->highestVccDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle29;
			this->highestVccDataGridViewTextBoxColumn->HeaderText = L"Time Highest Steady State Vcc Recorded in Hour";
			this->highestVccDataGridViewTextBoxColumn->Name = L"highestVccDataGridViewTextBoxColumn";
			this->highestVccDataGridViewTextBoxColumn->ReadOnly = true;
			this->highestVccDataGridViewTextBoxColumn->Width = 125;
			// 
			// aContactVoltDataGridViewTextBoxColumn
			// 
			this->aContactVoltDataGridViewTextBoxColumn->DataPropertyName = L"aContactVolt";
			dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle30->Format = L"N2";
			dataGridViewCellStyle30->NullValue = nullptr;
			this->aContactVoltDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle30;
			this->aContactVoltDataGridViewTextBoxColumn->HeaderText = L"Animal Contact Voltage Across Shunt Resistor Vcc (SVCh4 AC)";
			this->aContactVoltDataGridViewTextBoxColumn->Name = L"aContactVoltDataGridViewTextBoxColumn";
			this->aContactVoltDataGridViewTextBoxColumn->ReadOnly = true;
			this->aContactVoltDataGridViewTextBoxColumn->Width = 125;
			// 
			// pN2RVoltDataGridViewTextBoxColumn
			// 
			this->pN2RVoltDataGridViewTextBoxColumn->DataPropertyName = L"pN2RVolt";
			dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle31->Format = L"N2";
			dataGridViewCellStyle31->NullValue = nullptr;
			this->pN2RVoltDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle31;
			this->pN2RVoltDataGridViewTextBoxColumn->HeaderText = L"Primary Neutral to Reference Ground Rod Voltage Vp (SVCh1)";
			this->pN2RVoltDataGridViewTextBoxColumn->Name = L"pN2RVoltDataGridViewTextBoxColumn";
			this->pN2RVoltDataGridViewTextBoxColumn->ReadOnly = true;
			this->pN2RVoltDataGridViewTextBoxColumn->Width = 125;
			// 
			// sN2RVoltDataGridViewTextBoxColumn
			// 
			this->sN2RVoltDataGridViewTextBoxColumn->DataPropertyName = L"sN2RVolt";
			dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle32->Format = L"N2";
			dataGridViewCellStyle32->NullValue = nullptr;
			this->sN2RVoltDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle32;
			this->sN2RVoltDataGridViewTextBoxColumn->HeaderText = L"Secondary Neutral to Reference Ground Rod Voltage Vs (SVCh3)";
			this->sN2RVoltDataGridViewTextBoxColumn->Name = L"sN2RVoltDataGridViewTextBoxColumn";
			this->sN2RVoltDataGridViewTextBoxColumn->ReadOnly = true;
			this->sN2RVoltDataGridViewTextBoxColumn->Width = 125;
			// 
			// pN2SNVoltDataGridViewTextBoxColumn
			// 
			this->pN2SNVoltDataGridViewTextBoxColumn->DataPropertyName = L"pN2SNVolt";
			dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle33->Format = L"N2";
			dataGridViewCellStyle33->NullValue = nullptr;
			this->pN2SNVoltDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle33;
			this->pN2SNVoltDataGridViewTextBoxColumn->HeaderText = L"Primary Neutral to Secondary Neutral Voltage Vps (SVCh2)";
			this->pN2SNVoltDataGridViewTextBoxColumn->Name = L"pN2SNVoltDataGridViewTextBoxColumn";
			this->pN2SNVoltDataGridViewTextBoxColumn->ReadOnly = true;
			this->pN2SNVoltDataGridViewTextBoxColumn->Width = 125;
			// 
			// timeVccExceedsDataGridViewTextBoxColumn
			// 
			this->timeVccExceedsDataGridViewTextBoxColumn->DataPropertyName = L"timeVccExceeds";
			dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->timeVccExceedsDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle34;
			this->timeVccExceedsDataGridViewTextBoxColumn->HeaderText = L"Estimated Time During Hour Vcc Exceeds ACC/ACV Threshold (hh:mm:ss)";
			this->timeVccExceedsDataGridViewTextBoxColumn->Name = L"timeVccExceedsDataGridViewTextBoxColumn";
			this->timeVccExceedsDataGridViewTextBoxColumn->ReadOnly = true;
			this->timeVccExceedsDataGridViewTextBoxColumn->Width = 125;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(367, 189);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(284, 20);
			this->label18->TabIndex = 2;
			this->label18->Text = L"FARM STRAY VOLTAGE TEST DATA";
			this->label18->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(407, 14);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(204, 60);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Form 2\r\n\r\nFarm Stray Voltage Test";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::White;
			this->tabPage3->Controls->Add(this->phase3ses);
			this->tabPage3->Controls->Add(this->phases);
			this->tabPage3->Controls->Add(this->phaseBox);
			this->tabPage3->Controls->Add(this->clearButton);
			this->tabPage3->Controls->Add(this->enterData);
			this->tabPage3->Controls->Add(this->form3StopTime);
			this->tabPage3->Controls->Add(this->form3StartTime);
			this->tabPage3->Controls->Add(this->label19);
			this->tabPage3->Controls->Add(this->form3Stop);
			this->tabPage3->Controls->Add(this->vcc11);
			this->tabPage3->Controls->Add(this->form3Start);
			this->tabPage3->Controls->Add(this->vp11);
			this->tabPage3->Controls->Add(this->groupBox17);
			this->tabPage3->Controls->Add(this->vs11);
			this->tabPage3->Controls->Add(this->groupBox16);
			this->tabPage3->Controls->Add(this->label52);
			this->tabPage3->Controls->Add(this->time11);
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1019, 611);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Form 3";
			// 
			// phase3ses
			// 
			this->phase3ses->AutoSize = true;
			this->phase3ses->BackColor = System::Drawing::Color::Transparent;
			this->phase3ses->Location = System::Drawing::Point(719, 300);
			this->phase3ses->Name = L"phase3ses";
			this->phase3ses->Size = System::Drawing::Size(94, 13);
			this->phase3ses->TabIndex = 58;
			this->phase3ses->Text = L"5 Steps on Phase:";
			this->phase3ses->Visible = false;
			// 
			// phases
			// 
			this->phases->AutoSize = true;
			this->phases->BackColor = System::Drawing::Color::Transparent;
			this->phases->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->phases->Location = System::Drawing::Point(487, 300);
			this->phases->Name = L"phases";
			this->phases->Size = System::Drawing::Size(145, 13);
			this->phases->TabIndex = 58;
			this->phases->Text = L"Single Phase Secondary";
			// 
			// phaseBox
			// 
			this->phaseBox->FormattingEnabled = true;
			this->phaseBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"A", L"B", L"C"});
			this->phaseBox->Location = System::Drawing::Point(819, 297);
			this->phaseBox->Name = L"phaseBox";
			this->phaseBox->Size = System::Drawing::Size(67, 21);
			this->phaseBox->TabIndex = 57;
			this->phaseBox->Visible = false;
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(893, 518);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 52;
			this->clearButton->Text = L"Clear Data";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Form1::clearButton_Click);
			// 
			// enterData
			// 
			this->enterData->Location = System::Drawing::Point(893, 547);
			this->enterData->Name = L"enterData";
			this->enterData->Size = System::Drawing::Size(75, 56);
			this->enterData->TabIndex = 51;
			this->enterData->Text = L"Process File Data";
			this->enterData->UseVisualStyleBackColor = true;
			this->enterData->Click += gcnew System::EventHandler(this, &Form1::enterData_Click);
			// 
			// form3StopTime
			// 
			this->form3StopTime->AutoSize = true;
			this->form3StopTime->BackColor = System::Drawing::Color::Transparent;
			this->form3StopTime->Location = System::Drawing::Point(122, 219);
			this->form3StopTime->Name = L"form3StopTime";
			this->form3StopTime->Size = System::Drawing::Size(35, 13);
			this->form3StopTime->TabIndex = 56;
			this->form3StopTime->Text = L"label9";
			this->form3StopTime->Visible = false;
			// 
			// form3StartTime
			// 
			this->form3StartTime->AutoSize = true;
			this->form3StartTime->BackColor = System::Drawing::Color::Transparent;
			this->form3StartTime->Location = System::Drawing::Point(122, 206);
			this->form3StartTime->Name = L"form3StartTime";
			this->form3StartTime->Size = System::Drawing::Size(35, 13);
			this->form3StartTime->TabIndex = 56;
			this->form3StartTime->Text = L"label9";
			this->form3StartTime->Visible = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::White;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(369, 13);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(280, 60);
			this->label19->TabIndex = 3;
			this->label19->Text = L"Form 3\r\n\r\nDistributor Contribution Test Data";
			this->label19->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// form3Stop
			// 
			this->form3Stop->AutoSize = true;
			this->form3Stop->BackColor = System::Drawing::Color::Transparent;
			this->form3Stop->Location = System::Drawing::Point(31, 219);
			this->form3Stop->Name = L"form3Stop";
			this->form3Stop->Size = System::Drawing::Size(89, 13);
			this->form3Stop->TabIndex = 55;
			this->form3Stop->Text = L"File Record Stop:";
			this->form3Stop->Visible = false;
			// 
			// vcc11
			// 
			this->vcc11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc11->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc11->Location = System::Drawing::Point(475, 64);
			this->vcc11->Name = L"vcc11";
			this->vcc11->ReadOnly = true;
			this->vcc11->Size = System::Drawing::Size(95, 20);
			this->vcc11->TabIndex = 27;
			this->vcc11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc11->Visible = false;
			this->vcc11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vcc11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// form3Start
			// 
			this->form3Start->AutoSize = true;
			this->form3Start->BackColor = System::Drawing::Color::Transparent;
			this->form3Start->Location = System::Drawing::Point(31, 206);
			this->form3Start->Name = L"form3Start";
			this->form3Start->Size = System::Drawing::Size(87, 13);
			this->form3Start->TabIndex = 55;
			this->form3Start->Text = L"File Logger Start:";
			this->form3Start->Visible = false;
			// 
			// vp11
			// 
			this->vp11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp11->BackColor = System::Drawing::Color::Gainsboro;
			this->vp11->Location = System::Drawing::Point(475, 90);
			this->vp11->Name = L"vp11";
			this->vp11->ReadOnly = true;
			this->vp11->Size = System::Drawing::Size(95, 20);
			this->vp11->TabIndex = 27;
			this->vp11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp11->Visible = false;
			this->vp11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vp11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// groupBox17
			// 
			this->groupBox17->BackColor = System::Drawing::Color::Transparent;
			this->groupBox17->Controls->Add(this->tableLayoutPanel1);
			this->groupBox17->Location = System::Drawing::Point(132, 316);
			this->groupBox17->Name = L"groupBox17";
			this->groupBox17->Size = System::Drawing::Size(754, 287);
			this->groupBox17->TabIndex = 54;
			this->groupBox17->TabStop = false;
			this->groupBox17->Text = L"Distributor Contribution Test Measurements";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Outset;
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel1->Controls->Add(this->step1Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->step3Label, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->step4Label, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->step5Label, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->label40, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label41, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->step5Farm, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->label61, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->step3Farm, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->step4Farm, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->label65, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label66, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->step3Load, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->label91, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->step4Load, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->step5Load, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->label94, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label95, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label96, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label97, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label98, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->vcc1, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->vp1, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->vs1, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->vps1, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->vcc2, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->vp2, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->vs2, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->vps2, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->vps3, 3, 7);
			this->tableLayoutPanel1->Controls->Add(this->vs3, 3, 6);
			this->tableLayoutPanel1->Controls->Add(this->vp3, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->vcc3, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->vcc4, 4, 4);
			this->tableLayoutPanel1->Controls->Add(this->vp4, 4, 5);
			this->tableLayoutPanel1->Controls->Add(this->vs4, 4, 6);
			this->tableLayoutPanel1->Controls->Add(this->vps4, 4, 7);
			this->tableLayoutPanel1->Controls->Add(this->vps5, 5, 7);
			this->tableLayoutPanel1->Controls->Add(this->vs5, 5, 6);
			this->tableLayoutPanel1->Controls->Add(this->vp5, 5, 5);
			this->tableLayoutPanel1->Controls->Add(this->vcc5, 5, 4);
			this->tableLayoutPanel1->Controls->Add(this->time1, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->time3, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->time4, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->time5, 5, 3);
			this->tableLayoutPanel1->Controls->Add(this->step2Label, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->time2, 2, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 23);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(729, 258);
			this->tableLayoutPanel1->TabIndex = 50;
			// 
			// step1Label
			// 
			this->step1Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step1Label->AutoSize = true;
			this->step1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step1Label->Location = System::Drawing::Point(160, 10);
			this->step1Label->Name = L"step1Label";
			this->step1Label->Size = System::Drawing::Size(44, 13);
			this->step1Label->TabIndex = 0;
			this->step1Label->Text = L"Step 1";
			// 
			// step3Label
			// 
			this->step3Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step3Label->AutoSize = true;
			this->step3Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step3Label->Location = System::Drawing::Point(402, 10);
			this->step3Label->Name = L"step3Label";
			this->step3Label->Size = System::Drawing::Size(44, 13);
			this->step3Label->TabIndex = 0;
			this->step3Label->Text = L"Step 3";
			// 
			// step4Label
			// 
			this->step4Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step4Label->AutoSize = true;
			this->step4Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step4Label->Location = System::Drawing::Point(523, 10);
			this->step4Label->Name = L"step4Label";
			this->step4Label->Size = System::Drawing::Size(44, 13);
			this->step4Label->TabIndex = 0;
			this->step4Label->Text = L"Step 4";
			// 
			// step5Label
			// 
			this->step5Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step5Label->AutoSize = true;
			this->step5Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step5Label->Location = System::Drawing::Point(645, 10);
			this->step5Label->Name = L"step5Label";
			this->step5Label->Size = System::Drawing::Size(44, 13);
			this->step5Label->TabIndex = 0;
			this->step5Label->Text = L"Step 5";
			// 
			// label40
			// 
			this->label40->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(46, 42);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(30, 13);
			this->label40->TabIndex = 1;
			this->label40->Text = L"Farm";
			// 
			// label41
			// 
			this->label41->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(171, 42);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(23, 13);
			this->label41->TabIndex = 1;
			this->label41->Text = L"ON";
			// 
			// step5Farm
			// 
			this->step5Farm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step5Farm->AutoSize = true;
			this->step5Farm->Location = System::Drawing::Point(655, 42);
			this->step5Farm->Name = L"step5Farm";
			this->step5Farm->Size = System::Drawing::Size(23, 13);
			this->step5Farm->TabIndex = 1;
			this->step5Farm->Text = L"ON";
			// 
			// label61
			// 
			this->label61->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(290, 42);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(27, 13);
			this->label61->TabIndex = 1;
			this->label61->Text = L"OFF";
			// 
			// step3Farm
			// 
			this->step3Farm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step3Farm->AutoSize = true;
			this->step3Farm->Location = System::Drawing::Point(411, 42);
			this->step3Farm->Name = L"step3Farm";
			this->step3Farm->Size = System::Drawing::Size(27, 13);
			this->step3Farm->TabIndex = 1;
			this->step3Farm->Text = L"OFF";
			// 
			// step4Farm
			// 
			this->step4Farm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step4Farm->AutoSize = true;
			this->step4Farm->Location = System::Drawing::Point(532, 42);
			this->step4Farm->Name = L"step4Farm";
			this->step4Farm->Size = System::Drawing::Size(27, 13);
			this->step4Farm->TabIndex = 1;
			this->step4Farm->Text = L"OFF";
			// 
			// label65
			// 
			this->label65->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(35, 74);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(52, 13);
			this->label65->TabIndex = 1;
			this->label65->Text = L"Load Box";
			// 
			// label66
			// 
			this->label66->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(169, 74);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(27, 13);
			this->label66->TabIndex = 1;
			this->label66->Text = L"OFF";
			// 
			// step3Load
			// 
			this->step3Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step3Load->AutoSize = true;
			this->step3Load->Location = System::Drawing::Point(407, 74);
			this->step3Load->Name = L"step3Load";
			this->step3Load->Size = System::Drawing::Size(34, 13);
			this->step3Load->TabIndex = 1;
			this->step3Load->Text = L"HALF";
			// 
			// label91
			// 
			this->label91->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label91->AutoSize = true;
			this->label91->Location = System::Drawing::Point(290, 74);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(27, 13);
			this->label91->TabIndex = 1;
			this->label91->Text = L"OFF";
			// 
			// step4Load
			// 
			this->step4Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step4Load->AutoSize = true;
			this->step4Load->Location = System::Drawing::Point(529, 74);
			this->step4Load->Name = L"step4Load";
			this->step4Load->Size = System::Drawing::Size(33, 13);
			this->step4Load->TabIndex = 1;
			this->step4Load->Text = L"FULL";
			// 
			// step5Load
			// 
			this->step5Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step5Load->AutoSize = true;
			this->step5Load->Location = System::Drawing::Point(650, 74);
			this->step5Load->Name = L"step5Load";
			this->step5Load->Size = System::Drawing::Size(33, 13);
			this->step5Load->TabIndex = 1;
			this->step5Load->Text = L"FULL";
			// 
			// label94
			// 
			this->label94->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label94->AutoSize = true;
			this->label94->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label94->Location = System::Drawing::Point(10, 106);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(103, 13);
			this->label94->TabIndex = 1;
			this->label94->Text = L"Enter Start Time:";
			// 
			// label95
			// 
			this->label95->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label95->AutoSize = true;
			this->label95->Location = System::Drawing::Point(40, 138);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(42, 13);
			this->label95->TabIndex = 1;
			this->label95->Text = L"Vcc (V)";
			// 
			// label96
			// 
			this->label96->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label96->AutoSize = true;
			this->label96->Location = System::Drawing::Point(43, 170);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(36, 13);
			this->label96->TabIndex = 1;
			this->label96->Text = L"Vp (V)";
			// 
			// label97
			// 
			this->label97->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label97->AutoSize = true;
			this->label97->Location = System::Drawing::Point(44, 202);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(35, 13);
			this->label97->TabIndex = 1;
			this->label97->Text = L"Vs (V)";
			// 
			// label98
			// 
			this->label98->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label98->AutoSize = true;
			this->label98->Location = System::Drawing::Point(41, 234);
			this->label98->Name = L"label98";
			this->label98->Size = System::Drawing::Size(41, 13);
			this->label98->TabIndex = 1;
			this->label98->Text = L"Vps (V)";
			// 
			// vcc1
			// 
			this->vcc1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc1->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc1->Location = System::Drawing::Point(135, 135);
			this->vcc1->Name = L"vcc1";
			this->vcc1->ReadOnly = true;
			this->vcc1->Size = System::Drawing::Size(95, 20);
			this->vcc1->TabIndex = 11;
			this->vcc1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vcc1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vp1
			// 
			this->vp1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp1->BackColor = System::Drawing::Color::Gainsboro;
			this->vp1->Location = System::Drawing::Point(135, 167);
			this->vp1->Name = L"vp1";
			this->vp1->ReadOnly = true;
			this->vp1->Size = System::Drawing::Size(95, 20);
			this->vp1->TabIndex = 12;
			this->vp1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vp1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vs1
			// 
			this->vs1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs1->BackColor = System::Drawing::Color::Gainsboro;
			this->vs1->Location = System::Drawing::Point(135, 199);
			this->vs1->Name = L"vs1";
			this->vs1->ReadOnly = true;
			this->vs1->Size = System::Drawing::Size(95, 20);
			this->vs1->TabIndex = 13;
			this->vs1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vs1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vps1
			// 
			this->vps1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps1->BackColor = System::Drawing::Color::Gainsboro;
			this->vps1->Location = System::Drawing::Point(135, 231);
			this->vps1->Name = L"vps1";
			this->vps1->ReadOnly = true;
			this->vps1->Size = System::Drawing::Size(95, 20);
			this->vps1->TabIndex = 14;
			this->vps1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vps1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vcc2
			// 
			this->vcc2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc2->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc2->Location = System::Drawing::Point(256, 135);
			this->vcc2->Name = L"vcc2";
			this->vcc2->ReadOnly = true;
			this->vcc2->Size = System::Drawing::Size(95, 20);
			this->vcc2->TabIndex = 15;
			this->vcc2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vcc2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vp2
			// 
			this->vp2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp2->BackColor = System::Drawing::Color::Gainsboro;
			this->vp2->Location = System::Drawing::Point(256, 167);
			this->vp2->Name = L"vp2";
			this->vp2->ReadOnly = true;
			this->vp2->Size = System::Drawing::Size(95, 20);
			this->vp2->TabIndex = 16;
			this->vp2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vp2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vs2
			// 
			this->vs2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs2->BackColor = System::Drawing::Color::Gainsboro;
			this->vs2->Location = System::Drawing::Point(256, 199);
			this->vs2->Name = L"vs2";
			this->vs2->ReadOnly = true;
			this->vs2->Size = System::Drawing::Size(95, 20);
			this->vs2->TabIndex = 17;
			this->vs2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vs2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vps2
			// 
			this->vps2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps2->BackColor = System::Drawing::Color::Gainsboro;
			this->vps2->Location = System::Drawing::Point(256, 231);
			this->vps2->Name = L"vps2";
			this->vps2->ReadOnly = true;
			this->vps2->Size = System::Drawing::Size(95, 20);
			this->vps2->TabIndex = 18;
			this->vps2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vps2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vps3
			// 
			this->vps3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps3->BackColor = System::Drawing::Color::Gainsboro;
			this->vps3->Location = System::Drawing::Point(377, 231);
			this->vps3->Name = L"vps3";
			this->vps3->ReadOnly = true;
			this->vps3->Size = System::Drawing::Size(95, 20);
			this->vps3->TabIndex = 22;
			this->vps3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vps3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vs3
			// 
			this->vs3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs3->BackColor = System::Drawing::Color::Gainsboro;
			this->vs3->Location = System::Drawing::Point(377, 199);
			this->vs3->Name = L"vs3";
			this->vs3->ReadOnly = true;
			this->vs3->Size = System::Drawing::Size(95, 20);
			this->vs3->TabIndex = 21;
			this->vs3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vs3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vp3
			// 
			this->vp3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp3->BackColor = System::Drawing::Color::Gainsboro;
			this->vp3->Location = System::Drawing::Point(377, 167);
			this->vp3->Name = L"vp3";
			this->vp3->ReadOnly = true;
			this->vp3->Size = System::Drawing::Size(95, 20);
			this->vp3->TabIndex = 20;
			this->vp3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vp3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vcc3
			// 
			this->vcc3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc3->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc3->Location = System::Drawing::Point(377, 135);
			this->vcc3->Name = L"vcc3";
			this->vcc3->ReadOnly = true;
			this->vcc3->Size = System::Drawing::Size(95, 20);
			this->vcc3->TabIndex = 19;
			this->vcc3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vcc3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vcc4
			// 
			this->vcc4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc4->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc4->Location = System::Drawing::Point(498, 135);
			this->vcc4->Name = L"vcc4";
			this->vcc4->ReadOnly = true;
			this->vcc4->Size = System::Drawing::Size(95, 20);
			this->vcc4->TabIndex = 23;
			this->vcc4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vcc4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vp4
			// 
			this->vp4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp4->BackColor = System::Drawing::Color::Gainsboro;
			this->vp4->Location = System::Drawing::Point(498, 167);
			this->vp4->Name = L"vp4";
			this->vp4->ReadOnly = true;
			this->vp4->Size = System::Drawing::Size(95, 20);
			this->vp4->TabIndex = 24;
			this->vp4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vp4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vs4
			// 
			this->vs4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs4->BackColor = System::Drawing::Color::Gainsboro;
			this->vs4->Location = System::Drawing::Point(498, 199);
			this->vs4->Name = L"vs4";
			this->vs4->ReadOnly = true;
			this->vs4->Size = System::Drawing::Size(95, 20);
			this->vs4->TabIndex = 25;
			this->vs4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vs4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vps4
			// 
			this->vps4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps4->BackColor = System::Drawing::Color::Gainsboro;
			this->vps4->Location = System::Drawing::Point(498, 231);
			this->vps4->Name = L"vps4";
			this->vps4->ReadOnly = true;
			this->vps4->Size = System::Drawing::Size(95, 20);
			this->vps4->TabIndex = 26;
			this->vps4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vps4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vps5
			// 
			this->vps5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps5->BackColor = System::Drawing::Color::Gainsboro;
			this->vps5->Location = System::Drawing::Point(619, 231);
			this->vps5->Name = L"vps5";
			this->vps5->ReadOnly = true;
			this->vps5->Size = System::Drawing::Size(95, 20);
			this->vps5->TabIndex = 30;
			this->vps5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vps5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vs5
			// 
			this->vs5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs5->BackColor = System::Drawing::Color::Gainsboro;
			this->vs5->Location = System::Drawing::Point(619, 199);
			this->vs5->Name = L"vs5";
			this->vs5->ReadOnly = true;
			this->vs5->Size = System::Drawing::Size(95, 20);
			this->vs5->TabIndex = 29;
			this->vs5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vs5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vp5
			// 
			this->vp5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp5->BackColor = System::Drawing::Color::Gainsboro;
			this->vp5->Location = System::Drawing::Point(619, 167);
			this->vp5->Name = L"vp5";
			this->vp5->ReadOnly = true;
			this->vp5->Size = System::Drawing::Size(95, 20);
			this->vp5->TabIndex = 28;
			this->vp5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vp5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vcc5
			// 
			this->vcc5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc5->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc5->Location = System::Drawing::Point(619, 135);
			this->vcc5->Name = L"vcc5";
			this->vcc5->ReadOnly = true;
			this->vcc5->Size = System::Drawing::Size(95, 20);
			this->vcc5->TabIndex = 27;
			this->vcc5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vcc5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// time1
			// 
			this->time1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time1->BackColor = System::Drawing::Color::Gainsboro;
			this->time1->Location = System::Drawing::Point(135, 103);
			this->time1->Mask = L"00:00";
			this->time1->Name = L"time1";
			this->time1->ReadOnly = true;
			this->time1->Size = System::Drawing::Size(95, 20);
			this->time1->TabIndex = 6;
			this->time1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time1->ValidatingType = System::DateTime::typeid;
			// 
			// time3
			// 
			this->time3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time3->BackColor = System::Drawing::Color::Gainsboro;
			this->time3->Location = System::Drawing::Point(377, 103);
			this->time3->Mask = L"00:00";
			this->time3->Name = L"time3";
			this->time3->ReadOnly = true;
			this->time3->Size = System::Drawing::Size(95, 20);
			this->time3->TabIndex = 8;
			this->time3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time3->ValidatingType = System::DateTime::typeid;
			// 
			// time4
			// 
			this->time4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time4->BackColor = System::Drawing::Color::Gainsboro;
			this->time4->Location = System::Drawing::Point(498, 103);
			this->time4->Mask = L"00:00";
			this->time4->Name = L"time4";
			this->time4->ReadOnly = true;
			this->time4->Size = System::Drawing::Size(95, 20);
			this->time4->TabIndex = 9;
			this->time4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time4->ValidatingType = System::DateTime::typeid;
			// 
			// time5
			// 
			this->time5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time5->BackColor = System::Drawing::Color::Gainsboro;
			this->time5->Location = System::Drawing::Point(619, 103);
			this->time5->Mask = L"00:00";
			this->time5->Name = L"time5";
			this->time5->ReadOnly = true;
			this->time5->Size = System::Drawing::Size(95, 20);
			this->time5->TabIndex = 10;
			this->time5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time5->ValidatingType = System::DateTime::typeid;
			// 
			// step2Label
			// 
			this->step2Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step2Label->AutoSize = true;
			this->step2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step2Label->Location = System::Drawing::Point(281, 10);
			this->step2Label->Name = L"step2Label";
			this->step2Label->Size = System::Drawing::Size(44, 13);
			this->step2Label->TabIndex = 0;
			this->step2Label->Text = L"Step 2";
			// 
			// time2
			// 
			this->time2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time2->BackColor = System::Drawing::Color::Gainsboro;
			this->time2->Location = System::Drawing::Point(256, 103);
			this->time2->Mask = L"00:00";
			this->time2->Name = L"time2";
			this->time2->ReadOnly = true;
			this->time2->Size = System::Drawing::Size(95, 20);
			this->time2->TabIndex = 7;
			this->time2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time2->ValidatingType = System::DateTime::typeid;
			// 
			// vs11
			// 
			this->vs11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs11->BackColor = System::Drawing::Color::Gainsboro;
			this->vs11->Location = System::Drawing::Point(474, 118);
			this->vs11->Name = L"vs11";
			this->vs11->ReadOnly = true;
			this->vs11->Size = System::Drawing::Size(95, 20);
			this->vs11->TabIndex = 27;
			this->vs11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs11->Visible = false;
			this->vs11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vs11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// groupBox16
			// 
			this->groupBox16->BackColor = System::Drawing::Color::Transparent;
			this->groupBox16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->groupBox16->Controls->Add(this->F3Graph);
			this->groupBox16->Controls->Add(this->form3File);
			this->groupBox16->Controls->Add(this->form3Open);
			this->groupBox16->Controls->Add(this->userRadio);
			this->groupBox16->Controls->Add(this->fileRadio);
			this->groupBox16->Controls->Add(this->label107);
			this->groupBox16->Location = System::Drawing::Point(34, 91);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(325, 110);
			this->groupBox16->TabIndex = 53;
			this->groupBox16->TabStop = false;
			this->groupBox16->Text = L"Form Input";
			// 
			// F3Graph
			// 
			this->F3Graph->Enabled = false;
			this->F3Graph->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"F3Graph.Image")));
			this->F3Graph->Location = System::Drawing::Point(81, 61);
			this->F3Graph->Name = L"F3Graph";
			this->F3Graph->Size = System::Drawing::Size(52, 37);
			this->F3Graph->TabIndex = 56;
			this->F3Graph->UseVisualStyleBackColor = true;
			this->F3Graph->Click += gcnew System::EventHandler(this, &Form1::F3Graph_Click);
			// 
			// form3File
			// 
			this->form3File->AutoSize = true;
			this->form3File->ForeColor = System::Drawing::Color::Red;
			this->form3File->Location = System::Drawing::Point(6, 44);
			this->form3File->Name = L"form3File";
			this->form3File->Size = System::Drawing::Size(100, 13);
			this->form3File->TabIndex = 55;
			this->form3File->Text = L"Please open a file...";
			// 
			// form3Open
			// 
			this->form3Open->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"form3Open.Image")));
			this->form3Open->Location = System::Drawing::Point(23, 61);
			this->form3Open->Name = L"form3Open";
			this->form3Open->Size = System::Drawing::Size(52, 37);
			this->form3Open->TabIndex = 1;
			this->form3Open->UseVisualStyleBackColor = true;
			this->form3Open->Click += gcnew System::EventHandler(this, &Form1::form3Open_Click);
			// 
			// userRadio
			// 
			this->userRadio->AutoSize = true;
			this->userRadio->Location = System::Drawing::Point(182, 81);
			this->userRadio->Name = L"userRadio";
			this->userRadio->Size = System::Drawing::Size(73, 17);
			this->userRadio->TabIndex = 1;
			this->userRadio->Text = L"User input";
			this->userRadio->UseVisualStyleBackColor = true;
			this->userRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::userRadio_CheckedChanged);
			// 
			// fileRadio
			// 
			this->fileRadio->AutoSize = true;
			this->fileRadio->Checked = true;
			this->fileRadio->Location = System::Drawing::Point(182, 59);
			this->fileRadio->Name = L"fileRadio";
			this->fileRadio->Size = System::Drawing::Size(68, 17);
			this->fileRadio->TabIndex = 1;
			this->fileRadio->TabStop = true;
			this->fileRadio->Text = L"File Input";
			this->fileRadio->UseVisualStyleBackColor = true;
			// 
			// label107
			// 
			this->label107->AutoSize = true;
			this->label107->Location = System::Drawing::Point(6, 16);
			this->label107->Name = L"label107";
			this->label107->Size = System::Drawing::Size(188, 13);
			this->label107->TabIndex = 0;
			this->label107->Text = L"Form 3 Test Data will be populated by:";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->BackColor = System::Drawing::Color::Transparent;
			this->label52->Location = System::Drawing::Point(129, 287);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(242, 26);
			this->label52->TabIndex = 40;
			this->label52->Text = L"NOTE: For Voltages, record the highest value\r\nmeasured over the minimum 2 minute " 
				L"test duration";
			// 
			// time11
			// 
			this->time11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time11->BackColor = System::Drawing::Color::Gainsboro;
			this->time11->Location = System::Drawing::Point(475, 32);
			this->time11->Mask = L"00:00";
			this->time11->Name = L"time11";
			this->time11->ReadOnly = true;
			this->time11->Size = System::Drawing::Size(95, 20);
			this->time11->TabIndex = 26;
			this->time11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time11->ValidatingType = System::DateTime::typeid;
			this->time11->Visible = false;
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::Transparent;
			this->groupBox4->Controls->Add(this->richTextBox2);
			this->groupBox4->Controls->Add(this->richTextBox3);
			this->groupBox4->Controls->Add(this->label25);
			this->groupBox4->Controls->Add(this->richTextBox4);
			this->groupBox4->Controls->Add(this->richTextBox5);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->label26);
			this->groupBox4->Controls->Add(this->label28);
			this->groupBox4->Controls->Add(this->label29);
			this->groupBox4->Controls->Add(this->vpri);
			this->groupBox4->Controls->Add(this->label30);
			this->groupBox4->Controls->Add(this->ilbh);
			this->groupBox4->Controls->Add(this->vlbh);
			this->groupBox4->Controls->Add(this->ilbf);
			this->groupBox4->Controls->Add(this->vlbf);
			this->groupBox4->Controls->Add(this->label27);
			this->groupBox4->Controls->Add(this->label31);
			this->groupBox4->Controls->Add(this->label32);
			this->groupBox4->Controls->Add(this->ip);
			this->groupBox4->Location = System::Drawing::Point(378, 91);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(590, 183);
			this->groupBox4->TabIndex = 49;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Initial measurements and calculations with farm service de-energized:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Location = System::Drawing::Point(19, 35);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(235, 22);
			this->richTextBox2->TabIndex = 33;
			this->richTextBox2->TabStop = false;
			this->richTextBox2->Text = L"Primary Nominal Voltage Phase to Neutral (Vpri):";
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::Color::White;
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox3->Location = System::Drawing::Point(19, 63);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(175, 22);
			this->richTextBox3->TabIndex = 33;
			this->richTextBox3->TabStop = false;
			this->richTextBox3->Text = L"Load Box Current (ILB):     Half Load";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(363, 35);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(14, 13);
			this->label25->TabIndex = 34;
			this->label25->Text = L"V";
			// 
			// richTextBox4
			// 
			this->richTextBox4->BackColor = System::Drawing::Color::White;
			this->richTextBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox4->Location = System::Drawing::Point(19, 89);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->ReadOnly = true;
			this->richTextBox4->Size = System::Drawing::Size(184, 22);
			this->richTextBox4->TabIndex = 33;
			this->richTextBox4->TabStop = false;
			this->richTextBox4->Text = L"Load Box Voltage (VLB):   Half Load";
			// 
			// richTextBox5
			// 
			this->richTextBox5->BackColor = System::Drawing::Color::White;
			this->richTextBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox5->Location = System::Drawing::Point(19, 117);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->ReadOnly = true;
			this->richTextBox5->Size = System::Drawing::Size(184, 22);
			this->richTextBox5->TabIndex = 33;
			this->richTextBox5->TabStop = false;
			this->richTextBox5->Text = L"Transformer Primary Current (Ip):";
			this->toolTip1->SetToolTip(this->richTextBox5, L"Ip = (I lb x V lb) / V pri");
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(361, 115);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(14, 13);
			this->label11->TabIndex = 34;
			this->label11->Text = L"A";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(361, 61);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(14, 13);
			this->label26->TabIndex = 34;
			this->label26->Text = L"A";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(561, 61);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(14, 13);
			this->label28->TabIndex = 34;
			this->label28->Text = L"A";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(361, 87);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(14, 13);
			this->label29->TabIndex = 34;
			this->label29->Text = L"V";
			// 
			// vpri
			// 
			this->vpri->Location = System::Drawing::Point(255, 32);
			this->vpri->Name = L"vpri";
			this->vpri->Size = System::Drawing::Size(100, 20);
			this->vpri->TabIndex = 0;
			this->vpri->TextChanged += gcnew System::EventHandler(this, &Form1::vpri_TextChanged);
			this->vpri->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vpri->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(561, 87);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(14, 13);
			this->label30->TabIndex = 34;
			this->label30->Text = L"V";
			// 
			// ilbh
			// 
			this->ilbh->Location = System::Drawing::Point(255, 58);
			this->ilbh->Name = L"ilbh";
			this->ilbh->Size = System::Drawing::Size(100, 20);
			this->ilbh->TabIndex = 1;
			this->ilbh->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->ilbh->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vlbh
			// 
			this->vlbh->Location = System::Drawing::Point(255, 84);
			this->vlbh->Name = L"vlbh";
			this->vlbh->Size = System::Drawing::Size(100, 20);
			this->vlbh->TabIndex = 2;
			this->vlbh->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vlbh->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// ilbf
			// 
			this->ilbf->Location = System::Drawing::Point(455, 58);
			this->ilbf->Name = L"ilbf";
			this->ilbf->Size = System::Drawing::Size(100, 20);
			this->ilbf->TabIndex = 3;
			this->ilbf->TextChanged += gcnew System::EventHandler(this, &Form1::vpri_TextChanged);
			this->ilbf->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->ilbf->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// vlbf
			// 
			this->vlbf->Location = System::Drawing::Point(455, 84);
			this->vlbf->Name = L"vlbf";
			this->vlbf->Size = System::Drawing::Size(100, 20);
			this->vlbf->TabIndex = 4;
			this->vlbf->TextChanged += gcnew System::EventHandler(this, &Form1::vpri_TextChanged);
			this->vlbf->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vlbf->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(399, 61);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(50, 13);
			this->label27->TabIndex = 36;
			this->label27->Text = L"Full Load";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(399, 87);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(50, 13);
			this->label31->TabIndex = 36;
			this->label31->Text = L"Full Load";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(18, 151);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(319, 13);
			this->label32->TabIndex = 38;
			this->label32->Text = L"Note: I p is measured on the source side of the ground connection";
			// 
			// ip
			// 
			this->ip->BackColor = System::Drawing::Color::Gainsboro;
			this->ip->Location = System::Drawing::Point(255, 112);
			this->ip->Name = L"ip";
			this->ip->ReadOnly = true;
			this->ip->Size = System::Drawing::Size(100, 20);
			this->ip->TabIndex = 5;
			this->toolTip1->SetToolTip(this->ip, L"Ip = (I lb x V lb) / V pri");
			this->ip->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->ip->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// tabPage9
			// 
			this->tabPage9->BackColor = System::Drawing::Color::White;
			this->tabPage9->Controls->Add(this->groupBox10);
			this->tabPage9->Controls->Add(this->groupBox9);
			this->tabPage9->Controls->Add(this->groupBox8);
			this->tabPage9->Controls->Add(this->groupBox7);
			this->tabPage9->Controls->Add(this->groupBox6);
			this->tabPage9->Controls->Add(this->label20);
			this->tabPage9->Location = System::Drawing::Point(4, 22);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Padding = System::Windows::Forms::Padding(3);
			this->tabPage9->Size = System::Drawing::Size(1019, 611);
			this->tabPage9->TabIndex = 3;
			this->tabPage9->Text = L"Form 4";
			this->tabPage9->Enter += gcnew System::EventHandler(this, &Form1::tabPage9_Enter);
			// 
			// groupBox10
			// 
			this->groupBox10->BackColor = System::Drawing::Color::Transparent;
			this->groupBox10->Controls->Add(this->vccd1Phase);
			this->groupBox10->Controls->Add(this->vccd3Phase);
			this->groupBox10->Controls->Add(this->SingleLabel);
			this->groupBox10->Location = System::Drawing::Point(238, 419);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(543, 125);
			this->groupBox10->TabIndex = 18;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Distributor Contribution to ACC/ACV (VccD)";
			// 
			// vccd1Phase
			// 
			this->vccd1Phase->AutoSize = true;
			this->vccd1Phase->Location = System::Drawing::Point(286, 56);
			this->vccd1Phase->Name = L"vccd1Phase";
			this->vccd1Phase->Size = System::Drawing::Size(14, 13);
			this->vccd1Phase->TabIndex = 7;
			this->vccd1Phase->Text = L"V";
			// 
			// vccd3Phase
			// 
			this->vccd3Phase->AutoSize = true;
			this->vccd3Phase->Location = System::Drawing::Point(286, 56);
			this->vccd3Phase->Name = L"vccd3Phase";
			this->vccd3Phase->Size = System::Drawing::Size(14, 13);
			this->vccd3Phase->TabIndex = 7;
			this->vccd3Phase->Text = L"V";
			this->vccd3Phase->Visible = false;
			// 
			// SingleLabel
			// 
			this->SingleLabel->AutoSize = true;
			this->SingleLabel->Location = System::Drawing::Point(95, 56);
			this->SingleLabel->Name = L"SingleLabel";
			this->SingleLabel->Size = System::Drawing::Size(37, 13);
			this->SingleLabel->TabIndex = 13;
			this->SingleLabel->Text = L"VccD:";
			// 
			// groupBox9
			// 
			this->groupBox9->BackColor = System::Drawing::Color::Transparent;
			this->groupBox9->Controls->Add(this->richTextBox17);
			this->groupBox9->Controls->Add(this->vccfull);
			this->groupBox9->Controls->Add(this->richTextBox18);
			this->groupBox9->Controls->Add(this->vpfull);
			this->groupBox9->Location = System::Drawing::Point(238, 326);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(543, 62);
			this->groupBox9->TabIndex = 17;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Vcc and corresponding Vp in Distributor Contribution Test with Farm OFF and Load " 
				L"Box MAX:";
			// 
			// richTextBox17
			// 
			this->richTextBox17->BackColor = System::Drawing::Color::White;
			this->richTextBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox17->Location = System::Drawing::Point(6, 28);
			this->richTextBox17->Name = L"richTextBox17";
			this->richTextBox17->ReadOnly = true;
			this->richTextBox17->Size = System::Drawing::Size(106, 19);
			this->richTextBox17->TabIndex = 6;
			this->richTextBox17->TabStop = false;
			this->richTextBox17->Text = L"Vcc full :";
			// 
			// vccfull
			// 
			this->vccfull->AutoSize = true;
			this->vccfull->Location = System::Drawing::Point(118, 28);
			this->vccfull->Name = L"vccfull";
			this->vccfull->Size = System::Drawing::Size(14, 13);
			this->vccfull->TabIndex = 7;
			this->vccfull->Text = L"V";
			// 
			// richTextBox18
			// 
			this->richTextBox18->BackColor = System::Drawing::Color::White;
			this->richTextBox18->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox18->Location = System::Drawing::Point(174, 28);
			this->richTextBox18->Name = L"richTextBox18";
			this->richTextBox18->ReadOnly = true;
			this->richTextBox18->Size = System::Drawing::Size(106, 19);
			this->richTextBox18->TabIndex = 6;
			this->richTextBox18->TabStop = false;
			this->richTextBox18->Text = L"Vp full :";
			// 
			// vpfull
			// 
			this->vpfull->AutoSize = true;
			this->vpfull->Location = System::Drawing::Point(286, 28);
			this->vpfull->Name = L"vpfull";
			this->vpfull->Size = System::Drawing::Size(14, 13);
			this->vpfull->TabIndex = 7;
			this->vpfull->Text = L"V";
			// 
			// groupBox8
			// 
			this->groupBox8->BackColor = System::Drawing::Color::Transparent;
			this->groupBox8->Controls->Add(this->richTextBox14);
			this->groupBox8->Controls->Add(this->vcchalf);
			this->groupBox8->Controls->Add(this->richTextBox15);
			this->groupBox8->Controls->Add(this->vphalf);
			this->groupBox8->Location = System::Drawing::Point(238, 249);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(543, 62);
			this->groupBox8->TabIndex = 17;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Vcc and corresponding Vp in Distributor Contribution Test with Farm OFF and Load " 
				L"Box HALF:";
			// 
			// richTextBox14
			// 
			this->richTextBox14->BackColor = System::Drawing::Color::White;
			this->richTextBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox14->Location = System::Drawing::Point(6, 28);
			this->richTextBox14->Name = L"richTextBox14";
			this->richTextBox14->ReadOnly = true;
			this->richTextBox14->Size = System::Drawing::Size(106, 19);
			this->richTextBox14->TabIndex = 6;
			this->richTextBox14->TabStop = false;
			this->richTextBox14->Text = L"Vcc half :";
			// 
			// vcchalf
			// 
			this->vcchalf->AutoSize = true;
			this->vcchalf->Location = System::Drawing::Point(118, 28);
			this->vcchalf->Name = L"vcchalf";
			this->vcchalf->Size = System::Drawing::Size(14, 13);
			this->vcchalf->TabIndex = 7;
			this->vcchalf->Text = L"V";
			// 
			// richTextBox15
			// 
			this->richTextBox15->BackColor = System::Drawing::Color::White;
			this->richTextBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox15->Location = System::Drawing::Point(174, 28);
			this->richTextBox15->Name = L"richTextBox15";
			this->richTextBox15->ReadOnly = true;
			this->richTextBox15->Size = System::Drawing::Size(106, 19);
			this->richTextBox15->TabIndex = 6;
			this->richTextBox15->TabStop = false;
			this->richTextBox15->Text = L"Vp half :";
			// 
			// vphalf
			// 
			this->vphalf->AutoSize = true;
			this->vphalf->Location = System::Drawing::Point(286, 28);
			this->vphalf->Name = L"vphalf";
			this->vphalf->Size = System::Drawing::Size(14, 13);
			this->vphalf->TabIndex = 7;
			this->vphalf->Text = L"V";
			// 
			// groupBox7
			// 
			this->groupBox7->BackColor = System::Drawing::Color::Transparent;
			this->groupBox7->Controls->Add(this->richTextBox11);
			this->groupBox7->Controls->Add(this->vccoff);
			this->groupBox7->Controls->Add(this->richTextBox12);
			this->groupBox7->Controls->Add(this->vpoff);
			this->groupBox7->Location = System::Drawing::Point(238, 172);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(543, 62);
			this->groupBox7->TabIndex = 17;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Vcc and corresponding Vp in Distributor Contribution Test with Farm OFF and Load " 
				L"Box OFF:";
			// 
			// richTextBox11
			// 
			this->richTextBox11->BackColor = System::Drawing::Color::White;
			this->richTextBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox11->Location = System::Drawing::Point(6, 28);
			this->richTextBox11->Name = L"richTextBox11";
			this->richTextBox11->ReadOnly = true;
			this->richTextBox11->Size = System::Drawing::Size(106, 19);
			this->richTextBox11->TabIndex = 6;
			this->richTextBox11->TabStop = false;
			this->richTextBox11->Text = L"Vcc off :";
			// 
			// vccoff
			// 
			this->vccoff->AutoSize = true;
			this->vccoff->Location = System::Drawing::Point(118, 28);
			this->vccoff->Name = L"vccoff";
			this->vccoff->Size = System::Drawing::Size(14, 13);
			this->vccoff->TabIndex = 7;
			this->vccoff->Text = L"V";
			// 
			// richTextBox12
			// 
			this->richTextBox12->BackColor = System::Drawing::Color::White;
			this->richTextBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox12->Location = System::Drawing::Point(174, 28);
			this->richTextBox12->Name = L"richTextBox12";
			this->richTextBox12->ReadOnly = true;
			this->richTextBox12->Size = System::Drawing::Size(106, 19);
			this->richTextBox12->TabIndex = 6;
			this->richTextBox12->TabStop = false;
			this->richTextBox12->Text = L"Vp off :";
			// 
			// vpoff
			// 
			this->vpoff->AutoSize = true;
			this->vpoff->Location = System::Drawing::Point(286, 28);
			this->vpoff->Name = L"vpoff";
			this->vpoff->Size = System::Drawing::Size(14, 13);
			this->vpoff->TabIndex = 7;
			this->vpoff->Text = L"V";
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::Color::Transparent;
			this->groupBox6->Controls->Add(this->richTextBox8);
			this->groupBox6->Controls->Add(this->vccfsv);
			this->groupBox6->Controls->Add(this->richTextBox9);
			this->groupBox6->Controls->Add(this->vpfsv);
			this->groupBox6->Location = System::Drawing::Point(238, 95);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(543, 62);
			this->groupBox6->TabIndex = 16;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Highest Vcc and corresponding Vp from Farm Stray Voltage Test:";
			// 
			// richTextBox8
			// 
			this->richTextBox8->BackColor = System::Drawing::Color::White;
			this->richTextBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox8->Location = System::Drawing::Point(6, 28);
			this->richTextBox8->Name = L"richTextBox8";
			this->richTextBox8->ReadOnly = true;
			this->richTextBox8->Size = System::Drawing::Size(106, 19);
			this->richTextBox8->TabIndex = 6;
			this->richTextBox8->TabStop = false;
			this->richTextBox8->Text = L"Vcc fsv :";
			// 
			// vccfsv
			// 
			this->vccfsv->AutoSize = true;
			this->vccfsv->Location = System::Drawing::Point(118, 28);
			this->vccfsv->Name = L"vccfsv";
			this->vccfsv->Size = System::Drawing::Size(14, 13);
			this->vccfsv->TabIndex = 7;
			this->vccfsv->Text = L"V";
			// 
			// richTextBox9
			// 
			this->richTextBox9->BackColor = System::Drawing::Color::White;
			this->richTextBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox9->Location = System::Drawing::Point(174, 28);
			this->richTextBox9->Name = L"richTextBox9";
			this->richTextBox9->ReadOnly = true;
			this->richTextBox9->Size = System::Drawing::Size(106, 19);
			this->richTextBox9->TabIndex = 6;
			this->richTextBox9->TabStop = false;
			this->richTextBox9->Text = L"Vp fsv :";
			// 
			// vpfsv
			// 
			this->vpfsv->AutoSize = true;
			this->vpfsv->Location = System::Drawing::Point(286, 28);
			this->vpfsv->Name = L"vpfsv";
			this->vpfsv->Size = System::Drawing::Size(14, 13);
			this->vpfsv->TabIndex = 7;
			this->vpfsv->Text = L"V";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(364, 21);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(290, 60);
			this->label20->TabIndex = 4;
			this->label20->Text = L"Form 4\r\n\r\nDistributor Contribution Calculation";
			this->label20->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tabPage10
			// 
			this->tabPage10->BackColor = System::Drawing::Color::White;
			this->tabPage10->Controls->Add(this->tabControl4);
			this->tabPage10->Location = System::Drawing::Point(4, 22);
			this->tabPage10->Name = L"tabPage10";
			this->tabPage10->Padding = System::Windows::Forms::Padding(3);
			this->tabPage10->Size = System::Drawing::Size(1019, 611);
			this->tabPage10->TabIndex = 4;
			this->tabPage10->Text = L"Form 5";
			// 
			// tabControl4
			// 
			this->tabControl4->Controls->Add(this->tabPage11);
			this->tabControl4->Controls->Add(this->tabPage12);
			this->tabControl4->Location = System::Drawing::Point(6, 6);
			this->tabControl4->Name = L"tabControl4";
			this->tabControl4->SelectedIndex = 0;
			this->tabControl4->Size = System::Drawing::Size(1013, 602);
			this->tabControl4->TabIndex = 0;
			// 
			// tabPage11
			// 
			this->tabPage11->BackColor = System::Drawing::Color::White;
			this->tabPage11->Controls->Add(this->phase3ses5);
			this->tabPage11->Controls->Add(this->phases5);
			this->tabPage11->Controls->Add(this->phaseBox5);
			this->tabPage11->Controls->Add(this->form5StopTime);
			this->tabPage11->Controls->Add(this->form5StartTime);
			this->tabPage11->Controls->Add(this->form5Stop);
			this->tabPage11->Controls->Add(this->form5Start);
			this->tabPage11->Controls->Add(this->step12Load);
			this->tabPage11->Controls->Add(this->step12Farm);
			this->tabPage11->Controls->Add(this->step12Label);
			this->tabPage11->Controls->Add(this->groupBox3);
			this->tabPage11->Controls->Add(this->groupBox2);
			this->tabPage11->Controls->Add(this->clearButton5);
			this->tabPage11->Controls->Add(this->enterData5);
			this->tabPage11->Controls->Add(this->groupBox5);
			this->tabPage11->Controls->Add(this->label68);
			this->tabPage11->Controls->Add(this->label101);
			this->tabPage11->Controls->Add(this->time12);
			this->tabPage11->Controls->Add(this->vcc12);
			this->tabPage11->Controls->Add(this->vp12);
			this->tabPage11->Controls->Add(this->vs12);
			this->tabPage11->Controls->Add(this->vps12);
			this->tabPage11->Location = System::Drawing::Point(4, 22);
			this->tabPage11->Name = L"tabPage11";
			this->tabPage11->Padding = System::Windows::Forms::Padding(3);
			this->tabPage11->Size = System::Drawing::Size(1005, 576);
			this->tabPage11->TabIndex = 0;
			this->tabPage11->Text = L"Page 1";
			// 
			// phase3ses5
			// 
			this->phase3ses5->AutoSize = true;
			this->phase3ses5->BackColor = System::Drawing::Color::Transparent;
			this->phase3ses5->Location = System::Drawing::Point(709, 272);
			this->phase3ses5->Name = L"phase3ses5";
			this->phase3ses5->Size = System::Drawing::Size(94, 13);
			this->phase3ses5->TabIndex = 75;
			this->phase3ses5->Text = L"5 Steps on Phase:";
			this->phase3ses5->Visible = false;
			// 
			// phases5
			// 
			this->phases5->AutoSize = true;
			this->phases5->BackColor = System::Drawing::Color::Transparent;
			this->phases5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->phases5->Location = System::Drawing::Point(477, 272);
			this->phases5->Name = L"phases5";
			this->phases5->Size = System::Drawing::Size(145, 13);
			this->phases5->TabIndex = 76;
			this->phases5->Text = L"Single Phase Secondary";
			// 
			// phaseBox5
			// 
			this->phaseBox5->FormattingEnabled = true;
			this->phaseBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"A", L"B", L"C"});
			this->phaseBox5->Location = System::Drawing::Point(809, 269);
			this->phaseBox5->Name = L"phaseBox5";
			this->phaseBox5->Size = System::Drawing::Size(67, 21);
			this->phaseBox5->TabIndex = 74;
			this->phaseBox5->Visible = false;
			// 
			// form5StopTime
			// 
			this->form5StopTime->AutoSize = true;
			this->form5StopTime->Location = System::Drawing::Point(112, 191);
			this->form5StopTime->Name = L"form5StopTime";
			this->form5StopTime->Size = System::Drawing::Size(35, 13);
			this->form5StopTime->TabIndex = 72;
			this->form5StopTime->Text = L"label9";
			this->form5StopTime->Visible = false;
			// 
			// form5StartTime
			// 
			this->form5StartTime->AutoSize = true;
			this->form5StartTime->Location = System::Drawing::Point(112, 178);
			this->form5StartTime->Name = L"form5StartTime";
			this->form5StartTime->Size = System::Drawing::Size(35, 13);
			this->form5StartTime->TabIndex = 73;
			this->form5StartTime->Text = L"label9";
			this->form5StartTime->Visible = false;
			// 
			// form5Stop
			// 
			this->form5Stop->AutoSize = true;
			this->form5Stop->Location = System::Drawing::Point(21, 191);
			this->form5Stop->Name = L"form5Stop";
			this->form5Stop->Size = System::Drawing::Size(89, 13);
			this->form5Stop->TabIndex = 70;
			this->form5Stop->Text = L"File Record Stop:";
			this->form5Stop->Visible = false;
			// 
			// form5Start
			// 
			this->form5Start->AutoSize = true;
			this->form5Start->Location = System::Drawing::Point(21, 178);
			this->form5Start->Name = L"form5Start";
			this->form5Start->Size = System::Drawing::Size(87, 13);
			this->form5Start->TabIndex = 71;
			this->form5Start->Text = L"File Logger Start:";
			this->form5Start->Visible = false;
			// 
			// step12Load
			// 
			this->step12Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step12Load->AutoSize = true;
			this->step12Load->Location = System::Drawing::Point(6, 341);
			this->step12Load->Name = L"step12Load";
			this->step12Load->Size = System::Drawing::Size(27, 13);
			this->step12Load->TabIndex = 69;
			this->step12Load->Text = L"OFF";
			this->step12Load->Visible = false;
			// 
			// step12Farm
			// 
			this->step12Farm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step12Farm->AutoSize = true;
			this->step12Farm->Location = System::Drawing::Point(7, 316);
			this->step12Farm->Name = L"step12Farm";
			this->step12Farm->Size = System::Drawing::Size(27, 13);
			this->step12Farm->TabIndex = 69;
			this->step12Farm->Text = L"OFF";
			this->step12Farm->Visible = false;
			// 
			// step12Label
			// 
			this->step12Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step12Label->AutoSize = true;
			this->step12Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step12Label->Location = System::Drawing::Point(7, 294);
			this->step12Label->Name = L"step12Label";
			this->step12Label->Size = System::Drawing::Size(44, 13);
			this->step12Label->TabIndex = 69;
			this->step12Label->Text = L"Step 2";
			this->step12Label->Visible = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel2);
			this->groupBox3->Location = System::Drawing::Point(122, 288);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(754, 287);
			this->groupBox3->TabIndex = 68;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Load Box Measurements";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Outset;
			this->tableLayoutPanel2->ColumnCount = 6;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				16.66667F)));
			this->tableLayoutPanel2->Controls->Add(this->label69, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->step9Label, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->step10Label, 4, 0);
			this->tableLayoutPanel2->Controls->Add(this->step11Label, 5, 0);
			this->tableLayoutPanel2->Controls->Add(this->label73, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label74, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->label75, 5, 1);
			this->tableLayoutPanel2->Controls->Add(this->label76, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->step9Farm, 3, 1);
			this->tableLayoutPanel2->Controls->Add(this->label78, 4, 1);
			this->tableLayoutPanel2->Controls->Add(this->label79, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->label80, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->step9Load, 3, 2);
			this->tableLayoutPanel2->Controls->Add(this->label82, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->step10Load, 4, 2);
			this->tableLayoutPanel2->Controls->Add(this->step11Load, 5, 2);
			this->tableLayoutPanel2->Controls->Add(this->label85, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->label86, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->label87, 0, 5);
			this->tableLayoutPanel2->Controls->Add(this->label88, 0, 6);
			this->tableLayoutPanel2->Controls->Add(this->label89, 0, 7);
			this->tableLayoutPanel2->Controls->Add(this->vcc6, 1, 4);
			this->tableLayoutPanel2->Controls->Add(this->vp6, 1, 5);
			this->tableLayoutPanel2->Controls->Add(this->vs6, 1, 6);
			this->tableLayoutPanel2->Controls->Add(this->vps6, 1, 7);
			this->tableLayoutPanel2->Controls->Add(this->vcc7, 2, 4);
			this->tableLayoutPanel2->Controls->Add(this->vp7, 2, 5);
			this->tableLayoutPanel2->Controls->Add(this->vs7, 2, 6);
			this->tableLayoutPanel2->Controls->Add(this->vps7, 2, 7);
			this->tableLayoutPanel2->Controls->Add(this->vps8, 3, 7);
			this->tableLayoutPanel2->Controls->Add(this->vs8, 3, 6);
			this->tableLayoutPanel2->Controls->Add(this->vp8, 3, 5);
			this->tableLayoutPanel2->Controls->Add(this->vcc8, 3, 4);
			this->tableLayoutPanel2->Controls->Add(this->vcc9, 4, 4);
			this->tableLayoutPanel2->Controls->Add(this->vp9, 4, 5);
			this->tableLayoutPanel2->Controls->Add(this->vs9, 4, 6);
			this->tableLayoutPanel2->Controls->Add(this->vps9, 4, 7);
			this->tableLayoutPanel2->Controls->Add(this->vps10, 5, 7);
			this->tableLayoutPanel2->Controls->Add(this->vs10, 5, 6);
			this->tableLayoutPanel2->Controls->Add(this->vp10, 5, 5);
			this->tableLayoutPanel2->Controls->Add(this->vcc10, 5, 4);
			this->tableLayoutPanel2->Controls->Add(this->time6, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->time8, 3, 3);
			this->tableLayoutPanel2->Controls->Add(this->time9, 4, 3);
			this->tableLayoutPanel2->Controls->Add(this->time10, 5, 3);
			this->tableLayoutPanel2->Controls->Add(this->label90, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->time7, 2, 3);
			this->tableLayoutPanel2->Location = System::Drawing::Point(13, 23);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 8;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(729, 258);
			this->tableLayoutPanel2->TabIndex = 50;
			// 
			// label69
			// 
			this->label69->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label69->AutoSize = true;
			this->label69->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(160, 10);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(44, 13);
			this->label69->TabIndex = 0;
			this->label69->Text = L"Step 1";
			// 
			// step9Label
			// 
			this->step9Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step9Label->AutoSize = true;
			this->step9Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step9Label->Location = System::Drawing::Point(402, 10);
			this->step9Label->Name = L"step9Label";
			this->step9Label->Size = System::Drawing::Size(44, 13);
			this->step9Label->TabIndex = 0;
			this->step9Label->Text = L"Step 3";
			// 
			// step10Label
			// 
			this->step10Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step10Label->AutoSize = true;
			this->step10Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step10Label->Location = System::Drawing::Point(523, 10);
			this->step10Label->Name = L"step10Label";
			this->step10Label->Size = System::Drawing::Size(44, 13);
			this->step10Label->TabIndex = 0;
			this->step10Label->Text = L"Step 4";
			// 
			// step11Label
			// 
			this->step11Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step11Label->AutoSize = true;
			this->step11Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step11Label->Location = System::Drawing::Point(645, 10);
			this->step11Label->Name = L"step11Label";
			this->step11Label->Size = System::Drawing::Size(44, 13);
			this->step11Label->TabIndex = 0;
			this->step11Label->Text = L"Step 5";
			// 
			// label73
			// 
			this->label73->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(46, 42);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(30, 13);
			this->label73->TabIndex = 1;
			this->label73->Text = L"Farm";
			// 
			// label74
			// 
			this->label74->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(171, 42);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(23, 13);
			this->label74->TabIndex = 1;
			this->label74->Text = L"ON";
			// 
			// label75
			// 
			this->label75->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label75->AutoSize = true;
			this->label75->Location = System::Drawing::Point(655, 42);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(23, 13);
			this->label75->TabIndex = 1;
			this->label75->Text = L"ON";
			// 
			// label76
			// 
			this->label76->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(290, 42);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(27, 13);
			this->label76->TabIndex = 1;
			this->label76->Text = L"OFF";
			// 
			// step9Farm
			// 
			this->step9Farm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step9Farm->AutoSize = true;
			this->step9Farm->Location = System::Drawing::Point(411, 42);
			this->step9Farm->Name = L"step9Farm";
			this->step9Farm->Size = System::Drawing::Size(27, 13);
			this->step9Farm->TabIndex = 1;
			this->step9Farm->Text = L"OFF";
			// 
			// label78
			// 
			this->label78->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label78->AutoSize = true;
			this->label78->Location = System::Drawing::Point(532, 42);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(27, 13);
			this->label78->TabIndex = 1;
			this->label78->Text = L"OFF";
			// 
			// label79
			// 
			this->label79->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label79->AutoSize = true;
			this->label79->Location = System::Drawing::Point(35, 74);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(52, 13);
			this->label79->TabIndex = 1;
			this->label79->Text = L"Load Box";
			// 
			// label80
			// 
			this->label80->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label80->AutoSize = true;
			this->label80->Location = System::Drawing::Point(169, 74);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(27, 13);
			this->label80->TabIndex = 1;
			this->label80->Text = L"OFF";
			// 
			// step9Load
			// 
			this->step9Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step9Load->AutoSize = true;
			this->step9Load->Location = System::Drawing::Point(407, 74);
			this->step9Load->Name = L"step9Load";
			this->step9Load->Size = System::Drawing::Size(34, 13);
			this->step9Load->TabIndex = 1;
			this->step9Load->Text = L"HALF";
			// 
			// label82
			// 
			this->label82->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label82->AutoSize = true;
			this->label82->Location = System::Drawing::Point(290, 74);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(27, 13);
			this->label82->TabIndex = 1;
			this->label82->Text = L"OFF";
			// 
			// step10Load
			// 
			this->step10Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step10Load->AutoSize = true;
			this->step10Load->Location = System::Drawing::Point(529, 74);
			this->step10Load->Name = L"step10Load";
			this->step10Load->Size = System::Drawing::Size(33, 13);
			this->step10Load->TabIndex = 1;
			this->step10Load->Text = L"FULL";
			// 
			// step11Load
			// 
			this->step11Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step11Load->AutoSize = true;
			this->step11Load->Location = System::Drawing::Point(650, 74);
			this->step11Load->Name = L"step11Load";
			this->step11Load->Size = System::Drawing::Size(33, 13);
			this->step11Load->TabIndex = 1;
			this->step11Load->Text = L"FULL";
			// 
			// label85
			// 
			this->label85->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label85->AutoSize = true;
			this->label85->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label85->Location = System::Drawing::Point(10, 106);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(103, 13);
			this->label85->TabIndex = 1;
			this->label85->Text = L"Enter Start Time:";
			// 
			// label86
			// 
			this->label86->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label86->AutoSize = true;
			this->label86->Location = System::Drawing::Point(40, 138);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(42, 13);
			this->label86->TabIndex = 1;
			this->label86->Text = L"Vcc (V)";
			// 
			// label87
			// 
			this->label87->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label87->AutoSize = true;
			this->label87->Location = System::Drawing::Point(43, 170);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(36, 13);
			this->label87->TabIndex = 1;
			this->label87->Text = L"Vp (V)";
			// 
			// label88
			// 
			this->label88->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label88->AutoSize = true;
			this->label88->Location = System::Drawing::Point(44, 202);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(35, 13);
			this->label88->TabIndex = 1;
			this->label88->Text = L"Vs (V)";
			// 
			// label89
			// 
			this->label89->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label89->AutoSize = true;
			this->label89->Location = System::Drawing::Point(41, 234);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(41, 13);
			this->label89->TabIndex = 1;
			this->label89->Text = L"Vps (V)";
			// 
			// vcc6
			// 
			this->vcc6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc6->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc6->Location = System::Drawing::Point(135, 135);
			this->vcc6->Name = L"vcc6";
			this->vcc6->ReadOnly = true;
			this->vcc6->Size = System::Drawing::Size(95, 20);
			this->vcc6->TabIndex = 11;
			this->vcc6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vp6
			// 
			this->vp6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp6->BackColor = System::Drawing::Color::Gainsboro;
			this->vp6->Location = System::Drawing::Point(135, 167);
			this->vp6->Name = L"vp6";
			this->vp6->ReadOnly = true;
			this->vp6->Size = System::Drawing::Size(95, 20);
			this->vp6->TabIndex = 12;
			this->vp6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vs6
			// 
			this->vs6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs6->BackColor = System::Drawing::Color::Gainsboro;
			this->vs6->Location = System::Drawing::Point(135, 199);
			this->vs6->Name = L"vs6";
			this->vs6->ReadOnly = true;
			this->vs6->Size = System::Drawing::Size(95, 20);
			this->vs6->TabIndex = 13;
			this->vs6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vps6
			// 
			this->vps6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps6->BackColor = System::Drawing::Color::Gainsboro;
			this->vps6->Location = System::Drawing::Point(135, 231);
			this->vps6->Name = L"vps6";
			this->vps6->ReadOnly = true;
			this->vps6->Size = System::Drawing::Size(95, 20);
			this->vps6->TabIndex = 14;
			this->vps6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vcc7
			// 
			this->vcc7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc7->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc7->Location = System::Drawing::Point(256, 135);
			this->vcc7->Name = L"vcc7";
			this->vcc7->ReadOnly = true;
			this->vcc7->Size = System::Drawing::Size(95, 20);
			this->vcc7->TabIndex = 15;
			this->vcc7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vp7
			// 
			this->vp7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp7->BackColor = System::Drawing::Color::Gainsboro;
			this->vp7->Location = System::Drawing::Point(256, 167);
			this->vp7->Name = L"vp7";
			this->vp7->ReadOnly = true;
			this->vp7->Size = System::Drawing::Size(95, 20);
			this->vp7->TabIndex = 16;
			this->vp7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vs7
			// 
			this->vs7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs7->BackColor = System::Drawing::Color::Gainsboro;
			this->vs7->Location = System::Drawing::Point(256, 199);
			this->vs7->Name = L"vs7";
			this->vs7->ReadOnly = true;
			this->vs7->Size = System::Drawing::Size(95, 20);
			this->vs7->TabIndex = 17;
			this->vs7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vps7
			// 
			this->vps7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps7->BackColor = System::Drawing::Color::Gainsboro;
			this->vps7->Location = System::Drawing::Point(256, 231);
			this->vps7->Name = L"vps7";
			this->vps7->ReadOnly = true;
			this->vps7->Size = System::Drawing::Size(95, 20);
			this->vps7->TabIndex = 18;
			this->vps7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vps8
			// 
			this->vps8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps8->BackColor = System::Drawing::Color::Gainsboro;
			this->vps8->Location = System::Drawing::Point(377, 231);
			this->vps8->Name = L"vps8";
			this->vps8->ReadOnly = true;
			this->vps8->Size = System::Drawing::Size(95, 20);
			this->vps8->TabIndex = 22;
			this->vps8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vs8
			// 
			this->vs8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs8->BackColor = System::Drawing::Color::Gainsboro;
			this->vs8->Location = System::Drawing::Point(377, 199);
			this->vs8->Name = L"vs8";
			this->vs8->ReadOnly = true;
			this->vs8->Size = System::Drawing::Size(95, 20);
			this->vs8->TabIndex = 21;
			this->vs8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vp8
			// 
			this->vp8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp8->BackColor = System::Drawing::Color::Gainsboro;
			this->vp8->Location = System::Drawing::Point(377, 167);
			this->vp8->Name = L"vp8";
			this->vp8->ReadOnly = true;
			this->vp8->Size = System::Drawing::Size(95, 20);
			this->vp8->TabIndex = 20;
			this->vp8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vcc8
			// 
			this->vcc8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc8->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc8->Location = System::Drawing::Point(377, 135);
			this->vcc8->Name = L"vcc8";
			this->vcc8->ReadOnly = true;
			this->vcc8->Size = System::Drawing::Size(95, 20);
			this->vcc8->TabIndex = 19;
			this->vcc8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vcc9
			// 
			this->vcc9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc9->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc9->Location = System::Drawing::Point(498, 135);
			this->vcc9->Name = L"vcc9";
			this->vcc9->ReadOnly = true;
			this->vcc9->Size = System::Drawing::Size(95, 20);
			this->vcc9->TabIndex = 23;
			this->vcc9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vp9
			// 
			this->vp9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp9->BackColor = System::Drawing::Color::Gainsboro;
			this->vp9->Location = System::Drawing::Point(498, 167);
			this->vp9->Name = L"vp9";
			this->vp9->ReadOnly = true;
			this->vp9->Size = System::Drawing::Size(95, 20);
			this->vp9->TabIndex = 24;
			this->vp9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vs9
			// 
			this->vs9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs9->BackColor = System::Drawing::Color::Gainsboro;
			this->vs9->Location = System::Drawing::Point(498, 199);
			this->vs9->Name = L"vs9";
			this->vs9->ReadOnly = true;
			this->vs9->Size = System::Drawing::Size(95, 20);
			this->vs9->TabIndex = 25;
			this->vs9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vps9
			// 
			this->vps9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps9->BackColor = System::Drawing::Color::Gainsboro;
			this->vps9->Location = System::Drawing::Point(498, 231);
			this->vps9->Name = L"vps9";
			this->vps9->ReadOnly = true;
			this->vps9->Size = System::Drawing::Size(95, 20);
			this->vps9->TabIndex = 26;
			this->vps9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vps10
			// 
			this->vps10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps10->BackColor = System::Drawing::Color::Gainsboro;
			this->vps10->Location = System::Drawing::Point(619, 231);
			this->vps10->Name = L"vps10";
			this->vps10->ReadOnly = true;
			this->vps10->Size = System::Drawing::Size(95, 20);
			this->vps10->TabIndex = 30;
			this->vps10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vs10
			// 
			this->vs10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs10->BackColor = System::Drawing::Color::Gainsboro;
			this->vs10->Location = System::Drawing::Point(619, 199);
			this->vs10->Name = L"vs10";
			this->vs10->ReadOnly = true;
			this->vs10->Size = System::Drawing::Size(95, 20);
			this->vs10->TabIndex = 29;
			this->vs10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vp10
			// 
			this->vp10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp10->BackColor = System::Drawing::Color::Gainsboro;
			this->vp10->Location = System::Drawing::Point(619, 167);
			this->vp10->Name = L"vp10";
			this->vp10->ReadOnly = true;
			this->vp10->Size = System::Drawing::Size(95, 20);
			this->vp10->TabIndex = 28;
			this->vp10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// vcc10
			// 
			this->vcc10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc10->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc10->Location = System::Drawing::Point(619, 135);
			this->vcc10->Name = L"vcc10";
			this->vcc10->ReadOnly = true;
			this->vcc10->Size = System::Drawing::Size(95, 20);
			this->vcc10->TabIndex = 27;
			this->vcc10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// time6
			// 
			this->time6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time6->BackColor = System::Drawing::Color::Gainsboro;
			this->time6->Location = System::Drawing::Point(135, 103);
			this->time6->Mask = L"00:00";
			this->time6->Name = L"time6";
			this->time6->ReadOnly = true;
			this->time6->Size = System::Drawing::Size(95, 20);
			this->time6->TabIndex = 6;
			this->time6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time6->ValidatingType = System::DateTime::typeid;
			// 
			// time8
			// 
			this->time8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time8->BackColor = System::Drawing::Color::Gainsboro;
			this->time8->Location = System::Drawing::Point(377, 103);
			this->time8->Mask = L"00:00";
			this->time8->Name = L"time8";
			this->time8->ReadOnly = true;
			this->time8->Size = System::Drawing::Size(95, 20);
			this->time8->TabIndex = 8;
			this->time8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time8->ValidatingType = System::DateTime::typeid;
			// 
			// time9
			// 
			this->time9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time9->BackColor = System::Drawing::Color::Gainsboro;
			this->time9->Location = System::Drawing::Point(498, 103);
			this->time9->Mask = L"00:00";
			this->time9->Name = L"time9";
			this->time9->ReadOnly = true;
			this->time9->Size = System::Drawing::Size(95, 20);
			this->time9->TabIndex = 9;
			this->time9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time9->ValidatingType = System::DateTime::typeid;
			// 
			// time10
			// 
			this->time10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time10->BackColor = System::Drawing::Color::Gainsboro;
			this->time10->Location = System::Drawing::Point(619, 103);
			this->time10->Mask = L"00:00";
			this->time10->Name = L"time10";
			this->time10->ReadOnly = true;
			this->time10->Size = System::Drawing::Size(95, 20);
			this->time10->TabIndex = 10;
			this->time10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time10->ValidatingType = System::DateTime::typeid;
			// 
			// label90
			// 
			this->label90->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label90->AutoSize = true;
			this->label90->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label90->Location = System::Drawing::Point(281, 10);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(44, 13);
			this->label90->TabIndex = 0;
			this->label90->Text = L"Step 2";
			// 
			// time7
			// 
			this->time7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time7->BackColor = System::Drawing::Color::Gainsboro;
			this->time7->Location = System::Drawing::Point(256, 103);
			this->time7->Mask = L"00:00";
			this->time7->Name = L"time7";
			this->time7->ReadOnly = true;
			this->time7->Size = System::Drawing::Size(95, 20);
			this->time7->TabIndex = 7;
			this->time7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time7->ValidatingType = System::DateTime::typeid;
			// 
			// groupBox2
			// 
			this->groupBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->groupBox2->Controls->Add(this->F5Graph);
			this->groupBox2->Controls->Add(this->form5File);
			this->groupBox2->Controls->Add(this->form5Open);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Location = System::Drawing::Point(24, 63);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(325, 110);
			this->groupBox2->TabIndex = 67;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Form Input";
			// 
			// F5Graph
			// 
			this->F5Graph->Enabled = false;
			this->F5Graph->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"F5Graph.Image")));
			this->F5Graph->Location = System::Drawing::Point(81, 61);
			this->F5Graph->Name = L"F5Graph";
			this->F5Graph->Size = System::Drawing::Size(52, 37);
			this->F5Graph->TabIndex = 77;
			this->F5Graph->UseVisualStyleBackColor = true;
			this->F5Graph->Click += gcnew System::EventHandler(this, &Form1::F3Graph_Click);
			// 
			// form5File
			// 
			this->form5File->AutoSize = true;
			this->form5File->ForeColor = System::Drawing::Color::Red;
			this->form5File->Location = System::Drawing::Point(6, 44);
			this->form5File->Name = L"form5File";
			this->form5File->Size = System::Drawing::Size(100, 13);
			this->form5File->TabIndex = 55;
			this->form5File->Text = L"Please open a file...";
			// 
			// form5Open
			// 
			this->form5Open->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"form5Open.Image")));
			this->form5Open->Location = System::Drawing::Point(23, 61);
			this->form5Open->Name = L"form5Open";
			this->form5Open->Size = System::Drawing::Size(52, 37);
			this->form5Open->TabIndex = 1;
			this->form5Open->UseVisualStyleBackColor = true;
			this->form5Open->Click += gcnew System::EventHandler(this, &Form1::form3Open_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(182, 81);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(73, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->Text = L"User input";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(182, 59);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(68, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"File Input";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 16);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(188, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Form 5 Test Data will be populated by:";
			// 
			// clearButton5
			// 
			this->clearButton5->Location = System::Drawing::Point(883, 490);
			this->clearButton5->Name = L"clearButton5";
			this->clearButton5->Size = System::Drawing::Size(75, 23);
			this->clearButton5->TabIndex = 66;
			this->clearButton5->Text = L"Clear Data";
			this->clearButton5->UseVisualStyleBackColor = true;
			this->clearButton5->Click += gcnew System::EventHandler(this, &Form1::clearButton_Click);
			// 
			// enterData5
			// 
			this->enterData5->Location = System::Drawing::Point(883, 519);
			this->enterData5->Name = L"enterData5";
			this->enterData5->Size = System::Drawing::Size(75, 56);
			this->enterData5->TabIndex = 65;
			this->enterData5->Text = L"Process File Data";
			this->enterData5->UseVisualStyleBackColor = true;
			this->enterData5->Click += gcnew System::EventHandler(this, &Form1::enterData_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->richTextBox20);
			this->groupBox5->Controls->Add(this->richTextBox21);
			this->groupBox5->Controls->Add(this->label24);
			this->groupBox5->Controls->Add(this->richTextBox22);
			this->groupBox5->Controls->Add(this->richTextBox23);
			this->groupBox5->Controls->Add(this->label34);
			this->groupBox5->Controls->Add(this->label35);
			this->groupBox5->Controls->Add(this->label36);
			this->groupBox5->Controls->Add(this->label37);
			this->groupBox5->Controls->Add(this->textBox11);
			this->groupBox5->Controls->Add(this->label43);
			this->groupBox5->Controls->Add(this->textBox12);
			this->groupBox5->Controls->Add(this->textBox13);
			this->groupBox5->Controls->Add(this->textBox14);
			this->groupBox5->Controls->Add(this->textBox17);
			this->groupBox5->Controls->Add(this->label44);
			this->groupBox5->Controls->Add(this->label45);
			this->groupBox5->Controls->Add(this->label46);
			this->groupBox5->Controls->Add(this->textBox18);
			this->groupBox5->Location = System::Drawing::Point(368, 63);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(590, 183);
			this->groupBox5->TabIndex = 64;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Initial measurements and calculations with farm service de-energized:";
			// 
			// richTextBox20
			// 
			this->richTextBox20->BackColor = System::Drawing::Color::White;
			this->richTextBox20->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox20->Location = System::Drawing::Point(19, 35);
			this->richTextBox20->Name = L"richTextBox20";
			this->richTextBox20->ReadOnly = true;
			this->richTextBox20->Size = System::Drawing::Size(235, 22);
			this->richTextBox20->TabIndex = 33;
			this->richTextBox20->TabStop = false;
			this->richTextBox20->Text = L"Primary Nominal Voltage Phase to Neutral (Vpri):";
			// 
			// richTextBox21
			// 
			this->richTextBox21->BackColor = System::Drawing::Color::White;
			this->richTextBox21->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox21->Location = System::Drawing::Point(19, 63);
			this->richTextBox21->Name = L"richTextBox21";
			this->richTextBox21->ReadOnly = true;
			this->richTextBox21->Size = System::Drawing::Size(175, 22);
			this->richTextBox21->TabIndex = 33;
			this->richTextBox21->TabStop = false;
			this->richTextBox21->Text = L"Load Box Current (ILB):     Half Load";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(363, 35);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(14, 13);
			this->label24->TabIndex = 34;
			this->label24->Text = L"V";
			// 
			// richTextBox22
			// 
			this->richTextBox22->BackColor = System::Drawing::Color::White;
			this->richTextBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox22->Location = System::Drawing::Point(19, 89);
			this->richTextBox22->Name = L"richTextBox22";
			this->richTextBox22->ReadOnly = true;
			this->richTextBox22->Size = System::Drawing::Size(184, 22);
			this->richTextBox22->TabIndex = 33;
			this->richTextBox22->TabStop = false;
			this->richTextBox22->Text = L"Load Box Voltage (VLB):   Half Load";
			// 
			// richTextBox23
			// 
			this->richTextBox23->BackColor = System::Drawing::Color::White;
			this->richTextBox23->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox23->Location = System::Drawing::Point(19, 117);
			this->richTextBox23->Name = L"richTextBox23";
			this->richTextBox23->ReadOnly = true;
			this->richTextBox23->Size = System::Drawing::Size(184, 22);
			this->richTextBox23->TabIndex = 33;
			this->richTextBox23->TabStop = false;
			this->richTextBox23->Text = L"Transformer Primary Current (Ip):";
			this->toolTip1->SetToolTip(this->richTextBox23, L"Ip = (I lb x V lb) / V pri");
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(361, 115);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(14, 13);
			this->label34->TabIndex = 34;
			this->label34->Text = L"A";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(361, 61);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(14, 13);
			this->label35->TabIndex = 34;
			this->label35->Text = L"A";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(561, 61);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(14, 13);
			this->label36->TabIndex = 34;
			this->label36->Text = L"A";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(361, 87);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(14, 13);
			this->label37->TabIndex = 34;
			this->label37->Text = L"V";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(255, 32);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 0;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(561, 87);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(14, 13);
			this->label43->TabIndex = 34;
			this->label43->Text = L"V";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(255, 58);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(100, 20);
			this->textBox12->TabIndex = 1;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(255, 84);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 20);
			this->textBox13->TabIndex = 2;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(455, 58);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 20);
			this->textBox14->TabIndex = 3;
			this->textBox14->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(455, 84);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(100, 20);
			this->textBox17->TabIndex = 4;
			this->textBox17->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(399, 61);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(50, 13);
			this->label44->TabIndex = 36;
			this->label44->Text = L"Full Load";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(399, 87);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(50, 13);
			this->label45->TabIndex = 36;
			this->label45->Text = L"Full Load";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(18, 151);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(319, 13);
			this->label46->TabIndex = 38;
			this->label46->Text = L"Note: I p is measured on the source side of the ground connection";
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::Color::Gainsboro;
			this->textBox18->Location = System::Drawing::Point(255, 112);
			this->textBox18->Name = L"textBox18";
			this->textBox18->ReadOnly = true;
			this->textBox18->Size = System::Drawing::Size(100, 20);
			this->textBox18->TabIndex = 5;
			this->toolTip1->SetToolTip(this->textBox18, L"Ip = (I lb x V lb) / V pri");
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(119, 259);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(242, 26);
			this->label68->TabIndex = 63;
			this->label68->Text = L"NOTE: For Voltages, record the highest value\r\nmeasured over the minimum 2 minute " 
				L"test duration";
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label101->Location = System::Drawing::Point(220, 12);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(565, 40);
			this->label101->TabIndex = 41;
			this->label101->Text = L"Form 5\r\nDistributor Contribution Confirmation Test and Calculations Test Data";
			this->label101->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// time12
			// 
			this->time12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time12->BackColor = System::Drawing::Color::Gainsboro;
			this->time12->Location = System::Drawing::Point(885, 306);
			this->time12->Mask = L"00:00";
			this->time12->Name = L"time12";
			this->time12->ReadOnly = true;
			this->time12->Size = System::Drawing::Size(95, 20);
			this->time12->TabIndex = 31;
			this->time12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->time12->ValidatingType = System::DateTime::typeid;
			this->time12->Visible = false;
			// 
			// vcc12
			// 
			this->vcc12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vcc12->BackColor = System::Drawing::Color::Gainsboro;
			this->vcc12->Location = System::Drawing::Point(885, 338);
			this->vcc12->Name = L"vcc12";
			this->vcc12->ReadOnly = true;
			this->vcc12->Size = System::Drawing::Size(95, 20);
			this->vcc12->TabIndex = 32;
			this->vcc12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vcc12->Visible = false;
			// 
			// vp12
			// 
			this->vp12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vp12->BackColor = System::Drawing::Color::Gainsboro;
			this->vp12->Location = System::Drawing::Point(885, 370);
			this->vp12->Name = L"vp12";
			this->vp12->ReadOnly = true;
			this->vp12->Size = System::Drawing::Size(95, 20);
			this->vp12->TabIndex = 33;
			this->vp12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vp12->Visible = false;
			// 
			// vs12
			// 
			this->vs12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vs12->BackColor = System::Drawing::Color::Gainsboro;
			this->vs12->Location = System::Drawing::Point(885, 402);
			this->vs12->Name = L"vs12";
			this->vs12->ReadOnly = true;
			this->vs12->Size = System::Drawing::Size(95, 20);
			this->vs12->TabIndex = 34;
			this->vs12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vs12->Visible = false;
			// 
			// vps12
			// 
			this->vps12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps12->BackColor = System::Drawing::Color::Gainsboro;
			this->vps12->Location = System::Drawing::Point(885, 434);
			this->vps12->Name = L"vps12";
			this->vps12->ReadOnly = true;
			this->vps12->Size = System::Drawing::Size(95, 20);
			this->vps12->TabIndex = 35;
			this->vps12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps12->Visible = false;
			// 
			// tabPage12
			// 
			this->tabPage12->BackColor = System::Drawing::Color::White;
			this->tabPage12->Controls->Add(this->groupBox11);
			this->tabPage12->Controls->Add(this->groupBox12);
			this->tabPage12->Controls->Add(this->groupBox13);
			this->tabPage12->Controls->Add(this->groupBox14);
			this->tabPage12->Controls->Add(this->groupBox15);
			this->tabPage12->Controls->Add(this->label102);
			this->tabPage12->Location = System::Drawing::Point(4, 22);
			this->tabPage12->Name = L"tabPage12";
			this->tabPage12->Padding = System::Windows::Forms::Padding(3);
			this->tabPage12->Size = System::Drawing::Size(1005, 576);
			this->tabPage12->TabIndex = 1;
			this->tabPage12->Text = L"Page 2";
			this->tabPage12->Enter += gcnew System::EventHandler(this, &Form1::tabPage12_Enter);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->vccd3Phase5);
			this->groupBox11->Controls->Add(this->vccd1Phase5);
			this->groupBox11->Controls->Add(this->label49);
			this->groupBox11->Location = System::Drawing::Point(229, 416);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(543, 116);
			this->groupBox11->TabIndex = 50;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Distributor Contribution to ACC/ACV (VccD)";
			// 
			// vccd3Phase5
			// 
			this->vccd3Phase5->AutoSize = true;
			this->vccd3Phase5->Location = System::Drawing::Point(286, 56);
			this->vccd3Phase5->Name = L"vccd3Phase5";
			this->vccd3Phase5->Size = System::Drawing::Size(14, 13);
			this->vccd3Phase5->TabIndex = 7;
			this->vccd3Phase5->Text = L"V";
			this->vccd3Phase5->Visible = false;
			// 
			// vccd1Phase5
			// 
			this->vccd1Phase5->AutoSize = true;
			this->vccd1Phase5->Location = System::Drawing::Point(286, 56);
			this->vccd1Phase5->Name = L"vccd1Phase5";
			this->vccd1Phase5->Size = System::Drawing::Size(14, 13);
			this->vccd1Phase5->TabIndex = 7;
			this->vccd1Phase5->Text = L"V";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(95, 56);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(37, 13);
			this->label49->TabIndex = 13;
			this->label49->Text = L"VccD:";
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->richTextBox10);
			this->groupBox12->Controls->Add(this->vccfull5);
			this->groupBox12->Controls->Add(this->richTextBox13);
			this->groupBox12->Controls->Add(this->vpfull5);
			this->groupBox12->Location = System::Drawing::Point(229, 338);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(543, 62);
			this->groupBox12->TabIndex = 47;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Vcc and corresponding Vp in Distributor Contribution Test with Farm OFF and Load " 
				L"Box MAX:";
			// 
			// richTextBox10
			// 
			this->richTextBox10->BackColor = System::Drawing::Color::White;
			this->richTextBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox10->Location = System::Drawing::Point(6, 28);
			this->richTextBox10->Name = L"richTextBox10";
			this->richTextBox10->ReadOnly = true;
			this->richTextBox10->Size = System::Drawing::Size(106, 19);
			this->richTextBox10->TabIndex = 6;
			this->richTextBox10->TabStop = false;
			this->richTextBox10->Text = L"Vccfull:";
			// 
			// vccfull5
			// 
			this->vccfull5->AutoSize = true;
			this->vccfull5->Location = System::Drawing::Point(118, 28);
			this->vccfull5->Name = L"vccfull5";
			this->vccfull5->Size = System::Drawing::Size(14, 13);
			this->vccfull5->TabIndex = 7;
			this->vccfull5->Text = L"V";
			// 
			// richTextBox13
			// 
			this->richTextBox13->BackColor = System::Drawing::Color::White;
			this->richTextBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox13->Location = System::Drawing::Point(174, 28);
			this->richTextBox13->Name = L"richTextBox13";
			this->richTextBox13->ReadOnly = true;
			this->richTextBox13->Size = System::Drawing::Size(106, 19);
			this->richTextBox13->TabIndex = 6;
			this->richTextBox13->TabStop = false;
			this->richTextBox13->Text = L"Vpfull:";
			// 
			// vpfull5
			// 
			this->vpfull5->AutoSize = true;
			this->vpfull5->Location = System::Drawing::Point(286, 28);
			this->vpfull5->Name = L"vpfull5";
			this->vpfull5->Size = System::Drawing::Size(14, 13);
			this->vpfull5->TabIndex = 7;
			this->vpfull5->Text = L"V";
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->richTextBox16);
			this->groupBox13->Controls->Add(this->vcchalf5);
			this->groupBox13->Controls->Add(this->richTextBox834);
			this->groupBox13->Controls->Add(this->vphalf5);
			this->groupBox13->Location = System::Drawing::Point(229, 261);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(543, 62);
			this->groupBox13->TabIndex = 48;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"Vcc and corresponding Vp in Distributor Contribution Test with Farm OFF and Load " 
				L"Box HALF:";
			// 
			// richTextBox16
			// 
			this->richTextBox16->BackColor = System::Drawing::Color::White;
			this->richTextBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox16->Location = System::Drawing::Point(6, 28);
			this->richTextBox16->Name = L"richTextBox16";
			this->richTextBox16->ReadOnly = true;
			this->richTextBox16->Size = System::Drawing::Size(106, 19);
			this->richTextBox16->TabIndex = 6;
			this->richTextBox16->TabStop = false;
			this->richTextBox16->Text = L"Vcchalf:";
			// 
			// vcchalf5
			// 
			this->vcchalf5->AutoSize = true;
			this->vcchalf5->Location = System::Drawing::Point(118, 28);
			this->vcchalf5->Name = L"vcchalf5";
			this->vcchalf5->Size = System::Drawing::Size(14, 13);
			this->vcchalf5->TabIndex = 7;
			this->vcchalf5->Text = L"V";
			// 
			// richTextBox834
			// 
			this->richTextBox834->BackColor = System::Drawing::Color::White;
			this->richTextBox834->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox834->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox834->Location = System::Drawing::Point(174, 28);
			this->richTextBox834->Name = L"richTextBox834";
			this->richTextBox834->ReadOnly = true;
			this->richTextBox834->Size = System::Drawing::Size(106, 19);
			this->richTextBox834->TabIndex = 6;
			this->richTextBox834->TabStop = false;
			this->richTextBox834->Text = L"Vphalf:";
			// 
			// vphalf5
			// 
			this->vphalf5->AutoSize = true;
			this->vphalf5->Location = System::Drawing::Point(286, 28);
			this->vphalf5->Name = L"vphalf5";
			this->vphalf5->Size = System::Drawing::Size(14, 13);
			this->vphalf5->TabIndex = 7;
			this->vphalf5->Text = L"V";
			// 
			// groupBox14
			// 
			this->groupBox14->Controls->Add(this->richTextBox24);
			this->groupBox14->Controls->Add(this->vccoff5);
			this->groupBox14->Controls->Add(this->richTextBox25);
			this->groupBox14->Controls->Add(this->vpoff5);
			this->groupBox14->Location = System::Drawing::Point(229, 184);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(543, 62);
			this->groupBox14->TabIndex = 49;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"Vcc and corresponding Vp in Distributor Contribution Test with Farm OFF and Load " 
				L"Box OFF:";
			// 
			// richTextBox24
			// 
			this->richTextBox24->BackColor = System::Drawing::Color::White;
			this->richTextBox24->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox24->Location = System::Drawing::Point(6, 28);
			this->richTextBox24->Name = L"richTextBox24";
			this->richTextBox24->ReadOnly = true;
			this->richTextBox24->Size = System::Drawing::Size(106, 19);
			this->richTextBox24->TabIndex = 6;
			this->richTextBox24->TabStop = false;
			this->richTextBox24->Text = L"Vccoff:";
			// 
			// vccoff5
			// 
			this->vccoff5->AutoSize = true;
			this->vccoff5->Location = System::Drawing::Point(118, 28);
			this->vccoff5->Name = L"vccoff5";
			this->vccoff5->Size = System::Drawing::Size(14, 13);
			this->vccoff5->TabIndex = 7;
			this->vccoff5->Text = L"V";
			// 
			// richTextBox25
			// 
			this->richTextBox25->BackColor = System::Drawing::Color::White;
			this->richTextBox25->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox25->Location = System::Drawing::Point(174, 28);
			this->richTextBox25->Name = L"richTextBox25";
			this->richTextBox25->ReadOnly = true;
			this->richTextBox25->Size = System::Drawing::Size(106, 19);
			this->richTextBox25->TabIndex = 6;
			this->richTextBox25->TabStop = false;
			this->richTextBox25->Text = L"Vpoff:";
			// 
			// vpoff5
			// 
			this->vpoff5->AutoSize = true;
			this->vpoff5->Location = System::Drawing::Point(286, 28);
			this->vpoff5->Name = L"vpoff5";
			this->vpoff5->Size = System::Drawing::Size(14, 13);
			this->vpoff5->TabIndex = 7;
			this->vpoff5->Text = L"V";
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->richTextBox26);
			this->groupBox15->Controls->Add(this->vccfsv5);
			this->groupBox15->Controls->Add(this->richTextBox27);
			this->groupBox15->Controls->Add(this->vpfsv5);
			this->groupBox15->Location = System::Drawing::Point(229, 107);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(543, 62);
			this->groupBox15->TabIndex = 46;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"Highest Vcc and corresponding Vp from Farm Stray Voltage Test:";
			// 
			// richTextBox26
			// 
			this->richTextBox26->BackColor = System::Drawing::Color::White;
			this->richTextBox26->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox26->Location = System::Drawing::Point(6, 28);
			this->richTextBox26->Name = L"richTextBox26";
			this->richTextBox26->ReadOnly = true;
			this->richTextBox26->Size = System::Drawing::Size(106, 19);
			this->richTextBox26->TabIndex = 6;
			this->richTextBox26->TabStop = false;
			this->richTextBox26->Text = L"Vccfsv:";
			// 
			// vccfsv5
			// 
			this->vccfsv5->AutoSize = true;
			this->vccfsv5->Location = System::Drawing::Point(118, 28);
			this->vccfsv5->Name = L"vccfsv5";
			this->vccfsv5->Size = System::Drawing::Size(14, 13);
			this->vccfsv5->TabIndex = 7;
			this->vccfsv5->Text = L"V";
			// 
			// richTextBox27
			// 
			this->richTextBox27->BackColor = System::Drawing::Color::White;
			this->richTextBox27->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox27->Location = System::Drawing::Point(174, 28);
			this->richTextBox27->Name = L"richTextBox27";
			this->richTextBox27->ReadOnly = true;
			this->richTextBox27->Size = System::Drawing::Size(106, 19);
			this->richTextBox27->TabIndex = 6;
			this->richTextBox27->TabStop = false;
			this->richTextBox27->Text = L"Vpfsv:";
			// 
			// vpfsv5
			// 
			this->vpfsv5->AutoSize = true;
			this->vpfsv5->Location = System::Drawing::Point(286, 28);
			this->vpfsv5->Name = L"vpfsv5";
			this->vpfsv5->Size = System::Drawing::Size(14, 13);
			this->vpfsv5->TabIndex = 7;
			this->vpfsv5->Text = L"V";
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label102->Location = System::Drawing::Point(262, 13);
			this->label102->Name = L"label102";
			this->label102->Size = System::Drawing::Size(481, 80);
			this->label102->TabIndex = 42;
			this->label102->Text = L"Form 5 (concluded)\r\n\r\nDistributor Contirbution Confirmation Test and Calculations" 
				L"\r\nCalculations";
			this->label102->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tabPage13
			// 
			this->tabPage13->BackColor = System::Drawing::Color::White;
			this->tabPage13->Controls->Add(this->form6FileText);
			this->tabPage13->Controls->Add(this->groupBox20);
			this->tabPage13->Controls->Add(this->button1);
			this->tabPage13->Controls->Add(this->form6Open);
			this->tabPage13->Controls->Add(this->dataGridView3);
			this->tabPage13->Controls->Add(this->label123);
			this->tabPage13->Controls->Add(this->label124);
			this->tabPage13->Location = System::Drawing::Point(4, 22);
			this->tabPage13->Name = L"tabPage13";
			this->tabPage13->Padding = System::Windows::Forms::Padding(3);
			this->tabPage13->Size = System::Drawing::Size(1019, 611);
			this->tabPage13->TabIndex = 5;
			this->tabPage13->Text = L"Form 6";
			// 
			// form6FileText
			// 
			this->form6FileText->AutoSize = true;
			this->form6FileText->ForeColor = System::Drawing::Color::Red;
			this->form6FileText->Location = System::Drawing::Point(98, 153);
			this->form6FileText->Name = L"form6FileText";
			this->form6FileText->Size = System::Drawing::Size(100, 13);
			this->form6FileText->TabIndex = 57;
			this->form6FileText->Text = L"Please open a file...";
			// 
			// groupBox20
			// 
			this->groupBox20->BackColor = System::Drawing::Color::Transparent;
			this->groupBox20->Controls->Add(this->locCombo6);
			this->groupBox20->Controls->Add(this->form6Stop);
			this->groupBox20->Controls->Add(this->form6Start);
			this->groupBox20->Controls->Add(this->label105);
			this->groupBox20->Controls->Add(this->label104);
			this->groupBox20->Controls->Add(this->label103);
			this->groupBox20->Location = System::Drawing::Point(250, 77);
			this->groupBox20->Name = L"groupBox20";
			this->groupBox20->Size = System::Drawing::Size(518, 106);
			this->groupBox20->TabIndex = 37;
			this->groupBox20->TabStop = false;
			this->groupBox20->Text = L"Test Information";
			// 
			// locCombo6
			// 
			this->locCombo6->DataSource = this->form1DataBindingSource;
			this->locCombo6->DisplayMember = L"locId";
			this->locCombo6->FormattingEnabled = true;
			this->locCombo6->Location = System::Drawing::Point(161, 73);
			this->locCombo6->Name = L"locCombo6";
			this->locCombo6->Size = System::Drawing::Size(82, 21);
			this->locCombo6->TabIndex = 36;
			// 
			// form6Stop
			// 
			this->form6Stop->BackColor = System::Drawing::Color::Gainsboro;
			this->form6Stop->Location = System::Drawing::Point(374, 38);
			this->form6Stop->Name = L"form6Stop";
			this->form6Stop->ReadOnly = true;
			this->form6Stop->Size = System::Drawing::Size(130, 20);
			this->form6Stop->TabIndex = 35;
			// 
			// form6Start
			// 
			this->form6Start->BackColor = System::Drawing::Color::Gainsboro;
			this->form6Start->Location = System::Drawing::Point(113, 38);
			this->form6Start->Name = L"form6Start";
			this->form6Start->ReadOnly = true;
			this->form6Start->Size = System::Drawing::Size(130, 20);
			this->form6Start->TabIndex = 35;
			// 
			// label105
			// 
			this->label105->AutoSize = true;
			this->label105->Location = System::Drawing::Point(6, 41);
			this->label105->Name = L"label105";
			this->label105->Size = System::Drawing::Size(86, 13);
			this->label105->TabIndex = 30;
			this->label105->Text = L"Start Date/Time:";
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->Location = System::Drawing::Point(6, 67);
			this->label104->Name = L"label104";
			this->label104->Size = System::Drawing::Size(122, 26);
			this->label104->TabIndex = 29;
			this->label104->Text = L"Animal Contact Location\r\nIdentification No:";
			// 
			// label103
			// 
			this->label103->AutoSize = true;
			this->label103->Location = System::Drawing::Point(267, 41);
			this->label103->Name = L"label103";
			this->label103->Size = System::Drawing::Size(86, 13);
			this->label103->TabIndex = 31;
			this->label103->Text = L"Stop Date/Time:";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(159, 169);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(52, 37);
			this->button1->TabIndex = 36;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::viewGraph_Click);
			// 
			// form6Open
			// 
			this->form6Open->BackColor = System::Drawing::Color::AliceBlue;
			this->form6Open->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"form6Open.Image")));
			this->form6Open->Location = System::Drawing::Point(101, 169);
			this->form6Open->Name = L"form6Open";
			this->form6Open->Size = System::Drawing::Size(52, 37);
			this->form6Open->TabIndex = 35;
			this->form6Open->UseVisualStyleBackColor = false;
			this->form6Open->Click += gcnew System::EventHandler(this, &Form1::openButt_Click);
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->AllowUserToOrderColumns = true;
			this->dataGridView3->AutoGenerateColumns = false;
			this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle35->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle35->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle35->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle35->Format = L"N2";
			dataGridViewCellStyle35->NullValue = nullptr;
			dataGridViewCellStyle35->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle35->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle35->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle35;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->dataGridViewTextBoxColumn1, 
				this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5, 
				this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7});
			this->dataGridView3->DataSource = this->form6DataBindingSource;
			this->dataGridView3->Location = System::Drawing::Point(101, 212);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->Size = System::Drawing::Size(817, 386);
			this->dataGridView3->TabIndex = 28;
			this->dataGridView3->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &Form1::dataError);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->DataPropertyName = L"hour";
			dataGridViewCellStyle36->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle36->NullValue = nullptr;
			this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle36;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Hour";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->DataPropertyName = L"highestVcc";
			dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle37;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Time Highest Steady State Vcc Recorded in Hour";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->DataPropertyName = L"aContactVolt";
			dataGridViewCellStyle38->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle38->Format = L"N2";
			dataGridViewCellStyle38->NullValue = nullptr;
			this->dataGridViewTextBoxColumn3->DefaultCellStyle = dataGridViewCellStyle38;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Animal Contact Voltage Across Shunt Resistor [Vcc] (SVCh4)";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->DataPropertyName = L"pN2RVolt";
			dataGridViewCellStyle39->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle39->Format = L"N2";
			dataGridViewCellStyle39->NullValue = nullptr;
			this->dataGridViewTextBoxColumn4->DefaultCellStyle = dataGridViewCellStyle39;
			this->dataGridViewTextBoxColumn4->HeaderText = L"Primary Neutral to Reference Ground Rod Voltage [Vp] (SVCh1)";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 125;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->DataPropertyName = L"sN2RVolt";
			dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle40->Format = L"N2";
			dataGridViewCellStyle40->NullValue = nullptr;
			this->dataGridViewTextBoxColumn5->DefaultCellStyle = dataGridViewCellStyle40;
			this->dataGridViewTextBoxColumn5->HeaderText = L"Secondary Neutral to Reference Ground Rod Voltage [Vs] (SVCh3)";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 125;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->DataPropertyName = L"pN2SNVolt";
			dataGridViewCellStyle41->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle41->Format = L"N2";
			dataGridViewCellStyle41->NullValue = nullptr;
			this->dataGridViewTextBoxColumn6->DefaultCellStyle = dataGridViewCellStyle41;
			this->dataGridViewTextBoxColumn6->HeaderText = L"Primary Neutral to Secondary Neutral Voltage [Vps] (SVCh2)";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->ReadOnly = true;
			this->dataGridViewTextBoxColumn6->Width = 125;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->DataPropertyName = L"timeVccExceeds";
			dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewTextBoxColumn7->DefaultCellStyle = dataGridViewCellStyle42;
			this->dataGridViewTextBoxColumn7->HeaderText = L"Estimated Time During Hour Vcc Exceeds ACC/ACV Threshold (hh:mm:ss)";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->ReadOnly = true;
			this->dataGridViewTextBoxColumn7->Width = 125;
			// 
			// label123
			// 
			this->label123->AutoSize = true;
			this->label123->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label123->Location = System::Drawing::Point(342, 189);
			this->label123->Name = L"label123";
			this->label123->Size = System::Drawing::Size(334, 20);
			this->label123->TabIndex = 15;
			this->label123->Text = L"FINAL FARM STRAY VOLTAGE TEST DATA";
			this->label123->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label124
			// 
			this->label124->AutoSize = true;
			this->label124->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label124->Location = System::Drawing::Point(385, 14);
			this->label124->Name = L"label124";
			this->label124->Size = System::Drawing::Size(248, 60);
			this->label124->TabIndex = 16;
			this->label124->Text = L"Form 6\r\n\r\nFinal Farm Stray Voltage Test";
			this->label124->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// reportViewer1
			// 
			reportDataSource6->Name = L"Farm_Stray_Voltage_Data_Form_1_Data";
			reportDataSource6->Value = this->form1DataBindingSource;
			reportDataSource7->Name = L"Farm_Stray_Voltage_Data_Form_2_Data";
			reportDataSource7->Value = this->form2DataBindingSource;
			reportDataSource8->Name = L"Farm_Stray_Voltage_Data_Form_3_Data";
			reportDataSource8->Value = this->form3DataBindingSource;
			reportDataSource9->Name = L"Farm_Stray_Voltage_Data_Form_5_Data";
			reportDataSource9->Value = this->form5DataBindingSource;
			reportDataSource10->Name = L"Farm_Stray_Voltage_Data_Form_6_Data";
			reportDataSource10->Value = this->form6DataBindingSource;
			this->reportViewer1->LocalReport->DataSources->Add(reportDataSource6);
			this->reportViewer1->LocalReport->DataSources->Add(reportDataSource7);
			this->reportViewer1->LocalReport->DataSources->Add(reportDataSource8);
			this->reportViewer1->LocalReport->DataSources->Add(reportDataSource9);
			this->reportViewer1->LocalReport->DataSources->Add(reportDataSource10);
			this->reportViewer1->LocalReport->EnableExternalImages = true;
			this->reportViewer1->LocalReport->ReportEmbeddedResource = L"FormReport.rdlc";
			this->reportViewer1->Location = System::Drawing::Point(0, 24);
			this->reportViewer1->Margin = System::Windows::Forms::Padding(0);
			this->reportViewer1->Name = L"reportViewer1";
			this->reportViewer1->Size = System::Drawing::Size(47, 35);
			this->reportViewer1->TabIndex = 89;
			this->reportViewer1->Visible = false;
			// 
			// Form2Progress
			// 
			this->Form2Progress->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->Form2Progress->Location = System::Drawing::Point(556, 49);
			this->Form2Progress->Name = L"Form2Progress";
			this->Form2Progress->Size = System::Drawing::Size(145, 23);
			this->Form2Progress->Step = 1;
			this->Form2Progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->Form2Progress->TabIndex = 57;
			this->Form2Progress->Visible = false;
			// 
			// step6Label
			// 
			this->step6Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step6Label->AutoSize = true;
			this->step6Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->step6Label->Location = System::Drawing::Point(623, 2);
			this->step6Label->Name = L"step6Label";
			this->step6Label->Size = System::Drawing::Size(44, 13);
			this->step6Label->TabIndex = 55;
			this->step6Label->Text = L"Step 2";
			this->step6Label->Visible = false;
			// 
			// step6Farm
			// 
			this->step6Farm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step6Farm->AutoSize = true;
			this->step6Farm->Location = System::Drawing::Point(623, 34);
			this->step6Farm->Name = L"step6Farm";
			this->step6Farm->Size = System::Drawing::Size(27, 13);
			this->step6Farm->TabIndex = 56;
			this->step6Farm->Text = L"OFF";
			this->step6Farm->Visible = false;
			// 
			// step6Load
			// 
			this->step6Load->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->step6Load->AutoSize = true;
			this->step6Load->Location = System::Drawing::Point(623, 66);
			this->step6Load->Name = L"step6Load";
			this->step6Load->Size = System::Drawing::Size(27, 13);
			this->step6Load->TabIndex = 56;
			this->step6Load->Text = L"OFF";
			this->step6Load->Visible = false;
			// 
			// vps11
			// 
			this->vps11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->vps11->BackColor = System::Drawing::Color::Gainsboro;
			this->vps11->Location = System::Drawing::Point(34, 86);
			this->vps11->Name = L"vps11";
			this->vps11->ReadOnly = true;
			this->vps11->Size = System::Drawing::Size(95, 20);
			this->vps11->TabIndex = 57;
			this->vps11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->vps11->Visible = false;
			this->vps11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox_KeyDown);
			this->vps11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox_KeyPress);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"Open a file";
			this->openFileDialog1->Filter = L"TST files|*.TST";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->instructionsToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1027, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->saveFormsToolStripMenuItem, 
				this->openExistingFormsToolStripMenuItem, this->printToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveFormsToolStripMenuItem
			// 
			this->saveFormsToolStripMenuItem->Name = L"saveFormsToolStripMenuItem";
			this->saveFormsToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->saveFormsToolStripMenuItem->Text = L"Save Forms";
			this->saveFormsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveFormsToolStripMenuItem_Click);
			// 
			// openExistingFormsToolStripMenuItem
			// 
			this->openExistingFormsToolStripMenuItem->Name = L"openExistingFormsToolStripMenuItem";
			this->openExistingFormsToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->openExistingFormsToolStripMenuItem->Text = L"Open Existing Forms";
			this->openExistingFormsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openExistingFormsToolStripMenuItem_Click);
			// 
			// printToolStripMenuItem
			// 
			this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
			this->printToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->printToolStripMenuItem->Text = L"Print...";
			this->printToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::printToolStripMenuItem_Click);
			// 
			// instructionsToolStripMenuItem
			// 
			this->instructionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->form1ToolStripMenuItem, 
				this->form2ToolStripMenuItem, this->form3ToolStripMenuItem, this->form4ToolStripMenuItem, this->form5ToolStripMenuItem, this->form6ToolStripMenuItem, 
				this->mainFormToolStripMenuItem, this->infoToolStripMenuItem});
			this->instructionsToolStripMenuItem->Name = L"instructionsToolStripMenuItem";
			this->instructionsToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->instructionsToolStripMenuItem->Text = L"Instructions";
			// 
			// form1ToolStripMenuItem
			// 
			this->form1ToolStripMenuItem->Name = L"form1ToolStripMenuItem";
			this->form1ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->form1ToolStripMenuItem->Text = L"Form 1";
			this->form1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::form1ToolStripMenuItem_Click);
			// 
			// form2ToolStripMenuItem
			// 
			this->form2ToolStripMenuItem->Name = L"form2ToolStripMenuItem";
			this->form2ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->form2ToolStripMenuItem->Text = L"Form 2";
			this->form2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::form2ToolStripMenuItem_Click);
			// 
			// form3ToolStripMenuItem
			// 
			this->form3ToolStripMenuItem->Name = L"form3ToolStripMenuItem";
			this->form3ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->form3ToolStripMenuItem->Text = L"Form 3";
			this->form3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::form3ToolStripMenuItem_Click);
			// 
			// form4ToolStripMenuItem
			// 
			this->form4ToolStripMenuItem->Name = L"form4ToolStripMenuItem";
			this->form4ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->form4ToolStripMenuItem->Text = L"Form 4";
			this->form4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::form4ToolStripMenuItem_Click);
			// 
			// form5ToolStripMenuItem
			// 
			this->form5ToolStripMenuItem->Name = L"form5ToolStripMenuItem";
			this->form5ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->form5ToolStripMenuItem->Text = L"Form 5";
			this->form5ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::form5ToolStripMenuItem_Click);
			// 
			// form6ToolStripMenuItem
			// 
			this->form6ToolStripMenuItem->Name = L"form6ToolStripMenuItem";
			this->form6ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->form6ToolStripMenuItem->Text = L"Form 6";
			this->form6ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::form6ToolStripMenuItem_Click);
			// 
			// mainFormToolStripMenuItem
			// 
			this->mainFormToolStripMenuItem->Name = L"mainFormToolStripMenuItem";
			this->mainFormToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->mainFormToolStripMenuItem->Text = L"Settings";
			this->mainFormToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mainFormToolStripMenuItem_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->infoToolStripMenuItem->Text = L"Info";
			this->infoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::infoToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// form3OpenDialog
			// 
			this->form3OpenDialog->FileName = L"Open a file";
			this->form3OpenDialog->Filter = L"TST files|*.TST";
			// 
			// saveFormDialog
			// 
			this->saveFormDialog->Filter = L"fsv files|*.fsv";
			// 
			// openFormDialog
			// 
			this->openFormDialog->FileName = L"Open a file";
			this->openFormDialog->Filter = L"fsv files|*.fsv";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(719, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(301, 68);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// form5OpenDialog
			// 
			this->form5OpenDialog->FileName = L"Open a file";
			this->form5OpenDialog->Filter = L"TST files|*.TST";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1027, 715);
			this->Controls->Add(this->Form2Progress);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->reportViewer1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form1DataBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Farm_Stray_Voltage_Data))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form2DataBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form3DataBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form5DataBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form6DataBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RecordsBindingSource))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage14->ResumeLayout(false);
			this->groupBox26->ResumeLayout(false);
			this->groupBox26->PerformLayout();
			this->groupBox23->ResumeLayout(false);
			this->groupBox23->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox22->ResumeLayout(false);
			this->groupBox22->PerformLayout();
			this->groupBox21->ResumeLayout(false);
			this->groupBox21->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->groupBox25->ResumeLayout(false);
			this->groupBox25->PerformLayout();
			this->groupBox24->ResumeLayout(false);
			this->groupBox24->PerformLayout();
			this->groupBox19->ResumeLayout(false);
			this->groupBox19->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->form1Grid))->EndInit();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox18->ResumeLayout(false);
			this->groupBox18->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox17->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->groupBox16->ResumeLayout(false);
			this->groupBox16->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabPage9->ResumeLayout(false);
			this->tabPage9->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tabPage10->ResumeLayout(false);
			this->tabControl4->ResumeLayout(false);
			this->tabPage11->ResumeLayout(false);
			this->tabPage11->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabPage12->ResumeLayout(false);
			this->tabPage12->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			this->groupBox13->ResumeLayout(false);
			this->groupBox13->PerformLayout();
			this->groupBox14->ResumeLayout(false);
			this->groupBox14->PerformLayout();
			this->groupBox15->ResumeLayout(false);
			this->groupBox15->PerformLayout();
			this->tabPage13->ResumeLayout(false);
			this->tabPage13->PerformLayout();
			this->groupBox20->ResumeLayout(false);
			this->groupBox20->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: InsideBarn2::DrawingSpace^ barn;	
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			{
			barnDiagram = "";
			barn = gcnew InsideBarn2::DrawingSpace();
			barn->FormClosing += gcnew FormClosingEventHandler (this, &Form1::DiagramClosing);
			this->Farm_Stray_Voltage_Data->Form_1_Data->TableNewRow += gcnew DataTableNewRowEventHandler (this, &Form1::F1NewRow);
			YData = gcnew array<float>(10);
			YData5 = gcnew array<float>(10);
			form2FileName = "";form3FileName = "";form5FileName = "";form6FileName = "";
			entered = false;
			DataRow^ r1 = this->Farm_Stray_Voltage_Data->Form_1_Data->NewRow();
			r1["locid"] = 1;
			this->Farm_Stray_Voltage_Data->Form_1_Data->Rows->Add (r1);
			graphs = gcnew array<VoltGraph^>(2);
			openedFile = false;
			graphs[0] = gcnew VoltGraph(0);
			graphs[1] = gcnew VoltGraph(1);
			form3Date = ""; form5Date = "";
			this->Resize += gcnew EventHandler (this, &Form1::Form1_Resize);
			for (int a=1; a<6; a++)
			{
				DataRow^ r = this->Farm_Stray_Voltage_Data->Form_3_Data->NewRow();
				DataRow^ r2 = this->Farm_Stray_Voltage_Data->Form_5_Data->NewRow();
				r["step"] = a;
				r2["step"] = a;
				this->Farm_Stray_Voltage_Data->Form_3_Data->Rows->Add(r);
				this->Farm_Stray_Voltage_Data->Form_5_Data->Rows->Add(r2);
			}
			cal1 = 1; cal2=1;cal3=1;cal4=1;cal5=1;
			richTextBox8->Select(3,4);
			richTextBox8->SelectionCharOffset = -4;
			richTextBox8->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox26->Select(3,4);
			richTextBox26->SelectionCharOffset = -4;
			richTextBox26->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox9->Select(2,4);
			richTextBox9->SelectionCharOffset = -4;
			richTextBox9->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox27->Select(2,4);
			richTextBox27->SelectionCharOffset = -4;
			richTextBox27->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox11->Select(3,4);
			richTextBox11->SelectionCharOffset = -4;
			richTextBox11->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox24->Select(3,4);
			richTextBox24->SelectionCharOffset = -4;
			richTextBox24->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox12->Select(2,4);
			richTextBox12->SelectionCharOffset = -4;
			richTextBox12->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox25->Select(2,4);
			richTextBox25->SelectionCharOffset = -4;
			richTextBox25->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox14->Select(3,5);
			richTextBox14->SelectionCharOffset = -4;
			richTextBox14->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox16->Select(3,5);
			richTextBox16->SelectionCharOffset = -4;
			richTextBox16->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox15->Select(2,5);
			richTextBox15->SelectionCharOffset = -4;
			richTextBox15->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox834->Select(2,5);
			richTextBox834->SelectionCharOffset = -4;
			richTextBox834->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox17->Select(3,5);
			richTextBox17->SelectionCharOffset = -4;
			richTextBox17->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox10->Select(3,5);
			richTextBox10->SelectionCharOffset = -4;
			richTextBox10->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox18->Select(2,5);
			richTextBox18->SelectionCharOffset = -4;
			richTextBox18->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox13->Select(2,5);
			richTextBox13->SelectionCharOffset = -4;
			richTextBox13->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox3->Select(19,2);
			richTextBox3->SelectionCharOffset = -4;
			richTextBox3->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox21->Select(19,2);
			richTextBox21->SelectionCharOffset = -4;
			richTextBox21->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox4->Select(19,2);
			richTextBox4->SelectionCharOffset = -4;
			richTextBox4->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox22->Select(19,2);
			richTextBox22->SelectionCharOffset = -4;
			richTextBox22->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			richTextBox2->Select(43,3);
			richTextBox2->SelectionCharOffset = -4;
			richTextBox2->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox20->Select(43,3);
			richTextBox20->SelectionCharOffset = -4;
			richTextBox20->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			
			richTextBox5->Select(30,1);
			richTextBox5->SelectionCharOffset = -4;
			richTextBox5->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);
			richTextBox23->Select(30,1);
			richTextBox23->SelectionCharOffset = -4;
			richTextBox23->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

			this->Text = "Untitled.fsv";
			this->reportViewer1->RefreshReport();
			addListeners (this);
			
			if (Environment::GetCommandLineArgs()->Length > 1)
			{
				Form1::openAForm (Environment::GetCommandLineArgs()[1]);
				openedFile = true;
			}
		}
		private: System::Void initializeTable(String^ filename, int form)
		{
			array<DataTable^>^ forms = gcnew array <DataTable^>{this->Farm_Stray_Voltage_Data->Form_2_Data,this->Farm_Stray_Voltage_Data->Form_6_Data};
			forms[form]->Clear();
			DateTime highTime; //Time of record with highest vcc
			UInt16 i1, i2, i3, i4; //The four channels of current and Channel 4 V
			float vcc, vp, vs, vps; //The four voltage readings
			float highVcc=-1; //Used to keep track of the highest animal contact voltage
			float highVp,highVs,highVps;
			int tenSeconds = 0, secs=0; //Number of ten second intervals gone through, and time spent over threshold
			int total =0;
			//Will read in the header and save it to settings
			Settings^ settings = gcnew Settings(filename);
			if (settings->rightLogger == false)
			{
				MessageBox::Show ("Incorrect logger format");
				return;
			}
			numRecord = settings->numRecord;
			this->Form2Progress->Maximum = numRecord;
			this->Form2Progress->Visible = true;
			this->Form2Progress->Value = 0;
			array <float>^ graph1, ^graph2, ^graph3, ^graph4;
			
			this->Focus();
			this->BringToFront();
			this->Refresh();

			graph1 = gcnew array<float>(numRecord);graph2 = gcnew array<float>(numRecord);graph3 = gcnew array<float>(numRecord);graph4 = gcnew array<float>(numRecord);
			graphDataX = gcnew array<double>(numRecord);
			//The logger start time 
			DateTime start (settings->start);
			
			if (settings->interval > 10)
				MessageBox::Show ("Warning: The measurement interval exceeds the maximum of 10 seconds.");

			//Array of bytes, equal to one record
			array<Byte>^ record1 = gcnew array<Byte>(56);
			
			//Initializing variables
			int b;
			BinaryReader^ binReader = gcnew BinaryReader( File::Open( filename, FileMode::Open));
			
			//Reading in the header (But doing nothing)
			//NOTE: Just seek
			binReader->BaseStream->Seek(256, SeekOrigin::Begin);
			//for (int a=0; a<256; a++)
			//	binReader->ReadByte();
			//Populating the table in Form 2 & 5
			for (b = 1; b <= numRecord/(3600/settings->interval) + 1; b++)
			{
				//360 ten second intervals in an hour
				while (tenSeconds < 3600 && total < numRecord)
				{					
					//NOTE: file seek will be more efficient than reading 3181 bytes every time
					//for (int i=0; i<3181; i++)
					//	record1[i]=binReader->ReadByte();
					//binReader->BaseStream->Seek(3181, SeekOrigin::Current);
					//Reads in the raw (uncalibrated) channel 4 current value 
					binReader->BaseStream->Seek(53, SeekOrigin::Current);
					binReader->BaseStream->Read(record1, 0, 56);
					binReader->BaseStream->Seek (3072, SeekOrigin::Current);
					this->Form2Progress->PerformStep();
					if (channel4I->Checked)
					{
						i4 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[55],record1[54]},0);
						vcc = getCurrent(i4, settings, 4)*cal4;
					}
					else
					{
						i4 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[42],record1[41]},0);
						vcc = getCurrent(i4, settings, 5)*cal5;
					}
					//If the animal contact voltage is over the threshold, add 10 seconds to the exceed time
					if (vcc > 1)
						secs = secs+settings->interval;
					//Read in and calibrate all of the current data, and change to voltage by multiplying by its calibration
					i1 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[1],record1[0]},0);
					vp = getCurrent (i1, settings, 1)*cal1;
					i2 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[19],record1[18]},0);
					vps = getCurrent (i2, settings, 2)*cal2;
					i3 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[37],record1[36]},0);
					vs = getCurrent (i3, settings, 3)*cal3;

					//If the current is higher than the highest this hour
					if (vcc > highVcc)
					{												
						highVcc = vcc; //Set the highest voltage to the new highest
						highVp = vp;
						highVps = vps;
						highVs = vs;
						//Set the time to the time of this record
						highTime = start;
					}
					//After each record is read, add seconds to the time

					graph1[total] = vcc;
					graph2[total] = vp;
					graph3[total] = vs;
					graph4[total] = vps;
					graphDataX[total] = (start - DateTime(1899,12,30)).TotalDays;
					tenSeconds = tenSeconds + settings->interval;
					start = start.AddSeconds(settings->interval);	
					total++;
				}
				//Reset the tenSeconds for a new hour
				tenSeconds=0;
				//Adding all the data to the table
					DataRow^ row = forms[form]->NewRow();
					row["hour"] = b;
					row["highestVcc"] = highTime.TimeOfDay;
					row["aContactVolt"] = highVcc;
					if (highVcc > highestVcc && form == 0)
					{
						highestVcc = highVcc;
						highestP2RV = highVp;
					}
					highVcc = -1;
				
					row["pN2RVolt"] = highVp;
					row["sN2RVolt"] = highVs;
					row["pN2SNVolt"] = highVps;
				
					//Making the timespan to calculate the exceed time
					//NOTE: This seems like a stupid way of doing it
					DateTime before = DateTime::Now;
					DateTime now = before.AddSeconds(secs);
					TimeSpan exceedTime = now - before;
					secs=0;
					row["timeVccExceeds"] =exceedTime.FromMinutes(exceedTime.TotalMinutes );
					forms[form]->Rows->Add(row);
			}	
			binReader->Close();
			this->Form2Progress->Visible = false;
			if (settings->interval * settings->numRecord <  172800  && openedFile == false)
			{
				MessageBox::Show("Test duration does not meet the 48 hour minimum!");
				if (form == 0)
				{
					highestVcc = 0;
					highestP2RV = 0;
				}
			}
			if (form ==0)
			{
				this->form2StartText->Text = settings->start.ToString("yyyy/MM/dd HH:mm:ss");
				this->form2StopText->Text = settings->end.ToString("yyyy/MM/dd HH:mm:ss");
				graphVcc = graph1;graphVp=graph2;graphVs=graph3;graphVps=graph4;
			}
			else
			{
				this->form6Start->Text = settings->start.ToString("yyyy/MM/dd HH:mm:ss");
				this->form6Stop->Text = settings->end.ToString("yyyy/MM/dd HH:mm:ss");
				graphVcc6=graph1;graphVp6=graph2;graphVs6=graph3;graphVps6=graph4;
			}

			if (this->Farm_Stray_Voltage_Data->Form_2_Data->Rows->Count >= 48 && form == 0)
			{
				this->vccfsv->Text = String::Concat(Convert::ToString(Math::Round(highestVcc,2))," V");
				this->vpfsv->Text = String::Concat(Convert::ToString(Math::Round(highestP2RV,2))," V");
			}

			this->vccfsv5->Text = String::Concat(Convert::ToString(Math::Round(highestVcc,2))," V");
			this->vpfsv5->Text = String::Concat(Convert::ToString(Math::Round(highestP2RV,2))," V");

			int m =0;

				if (form == 0)
				{
					graphDataY = gcnew array<float>(numRecord*4);
					graphDataX2 = gcnew array<double>(numRecord*4);
					for (m; m<numRecord; m++){graphDataY[m] = graphVcc[m];graphDataX2[m] = graphDataX[m];}
					for (m; m<numRecord*2; m++){graphDataY[m] = graphVp[m-numRecord];graphDataX2[m] = graphDataX[m-numRecord];}
					for	(m; m<numRecord*3; m++){graphDataY[m] = graphVs[m-numRecord*2];graphDataX2[m] = graphDataX[m-numRecord*2];}
					for (m; m<numRecord*4; m++){graphDataY[m] = graphVps[m-numRecord*3];graphDataX2[m] = graphDataX[m-numRecord*3];}
				}
				else if (form == 1)
				{
					graphDataY6 = gcnew array<float>(numRecord*4);
					graphDataX26 = gcnew array<double>(numRecord*4);
					for (m; m<numRecord; m++){graphDataY6[m] = graphVcc6[m];graphDataX26[m] = graphDataX[m];}
					for (m; m<numRecord*2; m++){graphDataY6[m] = graphVp6[m-numRecord];graphDataX26[m] = graphDataX[m-numRecord];}
					for (m; m<numRecord*3; m++){graphDataY6[m] = graphVs6[m-numRecord*2];graphDataX26[m] = graphDataX[m-numRecord*2];}
					for (m; m<numRecord*4; m++){graphDataY6[m] = graphVps6[m-numRecord*3];graphDataX26[m] = graphDataX[m-numRecord*3];}
				}
				graphs[form] = gcnew VoltGraph(form);
				graphs[form]->SetBounds(0, 0, 701, 348);
				graphs[form]->SetNumRecord(numRecord);
				graphs[form]->pesgo1->PeData->Subsets = 4;
				graphs[form]->pesgo1->PeData->DateTimeMode = true; //So X Axis will have times
				graphs[form]->pesgo1->PeData->UsingXDataii = true; //Using double precision XDataii
				graphs[form]->pesgo1->PeString->XAxisLabel = "Time"; //Name of the X-Axis
				graphs[form]->pesgo1->PeString->YAxisLabel = "Voltage"; //Name of the Y-Axis
				graphs[form]->pesgo1->PeString->SubsetLabels[0] = ("Vcc"); //Name of the 1st subset
				graphs[form]->pesgo1->PeString->SubsetLabels[1] = ("Vp"); //Name of the 2nd subset
				graphs[form]->pesgo1->PeString->SubsetLabels[2] = ("Vs"); //Name of the 3rd subset
				graphs[form]->pesgo1->PeString->SubsetLabels[3] = ("Vps"); //Name of the 4th subset
				graphs[form]->pesgo1->PeString->MainTitle = "Farm Stray Voltage Test"; //Name of the graph
	
				//Shows the user where the cursor is
				graphs[form]->pesgo1->PeUserInterface->Cursor->PromptTracking = true;
				graphs[form]->pesgo1->PeUserInterface->Cursor->PromptStyle = Gigasoft::ProEssentials::Enums::CursorPromptStyle::XYValues;
				graphs[form]->pesgo1->PeUserInterface->Cursor->PromptLocation = Gigasoft::ProEssentials::Enums::CursorPromptLocation::Left;

				if (form == 0)
					graphs[0]->DrawGraph(graphDataX2,graphDataY);
				else
					graphs[1]->DrawGraph(graphDataX26,graphDataY6);
				
				graphs[form]->pesgo1->PeFunction->ResetImage(graphs[form]->Width,graphs[form]->Height);

				graphs[form]->saveBitmap(this->Width,this->Height);
				
		}
		//Will take in the raw current data and return calibrated actual current
		private: float getCurrent (UInt16 i, Settings^ settings, int mode)
		{
			//Array of calibration factors according to channel
			array<Int16>^ cal = gcnew array<Int16>{settings->iCal1,settings->iCal2,settings->iCal3};
			float fi1;
			
			if (mode == 5)
			{
				if (i%16 != 0)
					i = i - i % 16;
				else
					i = i / 16;
				fi1 = i;
			}

			else
			{
				//Remove the first half byte
				if (i >= 4096)
				{
				//int imod = i;
				//while (imod >16)
				//	imod = (imod - (imod%16))/16;
				//while (imod * 16 < i)
				//	imod = imod * 16;
				//fi1 = i - imod; 
					fi1 = i % 4096;
				}

				else 
					fi1 = i;
			}

			//If it is neutral current, use the neutral settings
			if (mode == 5)
				fi1 = fi1 * 0.2 * (settings->vNDecScale + settings->vCal4)/settings->vNBinScale/10;
			else if (mode == 4)
				fi1 = fi1 * 2 * (settings->iNDecScale + settings->iCal4)/settings->iNBinScale * settings->c2pN/settings->c2sN/1000;
			else
				fi1 = fi1 * (settings->iDecScale + cal[mode-1])/settings->iBinScale * settings->c2p/settings->c2s/1000;

			return fi1;
			}
		//If the user clicks on the enter data button
		private: System::Void enterData_Click (Object ^ sender, System::EventArgs^ e)
		{	
			ds = gcnew Stray_Voltage_Report_Writer::Farm_Stray_Voltage_Data();
			array<TextBox^>^ vccA = gcnew array<TextBox^>{vcc1,vcc2,vcc3,vcc4,vcc5,vcc11,vcc6,vcc7,vcc8,vcc9,vcc10,vcc12};
			array<TextBox^>^ vpA = gcnew array<TextBox^>{vp1,vp2,vp3,vp4,vp5,vp11,vp6,vp7,vp8,vp9,vp10,vp12};
			array<TextBox^>^ vsA = gcnew array<TextBox^>{vs1,vs2,vs3,vs4,vs5,vs11,vs6,vs7,vs8,vs9,vs10,vs12};
			array<TextBox^>^ vpsA = gcnew array<TextBox^>{vps1,vps2,vps3,vps4,vps5,vps11,vps6,vps7,vps8,vps9,vps10,vps12};
			array<MaskedTextBox^>^ timeA = gcnew array<MaskedTextBox^>{time1,time2,time3,time4,time5,time11,time6,time7,time8,time9,time10,time12};
			int howMany=0; //How many tests were run
			int offset = 0; //Iterator start point for running though arrays
			if (sender == enterData5)
				offset = 6;
			else
				this->Farm_Stray_Voltage_Data->Form_3_Data->Clear();
			int numStep = 5;
			if (this->step2Radio->Checked)
				numStep = 6;
			int initReturn;
			//Creates the rows for Form_3_Data table if they don't exist
			ds->Clear();
			for (int a=1; a<numStep+1; a++)
			{
				DataRow^ roe = ds->Form_3_Data ->NewRow();
				roe["step"] = a;
				roe["time"] = DateTime::Now;
				ds->Form_3_Data->Rows->Add(roe);
			}
			//If file input
			if (this->fileRadio->Checked)
			{
				for (int a=offset; a<numStep+offset; a++)
					if (timeA[a]->Text != "  :") //If there is a value in the time box
					{
						if (DateTime::TryParse(timeA[a]->Text,%ds->Form_3_Data[a-offset]->time))//If the value is a valid time
						{
							ds->Form_3_Data[a-offset]->time = Convert::ToDateTime(timeA[a]->Text);
							//If there is enough time between intervals for a 2-minute test
							if (a==offset||Math::Abs((ds->Form_3_Data[a-offset]->time - ds->Form_3_Data[a-offset-1]->time).TotalMinutes) >= 2)
							{
								if (offset==0)
									initReturn = initializeTable(this->form3OpenDialog->FileName, 2, ds->Form_3_Data[a-offset]->time, a-offset+1);
								else
									initReturn = initializeTable(this->form5OpenDialog->FileName, 2, ds->Form_3_Data[a-offset]->time, a-offset+1);
								if (initReturn != 1)//If initializeTable didn't return 1 (error)
								{
									//Filling in the text boxes of Form 3 with data received from database
									vccA[a]->Text = ds->Form_3_Data[a-offset]->vcc.ToString("#0.00");
									vpA[a]->Text = ds->Form_3_Data[a-offset]->vp.ToString("#0.00");
									vsA[a]->Text = ds->Form_3_Data[a-offset]->vs.ToString("#0.00");
									vpsA[a]->Text = ds->Form_3_Data[a-offset]->vps.ToString("#0.00");
									howMany++;
								}
							}
							//Error messages
							else
							{
								MessageBox::Show (String::Concat("Steps must be taken in intervals of at least 2 minutes\n\nAt time: ",ds->Form_3_Data[a-offset]->time.ToString("HH:mm")),"Error!");
								return;
							}							
						}
						else
						{
							MessageBox::Show (String::Concat("Time input not in correct format in Step ",(a+1).ToString()),"Error!");
							return;
						}
					}
			}
			else
			{
			//Enters all the text from the text boxes into the DataTable "form3Data"
			for (int i=0; i<5; i++)
				if (vccA[i]->Text != "" && vpA[i]->Text != "" && vsA[i]->Text != "" && vpsA[i]->Text != "")
				{
					ds->Form_3_Data[i]->vcc = Convert::ToSingle(vccA[i]->Text);
					ds->Form_3_Data[i]->vp = Convert::ToSingle(vpA[i]->Text);
					ds->Form_3_Data[i]->vs = Convert::ToSingle(vsA[i]->Text);
					ds->Form_3_Data[i]->vps = Convert::ToSingle(vpsA[i]->Text);
					if (timeA[i]->Text != ("  :"))
						if (DateTime::TryParse(timeA[i]->Text,%ds->Form_3_Data[i]->time)){}
						else
							MessageBox::Show ("Time not input in correct format");						
				}	
			}
			if (offset==0)
				vccd3Phase->Text = vcc2->Text;
			else if (offset > 0)
				vccd3Phase5->Text = vcc7->Text;;

			ds->Form_3_Data->WriteXml(filePath + "form3.xml");

			if (sender == enterData)
			{
				this->Farm_Stray_Voltage_Data->Form_3_Data->ReadXml(filePath + "form3.xml");
				this->form4Fill(0);
			}
			else
			{
				for (int a=0; a<howMany; a++)
				{
					if (!ds->Form_3_Data [a]->IsvccNull())this->Farm_Stray_Voltage_Data->Form_5_Data[a]->vcc = ds->Form_3_Data [a]->vcc;
					if (!ds->Form_3_Data [a]->IsvpNull())this->Farm_Stray_Voltage_Data->Form_5_Data[a]->vp = ds->Form_3_Data [a]->vp;
					if (!ds->Form_3_Data [a]->IsvsNull())this->Farm_Stray_Voltage_Data->Form_5_Data[a]->vs = ds->Form_3_Data [a]->vs;
					if (!ds->Form_3_Data [a]->IsvpsNull())this->Farm_Stray_Voltage_Data->Form_5_Data[a]->vps = ds->Form_3_Data [a]->vps;
					if (!ds->Form_3_Data [a]->IstimeNull())this->Farm_Stray_Voltage_Data->Form_5_Data[a]->time = ds->Form_3_Data [a]->time;
				}
				this->form4Fill(1);
			}
			
		}
		//If the user clicks the clear data button
		private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if(sender == this->clearButton)
				this->clearTables(0);
			else
				this->clearTables(1);
		}
		//If the user clicked on any "open file" button
		private: System::Void openButt_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//If the openFileDialog chose a file
			if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//If the user clicked on the Form 2 open button
				if (sender == openButt)
				{
					//Clear existing data in Form 2, and refill it with data from file
					this->Farm_Stray_Voltage_Data->Form_2_Data->Clear();
					annoteX2 = gcnew array<double>(10);
					tipX2 = gcnew array<Point^>(10);
					initializeTable(this->openFileDialog1->FileName,0);
					if (this->Farm_Stray_Voltage_Data->Form_2_Data->Rows->Count > 0)
					{
						form4Fill (0);
						form4Fill (1);
						form2FileText->Text = (this->openFileDialog1->SafeFileName);
						form2FileName = openFileDialog1->FileName;
						form2FileText->ForeColor = Color::Blue;
						viewGraph->Enabled = true;
					}
				}
				
				//If the user clicked on the open button in Form 6
				else if (sender == this->form6Open && openFileDialog1->SafeFileName != form2FileText->Text)
				{
					this->Farm_Stray_Voltage_Data->Form_6_Data->Clear();
					initializeTable(this->openFileDialog1->FileName,1);
					if (this->Farm_Stray_Voltage_Data->Form_6_Data->Rows->Count > 0)
					{
						this->form6FileText->Text = this->openFileDialog1->SafeFileName;
						form6FileText->ForeColor = Color::Blue;
						form6FileName = openFileDialog1->FileName;
						form4Fill(1);
						button1->Enabled = true;
					}
				}
				else if (sender == this->form6Open)
					MessageBox::Show ("You must select a file different than Form 2's input file","Duplicate File!");
			}
		}
		private: System::Void form3Open_Click (System::Object^ sender, System::EventArgs^ e)
		{
 			//If the user clicked on the Form 3 open button
			if (sender == form3Open)
			{
				if (form3OpenDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					Settings^ settings = gcnew Settings(this->form3OpenDialog->FileName);
					if (settings->rightLogger == false)
					{
						MessageBox::Show ("Incorrect logger format");
						return;
					}
					YData[0] = 10101986;
					time1->ReadOnly = false;time2->ReadOnly = false;time3->ReadOnly = false;time4->ReadOnly = false;time5->ReadOnly = false;time11->ReadOnly = false;
					time1->BackColor = Color::White;time2->BackColor = Color::White;time3->BackColor = Color::White;time4->BackColor = Color::White;time5->BackColor = Color::White;time11->BackColor = Color::White;
					form3File->Text = form3OpenDialog->SafeFileName;
					form3FileName = form3OpenDialog->FileName;
					form3File->ForeColor = Color::Blue;
					this->clearTables(0);
					this->enterData->Enabled = true;
					form3Date = settings->start.ToString(("yyyy/MM/dd HH:mm"));
					form3StartTime->Text = settings->start.ToString("yyyy/MM/dd HH:mm:ss");
					form3StopTime->Text = settings->end.ToString("yyyy/MM/dd HH:mm:ss");
					form3Start->Visible = true;
					form3Stop->Visible = true;
					F3Graph->Enabled = true;
					this->form3StartTime->Visible = true;
					this->form3StopTime->Visible = true;
				}
			}
			else if (sender == form5Open)				
			{
				if (form5OpenDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					if (form5OpenDialog->SafeFileName != form3OpenDialog->SafeFileName)
					{
						Settings^ settings = gcnew Settings(form5OpenDialog->FileName);
						if (settings->rightLogger == false)
						{
							MessageBox::Show ("Incorrect logger format");
							return;
						}
						form5Date = settings->start.ToString(("yyyy/MM/dd HH:mm"));
						form5StartTime->Text = settings->start.ToString("yyyy/MM/dd HH:mm");
						form5StopTime->Text = settings->end.ToString("yyyy/MM/dd HH:mm");
						YData5[0] = 10101986;
						form5Start->Visible = true;
						this->form5Stop->Visible = true;
						this->form5StartTime->Visible = true;
						F5Graph->Enabled = true;
						this->form5StopTime->Visible = true;
						time6->ReadOnly = false;time7->ReadOnly = false;time8->ReadOnly = false;time9->ReadOnly = false;time10->ReadOnly = false;time12->ReadOnly = false;
						time6->BackColor = Color::White;time7->BackColor = Color::White;time8->BackColor = Color::White;time9->BackColor = Color::White;time10->BackColor = Color::White;time12->BackColor = Color::White;
						form5File->Text = form5OpenDialog->SafeFileName;
						form5FileName = form5OpenDialog->FileName;
						form5File->ForeColor = Color::Blue;
						this->clearTables(1);	
						this->enterData5->Enabled = true;
					}
					else 
						MessageBox::Show ("You must select a file different than Form 3's input file","Duplicate File!");
			}
		}
		//Will write to file in specified format
		private: System::Void saveToFile (String^ filename)
		{
			StreamWriter^ sw = gcnew StreamWriter(filename);
			//Written to file will be all the variables needed, and then the xml file of the database

			sw->WriteLine (utilName->Text);
			sw->WriteLine (utilAddress1->Text);
			sw->WriteLine (utilAddress2->Text);
			sw->WriteLine (utilPhone->Text);
			sw->WriteLine (utilEmail->Text);
			sw->WriteLine (utilWebsite->Text);

			sw->WriteLine (investName->Text);
			sw->WriteLine (investPhone->Text);
			sw->WriteLine (investEmail->Text);
			sw->WriteLine (fileNumber->Text);
			sw->WriteLine (investReceive->Text);
			sw->WriteLine (investVisit->Text);
			sw->WriteLine (investStart->Text);
			sw->WriteLine (investConclude->Text);

			sw->WriteLine (custName->Text);
			sw->WriteLine (custAddress1->Text);
			sw->WriteLine (custAddress2->Text);
			sw->WriteLine (custPhone->Text);
			sw->WriteLine (custEmail->Text);

			sw->WriteLine (farmName->Text);
			sw->WriteLine (farmAddress1->Text);
			sw->WriteLine (farmAddress2->Text);
			sw->WriteLine (farmPhone->Text);
			sw->WriteLine (farmEmail->Text);

			sw->WriteLine (reportSummary->Lines->Length);
			if (reportSummary->Lines->Length >0)
				sw->WriteLine (reportSummary->Text);

			sw->WriteLine(form1DateText->Text);
			sw->WriteLine(this->form2StartText->Text);
			sw->WriteLine(this->form2StopText->Text);
			sw->WriteLine(this->form3Date);
			sw->WriteLine(this->form5Date);
			sw->WriteLine(this->form6Start->Text);
			sw->WriteLine(this->form6Stop->Text);
			sw->WriteLine(this->locCombo->Text);
			sw->WriteLine(this->locCombo6->Text);
			sw->WriteLine(this->vpri->Text);
			sw->WriteLine(this->ilbh->Text);
			sw->WriteLine(this->ilbf->Text);
			sw->WriteLine(this->vlbh->Text);
			sw->WriteLine(this->vlbf->Text);
			sw->WriteLine(this->ip->Text);
			sw->WriteLine(this->textBox11->Text);
			sw->WriteLine(this->textBox12->Text);
			sw->WriteLine(this->textBox14->Text);
			sw->WriteLine(this->textBox13->Text);
			sw->WriteLine(this->textBox17->Text);
			sw->WriteLine(this->textBox18->Text);
			sw->WriteLine(this->highestP2RV);
			sw->WriteLine(this->highestVcc);
			sw->WriteLine(this->form2FileText->Text);
			sw->WriteLine (form2FileName);
			sw->WriteLine(this->form3File->Text);
			sw->WriteLine (form3FileName);
			sw->WriteLine(this->form5File->Text);
			sw->WriteLine (form5FileName);
			sw->WriteLine(this->form6FileText->Text);
			sw->WriteLine (form6FileName);

			if (diagramText == "")
				sw->WriteLine("no_diagram");
			else
				sw->Write(String::Concat("diagram",System::Environment::NewLine,diagramText));
			if (barnDiagram == "")
				sw->WriteLine ("no_diagram");
			else
				sw->Write (String::Concat("diagram",System::Environment::NewLine,barnDiagram));
			sw->WriteLine(cal1);sw->WriteLine(cal2);sw->WriteLine(cal3);sw->WriteLine(cal4);
			sw->WriteLine(this->time1->Text);sw->WriteLine(this->vcc1->Text);sw->WriteLine(this->vp1->Text);sw->WriteLine(this->vs1->Text);sw->WriteLine(this->vps1->Text);
			sw->WriteLine(this->time2->Text);sw->WriteLine(this->vcc2->Text);sw->WriteLine(this->vp2->Text);sw->WriteLine(this->vs2->Text);sw->WriteLine(this->vps2->Text);
			sw->WriteLine(this->time3->Text);sw->WriteLine(this->vcc3->Text);sw->WriteLine(this->vp3->Text);sw->WriteLine(this->vs3->Text);sw->WriteLine(this->vps3->Text);
			sw->WriteLine(this->time4->Text);sw->WriteLine(this->vcc4->Text);sw->WriteLine(this->vp4->Text);sw->WriteLine(this->vs4->Text);sw->WriteLine(this->vps4->Text);
			sw->WriteLine(this->time5->Text);sw->WriteLine(this->vcc5->Text);sw->WriteLine(this->vp5->Text);sw->WriteLine(this->vs5->Text);sw->WriteLine(this->vps5->Text);

			sw->WriteLine(this->time6->Text);sw->WriteLine(this->vcc6->Text);sw->WriteLine(this->vp6->Text);sw->WriteLine(this->vs6->Text);sw->WriteLine(this->vps6->Text);
			sw->WriteLine(this->time7->Text);sw->WriteLine(this->vcc7->Text);sw->WriteLine(this->vp7->Text);sw->WriteLine(this->vs7->Text);sw->WriteLine(this->vps7->Text);
			sw->WriteLine(this->time8->Text);sw->WriteLine(this->vcc8->Text);sw->WriteLine(this->vp8->Text);sw->WriteLine(this->vs8->Text);sw->WriteLine(this->vps8->Text);
			sw->WriteLine(this->time9->Text);sw->WriteLine(this->vcc9->Text);sw->WriteLine(this->vp9->Text);sw->WriteLine(this->vs9->Text);sw->WriteLine(this->vps9->Text);
			sw->WriteLine(this->time10->Text);sw->WriteLine(this->vcc10->Text);sw->WriteLine(this->vp10->Text);sw->WriteLine(this->vs10->Text);sw->WriteLine(this->vps10->Text);

			this->Farm_Stray_Voltage_Data->WriteXml(sw);
			sw->Close();
		}
		//If the user chose "Save Forms" in the menu strip, run saveToFile function
		private: System::Void saveFormsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{	
			if (saveFormDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				saveToFile(saveFormDialog->FileName);
				this->Text = saveFormDialog->FileName->Substring(saveFormDialog->FileName->LastIndexOf('\\')+1);
			}
				
		}
		//Will read in the forms from file
		private: System::Void openExistingFormsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (openFormDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				openAForm(openFormDialog->FileName);
		}
		private: System::Void textBox_KeyDown( Object^ sender, System::Windows::Forms::KeyEventArgs^ e )
			{
				TextBox^ eieio = (TextBox^)sender;
			// Initialize the flag to false.
			nonNumberEntered = false;

			if ((e->KeyCode == Keys::OemPeriod || e->KeyCode == Keys::Decimal) && eieio->Text->Contains("."))
				nonNumberEntered = true;
			// Determine whether the keystroke is a number from the top of the keyboard.
			if ( e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9 )
			{
				// Determine whether the keystroke is a number from the keypad.
				if ( e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9 )
				{
					// Determine whether the keystroke is a backspace or period
					if ( e->KeyCode != Keys::Back && e->KeyCode != Keys::Decimal && e->KeyCode != Keys::OemPeriod)
					{
						// A non-numerical keystroke was pressed.
						// Set the flag to true and evaluate in KeyPress event.
						nonNumberEntered = true;
					}
				}
			}
			//If shift key was pressed, it's not a number.
			if (Control::ModifierKeys == Keys::Shift) 
			{
				nonNumberEntered = true;
			}
	    }

		private: System::Void textBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		{
			// Check for the flag being set in the KeyDown event.
			if ( nonNumberEntered == true )
			{
				// Stop the character from being entered into the control since it is non-numerical.
				e->Handled = true;
			}

		}
		//Called when there is incorrect input into any DataGridView
		private: System::Void dataError (Object ^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e)
		{
			MessageBox::Show ("Data input not in correct format");
		}
		//If the user changes the checked state of the user/file input radio buttons on Form 3
		private: System::Void userRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (userRadio->Checked)
			{
				//If the user chose "user input" enable all text boxes
				vcc1->ReadOnly = false; vcc1->BackColor = Color::White;vcc2->ReadOnly = false; vcc2->BackColor = Color::White;vcc3->ReadOnly = false; vcc3->BackColor = Color::White;vcc4->ReadOnly = false; vcc4->BackColor = Color::White;vcc5->ReadOnly = false; vcc5->BackColor = Color::White;vcc11->ReadOnly = false; vcc11->BackColor = Color::White;
				vp1->ReadOnly = false; vp1->BackColor = Color::White;vp2->ReadOnly = false; vp2->BackColor = Color::White;vp3->ReadOnly = false; vp3->BackColor = Color::White;vp4->ReadOnly = false; vp4->BackColor = Color::White;vp5->ReadOnly = false; vp5->BackColor = Color::White;vp11->ReadOnly = false; vp11->BackColor = Color::White;
				vs1->ReadOnly = false; vs1->BackColor = Color::White;vs2->ReadOnly = false; vs2->BackColor = Color::White;vs3->ReadOnly = false; vs3->BackColor = Color::White;vs4->ReadOnly = false; vs4->BackColor = Color::White;vs5->ReadOnly = false; vs5->BackColor = Color::White;vs11->ReadOnly = false; vs11->BackColor = Color::White;
				vps1->ReadOnly = false; vps1->BackColor = Color::White;vps2->ReadOnly = false; vps2->BackColor = Color::White;vps3->ReadOnly = false; vps3->BackColor = Color::White;vps4->ReadOnly = false; vps4->BackColor = Color::White;vps5->ReadOnly = false; vps5->BackColor = Color::White;vps11->ReadOnly = false; vps11->BackColor = Color::White;
				time1->ReadOnly = false; time1->BackColor = Color::White;time2->ReadOnly = false; time2->BackColor = Color::White;time3->ReadOnly = false; time3->BackColor = Color::White;time4->ReadOnly = false; time4->BackColor = Color::White;time5->ReadOnly = false; time5->BackColor = Color::White;time11->ReadOnly = false; time11->BackColor = Color::White;
				form3Open->Visible = false;	
				form3File->Visible = false;
				form3File->Text = "Please open a file...";
				this->F3Graph->Visible = false;
				F3Graph->Enabled = false;
				this->enterData->Text = "Process User Data";
				this->clearTables(0);
			}
			
			else
			{
				//If the user chose "file input" disable all text boxes
				vcc1->ReadOnly = true; vcc1->BackColor = Color::Gainsboro;vcc2->ReadOnly = true; vcc2->BackColor = Color::Gainsboro;vcc3->ReadOnly = true; vcc3->BackColor = Color::Gainsboro;vcc4->ReadOnly = true; vcc4->BackColor = Color::Gainsboro;vcc5->ReadOnly = true; vcc5->BackColor = Color::Gainsboro;vcc11->ReadOnly = true; vcc11->BackColor = Color::Gainsboro;
				vp1->ReadOnly = true; vp1->BackColor = Color::Gainsboro;vp2->ReadOnly = true; vp2->BackColor = Color::Gainsboro;vp3->ReadOnly = true; vp3->BackColor = Color::Gainsboro;vp4->ReadOnly = true; vp4->BackColor = Color::Gainsboro;vp5->ReadOnly = true; vp5->BackColor = Color::Gainsboro;vp11->ReadOnly = true; vp11->BackColor = Color::Gainsboro;
				vs1->ReadOnly = true; vs1->BackColor = Color::Gainsboro;vs2->ReadOnly = true; vs2->BackColor = Color::Gainsboro;vs3->ReadOnly = true; vs3->BackColor = Color::Gainsboro;vs4->ReadOnly = true; vs4->BackColor = Color::Gainsboro;vs5->ReadOnly = true; vs5->BackColor = Color::Gainsboro;vs11->ReadOnly = true; vs11->BackColor = Color::Gainsboro;
				vps1->ReadOnly = true; vps1->BackColor = Color::Gainsboro;vps2->ReadOnly = true; vps2->BackColor = Color::Gainsboro;vps3->ReadOnly = true; vps3->BackColor = Color::Gainsboro;vps4->ReadOnly = true; vps4->BackColor = Color::Gainsboro;vps5->ReadOnly = true; vps5->BackColor = Color::Gainsboro;vps11->ReadOnly = true; vps11->BackColor = Color::Gainsboro;
				time1->ReadOnly = true; time1->BackColor = Color::Gainsboro;time2->ReadOnly = true; time2->BackColor = Color::Gainsboro;time3->ReadOnly = true; time3->BackColor = Color::Gainsboro;time4->ReadOnly = true; time4->BackColor = Color::Gainsboro;time5->ReadOnly = true; time5->BackColor = Color::Gainsboro;time11->ReadOnly = true; time11->BackColor = Color::Gainsboro;
				form3Open->Visible = true;
				form3File->Visible = true;
				F5Graph->Enabled = false;
				this->clearTables(0);
				this->enterData->Text = "Process File Data";
				this->F3Graph->Visible = true;
			}
		}


		//This overloaded function serves Form 3 & 5, and will populate one column of the table from file
		private: int initializeTable (String ^ filename, int form, DateTime startTime, int row)
		{
			int startRecord; //The record that starts at the user-input time
			int numStep = 5;

			if (this->step2Radio->Checked)
				numStep = 6;

			array<DataTable^>^ forms = gcnew array <DataTable^>{ds->Form_3_Data,ds->Form_5_Data};
			UInt16 i1, i2, i3, i4; //The four channels of current
			float vcc, vp, vs, vps; //The four voltage readings
			float highVcc=0 ; //Used to keep track of the highest animal contact voltage

			//Will read in the header and save it to settings
			Settings^ settings = gcnew Settings(filename);

			if (settings->interval > 10)
				MessageBox::Show ("Warning: The measurement interval exceeds the maximum of 10 seconds.");

			//The logger start time 
			DateTime start (settings->start);
			DateTime st (start.Year,start.Month,start.Day,startTime.Hour,startTime.Minute,0);
			startRecord = (st - start).TotalSeconds/settings->interval;
			
			//If the start time is too low or too high
			if (startRecord < (59 / settings->interval * -1))
			{
				MessageBox::Show("Test time is before logger start\n\nAt time "+st.ToString("HH:mm"));
				return(1);
			}
			else if (startRecord < 0)
			{
				MessageBox::Show("Assuming start time of logger start");
				startRecord =0;
			}
			if (startRecord > settings->numRecord - 11)
			{MessageBox::Show("Not enough records to perform 2-minute test\n\nAt time "+st.ToString("HH:mm"));
			return(1);}
			//Array of bytes, equal to one record
			array<Byte>^ record1 = gcnew array<Byte>(3181);

			BinaryReader^ binReader = gcnew BinaryReader( File::Open( filename, FileMode::Open));

			//Reading in the header (But doing nothing)
			//NOTE: Just seek
			for (int a=0; a<256 + startRecord*3181; a++)
				binReader->ReadByte();

				//Will run 12 times for a 2-minute test
				for (int b =0; b<12; b++)
				{
					for (int i=0; i<3181; i++)
						record1[i]=binReader->ReadByte();

					//Reads in the raw (uncalibrated) channel 4 current value 
					

					if (!channel4I->Checked)
					{
						i4 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[351-256],record1[350-256]},0);
						vcc = getCurrent(i4, settings, 5)*cal5;
					}
					else
					{
						i4 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[108],record1[107]},0);
						vcc = getCurrent(i4, settings, 4)*cal4;
					}

					//If the current is higher than the highest in these 2 minutes
					if (vcc > highVcc)
					{												
						highVcc = vcc; //Set the highest voltage to the new highest

						//Read in and calibrate all of the current data, and change to voltage by multiplying by 0.15
						i1 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[54],record1[53]},0);
						vp = getCurrent (i1, settings, 1)*cal1;
						i2 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[72],record1[71]},0);
						vps = getCurrent (i2, settings, 2)*cal2;
						i3 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[90],record1[89]},0);
						vs = getCurrent (i3, settings, 3)*cal3;
					}
				}
				//This are the values of the record with the highest vcc in the two minute test
				ds->Form_3_Data[row-1]->vcc = highVcc;
				ds->Form_3_Data[row-1]->vp = vp;
				ds->Form_3_Data[row-1]->vs = vs;
				ds->Form_3_Data[row-1]->vps = vps;	
				binReader->Close();
				return 0;

		}

		//If the user clicked on "form 1" under instructions in the menu strip
		private: System::Void form1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Create a new instructions form displaying the instructions for Form 1
			 RichTextBox^ rt = gcnew RichTextBox();
			 rt->Text = readInstructions("form1Instr.txt");
			 rt->ReadOnly = true;
			 rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			 FarmStrayVoltage::Instructions^ instr = gcnew Instructions(rt,1);	
			 instr->ShowDialog();
		 }
		//If the user clicked on "form 2" under instructions in the menu strip
		private: System::Void form2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Create a new instructions form displaying the instructions for Form 2
			 RichTextBox^ rt = gcnew RichTextBox();
			 rt->Text = readInstructions("form2Instr.txt");
			 rt->ReadOnly = true;
			 rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			 FarmStrayVoltage::Instructions^ instr = gcnew Instructions(rt,2);	
			 instr->ShowDialog();
		 }
		//If the user clicked on "form 4" under instructions in the menu strip
		private: System::Void form4ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Create a new instructions form displaying the instructions for Form 4
			 RichTextBox^ rt = gcnew RichTextBox();
			 rt->Text = readInstructions("form4Instr.txt");
			 rt->ReadOnly = true;
			 rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			 FarmStrayVoltage::Instructions^ instr = gcnew Instructions(rt,4);	
			 instr->ShowDialog();
		 }
		//If the user clicked on "form 5" under instructions in the menu strip
		private: System::Void form5ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Create a new instructions form displaying the instructions for Form 5
			 RichTextBox^ rt = gcnew RichTextBox();
			 rt->Text = readInstructions("form5Instr.txt");
			 rt->ReadOnly = true;
			 rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			 FarmStrayVoltage::Instructions^ instr = gcnew Instructions(rt,5);	
			 instr->ShowDialog();
		 }
		//If the user clicked on "form 6" under instructions in the menu strip
		private: System::Void form6ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Create a new instructions form displaying the instructions for Form 6
			 RichTextBox^ rt = gcnew RichTextBox();
			 rt->Text = readInstructions("form6Instr.txt");
			 rt->ReadOnly = true;
			 rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			 FarmStrayVoltage::Instructions^ instr = gcnew Instructions(rt,6);	
			 instr->ShowDialog();
		 }
		//If the user clicked on "Form 3" under "Instructions" in the menu strip 
		private: System::Void form3ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			RichTextBox^ rt = gcnew RichTextBox();
			rt->Text = readInstructions ("form3Instr.txt");
			rt->ReadOnly = true;
			rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			Instructions^ instr = gcnew Instructions(rt,3);
			instr->ShowDialog();
		}

		//If the user changed the checked status of farm service type
		private: System::Void phaseRadio1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			//Toggle visibility of controls depending on checked radio button
			if (phaseRadio3->Checked)
			{
				vccd1Phase->Visible = false;
				vccd3Phase->Visible = true;
				vccd1Phase5->Visible = false;
				vccd3Phase5->Visible = true;

				this->step2Radio->Visible = true;
				this->radio5Step->Visible = true;
				phases->Text = "Three Phase Secondary";
				phases5->Text = "Three Phase Secondary";
				if (this->radio5Step->Checked)
				{
					phaseBox->SelectedIndex = 0;
					phaseBox->Visible = true;

					phaseBox5->SelectedIndex = 0;
					phaseBox5->Visible = true;
				}
				this->phase3ses->Visible = true;
				this->phase3ses5->Visible = true;
				if (this->vccd3Phase->Text != "V")
					completeForms[5]= true;
				else
					completeForms[5] = false;
				if (this->vccd3Phase5->Text != "V")
					completeForms[6]= true;
				else
					completeForms[6] = false;
			}
			 else
			 {
				this->step2Radio->Visible = false;
				this->radio5Step->Visible = false;
				radio5Step->Checked = true;
				vccd1Phase->Visible = true;
				vccd3Phase->Visible = false;
				vccd1Phase5->Visible = true;
				vccd3Phase5->Visible = false;
				phases->Text = "Single Phase Secondary";
				phases5->Text = "Single Phase Secondary";
				this->phase3ses->Visible = false;
				this->phaseBox->Visible = false;
				this->phase3ses5->Visible = false;
				this->phaseBox5->Visible = false;
				if (this->vccd1Phase->Text != "V")
					completeForms[5]= true;
				else
					completeForms[5] = false;
				if (this->vccd1Phase5->Text != "V")
					completeForms[6]= true;
				else
					completeForms[6] = false;
			}
			this->Refresh();
		}
		//If the user clicked the "Done" button in the Main page
		private: System::Void doneButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//Set the calibration to the numbers in the calibration text boxes 
			cal1 = Convert::ToSingle(cal1Text->Text);
			cal2 = Convert::ToSingle(cal2Text->Text);
			cal3 = Convert::ToSingle(cal3Text->Text);
			cal4 = Convert::ToSingle(cal4Text->Text);
		}

		//If the user changed the checked state of doing 1 5-step test or 3 2-step tests
		private: System::Void radio5Step_CheckedChanged (System::Object^ sender, System::EventArgs^ e)
		{
			//Change the tables in Form 3 & 5 to allow for tests with different number of steps
			if (radio5Step->Checked)
			{		
				this->tableLayoutPanel1->Controls->Remove(step6Label);
				this->tableLayoutPanel1->Controls->Remove(step6Farm);
				this->tableLayoutPanel1->Controls->Remove(step6Load);
				this->tableLayoutPanel1->Controls->Remove(vcc11);
				this->tableLayoutPanel1->Controls->Remove(time11);
				this->tableLayoutPanel1->Controls->Remove(vp11);
				this->tableLayoutPanel1->Controls->Remove(vps11);
				this->tableLayoutPanel1->Controls->Remove(vs11);
				this->tableLayoutPanel1->ColumnCount = 6;
				this->step3Label->Text = "Step 3";
				this->step4Label->Text = "Step 4";
				this->step5Label->Text = "Step 5";
				this->step3Farm->Text = "OFF";
				this->step5Farm->Text = "OFF";
				this->step3Load->Text = "HALF";
				this->step4Load->Text = "FULL";
				this->step5Load->Text = "FULL";


				this->tableLayoutPanel2->Controls->Remove(step12Label);
				this->tableLayoutPanel2->Controls->Remove(step12Farm);
				this->tableLayoutPanel2->Controls->Remove(step12Load);
				this->tableLayoutPanel2->Controls->Remove(vcc12);
				this->tableLayoutPanel2->Controls->Remove(time12);
				this->tableLayoutPanel2->Controls->Remove(vp12);
				this->tableLayoutPanel2->Controls->Remove(vps12);
				this->tableLayoutPanel2->Controls->Remove(vs12);
				this->tableLayoutPanel2->ColumnCount = 6;
				this->step9Label->Text = "Step 3";
				this->step10Label->Text = "Step 4";
				this->step11Label->Text = "Step 5";
				this->step9Farm->Text = "OFF";
				this->step9Load->Text = "HALF";
				this->step10Load->Text = "FULL";
				this->step11Load->Text = "FULL";


					phase3ses->Text = "5 Steps on Phase:";
					phaseBox->SelectedIndex = 0;
					phaseBox->Visible = true;

					phase3ses5->Text = "5 Steps on Phase:";
					phaseBox5->SelectedIndex = 0;
					phaseBox5->Visible = true;

			}
			else
			{
				this->tableLayoutPanel1->ColumnCount = 7;
				this->tableLayoutPanel1->Controls->Add(this->step6Label, 6, 0);
				this->tableLayoutPanel1->Controls->Add(this->step6Farm, 6, 1);
				this->tableLayoutPanel1->Controls->Add(this->step6Load, 6, 2);
				this->tableLayoutPanel1->Controls->Add(this->time11, 6, 3);
				this->tableLayoutPanel1->Controls->Add(this->vcc11, 6, 4);
				this->tableLayoutPanel1->Controls->Add(this->vp11, 6, 5);
				this->tableLayoutPanel1->Controls->Add(this->vs11, 6, 6);
				this->tableLayoutPanel1->Controls->Add(this->vps11, 6, 7);
				this->step3Label->Text = "Step 1";
				this->step4Label->Text = "Step 2";
				this->step5Label->Text = "Step 1";
				this->step3Farm->Text = "ON";
				this->step3Load->Text = "OFF";
				this->step4Load->Text = "OFF";
				this->step5Load->Text = "OFF";
				step6Label->Visible=true;step6Farm->Visible=true;step6Load->Visible=true;time11->Visible=true;vcc11->Visible=true;vp11->Visible=true;vs11->Visible=true;vps11->Visible=true;

				this->tableLayoutPanel2->ColumnCount = 7;
				this->tableLayoutPanel2->Controls->Add(this->step12Label, 6, 0);
				this->tableLayoutPanel2->Controls->Add(this->step12Farm, 6, 1);
				this->tableLayoutPanel2->Controls->Add(this->step12Load, 6, 2);
				this->tableLayoutPanel2->Controls->Add(this->time12, 6, 3);
				this->tableLayoutPanel2->Controls->Add(this->vcc12, 6, 4);
				this->tableLayoutPanel2->Controls->Add(this->vp12, 6, 5);
				this->tableLayoutPanel2->Controls->Add(this->vs12, 6, 6);
				this->tableLayoutPanel2->Controls->Add(this->vps12, 6, 7);
				
				this->step9Label->Text = "Step 1";
				this->step10Label->Text = "Step 2";
				this->step11Label->Text = "Step 1";
				this->step9Farm->Text = "ON";
				this->step9Load->Text = "OFF";
				this->step10Load->Text = "OFF";
				this->step11Load->Text = "OFF";
				step12Label->Visible=true;step12Farm->Visible=true;step12Load->Visible=true;time12->Visible=true;vcc12->Visible=true;vp12->Visible=true;vs12->Visible=true;vps12->Visible=true;
				
				phase3ses->Text = "2 Steps On 3 Phases";
				phaseBox->Visible = false;

				phase3ses5->Text = "2 Steps On 3 Phases";
				phaseBox5->Visible = false;
			}
		}
		//Will clear the table in either form3 or form5
		private: System::Void clearTables (int form)
		{
			//Using arrays will cut programming in half 
			array<TextBox^>^ vccA = gcnew array<TextBox^>{vcc1,vcc2,vcc3,vcc4,vcc5,vcc11,vcc6,vcc7,vcc8,vcc9,vcc10,vcc12};
			array<TextBox^>^ vpA = gcnew array<TextBox^>{vp1,vp2,vp3,vp4,vp5,vp11,vp6,vp7,vp8,vp9,vp10,vp12};
			array<TextBox^>^ vsA = gcnew array<TextBox^>{vs1,vs2,vs3,vs4,vs5,vs11,vs6,vs7,vs8,vs9,vs10,vs12};
			array<TextBox^>^ vpsA = gcnew array<TextBox^>{vps1,vps2,vps3,vps4,vps5,vps11,vps6,vps7,vps8,vps9,vps10,vps12};
			array<MaskedTextBox^>^ timeA = gcnew array<MaskedTextBox^>{time1,time2,time3,time4,time5,time11,time6,time7,time8,time9,time10,time12};
			
			int a = 6 * form; //Form will either be 1 or 0, so if form 5 needs to be cleared, a will start as 6
			
			//Clear the data tables of any data
			if (form ==0 && this->Farm_Stray_Voltage_Data->Form_3_Data->Rows->Count>0)
				this->Farm_Stray_Voltage_Data->Form_3_Data->Clear();
			else if (form == 0 && this->Farm_Stray_Voltage_Data->Form_5_Data->Rows->Count>0)
				this->Farm_Stray_Voltage_Data->Form_5_Data->Clear();
			
			//Make the textbox text fields empty
			for (a; a<6+(6*form); a++)
			{
				vccA[a]->Text = "";
				vpA[a]->Text = "";
				vsA[a]->Text = "";
				vpsA[a]->Text = "";
				timeA[a]->Text = "";
			}
		}
		//If the user double-clicks on a row in Form 1 page 2
		private: System::Void form1Grid_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) 
		{
			//If the grid has any rows, and user clicked on a row that has data
			if (form1Grid->RowCount > 0 && e->RowIndex < form1Grid->RowCount-1)
			{
				if (!this->Farm_Stray_Voltage_Data->Form_1_Data[e->RowIndex]->IscommentNull())
					commentText->Text = this->Farm_Stray_Voltage_Data->Form_1_Data[e->RowIndex]->comment; //Clear the carriage return that will likely be there
				else
					commentText->Text = "";

				//Make the textbox visible, position it, and give it focuse
				commentText->Visible = true;
				label5->Visible = true;
				commentText->Focus();
				commentText->Name = e->RowIndex.ToString();	//A way to save the row index of the double-clicked row			
			}
		}
		//If the user presses a key down in commentText
		private: System::Void commentText_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		{
			//Will check to see if enter was pressed, if it is, save the comment and make the textbox invisible
			if (e->KeyCode == Keys::Enter)
			{			
				this->Farm_Stray_Voltage_Data->Form_1_Data[Convert::ToInt16(commentText->Name)]->comment = commentText->Text;
				this->Focus();
				commentText->Visible = false;
				label5->Visible = false;
			}
		}
		//If the user clicks away from commentText
		private: System::Void commentText_LostFocus (Object^ sender, System::EventArgs^ e)
		{
			//Make it invisible
			commentText->Visible = false;
			label5->Visible = false;
		}

		//If the user enters Form 4
		private: System::Void tabPage9_Enter(System::Object^  sender, System::EventArgs^  e) 
		{
			//Will tell the user what he needs in order for form 4 to be filled
			String^ whatYouNeed = "Not enough data to complete Form 4:\n\n";
			
			//If the farm is singler service and there is no vccd value
			if (this->vccd1Phase->Text == "V" && this->phaseRadio1->Checked)
			{
				
				//Checks each required text field and adds it to the list if it does not have a value
				if (this->highestP2RV <= 0)
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Form 2 to get values for VCCfsv and VPfsv\n");
					tabControl1->SelectedIndex = 3;
				}
				if (this->vccoff->Text == "V")
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Step 2 of Form 3 to get values for VCCoff and VPoff\n");
					if (tabControl1->SelectedIndex != 3)
						tabControl1->SelectedIndex = 4;
				}
				if (this->vcchalf->Text == "V")
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Step 3 of Form 3 to get values for VCChalf and VPhalf\n");
					if (tabControl1->SelectedIndex != 3)
						tabControl1->SelectedIndex = 4;
				}
				if (this->vccfull->Text == "V")
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Step 4 of Form 3 to get values for VCCfull and VPfull\n");
					if (tabControl1->SelectedIndex != 3)
						tabControl1->SelectedIndex = 4;
				}
				MessageBox::Show(whatYouNeed);
			}
			//If the farm is three-service and vccd has no value
			else if (this->vccd3Phase->Text == "V" && this->phaseRadio3->Checked)
			{
				MessageBox::Show(String::Concat(whatYouNeed,"Complete Step 2 of Form 3 to get a value for VccD"));
				tabControl1->SelectedIndex = 4;
			}
		}
		//If the user clicked on "Print..." in the menu strip
		private: System::Void printToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
				//Show the print dialog and if the user chose a printer, print using the chosen printer							
				if (this->printDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					printDocument1->PrintPage += gcnew Printing::PrintPageEventHandler( this, &Form1::pd_PrintPage );
					printDocument1->PrinterSettings->PrinterName = this->printDialog1->PrinterSettings->PrinterName;
					printDocument1->Print();
				}

		}
		//Will print the current form
		private: System::Void pd_PrintPage( Object^ /*sender*/, Printing::PrintPageEventArgs^ ev )
		{		
			ev->Graphics->Clear(Color::White); //Clear the page
			this->Refresh();
			
			//Creating the image to be printed
			System::Drawing::Bitmap^ i = gcnew System::Drawing::Bitmap(tabControl1->Width,tabControl1->Height);
			System::Drawing::Rectangle ^rect = gcnew System::Drawing::Rectangle(Point(0,0), tabControl1->Size);
			tabControl1->DrawToBitmap(i,*rect);
			
			//Scale it down so it can fit on a page and draw it to page
			ev->Graphics->ScaleTransform(0.70,0.70);
			ev->Graphics->DrawImage(i,Point(0,0));
			ev->Graphics->ScaleTransform (1.42857142857,1.42857142857);
		}



		//This function will get all necessary information to fill Form 4's text boxes, and then output them
		private: System::Void form4Fill (int form)
		{
			
			while (this->Farm_Stray_Voltage_Data->Form_3_Data->Rows->Count<6)
			{
				DataRow^ row = this->Farm_Stray_Voltage_Data->Form_3_Data->NewRow();
				this->Farm_Stray_Voltage_Data->Form_3_Data->Rows->Add(row);
			}
			while (this->Farm_Stray_Voltage_Data->Form_5_Data->Rows->Count<6)
			{
				DataRow^ row = this->Farm_Stray_Voltage_Data->Form_5_Data->NewRow();
				this->Farm_Stray_Voltage_Data->Form_5_Data->Rows->Add(row);
			}
			
			int offset = 0;
			if (form != 0)
				offset = 8;
			array<Label^>^ form4A = gcnew array<Label^>{vccoff,vpoff,vcchalf,vphalf,vccfull,vpfull,vccd1Phase,vccd3Phase,vccoff5,vpoff5,vcchalf5,vphalf5,vccfull5,vpfull5,vccd1Phase5,vccd3Phase5};
			if (highestP2RV > 0 && highestVcc > 0)
			{
				this->vccfsv->Text = Math::Round(highestVcc,2).ToString(); this->vpfsv->Text = Math::Round(highestP2RV,2).ToString();
				this->vccfsv5->Text = Math::Round(highestVcc,2).ToString(); this->vpfsv5->Text = Math::Round(highestP2RV,2).ToString();
			}
			//If the vcc value is not null in the second row of Form 3 or Form5, get the vccfsv and vpfsv values, and set the VccD of three-service value
			if (form ==0 && !this->Farm_Stray_Voltage_Data->Form_3_Data[1]->IsvccNull()){
				form4A[offset]->Text = String::Concat(Convert::ToString(Math::Round(this->Farm_Stray_Voltage_Data->Form_3_Data[1]->vcc,2))," V");
				form4A[offset+1]->Text = String::Concat(Convert::ToString(Math::Round(this->Farm_Stray_Voltage_Data->Form_3_Data[1]->vp,2))," V");}
			else if (form==1 && vcc7->Text != ""){
				form4A[offset]->Text = vcc7->Text + " V";
				form4A[offset+1]->Text =vp7->Text + " V";}

			//If the vcc value is not null in the third row of Form 3 or Form5, get the vccfsv and vpfsv values
			if (form ==0 && !this->Farm_Stray_Voltage_Data->Form_3_Data[2]->IsvccNull()){
				form4A[offset+2]->Text = String::Concat(Convert::ToString(Math::Round(this->Farm_Stray_Voltage_Data->Form_3_Data[2]->vcc,2))," V");
				form4A[offset+3]->Text = String::Concat(Convert::ToString(Math::Round(this->Farm_Stray_Voltage_Data->Form_3_Data[2]->vp,2))," V");}
			else if (form ==1 && vcc8->Text != ""){
				form4A[offset+2]->Text = vcc8->Text + " V";
				form4A[offset+3]->Text = vp8->Text + " V";}

			//If the vcc value is not null in the fourth row of Form 3 or Form5, get the vccfsv and vpfsv values
			if (form ==0 && !this->Farm_Stray_Voltage_Data->Form_3_Data[3]->IsvccNull()){
				form4A[offset+4]->Text = String::Concat(Convert::ToString(Math::Round(this->Farm_Stray_Voltage_Data->Form_3_Data[3]->vcc,2))," V");
				form4A[offset+5]->Text = String::Concat(Convert::ToString (Math::Round (this->Farm_Stray_Voltage_Data->Form_3_Data[3]->vp,2))," V");}
			else if (form == 1 && vcc9->Text != ""){
				form4A[offset+4]->Text = vcc9->Text + " V";
				form4A[offset+5]->Text = vp9->Text + " V";}


			//If all the necessary text boxes have values and highestP2RV is greater than 0, do the math to get VccD for single-phase farms
			if (((form == 0 && !this->Farm_Stray_Voltage_Data->Form_3_Data[3]->IsvccNull() && !this->Farm_Stray_Voltage_Data->Form_3_Data[2]->IsvccNull())|| (form == 1 && vcc9->Text != "" && vcc8->Text != ""))&& highestP2RV>0)
				if (form ==0)
				{
					form4A[offset+6]->Text = String::Concat(Convert::ToString(Math::Round((highestP2RV - this->Farm_Stray_Voltage_Data->Form_3_Data[2]->vp)/(this->Farm_Stray_Voltage_Data->Form_3_Data[3]->vp-this->Farm_Stray_Voltage_Data->Form_3_Data[2]->vp)* (this->Farm_Stray_Voltage_Data->Form_3_Data[3]->vcc-this->Farm_Stray_Voltage_Data->Form_3_Data[2]->vcc)+ this->Farm_Stray_Voltage_Data->Form_3_Data[2]->vcc,2)) ," V");					
					completeForms[5] = true;
				}
				else
				{
					form4A[offset+6]->Text = String::Concat(Convert::ToString(Math::Round((highestP2RV - Convert::ToDouble(vp8->Text))/(Convert::ToDouble(vp9->Text)-Convert::ToDouble(vp8->Text))* (Convert::ToDouble(vcc9->Text)-Convert::ToDouble(vcc8->Text))+ Convert::ToDouble(vcc8->Text), 2)) ," V");
					completeForms[6] = true;
				}
			
			if (this->phaseRadio3->Checked && !this->Farm_Stray_Voltage_Data->Form_3_Data[1]->IsvccNull() && form == 0)
			{
				form4A[7]->Text =this->Farm_Stray_Voltage_Data->Form_3_Data[1]->vcc.ToString();
				completeForms[5] = true;
			}
			else if (this->phaseRadio3->Checked && vcc7->Text!= "" && form == 1)
			{
				form4A[7+offset]->Text = vcc7->Text;
				
				completeForms[6] = true;
			}

			this->Refresh();
		}
		//Fired when the user enters Form 5 Page 2, and will let them know what is missing
		private: System::Void tabPage12_Enter(System::Object^  sender, System::EventArgs^  e) 
		{
			//Will tell the user what he needs in order for form 4 to be filled
			String^ whatYouNeed = "Not enough data to complete Form 5:\n\n";
			
			//If the farm is singler service and there is no vccd value
			if (this->vccd1Phase5->Text == "V" && this->phaseRadio1->Checked)
			{
				//Checks each required text field and adds it to the list if it does not have a value
				if (this->vccoff5->Text == "V")
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Step 2 of Form 5 to get values for VCCoff and VPoff\n");
					this->tabControl4->SelectedIndex = 0;
				}
				if (this->vcchalf5->Text == "V")
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Step 3 of Form 5 to get values for VCChalf and VPhalf\n");
						this->tabControl4->SelectedIndex = 0;
				}
				if (this->vccfull5->Text == "V")
				{
					whatYouNeed = String::Concat(whatYouNeed, "Complete Step 4 of Form 5 to get values for VCCfull and VPfull\n");
						this->tabControl4->SelectedIndex = 0;
				}
				if (this->highestP2RV <= 0)
				{
					whatYouNeed = whatYouNeed->Insert (37,"Complete Form 2 to get values for VCCfsv and VPfsv\n");
					tabControl1->SelectedIndex = 3;
					tabControl4->SelectedIndex = 0;
				}
				
				MessageBox::Show(whatYouNeed);
			}
			//If the farm is three-service and vccd has no value
			else if (this->vccd3Phase5->Text == "V" && this->phaseRadio3->Checked)
				MessageBox::Show(String::Concat(whatYouNeed,"Complete Step 2 of Form 3 to get a value for VCCoff"));
		}
		//Fired when the "View Graph" button is pressed
		private: System::Void viewGraph_Click(System::Object^  sender, System::EventArgs^  e) 
		{		
			int whichForm = 0; //0=Form 2, 1=Form6
			if (sender == button1)
				whichForm = 1;
			
			VoltGraph^ vg;
			
			vg = gcnew VoltGraph(whichForm);

			//Set the values of vg to be the same as the existing graph
			vg->SetNumRecord(graphs[whichForm]->pesgo1->PeData->Xii->Length()/4);
			vg->pesgo1->PeData->Subsets = 4;
			vg->pesgo1->PeString->XAxisLabel = "Time"; //Name of the X-Axis
			vg->pesgo1->PeString->YAxisLabel = "Voltage"; //Name of the Y-Axis
			vg->pesgo1->PeString->SubsetLabels[0] = ("Vcc"); //Name of the 1st subset
			vg->pesgo1->PeString->SubsetLabels[1] = ("Vp"); //Name of the 2nd subset
			vg->pesgo1->PeString->SubsetLabels[2] = ("Vs"); //Name of the 3rd subset
			vg->pesgo1->PeString->SubsetLabels[3] = ("Vps"); //Name of the 4th subset
			vg->pesgo1->PeString->MainTitle = "Farm Stray Voltage Test"; //Name of the graph
			vg->pesgo1->PeString->SubTitle = "";
	
			//Draw the graph using the data found in initializeTable
			if (whichForm == 0)
				vg->DrawGraph(graphDataX2,graphDataY);
			else
				vg->DrawGraph(graphDataX26,graphDataY6);

			//Show the popup window that has the graph as a control
			FarmStrayVoltage::Instructions^ instr = gcnew Instructions(vg,whichForm);
			instr->ShowDialog();

		}
		//These next 5 procedures are fired when their respective textbox's text is changed, the cal factor will change as well, if the text length>0
		private: System::Void cal1Text_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (cal1Text->Text->Length > 0 && cal1Text->Text[0] == '.')
			{
				cal1Text->Text = cal1Text->Text->Insert(0,"0");
				cal1Text->SelectionStart = 2;
			}

			if (cal1Text->Text->Length>0)
				cal1 = Convert::ToSingle(cal1Text->Text);
			else
				cal1=0;
		}
		private: System::Void cal2Text_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			if (cal2Text->Text->Length > 0 && cal2Text->Text[0] == '.')
			{
				cal2Text->Text = cal2Text->Text->Insert(0,"0");
				cal2Text->SelectionStart = 2;
			}
			 if (cal2Text->Text->Length>0)			
				cal2 = Convert::ToSingle(cal2Text->Text);
			else
				cal2=0;
		 }
		private: System::Void cal3Text_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			if (cal3Text->Text->Length > 0 && cal3Text->Text[0] == '.')
			{
				cal3Text->Text = cal3Text->Text->Insert(0,"0");
				cal3Text->SelectionStart = 2;
			}
			if (cal3Text->Text->Length>0)
				cal3 = Convert::ToSingle(cal3Text->Text);
			 else
				cal3=0;
		 }
		private: System::Void cal4Text_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (cal4Text->Text->Length > 0 && cal4Text->Text[0] == '.')
			{
				cal4Text->Text = cal4Text->Text->Insert(0,"0");
				cal4Text->SelectionStart = 2;
			}
			if (cal4Text->Text->Length>0)
				cal4 = Convert::ToSingle(cal4Text->Text);
			else
				cal4=0;
		}

		private: System::Void cal5Text_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			if (cal5Text->Text->Length > 0 && cal5Text->Text[0] == '.')
			{
				cal5Text->Text = cal5Text->Text->Insert(0,"0");
				cal5Text->SelectionStart = 2;
			}
			if (cal5Text->Text->Length>0)
				cal5 = Convert::ToSingle(cal5Text->Text);
			else
				cal5=0;
		 }
		//Fired when the "generate report" button is clicked
		private: System::Void reportButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (this->madeDiagram)
			{
			System::Drawing::Bitmap^ bmp = gcnew Bitmap(filePath + "diagram.bmp");
			bmp->RotateFlip(RotateFlipType::Rotate90FlipNone);
			bmp->Save (filePath + "diagram2.bmp");
			delete bmp;
			}
				this->setReportParameters();//Set the parameters for the report in reportViewer1

				this->form1DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data->Form_1_Data;
				this->form2DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data->Form_2_Data;
				this->form3DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data->Form_3_Data;
				this->form5DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data->Form_5_Data;
				this->form6DataBindingSource->DataSource = this->Farm_Stray_Voltage_Data->Form_6_Data;			
				this->reportViewer1->RefreshReport();

				sfd = gcnew SaveFileDialog();
				sfd->Filter = "PDF Files|*.PDF";
				if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					Export(this->reportViewer1->LocalReport);
				}
		}
		//Will send all the needed parameters (found in text boxes) to the report
		private: System::Void setReportParameters ()
		{
			//The VccD for forms 4 and 5 depend on whether the farm is three-phase or single-phase
			String ^ vccdText;
			if (this->phaseRadio1->Checked)
				vccdText=this->vccd1Phase->Text;
			else
				vccdText=this->vccd3Phase->Text;
			String ^ vccdText5;
			if (this->phaseRadio1->Checked)
				vccdText5=this->vccd1Phase5->Text;
			else
				vccdText5=this->vccd3Phase5->Text;

			vccdText = vccdText->Remove(vccdText->Length-1, 1);
			vccdText5 = vccdText5->Remove(vccdText5->Length-1, 1);

			String^ vccInput;
			if (this->channel4I->Checked)
				vccInput = "Channel 4 AC";
			else
				vccInput = "Channel 5 DC";
			//Create all the parameters to send by gathering all the information from the text boxes
			Microsoft::Reporting::WinForms::ReportParameter^ a = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_2_Start",this->form2StartText->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ b = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_2_Stop",this->form2StopText->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ c = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_2_LocId",this->locCombo->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ d = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_Vpri",this->vpri->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ e = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_ILBH",this->ilbh->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ f = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_ILBF",this->ilbf->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ g = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_VLBH",this->vlbh->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ h = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_VLBF",this->vlbf->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ i = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_IP",this->ip->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ j = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_4_VccD",vccdText);
			Microsoft::Reporting::WinForms::ReportParameter^ k = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_Vpri",this->textBox11->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ l = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_ILBH",this->textBox12->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ m = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_ILBF",this->textBox14->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ n = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_VLBH",this->textBox13->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ o = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_VLBF",this->textBox17->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ p = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_IP",this->textBox18->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ q = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_VccD",vccdText5);
			Microsoft::Reporting::WinForms::ReportParameter^ r = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_6_Start",this->form6Start->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ s = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_6_Stop",this->form6Stop->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ t = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_6_LocId",this->locCombo6->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ u = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_2_File",this->form2FileText->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ v = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_File",this->form3File->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ w = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_File",this->form5File->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ x = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_6_File",this->form6FileText->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ y = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_1_Date",this->form1DateText->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ z = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_3_Date",this->form3Date);
			Microsoft::Reporting::WinForms::ReportParameter^ a2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("Form_5_Date",this->form5Date);
			Microsoft::Reporting::WinForms::ReportParameter^ b2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("ch1_Cal",this->cal1Text->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ c2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("ch2_Cal",this->cal2Text->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ d2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("ch3_Cal",this->cal3Text->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ e2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("ch4_Cal",this->cal4Text->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ f2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vcc1",this->vcc1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ g2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vcc2",this->vcc2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ h2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vcc3",this->vcc3->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ i2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vcc4",this->vcc4->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ j2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vcc5",this->vcc5->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ k2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vp1",this->vp1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ l2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vp2",this->vp2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ m2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vp3",this->vp3->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ n2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vp4",this->vp4->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ o2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vp5",this->vp5->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ p2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vs1",this->vs1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ q2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vs2",this->vs2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ r2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vs3",this->vs3->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ s2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vs4",this->vs4->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ t2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vs5",this->vs5->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ u2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vps1",this->vps1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ v2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vps2",this->vps2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ w2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vps3",this->vps3->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ x2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vps4",this->vps4->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ y2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3vps5",this->vps5->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ z2 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3time1",this->time1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ a3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3time2",this->time2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ b3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3time3",this->time3->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ c3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3time4",this->time4->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ d3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F3time5",this->time5->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ e3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vcc1",this->vcc6->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ f3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vcc2",this->vcc7->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ g3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vcc3",this->vcc8->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ h3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vcc4",this->vcc9->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ i3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vcc5",this->vcc10->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ j3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vp1",this->vp6->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ k3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vp2",this->vp7->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ l3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vp3",this->vp8->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ m3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vp4",this->vp9->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ n3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vp5",this->vp10->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ o3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vs1",this->vs6->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ p3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vs2",this->vs7->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ q3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vs3",this->vs8->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ r3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vs4",this->vs9->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ s3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vs5",this->vs10->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ t3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vps1",this->vps6->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ u3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vps2",this->vps7->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ v3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vps3",this->vps8->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ w3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vps4",this->vps9->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ x3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5vps5",this->vps10->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ y3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5time1",this->time6->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ z3 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5time2",this->time7->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ a4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5time3",this->time8->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ b4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5time4",this->time9->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ c4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("F5time5",this->time10->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ d4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Time",this->time11->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ e4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vcc",this->vcc11->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ f4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vp",this->vp11->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ g4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vs",this->vs11->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ h4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vps",this->vps11->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ i4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Time5",this->time12->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ j4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vcc5",this->vcc12->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ k4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vp5",this->vp12->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ l4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vs5",this->vs12->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ m4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("step6Vps5",this->vps12->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ n4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("fiveStep",this->radio5Step->Checked.ToString());
			Microsoft::Reporting::WinForms::ReportParameter^ o4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("filePath",filePath);
			Microsoft::Reporting::WinForms::ReportParameter^ p4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("utilName",this->utilName->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ q4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("utilAddress1",this->utilAddress1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ r4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("utilAddress2",this->utilAddress2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ s4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("utilPhone",this->utilPhone->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ t4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("utilEmail",this->utilEmail->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ u4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("utilWebsite",this->utilWebsite->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ v4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investName",this->investName->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ w4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investReceive",this->investReceive->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ x4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investVisit",this->investVisit->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ y4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investStart",this->investStart->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ z4 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investConclude",this->investConclude->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ a5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("custName",this->custName->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ b5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("custAddress1",this->custAddress1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ c5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("custAddress2",this->custAddress2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ d5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("custPhone",this->custPhone->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ e5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("custEmail",this->custEmail->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ f5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("farmName",this->farmName->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ g5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("farmAddress1",this->farmAddress1->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ h5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("farmAddress2",this->farmAddress2->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ i5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("farmPhone",this->farmPhone->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ j5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("farmEmail",this->farmEmail->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ k5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investEmail",this->investEmail->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ l5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("investPhone",this->investPhone->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ m5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("fileNumber",this->fileNumber->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ n5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("phases",this->phases->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ o5;
			if (phaseRadio3->Checked)
				o5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("phase3ses",this->phase3ses->Text);
			else
				o5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("phase3ses","");
			Microsoft::Reporting::WinForms::ReportParameter^ p5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("activePhase",this->phaseBox->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ q5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("ReportSummary",this->reportSummary->Text);
			Microsoft::Reporting::WinForms::ReportParameter^ r5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("VccInput",vccInput);
			Microsoft::Reporting::WinForms::ReportParameter^ s5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("highVp",Math::Round(this->highestP2RV,2).ToString("0.00"));
			Microsoft::Reporting::WinForms::ReportParameter^ t5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("highVcc",Math::Round(this->highestVcc,2).ToString("0.00"));
			Microsoft::Reporting::WinForms::ReportParameter^ u5 = gcnew Microsoft::Reporting::WinForms::ReportParameter("Cal5",this->cal5Text->Text);

			this->reportViewer1->LocalReport->SetParameters(gcnew array <Microsoft::Reporting::WinForms::ReportParameter^>{a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a2,b2,c2,d2,e2,f2,g2,h2,i2,j2,k2,l2,m2,n2,o2,
				p2,q2,r2,s2,t2,u2,v2,w2,x2,y2,z2,a3,b3,c3,d3,e3,f3,g3,h3,i3,j3,k3,l3,m3,n3,o3,p3,q3,r3,s3,t3,u3,v3,w3,x3,y3,z3,a4,b4,c4,d4,e4,f4,g4,h4,i4,j4,k4,l4,m4,n4,o4,p4,q4,r4,s4,t4,u4,
			v4,w4,x4,y4,z4,a5,b5,c5,d5,e5,f5,g5,h5,i5,j5,k5,l5, m5,n5,o5,p5,q5, r5,s5,t5,u5});
		}

		//Fired when the user leaves the main page
		private: System::Void tabPage14_Leave(System::Object^  sender, System::EventArgs^  e) 
		{
			//If any of the cal factors are 0, will output a warning		
			if (cal1*cal2*cal3*cal4 == 0)
				 MessageBox::Show("One or more calibration factors do not have a value!","Warning");
		//	if (!isFilled(tabPage14))
		//		MessageBox::Show ("You ain't done yet!");
		 }

		//Fired when the user changes the state of "File/User Input" Radio buttons on Form 5
		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (!radioButton2->Checked)
			{
				//If the user chose "file input" disable all text boxes
				vcc6->ReadOnly = false; vcc6->BackColor = Color::White;vcc7->ReadOnly = false; vcc7->BackColor = Color::White;vcc8->ReadOnly = false; vcc8->BackColor = Color::White;vcc9->ReadOnly = false; vcc9->BackColor = Color::White;vcc10->ReadOnly = false; vcc10->BackColor = Color::White;vcc12->ReadOnly = false; vcc12->BackColor = Color::White;
				vp6->ReadOnly = false; vp6->BackColor = Color::White;vp7->ReadOnly = false; vp7->BackColor = Color::White;vp8->ReadOnly = false; vp8->BackColor = Color::White;vp9->ReadOnly = false; vp9->BackColor = Color::White;vp10->ReadOnly = false; vp10->BackColor = Color::White;vp12->ReadOnly = false; vp12->BackColor = Color::White;
				vs6->ReadOnly = false; vs6->BackColor = Color::White;vs7->ReadOnly = false; vs7->BackColor = Color::White;vs8->ReadOnly = false; vs8->BackColor = Color::White;vs9->ReadOnly = false; vs9->BackColor = Color::White;vs10->ReadOnly = false; vs10->BackColor = Color::White;vs12->ReadOnly = false; vs12->BackColor = Color::White;
				vps6->ReadOnly = false; vps6->BackColor = Color::White;vps7->ReadOnly = false; vps7->BackColor = Color::White;vps8->ReadOnly = false; vps8->BackColor = Color::White;vps9->ReadOnly = false; vps9->BackColor = Color::White;vps10->ReadOnly = false; vps10->BackColor = Color::White;vps12->ReadOnly = false; vps12->BackColor = Color::White;
				time6->ReadOnly = false; time6->BackColor = Color::White;time7->ReadOnly = false; time7->BackColor = Color::White;time8->ReadOnly = false; time8->BackColor = Color::White;time9->ReadOnly = false; time9->BackColor = Color::White;time10->ReadOnly = false; time10->BackColor = Color::White;time12->ReadOnly = false; time12->BackColor = Color::White;
				form5Open->Visible = false;
				form5File->Visible = false;
				form5File->Text = "Please open a file...";
				this->clearTables(1);
				F5Graph->Visible = false;
				this->enterData5->Text = "Process User Data";
			}
			else
			{
				//If the user chose "user input"
				vcc6->ReadOnly = true; vcc6->BackColor = Color::Gainsboro;vcc7->ReadOnly = true; vcc7->BackColor = Color::Gainsboro;vcc8->ReadOnly = true; vcc8->BackColor = Color::Gainsboro;vcc9->ReadOnly = true; vcc9->BackColor = Color::Gainsboro;vcc10->ReadOnly = true; vcc10->BackColor = Color::Gainsboro;vcc12->ReadOnly = true; vcc12->BackColor = Color::Gainsboro;
				vp6->ReadOnly = true; vp6->BackColor = Color::Gainsboro;vp7->ReadOnly = true; vp7->BackColor = Color::Gainsboro;vp8->ReadOnly = true; vp8->BackColor = Color::Gainsboro;vp9->ReadOnly = true; vp9->BackColor = Color::Gainsboro;vp10->ReadOnly = true; vp10->BackColor = Color::Gainsboro;vp12->ReadOnly = true; vp12->BackColor = Color::Gainsboro;
				vs6->ReadOnly = true; vs6->BackColor = Color::Gainsboro;vs7->ReadOnly = true; vs7->BackColor = Color::Gainsboro;vs8->ReadOnly = true; vs8->BackColor = Color::Gainsboro;vs9->ReadOnly = true; vs9->BackColor = Color::Gainsboro;vs10->ReadOnly = true; vs10->BackColor = Color::Gainsboro;vs12->ReadOnly = true; vs12->BackColor = Color::Gainsboro;
				vps6->ReadOnly = true; vps6->BackColor = Color::Gainsboro;vps7->ReadOnly = true; vps7->BackColor = Color::Gainsboro;vps8->ReadOnly = true; vps8->BackColor = Color::Gainsboro;vps9->ReadOnly = true; vps9->BackColor = Color::Gainsboro;vps10->ReadOnly = true; vps10->BackColor = Color::Gainsboro;vps12->ReadOnly = true; vps12->BackColor = Color::Gainsboro;
				time6->ReadOnly = true; time6->BackColor = Color::Gainsboro;time7->ReadOnly = true; time7->BackColor = Color::Gainsboro;time8->ReadOnly = true; time8->BackColor = Color::Gainsboro;time9->ReadOnly = true; time9->BackColor = Color::Gainsboro;time10->ReadOnly = true; time10->BackColor = Color::Gainsboro;time12->ReadOnly = true; time12->BackColor = Color::Gainsboro;
				form5Open->Visible = true;
				form5File->Visible = true;
				this->clearTables(1);
				F5Graph->Visible = true;
				this->enterData5->Text = "Process File Data";
			}
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (madeDiagram)
				tablet = gcnew FarmStrayVoltage::TabletForm();
			madeDiagram = true;
			tablet->Closed += gcnew EventHandler (this,&Form1::tablet_Close);
			if(diagramText != "")
			{
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("diagram.txt");
				sw->Write(diagramText);
				sw->Close();
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("diagram.txt");
				tablet->openDiagram(sr);
				sr->Close();
				File::Delete("diagram.txt");
			}
			tablet->ShowDialog();
		}
		private: System::Void tablet_Close(Object^ sender, EventArgs^ e)
		{
			tablet->saveBitmap(filePath + "diagram.bmp");
			diagramText = tablet->saveDiagram();
		}
		private: System::String^ readInstructions (String^ filename)
		{
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(filePath + filename);
			return (sr->ReadToEnd());
			sr->Close();

		}
		private: System::Void mainFormToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RichTextBox^ rt = gcnew RichTextBox();
			rt->Text = readInstructions ("mainInstr.txt");
			rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			rt->ReadOnly = true;
			Instructions^ instr = gcnew Instructions(rt,0);
			instr->ShowDialog();
		 }


		private: Boolean isFilled (Control^ c)
		{
			if (c->Controls->Count > 0 && c->GetType() != DataGridView::typeid && c->GetType() != ReportViewer::typeid)
				for each (Control^ d in c->Controls)				
					if (isFilled(d) == false)
						return false;
			if (c->GetType() == TextBox::typeid && c->Text->Length==0 && c->Visible == true && c->MaximumSize.Width != 3000)
				return false;
			else if (c->GetType() == MaskedTextBox::typeid && (c->Text == "  :" || c->Text == "    /  /" ))
			{
				if (c->Visible || c == this->form1DateText)			
					return false;

			}
			else if (c->GetType() == DataGridView::typeid)
			{
				DataGridView^ d = (DataGridView^) c;
				if (d->Rows->Count <= 1 || (c == dataGridView2 && d->Rows->Count <= 48) || (c == dataGridView3 && d->Rows->Count <= 48))
					return false;
			}

			return true;

		}

		private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		{
			SolidBrush^ brush = gcnew SolidBrush(Color::Red);
			Graphics^ g = this->CreateGraphics();
			int x = 0;
			double xLoc =-7.25;
			for each (bool b in completeForms)
			{
				brush->Color = Color::Red;
				if (b == true)
					brush->Color =Color::Green;
				xLoc = xLoc + (7.0 * tabControl1->TabPages[x]->Text->Length);
				g->FillEllipse(brush,Rectangle (xLoc,tabControl1->Location.Y-15,10,10));
												x++;

			}
				 
		}
		private: System::Void addListeners (Control^ c)
		{
			for each (Control^ contr in c->Controls)
			{
				if (contr->GetType() == TextBox::typeid)
				{
					TextBox^ geewhiz = (TextBox^) contr;
					geewhiz->TextChanged += gcnew EventHandler (this, &Form1::TextBoxTextChange);
				}
				if (contr->GetType() == MaskedTextBox::typeid)
				{
					MaskedTextBox^ geewhiz = (MaskedTextBox^) contr;
					geewhiz->TextChanged += gcnew EventHandler (this, &Form1::TextBoxTextChange);
				}
				else if (contr->GetType() == Button::typeid)
				{
					Button^ geewhiz = (Button^) contr;
					geewhiz->Click += gcnew EventHandler (this, &Form1::TextBoxTextChange);

				}
				else if (contr->GetType() == DataGridView::typeid)
				{
					DataGridView^ geewhiz = (DataGridView^) contr;
					geewhiz->RowsAdded += gcnew DataGridViewRowsAddedEventHandler (this, &Form1::DataRowChange);
				}
				else if (contr->Controls->Count >0)
					addListeners (contr);
			}
		}
		private: System::Void TextBoxTextChange (Object^ sender, EventArgs^ e)
		{
			Control^ c = (Control^) sender;
			if ((c->Parent) && c->Parent->GetType() == System::Windows::Forms::TabPage::typeid && this->tabControl1->TabPages->Contains((TabPage^)c->Parent))
			{
				//Form 5 and Form 1 do not belong to tabpages of tabcontrol1
				if (completeForms[tabControl1->TabPages->IndexOf((TabPage^)c->Parent)] != isFilled(c->Parent) && isFilled(c->Parent) == true)
				{
					completeForms[tabControl1->TabPages->IndexOf((TabPage^)c->Parent)] = true;
					this->Refresh();
				}	
			}
			else
				Form1::TextBoxTextChange(c->Parent, e);
		}
		private: System::Void DataRowChange (Object^ sender, DataGridViewRowsAddedEventArgs^ e)
		{
			Form1::TextBoxTextChange(sender,gcnew EventArgs());
		}


		private: System::Void openAForm (String^ filename)
		 {
			madeDiagram = false;
				diagramText = "";
				tablet = gcnew TabletForm();
				this->Farm_Stray_Voltage_Data->Clear();
				StreamReader^ sr = gcnew StreamReader(filename);
			
				//Reads all the needed variables, and then the xml file of the database
				this->utilName->Text = sr->ReadLine();
				this->utilAddress1->Text = sr->ReadLine();
				this->utilAddress2->Text = sr->ReadLine();
				this->utilPhone->Text = sr->ReadLine();
				this->utilEmail->Text = sr->ReadLine();
				this->utilWebsite->Text = sr->ReadLine();

				this->investName->Text = sr->ReadLine();
				this->investPhone->Text = sr->ReadLine();
				this->investEmail->Text = sr->ReadLine();
				this->fileNumber->Text = sr->ReadLine();
				this->investReceive->Text = sr->ReadLine();
				this->investVisit->Text = sr->ReadLine();
				this->investStart->Text = sr->ReadLine();
				this->investConclude->Text = sr->ReadLine();

				this->custName->Text = sr->ReadLine();
				this->custAddress1->Text = sr->ReadLine();
				this->custAddress2->Text = sr->ReadLine();
				this->custPhone->Text = sr->ReadLine();
				this->custEmail->Text = sr->ReadLine();

				this->farmName->Text = sr->ReadLine();
				this->farmAddress1->Text = sr->ReadLine();
				this->farmAddress2->Text = sr->ReadLine();
				this->farmPhone->Text = sr->ReadLine();
				this->farmEmail->Text = sr->ReadLine();

				int numLines = System::Convert::ToInt16 (sr->ReadLine());
				reportSummary ->Text = "";
				for (int n=0; n<numLines; n++)
					this->reportSummary->Text = reportSummary->Text + System::Environment::NewLine + sr->ReadLine();
				if (numLines>0)
					this->reportSummary->Text = this->reportSummary->Text->Remove (0,2);

				this->form1DateText->Text = sr->ReadLine();
				this->form2StartText->Text = sr->ReadLine();
				this->form2StopText->Text = sr->ReadLine();
				this->form3Date = sr->ReadLine();
				this->form5Date = sr->ReadLine();
				this->form6Start->Text = sr->ReadLine();
				this->form6Stop->Text = sr->ReadLine();
				String^ locNum = sr->ReadLine();
				String^ locNum6 = sr->ReadLine();
				this->vpri->Text = sr->ReadLine();
				this->ilbh->Text = sr->ReadLine();
				this->ilbf->Text = sr->ReadLine();
				this->vlbh->Text = sr->ReadLine(); 
				this->vlbf->Text = sr->ReadLine();
				this->ip->Text = sr->ReadLine();
				this->textBox11->Text = sr->ReadLine();
				this->textBox12->Text = sr->ReadLine();
				this->textBox14->Text = sr->ReadLine();
				this->textBox13->Text = sr->ReadLine();
				this->textBox17->Text = sr->ReadLine();
				this->textBox18->Text = sr->ReadLine();
				this->highestP2RV = Convert::ToSingle(sr->ReadLine());
				this->highestVcc = Convert::ToSingle(sr->ReadLine());
				this->form2FileText->Text = sr->ReadLine();
				form2FileName = sr->ReadLine();
				this->form3File->Text = sr->ReadLine();
				form3FileName = sr->ReadLine();
				this->form5File->Text = sr->ReadLine();
				form5FileName = sr->ReadLine();
				this->form6FileText->Text = sr->ReadLine();
				form6FileName = sr->ReadLine();

				if (sr->ReadLine()=="diagram")
				{
					tablet = gcnew TabletForm();
					tablet->openDiagram(sr);
					diagramText = "";
				}
				if (sr->ReadLine() == "diagram")
				{
					barn = gcnew InsideBarn2::DrawingSpace();
					sr = barn->openDiagram(sr);
				}
				this->cal1Text->Text = sr->ReadLine();this->cal2Text->Text = sr->ReadLine();this->cal3Text->Text = sr->ReadLine();this->cal4Text->Text = sr->ReadLine();
				this->time1->Text = sr->ReadLine();this->vcc1->Text = sr->ReadLine();this->vp1->Text = sr->ReadLine();this->vs1->Text = sr->ReadLine();this->vps1->Text = sr->ReadLine();
				this->time2->Text = sr->ReadLine();this->vcc2->Text = sr->ReadLine();this->vp2->Text = sr->ReadLine();this->vs2->Text = sr->ReadLine();this->vps2->Text = sr->ReadLine();
				this->time3->Text = sr->ReadLine();this->vcc3->Text = sr->ReadLine();this->vp3->Text = sr->ReadLine();this->vs3->Text = sr->ReadLine();this->vps3->Text = sr->ReadLine();
				this->time4->Text = sr->ReadLine();this->vcc4->Text = sr->ReadLine();this->vp4->Text = sr->ReadLine();this->vs4->Text = sr->ReadLine();this->vps4->Text = sr->ReadLine();
				this->time5->Text = sr->ReadLine();this->vcc5->Text = sr->ReadLine();this->vp5->Text = sr->ReadLine();this->vs5->Text = sr->ReadLine();this->vps5->Text = sr->ReadLine();
				this->time6->Text = sr->ReadLine();this->vcc6->Text = sr->ReadLine();this->vp6->Text = sr->ReadLine();this->vs6->Text = sr->ReadLine();this->vps6->Text = sr->ReadLine();
				this->time7->Text = sr->ReadLine();this->vcc7->Text = sr->ReadLine();this->vp7->Text = sr->ReadLine();this->vs7->Text = sr->ReadLine();this->vps7->Text = sr->ReadLine();
				this->time8->Text = sr->ReadLine();this->vcc8->Text = sr->ReadLine();this->vp8->Text = sr->ReadLine();this->vs8->Text = sr->ReadLine();this->vps8->Text = sr->ReadLine();
				this->time9->Text = sr->ReadLine();this->vcc9->Text = sr->ReadLine();this->vp9->Text = sr->ReadLine();this->vs9->Text = sr->ReadLine();this->vps9->Text = sr->ReadLine();
				this->time10->Text = sr->ReadLine();this->vcc10->Text = sr->ReadLine();this->vp10->Text = sr->ReadLine();this->vs10->Text = sr->ReadLine();this->vps10->Text = sr->ReadLine();

				this->Farm_Stray_Voltage_Data->ReadXml(sr);
				sr->Close();
				this->tabControl1->SelectedIndex = 0;
				this->Text = filename->Substring(filename->LastIndexOf('\\')+1);

				if(File::Exists(form2FileName))
					this->initializeTable(form2FileName,0);
				if (File::Exists(form6FileName))
					this->initializeTable(form6FileName,1);

				form4Fill(0);form4Fill(1);


			if (this->Farm_Stray_Voltage_Data->Form_2_Data->Rows->Count > 0)
				this->viewGraph->Enabled = true;
			if (this->Farm_Stray_Voltage_Data->Form_6_Data->Rows->Count > 0)
				this->button1->Enabled = true;
			
			locCombo->SelectedIndex = locCombo->Items->IndexOf (locNum);
			locCombo6->SelectedIndex = locCombo6->Items->IndexOf (locNum6);
		 }
		private: System::Void Form1_Resize (Object^ sender, EventArgs^ e)
	{
		this->Refresh();

	}
		private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 About^ ab = gcnew About ();
			 ab->ShowDialog();
		 }

		private: System::Void investReceive_Enter(System::Object^  sender, System::EventArgs^  e) 
{
	calendar->Visible = true;
	lastMTB = (MaskedTextBox^) sender;
}
		private: System::Void calendar_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) 
		 {
			 lastMTB->Text = e->Start.ToString("yyyy/MM/dd");
			 calendar->Visible = false;
		 }
		private: System::Void investReceive_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (calendar->Focused == false)
				 calendar->Visible = false;
		 }
		private: System::Void calendar_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			if (lastMTB->Focused == false)
				calendar->Visible = false;
		 }
		private: System::Void channel4I_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if (this->channel4I->Checked)
				{
					this->dataGridView2->Columns[2]->HeaderText = "Animal Contact Voltage Across Shunt Resistor Vcc (SVCh4 AC)";
					this->dataGridView3->Columns[2]->HeaderText = "Animal Contact Voltage Across Shunt Resistor Vcc (SVCh4 AC)";
				}

				else
				{
					this->dataGridView2->Columns[2]->HeaderText = "Animal Contact Voltage Across Shunt Resistor Vcc (SVCh5 DC)";
					this->dataGridView3->Columns[2]->HeaderText = "Animal Contact Voltage Across Shunt Resistor Vcc (SVCh5 DC)";
				}
			 }
		private: System::Void form1DateText_Enter(System::Object^  sender, System::EventArgs^  e) {
			 calendar2->Visible = true;
		 }
		private: System::Void calendar2_Leave(System::Object^  sender, System::EventArgs^  e) {
			 if (!form1DateText->Focused)
				 calendar2->Visible = false;
		 }
		private: System::Void form1DateText_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (!calendar2->Focused)
				 calendar2->Visible = false;
		 }
		private: System::Void calendar2_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {
			form1DateText->Text = e->Start.ToString("yyyy/MM/dd");
			 calendar2->Visible = false;
		 }
		private: void Export(LocalReport^ report)
    {
        String^ deviceInfo =
          "<DeviceInfo>" +
          "  <OutputFormat>EMF</OutputFormat>" + 
          "  <PageWidth>8.5in</PageWidth>" +
          "  <PageHeight>11in</PageHeight>" +
          "  <MarginTop>0.25in</MarginTop>" +
          "  <MarginLeft>0.25in</MarginLeft>" +
          "  <MarginRight>0.25in</MarginRight>" +
          "  <MarginBottom>0.25in</MarginBottom>" +
          "</DeviceInfo>";
        array<Warning^>^ warnings;
        m_streams = gcnew List<Stream^>();
		
		report->Render ("PDF", deviceInfo, gcnew CreateStreamCallback(this, &Form1::CreateStream), warnings);

        for each (Stream^ stream in m_streams)
		{stream->Position = 0;
		stream->Close();
		}
    }
		private: Stream^ CreateStream(String^ name, String^ fileNameExtension, Encoding^ encoding, String^ mimeType, bool willSeek)
    {
		
		Stream^ stream = gcnew FileStream(sfd->FileName , FileMode::Create);
        m_streams->Add(stream);
        return stream;
    }


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void vpri_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 TextBox^ tb = (TextBox^) sender;
			 if (tb->Text->Length > 0 && tb->Text[0] == '.')
			 {
				 tb->Text = "0.";
				tb->SelectionStart = 2;
			 }
			 
			 if (vpri->Text->Length > 0 && ilbf->Text->Length > 0 && vlbf->Text->Length > 0)
			 {
				 ip->Text = Math::Round((System::Convert::ToDouble(ilbf->Text) * System::Convert::ToDouble(vlbf->Text))/System::Convert::ToDouble(vpri->Text),2).ToString();

			 }
			 else 
				 ip->Text = "";
		 }
private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 TextBox^ tb = (TextBox^) sender;
			 if (tb->Text[0] == '.')
			 {
				 tb->Text = "0.";
				tb->SelectionStart = 2;
			 }

			 if (textBox11->Text->Length > 0 && textBox14->Text->Length > 0 && textBox17->Text->Length > 0)
			{
				textBox18->Text = Math::Round((System::Convert::ToDouble(textBox14->Text) * System::Convert::ToDouble(textBox17->Text))/System::Convert::ToDouble(textBox11->Text),2).ToString();
			}
			else
				textBox18->Text = "";

		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (checkBox1->Checked)
			 {
				farmName->Text = custName->Text;
				farmAddress1->Text = custAddress1->Text;
				farmAddress2->Text = custAddress2->Text;
				farmPhone->Text = custPhone->Text;
				farmEmail->Text = custEmail->Text;
			 }
			 else
			 {
				farmName->Text = "";
				farmAddress1->Text = "";
				farmAddress2->Text = "";
				farmPhone->Text = "";
				farmEmail->Text = "";
			 }
		 }

private: System::Void tabPage5_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->custNameF1->Text = custName->Text;
			 farmLocationF1->Text = farmAddress1->Text;
	
		 }

private: System::Void form1Grid_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {


			if (form1Grid->SelectedCells[0]->ColumnIndex == 0 && e->KeyCode == Keys::Delete)
			{

				for (int a = (form1Grid->SelectedCells[0]->RowIndex); a<this->Farm_Stray_Voltage_Data->Form_1_Data->Count; a++)
					this->Farm_Stray_Voltage_Data->Form_1_Data[a]["locid"] = this->Farm_Stray_Voltage_Data->Form_1_Data[a]->locId - 1;
				this->Farm_Stray_Voltage_Data->Form_1_Data->Rows->RemoveAt (form1Grid->SelectedCells[0]->RowIndex); 
			}

		 }
private: int initializeTable (int form, String ^ filename)
{
	UInt16 i1, i2, i3, i4; //The four channels of current and Channel 4 V
	float vcc, vp, vs, vps; //The four voltage readings
	Settings^ settings = gcnew Settings (filename);
	BinaryReader^ binReader = gcnew BinaryReader( File::Open( filename, FileMode::Open));
	array<Byte>^ record1 = gcnew array<Byte>(3181);
	
	array<double>^ XData0;
	array<float>^ YData0;

	if (form ==0)
	{
		XData = gcnew array<double>(settings->numRecord*4); 
		YData = gcnew array<float>(settings->numRecord*4); 
		XData0 = XData;
		YData0 = YData;
	}
	else
	{
		XData5 = gcnew array<double>(settings->numRecord*4); 
		YData5 = gcnew array<float>(settings->numRecord*4); 
		XData0 = XData5;
		YData0 = YData5;
	}
	DateTime start = settings->start;
	DateTime oldTimes = DateTime (1899, 12, 30);

	this->Form2Progress->Maximum = settings->numRecord;
	this->Form2Progress->Visible = true;
	this->Form2Progress->Value = 0;

	for (int a=0; a<256; a++)
		binReader->ReadByte();
	for (int a=0; a<settings->numRecord; a++)
	{
		for (int i=0; i<3181; i++)
			record1[i]=binReader->ReadByte();

		if (channel4I->Checked)
		{
			i4 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[364-256],record1[363-256]},0);
			vcc = getCurrent(i4, settings, 4)*cal4;
		}
		else
		{
			i4 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[351-256],record1[350-256]},0);
			vcc = getCurrent(i4, settings, 5)*cal5;
		}
		YData0[a] = vcc;

		i1 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[310-256],record1[309-256]},0);
		vp = getCurrent (i1, settings, 1)*cal1;
		YData0[a+settings->numRecord] = vp;

		i3 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[346-256],record1[345-256]},0);
		vs = getCurrent (i3, settings, 3)*cal3;
		YData0[a+settings->numRecord*2] = vs;

		i2 = System::BitConverter::ToUInt16 (gcnew array<Byte>{record1[328-256],record1[327-256]},0);
		vps = getCurrent (i2, settings, 2)*cal2;
		YData0[a+settings->numRecord*3] = vps;

		start = start.AddSeconds (settings->interval);

		XData0[a] = (start - oldTimes).TotalDays;
		XData0[a+settings->numRecord] = (start - oldTimes).TotalDays;
		XData0[a+settings->numRecord*2] = (start - oldTimes).TotalDays;
		XData0[a+settings->numRecord*3] = (start - oldTimes).TotalDays;
		this->Form2Progress->PerformStep();
	}
	binReader->Close();
	Form2Progress->Visible = false;
	return settings->numRecord;
}
private: System::Void F3Graph_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			
			VoltGraph^ vg = gcnew VoltGraph(3);
			if (sender == F3Graph && YData[0] == 10101986)			
					vg->SetNumRecord (initializeTable(0,form3FileName));
			else if ( sender == F3Graph)
				vg->SetNumRecord (YData->Length/4);
			else if (YData5[0] == 10101986)
					vg->SetNumRecord (initializeTable(1, form5FileName));
			else
				vg->SetNumRecord (YData5->Length/4);

			vg->pesgo1->PeData->Subsets = 4;
			vg->pesgo1->PeString->XAxisLabel = "Time"; //Name of the X-Axis
			vg->pesgo1->PeString->YAxisLabel = "Voltage"; //Name of the Y-Axis
			vg->pesgo1->PeString->SubsetLabels[0] = ("Vcc"); //Name of the 1st subset
			vg->pesgo1->PeString->SubsetLabels[1] = ("Vp"); //Name of the 2nd subset
			vg->pesgo1->PeString->SubsetLabels[2] = ("Vs"); //Name of the 3rd subset
			vg->pesgo1->PeString->SubsetLabels[3] = ("Vps"); //Name of the 4th subset
			vg->pesgo1->PeString->MainTitle = "Farm Stray Voltage Test"; //Name of the graph
			vg->pesgo1->PeString->SubTitle = "";
			if (sender == F3Graph)
			vg->DrawGraph (XData, YData);
			else
			vg->DrawGraph (XData5, YData5);
			Instructions^ instr = gcnew Instructions (vg, 3);
			instr->ShowDialog();
		}

private: System::Void F1NewRow (Object^ sender, DataTableNewRowEventArgs^ e)
{
	e->Row["locid"] = this->Farm_Stray_Voltage_Data->Form_1_Data->Count + 1;
}
private: System::Void barnDiagram_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			barn->ShowDialog();
		 }
		private: System::Void DiagramClosing (Object^ sender, FormClosingEventArgs^ e)
		{
			barnDiagram = barn->saveDiagram();
			barn->saveBitmap(filePath + "barnDiagram.bmp");
		}
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if( MessageBox::Show ("Save work before exiting?","Save?", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
				 this->saveFormsToolStripMenuItem_Click(this->saveFormsToolStripMenuItem, gcnew EventArgs ());
		 }
private: System::Void infoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 			 //Create a new instructions form displaying the instructions for Form 1
			 RichTextBox^ rt = gcnew RichTextBox();
			 rt->Text = readInstructions("infoInstr.txt");
			 rt->ReadOnly = true;
			 rt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Both;
			 FarmStrayVoltage::Instructions^ instr = gcnew Instructions(rt,-1);	
			 instr->ShowDialog();
		 }
private: System::Void utilName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void utilPhone_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};	
}
