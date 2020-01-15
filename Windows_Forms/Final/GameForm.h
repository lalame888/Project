#pragma once

namespace Final {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace Final;

	//using namespace About;
	/// <summary>
	/// GameForm 的摘要
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼

			star();
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  C1;
	private: System::Windows::Forms::PictureBox^  A1;
	protected:

	private: System::Windows::Forms::PictureBox^  C2;
	private: System::Windows::Forms::PictureBox^  C3;
	private: System::Windows::Forms::PictureBox^  C4;
	private: System::Windows::Forms::PictureBox^  C8;

	private: System::Windows::Forms::PictureBox^  C7;

	private: System::Windows::Forms::PictureBox^  C6;

	private: System::Windows::Forms::PictureBox^  C5;
	private: System::Windows::Forms::PictureBox^  C16;


	private: System::Windows::Forms::PictureBox^  C15;

	private: System::Windows::Forms::PictureBox^  C14;

	private: System::Windows::Forms::PictureBox^  C13;

	private: System::Windows::Forms::PictureBox^  C12;

	private: System::Windows::Forms::PictureBox^  C11;

	private: System::Windows::Forms::PictureBox^  C10;

	private: System::Windows::Forms::PictureBox^  C9;

	private: System::Windows::Forms::Button^  start;

	private:
		/// <summary>

		int click = 0;
		int click_ID = 0;
		int time = 2000;
		int count = 0; //計算有幾個已經消失
		int s = 0;
		int m = 0;


		String ^Sec;
		String ^Min;

		int Start = 0;
		array <int> ^dis=gcnew array<int> (16);
		int i = 0;
		
		
		


	private: System::Windows::Forms::PictureBox^  A7;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  A2;
	private: System::Windows::Forms::PictureBox^  A12;
	private: System::Windows::Forms::PictureBox^  A5;
	private: System::Windows::Forms::PictureBox^  A11;
	private: System::Windows::Forms::PictureBox^  A8;
	private: System::Windows::Forms::PictureBox^  A16;
	private: System::Windows::Forms::PictureBox^  A10;
	private: System::Windows::Forms::PictureBox^  A13;
	private: System::Windows::Forms::PictureBox^  A6;
	private: System::Windows::Forms::PictureBox^  A15;
	private: System::Windows::Forms::PictureBox^  A3;
	private: System::Windows::Forms::PictureBox^  A14;
	private: System::Windows::Forms::PictureBox^  A4;
	private: System::Windows::Forms::PictureBox^  A9;
	private: System::Windows::Forms::Label^  CountTime;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  選項ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  新遊戲ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  結束遊戲ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關於ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關於ToolStripMenuItem1;
private: System::Windows::Forms::Button^  cheat;
private: System::Windows::Forms::Button^  Pause_Button;

private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::PictureBox^  init;

private: System::Windows::Forms::PictureBox^  close_game;

private: System::Windows::Forms::PictureBox^  start_game;

private: System::Windows::Forms::PictureBox^  Click_OK;
private: System::Windows::Forms::Label^  clear_m;
private: System::Windows::Forms::Label^  clear_s;
private: System::Windows::Forms::PictureBox^  clear;








