// Copyright © 2019 趙珈葦. All Rights Reserved.
// 系級: 機械109
// 學號: E14056431

#pragma once

namespace HW04_bonus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		bool starter = true; // true: player1, false: player2
		bool turn = true;
		bool gaming = false;
		DateTime timer_start;
		array<int, 2>^ board = gcnew array<int, 2>(4, 4);

	private: System::Windows::Forms::StatusStrip^  status;
	private: System::Windows::Forms::ToolStripStatusLabel^  play_turn;
	private: System::Windows::Forms::PictureBox^  block_4_2;
	private: System::Windows::Forms::PictureBox^  block_4_1;


	private: System::Windows::Forms::PictureBox^  block_4_4;
	private: System::Windows::Forms::PictureBox^  block_4_3;


	private: System::Windows::Forms::PictureBox^  block_2_4;

	private: System::Windows::Forms::PictureBox^  block_1_4;
	private: System::Windows::Forms::PictureBox^  block_3_4;


	private: System::Windows::Forms::ToolStripStatusLabel^  mouse_pos;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  game_btn;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^  timer;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::RadioButton^  player1_btn;
	private: System::Windows::Forms::RadioButton^  player2_btn;
	private: System::Windows::Forms::GroupBox^  player_select;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::PictureBox^  block_3_3;
	private: System::Windows::Forms::PictureBox^  block_3_2;
	private: System::Windows::Forms::PictureBox^  block_3_1;
	private: System::Windows::Forms::PictureBox^  block_2_3;
	private: System::Windows::Forms::PictureBox^  block_2_2;
	private: System::Windows::Forms::PictureBox^  block_2_1;
	private: System::Windows::Forms::PictureBox^  block_1_3;
	private: System::Windows::Forms::PictureBox^  block_1_2;
	private: System::Windows::Forms::PictureBox^  block_1_1;
	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
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
			this->game_btn = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->player1_btn = (gcnew System::Windows::Forms::RadioButton());
			this->player2_btn = (gcnew System::Windows::Forms::RadioButton());
			this->player_select = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->block_4_2 = (gcnew System::Windows::Forms::PictureBox());
			this->block_4_1 = (gcnew System::Windows::Forms::PictureBox());
			this->block_4_4 = (gcnew System::Windows::Forms::PictureBox());
			this->block_4_3 = (gcnew System::Windows::Forms::PictureBox());
			this->block_3_3 = (gcnew System::Windows::Forms::PictureBox());
			this->block_3_2 = (gcnew System::Windows::Forms::PictureBox());
			this->block_3_1 = (gcnew System::Windows::Forms::PictureBox());
			this->block_2_3 = (gcnew System::Windows::Forms::PictureBox());
			this->block_2_2 = (gcnew System::Windows::Forms::PictureBox());
			this->block_2_1 = (gcnew System::Windows::Forms::PictureBox());
			this->block_1_3 = (gcnew System::Windows::Forms::PictureBox());
			this->block_1_2 = (gcnew System::Windows::Forms::PictureBox());
			this->block_1_1 = (gcnew System::Windows::Forms::PictureBox());
			this->block_2_4 = (gcnew System::Windows::Forms::PictureBox());
			this->block_1_4 = (gcnew System::Windows::Forms::PictureBox());
			this->block_3_4 = (gcnew System::Windows::Forms::PictureBox());
			this->status = (gcnew System::Windows::Forms::StatusStrip());
			this->play_turn = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->mouse_pos = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->player_select->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_4))->BeginInit();
			this->status->SuspendLayout();
			this->SuspendLayout();
			// 
			// game_btn
			// 
			this->game_btn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->game_btn->Location = System::Drawing::Point(765, 614);
			this->game_btn->Name = L"game_btn";
			this->game_btn->Size = System::Drawing::Size(305, 50);
			this->game_btn->TabIndex = 0;
			this->game_btn->Text = L"Start";
			this->game_btn->UseVisualStyleBackColor = true;
			this->game_btn->Click += gcnew System::EventHandler(this, &MyForm::game_btn_Click);
			// 
			// timer
			// 
			this->timer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timer->Location = System::Drawing::Point(765, 682);
			this->timer->Name = L"timer";
			this->timer->Size = System::Drawing::Size(305, 50);
			this->timer->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// player1_btn
			// 
			this->player1_btn->AutoSize = true;
			this->player1_btn->Checked = true;
			this->player1_btn->Location = System::Drawing::Point(6, 24);
			this->player1_btn->Name = L"player1_btn";
			this->player1_btn->Size = System::Drawing::Size(73, 19);
			this->player1_btn->TabIndex = 2;
			this->player1_btn->TabStop = true;
			this->player1_btn->Text = L"玩家一";
			this->player1_btn->UseVisualStyleBackColor = true;
			this->player1_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::player1_btn_CheckedChanged);
			// 
			// player2_btn
			// 
			this->player2_btn->AutoSize = true;
			this->player2_btn->Location = System::Drawing::Point(6, 49);
			this->player2_btn->Name = L"player2_btn";
			this->player2_btn->Size = System::Drawing::Size(73, 19);
			this->player2_btn->TabIndex = 3;
			this->player2_btn->TabStop = true;
			this->player2_btn->Text = L"玩家二";
			this->player2_btn->UseVisualStyleBackColor = true;
			this->player2_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::player2_btn_CheckedChanged);
			// 
			// player_select
			// 
			this->player_select->Controls->Add(this->player2_btn);
			this->player_select->Controls->Add(this->player1_btn);
			this->player_select->Location = System::Drawing::Point(765, 12);
			this->player_select->Name = L"player_select";
			this->player_select->Size = System::Drawing::Size(305, 91);
			this->player_select->TabIndex = 5;
			this->player_select->TabStop = false;
			this->player_select->Text = L"先手(O)";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Black;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				180)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				180)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				180)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				183)));
			this->tableLayoutPanel1->Controls->Add(this->block_4_2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->block_4_1, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->block_4_4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->block_4_3, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->block_3_3, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->block_3_2, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->block_3_1, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->block_2_3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->block_2_2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->block_2_1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->block_1_3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->block_1_2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->block_1_1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->block_2_4, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->block_1_4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->block_3_4, 3, 2);
			this->tableLayoutPanel1->Enabled = false;
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(0, 0, 3, 3);
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 180)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 180)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 180)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 183)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(723, 723);
			this->tableLayoutPanel1->TabIndex = 6;
			// 
			// block_4_2
			// 
			this->block_4_2->BackColor = System::Drawing::Color::White;
			this->block_4_2->Location = System::Drawing::Point(183, 543);
			this->block_4_2->Margin = System::Windows::Forms::Padding(3, 3, 0, 3);
			this->block_4_2->Name = L"block_4_2";
			this->block_4_2->Size = System::Drawing::Size(177, 177);
			this->block_4_2->TabIndex = 15;
			this->block_4_2->TabStop = false;
			this->block_4_2->Click += gcnew System::EventHandler(this, &MyForm::block_4_2_Click);
			this->block_4_2->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_4_2->MouseHover += gcnew System::EventHandler(this, &MyForm::block_4_2_MouseHover);

			// 
			// block_4_1
			// 
			this->block_4_1->BackColor = System::Drawing::Color::White;
			this->block_4_1->Location = System::Drawing::Point(3, 543);
			this->block_4_1->Margin = System::Windows::Forms::Padding(3, 3, 0, 3);
			this->block_4_1->Name = L"block_4_1";
			this->block_4_1->Size = System::Drawing::Size(177, 177);
			this->block_4_1->TabIndex = 14;
			this->block_4_1->TabStop = false;
			this->block_4_1->Click += gcnew System::EventHandler(this, &MyForm::block_4_1_Click);
			this->block_4_1->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_4_1->MouseHover += gcnew System::EventHandler(this, &MyForm::block_4_1_MouseHover);
			// 
			// block_4_4
			// 
			this->block_4_4->BackColor = System::Drawing::Color::White;
			this->block_4_4->Location = System::Drawing::Point(543, 543);
			this->block_4_4->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->block_4_4->Name = L"block_4_4";
			this->block_4_4->Size = System::Drawing::Size(177, 177);
			this->block_4_4->TabIndex = 13;
			this->block_4_4->TabStop = false;
			this->block_4_4->Click += gcnew System::EventHandler(this, &MyForm::block_4_4_Click);
			this->block_4_4->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_4_4->MouseHover += gcnew System::EventHandler(this, &MyForm::block_4_4_MouseHover);
			// 
			// block_4_3
			// 
			this->block_4_3->BackColor = System::Drawing::Color::White;
			this->block_4_3->Location = System::Drawing::Point(363, 543);
			this->block_4_3->Margin = System::Windows::Forms::Padding(3, 3, 0, 3);
			this->block_4_3->Name = L"block_4_3";
			this->block_4_3->Size = System::Drawing::Size(177, 177);
			this->block_4_3->TabIndex = 12;
			this->block_4_3->TabStop = false;
			this->block_4_3->Click += gcnew System::EventHandler(this, &MyForm::block_4_3_Click);
			this->block_4_3->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_4_3->MouseHover += gcnew System::EventHandler(this, &MyForm::block_4_3_MouseHover);
			// 
			// block_3_3
			// 
			this->block_3_3->BackColor = System::Drawing::Color::White;
			this->block_3_3->Location = System::Drawing::Point(363, 363);
			this->block_3_3->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_3_3->Name = L"block_3_3";
			this->block_3_3->Size = System::Drawing::Size(177, 177);
			this->block_3_3->TabIndex = 8;
			this->block_3_3->TabStop = false;
			this->block_3_3->Click += gcnew System::EventHandler(this, &MyForm::block_3_3_Click);
			this->block_3_3->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_3_3->MouseHover += gcnew System::EventHandler(this, &MyForm::block_3_3_MouseHover);
			// 
			// block_3_2
			// 
			this->block_3_2->BackColor = System::Drawing::Color::White;
			this->block_3_2->Location = System::Drawing::Point(183, 363);
			this->block_3_2->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_3_2->Name = L"block_3_2";
			this->block_3_2->Size = System::Drawing::Size(177, 177);
			this->block_3_2->TabIndex = 7;
			this->block_3_2->TabStop = false;
			this->block_3_2->Click += gcnew System::EventHandler(this, &MyForm::block_3_2_Click);
			this->block_3_2->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_3_2->MouseHover += gcnew System::EventHandler(this, &MyForm::block_3_2_MouseHover);
			// 
			// block_3_1
			// 
			this->block_3_1->BackColor = System::Drawing::Color::White;
			this->block_3_1->Location = System::Drawing::Point(3, 363);
			this->block_3_1->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_3_1->Name = L"block_3_1";
			this->block_3_1->Size = System::Drawing::Size(177, 177);
			this->block_3_1->TabIndex = 6;
			this->block_3_1->TabStop = false;
			this->block_3_1->Click += gcnew System::EventHandler(this, &MyForm::block_3_1_Click);
			this->block_3_1->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_3_1->MouseHover += gcnew System::EventHandler(this, &MyForm::block_3_1_MouseHover);
			// 
			// block_2_3
			// 
			this->block_2_3->BackColor = System::Drawing::Color::White;
			this->block_2_3->Location = System::Drawing::Point(363, 183);
			this->block_2_3->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_2_3->Name = L"block_2_3";
			this->block_2_3->Size = System::Drawing::Size(177, 177);
			this->block_2_3->TabIndex = 5;
			this->block_2_3->TabStop = false;
			this->block_2_3->Click += gcnew System::EventHandler(this, &MyForm::block_2_3_Click);
			this->block_2_3->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_2_3->MouseHover += gcnew System::EventHandler(this, &MyForm::block_2_3_MouseHover);
			// 
			// block_2_2
			// 
			this->block_2_2->BackColor = System::Drawing::Color::White;
			this->block_2_2->Location = System::Drawing::Point(183, 183);
			this->block_2_2->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_2_2->Name = L"block_2_2";
			this->block_2_2->Size = System::Drawing::Size(177, 177);
			this->block_2_2->TabIndex = 4;
			this->block_2_2->TabStop = false;
			this->block_2_2->Click += gcnew System::EventHandler(this, &MyForm::block_2_2_Click);
			this->block_2_2->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_2_2->MouseHover += gcnew System::EventHandler(this, &MyForm::block_2_2_MouseHover);
			// 
			// block_2_1
			// 
			this->block_2_1->BackColor = System::Drawing::Color::White;
			this->block_2_1->Location = System::Drawing::Point(3, 183);
			this->block_2_1->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_2_1->Name = L"block_2_1";
			this->block_2_1->Size = System::Drawing::Size(177, 177);
			this->block_2_1->TabIndex = 3;
			this->block_2_1->TabStop = false;
			this->block_2_1->Click += gcnew System::EventHandler(this, &MyForm::block_2_1_Click);
			this->block_2_1->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_2_1->MouseHover += gcnew System::EventHandler(this, &MyForm::block_2_1_MouseHover);
			// 
			// block_1_3
			// 
			this->block_1_3->BackColor = System::Drawing::Color::White;
			this->block_1_3->Location = System::Drawing::Point(363, 3);
			this->block_1_3->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_1_3->Name = L"block_1_3";
			this->block_1_3->Size = System::Drawing::Size(177, 177);
			this->block_1_3->TabIndex = 2;
			this->block_1_3->TabStop = false;
			this->block_1_3->Click += gcnew System::EventHandler(this, &MyForm::block_1_3_Click);
			this->block_1_3->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_1_3->MouseHover += gcnew System::EventHandler(this, &MyForm::block_1_3_MouseHover);
			// 
			// block_1_2
			// 
			this->block_1_2->BackColor = System::Drawing::Color::White;
			this->block_1_2->Location = System::Drawing::Point(183, 3);
			this->block_1_2->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_1_2->Name = L"block_1_2";
			this->block_1_2->Size = System::Drawing::Size(177, 177);
			this->block_1_2->TabIndex = 1;
			this->block_1_2->TabStop = false;
			this->block_1_2->Click += gcnew System::EventHandler(this, &MyForm::block_1_2_Click);
			this->block_1_2->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_1_2->MouseHover += gcnew System::EventHandler(this, &MyForm::block_1_2_MouseHover);
			// 
			// block_1_1
			// 
			this->block_1_1->BackColor = System::Drawing::Color::White;
			this->block_1_1->Location = System::Drawing::Point(3, 3);
			this->block_1_1->Margin = System::Windows::Forms::Padding(3, 3, 0, 0);
			this->block_1_1->Name = L"block_1_1";
			this->block_1_1->Size = System::Drawing::Size(177, 177);
			this->block_1_1->TabIndex = 0;
			this->block_1_1->TabStop = false;
			this->block_1_1->Click += gcnew System::EventHandler(this, &MyForm::block_1_1_Click);
			this->block_1_1->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_1_1->MouseHover += gcnew System::EventHandler(this, &MyForm::block_1_1_MouseHover);
			// 
			// block_2_4
			// 
			this->block_2_4->BackColor = System::Drawing::Color::White;
			this->block_2_4->Location = System::Drawing::Point(543, 183);
			this->block_2_4->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->block_2_4->Name = L"block_2_4";
			this->block_2_4->Size = System::Drawing::Size(177, 177);
			this->block_2_4->TabIndex = 10;
			this->block_2_4->TabStop = false;
			this->block_2_4->Click += gcnew System::EventHandler(this, &MyForm::block_2_4_Click);
			this->block_2_4->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_2_4->MouseHover += gcnew System::EventHandler(this, &MyForm::block_2_4_MouseHover);
			// 
			// block_1_4
			// 
			this->block_1_4->BackColor = System::Drawing::Color::White;
			this->block_1_4->Location = System::Drawing::Point(543, 3);
			this->block_1_4->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->block_1_4->Name = L"block_1_4";
			this->block_1_4->Size = System::Drawing::Size(177, 177);
			this->block_1_4->TabIndex = 9;
			this->block_1_4->TabStop = false;
			this->block_1_4->Click += gcnew System::EventHandler(this, &MyForm::block_1_4_Click);
			this->block_1_4->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_1_4->MouseHover += gcnew System::EventHandler(this, &MyForm::block_1_4_MouseHover);
			// 
			// block_3_4
			// 
			this->block_3_4->BackColor = System::Drawing::Color::White;
			this->block_3_4->Location = System::Drawing::Point(543, 363);
			this->block_3_4->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->block_3_4->Name = L"block_3_4";
			this->block_3_4->Size = System::Drawing::Size(177, 177);
			this->block_3_4->TabIndex = 11;
			this->block_3_4->TabStop = false;
			this->block_3_4->Click += gcnew System::EventHandler(this, &MyForm::block_3_4_Click);
			this->block_3_4->MouseLeave += gcnew System::EventHandler(this, &MyForm::block_MouseLeave);
			this->block_3_4->MouseHover += gcnew System::EventHandler(this, &MyForm::block_3_4_MouseHover);
			// 
			// status
			// 
			this->status->ImageScalingSize = System::Drawing::Size(20, 20);
			this->status->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->play_turn, this->mouse_pos });
			this->status->Location = System::Drawing::Point(0, 741);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(1082, 22);
			this->status->TabIndex = 7;
			this->status->Text = L"玩家一";
			// 
			// play_turn
			// 
			this->play_turn->Name = L"play_turn";
			this->play_turn->Size = System::Drawing::Size(0, 17);
			// 
			// mouse_pos
			// 
			this->mouse_pos->Name = L"mouse_pos";
			this->mouse_pos->Size = System::Drawing::Size(0, 17);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1082, 763);
			this->Controls->Add(this->status);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->player_select);
			this->Controls->Add(this->timer);
			this->Controls->Add(this->game_btn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->player_select->ResumeLayout(false);
			this->player_select->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_4_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_2_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_1_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->block_3_4))->EndInit();
			this->status->ResumeLayout(false);
			this->status->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Start / Stop
	private: System::Void game_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!gaming)
		{
			gaming = true;
			turn = starter;
			timer_start = DateTime::Now;
			this->game_btn->Text = "Stop";
			this->timer1->Enabled = true;
			this->player_select->Enabled = false;
			this->tableLayoutPanel1->Enabled = true;
			board_ini();
			if (turn)
				this->play_turn->Text = "玩家一";
			else
				this->play_turn->Text = "玩家二";
		}
		else
		{
			gaming = false;
			this->game_btn->Text = "Start";
			this->timer1->Enabled = false;
			this->player_select->Enabled = true;
			this->tableLayoutPanel1->Enabled = false;
			this->play_turn->Text = "";
		}
	}

			 // Timer action per tick
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (gaming)
		{
			DateTime now = DateTime::Now;
			this->timer->Text = (now - timer_start).ToString();
		}
	}

			 // Player select
	private: System::Void player1_btn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		starter = true;
	}
	private: System::Void player2_btn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		starter = false;
	}

			 // Blocks click action
	private: System::Void block_1_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[0, 0] == -1)
		{
			board[0, 0] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_1_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_1_1->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_1_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_1_1->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_2_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[1, 2] == -1)
		{
			board[1, 2] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_2_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_3->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_2_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_3->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_2_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[1, 3] == -1)
		{
			board[1, 3] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_2_4->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_4->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_2_4->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_4->Image = image;
			}
			turn_change();
		}
	}
			 private: System::Void block_1_4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (board[0, 3] == -1)
				 {
					 board[0, 3] = turn ? 1 : 0;
					 if (turn == starter) {
						 Bitmap^ image = gcnew Bitmap("./res/circle.png");
						 this->block_1_4->SizeMode = PictureBoxSizeMode::StretchImage;
						 this->block_1_4->Image = image;
					 }
					 else {
						 Bitmap^ image = gcnew Bitmap("./res/cross.png");
						 this->block_1_4->SizeMode = PictureBoxSizeMode::StretchImage;
						 this->block_1_4->Image = image;
					 }
					 turn_change();
				 }
			 }
	private: System::Void block_1_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[0, 2] == -1)
		{
			board[0, 2] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_1_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_1_3->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_1_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_1_3->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_1_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[0, 1] == -1)
		{
			board[0, 1] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_1_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_1_2->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_1_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_1_2->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_2_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[1, 0] == -1)
		{
			board[1, 0] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_2_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_1->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_2_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_1->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_2_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[1, 1] == -1)
		{
			board[1, 1] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_2_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_2->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_2_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_2_2->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_3_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[2, 3] == -1)
		{
			board[2, 3] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_3_4->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_4->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_3_4->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_4->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_3_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[2, 2] == -1)
		{
			board[2, 2] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_3_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_3->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_3_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_3->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_3_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[2, 1] == -1)
		{
			board[2, 1] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_3_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_2->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_3_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_2->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_3_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[2, 0] == -1)
		{
			board[2, 0] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_3_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_1->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_3_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_3_1->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_4_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[3, 3] == -1)
		{
			board[3, 3] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_4_4->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_4->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_4_4->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_4->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_4_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[3, 2] == -1)
		{
			board[3, 2] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_4_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_3->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_4_3->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_3->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_4_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[3, 1] == -1)
		{
			board[3, 1] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_4_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_2->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_4_2->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_2->Image = image;
			}
			turn_change();
		}
	}
	private: System::Void block_4_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (board[3, 0] == -1)
		{
			board[3, 0] = turn ? 1 : 0;
			if (turn == starter) {
				Bitmap^ image = gcnew Bitmap("./res/circle.png");
				this->block_4_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_1->Image = image;
			}
			else {
				Bitmap^ image = gcnew Bitmap("./res/cross.png");
				this->block_4_1->SizeMode = PictureBoxSizeMode::StretchImage;
				this->block_4_1->Image = image;
			}
			turn_change();
		}
	}

			 // Mouse hover & leave action
	private: System::Void block_1_1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(1, 1)";
	}
	private: System::Void block_2_4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(2, 4)";
	}
	private: System::Void block_2_3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(2, 3)";
	}
	private: System::Void block_1_4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(1, 4)";
	}
	private: System::Void block_1_3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(1, 3)";
	}
	private: System::Void block_1_2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(1, 2)";
	}
	private: System::Void block_2_1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(2, 1)";
	}
	private: System::Void block_2_2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(2, 2)";
	}
	private: System::Void block_3_4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(3, 4)";
	}
	private: System::Void block_3_3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(3, 3)";
	}
	private: System::Void block_3_2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(3, 2)";
	}
	private: System::Void block_3_1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(3, 1)";
	}
	private: System::Void block_4_4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(4, 4)";
	}
	private: System::Void block_4_3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(4, 3)";
	}
	private: System::Void block_4_2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(4, 2)";
	}
	private: System::Void block_4_1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "滑鼠目前位置:(4, 1)";
	}
	private: System::Void block_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		this->mouse_pos->Text = "";
	}

	private:
		// Check if one wins ( 1: not yet, 2: draw, 3: player1, 4: player2 )
		int win() {
			// rows & columns
			for (int i = 0; i < 4; i++)
			{
				if (board[i, 0] == board[i, 1] && board[i, 1] == board[i, 2] && board[i, 2] == board[i, 3])
				{
					if (board[i, 0] == 0) return 4;
					else if (board[i, 0] == 1) return 3;
				}
				if (board[0, i] == board[1, i] && board[1, i] == board[2, i] && board[2, i] == board[3, i])
				{
					if (board[0, i] == 0) return 4;
					else if (board[0, i] == 1) return 3;
				}
			}

			// diagonal
			if (board[0, 0] == board[1, 1] && board[1, 1] == board[2, 2] && board[2, 2] == board[3, 3])
			{
				if (board[0, 0] == 0) return 4;
				else if (board[0, 0] == 1) return 3;
			}
			if (board[3, 0] == board[2, 1] && board[2, 1] == board[1, 2] && board[1, 2] == board[0, 3])
			{
				if (board[3, 0] == 0) return 4;
				else if (board[3, 0] == 1) return 3;
			}

			// draw
			bool draw = true;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (board[i, j] == -1)
						draw = false;
			if (draw) return 2;
			else return 1;
		}

		// Change turn and hint ( after winning checking
		void turn_change() {
			int game_state = win();

			// player1 wins
			if (game_state == 3) {
				gaming = false;
				this->game_btn->Text = "Start";
				this->timer1->Enabled = false;
				this->player_select->Enabled = true;
				this->tableLayoutPanel1->Enabled = false;
				this->play_turn->Text = "";
				this->play_turn->Text = "玩家一獲勝!!!!!!!!!!!";
				return;
			}
			// player2 wins
			else if (game_state == 4) {
				gaming = false;
				this->game_btn->Text = "Start";
				this->timer1->Enabled = false;
				this->player_select->Enabled = true;
				this->tableLayoutPanel1->Enabled = false;
				this->play_turn->Text = "";
				this->play_turn->Text = "玩家二獲勝!!!!!!!!!!!";
				return;
			}
			// draw
			else if (game_state == 2) {
				gaming = false;
				this->game_btn->Text = "Start";
				this->timer1->Enabled = false;
				this->player_select->Enabled = true;
				this->tableLayoutPanel1->Enabled = false;
				this->play_turn->Text = "";
				this->play_turn->Text = "雙方平手~~~~~~";
				return;
			}
			// not over yet
			turn = !turn;
			if (turn)
				this->play_turn->Text = "玩家一";
			else
				this->play_turn->Text = "玩家二";
		}

		// Initialize the board and pics
		void board_ini() {
			// board info
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					this->board[i, j] = -1;

			// pics
			Image^ temp = this->block_1_1->Image;
			this->block_1_1->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_1_2->Image;
			this->block_1_2->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_1_3->Image;
			this->block_1_3->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_1_4->Image;
			this->block_1_4->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_2_1->Image;
			this->block_2_1->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_2_2->Image;
			this->block_2_2->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_2_3->Image;
			this->block_2_3->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_2_4->Image;
			this->block_2_4->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_3_1->Image;
			this->block_3_1->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_3_2->Image;
			this->block_3_2->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_3_3->Image;
			this->block_3_3->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_3_4->Image;
			this->block_3_4->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_4_1->Image;
			this->block_4_1->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_4_2->Image;
			this->block_4_2->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_4_3->Image;
			this->block_4_3->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();

			temp = this->block_4_4->Image;
			this->block_4_4->Image = nullptr;
			if (temp != nullptr)
				temp->~Image();
		}
	};
}
