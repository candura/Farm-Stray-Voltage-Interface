#pragma once


namespace FarmStrayVoltage {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TabletForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>

	
	
	public ref class PaintPanel : System::Windows::Forms::Panel
	{
	private: List<PictureBox^>^ nodes;
	public: List<Rectangle>^ rects;
	private: Bitmap^ _backBuffer;
	private: System::Drawing::Pen^ pen;  //Black pen for drawing
	private: SolidBrush^ brush;
	private: Point currPoint1;
	private: Point currPoint2;
	public: bool drawing;
	public: bool drawingR;
	private:Rectangle highRect;
	private: Rectangle currRect;
	private: int nodeIndy;
	
	protected: virtual void OnPaint (PaintEventArgs^ e) override
		   {
			   if (!_backBuffer)
            {
				_backBuffer = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
            }
			Graphics^ g = System::Drawing::Graphics::FromImage (_backBuffer);
			//Draw each line according to the recorded locations
			g->FillRectangle (brush, 0,0,_backBuffer->Width, _backBuffer->Height);
			
			for each (Rectangle rect in rects)
			{			
				if (rects->IndexOf (rect) != nodeIndy-1000)
					g->DrawRectangle (pen, rect);
				else
					g->DrawRectangle(gcnew Pen(Color::Blue), rect);

			}
			
			for (int a=0; a<nodes->Count-1; a=a+2)
			{
				if ( a != nodeIndy)
					g->DrawLine (pen,nodes[a]->Location.X+2,nodes[a]->Location.Y+2,nodes[a+1]->Location.X+2,nodes[a+1]->Location.Y+2);
				else
					g->DrawLine (gcnew System::Drawing::Pen(Color::Blue),nodes[a]->Location.X+2,nodes[a]->Location.Y+2,nodes[a+1]->Location.X+2,nodes[a+1]->Location.Y+2);
			}
			if (drawing)
				g->DrawLine (pen, currPoint1.X, currPoint1.Y,currPoint2.X,currPoint2.Y);
			if (drawingR)
				g->DrawRectangle (pen, currRect);
			delete g;
			e->Graphics->DrawImageUnscaled (_backBuffer, 0,0);
		   }
	protected: virtual void OnPaintBackground (PaintEventArgs^ e) override
		   {
			}
	public: PaintPanel ()
			{
				nodes = gcnew List<PictureBox^>(50);
				pen = gcnew Pen(Color::Black);
				brush = gcnew SolidBrush(Color::White);
				drawing = false;
				drawingR = false;
				nodeIndy = -1;
				rects = gcnew List<Rectangle>(25);
			}
	public: void setNodes (List<PictureBox^>^ points)
			{
				nodes = points;
			}
	public: void drawLine (Point p1, Point p2)
	{
		currPoint1 = p1;
		currPoint2 = p2;
	}
	public: void drawRect (Rectangle rect)
	{
		currRect = rect;
	}
	public: void nodeSelected (int numOfNode)
	{
		nodeIndy = numOfNode;
		if (nodeIndy >-1)
			nodeIndy = numOfNode - numOfNode % 2;
	}
	public: int Contains (Point p)
	{
		for each (Rectangle r in rects)
		{
			if (r.Contains(p))
			{
				nodeIndy = rects->IndexOf(r)+1000;
				this->Refresh();
				return rects->IndexOf(r);
			}
		}
		nodeIndy = -1;
		return -1;
	}
	public: System::Void KillRectangle (int index)
	{
		rects->RemoveAt (index);
		nodeIndy = -1;
		this->Refresh();
	}
	};
	