	private: System::ComponentModel::IContainer^  components;

		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->C1 = (gcnew System::Windows::Forms::PictureBox());
			this->A1 = (gcnew System::Windows::Forms::PictureBox());
			this->C2 = (gcnew System::Windows::Forms::PictureBox());
			this->C3 = (gcnew System::Windows::Forms::PictureBox());
			this->C4 = (gcnew System::Windows::Forms::PictureBox());
			this->C8 = (gcnew System::Windows::Forms::PictureBox());
			this->C7 = (gcnew System::Windows::Forms::PictureBox());
			this->C6 = (gcnew System::Windows::Forms::PictureBox());
			this->C5 = (gcnew System::Windows::Forms::PictureBox());
			this->C16 = (gcnew System::Windows::Forms::PictureBox());
			this->C15 = (gcnew System::Windows::Forms::PictureBox());
			this->C14 = (gcnew System::Windows::Forms::PictureBox());
			this->C13 = (gcnew System::Windows::Forms::PictureBox());
			this->C12 = (gcnew System::Windows::Forms::PictureBox());
			this->C11 = (gcnew System::Windows::Forms::PictureBox());
			this->C10 = (gcnew System::Windows::Forms::PictureBox());
			this->C9 = (gcnew System::Windows::Forms::PictureBox());
			this->start = (gcnew System::Windows::Forms::Button());
			this->A7 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->A2 = (gcnew System::Windows::Forms::PictureBox());
			this->A12 = (gcnew System::Windows::Forms::PictureBox());
			this->A5 = (gcnew System::Windows::Forms::PictureBox());
			this->A11 = (gcnew System::Windows::Forms::PictureBox());
			this->A8 = (gcnew System::Windows::Forms::PictureBox());
			this->A16 = (gcnew System::Windows::Forms::PictureBox());
			this->A10 = (gcnew System::Windows::Forms::PictureBox());
			this->A13 = (gcnew System::Windows::Forms::PictureBox());
			this->A6 = (gcnew System::Windows::Forms::PictureBox());
			this->A15 = (gcnew System::Windows::Forms::PictureBox());
			this->A3 = (gcnew System::Windows::Forms::PictureBox());
			this->A14 = (gcnew System::Windows::Forms::PictureBox());
			this->A4 = (gcnew System::Windows::Forms::PictureBox());
			this->A9 = (gcnew System::Windows::Forms::PictureBox());
			this->CountTime = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->選項ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->新遊戲ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->結束遊戲ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關於ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關於ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cheat = (gcnew System::Windows::Forms::Button());
			this->Pause_Button = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->init = (gcnew System::Windows::Forms::PictureBox());
			this->close_game = (gcnew System::Windows::Forms::PictureBox());
			this->start_game = (gcnew System::Windows::Forms::PictureBox());
			this->Click_OK = (gcnew System::Windows::Forms::PictureBox());
			this->clear_m = (gcnew System::Windows::Forms::Label());
			this->clear_s = (gcnew System::Windows::Forms::Label());
			this->clear = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A9))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->init))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->close_game))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start_game))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Click_OK))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clear))->BeginInit();
			this->SuspendLayout();
			// 
			// C1
			// 
			this->C1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C1.Image")));
			this->C1->Location = System::Drawing::Point(100, 71);
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(65, 92);
			this->C1->TabIndex = 0;
			this->C1->TabStop = false;
			this->C1->Visible = false;
			this->C1->Click += gcnew System::EventHandler(this, &GameForm::C1_Click);
			// 
			// A1
			// 
			this->A1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A1.Image")));
			this->A1->Location = System::Drawing::Point(100, 71);
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(65, 92);
			this->A1->TabIndex = 1;
			this->A1->TabStop = false;
			// 
			// C2
			// 
			this->C2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C2.Image")));
			this->C2->Location = System::Drawing::Point(228, 71);
			this->C2->Name = L"C2";
			this->C2->Size = System::Drawing::Size(65, 92);
			this->C2->TabIndex = 2;
			this->C2->TabStop = false;
			this->C2->Visible = false;
			this->C2->Click += gcnew System::EventHandler(this, &GameForm::C2_Click);
			// 
			// C3
			// 
			this->C3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C3.Image")));
			this->C3->Location = System::Drawing::Point(351, 71);
			this->C3->Name = L"C3";
			this->C3->Size = System::Drawing::Size(65, 92);
			this->C3->TabIndex = 3;
			this->C3->TabStop = false;
			this->C3->Visible = false;
			this->C3->Click += gcnew System::EventHandler(this, &GameForm::C3_Click);
			// 
			// C4
			// 
			this->C4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C4.Image")));
			this->C4->Location = System::Drawing::Point(475, 71);
			this->C4->Name = L"C4";
			this->C4->Size = System::Drawing::Size(65, 92);
			this->C4->TabIndex = 4;
			this->C4->TabStop = false;
			this->C4->Visible = false;
			this->C4->Click += gcnew System::EventHandler(this, &GameForm::C4_Click);
			// 
			// C8
			// 
			this->C8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C8.Image")));
			this->C8->Location = System::Drawing::Point(475, 194);
			this->C8->Name = L"C8";
			this->C8->Size = System::Drawing::Size(65, 92);
			this->C8->TabIndex = 8;
			this->C8->TabStop = false;
			this->C8->Visible = false;
			this->C8->Click += gcnew System::EventHandler(this, &GameForm::C8_Click);
			// 
			// C7
			// 
			this->C7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C7.Image")));
			this->C7->Location = System::Drawing::Point(351, 194);
			this->C7->Name = L"C7";
			this->C7->Size = System::Drawing::Size(65, 92);
			this->C7->TabIndex = 7;
			this->C7->TabStop = false;
			this->C7->Visible = false;
			this->C7->Click += gcnew System::EventHandler(this, &GameForm::C7_Click);
			// 
			// C6
			// 
			this->C6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C6.Image")));
			this->C6->Location = System::Drawing::Point(229, 194);
			this->C6->Name = L"C6";
			this->C6->Size = System::Drawing::Size(65, 92);
			this->C6->TabIndex = 6;
			this->C6->TabStop = false;
			this->C6->Visible = false;
			this->C6->Click += gcnew System::EventHandler(this, &GameForm::C6_Click);
			// 
			// C5
			// 
			this->C5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C5.Image")));
			this->C5->Location = System::Drawing::Point(100, 194);
			this->C5->Name = L"C5";
			this->C5->Size = System::Drawing::Size(65, 92);
			this->C5->TabIndex = 5;
			this->C5->TabStop = false;
			this->C5->Visible = false;
			this->C5->Click += gcnew System::EventHandler(this, &GameForm::C5_Click);
			// 
			// C16
			// 
			this->C16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C16.Image")));
			this->C16->Location = System::Drawing::Point(475, 440);
			this->C16->Name = L"C16";
			this->C16->Size = System::Drawing::Size(65, 92);
			this->C16->TabIndex = 16;
			this->C16->TabStop = false;
			this->C16->Visible = false;
			this->C16->Click += gcnew System::EventHandler(this, &GameForm::C16_Click);
			// 
			// C15
			// 
			this->C15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C15.Image")));
			this->C15->Location = System::Drawing::Point(351, 440);
			this->C15->Name = L"C15";
			this->C15->Size = System::Drawing::Size(65, 92);
			this->C15->TabIndex = 15;
			this->C15->TabStop = false;
			this->C15->Visible = false;
			this->C15->Click += gcnew System::EventHandler(this, &GameForm::C15_Click);
			// 
			// C14
			// 
			this->C14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C14.Image")));
			this->C14->Location = System::Drawing::Point(228, 440);
			this->C14->Name = L"C14";
			this->C14->Size = System::Drawing::Size(65, 92);
			this->C14->TabIndex = 14;
			this->C14->TabStop = false;
			this->C14->Visible = false;
			this->C14->Click += gcnew System::EventHandler(this, &GameForm::C14_Click);
			// 
			// C13
			// 
			this->C13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C13.Image")));
			this->C13->Location = System::Drawing::Point(100, 440);
			this->C13->Name = L"C13";
			this->C13->Size = System::Drawing::Size(65, 92);
			this->C13->TabIndex = 13;
			this->C13->TabStop = false;
			this->C13->Visible = false;
			this->C13->Click += gcnew System::EventHandler(this, &GameForm::C13_Click);
			// 
			// C12
			// 
			this->C12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C12.Image")));
			this->C12->Location = System::Drawing::Point(475, 317);
			this->C12->Name = L"C12";
			this->C12->Size = System::Drawing::Size(65, 92);
			this->C12->TabIndex = 12;
			this->C12->TabStop = false;
			this->C12->Visible = false;
			this->C12->Click += gcnew System::EventHandler(this, &GameForm::C12_Click);
			// 
			// C11
			// 
			this->C11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C11.Image")));
			this->C11->Location = System::Drawing::Point(351, 317);
			this->C11->Name = L"C11";
			this->C11->Size = System::Drawing::Size(65, 92);
			this->C11->TabIndex = 11;
			this->C11->TabStop = false;
			this->C11->Visible = false;
			this->C11->Click += gcnew System::EventHandler(this, &GameForm::C11_Click);
			// 
			// C10
			// 
			this->C10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C10.Image")));
			this->C10->Location = System::Drawing::Point(228, 317);
			this->C10->Name = L"C10";
			this->C10->Size = System::Drawing::Size(65, 92);
			this->C10->TabIndex = 10;
			this->C10->TabStop = false;
			this->C10->Visible = false;
			this->C10->Click += gcnew System::EventHandler(this, &GameForm::C10_Click);
			// 
			// C9
			// 
			this->C9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C9.Image")));
			this->C9->Location = System::Drawing::Point(100, 317);
			this->C9->Name = L"C9";
			this->C9->Size = System::Drawing::Size(65, 92);
			this->C9->TabIndex = 9;
			this->C9->TabStop = false;
			this->C9->Visible = false;
			this->C9->Click += gcnew System::EventHandler(this, &GameForm::C9_Click);
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(284, 566);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(75, 37);
			this->start->TabIndex = 17;
			this->start->Text = L"開始遊戲";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &GameForm::start_Click);
			// 
			// A7
			// 
			this->A7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A7.Image")));
			this->A7->Location = System::Drawing::Point(351, 194);
			this->A7->Name = L"A7";
			this->A7->Size = System::Drawing::Size(65, 92);
			this->A7->TabIndex = 18;
			this->A7->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// A2
			// 
			this->A2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A2.Image")));
			this->A2->Location = System::Drawing::Point(228, 71);
			this->A2->Name = L"A2";
			this->A2->Size = System::Drawing::Size(66, 92);
			this->A2->TabIndex = 19;
			this->A2->TabStop = false;
			// 
			// A12
			// 
			this->A12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A12.Image")));
			this->A12->Location = System::Drawing::Point(475, 317);
			this->A12->Name = L"A12";
			this->A12->Size = System::Drawing::Size(66, 92);
			this->A12->TabIndex = 20;
			this->A12->TabStop = false;
			// 
			// A5
			// 
			this->A5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A5.Image")));
			this->A5->Location = System::Drawing::Point(100, 194);
			this->A5->Name = L"A5";
			this->A5->Size = System::Drawing::Size(65, 92);
			this->A5->TabIndex = 21;
			this->A5->TabStop = false;
			// 
			// A11
			// 
			this->A11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A11.Image")));
			this->A11->Location = System::Drawing::Point(351, 317);
			this->A11->Name = L"A11";
			this->A11->Size = System::Drawing::Size(65, 92);
			this->A11->TabIndex = 22;
			this->A11->TabStop = false;
			// 
			// A8
			// 
			this->A8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A8.Image")));
			this->A8->Location = System::Drawing::Point(475, 194);
			this->A8->Name = L"A8";
			this->A8->Size = System::Drawing::Size(65, 92);
			this->A8->TabIndex = 23;
			this->A8->TabStop = false;
			// 
			// A16
			// 
			this->A16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A16.Image")));
			this->A16->Location = System::Drawing::Point(476, 440);
			this->A16->Name = L"A16";
			this->A16->Size = System::Drawing::Size(65, 92);
			this->A16->TabIndex = 24;
			this->A16->TabStop = false;
			// 
			// A10
			// 
			this->A10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A10.Image")));
			this->A10->Location = System::Drawing::Point(228, 317);
			this->A10->Name = L"A10";
			this->A10->Size = System::Drawing::Size(65, 92);
			this->A10->TabIndex = 25;
			this->A10->TabStop = false;
			// 
			// A13
			// 
			this->A13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A13.Image")));
			this->A13->Location = System::Drawing::Point(100, 440);
			this->A13->Name = L"A13";
			this->A13->Size = System::Drawing::Size(65, 92);
			this->A13->TabIndex = 26;
			this->A13->TabStop = false;
			// 
			// A6
			// 
			this->A6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A6.Image")));
			this->A6->Location = System::Drawing::Point(228, 194);
			this->A6->Name = L"A6";
			this->A6->Size = System::Drawing::Size(65, 92);
			this->A6->TabIndex = 27;
			this->A6->TabStop = false;
			// 
			// A15
			// 
			this->A15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A15.Image")));
			this->A15->Location = System::Drawing::Point(351, 440);
			this->A15->Name = L"A15";
			this->A15->Size = System::Drawing::Size(65, 92);
			this->A15->TabIndex = 28;
			this->A15->TabStop = false;
			// 
			// A3
			// 
			this->A3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A3.Image")));
			this->A3->Location = System::Drawing::Point(351, 71);
			this->A3->Name = L"A3";
			this->A3->Size = System::Drawing::Size(65, 92);
			this->A3->TabIndex = 29;
			this->A3->TabStop = false;
			// 
			// A14
			// 
			this->A14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A14.Image")));
			this->A14->Location = System::Drawing::Point(229, 440);
			this->A14->Name = L"A14";
			this->A14->Size = System::Drawing::Size(65, 92);
			this->A14->TabIndex = 30;
			this->A14->TabStop = false;
			// 
			// A4
			// 
			this->A4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A4.Image")));
			this->A4->Location = System::Drawing::Point(475, 71);
			this->A4->Name = L"A4";
			this->A4->Size = System::Drawing::Size(65, 92);
			this->A4->TabIndex = 31;
			this->A4->TabStop = false;
			// 
			// A9
			// 
			this->A9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A9.Image")));
			this->A9->Location = System::Drawing::Point(100, 317);
			this->A9->Name = L"A9";
			this->A9->Size = System::Drawing::Size(65, 92);
			this->A9->TabIndex = 32;
			this->A9->TabStop = false;
			// 
			// CountTime
			// 
			this->CountTime->AutoSize = true;
			this->CountTime->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->CountTime->Location = System::Drawing::Point(297, 20);
			this->CountTime->Name = L"CountTime";
			this->CountTime->Size = System::Drawing::Size(47, 30);
			this->CountTime->TabIndex = 33;
			this->CountTime->Text = L"0:0";
			this->CountTime->Visible = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->選項ToolStripMenuItem,
					this->關於ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(741, 24);
			this->menuStrip1->TabIndex = 34;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 選項ToolStripMenuItem
			// 
			this->選項ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->新遊戲ToolStripMenuItem,
					this->結束遊戲ToolStripMenuItem
			});
			this->選項ToolStripMenuItem->Name = L"選項ToolStripMenuItem";
			this->選項ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->選項ToolStripMenuItem->Text = L"選項";
			// 
			// 新遊戲ToolStripMenuItem
			// 
			this->新遊戲ToolStripMenuItem->Name = L"新遊戲ToolStripMenuItem";
			this->新遊戲ToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->新遊戲ToolStripMenuItem->Text = L"新遊戲";
			this->新遊戲ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::新遊戲ToolStripMenuItem_Click);
			// 
			// 結束遊戲ToolStripMenuItem
			// 
			this->結束遊戲ToolStripMenuItem->Name = L"結束遊戲ToolStripMenuItem";
			this->結束遊戲ToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->結束遊戲ToolStripMenuItem->Text = L"結束遊戲";
			this->結束遊戲ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::結束遊戲ToolStripMenuItem_Click);
			// 
			// 關於ToolStripMenuItem
			// 
			this->關於ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->關於ToolStripMenuItem1 });
			this->關於ToolStripMenuItem->Name = L"關於ToolStripMenuItem";
			this->關於ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->關於ToolStripMenuItem->Text = L"關於";
			// 
			// 關於ToolStripMenuItem1
			// 
			this->關於ToolStripMenuItem1->Name = L"關於ToolStripMenuItem1";
			this->關於ToolStripMenuItem1->Size = System::Drawing::Size(98, 22);
			this->關於ToolStripMenuItem1->Text = L"關於";
			this->關於ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &GameForm::關於ToolStripMenuItem1_Click);
			// 
			// cheat
			// 
			this->cheat->Location = System::Drawing::Point(610, 557);
			this->cheat->Name = L"cheat";
			this->cheat->Size = System::Drawing::Size(75, 37);
			this->cheat->TabIndex = 35;
			this->cheat->Text = L"作弊鍵";
			this->cheat->UseVisualStyleBackColor = true;
			this->cheat->Visible = false;
			this->cheat->Click += gcnew System::EventHandler(this, &GameForm::cheat_Click);
			// 
			// Pause_Button
			// 
			this->Pause_Button->Location = System::Drawing::Point(610, 495);
			this->Pause_Button->Name = L"Pause_Button";
			this->Pause_Button->Size = System::Drawing::Size(75, 37);
			this->Pause_Button->TabIndex = 36;
			this->Pause_Button->Text = L"暫停鍵";
			this->Pause_Button->UseVisualStyleBackColor = true;
			this->Pause_Button->Visible = false;
			this->Pause_Button->Click += gcnew System::EventHandler(this, &GameForm::Pause_Button_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 20);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(741, 622);
			this->pictureBox1->TabIndex = 38;
			this->pictureBox1->TabStop = false;
			// 
			// init
			// 
			this->init->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"init.Image")));
			this->init->Location = System::Drawing::Point(0, 20);
			this->init->Name = L"init";
			this->init->Size = System::Drawing::Size(741, 622);
			this->init->TabIndex = 39;
			this->init->TabStop = false;
			// 
			// close_game
			// 
			this->close_game->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close_game.Image")));
			this->close_game->Location = System::Drawing::Point(228, 361);
			this->close_game->Name = L"close_game";
			this->close_game->Size = System::Drawing::Size(271, 94);
			this->close_game->TabIndex = 40;
			this->close_game->TabStop = false;
			this->close_game->Click += gcnew System::EventHandler(this, &GameForm::close_game_Click);
			// 
			// start_game
			// 
			this->start_game->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"start_game.Image")));
			this->start_game->Location = System::Drawing::Point(229, 226);
			this->start_game->Name = L"start_game";
			this->start_game->Size = System::Drawing::Size(271, 94);
			this->start_game->TabIndex = 41;
			this->start_game->TabStop = false;
			this->start_game->Click += gcnew System::EventHandler(this, &GameForm::start_game_Click);
			// 
			// Click_OK
			// 
			this->Click_OK->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Click_OK.Image")));
			this->Click_OK->Location = System::Drawing::Point(289, 421);
			this->Click_OK->Name = L"Click_OK";
			this->Click_OK->Size = System::Drawing::Size(167, 25);
			this->Click_OK->TabIndex = 43;
			this->Click_OK->TabStop = false;
			this->Click_OK->Click += gcnew System::EventHandler(this, &GameForm::Click_OK_Click);
			// 
			// clear_m
			// 
			this->clear_m->AutoSize = true;
			this->clear_m->BackColor = System::Drawing::Color::Gray;
			this->clear_m->Font = (gcnew System::Drawing::Font(L"王漢宗超明體繁", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->clear_m->ForeColor = System::Drawing::SystemColors::InfoText;
			this->clear_m->Location = System::Drawing::Point(323, 347);
			this->clear_m->Name = L"clear_m";
			this->clear_m->Size = System::Drawing::Size(21, 21);
			this->clear_m->TabIndex = 44;
			this->clear_m->Text = L"0";
			// 
			// clear_s
			// 
			this->clear_s->AutoSize = true;
			this->clear_s->BackColor = System::Drawing::Color::Gray;
			this->clear_s->Font = (gcnew System::Drawing::Font(L"王漢宗超明體繁", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->clear_s->ForeColor = System::Drawing::SystemColors::InfoText;
			this->clear_s->Location = System::Drawing::Point(410, 346);
			this->clear_s->Name = L"clear_s";
			this->clear_s->Size = System::Drawing::Size(21, 21);
			this->clear_s->TabIndex = 45;
			this->clear_s->Text = L"0";
			// 
			// clear
			// 
			this->clear->Enabled = false;
			this->clear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clear.Image")));
			this->clear->Location = System::Drawing::Point(0, 20);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(741, 622);
			this->clear->TabIndex = 46;
			this->clear->TabStop = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 638);
			this->Controls->Add(this->Click_OK);
			this->Controls->Add(this->clear_s);
			this->Controls->Add(this->clear_m);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->start_game);
			this->Controls->Add(this->close_game);
			this->Controls->Add(this->init);
			this->Controls->Add(this->Pause_Button);
			this->Controls->Add(this->cheat);
			this->Controls->Add(this->CountTime);
			this->Controls->Add(this->start);
			this->Controls->Add(this->C16);
			this->Controls->Add(this->C15);
			this->Controls->Add(this->C14);
			this->Controls->Add(this->C13);
			this->Controls->Add(this->C11);
			this->Controls->Add(this->C10);
			this->Controls->Add(this->C9);
			this->Controls->Add(this->C8);
			this->Controls->Add(this->C5);
			this->Controls->Add(this->C6);
			this->Controls->Add(this->C1);
			this->Controls->Add(this->C7);
			this->Controls->Add(this->C12);
			this->Controls->Add(this->A1);
			this->Controls->Add(this->C4);
			this->Controls->Add(this->C3);
			this->Controls->Add(this->C2);
			this->Controls->Add(this->A2);
			this->Controls->Add(this->A3);
			this->Controls->Add(this->A4);
			this->Controls->Add(this->A8);
			this->Controls->Add(this->A7);
			this->Controls->Add(this->A6);
			this->Controls->Add(this->A5);
			this->Controls->Add(this->A12);
			this->Controls->Add(this->A11);
			this->Controls->Add(this->A10);
			this->Controls->Add(this->A9);
			this->Controls->Add(this->A13);
			this->Controls->Add(this->A14);
			this->Controls->Add(this->A15);
			this->Controls->Add(this->A16);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"GameForm";
			this->Text = L"Unlight memory";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A9))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->init))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->close_game))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->start_game))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Click_OK))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clear))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void star() {

		Click_OK->Visible = false;
		clear->Visible = false;
		clear_m->Visible = false;
		clear_s->Visible = false;



		Sec = gcnew System::String(L"00");
		Min = gcnew System::String(L"00");
		for (i = 0; i < 16; i++) {
			dis[i] = 0;
		}

		array<int> ^xLocate = gcnew array<int>(16) {
			100, 228, 356, 484, 100, 228, 356, 484, 100, 228, 356, 484
				, 100, 228, 356, 484
		};
		array<int> ^yLocate = gcnew array<int>(16) { 71, 71, 71, 71, 194, 194, 194, 194, 317, 317, 317, 317, 440, 440, 440, 440 };


		swap(xLocate, yLocate);

		A1->Visible = true;
		A2->Visible = true;
		A3->Visible = true;
		A4->Visible = true;
		A5->Visible = true;
		A6->Visible = true;
		A7->Visible = true;
		A8->Visible = true;
		A9->Visible = true;
		A10->Visible = true;
		A11->Visible = true;
		A12->Visible = true;
		A13->Visible = true;
		A14->Visible = true;
		A15->Visible = true;
		A16->Visible = true;

		C1->Visible = false;
		C2->Visible = false;
		C3->Visible = false;
		C4->Visible = false;
		C5->Visible = false;
		C6->Visible = false;
		C7->Visible = false;
		C8->Visible = false;
		C9->Visible = false;
		C10->Visible = false;
		C11->Visible = false;
		C12->Visible = false;
		C13->Visible = false;
		C14->Visible = false;
		C15->Visible = false;
		C16->Visible = false;

		CountTime->Visible = false;
		start->Visible = true;
		
		Start = 0;

		this->A1->Location = System::Drawing::Point(xLocate[0], yLocate[0]);
		this->C1->Location = System::Drawing::Point(xLocate[0], yLocate[0]);
		this->A2->Location = System::Drawing::Point(xLocate[1], yLocate[1]);
		this->C2->Location = System::Drawing::Point(xLocate[1], yLocate[1]);
		this->A3->Location = System::Drawing::Point(xLocate[2], yLocate[2]);
		this->C3->Location = System::Drawing::Point(xLocate[2], yLocate[2]);
		this->A4->Location = System::Drawing::Point(xLocate[3], yLocate[3]);
		this->C4->Location = System::Drawing::Point(xLocate[3], yLocate[3]);
		this->A5->Location = System::Drawing::Point(xLocate[4], yLocate[4]);
		this->C5->Location = System::Drawing::Point(xLocate[4], yLocate[4]);
		this->A6->Location = System::Drawing::Point(xLocate[5], yLocate[5]);
		this->C6->Location = System::Drawing::Point(xLocate[5], yLocate[5]);
		this->A7->Location = System::Drawing::Point(xLocate[6], yLocate[6]);
		this->C7->Location = System::Drawing::Point(xLocate[6], yLocate[6]);
		this->A8->Location = System::Drawing::Point(xLocate[7], yLocate[7]);
		this->C8->Location = System::Drawing::Point(xLocate[7], yLocate[7]);
		this->A9->Location = System::Drawing::Point(xLocate[8], yLocate[8]);
		this->C9->Location = System::Drawing::Point(xLocate[8], yLocate[8]);
		this->A10->Location = System::Drawing::Point(xLocate[9], yLocate[9]);
		this->C10->Location = System::Drawing::Point(xLocate[9], yLocate[9]);
		this->A11->Location = System::Drawing::Point(xLocate[10], yLocate[10]);
		this->C11->Location = System::Drawing::Point(xLocate[10], yLocate[10]);
		this->A12->Location = System::Drawing::Point(xLocate[11], yLocate[11]);
		this->C12->Location = System::Drawing::Point(xLocate[11], yLocate[11]);
		this->A13->Location = System::Drawing::Point(xLocate[12], yLocate[12]);
		this->C13->Location = System::Drawing::Point(xLocate[12], yLocate[12]);
		this->A14->Location = System::Drawing::Point(xLocate[13], yLocate[13]);
		this->C14->Location = System::Drawing::Point(xLocate[13], yLocate[13]);
		this->A15->Location = System::Drawing::Point(xLocate[14], yLocate[14]);
		this->C15->Location = System::Drawing::Point(xLocate[14], yLocate[14]);
		this->A16->Location = System::Drawing::Point(xLocate[15], yLocate[15]);
		this->C16->Location = System::Drawing::Point(xLocate[15], yLocate[15]);



	}

	private: System::Void swap(array<int>^ xLocate,array<int>^ yLocate) {
		Random^ generator = gcnew Random;
		int r;
		double^ value;
		int i;
		int temp;
		for (i = 0; i < 16; i++) {
			value = 10 * (generator->NextDouble());
			r = (safe_cast<int>(*value)) % (16);

			temp = xLocate[i];
			xLocate[i]= xLocate[r];
			xLocate[r]=temp;

			temp = yLocate[i];
			yLocate[i] = yLocate[r];
			yLocate[r] = temp;

		}



		
	
	
	}



	private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {
		s = 0; m = 0; //時間歸零
		 Start = 1;

		 Pause_Button->Visible = true;
		 cheat->Visible = true;
		 CountTime->Visible = true;

		C1->Visible = true ;
		C2->Visible = true;
		C3->Visible = true;
		C4->Visible = true;
		C5->Visible = true;
		C6->Visible = true;
		C7->Visible = true;
		C8->Visible = true;
		C9->Visible = true;
		C10->Visible = true;
		C11->Visible = true;
		C12->Visible = true;
		C13->Visible = true;
		C14->Visible = true;
		C15->Visible = true;
		C16->Visible = true;

		start->Visible = false;
		

	}

