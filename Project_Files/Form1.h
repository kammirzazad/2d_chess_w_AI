namespace FINALPROJECT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
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

		static int time=600;

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  B2;
	protected: 
	private: System::Windows::Forms::Button^  D2;
	private: System::Windows::Forms::Button^  F2;
	private: System::Windows::Forms::Button^  H2;
	private: System::Windows::Forms::Button^  G3;
	private: System::Windows::Forms::Button^  E3;
	private: System::Windows::Forms::Button^  C3;
	private: System::Windows::Forms::Button^  A3;
	private: System::Windows::Forms::Button^  A5;
	private: System::Windows::Forms::Button^  B4;
	private: System::Windows::Forms::Button^  D4;
	private: System::Windows::Forms::Button^  F4;
	private: System::Windows::Forms::Button^  H4;
	private: System::Windows::Forms::Button^  G5;
	private: System::Windows::Forms::Button^  E5;
	private: System::Windows::Forms::Button^  C5;
	private: System::Windows::Forms::Button^  B6;
	private: System::Windows::Forms::Button^  D6;
	private: System::Windows::Forms::Button^  F6;
	private: System::Windows::Forms::Button^  H8;
	private: System::Windows::Forms::Button^  G8;
	private: System::Windows::Forms::Button^  F8;
	private: System::Windows::Forms::Button^  E8;
	private: System::Windows::Forms::Button^  D8;
	private: System::Windows::Forms::Button^  C8;
	private: System::Windows::Forms::Button^  B8;
	private: System::Windows::Forms::Button^  A8;
	private: System::Windows::Forms::Button^  H7;
	private: System::Windows::Forms::Button^  F7;
	private: System::Windows::Forms::Button^  C7;
	private: System::Windows::Forms::Button^  D7;
	private: System::Windows::Forms::Button^  A7;
	private: System::Windows::Forms::Button^  E7;
	private: System::Windows::Forms::Button^  G7;
	private: System::Windows::Forms::Button^  H6;
	private: System::Windows::Forms::Button^  B7;
	private: System::Windows::Forms::Button^  A6;
	private: System::Windows::Forms::Button^  C6;
	private: System::Windows::Forms::Button^  E6;
	private: System::Windows::Forms::Button^  G6;
	private: System::Windows::Forms::Button^  H5;
	private: System::Windows::Forms::Button^  F5;
	private: System::Windows::Forms::Button^  D5;
	private: System::Windows::Forms::Button^  B5;
	private: System::Windows::Forms::Button^  A4;
	private: System::Windows::Forms::Button^  C4;
	private: System::Windows::Forms::Button^  E4;
	private: System::Windows::Forms::Button^  G4;
	private: System::Windows::Forms::Button^  H3;
	private: System::Windows::Forms::Button^  B3;
	private: System::Windows::Forms::Button^  D3;
	private: System::Windows::Forms::Button^  F3;
	private: System::Windows::Forms::Button^  A2;
	private: System::Windows::Forms::Button^  C2;
	private: System::Windows::Forms::Button^  E2;
	private: System::Windows::Forms::Button^  G2;
	private: System::Windows::Forms::Button^  H1;
	private: System::Windows::Forms::Button^  G1;
	private: System::Windows::Forms::Button^  F1;
	private: System::Windows::Forms::Button^  E1;
	private: System::Windows::Forms::Button^  D1;
	private: System::Windows::Forms::Button^  C1;
	private: System::Windows::Forms::Button^  B1;
	private: System::Windows::Forms::Button^  A1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::SaveFileDialog^  SaveFile;

	private: System::Windows::Forms::OpenFileDialog^  OpenFile;

	private: System::Windows::Forms::Button^  B_Rook;
	private: System::Windows::Forms::Button^  B_Queen;
	private: System::Windows::Forms::Button^  B_Knight;
	private: System::Windows::Forms::Button^  B_Bishop;
	private: System::Windows::Forms::Button^  Black_Lost_1;
































private: System::Windows::Forms::Button^  Black_Lost_6;

private: System::Windows::Forms::Button^  Black_Lost_2;
private: System::Windows::Forms::Button^  Black_Lost_7;
private: System::Windows::Forms::Button^  Black_Lost_8;



private: System::Windows::Forms::Button^  Black_Lost_3;
private: System::Windows::Forms::Button^  Black_Lost_9;


private: System::Windows::Forms::Button^  Black_Lost_4;
private: System::Windows::Forms::Button^  Black_Lost_11;
private: System::Windows::Forms::Button^  Black_Lost_12;
private: System::Windows::Forms::Button^  Black_Lost_14;




private: System::Windows::Forms::Button^  Black_Lost_13;

private: System::Windows::Forms::Button^  Black_Lost_5;
private: System::Windows::Forms::Button^  Black_Lost_10;
private: System::Windows::Forms::Button^  Black_Lost_15;
private: System::Windows::Forms::Button^  White_Lost_5;
private: System::Windows::Forms::Button^  White_Lost_10;
private: System::Windows::Forms::Button^  White_Lost_15;






private: System::Windows::Forms::Button^  White_Lost_3;
private: System::Windows::Forms::Button^  White_Lost_4;


private: System::Windows::Forms::Button^  White_Lost_2;

private: System::Windows::Forms::Button^  White_Lost_1;
private: System::Windows::Forms::Button^  White_Lost_14;


private: System::Windows::Forms::Button^  White_Lost_9;
private: System::Windows::Forms::Button^  White_Lost_13;


private: System::Windows::Forms::Button^  White_Lost_8;

private: System::Windows::Forms::Button^  White_Lost_7;
private: System::Windows::Forms::Button^  White_Lost_12;