	public ref class TabletForm : public System::Windows::Forms::Form
	{
	public:
		TabletForm(void)
		{
			filePath = System::Windows::Forms::Application::ExecutablePath->Remove(System::Windows::Forms::Application::ExecutablePath->LastIndexOf('\\')+1)+"bitmap\\";
			InitializeComponent();
			rectClick = Point(0,0);
			rectangleCursor = gcnew System::Windows::Forms::Cursor (filePath + "RectangleCursor.cur");
			//Initialize all of my variables and give drawingPanel focus
			drawingLine = false;
			oldMouse = Point(0,0);
			pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
			pbs2 = gcnew List<PictureBox^>(25);
			pbs = gcnew List<PictureBox^>(10);
			pbs->Add(poleIcon);pbs->Add(meterIcon);pbs->Add(loadIcon);pbs->Add(barnIcon);pbs->Add(groundIcon);
			pbs->Add(bowlIcon);pbs->Add(wellIcon);pbs->Add(transIcon);pbs->Add(panelIcon);pbs->Add(shockerIcon);
			drawingPanel->Focus();
			nodes = gcnew List<PictureBox^>(50);
			eraser = gcnew System::Drawing::Pen(System::Drawing::Color::White);
			highlight  = gcnew System::Drawing::Pen(System::Drawing::Color::Blue);
			nodeIndy = -1;
			contactCount = 0;
			first = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TabletForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::PictureBox^  poleIcon;

	private: PaintPanel^  drawingPanel;

	private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	private: int activePB;  //Index of PB in the palette that was recently clicked
	private: int activePB2; //Index of PB in the panel that was recently clicked
	
	//PictureBoxes in the palette
	private: System::Windows::Forms::PictureBox^  meterIcon;
	private: System::Windows::Forms::PictureBox^  barnIcon;
	private: System::Windows::Forms::PictureBox^  loadIcon;
	private: System::Windows::Forms::PictureBox^  groundIcon;
	private: System::Windows::Forms::Button^  pointButton;
	private: System::Windows::Forms::Button^  lineButton;
	private: System::Windows::Forms::Button^  textButton;
	private: System::Drawing::Pen^ highlight;
 	private: System::Drawing::Pen^ eraser;
	private: System::Drawing::Pen^ pen;  //Black pen for drawing
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  saveButton;
	private: System::Windows::Forms::SaveFileDialog^  saveDialog;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: Point lineStart; //Point where the drawing line was started
	private: bool drawingLine; //If the user is currently drawing a line
	private: Point oldMouse; //Previous mouse location from last mouseMove event
	private: List<PictureBox^>^ nodes;
	private: List <PictureBox^>^ pbs; //List of PB's in the palette
	private: int nodeIndy;
	private: bool first;
	private: TextBox^ tbDrag;
	private: String^ filePath;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  newButton;
	private: List <PictureBox^>^ pbs2;//List of PB's created by user
	private: System::Windows::Forms::PictureBox^  transIcon;
	private: System::Windows::Forms::PictureBox^  shockerIcon;
	private: System::Windows::Forms::PictureBox^  wellIcon;
	private: System::Windows::Forms::PictureBox^  panelIcon;
	private: System::Windows::Forms::PictureBox^  bowlIcon;
	private: System::Windows::Forms::Button^  rectangleTool;
	private: int contactCount;
	private: TextBox^ currText;
	private: System::Windows::Forms::Cursor^ rectangleCursor;
	private: Point rectClick;
	private: System::Windows::Forms::Label^  acv;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TabletForm::typeid));
			this->poleIcon = (gcnew System::Windows::Forms::PictureBox());
			this->drawingPanel = (gcnew PaintPanel());
			this->meterIcon = (gcnew System::Windows::Forms::PictureBox());
			this->barnIcon = (gcnew System::Windows::Forms::PictureBox());
			this->loadIcon = (gcnew System::Windows::Forms::PictureBox());
			this->groundIcon = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->pointButton = (gcnew System::Windows::Forms::Button());
			this->lineButton = (gcnew System::Windows::Forms::Button());
			this->textButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->newButton = (gcnew System::Windows::Forms::Button());
			this->saveDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->transIcon = (gcnew System::Windows::Forms::PictureBox());
			this->bowlIcon = (gcnew System::Windows::Forms::PictureBox());
			this->panelIcon = (gcnew System::Windows::Forms::PictureBox());
			this->wellIcon = (gcnew System::Windows::Forms::PictureBox());
			this->shockerIcon = (gcnew System::Windows::Forms::PictureBox());
			this->rectangleTool = (gcnew System::Windows::Forms::Button());
			this->acv = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->poleIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->meterIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barnIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->loadIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->groundIcon))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->transIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bowlIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->panelIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wellIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->shockerIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// poleIcon
			// 
			this->poleIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->poleIcon->Location = System::Drawing::Point(21, 19);
			this->poleIcon->MaximumSize = System::Drawing::Size(32, 90);
			try
			{
				this->poleIcon->ImageLocation = filePath + "pole.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'pole.bmp'","File not found!");
			}
			this->poleIcon->Name = L"poleIcon";
			this->poleIcon->Size = System::Drawing::Size(28, 27);
			this->poleIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->poleIcon->TabIndex = 2;
			this->poleIcon->TabStop = false;
			this->toolTip1->SetToolTip(this->poleIcon, L"Pole");
			this->poleIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			// 
			// drawingPanel
			// 
			this->drawingPanel->AllowDrop = true;
			this->drawingPanel->BackColor = System::Drawing::Color::White;
			this->drawingPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->drawingPanel->Location = System::Drawing::Point(0, 100);
			this->drawingPanel->Name = L"drawingPanel";
			this->drawingPanel->Size = System::Drawing::Size(794, 403);
			this->drawingPanel->TabIndex = 4;
			this->drawingPanel->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &TabletForm::drawingPanel_PreviewKeyDown);
			this->drawingPanel->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &TabletForm::drawingPanel_DragOver);
			this->drawingPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::drawingPanel_MouseMove);
			this->drawingPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::drawingPanel_MouseDown);
			this->drawingPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::drawingPanel_MouseUp);
			this->drawingPanel->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &TabletForm::drawingPanel_DragEnter);
			// 
			// meterIcon
			// 
			this->meterIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->meterIcon->Location = System::Drawing::Point(64, 19);
			this->meterIcon->MaximumSize = System::Drawing::Size(28, 27);
			this->meterIcon->Name = L"meterIcon";
			try
			{
				this->meterIcon->ImageLocation = filePath + "meter.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'meter.bmp'","File not found!");
			}
			this->meterIcon->Size = System::Drawing::Size(28, 27);
			this->meterIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->meterIcon->TabIndex = 2;
			this->meterIcon->TabStop = false;
			this->toolTip1->SetToolTip(this->meterIcon, L"Meter");
			this->meterIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			// 
			// barnIcon
			// 
			this->barnIcon->BackColor = Color::Transparent;
			this->barnIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			try
			{
				this->barnIcon->ImageLocation = filePath + "barn.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'barn.bmp'","File not found!");
			}
			this->barnIcon->Location = System::Drawing::Point(107, 19);
			this->barnIcon->MaximumSize = System::Drawing::Size(116, 107);
			this->barnIcon->Name = L"barnIcon";
			this->barnIcon->Size = System::Drawing::Size(28, 27);
			this->barnIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->barnIcon->TabIndex = 2;
			this->barnIcon->TabStop = false;
			this->toolTip1->SetToolTip(this->barnIcon, L"Barn");
			this->barnIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			// 
			// loadIcon
			// 
			this->loadIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			try
			{
				this->loadIcon->ImageLocation = filePath + "loadbox.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'loadbox.bmp'","File not found!");
			}
			this->loadIcon->Location = System::Drawing::Point(150, 19);
			this->loadIcon->MaximumSize = System::Drawing::Size(28, 27);
			this->loadIcon->Name = L"loadIcon";
			this->loadIcon->Size = System::Drawing::Size(28, 27);
			this->loadIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->loadIcon->TabIndex = 2;
			this->loadIcon->TabStop = false;
			this->toolTip1->SetToolTip(this->loadIcon, L"Load Box");
			this->loadIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			// 
			// groundIcon
			// 
			this->groundIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->groundIcon->Location = System::Drawing::Point(193, 19);
			try
			{
				this->groundIcon->ImageLocation = filePath + "ground.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'ground.bmp'","File not found!");
			}
			this->groundIcon->MaximumSize = System::Drawing::Size(28, 27);
			this->groundIcon->Name = L"groundIcon";
			this->groundIcon->Size = System::Drawing::Size(28, 27);
			this->groundIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->groundIcon->TabIndex = 2;
			this->groundIcon->TabStop = false;
			this->toolTip1->SetToolTip(this->groundIcon, L"Ground Rod");
			this->groundIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			// 
			// toolTip1
			// 
			this->toolTip1->IsBalloon = true;
			this->toolTip1->ShowAlways = true;
			// 
			// pointButton
			// 
			this->pointButton->Location = System::Drawing::Point(21, 19);
			this->pointButton->Name = L"pointButton";
			try
			{
				this->pointButton->Image = gcnew Bitmap (filePath + "point.bmp");
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'point.bmp'","File not found!");
			}
			this->pointButton->Size = System::Drawing::Size(28, 27);
			this->pointButton->TabIndex = 6;
			this->toolTip1->SetToolTip(this->pointButton, L"Pointer Tool");
			this->pointButton->UseVisualStyleBackColor = true;
			this->pointButton->Click += gcnew System::EventHandler(this, &TabletForm::PointButton_Click);
			// 
			// lineButton
			// 
			try
			{
				this->lineButton->Image = gcnew Bitmap (filePath + "line.bmp");
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'line.bmp'","File not found!");
			}
			this->lineButton->Location = System::Drawing::Point(64, 19);
			this->lineButton->Name = L"lineButton";
			this->lineButton->Size = System::Drawing::Size(28, 27);
			this->lineButton->TabIndex = 6;
			this->toolTip1->SetToolTip(this->lineButton, L"Line Tool");
			this->lineButton->UseVisualStyleBackColor = true;
			this->lineButton->Click += gcnew System::EventHandler(this, &TabletForm::LineButton_Click);
			// 
			// textButton
			// 
			try
			{
				this->textButton->Image = gcnew Bitmap (filePath + "text.bmp");
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'text.bmp'","File not found!");
			}
			this->textButton->Location = System::Drawing::Point(107, 19);
			this->textButton->Name = L"textButton";
			this->textButton->Size = System::Drawing::Size(28, 27);
			this->textButton->TabIndex = 6;
			this->toolTip1->SetToolTip(this->textButton, L"Text Box Tool");
			this->textButton->UseVisualStyleBackColor = true;
			this->textButton->Click += gcnew System::EventHandler(this, &TabletForm::TextButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->saveButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->saveButton->Location = System::Drawing::Point(752, 12);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(30, 30);
			this->saveButton->TabIndex = 7;
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &TabletForm::saveButton_Click);
			this->toolTip1->SetToolTip(this->saveButton, L"Save");
			// 
			// saveDialog
			// 
			this->saveDialog->Filter = L"\"Bitmaps\"|*.bmp";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->acv);
			this->groupBox1->Controls->Add(this->barnIcon);
			this->groupBox1->Controls->Add(this->transIcon);
			this->groupBox1->Controls->Add(this->poleIcon);
			this->groupBox1->Controls->Add(this->shockerIcon);
			this->groupBox1->Controls->Add(this->wellIcon);
			this->groupBox1->Controls->Add(this->panelIcon);
			this->groupBox1->Controls->Add(this->bowlIcon);
			this->groupBox1->Controls->Add(this->meterIcon);
			this->groupBox1->Controls->Add(this->groundIcon);
			this->groupBox1->Controls->Add(this->loadIcon);
			this->groupBox1->Location = System::Drawing::Point(22, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(292, 82);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Palette";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->lineButton);
			this->groupBox2->Controls->Add(this->pointButton);
			this->groupBox2->Controls->Add(this->rectangleTool);
			this->groupBox2->Controls->Add(this->textButton);
			this->groupBox2->Location = System::Drawing::Point(331, 26);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(193, 56);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Tools";
			// 
			// newButton
			// 
			try
			{
				this->newButton->BackgroundImage = gcnew Bitmap (filePath + "newfile.bmp");
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'newfile.bmp'","File not found!");
			}
			this->newButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->newButton->Location = System::Drawing::Point(716, 12);
			this->newButton->Name = L"newButton";
			this->newButton->Size = System::Drawing::Size(30, 30);
			this->newButton->TabIndex = 7;
			this->newButton->UseVisualStyleBackColor = true;
			this->newButton->Click += gcnew System::EventHandler(this, &TabletForm::new_Diagram);
			this->toolTip1->SetToolTip(this->newButton, L"New Diagram");
			// 
			// transIcon
			// 
			this->transIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->transIcon->Location = System::Drawing::Point(20, 47);
			this->transIcon->MaximumSize = System::Drawing::Size(35, 35);
			this->transIcon->Name = L"transIcon";
			this->transIcon->Size = System::Drawing::Size(28, 27);
			this->transIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->transIcon->TabIndex = 2;
			this->transIcon->TabStop = false;
			this->transIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			try
			{
				this->transIcon->ImageLocation = filePath + "transformer.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'transformer.bmp'","File not found!");
			}
			this->toolTip1->SetToolTip(this->transIcon, L"Transformer");
			// 
			// bowlIcon
			// 
			this->bowlIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bowlIcon->Location = System::Drawing::Point(63, 47);
			this->bowlIcon->MaximumSize = System::Drawing::Size(35, 35);
			this->bowlIcon->Name = L"bowlIcon";
			this->bowlIcon->Size = System::Drawing::Size(28, 27);
			this->bowlIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bowlIcon->TabIndex = 2;
			this->bowlIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			this->bowlIcon->TabStop = false;
			try
			{
				this->bowlIcon->ImageLocation = filePath + "bowl.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'bowl.bmp'","File not found!");
			}
			this->toolTip1->SetToolTip(this->bowlIcon, L"Watering Bowl");
			// 
			// panelIcon
			// 
			this->panelIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelIcon->Location = System::Drawing::Point(106, 47);
			this->panelIcon->MaximumSize = System::Drawing::Size(35, 35);
			this->panelIcon->Name = L"panelIcon";
			this->panelIcon->Size = System::Drawing::Size(28, 27);
			this->panelIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->panelIcon->TabIndex = 2;
			this->panelIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			this->panelIcon->TabStop = false;
			try
			{
				this->panelIcon->ImageLocation = filePath + "panel.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'panel.bmp'","File not found!");
			}
			this->toolTip1->SetToolTip(this->panelIcon, L"Service Panel");
			// 
			// wellIcon
			// 
			this->wellIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->wellIcon->Location = System::Drawing::Point(149, 47);
			this->wellIcon->MaximumSize = System::Drawing::Size(35, 35);
			this->wellIcon->Name = L"wellIcon";
			this->wellIcon->Size = System::Drawing::Size(28, 27);
			this->wellIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wellIcon->TabIndex = 2;
			this->wellIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			this->wellIcon->TabStop = false;
			try
			{
				this->wellIcon->ImageLocation = filePath + "well.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'well.bmp'","File not found!");
			}
			this->toolTip1->SetToolTip(this->wellIcon, L"Well");
			// 
			// shockerIcon
			// 
			this->shockerIcon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->shockerIcon->Location = System::Drawing::Point(192, 47);
			this->shockerIcon->MaximumSize = System::Drawing::Size(35, 35);
			this->shockerIcon->Name = L"shockerIcon";
			this->shockerIcon->Size = System::Drawing::Size(28, 27);
			this->shockerIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->shockerIcon->TabIndex = 2;
			this->shockerIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TabletForm::PictureBox_MouseDown);
			this->shockerIcon->TabStop = false;
			try
			{
				this->shockerIcon->ImageLocation = filePath + "accPoint.bmp";
			}
			catch (ArgumentException^ ae)
			{
				MessageBox::Show ("Missing 'accPoint.bmp'","File not found!");
			}
			this->toolTip1->SetToolTip(this->shockerIcon, L"Cow Shocker");
			// 
			// rectangleTool
			// 
			this->rectangleTool->Location = System::Drawing::Point(150, 19);
			this->rectangleTool->Name = L"rectangleTool";
			this->rectangleTool->Size = System::Drawing::Size(28, 27);
			this->rectangleTool->TabIndex = 6;
			this->rectangleTool->UseVisualStyleBackColor = true;
			this->rectangleTool->Click += gcnew System::EventHandler (this, &TabletForm::RectClick);
			this->toolTip1->SetToolTip(this->rectangleTool, L"Rectangle Tool");
			// 
			// acv
			// 
			this->acv->AutoSize = true;
			this->acv->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->acv->Location = System::Drawing::Point(242, 33);
			this->acv->Name = L"acv";
			this->acv->Size = System::Drawing::Size(30, 16);
			this->acv->TabIndex = 3;
			this->acv->Text = L"ACV";
			this->acv->MouseDown +=	gcnew System::Windows::Forms::MouseEventHandler (this, &TabletForm::ACV_Click);
			this->toolTip1->SetToolTip(this->acv, L"Animal Contact Location");
			// 
			// TabletForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 509);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->newButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->drawingPanel);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Name = L"TabletForm";
			this->Text = L"Diagram";
			this->Load += gcnew System::EventHandler(this, &TabletForm::TabletForm_Load);
			this->Click += gcnew System::EventHandler(this, &TabletForm::Form1_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->poleIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->meterIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barnIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->loadIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->groundIcon))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	//Fired when the user clicks down on a panel-PB
	private: System::Void new_mouseDown (Object^ sender, MouseEventArgs^ e)
	{
		unselect();
		//Casts the sender as a PB and makes activePB2 the index of the sender in pbs2
		activePB2 = pbs2->IndexOf((PictureBox^)sender);	
		
		if (drawingPanel->Cursor == Cursors::Default)
		{
			pbs2[activePB2]->AllowDrop = true;
			nodeIndy = 900;
			pbs2[activePB2]->BorderStyle = BorderStyle::Fixed3D;
		}
		
		else if (drawingPanel->Cursor == Cursors::Cross && drawingLine == false)
		{
			PictureBox^ node = gcnew PictureBox();
			node->BorderStyle = BorderStyle::None;
			pbs2[activePB2]->BorderStyle = BorderStyle::FixedSingle;
			Point cp = pbs2[activePB2]->PointToClient(this->Cursor->Position);
			node->Location = Point (pbs2[activePB2]->Location.X+pbs2[activePB2]->Width-2,pbs2[activePB2]->Location.Y+pbs2[activePB2]->Height-drawingPanel->Location.Y-2);
			if (cp.X < pbs2[activePB2]->Width /2)
			{
				node->SetBounds (pbs2[activePB2]->Location.X + 2,node->Location.Y,2,2);
				node->Text = "L";
			}
			if (cp.Y < pbs2[activePB2]->Height /2)
			{
				node->SetBounds (node->Location.X,pbs2[activePB2]->Location.Y + 2 - drawingPanel->Location.Y,2,2);
				node->Text = node->Text + " T";
			}
			if (pbs2[activePB2]->Name == pbs->IndexOf(barnIcon).ToString())
				node->SetBounds (node->Location.X,pbs2[activePB2]->Location.Y - drawingPanel->Location.Y + pbs2[activePB2]->Height/2,2,2);
			node->Size = System::Drawing::Size (2,2);
			node->Show();
			node->Name = activePB2.ToString();
			drawingPanel->Controls->Add(node);
			if (pbs2[activePB2]->Anchor != AnchorStyles::Right)
			{
				pbs2[activePB2]->LocationChanged += gcnew EventHandler (this, &TabletForm::pb_LocChange);
				pbs2[activePB2]->Anchor = AnchorStyles::Right;
			}
			nodes->Add(node);
			drawingLine = true;
			drawingPanel->drawing = true;
			lineStart = Point(node->Location.X, node->Location.Y);
		}
		else if (drawingPanel->Cursor == Cursors::Cross && drawingLine == true)
		{
			PictureBox^ node = gcnew PictureBox();
			node->BorderStyle = BorderStyle::None;
			pbs2[activePB2]->BorderStyle = BorderStyle::FixedSingle;
			nodeIndy = 900;
			Point cp = pbs2[activePB2]->PointToClient(this->Cursor->Position);
			node->Location = Point (pbs2[activePB2]->Location.X+pbs2[activePB2]->Width-2,pbs2[activePB2]->Location.Y+pbs2[activePB2]->Height-drawingPanel->Location.Y-2);
			if (cp.X < pbs2[activePB2]->Width /2)
			{
				node->SetBounds (pbs2[activePB2]->Location.X + 2,node->Location.Y,2,2);
				node->Text = "L";
			}
			if (cp.Y < pbs2[activePB2]->Height /2)
			{
				node->SetBounds (node->Location.X,pbs2[activePB2]->Location.Y + 2 - drawingPanel->Location.Y,2,2);
				node->Text = node->Text + " T";
			}
			if (pbs2[activePB2]->Name == pbs->IndexOf(barnIcon).ToString())
				node->SetBounds (node->Location.X,pbs2[activePB2]->Location.Y - drawingPanel->Location.Y + pbs2[activePB2]->Height/2,2,2);
			node->Size = System::Drawing::Size (2,2);
			node->Show();
			node->Name = activePB2.ToString();
			drawingPanel->Controls->Add(node);
			if (pbs2[activePB2]->Anchor != AnchorStyles::Right)
			{
				pbs2[activePB2]->LocationChanged += gcnew EventHandler (this, &TabletForm::pb_LocChange);
				pbs2[activePB2]->Anchor = AnchorStyles::Right;
			}
			nodes[nodes->Count-1]->Visible = false;
			nodes->Add(node);
			drawingPanel->setNodes (nodes);
			drawingLine = false;
			drawingPanel->drawing = false;

		}
	}

	//Fired when the user clicks on a PB in the palette
	private: System::Void PictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{	
		unselect();
		
		if (drawingPanel->Cursor == Cursors::Default)
		{
		//Casts the sender as a PB and makes activePB2 the index of the sender in pbs2
		activePB = pbs->IndexOf((PictureBox^)sender);
			
		//Creates the new PB and initializes its variables to that of the palette PB
		PictureBox^ newpic = gcnew PictureBox();
		newpic->Image = pbs[activePB]->Image;
		newpic->Name = activePB.ToString();
		newpic->MaximumSize = pbs[activePB]->MaximumSize;
		pbs2->Add(newpic);
		activePB2 = pbs2->Count-1; //Sets activePB2 to the latest PB added (this one)
		pbs2[pbs2->Count-1]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		pbs2[pbs2->Count-1]->Width = 25; pbs2[pbs2->Count-1]->Height = 25;
		pbs2[pbs2->Count-1]->MouseDown += gcnew MouseEventHandler (this,&TabletForm::new_mouseDown);
		pbs2[pbs2->Count-1]->MouseUp += gcnew MouseEventHandler (this,&TabletForm::new_mouseUp);
		pbs2[pbs2->Count-1]->MouseEnter += gcnew EventHandler (this,&TabletForm::PicMouseOver);
		pbs2[pbs2->Count-1]->MouseMove += gcnew MouseEventHandler (this,&TabletForm::PicMouseMove);
			//pbs2[pbs2->Count-1]->GiveFeedback += gcnew System::Windows::Forms::GiveFeedbackEventHandler (this, &TabletForm::boobers);
		//Begin the dragdrop operation on the new PB
		pbs2[pbs2->Count-1]->AllowDrop = true;
			Point p;
			p = this->drawingPanel->PointToClient(this->Cursor->Position);
			this->Controls->Add(pbs2[pbs2->Count-1]);
			pbs2[pbs2->Count-1]->SetBounds(p.X-pbs2[pbs2->Count-1]->Width/2,p.Y-pbs2[pbs2->Count-1]->Height/2+drawingPanel->Location.Y,pbs2[pbs2->Count-1]->MaximumSize.Width,pbs2[pbs2->Count-1]->MaximumSize.Height);
			pbs2[pbs2->Count-1]->BringToFront();
			pbs2[pbs2->Count-1]->Visible = true;
			pbs2[pbs2->Count-1]->ForeColor = Color::Aqua;
		}
				
	}
	//Fired when the user drags a PB into drawingPanel
	private: System::Void drawingPanel_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) 
		{	
			if (e->Data->GetDataPresent(String::typeid))
			{
				e->Effect = DragDropEffects::Move;
				System::Drawing::Point p;
				p.X = e->X;
				p.Y = e->Y;
				Point clientp = drawingPanel->PointToClient(p);
				nodes[nodeIndy]->SetBounds(clientp.X+5,clientp.Y+5,nodes[nodeIndy]->Width,nodes[nodeIndy]->Height);
			}
			else if (e->Data->GetDataPresent(bool::typeid))
			{
				e->Effect = DragDropEffects::Move;
			}
		}
	//Fired when the user drags a PB over drawingPanel
	private: System::Void drawingPanel_DragOver(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) 
	{
		
		//Setting the location of PB to the mouse's location and a bit to the right (NOTE*** Must change to right on mouseLoc)
		System::Drawing::Point p;
		p.X = e->X;
		p.Y = e->Y;
		Point clientp = drawingPanel->PointToClient(p);
		if (e->Data->GetDataPresent(String::typeid))
		{
			nodes[nodeIndy]->SetBounds(clientp.X+5,clientp.Y+5,nodes[nodeIndy]->Width,nodes[nodeIndy]->Height);
		}
		else if (e->Data->GetDataPresent(bool::typeid))
		{
			e->Effect = DragDropEffects::Move;
			tbDrag->SetBounds (clientp.X+5,clientp.Y+5,tbDrag->Width,tbDrag->Height);
		}

		this->Location.X = clientp.X;
		this->Location.Y = clientp.Y;
	}
	//Fired when the user pushes down a mouse button on the drawingPanel
	private: System::Void drawingPanel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		unselect();
		//If drawingPanel has focus
		if (drawingPanel->Focused){
			

			if (nodes->Count%2 ==0 && drawingLine == false && drawingPanel->Cursor == Cursors::Default)
			for (int a=0; a<nodes->Count; a=a+2)
			{

				double slopeX = (nodes[a+1]->Location.X - nodes[a]->Location.X);
				double slopeY = (nodes[a+1]->Location.Y - nodes[a]->Location.Y);
				double slope = slopeY/slopeX;
				if (slopeX ==0)
					slope = 999999999;
				float b = nodes[a]->Location.Y - slope * nodes[a]->Location.X;

				if ((Math::Abs(e->Y - (slope * e->X + b))<5 && e->X<=Math::Max(nodes[a]->Location.X,nodes[a+1]->Location.X) && e->X >= Math::Min(nodes[a]->Location.X,nodes[a+1]->Location.X)) || (slope == 999999999 && Math::Abs(e->X-nodes[a]->Location.X)<5))
				{
					nodes[a]->Visible = true;
					nodes[a+1]->Visible = true;
					nodeIndy = a;
					drawingPanel->nodeSelected(a);
					drawingPanel->Refresh();
				}
			}				
			
			if (drawingPanel->Cursor == Cursors::Cross && nodes->Count%2 ==0)
			{
				PictureBox^ node = gcnew PictureBox();
				node->BorderStyle = BorderStyle::FixedSingle;
				node->SetBounds(e->X-2,e->Y-2,5,5);
				node->Show();
				drawingPanel->Controls->Add(node);
				node->MouseDown += gcnew MouseEventHandler (this, &TabletForm::node_MouseDown);
				node->Cursor = System::Windows::Forms::Cursors::Cross;
				node->LocationChanged += gcnew EventHandler (this, &TabletForm::node_LocChange);
				nodes->Add(node);
				drawingLine = true;
				drawingPanel->drawing = true;
				lineStart = Point(e->X,e->Y);
			}
			else if (drawingPanel->Cursor == Cursors::Cross && nodes->Count%2 !=0 && Math::Abs(e->Location.X - lineStart.X)+ Math::Abs(e->Location.Y - lineStart.Y)>5)
			{
				drawingLine = false;
				drawingPanel->drawing = false;
				PictureBox^ node = gcnew PictureBox();
				node->BorderStyle = BorderStyle::FixedSingle;
				node->SetBounds(e->X-2,e->Y-2,5,5);
				nodes->Add(node);
				drawingPanel->Controls->Add(node);
				node->MouseDown += gcnew MouseEventHandler (this, &TabletForm::node_MouseDown);
				node->LocationChanged += gcnew EventHandler (this, &TabletForm::node_LocChange);
				nodes[nodes->Count-1]->Visible = false;
				nodes[nodes->Count-2]->Visible = false;
				node->Cursor = Cursors::Hand;
				nodes[nodes->Count-2]->Cursor = System::Windows::Forms::Cursors::Hand;
				drawingPanel->setNodes (nodes);
			}
			else if (nodes->Count%2 !=0 && drawingPanel->Cursor == Cursors::Cross)
			{
				Graphics^ g = drawingPanel->CreateGraphics();
				drawingPanel->Controls->Remove(nodes[nodes->Count-1]);
				delete nodes[nodes->Count-1];
				nodes->RemoveAt(nodes->Count-1);
				drawingLine=false;
				drawingPanel->drawing = false;
				g->DrawLine(eraser,oldMouse.X,oldMouse.Y,lineStart.X,lineStart.Y);
				delete g;
			}
			else if (drawingPanel->Cursor != Cursors::Default && drawingPanel->Cursor != Cursors::Cross && drawingPanel->Cursor != rectangleCursor)
			{
				lineStart = Point(e->X,e->Y);
				drawingLine = true;
				drawingPanel->drawingR = true;
			}
			else if (drawingPanel->Cursor == rectangleCursor)
			{
				lineStart = Point (e->X, e->Y);
				drawingLine = true;
				drawingPanel->drawingR = true;

			}
			else if (drawingPanel->Cursor == Cursors::Default && drawingPanel->Contains(e->Location) > -1)
			{
				nodeIndy = 2000 + drawingPanel->Contains(e->Location);
			}
		}
		drawingPanel->Focus(); //Give drawingPanel focus
	}
	//Fired when the user moves his mouse over drawingPanel
	private: System::Void drawingPanel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			if (drawingLine == true && drawingPanel->Cursor == Cursors::Cross)
			{
				Rectangle rect = Rectangle(Math::Min(lineStart.X, oldMouse.X)-1,Math::Min(lineStart.Y, oldMouse.Y)-1,Math::Abs(lineStart.X - oldMouse.X)+2,Math::Abs(oldMouse.Y - lineStart.Y)+2);

				drawingPanel->drawLine (lineStart, e->Location);
				drawingPanel->Invalidate (rect);
				drawingPanel->Update();

			}
			else if (drawingLine == true && drawingPanel->Cursor != Cursors::Default && drawingPanel->Cursor != Cursors::Cross)
			{
				drawingPanel->drawRect(Rectangle(Math::Min (lineStart.X,e->X),Math::Min(lineStart.Y,e->Y),Math::Abs(e->X-lineStart.X),Math::Abs(e->Y-lineStart.Y)));
				drawingPanel->Invalidate ();
				drawingPanel->Update();
			}
			if (pbs2->Count > 0 && pbs2[pbs2->Count-1]->AllowDrop == true)
			{
				Point p;
				p = this->drawingPanel->PointToClient(this->Cursor->Position);				
				pbs2[pbs2->Count-1]->SetBounds(p.X-pbs2[pbs2->Count-1]->Width/2,p.Y-pbs2[pbs2->Count-1]->Height/2+drawingPanel->Location.Y,pbs2[pbs2->Count-1]->MaximumSize.Width,pbs2[pbs2->Count-1]->MaximumSize.Height);

			}
			else if (activePB2 < pbs2->Count && pbs2[activePB2]->AllowDrop == true)
			{
				Point p;
				p = this->drawingPanel->PointToClient(this->Cursor->Position);				
				pbs2[activePB2]->SetBounds(p.X-pbs2[activePB2]->Width/2,p.Y-pbs2[activePB2]->Height/2+drawingPanel->Location.Y,pbs2[activePB2]->MaximumSize.Width,pbs2[activePB2]->MaximumSize.Height);

			}
			 oldMouse = e->Location;
		 }
	//Fired when the mouseButton is released over drawingPanel
	private: System::Void drawingPanel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			
			if (drawingLine && drawingPanel->Cursor == rectangleCursor)
			{
				drawingLine = false;
				drawingPanel->drawingR = false;
				Rectangle r = Rectangle (Math::Min (lineStart.X, e->X), Math::Min (lineStart.Y, e->Y), Math::Abs(e->X-lineStart.X),Math::Abs(e->Y-lineStart.Y));
				drawingPanel->rects->Add (r);
			}
			else if (drawingLine && drawingPanel->Cursor != Cursors::Default && drawingPanel->Cursor != Cursors::Cross)
			{		
				//Initialize new textBox with size as size of dragged rectangle, add listeners, and give it focus
				TextBox^ tb = gcnew TextBox();
				tb->Multiline = true;
				tb->SetBounds(Math::Min (lineStart.X,e->X),Math::Min(lineStart.Y,e->Y),Math::Abs(e->X-lineStart.X),Math::Abs(e->Y-lineStart.Y));
				if (tb->Height < 18)
					tb->Height = 18;
				if (tb->Width < 70)			
					tb->Width = 70;

				drawingPanel->Controls->Add(tb);
				tb->BringToFront();
				tb->Show();
				tb->Focus();
				tb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler (this,&TabletForm::tb_KeyDown);
				tb->LostFocus += gcnew EventHandler (this,&TabletForm::tb_LostFocus);
				tb->MouseEnter += gcnew EventHandler (this, &TabletForm::tb_mouseEnter);
				tb->MouseDown += gcnew MouseEventHandler (this, &TabletForm::tb_mouseDown);
				drawingLine = false;
				drawingPanel->drawingR = false;
			}
		}
	//Fired when the user presses a key in a dynamically created textBox
	private: System::Void tb_KeyDown (Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			//If the user pressed 'Escape', cast the sender as a textBox and delete it
			if(e->KeyCode == Keys::Escape)
			{
				drawingPanel->Controls->Remove((TextBox^)sender);
				delete ((TextBox^)sender);
			}
		}
	//Fired when a textBox has lost focus
	private: System::Void tb_LostFocus (Object^ sender, EventArgs^ e)
	{
		//Create a new textbox with the cast of the sender
		TextBox^ tb = (TextBox^) sender;
		//Delete the border and the rectangle around it
		tb->BorderStyle = BorderStyle::None;
		Graphics^ g=drawingPanel->CreateGraphics();
		g->DrawRectangle(eraser,Rectangle(tb->Location,tb->Size));
		int maxWidth = 0;
		tb->Height = 0;
		for each (String^ line in tb->Lines)
		{
			if (line->Length > maxWidth)
			{
				tb->Width = line->Length * 7;
				maxWidth = line->Length;
			}
			tb->Height = tb->Height + 14;
		}
		delete g;
		
	}

	//Fired when the user presses a key on the panel
	private: System::Void drawingPanel_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) 
	{
		//If the user is drawing a line and presses 'Escape', cancel the current draw action and erase the line
		if (e->KeyCode == Keys::Escape && drawingLine == true)
		{
			drawingLine = false;
			Graphics^ g = drawingPanel->CreateGraphics();
			delete g;
			drawingPanel->Controls->Remove (nodes[nodes->Count-1]);
			delete nodes[nodes->Count-1];
			nodes->RemoveAt(nodes->Count-1);
			drawingPanel->Refresh();
		}
		if (e->KeyCode == Keys::Delete && nodeIndy != -1 && nodeIndy < 900)
		{
			Graphics^ g = drawingPanel->CreateGraphics();
			nodeIndy = nodeIndy - nodeIndy%2;
			
			g->DrawLine(eraser,nodes[nodeIndy]->Location.X+2,nodes[nodeIndy]->Location.Y+2,nodes[nodeIndy+1]->Location.X+2,nodes[nodeIndy+1]->Location.Y+2);
				delete(nodes[nodeIndy]);
				this->Controls->Remove(nodes[nodeIndy]);

				delete(nodes[nodeIndy+1]);
				this->Controls->Remove(nodes[nodeIndy+1]);

			nodes->Remove(nodes[nodeIndy]);nodes->Remove(nodes[nodeIndy]);
			nodeIndy=-1;

			delete g;
		}
		else if (e->KeyCode == Keys::Delete && nodeIndy == 900)
		{
			
			for each (PictureBox^ node in nodes)
			{
				if (node->Name == activePB2.ToString())
					node->Name = (-1).ToString();
			}
			
			
			this->Controls->Remove(pbs2[activePB2]);
			delete pbs2[activePB2];
			pbs2->RemoveAt(activePB2);
			nodeIndy = -1;
		}
		else if (e->KeyCode == Keys::Delete && nodeIndy == 1000)
		{
			for each (Control^ tb in drawingPanel->Controls)
				if (tb->GetType() == TextBox::typeid && tb->ForeColor == Color::Blue)
				{
					if (tb->AllowDrop)
					{
						this->contactCount --;
						drawingPanel->Controls->Remove(tb);
						for each (Control^ tt in drawingPanel->Controls)
							if (tt->GetType() == TextBox::typeid && tt->AllowDrop)
								if (System::Convert::ToInt16 (tt->Text) > System::Convert::ToInt16(tb->Text))
									tt->Text = (System::Convert::ToInt16(tt->Text) - 1).ToString();
					}

					drawingPanel->Controls->Remove(tb);
					delete tb;
				}
		}
		else if (e->KeyCode == Keys::Delete && nodeIndy >= 2000)
		{
			drawingPanel->KillRectangle(nodeIndy - 2000);
			nodeIndy = -1;
		}

	}
	//Used to return the save string to the main form
	public: System::String^ saveDiagram ()
	{
		List<PictureBox^>^ pbs3 = gcnew List<PictureBox^>(pbs2->Count);
		pbs3->InsertRange(0,pbs2);
		for each (PictureBox^ pb in pbs2)
			if (pb->Location.Y < drawingPanel->Location.Y)
			{
				this->Controls->Remove(pb);	
				pbs3->Remove(pb);
				delete pb;
			}
		pbs2 = pbs3;
		String^ save; //String with specific format to send to main form
		TextBox^ tb = gcnew TextBox();
		save = nodes->Count.ToString(); //Begins with the number of lines
		
		//For each point in lines, convert it to a string and concat it to save
		for (int a=0; a<nodes->Count; a++){
			save = String::Concat(save,System::Environment::NewLine,nodes[a]->Location.X,",",nodes[a]->Location.Y);
		if (nodes[a]->Name->Length ==0)
			nodes[a]->Name = (-1).ToString();
		save = String::Concat(save,System::Environment::NewLine,nodes[a]->Name);}

		//Concatenate the number of panel-PB's to save
		save = String::Concat (save,System::Environment::NewLine,pbs2->Count);
		
		//For each panel-PB, concatenate its location and number (saved in name, it is the index of pbs that the panel-PB is a copy of)
		for (int a=0; a<pbs2->Count; a++)
			save = String::Concat(save,System::Environment::NewLine,pbs2[a]->Name,System::Environment::NewLine,pbs2[a]->Location.X,",",pbs2[a]->Location.Y);
	
		//Concatenate the number of textBoxes in drawingPanel to save
		save = String::Concat(save,System::Environment::NewLine,drawingPanel->Controls->Count - nodes->Count);
		
		//For each control, if it is a textbox, concat its location, size, and text
		for each (Control^ c in drawingPanel->Controls)
			if (c->GetType() == tb->GetType())
			{
				String^ text="";
				tb = (TextBox^) c; 
				save = String::Concat(save,System::Environment::NewLine,tb->Location.X,",",tb->Location.Y,System::Environment::NewLine,tb->Width,",",tb->Height,System::Environment::NewLine, tb->AllowDrop.ToString());
				
				//Modify the newline character to become *cr* so that its text will be on one line in the save file
				text = tb->Text->Replace(System::Environment::NewLine,"*cr*");
				save = String::Concat(save,System::Environment::NewLine,text);
			}
			save = String::Concat(save,System::Environment::NewLine, drawingPanel->rects->Count, System::Environment::NewLine);

		for each (Rectangle rect in drawingPanel->rects)
		{
			save = String::Concat (save, rect.Location.X,",",rect.Location.Y,System::Environment::NewLine,rect.Width, ",",rect.Height, System::Environment::NewLine);
		}

		return save;
	}
	//Accepts a streamReader as a parameter and reads in a diagram
	public: System::Void openDiagram (System::IO::StreamReader^ sr)
			{
			int num = Convert::ToInt32(sr->ReadLine());//Number of lines
			nodes->Clear();
			//For each line, read in the two points (have to dodge around the comma), and add it to lines
			for (int a=0; a<num; a++)
			{
				Point pt = Point(0,0);
				String^ next = sr->ReadLine();
				pt.X = Convert::ToInt32(next->Substring(0,next->IndexOf(",")));
				pt.Y = Convert::ToInt32(next->Substring(next->IndexOf(",")+1));
				PictureBox^ node = gcnew PictureBox();
				node->SetBounds(pt.X,pt.Y,5,5);
				node->BorderStyle = BorderStyle::FixedSingle;
				drawingPanel->Controls->Add (node);
				node->Visible = false;
				node->MouseDown += gcnew MouseEventHandler (this, &TabletForm::node_MouseDown);
				node->Cursor = Cursors::Hand;
				node->Name = sr->ReadLine();
				if (System::Convert::ToInt16(node->Name)<0)
					node->LocationChanged += gcnew EventHandler (this, &TabletForm::node_LocChange);

				nodes->Add(node);
			}

			num = Convert::ToInt32(sr->ReadLine());//Number of panel-PB's
			pbs2->Clear();
			
			//For each PB; create a new PB, read in its location and active number, set variables, and add listeners
			for (int a=0; a<num; a++)
			{
				int active = Convert::ToInt32(sr->ReadLine());
				PictureBox^ poop = gcnew PictureBox();
				poop->ImageLocation =  pbs[active]->ImageLocation;
				poop->BringToFront();
				String^ next = sr->ReadLine();
				poop->SetBounds(Convert::ToInt32(next->Substring(0,next->IndexOf(","))),Convert::ToInt32(next->Substring(next->IndexOf(",")+1)),
				pbs[active]->MaximumSize.Width,pbs[active]->MaximumSize.Height);
				poop->Name = active.ToString();
				poop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				poop->MouseDown += gcnew MouseEventHandler (this,&TabletForm::new_mouseDown);
				poop->MouseMove += gcnew MouseEventHandler (this,&TabletForm::PicMouseMove);
				poop->MouseUp += gcnew MouseEventHandler (this,&TabletForm::new_mouseUp);
				poop->LocationChanged += gcnew EventHandler (this,&TabletForm::pb_LocChange);
				poop->Anchor = AnchorStyles::Right;
				poop->MouseEnter += gcnew EventHandler (this, &TabletForm::PicMouseOver);

				pbs2->Add(poop);
				this->Controls->Add(pbs2[a]);
			}

			num = Convert::ToInt32(sr->ReadLine()); //Number of textboxes
			
			//For each textBox; create a new textBox, read in (location, size, and text), set variables, and change *cr* to newline
			for (int a=0; a<num; a++)
			{
				TextBox^ tb = gcnew TextBox;
				String^ next = sr->ReadLine();
				String^ size = sr->ReadLine();

				tb->Multiline = true;
				tb->SetBounds (Convert::ToInt32(next->Substring(0,next->IndexOf(","))),Convert::ToInt32(next->Substring(next->IndexOf(",")+1)),
				Convert::ToInt32(size->Substring(0,size->IndexOf(","))),Convert::ToInt32(size->Substring(size->IndexOf(",")+1)));
				

				if (sr->ReadLine() == "False")
				{
				tb->Text = sr->ReadLine()->Replace("*cr*",System::Environment::NewLine);
				tb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler (this,&TabletForm::tb_KeyDown);
				tb->LostFocus += gcnew EventHandler (this,&TabletForm::tb_LostFocus);
				tb->BorderStyle = BorderStyle::None;

				}
				else 
				{
					tb->Text = sr->ReadLine();
					tb->ForeColor = Color::Red;
					tb->TextAlign = HorizontalAlignment::Center;
					tb->AllowDrop = true;
					tb->BorderStyle = BorderStyle::FixedSingle;
				}
				tb->MouseDown += gcnew MouseEventHandler (this, &TabletForm::tb_mouseDown);
				tb->MouseEnter += gcnew EventHandler (this, &TabletForm::tb_mouseEnter);
				drawingPanel->Controls->Add(tb);
				tb->BringToFront();
				tb->Show();
			}

			num = Convert::ToInt32(sr->ReadLine()); //Number of rectangles
			for (int a=0; a<num; a++)
			{
				String^ next = sr->ReadLine();
				String^ size = sr->ReadLine();
				
				Rectangle rect = Rectangle (Convert::ToInt32(next->Substring(0,next->IndexOf(","))),Convert::ToInt32(next->Substring(next->IndexOf(",")+1)),
				Convert::ToInt32(size->Substring(0,size->IndexOf(","))),Convert::ToInt32(size->Substring(size->IndexOf(",")+1)));

				drawingPanel->rects->Add (rect);
			}


			drawingPanel->setNodes (nodes);
			drawingPanel->SendToBack();
			drawingPanel->Refresh();
			drawingPanel->Focus();
		}
	//Fired when the user clicks on the form
	private: System::Void Form1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Give focus to drawingPanel (used to keep from having to click on the panel twice to begin drawing)
		drawingPanel->Focus();
		unselect();
	}
	private: System::Void TabletForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->ActiveControl = drawingPanel;

		 }
	public: System::Void saveBitmap (String^ filename)
		{
			unselect();
			drawingPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->BringToFront();
			//Rectangle of the screen to be copied
			System::Drawing::Rectangle^ rc = gcnew System::Drawing::Rectangle (Point(0,0), this->drawingPanel->Size);
			//The image to be copied to
			System::Drawing::Bitmap^ i2 = gcnew Bitmap(rc->Width, rc->Height);
			System::Drawing::Graphics^ g2;
			for each (PictureBox^ pb in pbs2)
			{
			pb->LocationChanged -= gcnew EventHandler (this, &TabletForm::pb_LocChange);
			 drawingPanel->Controls->Add (pb);
			 pb->Location = Point (pb->Location.X, pb->Location.Y - 100);
			}
			drawingPanel->DrawToBitmap (i2, *rc);
			g2 = System::Drawing::Graphics::FromImage(i2);

			for each (PictureBox^ pb in pbs2)
			{
			this->Controls->Add (pb);
			 pb->Location = Point (pb->Location.X, pb->Location.Y + 100);
			 pb->BringToFront();
			 pb->LocationChanged += gcnew EventHandler (this, &TabletForm::pb_LocChange);
			}

			//Save the file and refresh the report
			i2->Save(filename);
			drawingPanel->BorderStyle = System::Windows::Forms::BorderStyle::None;

	
		}


	private: System::Void node_MouseDown (Object^ sender, MouseEventArgs^ e)
	{
		if (drawingPanel->Cursor == Cursors::Default)
		{
		nodeIndy = nodes->IndexOf((PictureBox^)sender);
		if (nodeIndy % 2 ==0)
		{
			lineStart = Point(nodes[nodeIndy+1]->Location.X+2,nodes[nodeIndy+1]->Location.Y+2);
			oldMouse = Point(nodes[nodeIndy]->Location.X+2,nodes[nodeIndy]->Location.Y+2);		
		}
		else
		{
			lineStart = Point(nodes[nodeIndy-1]->Location.X+2,nodes[nodeIndy-1]->Location.Y+2);
			oldMouse = Point(nodes[nodeIndy]->Location.X+2,nodes[nodeIndy]->Location.Y+2);
		}
		drawingPanel->nodeSelected (nodeIndy);
		nodes[nodeIndy]->MouseUp += gcnew MouseEventHandler (this, &TabletForm::Node_MouseUp);
		nodes[nodeIndy]->MouseMove += gcnew MouseEventHandler (this, &TabletForm::Node_MouseMove);
		}
	}
	private: System::Void node_LocChange (Object^ sender, EventArgs^ e)
	{
		drawingPanel->setNodes(nodes);
		drawingPanel->Invalidate();
		drawingPanel->Update();
		oldMouse = Point (nodes[nodeIndy]->Location.X+2,nodes[nodeIndy]->Location.Y+2);
	}
	private: void unselect ()
	{
		Graphics^ g = drawingPanel->CreateGraphics();
		if (nodeIndy != -1 && nodeIndy < 900 && nodes->Count > nodeIndy && nodes[nodeIndy])
		{
			nodeIndy = nodeIndy - nodeIndy%2;			
			g->DrawLine(pen,nodes[nodeIndy+1]->Location.X+2,nodes[nodeIndy+1]->Location.Y+2,nodes[nodeIndy]->Location.X+2,nodes[nodeIndy]->Location.Y+2);
			if (nodes[nodeIndy]->Width<10)
				nodes[nodeIndy]->Visible = false;
			if (nodes[nodeIndy+1]->Width < 10)
				nodes[nodeIndy+1]->Visible = false;
		}
		for each (PictureBox^ pb in pbs2)
			pb->BorderStyle = BorderStyle::None;

		for each (Control^ tb in drawingPanel->Controls)
			if (tb->GetType() == TextBox::typeid)
			{
				if (tb->AllowDrop == false)
					tb->ForeColor = Color::Black;
				else
					tb->ForeColor = Color::Red;
			}
		nodeIndy = -1;
		drawingPanel->nodeSelected (-1);
		drawingPanel->Refresh();
			delete g;
	}
	private: System::Void PointButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		drawingPanel->Cursor = Cursors::Default;
		drawingLine = false;
		this->Cursor = Cursors::Default;
		drawingPanel->Focus();
		unselect();
		if (nodes->Count %2 != 0)
		{
			drawingPanel->Controls->Remove(nodes[nodes->Count-1]);
			delete nodes[nodes->Count-1];
			nodes->RemoveAt(nodes->Count-1);
			drawingLine=false;
			drawingPanel->drawLine (Point(0,0),Point(0,0));
			drawingPanel->Refresh();
		}
	}
	private: System::Void LineButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		drawingPanel->Cursor = Cursors::Cross;
		this->Cursor = Cursors::Cross;
		drawingLine = false;
		drawingPanel->Focus();
		unselect();
		if (nodes->Count %2 != 0)
		{
			drawingPanel->Controls->Remove(nodes[nodes->Count-1]);
			delete nodes[nodes->Count-1];
			nodes->RemoveAt(nodes->Count-1);
			drawingLine=false;
			drawingPanel->drawLine (Point(0,0),Point(0,0));
			drawingPanel->Refresh();
		}
	}
	private: System::Void TextButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		drawingPanel->Cursor = gcnew System::Windows::Forms::Cursor(filePath + "text.cur");
		this->Cursor = gcnew System::Windows::Forms::Cursor(filePath + "text.cur");
		drawingPanel->Focus();
		unselect();
		if (nodes->Count %2 != 0)
		{
			drawingPanel->Controls->Remove(nodes[nodes->Count-1]);
			delete nodes[nodes->Count-1];
			nodes->RemoveAt(nodes->Count-1);
			drawingLine=false;
			drawingPanel->drawLine (Point(0,0),Point(0,0));
			drawingPanel->Refresh();
		}
	}

	private: System::Void PicMouseOver (Object^ sender, EventArgs^ e)
{
	PictureBox^ pb = (PictureBox^) sender;
	pb->Cursor = drawingPanel->Cursor;
}

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			
		{
			this->saveBitmap (saveDialog->FileName);
		}
	}
	private: System::Void pb_LocChange (Object^ sender, EventArgs^ e)
{
	PictureBox^ pb = (PictureBox^) sender;
	for each (PictureBox^ node in nodes)
	{
		if (node->Name == pbs2->IndexOf(pb).ToString())
		{
			nodeIndy = nodes->IndexOf(node);
			
			if (nodeIndy %2 == 0)
				lineStart = nodes[nodeIndy+1]->Location;
			else
				lineStart = nodes[nodeIndy-1]->Location;

			if (node->Text->Contains ("L"))
				node->SetBounds (pbs2[activePB2]->Location.X+2,node->Location.Y,2,2);
			else 
				node->SetBounds (pbs2[activePB2]->Location.X-2+pbs2[activePB2]->Width,node->Location.Y,2,2);
			if (node->Text->Contains ("T"))
				node->SetBounds(node->Location.X, pbs2[activePB2]->Location.Y - drawingPanel->Location.Y + 2,2,2);
			else
				node->SetBounds(node->Location.X, pbs2[activePB2]->Location.Y - drawingPanel->Location.Y - 2 + pbs2[activePB2]->Height,2,2);
			if (pbs2[activePB2]->Name == pbs->IndexOf(barnIcon).ToString())
				node->SetBounds (node->Location.X,pbs2[activePB2]->Location.Y - drawingPanel->Location.Y + pbs2[activePB2]->Height/2,2,2);
			drawingPanel->Refresh();

		}
	}
	nodeIndy = 900;
}

	private: System::Void tb_mouseEnter (Object^ sender, EventArgs^ e)
	{
		TextBox^ tb =  (TextBox^) sender;
		if (drawingPanel->Cursor == Cursors::Default || drawingPanel->Cursor == Cursors::Cross)
		{
			tb->Cursor = drawingPanel->Cursor;
			drawingPanel->Focus();
		}
		else
			tb->Cursor = Cursors::IBeam;

	}
	private: System::Void tb_mouseDown (Object^ sender, MouseEventArgs^ e)
	{
		unselect();
		if (drawingPanel->Cursor == Cursors::Default)
		{
			TextBox^ tb = (TextBox^) sender;
			tbDrag = (TextBox^) sender;
			tb->ForeColor = Color::Blue;
			nodeIndy = 1000;
			tbDrag->DoDragDrop(true,DragDropEffects::Move);
			drawingPanel->Focus();
		}
	}