private: System::Void Visble_true() {
	count = 0;

	if(dis[0]==0){ C1->Visible = true; }
	else { A1->Visible = false; count++; }
	if (dis[1] == 0) { C2->Visible = true; }
	else { A2->Visible = false; count++; }
	if (dis[2] == 0) { C3->Visible = true; }
	else { A3->Visible = false;count++; }
	if (dis[3] == 0) { C4->Visible = true; }
	else { A4->Visible = false; count++;
	}
	if (dis[4] == 0) { C5->Visible = true; }
	else { A5->Visible = false; count++;
	}
	if (dis[5] == 0) { C6->Visible = true; }
	else { A6->Visible = false; count++;
	}
	if (dis[6] == 0) { C7->Visible = true; }
	else { A7->Visible = false; count++;
	}
	if (dis[7] == 0) { C8->Visible = true; }
	else { A8->Visible = false; count++;
	}
	if (dis[8] == 0) { C9->Visible = true; }
	else { A9->Visible = false; count++;
	}
	if (dis[9] == 0) { C10->Visible = true; }
	else { A10->Visible = false; count++;
	}
	if (dis[10] == 0) { C11->Visible = true; }
	else { A11->Visible = false; count++;
	}
	if (dis[11] == 0) { C12->Visible = true; }
	else { A12->Visible = false; count++;
	}
	if (dis[12] == 0) { C13->Visible = true; }
	else { A13->Visible = false; count++;
	}
	if (dis[13] == 0) { C14->Visible = true; }
	else { A14->Visible = false; count++;
	}
	if (dis[14] == 0) { C15->Visible = true; }
	else { A15->Visible = false; count++;
	}
	if (dis[15] == 0) { C16->Visible = true; }
	else { A16->Visible = false; count++;
	}

	
	if (count == 16) {
		//全消除 
		Start = 2; //表示結束

		
		clear_m->Text = System::Convert::ToString(m / 100);
		clear_s->Text = System::Convert::ToString(s / 100);

		
		clear_m->Visible = true;
		clear_s->Visible = true;
		Click_OK->Visible=true;

		clear->Visible = true;

	
		
	}


}

	private: System::Void Cilck(int id, int pair) {
		
		if (click == 0) {

			click++;

			click_ID = id;


		}
		else if (click == 1) {
			click++;

			
			if (click_ID == pair) { // 要消去

				dis[pair-1] = 1;
				dis[id-1] = 1;

			}
		}
	
	
	}