private: System::Windows::Forms::Button^  White_Lost_6;
private: System::Windows::Forms::Button^  White_Lost_11;
private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Button^  button2;



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->B2 = (gcnew System::Windows::Forms::Button());
			this->D2 = (gcnew System::Windows::Forms::Button());
			this->F2 = (gcnew System::Windows::Forms::Button());
			this->H2 = (gcnew System::Windows::Forms::Button());
			this->G3 = (gcnew System::Windows::Forms::Button());
			this->E3 = (gcnew System::Windows::Forms::Button());
			this->C3 = (gcnew System::Windows::Forms::Button());
			this->A3 = (gcnew System::Windows::Forms::Button());
			this->A5 = (gcnew System::Windows::Forms::Button());
			this->B4 = (gcnew System::Windows::Forms::Button());
			this->D4 = (gcnew System::Windows::Forms::Button());
			this->F4 = (gcnew System::Windows::Forms::Button());
			this->H4 = (gcnew System::Windows::Forms::Button());
			this->G5 = (gcnew System::Windows::Forms::Button());
			this->E5 = (gcnew System::Windows::Forms::Button());
			this->C5 = (gcnew System::Windows::Forms::Button());
			this->B6 = (gcnew System::Windows::Forms::Button());
			this->D6 = (gcnew System::Windows::Forms::Button());
			this->F6 = (gcnew System::Windows::Forms::Button());
			this->H8 = (gcnew System::Windows::Forms::Button());
			this->G8 = (gcnew System::Windows::Forms::Button());
			this->F8 = (gcnew System::Windows::Forms::Button());
			this->E8 = (gcnew System::Windows::Forms::Button());
			this->D8 = (gcnew System::Windows::Forms::Button());
			this->C8 = (gcnew System::Windows::Forms::Button());
			this->B8 = (gcnew System::Windows::Forms::Button());
			this->A8 = (gcnew System::Windows::Forms::Button());
			this->H7 = (gcnew System::Windows::Forms::Button());
			this->F7 = (gcnew System::Windows::Forms::Button());
			this->C7 = (gcnew System::Windows::Forms::Button());
			this->D7 = (gcnew System::Windows::Forms::Button());
			this->A7 = (gcnew System::Windows::Forms::Button());
			this->E7 = (gcnew System::Windows::Forms::Button());
			this->G7 = (gcnew System::Windows::Forms::Button());
			this->H6 = (gcnew System::Windows::Forms::Button());
			this->B7 = (gcnew System::Windows::Forms::Button());
			this->A6 = (gcnew System::Windows::Forms::Button());
			this->C6 = (gcnew System::Windows::Forms::Button());
			this->E6 = (gcnew System::Windows::Forms::Button());
			this->G6 = (gcnew System::Windows::Forms::Button());
			this->H5 = (gcnew System::Windows::Forms::Button());
			this->F5 = (gcnew System::Windows::Forms::Button());
			this->D5 = (gcnew System::Windows::Forms::Button());
			this->B5 = (gcnew System::Windows::Forms::Button());
			this->A4 = (gcnew System::Windows::Forms::Button());
			this->C4 = (gcnew System::Windows::Forms::Button());
			this->E4 = (gcnew System::Windows::Forms::Button());
			this->G4 = (gcnew System::Windows::Forms::Button());
			this->H3 = (gcnew System::Windows::Forms::Button());
			this->B3 = (gcnew System::Windows::Forms::Button());
			this->D3 = (gcnew System::Windows::Forms::Button());
			this->F3 = (gcnew System::Windows::Forms::Button());
			this->A2 = (gcnew System::Windows::Forms::Button());
			this->C2 = (gcnew System::Windows::Forms::Button());
			this->E2 = (gcnew System::Windows::Forms::Button());
			this->G2 = (gcnew System::Windows::Forms::Button());
			this->H1 = (gcnew System::Windows::Forms::Button());
			this->G1 = (gcnew System::Windows::Forms::Button());
			this->F1 = (gcnew System::Windows::Forms::Button());
			this->E1 = (gcnew System::Windows::Forms::Button());
			this->D1 = (gcnew System::Windows::Forms::Button());
			this->C1 = (gcnew System::Windows::Forms::Button());
			this->B1 = (gcnew System::Windows::Forms::Button());
			this->A1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->SaveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->OpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->B_Rook = (gcnew System::Windows::Forms::Button());
			this->B_Queen = (gcnew System::Windows::Forms::Button());
			this->B_Knight = (gcnew System::Windows::Forms::Button());
			this->B_Bishop = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_1 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_6 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_2 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_7 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_8 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_3 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_9 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_4 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_11 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_12 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_14 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_13 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_5 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_10 = (gcnew System::Windows::Forms::Button());
			this->Black_Lost_15 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_5 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_10 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_15 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_3 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_4 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_2 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_1 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_14 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_9 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_13 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_8 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_7 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_12 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_6 = (gcnew System::Windows::Forms::Button());
			this->White_Lost_11 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// B2
			// 
			this->B2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->B2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B2.BackgroundImage")));
			this->B2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B2->Location = System::Drawing::Point(76, 422);
			this->B2->Name = L"B2";
			this->B2->Size = System::Drawing::Size(64, 64);
			this->B2->TabIndex = 274;
			this->B2->UseVisualStyleBackColor = false;
			this->B2->Click += gcnew System::EventHandler(this, &Form1::B2_Click);
			// 
			// D2
			// 
			this->D2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->D2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D2.BackgroundImage")));
			this->D2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D2->Location = System::Drawing::Point(204, 422);
			this->D2->Name = L"D2";
			this->D2->Size = System::Drawing::Size(64, 64);
			this->D2->TabIndex = 273;
			this->D2->UseVisualStyleBackColor = false;
			this->D2->Click += gcnew System::EventHandler(this, &Form1::D2_Click);
			// 
			// F2
			// 
			this->F2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->F2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"F2.BackgroundImage")));
			this->F2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F2->Location = System::Drawing::Point(332, 422);
			this->F2->Name = L"F2";
			this->F2->Size = System::Drawing::Size(64, 64);
			this->F2->TabIndex = 272;
			this->F2->UseVisualStyleBackColor = false;
			this->F2->Click += gcnew System::EventHandler(this, &Form1::F2_Click);
			// 
			// H2
			// 
			this->H2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->H2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"H2.BackgroundImage")));
			this->H2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H2->Location = System::Drawing::Point(460, 422);
			this->H2->Name = L"H2";
			this->H2->Size = System::Drawing::Size(64, 64);
			this->H2->TabIndex = 271;
			this->H2->UseVisualStyleBackColor = false;
			this->H2->Click += gcnew System::EventHandler(this, &Form1::H2_Click);
			// 
			// G3
			// 
			this->G3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->G3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G3->Location = System::Drawing::Point(396, 358);
			this->G3->Name = L"G3";
			this->G3->Size = System::Drawing::Size(64, 64);
			this->G3->TabIndex = 270;
			this->G3->UseVisualStyleBackColor = false;
			this->G3->Click += gcnew System::EventHandler(this, &Form1::G3_Click);
			// 
			// E3
			// 
			this->E3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->E3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E3->Location = System::Drawing::Point(268, 358);
			this->E3->Name = L"E3";
			this->E3->Size = System::Drawing::Size(64, 64);
			this->E3->TabIndex = 269;
			this->E3->UseVisualStyleBackColor = false;
			this->E3->Click += gcnew System::EventHandler(this, &Form1::E3_Click);
			// 
			// C3
			// 
			this->C3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->C3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C3->Location = System::Drawing::Point(140, 358);
			this->C3->Name = L"C3";
			this->C3->Size = System::Drawing::Size(64, 64);
			this->C3->TabIndex = 268;
			this->C3->UseVisualStyleBackColor = false;
			this->C3->Click += gcnew System::EventHandler(this, &Form1::C3_Click);
			// 
			// A3
			// 
			this->A3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->A3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A3->Location = System::Drawing::Point(12, 358);
			this->A3->Name = L"A3";
			this->A3->Size = System::Drawing::Size(64, 64);
			this->A3->TabIndex = 267;
			this->A3->UseVisualStyleBackColor = false;
			this->A3->Click += gcnew System::EventHandler(this, &Form1::A3_Click);
			// 
			// A5
			// 
			this->A5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->A5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A5->Location = System::Drawing::Point(12, 230);
			this->A5->Name = L"A5";
			this->A5->Size = System::Drawing::Size(64, 64);
			this->A5->TabIndex = 266;
			this->A5->UseVisualStyleBackColor = false;
			this->A5->Click += gcnew System::EventHandler(this, &Form1::A5_Click);
			// 
			// B4
			// 
			this->B4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->B4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B4->Location = System::Drawing::Point(76, 294);
			this->B4->Name = L"B4";
			this->B4->Size = System::Drawing::Size(64, 64);
			this->B4->TabIndex = 265;
			this->B4->UseVisualStyleBackColor = false;
			this->B4->Click += gcnew System::EventHandler(this, &Form1::B4_Click);
			// 
			// D4
			// 
			this->D4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->D4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D4->Location = System::Drawing::Point(204, 294);
			this->D4->Name = L"D4";
			this->D4->Size = System::Drawing::Size(64, 64);
			this->D4->TabIndex = 264;
			this->D4->UseVisualStyleBackColor = false;
			this->D4->Click += gcnew System::EventHandler(this, &Form1::D4_Click);
			// 
			// F4
			// 
			this->F4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->F4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F4->Location = System::Drawing::Point(332, 294);
			this->F4->Name = L"F4";
			this->F4->Size = System::Drawing::Size(64, 64);
			this->F4->TabIndex = 263;
			this->F4->UseVisualStyleBackColor = false;
			this->F4->Click += gcnew System::EventHandler(this, &Form1::F4_Click);
			// 
			// H4
			// 
			this->H4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->H4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H4->Location = System::Drawing::Point(460, 294);
			this->H4->Name = L"H4";
			this->H4->Size = System::Drawing::Size(64, 64);
			this->H4->TabIndex = 262;
			this->H4->UseVisualStyleBackColor = false;
			this->H4->Click += gcnew System::EventHandler(this, &Form1::H4_Click);
			// 
			// G5
			// 
			this->G5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->G5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G5->Location = System::Drawing::Point(396, 230);
			this->G5->Name = L"G5";
			this->G5->Size = System::Drawing::Size(64, 64);
			this->G5->TabIndex = 261;
			this->G5->UseVisualStyleBackColor = false;
			this->G5->Click += gcnew System::EventHandler(this, &Form1::G5_Click);
			// 
			// E5
			// 
			this->E5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->E5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E5->Location = System::Drawing::Point(268, 230);
			this->E5->Name = L"E5";
			this->E5->Size = System::Drawing::Size(64, 64);
			this->E5->TabIndex = 260;
			this->E5->UseVisualStyleBackColor = false;
			this->E5->Click += gcnew System::EventHandler(this, &Form1::E5_Click);
			// 
			// C5
			// 
			this->C5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->C5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C5->Location = System::Drawing::Point(140, 230);
			this->C5->Name = L"C5";
			this->C5->Size = System::Drawing::Size(64, 64);
			this->C5->TabIndex = 259;
			this->C5->UseVisualStyleBackColor = false;
			this->C5->Click += gcnew System::EventHandler(this, &Form1::C5_Click);
			// 
			// B6
			// 
			this->B6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->B6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B6->Location = System::Drawing::Point(76, 166);
			this->B6->Name = L"B6";
			this->B6->Size = System::Drawing::Size(64, 64);
			this->B6->TabIndex = 258;
			this->B6->UseVisualStyleBackColor = false;
			this->B6->Click += gcnew System::EventHandler(this, &Form1::B6_Click);
			// 
			// D6
			// 
			this->D6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->D6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D6->Location = System::Drawing::Point(204, 166);
			this->D6->Name = L"D6";
			this->D6->Size = System::Drawing::Size(64, 64);
			this->D6->TabIndex = 257;
			this->D6->UseVisualStyleBackColor = false;
			this->D6->Click += gcnew System::EventHandler(this, &Form1::D6_Click);
			// 
			// F6
			// 
			this->F6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->F6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F6->Location = System::Drawing::Point(332, 166);
			this->F6->Name = L"F6";
			this->F6->Size = System::Drawing::Size(64, 64);
			this->F6->TabIndex = 256;
			this->F6->UseVisualStyleBackColor = false;
			this->F6->Click += gcnew System::EventHandler(this, &Form1::F6_Click);
			// 
			// H8
			// 
			this->H8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->H8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"H8.BackgroundImage")));
			this->H8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H8->Location = System::Drawing::Point(460, 38);
			this->H8->Name = L"H8";
			this->H8->Size = System::Drawing::Size(64, 64);
			this->H8->TabIndex = 255;
			this->H8->UseVisualStyleBackColor = false;
			this->H8->Click += gcnew System::EventHandler(this, &Form1::H8_Click);
			// 
			// G8
			// 
			this->G8->BackColor = System::Drawing::Color::White;
			this->G8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"G8.BackgroundImage")));
			this->G8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G8->Location = System::Drawing::Point(396, 38);
			this->G8->Name = L"G8";
			this->G8->Size = System::Drawing::Size(64, 64);
			this->G8->TabIndex = 254;
			this->G8->UseVisualStyleBackColor = false;
			this->G8->Click += gcnew System::EventHandler(this, &Form1::G8_Click);
			// 
			// F8
			// 
			this->F8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->F8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"F8.BackgroundImage")));
			this->F8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F8->Location = System::Drawing::Point(332, 38);
			this->F8->Name = L"F8";
			this->F8->Size = System::Drawing::Size(64, 64);
			this->F8->TabIndex = 253;
			this->F8->UseVisualStyleBackColor = false;
			this->F8->Click += gcnew System::EventHandler(this, &Form1::F8_Click);
			// 
			// E8
			// 
			this->E8->BackColor = System::Drawing::Color::White;
			this->E8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E8.BackgroundImage")));
			this->E8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E8->Location = System::Drawing::Point(268, 38);
			this->E8->Name = L"E8";
			this->E8->Size = System::Drawing::Size(64, 64);
			this->E8->TabIndex = 252;
			this->E8->UseVisualStyleBackColor = false;
			this->E8->Click += gcnew System::EventHandler(this, &Form1::E8_Click);
			// 
			// D8
			// 
			this->D8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->D8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D8.BackgroundImage")));
			this->D8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D8->Location = System::Drawing::Point(204, 38);
			this->D8->Name = L"D8";
			this->D8->Size = System::Drawing::Size(64, 64);
			this->D8->TabIndex = 251;
			this->D8->UseVisualStyleBackColor = false;
			this->D8->Click += gcnew System::EventHandler(this, &Form1::D8_Click);
			// 
			// C8
			// 
			this->C8->BackColor = System::Drawing::Color::White;
			this->C8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C8.BackgroundImage")));
			this->C8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C8->Location = System::Drawing::Point(140, 38);
			this->C8->Name = L"C8";
			this->C8->Size = System::Drawing::Size(64, 64);
			this->C8->TabIndex = 250;
			this->C8->UseVisualStyleBackColor = false;
			this->C8->Click += gcnew System::EventHandler(this, &Form1::C8_Click);
			// 
			// B8
			// 
			this->B8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->B8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B8.BackgroundImage")));
			this->B8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B8->Location = System::Drawing::Point(76, 38);
			this->B8->Name = L"B8";
			this->B8->Size = System::Drawing::Size(64, 64);
			this->B8->TabIndex = 249;
			this->B8->UseVisualStyleBackColor = false;
			this->B8->Click += gcnew System::EventHandler(this, &Form1::B8_Click);
			// 
			// A8
			// 
			this->A8->BackColor = System::Drawing::Color::White;
			this->A8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A8.BackgroundImage")));
			this->A8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A8->Location = System::Drawing::Point(12, 38);
			this->A8->Name = L"A8";
			this->A8->Size = System::Drawing::Size(64, 64);
			this->A8->TabIndex = 248;
			this->A8->UseVisualStyleBackColor = false;
			this->A8->Click += gcnew System::EventHandler(this, &Form1::A8_Click);
			// 
			// H7
			// 
			this->H7->BackColor = System::Drawing::Color::White;
			this->H7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"H7.BackgroundImage")));
			this->H7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H7->Location = System::Drawing::Point(460, 102);
			this->H7->Name = L"H7";
			this->H7->Size = System::Drawing::Size(64, 64);
			this->H7->TabIndex = 247;
			this->H7->UseVisualStyleBackColor = false;
			this->H7->Click += gcnew System::EventHandler(this, &Form1::H7_Click);
			// 
			// F7
			// 
			this->F7->BackColor = System::Drawing::Color::White;
			this->F7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"F7.BackgroundImage")));
			this->F7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F7->Location = System::Drawing::Point(332, 102);
			this->F7->Name = L"F7";
			this->F7->Size = System::Drawing::Size(64, 64);
			this->F7->TabIndex = 246;
			this->F7->UseVisualStyleBackColor = false;
			this->F7->Click += gcnew System::EventHandler(this, &Form1::F7_Click);
			// 
			// C7
			// 
			this->C7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->C7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C7.BackgroundImage")));
			this->C7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C7->Location = System::Drawing::Point(140, 102);
			this->C7->Name = L"C7";
			this->C7->Size = System::Drawing::Size(64, 64);
			this->C7->TabIndex = 245;
			this->C7->UseVisualStyleBackColor = false;
			this->C7->Click += gcnew System::EventHandler(this, &Form1::C7_Click);
			// 
			// D7
			// 
			this->D7->BackColor = System::Drawing::Color::White;
			this->D7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D7.BackgroundImage")));
			this->D7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D7->Location = System::Drawing::Point(204, 102);
			this->D7->Name = L"D7";
			this->D7->Size = System::Drawing::Size(64, 64);
			this->D7->TabIndex = 244;
			this->D7->UseVisualStyleBackColor = false;
			this->D7->Click += gcnew System::EventHandler(this, &Form1::D7_Click);
			// 
			// A7
			// 
			this->A7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->A7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A7.BackgroundImage")));
			this->A7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A7->Location = System::Drawing::Point(12, 102);
			this->A7->Name = L"A7";
			this->A7->Size = System::Drawing::Size(64, 64);
			this->A7->TabIndex = 243;
			this->A7->UseVisualStyleBackColor = false;
			this->A7->Click += gcnew System::EventHandler(this, &Form1::A7_Click);
			// 
			// E7
			// 
			this->E7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->E7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E7.BackgroundImage")));
			this->E7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E7->Location = System::Drawing::Point(268, 102);
			this->E7->Name = L"E7";
			this->E7->Size = System::Drawing::Size(64, 64);
			this->E7->TabIndex = 242;
			this->E7->UseVisualStyleBackColor = false;
			this->E7->Click += gcnew System::EventHandler(this, &Form1::E7_Click);
			// 
			// G7
			// 
			this->G7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->G7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"G7.BackgroundImage")));
			this->G7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G7->Location = System::Drawing::Point(396, 102);
			this->G7->Name = L"G7";
			this->G7->Size = System::Drawing::Size(64, 64);
			this->G7->TabIndex = 241;
			this->G7->UseVisualStyleBackColor = false;
			this->G7->Click += gcnew System::EventHandler(this, &Form1::G7_Click);
			// 
			// H6
			// 
			this->H6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->H6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H6->Location = System::Drawing::Point(460, 166);
			this->H6->Name = L"H6";
			this->H6->Size = System::Drawing::Size(64, 64);
			this->H6->TabIndex = 240;
			this->H6->UseVisualStyleBackColor = false;
			this->H6->Click += gcnew System::EventHandler(this, &Form1::H6_Click);
			// 
			// B7
			// 
			this->B7->BackColor = System::Drawing::Color::White;
			this->B7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B7.BackgroundImage")));
			this->B7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B7->Location = System::Drawing::Point(76, 102);
			this->B7->Name = L"B7";
			this->B7->Size = System::Drawing::Size(64, 64);
			this->B7->TabIndex = 239;
			this->B7->UseVisualStyleBackColor = false;
			this->B7->Click += gcnew System::EventHandler(this, &Form1::B7_Click);
			// 
			// A6
			// 
			this->A6->BackColor = System::Drawing::Color::White;
			this->A6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A6->Location = System::Drawing::Point(12, 166);
			this->A6->Name = L"A6";
			this->A6->Size = System::Drawing::Size(64, 64);
			this->A6->TabIndex = 238;
			this->A6->UseVisualStyleBackColor = false;
			this->A6->Click += gcnew System::EventHandler(this, &Form1::A6_Click);
			// 
			// C6
			// 
			this->C6->BackColor = System::Drawing::Color::White;
			this->C6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C6->Location = System::Drawing::Point(140, 166);
			this->C6->Name = L"C6";
			this->C6->Size = System::Drawing::Size(64, 64);
			this->C6->TabIndex = 237;
			this->C6->UseVisualStyleBackColor = false;
			this->C6->Click += gcnew System::EventHandler(this, &Form1::C6_Click);
			// 
			// E6
			// 
			this->E6->BackColor = System::Drawing::Color::White;
			this->E6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E6->Location = System::Drawing::Point(268, 166);
			this->E6->Name = L"E6";
			this->E6->Size = System::Drawing::Size(64, 64);
			this->E6->TabIndex = 236;
			this->E6->UseVisualStyleBackColor = false;
			this->E6->Click += gcnew System::EventHandler(this, &Form1::E6_Click);
			// 
			// G6
			// 
			this->G6->BackColor = System::Drawing::Color::White;
			this->G6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G6->Location = System::Drawing::Point(396, 166);
			this->G6->Name = L"G6";
			this->G6->Size = System::Drawing::Size(64, 64);
			this->G6->TabIndex = 235;
			this->G6->UseVisualStyleBackColor = false;
			this->G6->Click += gcnew System::EventHandler(this, &Form1::G6_Click);
			// 
			// H5
			// 
			this->H5->BackColor = System::Drawing::Color::White;
			this->H5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H5->Location = System::Drawing::Point(460, 230);
			this->H5->Name = L"H5";
			this->H5->Size = System::Drawing::Size(64, 64);
			this->H5->TabIndex = 234;
			this->H5->UseVisualStyleBackColor = false;
			this->H5->Click += gcnew System::EventHandler(this, &Form1::H5_Click);
			// 
			// F5
			// 
			this->F5->BackColor = System::Drawing::Color::White;
			this->F5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F5->Location = System::Drawing::Point(332, 230);
			this->F5->Name = L"F5";
			this->F5->Size = System::Drawing::Size(64, 64);
			this->F5->TabIndex = 233;
			this->F5->UseVisualStyleBackColor = false;
			this->F5->Click += gcnew System::EventHandler(this, &Form1::F5_Click);
			// 
			// D5
			// 
			this->D5->BackColor = System::Drawing::Color::White;
			this->D5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D5->Location = System::Drawing::Point(204, 230);
			this->D5->Name = L"D5";
			this->D5->Size = System::Drawing::Size(64, 64);
			this->D5->TabIndex = 232;
			this->D5->UseVisualStyleBackColor = false;
			this->D5->Click += gcnew System::EventHandler(this, &Form1::D5_Click);
			// 
			// B5
			// 
			this->B5->BackColor = System::Drawing::Color::White;
			this->B5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B5->Location = System::Drawing::Point(76, 230);
			this->B5->Name = L"B5";
			this->B5->Size = System::Drawing::Size(64, 64);
			this->B5->TabIndex = 231;
			this->B5->UseVisualStyleBackColor = false;
			this->B5->Click += gcnew System::EventHandler(this, &Form1::B5_Click);
			// 
			// A4
			// 
			this->A4->BackColor = System::Drawing::Color::White;
			this->A4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A4->Location = System::Drawing::Point(12, 294);
			this->A4->Name = L"A4";
			this->A4->Size = System::Drawing::Size(64, 64);
			this->A4->TabIndex = 230;
			this->A4->UseVisualStyleBackColor = false;
			this->A4->Click += gcnew System::EventHandler(this, &Form1::A4_Click);
			// 
			// C4
			// 
			this->C4->BackColor = System::Drawing::Color::White;
			this->C4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C4->Location = System::Drawing::Point(140, 294);
			this->C4->Name = L"C4";
			this->C4->Size = System::Drawing::Size(64, 64);
			this->C4->TabIndex = 229;
			this->C4->UseVisualStyleBackColor = false;
			this->C4->Click += gcnew System::EventHandler(this, &Form1::C4_Click);
			// 
			// E4
			// 
			this->E4->BackColor = System::Drawing::Color::White;
			this->E4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E4->Location = System::Drawing::Point(268, 294);
			this->E4->Name = L"E4";
			this->E4->Size = System::Drawing::Size(64, 64);
			this->E4->TabIndex = 228;
			this->E4->UseVisualStyleBackColor = false;
			this->E4->Click += gcnew System::EventHandler(this, &Form1::E4_Click);
			// 
			// G4
			// 
			this->G4->BackColor = System::Drawing::Color::White;
			this->G4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G4->Location = System::Drawing::Point(396, 294);
			this->G4->Name = L"G4";
			this->G4->Size = System::Drawing::Size(64, 64);
			this->G4->TabIndex = 227;
			this->G4->UseVisualStyleBackColor = false;
			this->G4->Click += gcnew System::EventHandler(this, &Form1::G4_Click);
			// 
			// H3
			// 
			this->H3->BackColor = System::Drawing::Color::White;
			this->H3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H3->Location = System::Drawing::Point(460, 358);
			this->H3->Name = L"H3";
			this->H3->Size = System::Drawing::Size(64, 64);
			this->H3->TabIndex = 226;
			this->H3->UseVisualStyleBackColor = false;
			this->H3->Click += gcnew System::EventHandler(this, &Form1::H3_Click);
			// 
			// B3
			// 
			this->B3->BackColor = System::Drawing::Color::White;
			this->B3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B3->Location = System::Drawing::Point(76, 358);
			this->B3->Name = L"B3";
			this->B3->Size = System::Drawing::Size(64, 64);
			this->B3->TabIndex = 225;
			this->B3->UseVisualStyleBackColor = false;
			this->B3->Click += gcnew System::EventHandler(this, &Form1::B3_Click);
			// 
			// D3
			// 
			this->D3->BackColor = System::Drawing::Color::White;
			this->D3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D3->Location = System::Drawing::Point(204, 358);
			this->D3->Name = L"D3";
			this->D3->Size = System::Drawing::Size(64, 64);
			this->D3->TabIndex = 224;
			this->D3->UseVisualStyleBackColor = false;
			this->D3->Click += gcnew System::EventHandler(this, &Form1::D3_Click);
			// 
			// F3
			// 
			this->F3->BackColor = System::Drawing::Color::White;
			this->F3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F3->Location = System::Drawing::Point(332, 358);
			this->F3->Name = L"F3";
			this->F3->Size = System::Drawing::Size(64, 64);
			this->F3->TabIndex = 223;
			this->F3->UseVisualStyleBackColor = false;
			this->F3->Click += gcnew System::EventHandler(this, &Form1::F3_Click);
			// 
			// A2
			// 
			this->A2->BackColor = System::Drawing::Color::White;
			this->A2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A2.BackgroundImage")));
			this->A2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A2->Location = System::Drawing::Point(12, 422);
			this->A2->Name = L"A2";
			this->A2->Size = System::Drawing::Size(64, 64);
			this->A2->TabIndex = 222;
			this->A2->UseVisualStyleBackColor = false;
			this->A2->Click += gcnew System::EventHandler(this, &Form1::A2_Click);
			// 
			// C2
			// 
			this->C2->BackColor = System::Drawing::Color::White;
			this->C2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C2.BackgroundImage")));
			this->C2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C2->Location = System::Drawing::Point(140, 422);
			this->C2->Name = L"C2";
			this->C2->Size = System::Drawing::Size(64, 64);
			this->C2->TabIndex = 221;
			this->C2->UseVisualStyleBackColor = false;
			this->C2->Click += gcnew System::EventHandler(this, &Form1::C2_Click);
			// 
			// E2
			// 
			this->E2->BackColor = System::Drawing::Color::White;
			this->E2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E2.BackgroundImage")));
			this->E2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E2->Location = System::Drawing::Point(268, 422);
			this->E2->Name = L"E2";
			this->E2->Size = System::Drawing::Size(64, 64);
			this->E2->TabIndex = 220;
			this->E2->UseVisualStyleBackColor = false;
			this->E2->Click += gcnew System::EventHandler(this, &Form1::E2_Click);
			// 
			// G2
			// 
			this->G2->BackColor = System::Drawing::Color::White;
			this->G2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"G2.BackgroundImage")));
			this->G2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G2->Location = System::Drawing::Point(396, 422);
			this->G2->Name = L"G2";
			this->G2->Size = System::Drawing::Size(64, 64);
			this->G2->TabIndex = 219;
			this->G2->UseVisualStyleBackColor = false;
			this->G2->Click += gcnew System::EventHandler(this, &Form1::G2_Click);
			// 
			// H1
			// 
			this->H1->BackColor = System::Drawing::Color::White;
			this->H1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"H1.BackgroundImage")));
			this->H1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->H1->Location = System::Drawing::Point(460, 486);
			this->H1->Name = L"H1";
			this->H1->Size = System::Drawing::Size(64, 64);
			this->H1->TabIndex = 218;
			this->H1->UseVisualStyleBackColor = false;
			this->H1->Click += gcnew System::EventHandler(this, &Form1::H1_Click);
			// 
			// G1
			// 
			this->G1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->G1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"G1.BackgroundImage")));
			this->G1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->G1->Location = System::Drawing::Point(396, 486);
			this->G1->Name = L"G1";
			this->G1->Size = System::Drawing::Size(64, 64);
			this->G1->TabIndex = 217;
			this->G1->UseVisualStyleBackColor = false;
			this->G1->Click += gcnew System::EventHandler(this, &Form1::G1_Click);
			// 
			// F1
			// 
			this->F1->BackColor = System::Drawing::Color::White;
			this->F1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"F1.BackgroundImage")));
			this->F1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->F1->Location = System::Drawing::Point(332, 486);
			this->F1->Name = L"F1";
			this->F1->Size = System::Drawing::Size(64, 64);
			this->F1->TabIndex = 216;
			this->F1->UseVisualStyleBackColor = false;
			this->F1->Click += gcnew System::EventHandler(this, &Form1::F1_Click);
			// 
			// E1
			// 
			this->E1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->E1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"E1.BackgroundImage")));
			this->E1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->E1->Location = System::Drawing::Point(268, 486);
			this->E1->Name = L"E1";
			this->E1->Size = System::Drawing::Size(64, 64);
			this->E1->TabIndex = 215;
			this->E1->UseVisualStyleBackColor = false;
			this->E1->Click += gcnew System::EventHandler(this, &Form1::E1_Click);
			// 
			// D1
			// 
			this->D1->BackColor = System::Drawing::Color::White;
			this->D1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"D1.BackgroundImage")));
			this->D1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->D1->Location = System::Drawing::Point(204, 486);
			this->D1->Name = L"D1";
			this->D1->Size = System::Drawing::Size(64, 64);
			this->D1->TabIndex = 214;
			this->D1->UseVisualStyleBackColor = false;
			this->D1->Click += gcnew System::EventHandler(this, &Form1::D1_Click);
			// 
			// C1
			// 
			this->C1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->C1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"C1.BackgroundImage")));
			this->C1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->C1->Location = System::Drawing::Point(140, 486);
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(64, 64);
			this->C1->TabIndex = 213;
			this->C1->UseVisualStyleBackColor = false;
			this->C1->Click += gcnew System::EventHandler(this, &Form1::C1_Click);
			// 
			// B1
			// 
			this->B1->BackColor = System::Drawing::Color::White;
			this->B1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"B1.BackgroundImage")));
			this->B1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B1->Location = System::Drawing::Point(76, 486);
			this->B1->Name = L"B1";
			this->B1->Size = System::Drawing::Size(64, 64);
			this->B1->TabIndex = 212;
			this->B1->UseVisualStyleBackColor = false;
			this->B1->Click += gcnew System::EventHandler(this, &Form1::B1_Click);
			// 
			// A1
			// 
			this->A1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->A1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"A1.BackgroundImage")));
			this->A1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->A1->Location = System::Drawing::Point(12, 486);
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(64, 64);
			this->A1->TabIndex = 211;
			this->A1->UseVisualStyleBackColor = false;
			this->A1->Click += gcnew System::EventHandler(this, &Form1::A1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(178)));
			this->textBox1->Location = System::Drawing::Point(566, 195);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(184, 42);
			this->textBox1->TabIndex = 275;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(566, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 23);
			this->button1->TabIndex = 276;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(178)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->textBox2->Location = System::Drawing::Point(566, 155);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(184, 38);
			this->textBox2->TabIndex = 277;
			this->textBox2->Text = L"Not Started";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripButton1, 
				this->toolStripButton2, this->toolStripButton3, this->toolStripButton4});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(772, 25);
			this->toolStrip1->TabIndex = 278;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(35, 22);
			this->toolStripButton1->Text = L"Save";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(37, 22);
			this->toolStripButton2->Text = L"Load";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(40, 22);
			this->toolStripButton3->Text = L"Undo";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(38, 22);
			this->toolStripButton4->Text = L"Redo";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButton4_Click);
			// 
			// SaveFile
			// 
			this->SaveFile->Filter = L"Chess Files (*.chess)|*.chess";
			// 
			// OpenFile
			// 
			this->OpenFile->FileName = L"openFileDialog1";
			this->OpenFile->Filter = L"Chess Files (*.chess)|*.chess";
			// 
			// B_Rook
			// 
			this->B_Rook->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->B_Rook->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_Rook->ForeColor = System::Drawing::Color::Blue;
			this->B_Rook->Location = System::Drawing::Point(567, 358);
			this->B_Rook->Name = L"B_Rook";
			this->B_Rook->Size = System::Drawing::Size(88, 68);
			this->B_Rook->TabIndex = 280;
			this->B_Rook->Text = L"Promote to Rook";
			this->B_Rook->UseVisualStyleBackColor = false;
			this->B_Rook->Visible = false;
			this->B_Rook->Click += gcnew System::EventHandler(this, &Form1::B_Rook_Click);
			// 
			// B_Queen
			// 
			this->B_Queen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->B_Queen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_Queen->ForeColor = System::Drawing::Color::Blue;
			this->B_Queen->Location = System::Drawing::Point(663, 358);
			this->B_Queen->Name = L"B_Queen";
			this->B_Queen->Size = System::Drawing::Size(88, 68);
			this->B_Queen->TabIndex = 281;
			this->B_Queen->Text = L"Promote to Queen";
			this->B_Queen->UseVisualStyleBackColor = false;
			this->B_Queen->Visible = false;
			this->B_Queen->Click += gcnew System::EventHandler(this, &Form1::B_Queen_Click);
			// 
			// B_Knight
			// 
			this->B_Knight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->B_Knight->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_Knight->ForeColor = System::Drawing::Color::Blue;
			this->B_Knight->Location = System::Drawing::Point(566, 287);
			this->B_Knight->Name = L"B_Knight";
			this->B_Knight->Size = System::Drawing::Size(88, 68);
			this->B_Knight->TabIndex = 282;
			this->B_Knight->Text = L"Promote to Knight";
			this->B_Knight->UseVisualStyleBackColor = false;
			this->B_Knight->Visible = false;
			this->B_Knight->Click += gcnew System::EventHandler(this, &Form1::B_Knight_Click);
			// 
			// B_Bishop
			// 
			this->B_Bishop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->B_Bishop->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->B_Bishop->ForeColor = System::Drawing::Color::Blue;
			this->B_Bishop->Location = System::Drawing::Point(663, 287);
			this->B_Bishop->Name = L"B_Bishop";
			this->B_Bishop->Size = System::Drawing::Size(88, 68);
			this->B_Bishop->TabIndex = 283;
			this->B_Bishop->Text = L"Promote to Bishop";
			this->B_Bishop->UseVisualStyleBackColor = false;
			this->B_Bishop->Visible = false;
			this->B_Bishop->Click += gcnew System::EventHandler(this, &Form1::B_Bishop_Click);
			// 
			// Black_Lost_1
			// 
			this->Black_Lost_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_1->Enabled = false;
			this->Black_Lost_1->Location = System::Drawing::Point(566, 38);
			this->Black_Lost_1->Name = L"Black_Lost_1";
			this->Black_Lost_1->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_1->TabIndex = 307;
			this->Black_Lost_1->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_6
			// 
			this->Black_Lost_6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_6->Enabled = false;
			this->Black_Lost_6->Location = System::Drawing::Point(566, 76);
			this->Black_Lost_6->Name = L"Black_Lost_6";
			this->Black_Lost_6->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_6->TabIndex = 332;
			this->Black_Lost_6->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_2
			// 
			this->Black_Lost_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_2->Enabled = false;
			this->Black_Lost_2->Location = System::Drawing::Point(604, 38);
			this->Black_Lost_2->Name = L"Black_Lost_2";
			this->Black_Lost_2->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_2->TabIndex = 333;
			this->Black_Lost_2->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_7
			// 
			this->Black_Lost_7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_7->Enabled = false;
			this->Black_Lost_7->Location = System::Drawing::Point(604, 76);
			this->Black_Lost_7->Name = L"Black_Lost_7";
			this->Black_Lost_7->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_7->TabIndex = 334;
			this->Black_Lost_7->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_8
			// 
			this->Black_Lost_8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_8->Enabled = false;
			this->Black_Lost_8->Location = System::Drawing::Point(642, 76);
			this->Black_Lost_8->Name = L"Black_Lost_8";
			this->Black_Lost_8->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_8->TabIndex = 335;
			this->Black_Lost_8->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_3
			// 
			this->Black_Lost_3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_3->Enabled = false;
			this->Black_Lost_3->Location = System::Drawing::Point(642, 38);
			this->Black_Lost_3->Name = L"Black_Lost_3";
			this->Black_Lost_3->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_3->TabIndex = 336;
			this->Black_Lost_3->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_9
			// 
			this->Black_Lost_9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_9->Enabled = false;
			this->Black_Lost_9->Location = System::Drawing::Point(680, 76);
			this->Black_Lost_9->Name = L"Black_Lost_9";
			this->Black_Lost_9->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_9->TabIndex = 337;
			this->Black_Lost_9->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_4
			// 
			this->Black_Lost_4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_4->Enabled = false;
			this->Black_Lost_4->Location = System::Drawing::Point(680, 38);
			this->Black_Lost_4->Name = L"Black_Lost_4";
			this->Black_Lost_4->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_4->TabIndex = 338;
			this->Black_Lost_4->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_11
			// 
			this->Black_Lost_11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_11->Enabled = false;
			this->Black_Lost_11->Location = System::Drawing::Point(566, 114);
			this->Black_Lost_11->Name = L"Black_Lost_11";
			this->Black_Lost_11->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_11->TabIndex = 339;
			this->Black_Lost_11->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_12
			// 
			this->Black_Lost_12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_12->Enabled = false;
			this->Black_Lost_12->Location = System::Drawing::Point(604, 114);
			this->Black_Lost_12->Name = L"Black_Lost_12";
			this->Black_Lost_12->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_12->TabIndex = 340;
			this->Black_Lost_12->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_14
			// 
			this->Black_Lost_14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_14->Enabled = false;
			this->Black_Lost_14->Location = System::Drawing::Point(680, 114);
			this->Black_Lost_14->Name = L"Black_Lost_14";
			this->Black_Lost_14->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_14->TabIndex = 341;
			this->Black_Lost_14->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_13
			// 
			this->Black_Lost_13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_13->Enabled = false;
			this->Black_Lost_13->Location = System::Drawing::Point(642, 114);
			this->Black_Lost_13->Name = L"Black_Lost_13";
			this->Black_Lost_13->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_13->TabIndex = 342;
			this->Black_Lost_13->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_5
			// 
			this->Black_Lost_5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_5->Enabled = false;
			this->Black_Lost_5->Location = System::Drawing::Point(718, 38);
			this->Black_Lost_5->Name = L"Black_Lost_5";
			this->Black_Lost_5->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_5->TabIndex = 343;
			this->Black_Lost_5->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_10
			// 
			this->Black_Lost_10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_10->Enabled = false;
			this->Black_Lost_10->Location = System::Drawing::Point(718, 76);
			this->Black_Lost_10->Name = L"Black_Lost_10";
			this->Black_Lost_10->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_10->TabIndex = 344;
			this->Black_Lost_10->UseVisualStyleBackColor = true;
			// 
			// Black_Lost_15
			// 
			this->Black_Lost_15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Black_Lost_15->Enabled = false;
			this->Black_Lost_15->Location = System::Drawing::Point(718, 114);
			this->Black_Lost_15->Name = L"Black_Lost_15";
			this->Black_Lost_15->Size = System::Drawing::Size(32, 32);
			this->Black_Lost_15->TabIndex = 345;
			this->Black_Lost_15->UseVisualStyleBackColor = true;
			// 
			// White_Lost_5
			// 
			this->White_Lost_5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_5->Enabled = false;
			this->White_Lost_5->Location = System::Drawing::Point(719, 514);
			this->White_Lost_5->Name = L"White_Lost_5";
			this->White_Lost_5->Size = System::Drawing::Size(32, 32);
			this->White_Lost_5->TabIndex = 360;
			this->White_Lost_5->UseVisualStyleBackColor = true;
			// 
			// White_Lost_10
			// 
			this->White_Lost_10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_10->Enabled = false;
			this->White_Lost_10->Location = System::Drawing::Point(719, 476);
			this->White_Lost_10->Name = L"White_Lost_10";
			this->White_Lost_10->Size = System::Drawing::Size(32, 32);
			this->White_Lost_10->TabIndex = 359;
			this->White_Lost_10->UseVisualStyleBackColor = true;
			// 
			// White_Lost_15
			// 
			this->White_Lost_15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_15->Enabled = false;
			this->White_Lost_15->Location = System::Drawing::Point(719, 438);
			this->White_Lost_15->Name = L"White_Lost_15";
			this->White_Lost_15->Size = System::Drawing::Size(32, 32);
			this->White_Lost_15->TabIndex = 358;
			this->White_Lost_15->UseVisualStyleBackColor = true;
			// 
			// White_Lost_3
			// 
			this->White_Lost_3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_3->Enabled = false;
			this->White_Lost_3->Location = System::Drawing::Point(643, 514);
			this->White_Lost_3->Name = L"White_Lost_3";
			this->White_Lost_3->Size = System::Drawing::Size(32, 32);
			this->White_Lost_3->TabIndex = 357;
			this->White_Lost_3->UseVisualStyleBackColor = true;
			// 
			// White_Lost_4
			// 
			this->White_Lost_4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_4->Enabled = false;
			this->White_Lost_4->Location = System::Drawing::Point(681, 514);
			this->White_Lost_4->Name = L"White_Lost_4";
			this->White_Lost_4->Size = System::Drawing::Size(32, 32);
			this->White_Lost_4->TabIndex = 356;
			this->White_Lost_4->UseVisualStyleBackColor = true;
			// 
			// White_Lost_2
			// 
			this->White_Lost_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_2->Enabled = false;
			this->White_Lost_2->Location = System::Drawing::Point(605, 514);
			this->White_Lost_2->Name = L"White_Lost_2";
			this->White_Lost_2->Size = System::Drawing::Size(32, 32);
			this->White_Lost_2->TabIndex = 355;
			this->White_Lost_2->UseVisualStyleBackColor = true;
			// 
			// White_Lost_1
			// 
			this->White_Lost_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_1->Enabled = false;
			this->White_Lost_1->Location = System::Drawing::Point(567, 514);
			this->White_Lost_1->Name = L"White_Lost_1";
			this->White_Lost_1->Size = System::Drawing::Size(32, 32);
			this->White_Lost_1->TabIndex = 354;
			this->White_Lost_1->UseVisualStyleBackColor = true;
			// 
			// White_Lost_14
			// 
			this->White_Lost_14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_14->Enabled = false;
			this->White_Lost_14->Location = System::Drawing::Point(681, 438);
			this->White_Lost_14->Name = L"White_Lost_14";
			this->White_Lost_14->Size = System::Drawing::Size(32, 32);
			this->White_Lost_14->TabIndex = 353;
			this->White_Lost_14->UseVisualStyleBackColor = true;
			// 
			// White_Lost_9
			// 
			this->White_Lost_9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_9->Enabled = false;
			this->White_Lost_9->Location = System::Drawing::Point(681, 476);
			this->White_Lost_9->Name = L"White_Lost_9";
			this->White_Lost_9->Size = System::Drawing::Size(32, 32);
			this->White_Lost_9->TabIndex = 352;
			this->White_Lost_9->UseVisualStyleBackColor = true;
			// 
			// White_Lost_13
			// 
			this->White_Lost_13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_13->Enabled = false;
			this->White_Lost_13->Location = System::Drawing::Point(643, 438);
			this->White_Lost_13->Name = L"White_Lost_13";
			this->White_Lost_13->Size = System::Drawing::Size(32, 32);
			this->White_Lost_13->TabIndex = 351;
			this->White_Lost_13->UseVisualStyleBackColor = true;
			// 
			// White_Lost_8
			// 
			this->White_Lost_8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_8->Enabled = false;
			this->White_Lost_8->Location = System::Drawing::Point(643, 476);
			this->White_Lost_8->Name = L"White_Lost_8";
			this->White_Lost_8->Size = System::Drawing::Size(32, 32);
			this->White_Lost_8->TabIndex = 350;
			this->White_Lost_8->UseVisualStyleBackColor = true;
			// 
			// White_Lost_7
			// 
			this->White_Lost_7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_7->Enabled = false;
			this->White_Lost_7->Location = System::Drawing::Point(605, 476);
			this->White_Lost_7->Name = L"White_Lost_7";
			this->White_Lost_7->Size = System::Drawing::Size(32, 32);
			this->White_Lost_7->TabIndex = 349;
			this->White_Lost_7->UseVisualStyleBackColor = true;
			// 
			// White_Lost_12
			// 
			this->White_Lost_12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_12->Enabled = false;
			this->White_Lost_12->Location = System::Drawing::Point(605, 438);
			this->White_Lost_12->Name = L"White_Lost_12";
			this->White_Lost_12->Size = System::Drawing::Size(32, 32);
			this->White_Lost_12->TabIndex = 348;
			this->White_Lost_12->UseVisualStyleBackColor = true;
			// 
			// White_Lost_6
			// 
			this->White_Lost_6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_6->Enabled = false;
			this->White_Lost_6->Location = System::Drawing::Point(567, 476);
			this->White_Lost_6->Name = L"White_Lost_6";
			this->White_Lost_6->Size = System::Drawing::Size(32, 32);
			this->White_Lost_6->TabIndex = 347;
			this->White_Lost_6->UseVisualStyleBackColor = true;
			// 
			// White_Lost_11
			// 
			this->White_Lost_11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->White_Lost_11->Enabled = false;
			this->White_Lost_11->Location = System::Drawing::Point(567, 438);
			this->White_Lost_11->Name = L"White_Lost_11";
			this->White_Lost_11->Size = System::Drawing::Size(32, 32);
			this->White_Lost_11->TabIndex = 346;
			this->White_Lost_11->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(567, 238);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(155, 17);
			this->checkBox1->TabIndex = 361;
			this->checkBox1->Text = L"Enable Artificial Intelligence";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(725, 238);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(26, 21);
			this->button2->TabIndex = 362;
			this->button2->Text = L"*";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 559);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->White_Lost_5);
			this->Controls->Add(this->White_Lost_10);
			this->Controls->Add(this->White_Lost_15);
			this->Controls->Add(this->White_Lost_3);
			this->Controls->Add(this->White_Lost_4);
			this->Controls->Add(this->White_Lost_2);
			this->Controls->Add(this->White_Lost_1);
			this->Controls->Add(this->White_Lost_14);
			this->Controls->Add(this->White_Lost_9);
			this->Controls->Add(this->White_Lost_13);
			this->Controls->Add(this->White_Lost_8);
			this->Controls->Add(this->White_Lost_7);
			this->Controls->Add(this->White_Lost_12);
			this->Controls->Add(this->White_Lost_6);
			this->Controls->Add(this->White_Lost_11);
			this->Controls->Add(this->Black_Lost_15);
			this->Controls->Add(this->Black_Lost_10);
			this->Controls->Add(this->Black_Lost_5);
			this->Controls->Add(this->Black_Lost_13);
			this->Controls->Add(this->Black_Lost_14);
			this->Controls->Add(this->Black_Lost_12);
			this->Controls->Add(this->Black_Lost_11);
			this->Controls->Add(this->Black_Lost_4);
			this->Controls->Add(this->Black_Lost_9);
			this->Controls->Add(this->Black_Lost_3);
			this->Controls->Add(this->Black_Lost_8);
			this->Controls->Add(this->Black_Lost_7);
			this->Controls->Add(this->Black_Lost_2);
			this->Controls->Add(this->Black_Lost_6);
			this->Controls->Add(this->Black_Lost_1);
			this->Controls->Add(this->B_Bishop);
			this->Controls->Add(this->B_Knight);
			this->Controls->Add(this->B_Queen);
			this->Controls->Add(this->B_Rook);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->B2);
			this->Controls->Add(this->D2);
			this->Controls->Add(this->F2);
			this->Controls->Add(this->H2);
			this->Controls->Add(this->G3);
			this->Controls->Add(this->E3);
			this->Controls->Add(this->C3);
			this->Controls->Add(this->A3);
			this->Controls->Add(this->A5);
			this->Controls->Add(this->B4);
			this->Controls->Add(this->D4);
			this->Controls->Add(this->F4);
			this->Controls->Add(this->H4);
			this->Controls->Add(this->G5);
			this->Controls->Add(this->E5);
			this->Controls->Add(this->C5);
			this->Controls->Add(this->B6);
			this->Controls->Add(this->D6);
			this->Controls->Add(this->F6);
			this->Controls->Add(this->H8);
			this->Controls->Add(this->G8);
			this->Controls->Add(this->F8);
			this->Controls->Add(this->E8);
			this->Controls->Add(this->D8);
			this->Controls->Add(this->C8);
			this->Controls->Add(this->B8);
			this->Controls->Add(this->A8);
			this->Controls->Add(this->H7);
			this->Controls->Add(this->F7);
			this->Controls->Add(this->C7);
			this->Controls->Add(this->D7);
			this->Controls->Add(this->A7);
			this->Controls->Add(this->E7);
			this->Controls->Add(this->G7);
			this->Controls->Add(this->H6);
			this->Controls->Add(this->B7);
			this->Controls->Add(this->A6);
			this->Controls->Add(this->C6);
			this->Controls->Add(this->E6);
			this->Controls->Add(this->G6);
			this->Controls->Add(this->H5);
			this->Controls->Add(this->F5);
			this->Controls->Add(this->D5);
			this->Controls->Add(this->B5);
			this->Controls->Add(this->A4);
			this->Controls->Add(this->C4);
			this->Controls->Add(this->E4);
			this->Controls->Add(this->G4);
			this->Controls->Add(this->H3);
			this->Controls->Add(this->B3);
			this->Controls->Add(this->D3);
			this->Controls->Add(this->F3);
			this->Controls->Add(this->A2);
			this->Controls->Add(this->C2);
			this->Controls->Add(this->E2);
			this->Controls->Add(this->G2);
			this->Controls->Add(this->H1);
			this->Controls->Add(this->G1);
			this->Controls->Add(this->F1);
			this->Controls->Add(this->E1);
			this->Controls->Add(this->D1);
			this->Controls->Add(this->C1);
			this->Controls->Add(this->B1);
			this->Controls->Add(this->A1);
			this->Name = L"Form1";
			this->Text = L"2D Chess";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void H8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void H1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void G8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void G1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void F8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void F1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void E8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void E1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void D8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void D1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void C8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void C1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void B8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void A8_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A7_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A6_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A5_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A4_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A3_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A2_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void A1_Click(System::Object^  sender, System::EventArgs^  e) ;