private: System::Void PicMouseMove (Object^ sender, MouseEventArgs^ e)
		{
			if (activePB2 < pbs2->Count && pbs2[activePB2]->AllowDrop == true && ((pbs2[activePB2]->Height/2 < this->drawingPanel->PointToClient(this->Cursor->Position).Y && this->drawingPanel->PointToClient(this->Cursor->Position).Y < this->Height) || pbs2[activePB2]->ForeColor == Color::Aqua))
			{
				Point p;
				p = this->drawingPanel->PointToClient(this->Cursor->Position);
				pbs2[activePB2]->Location = Point(p.X-pbs2[activePB2]->Width/2,p.Y-pbs2[activePB2]->Height/2+drawingPanel->Location.Y);
				
			}
		}
private: System::Void new_mouseUp (Object^ sender, MouseEventArgs^ e)
		{						
			if (this->Cursor == Cursors::Default)
			{
			pbs2[activePB2]->AllowDrop = false;
			pbs2[activePB2]->BorderStyle = BorderStyle::FixedSingle;
			
			if (pbs2[activePB2]->ForeColor == Color::Aqua && pbs2[activePB2]->Location.Y < drawingPanel->Location.Y  || pbs2[activePB2]->Location.Y > this->Height)
			{
				this->Controls->Remove (pbs2[activePB2]);
				delete pbs2[activePB2];
				pbs2->RemoveAt(activePB2);
			}
			else
				pbs2[activePB2]->ForeColor = Color::White;
			}
			

		 }