private: System::Void C1_Click(System::Object^  sender, System::EventArgs^  e) {

	if (click < 2 && Start==1) {
		C1->Visible = false;

		Cilck(1, 7);
	}
}
private: System::Void C2_Click(System::Object^  sender, System::EventArgs^  e) {

	if (click < 2 && Start == 1) {
		C2->Visible = false;

		Cilck(2, 12);
	}

}



private: System::Void C3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C3->Visible = false;

		Cilck(3, 14);
	}

}
private: System::Void C4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C4->Visible = false;

		Cilck(4, 9);
	}
}
private: System::Void C5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C5->Visible = false;

		Cilck(5, 11);
	}
}
private: System::Void C6_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C6->Visible = false;

		Cilck(6, 15);
	}
}
private: System::Void C7_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C7->Visible = false;

		Cilck(7, 1);
	}
}
private: System::Void C8_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C8->Visible = false;

		Cilck(8, 16);
	}
}
private: System::Void C9_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C9->Visible = false;

		Cilck(9, 4);
	}
}
private: System::Void C10_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C10->Visible = false;

		Cilck(10, 13);
	}
}
private: System::Void C11_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C11->Visible = false;

		Cilck(11, 5);
	}
}
private: System::Void C12_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) 
		{
		C12->Visible = false;

		Cilck(12, 2);
	}
}
private: System::Void C13_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C13->Visible = false;

		Cilck(13, 10);
	}
}
private: System::Void C14_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C14->Visible = false;

		Cilck(14, 3);
	}
}
private: System::Void C15_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C15->Visible = false;

		Cilck(15, 6);
	}
}
private: System::Void C16_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {
		C16->Visible = false;

		Cilck(16, 8);
	}
}


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (Start == 1) {
		s++;
		if (s == 6000) { s = 0; m+=100; }
		Sec = System::Convert::ToString(s/100);
		Min = System::Convert::ToString(m/100);
		CountTime->Text = Min + ":" + Sec;
	}

	if (Start == 2) {
		

		clear->Visible = true;
		clear_m->Visible = true;
		clear_s->Visible = true;
		Click_OK->Visible = true;

	}

	if (click == 2) { time = 0; click = 3; }
	time++;
	if (time == 80) {
		click = 0; 
		Visble_true();
	}
	if (time > 10000) {
		time = 200;
	}

	
}