private: System::Void B_Rook_Click  (System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B_Knight_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B_Queen_Click (System::Object^  sender, System::EventArgs^  e) ;
private: System::Void B_Bishop_Click(System::Object^  sender, System::EventArgs^  e) ;

		 //********************************************************************>additional functions
private: System::Void RefreshTable();
private: System::Void ClearLost();
private: System::Void Select(int**);
private: System::Void DeSelect(int**);
private: System::Void ChangeState(bool);
private: System::Void AddLost(bool,int);
private: System::Void ClearBackGround(int ,int);
private: System::Void ChangeState(int , int , bool);
private: System::Void ChangeBackGround(int , int , int , bool);
private: System::Void Colorize(int , int, System::Drawing::Color color);
private: System::Void Artificial_Move();
		 //*********************************************************************
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

			 if(time!=0)
			 {
				 time--;
			 }
			 else
			 {
				 time=600;//change to end game
				 //System::Windows::Forms::MessageBox
			 }

			 textBox2->Text=time.ToString();

			 if(time<100)
			 {
				 textBox2->ForeColor=System::Drawing::Color::DarkRed;
			 }
			 else if(time<200)
			 {
				 textBox2->ForeColor=System::Drawing::Color::Red;
			 }
			 else if(time<300)
			 {
				 textBox2->ForeColor=System::Drawing::Color::DarkBlue;
			 }
			 else if(time<400)
			 {
				 textBox2->ForeColor=System::Drawing::Color::Blue;
			 }
			 else if(time<500)
			 {
				 textBox2->ForeColor=System::Drawing::Color::DarkGreen;
			 }
			 else
			 {
				 textBox2->ForeColor=System::Drawing::Color::Green;
			 }

		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Start();
		 }

private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e);//Save
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e);//Load or open
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e);//Undo
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e);
		
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Artificial_Move();
		 }
};

};