private: System::Void new_Diagram (Object^ sender, EventArgs^ e)
{
	this->drawingPanel->Controls->Clear();

	nodes->Clear();
	for each (PictureBox^ pb in pbs2)
	{
		this->Controls->Remove (pb);
		delete pb;
	}
	drawingPanel->drawing = false;
	pbs2->Clear();
	this->Refresh();
}

private: System::Void Node_MouseMove (Object^ sender, MouseEventArgs^ e)
		 {
				Point p;
				p = this->drawingPanel->PointToClient(this->Cursor->Position);
				nodes[nodeIndy]->Location = Point(p.X-nodes[nodeIndy]->Width/2,p.Y-nodes[nodeIndy]->Height/2);
		 }
private: System::Void Node_MouseUp (Object^ sender, MouseEventArgs^ e)
				  {
					nodes[nodeIndy]->MouseMove -= gcnew MouseEventHandler (this, &TabletForm::Node_MouseMove);
					nodes[nodeIndy]->MouseUp -= gcnew MouseEventHandler (this, &TabletForm::Node_MouseUp);
					drawingPanel->nodeSelected (-1);
				  }
private: System::Void RectClick (Object^ sender, EventArgs^ e)
		 {
			 drawingPanel->Cursor = rectangleCursor;
			 drawingPanel->Focus();
			 unselect();

		if (nodes->Count %2 != 0)
		{
			drawingPanel->Controls->Remove(nodes[nodes->Count-1]);
			delete nodes[nodes->Count-1];
			nodes->RemoveAt(nodes->Count-1);
			drawingLine=false;
			drawingPanel->drawLine (Point(0,0),Point(0,0));
			drawingPanel->Refresh();
		}
	}