private: System::Void 紀錄ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void 結束遊戲ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	Close();

}
private: System::Void Pause_Button_Click(System::Object^  sender, System::EventArgs^  e) {


	Start = (Start+1) % 2;

	if (Start == 0) { Pause_Button->Text = L"繼續"; }
	else{ Pause_Button->Text = L"暫停鍵"; }
}
private: System::Void 關於ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show(L"Unlight memory\n製作人:黃韻儒、莊鈞翔",L"關於");
	
}
private: System::Void cheat_Click(System::Object^  sender, System::EventArgs^  e) {
	if (click < 2 && Start == 1) {


		if (dis[0] == 0) {
			C1->Visible = false;
			C7->Visible = false;
			Cilck(1, 7);
			Cilck(7, 1);
		}
		else if (dis[1] == 0) {
			C12->Visible = false;
			C2->Visible = false;
			Cilck(2, 12);
			Cilck(12, 2);
		}
		else if (dis[2] == 0) {
			C14->Visible = false;
			C3->Visible = false;
			Cilck(3, 14);
			Cilck(14, 3);
		}
		else if (dis[3] == 0) {
			C4->Visible = false;
			C9->Visible = false;
			Cilck(4, 9);
			Cilck(9, 4);
		}
		else if (dis[4] == 0) {
			C5->Visible = false;
			C11->Visible = false;
			Cilck(5, 11);
			Cilck(11, 5);
		}
		else if (dis[5] == 0) {
			C6->Visible = false;
			C15->Visible = false;
			Cilck(6, 15);
			Cilck(15, 6);
		}
		else if (dis[7] == 0) {
			C8->Visible = false;
			C16->Visible = false;
			Cilck(8, 16);
			Cilck(16, 8);
		}
		else if (dis[9] == 0) {
			C10->Visible = false;
			C13->Visible = false;
			Cilck(10, 13);
			Cilck(13, 10);
		}

	}

}
private: System::Void 新遊戲ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	Click_OK->Visible = false;
	clear->Visible = false;
	clear_m->Visible = false;
	clear_s->Visible = false;

	cheat->Visible = false;
	Pause_Button->Visible = false;
	star();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	init->Visible = true;
	start_game->Visible = true;
	close_game->Visible = true;
	
	
}

private: System::Void close_game_Click(System::Object^  sender, System::EventArgs^  e) {

	Close();
}
private: System::Void start_game_Click(System::Object^  sender, System::EventArgs^  e) {
	
	Click_OK->Visible = false;
	clear->Visible = false;
	clear_m->Visible = false;
	clear_s->Visible = false;
	cheat->Visible = false;
	Pause_Button->Visible = false;


	
	start_game->Visible = false;
	close_game->Visible = false;
	init->Visible = false;
	star();

}
private: System::Void Click_OK_Click(System::Object^  sender, System::EventArgs^  e) {

	init->Visible = true;
	start_game->Visible = true;
	close_game->Visible = true;


	
	Click_OK->Visible = false;
	clear->Visible = false;
	clear_m->Visible = false;
	clear_s->Visible = false;
	Start = 0;
}

};
}