private: System::Void ACV_Click (Object^ sender, MouseEventArgs^ e)
		 {
			TextBox^ tb = gcnew TextBox();
			contactCount++;
			tb->Text = contactCount.ToString();
			tb->BorderStyle = BorderStyle::FixedSingle;
			tb->Size = System::Drawing::Size(20,15);
			tb->ForeColor = Color::Red;
			tb->TextAlign = HorizontalAlignment::Center;
			tb->AllowDrop = true;
			Point p = this->PointToClient(this->Cursor->Position);
			tb->Location = Point (p.X - 10, p.Y - 10);
			tb->MaxLength = 2;
			tb->Show();
			currText = tb;
			this->Controls->Add(tb);
			tb->Cursor = Cursors::Default;
			tb->BringToFront();
			tb->MouseMove += gcnew MouseEventHandler (this, &TabletForm::TB_MouseMove);
			tb->MouseDown += gcnew MouseEventHandler (this, &TabletForm::TB_MouseDown);
			tb->MouseEnter += gcnew EventHandler (this, &TabletForm::tb_mouseEnter);
			drawingPanel->MouseMove += gcnew MouseEventHandler (this, &TabletForm::Draw_MouseMove);
		 }
private: System::Void TB_MouseMove (Object^ sender, MouseEventArgs^ e)
		{
			TextBox^ tb = (TextBox^) sender;
			Point p = this->PointToClient(this->Cursor->Position);
			tb->Location = Point (p.X - 7, p.Y - 7);
		}
private: System::Void TB_MouseDown (Object^ sender, MouseEventArgs^ e)
		{
			TextBox^ tb = (TextBox^) sender;
			tb->MouseMove -= gcnew MouseEventHandler (this, &TabletForm::TB_MouseMove);
			tb->MouseDown -= gcnew MouseEventHandler (this, &TabletForm::TB_MouseDown);
			tb->Cursor = Cursors::IBeam;
			drawingPanel->Controls->Add(tb);
			tb->Location = Point (tb->Location.X, tb->Location.Y - 100);
			drawingPanel->MouseMove -= gcnew MouseEventHandler (this, &TabletForm::Draw_MouseMove);
			tb->MouseEnter += gcnew EventHandler (this, &TabletForm::tb_mouseEnter);
				tb->MouseDown += gcnew MouseEventHandler (this, &TabletForm::tb_mouseDown);
		}
private: System::Void Draw_MouseMove (Object^ sender, MouseEventArgs^ e)
		{
			
			Point p = this->PointToClient(this->Cursor->Position);
			currText->Location = Point (p.X - 7, p.Y - 7);
		}
};	
}