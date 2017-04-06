#pragma once
#include "stdafx.h"
#include "Dealer.h"
#include "SimForm.h"
namespace ChinesePoker 
{
	public ref class Form1 : public System::Windows::Forms::Form
	{
		array<float, 2> ^handValue;
		Dealer ^table;
		String ^activeBrainFilename;
	
	private: System::Windows::Forms::MenuStrip^  mStrip_main;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadSavedStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveCurrentStatsToolStripMenuItem;
	private: System::Windows::Forms::Button^  btn_reset;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  mergeCurrentAndSavedStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  playerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadYourSavedStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveYourCurrentStatsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  highScoresToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveCurrentStatsAsToolStripMenuItem;

		#pragma region Constructor/Destructor
		public: Form1(void)
		{
			InitializeComponent();
			InitPicBoxArray();
			initMousePos = Point::Empty;
			for(int i = 0; i < 13; i++)
			{
				picBox[i]->Location = Point(11 + (30 + hScrollBar1->Value) * i, 501);
				picBox[i]->BringToFront();
			}
			panel1->Hide();
			panel2->Hide();
			panel3->Hide();
			
			score = gcnew array<int>(4);
			table = gcnew Dealer();
			handValue = gcnew array<float, 2>(4, 3);
		}

		protected: ~Form1()
		{
			delete handValue;
			if (components)
			{
				delete components;
			}
			delete picBox;
			delete picBoxData;
		}

		#pragma endregion
		#pragma region GUI Variables	
		// PictureBox interaction variables
		private: PictureBox ^draggedPB;
		private: array<PictureBox ^> ^picBox;
		private: array<int> ^picBoxData;
		private: Point initMousePos;
		private: Point initPBPos;
		private: static bool CtrlPressed = false;
		private: static int cardsSelected = 0;
		private: static bool stackedDeck = false;
		private: array<int> ^score;
		#pragma endregion
		#pragma region Component Declarations
		private: System::ComponentModel::Container ^components; // Required designer variable
		private: System::Windows::Forms::CheckBox^  cBox_ShowEV;
		private: System::Windows::Forms::Button^  btn_SelLower;
		private: System::Windows::Forms::Button^  btn_SelUpper;
		private: System::Windows::Forms::PictureBox^  pictureBox1;
		private: System::Windows::Forms::PictureBox^  pictureBox2;
		private: System::Windows::Forms::PictureBox^  pictureBox3;
		private: System::Windows::Forms::PictureBox^  pictureBox4;
		private: System::Windows::Forms::PictureBox^  pictureBox5;
		private: System::Windows::Forms::PictureBox^  pictureBox6;
		private: System::Windows::Forms::PictureBox^  pictureBox7;
		private: System::Windows::Forms::PictureBox^  pictureBox8;
		private: System::Windows::Forms::PictureBox^  pictureBox9;
		private: System::Windows::Forms::PictureBox^  pictureBox10;
		private: System::Windows::Forms::PictureBox^  pictureBox11;
		private: System::Windows::Forms::PictureBox^  pictureBox12;
		private: System::Windows::Forms::PictureBox^  pictureBox13;
		private: System::Windows::Forms::PictureBox^  pictureBox14;
		private: System::Windows::Forms::PictureBox^  pictureBox15;
		private: System::Windows::Forms::PictureBox^  pictureBox16;
		private: System::Windows::Forms::PictureBox^  pictureBox17;
		private: System::Windows::Forms::PictureBox^  pictureBox18;
		private: System::Windows::Forms::PictureBox^  pictureBox19;
		private: System::Windows::Forms::PictureBox^  pictureBox20;
		private: System::Windows::Forms::PictureBox^  pictureBox21;
		private: System::Windows::Forms::PictureBox^  pictureBox22;
		private: System::Windows::Forms::PictureBox^  pictureBox23;
		private: System::Windows::Forms::PictureBox^  pictureBox24;
		private: System::Windows::Forms::PictureBox^  pictureBox25;
		private: System::Windows::Forms::PictureBox^  pictureBox26;
		private: System::Windows::Forms::PictureBox^  pictureBox27;
		private: System::Windows::Forms::PictureBox^  pictureBox28;
		private: System::Windows::Forms::PictureBox^  pictureBox29;
		private: System::Windows::Forms::PictureBox^  pictureBox30;
		private: System::Windows::Forms::PictureBox^  pictureBox31;
		private: System::Windows::Forms::PictureBox^  pictureBox32;
		private: System::Windows::Forms::PictureBox^  pictureBox33;
		private: System::Windows::Forms::PictureBox^  pictureBox34;
		private: System::Windows::Forms::PictureBox^  pictureBox35;
		private: System::Windows::Forms::PictureBox^  pictureBox36;
		private: System::Windows::Forms::PictureBox^  pictureBox37;
		private: System::Windows::Forms::PictureBox^  pictureBox38;
		private: System::Windows::Forms::PictureBox^  pictureBox39;
		private: System::Windows::Forms::PictureBox^  pictureBox40;
		private: System::Windows::Forms::PictureBox^  pictureBox41;
		private: System::Windows::Forms::PictureBox^  pictureBox42;
		private: System::Windows::Forms::PictureBox^  pictureBox43;
		private: System::Windows::Forms::PictureBox^  pictureBox44;
		private: System::Windows::Forms::PictureBox^  pictureBox45;
		private: System::Windows::Forms::PictureBox^  pictureBox46;
		private: System::Windows::Forms::PictureBox^  pictureBox47;
		private: System::Windows::Forms::PictureBox^  pictureBox48;
		private: System::Windows::Forms::PictureBox^  pictureBox49;
		private: System::Windows::Forms::PictureBox^  pictureBox50;
		private: System::Windows::Forms::PictureBox^  pictureBox51;
		private: System::Windows::Forms::PictureBox^  pictureBox52;
		private: System::Windows::Forms::PictureBox^  pictureBox53;
		private: System::Windows::Forms::PictureBox^  pictureBox54;
		private: System::Windows::Forms::PictureBox^  pictureBox55;
		private: System::Windows::Forms::PictureBox^  pictureBox56;
		private: System::Windows::Forms::PictureBox^  pictureBox57;
		private: System::Windows::Forms::PictureBox^  pictureBox58;
		private: System::Windows::Forms::PictureBox^  pictureBox59;
		private: System::Windows::Forms::PictureBox^  pictureBox60;
		private: System::Windows::Forms::PictureBox^  pictureBox61;
		private: System::Windows::Forms::PictureBox^  pictureBox62;
		private: System::Windows::Forms::PictureBox^  pictureBox63;
		private: System::Windows::Forms::PictureBox^  pictureBox64;
		private: System::Windows::Forms::PictureBox^  pictureBox65;
		private: System::Windows::Forms::PictureBox^  pictureBox117;
		private: System::Windows::Forms::PictureBox^  pictureBox116;
		private: System::Windows::Forms::PictureBox^  pictureBox115;
		private: System::Windows::Forms::PictureBox^  pictureBox114;
		private: System::Windows::Forms::PictureBox^  pictureBox113;
		private: System::Windows::Forms::PictureBox^  pictureBox112;
		private: System::Windows::Forms::PictureBox^  pictureBox111;
		private: System::Windows::Forms::PictureBox^  pictureBox110;
		private: System::Windows::Forms::PictureBox^  pictureBox109;
		private: System::Windows::Forms::PictureBox^  pictureBox108;
		private: System::Windows::Forms::PictureBox^  pictureBox107;
		private: System::Windows::Forms::PictureBox^  pictureBox106;
		private: System::Windows::Forms::PictureBox^  pictureBox105;
		private: System::Windows::Forms::PictureBox^  pictureBox104;
		private: System::Windows::Forms::PictureBox^  pictureBox103;
		private: System::Windows::Forms::PictureBox^  pictureBox102;
		private: System::Windows::Forms::PictureBox^  pictureBox101;
		private: System::Windows::Forms::PictureBox^  pictureBox100;
		private: System::Windows::Forms::PictureBox^  pictureBox99;
		private: System::Windows::Forms::PictureBox^  pictureBox98;
		private: System::Windows::Forms::PictureBox^  pictureBox97;
		private: System::Windows::Forms::PictureBox^  pictureBox96;
		private: System::Windows::Forms::PictureBox^  pictureBox95;
		private: System::Windows::Forms::PictureBox^  pictureBox94;
		private: System::Windows::Forms::PictureBox^  pictureBox93;
		private: System::Windows::Forms::PictureBox^  pictureBox92;
		private: System::Windows::Forms::PictureBox^  pictureBox91;
		private: System::Windows::Forms::PictureBox^  pictureBox90;
		private: System::Windows::Forms::PictureBox^  pictureBox89;
		private: System::Windows::Forms::PictureBox^  pictureBox88;
		private: System::Windows::Forms::PictureBox^  pictureBox87;
		private: System::Windows::Forms::PictureBox^  pictureBox86;
		private: System::Windows::Forms::PictureBox^  pictureBox85;
		private: System::Windows::Forms::PictureBox^  pictureBox84;
		private: System::Windows::Forms::PictureBox^  pictureBox83;
		private: System::Windows::Forms::PictureBox^  pictureBox82;
		private: System::Windows::Forms::PictureBox^  pictureBox81;
		private: System::Windows::Forms::PictureBox^  pictureBox80;
		private: System::Windows::Forms::PictureBox^  pictureBox79;
		private: System::Windows::Forms::PictureBox^  pictureBox78;
		private: System::Windows::Forms::PictureBox^  pictureBox77;
		private: System::Windows::Forms::PictureBox^  pictureBox76;
		private: System::Windows::Forms::PictureBox^  pictureBox75;
		private: System::Windows::Forms::PictureBox^  pictureBox74;
		private: System::Windows::Forms::PictureBox^  pictureBox73;
		private: System::Windows::Forms::PictureBox^  pictureBox72;
		private: System::Windows::Forms::PictureBox^  pictureBox71;
		private: System::Windows::Forms::PictureBox^  pictureBox70;
		private: System::Windows::Forms::PictureBox^  pictureBox69;
		private: System::Windows::Forms::PictureBox^  pictureBox68;
		private: System::Windows::Forms::PictureBox^  pictureBox67;
		private: System::Windows::Forms::PictureBox^  pictureBox66;
		private: System::Windows::Forms::Panel^  panel1;
		private: System::Windows::Forms::Panel^  panel2;
		private: System::Windows::Forms::Panel^  panel3;
		private: System::Windows::Forms::Button^  btn_deal;
		private: System::Windows::Forms::Button^  btn_build;
		private: System::Windows::Forms::Button^  btn_submit;
		private: System::Windows::Forms::Button^  btn_stack;
		private: System::Windows::Forms::Button^  btn_sim;
		private: System::Windows::Forms::Button^  btn_Sort_Rank;
		private: System::Windows::Forms::Button^  btn_Sort_Suit;
		private: System::Windows::Forms::Button^  btn_Clear_Scores;
		private: System::Windows::Forms::Label^  lbl_score0;
		private: System::Windows::Forms::Label^  lbl_score1;
		private: System::Windows::Forms::Label^  lbl_score2;
		private: System::Windows::Forms::Label^  lbl_score3;
		private: System::Windows::Forms::TextBox^  lbl_EV;
		private: System::Windows::Forms::RadioButton^  rBtn_high;
		private: System::Windows::Forms::RadioButton^  rBtn_low;

		private: System::Windows::Forms::HScrollBar^  hScrollBar1;
		#pragma endregion
		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox58 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox59 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox60 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox61 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox62 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox63 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox64 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox65 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_deal = (gcnew System::Windows::Forms::Button());
			this->btn_build = (gcnew System::Windows::Forms::Button());
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			this->btn_stack = (gcnew System::Windows::Forms::Button());
			this->btn_sim = (gcnew System::Windows::Forms::Button());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->pictureBox117 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox116 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox115 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox114 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox113 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox112 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox111 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox110 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox109 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox108 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox107 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox106 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox105 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox104 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox103 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox102 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox101 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox100 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox99 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox98 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox97 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox96 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox95 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox94 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox93 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox92 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox91 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox90 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox89 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox88 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox87 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox86 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox85 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox84 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox83 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox82 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox81 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox80 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox79 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox78 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox77 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox76 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox75 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox74 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox73 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox72 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox71 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox70 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox69 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox68 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox67 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox66 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_Sort_Rank = (gcnew System::Windows::Forms::Button());
			this->btn_Sort_Suit = (gcnew System::Windows::Forms::Button());
			this->btn_Clear_Scores = (gcnew System::Windows::Forms::Button());
			this->lbl_score0 = (gcnew System::Windows::Forms::Label());
			this->lbl_score1 = (gcnew System::Windows::Forms::Label());
			this->lbl_score2 = (gcnew System::Windows::Forms::Label());
			this->lbl_score3 = (gcnew System::Windows::Forms::Label());
			this->lbl_EV = (gcnew System::Windows::Forms::TextBox());
			this->rBtn_high = (gcnew System::Windows::Forms::RadioButton());
			this->rBtn_low = (gcnew System::Windows::Forms::RadioButton());
			this->btn_SelLower = (gcnew System::Windows::Forms::Button());
			this->btn_SelUpper = (gcnew System::Windows::Forms::Button());
			this->cBox_ShowEV = (gcnew System::Windows::Forms::CheckBox());
			this->mStrip_main = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadSavedStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mergeCurrentAndSavedStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCurrentStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCurrentStatsAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->playerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadYourSavedStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveYourCurrentStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->highScoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox58))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox59))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox60))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox65))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox117))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox116))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox115))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox114))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox113))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox112))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox111))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox110))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox109))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox108))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox107))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox106))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox105))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox104))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox103))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox102))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox101))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox100))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox99))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox98))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox97))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox96))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox95))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox94))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox93))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox92))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox91))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox90))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox89))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox88))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox87))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox86))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox85))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox84))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox83))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox82))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox81))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox80))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox79))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox78))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox77))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox76))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox75))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox73))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox70))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox69))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox68))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox67))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox66))->BeginInit();
			this->mStrip_main->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->Location = System::Drawing::Point(11, 349);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(90, 120);
			this->pictureBox14->TabIndex = 14;
			this->pictureBox14->TabStop = false;
			this->pictureBox14->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox14->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox14->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox15.Image")));
			this->pictureBox15->Location = System::Drawing::Point(107, 349);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(90, 120);
			this->pictureBox15->TabIndex = 15;
			this->pictureBox15->TabStop = false;
			this->pictureBox15->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox15->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox15->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox15->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox16.Image")));
			this->pictureBox16->Location = System::Drawing::Point(203, 349);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(90, 120);
			this->pictureBox16->TabIndex = 16;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox16->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox16->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox16->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox17
			// 
			this->pictureBox17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox17.Image")));
			this->pictureBox17->Location = System::Drawing::Point(299, 349);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(90, 120);
			this->pictureBox17->TabIndex = 17;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox17->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox17->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox17->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox18
			// 
			this->pictureBox18->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox18.Image")));
			this->pictureBox18->Location = System::Drawing::Point(395, 349);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(90, 120);
			this->pictureBox18->TabIndex = 18;
			this->pictureBox18->TabStop = false;
			this->pictureBox18->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox18->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox18->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox18->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox19
			// 
			this->pictureBox19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->Location = System::Drawing::Point(11, 223);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(90, 120);
			this->pictureBox19->TabIndex = 19;
			this->pictureBox19->TabStop = false;
			this->pictureBox19->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox19->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox19->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox19->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox20
			// 
			this->pictureBox20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox20.Image")));
			this->pictureBox20->Location = System::Drawing::Point(107, 223);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(90, 120);
			this->pictureBox20->TabIndex = 20;
			this->pictureBox20->TabStop = false;
			this->pictureBox20->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox20->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox20->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox20->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox21
			// 
			this->pictureBox21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox21.Image")));
			this->pictureBox21->Location = System::Drawing::Point(203, 223);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(90, 120);
			this->pictureBox21->TabIndex = 21;
			this->pictureBox21->TabStop = false;
			this->pictureBox21->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox21->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox21->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox21->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox22
			// 
			this->pictureBox22->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox22.Image")));
			this->pictureBox22->Location = System::Drawing::Point(299, 223);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(90, 120);
			this->pictureBox22->TabIndex = 22;
			this->pictureBox22->TabStop = false;
			this->pictureBox22->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox22->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox22->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox22->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox24
			// 
			this->pictureBox24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox24->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox24.Image")));
			this->pictureBox24->Location = System::Drawing::Point(107, 97);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(90, 120);
			this->pictureBox24->TabIndex = 24;
			this->pictureBox24->TabStop = false;
			this->pictureBox24->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox24->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox24->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox24->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox25
			// 
			this->pictureBox25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox25.Image")));
			this->pictureBox25->Location = System::Drawing::Point(203, 97);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(90, 120);
			this->pictureBox25->TabIndex = 27;
			this->pictureBox25->TabStop = false;
			this->pictureBox25->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox25->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox25->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox25->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox26
			// 
			this->pictureBox26->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox26.Image")));
			this->pictureBox26->Location = System::Drawing::Point(299, 97);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(90, 120);
			this->pictureBox26->TabIndex = 28;
			this->pictureBox26->TabStop = false;
			this->pictureBox26->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox26->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox26->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox26->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox23
			// 
			this->pictureBox23->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox23->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox23.Image")));
			this->pictureBox23->Location = System::Drawing::Point(395, 223);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(90, 120);
			this->pictureBox23->TabIndex = 23;
			this->pictureBox23->TabStop = false;
			this->pictureBox23->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox23->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox23->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox23->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(11, 500);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(90, 120);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(107, 500);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(90, 120);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(203, 500);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(90, 120);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(299, 500);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(90, 120);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox4->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(395, 500);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(90, 120);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(683, 500);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(90, 120);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox8->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox8->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(779, 500);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(90, 120);
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox9->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox9->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox9->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(491, 500);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(90, 120);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox6->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox6->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(587, 500);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(90, 120);
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox7->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox7->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(875, 500);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(90, 120);
			this->pictureBox10->TabIndex = 9;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox10->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox10->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox10->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(1163, 500);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(90, 120);
			this->pictureBox13->TabIndex = 11;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox13->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox13->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(971, 500);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(90, 120);
			this->pictureBox11->TabIndex = 10;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox11->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox11->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(1067, 500);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(90, 120);
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox12->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox12->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox27
			// 
			this->pictureBox27->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox27->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox27.Image")));
			this->pictureBox27->Location = System::Drawing::Point(17, 263);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(90, 120);
			this->pictureBox27->TabIndex = 30;
			this->pictureBox27->TabStop = false;
			// 
			// pictureBox28
			// 
			this->pictureBox28->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox28.Image")));
			this->pictureBox28->Location = System::Drawing::Point(42, 263);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(90, 120);
			this->pictureBox28->TabIndex = 31;
			this->pictureBox28->TabStop = false;
			// 
			// pictureBox29
			// 
			this->pictureBox29->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox29->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox29.Image")));
			this->pictureBox29->Location = System::Drawing::Point(67, 263);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(90, 120);
			this->pictureBox29->TabIndex = 32;
			this->pictureBox29->TabStop = false;
			// 
			// pictureBox30
			// 
			this->pictureBox30->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox30.Image")));
			this->pictureBox30->Location = System::Drawing::Point(92, 263);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(90, 120);
			this->pictureBox30->TabIndex = 33;
			this->pictureBox30->TabStop = false;
			// 
			// pictureBox31
			// 
			this->pictureBox31->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox31->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox31.Image")));
			this->pictureBox31->Location = System::Drawing::Point(117, 263);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(90, 120);
			this->pictureBox31->TabIndex = 34;
			this->pictureBox31->TabStop = false;
			// 
			// pictureBox32
			// 
			this->pictureBox32->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox32.Image")));
			this->pictureBox32->Location = System::Drawing::Point(17, 137);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(90, 120);
			this->pictureBox32->TabIndex = 35;
			this->pictureBox32->TabStop = false;
			// 
			// pictureBox33
			// 
			this->pictureBox33->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox33.Image")));
			this->pictureBox33->Location = System::Drawing::Point(42, 137);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(90, 120);
			this->pictureBox33->TabIndex = 36;
			this->pictureBox33->TabStop = false;
			// 
			// pictureBox34
			// 
			this->pictureBox34->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox34.Image")));
			this->pictureBox34->Location = System::Drawing::Point(67, 137);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(90, 120);
			this->pictureBox34->TabIndex = 37;
			this->pictureBox34->TabStop = false;
			// 
			// pictureBox35
			// 
			this->pictureBox35->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox35->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox35.Image")));
			this->pictureBox35->Location = System::Drawing::Point(92, 137);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(90, 120);
			this->pictureBox35->TabIndex = 38;
			this->pictureBox35->TabStop = false;
			// 
			// pictureBox36
			// 
			this->pictureBox36->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox36->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox36.Image")));
			this->pictureBox36->Location = System::Drawing::Point(117, 137);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(90, 120);
			this->pictureBox36->TabIndex = 39;
			this->pictureBox36->TabStop = false;
			// 
			// pictureBox37
			// 
			this->pictureBox37->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox37->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox37.Image")));
			this->pictureBox37->Location = System::Drawing::Point(17, 11);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(90, 120);
			this->pictureBox37->TabIndex = 40;
			this->pictureBox37->TabStop = false;
			// 
			// pictureBox38
			// 
			this->pictureBox38->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox38->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox38.Image")));
			this->pictureBox38->Location = System::Drawing::Point(67, 11);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(90, 120);
			this->pictureBox38->TabIndex = 41;
			this->pictureBox38->TabStop = false;
			// 
			// pictureBox39
			// 
			this->pictureBox39->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox39->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox39.Image")));
			this->pictureBox39->Location = System::Drawing::Point(117, 11);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(90, 120);
			this->pictureBox39->TabIndex = 42;
			this->pictureBox39->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel1->Controls->Add(this->pictureBox39);
			this->panel1->Controls->Add(this->pictureBox38);
			this->panel1->Controls->Add(this->pictureBox37);
			this->panel1->Controls->Add(this->pictureBox36);
			this->panel1->Controls->Add(this->pictureBox35);
			this->panel1->Controls->Add(this->pictureBox34);
			this->panel1->Controls->Add(this->pictureBox33);
			this->panel1->Controls->Add(this->pictureBox32);
			this->panel1->Controls->Add(this->pictureBox31);
			this->panel1->Controls->Add(this->pictureBox30);
			this->panel1->Controls->Add(this->pictureBox29);
			this->panel1->Controls->Add(this->pictureBox28);
			this->panel1->Controls->Add(this->pictureBox27);
			this->panel1->Location = System::Drawing::Point(503, 76);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(226, 393);
			this->panel1->TabIndex = 43;
			this->panel1->Visible = false;
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel2->Controls->Add(this->pictureBox40);
			this->panel2->Controls->Add(this->pictureBox41);
			this->panel2->Controls->Add(this->pictureBox42);
			this->panel2->Controls->Add(this->pictureBox43);
			this->panel2->Controls->Add(this->pictureBox44);
			this->panel2->Controls->Add(this->pictureBox45);
			this->panel2->Controls->Add(this->pictureBox46);
			this->panel2->Controls->Add(this->pictureBox47);
			this->panel2->Controls->Add(this->pictureBox48);
			this->panel2->Controls->Add(this->pictureBox49);
			this->panel2->Controls->Add(this->pictureBox50);
			this->panel2->Controls->Add(this->pictureBox51);
			this->panel2->Controls->Add(this->pictureBox52);
			this->panel2->Location = System::Drawing::Point(737, 76);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(226, 393);
			this->panel2->TabIndex = 44;
			this->panel2->Visible = false;
			this->panel2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->panel2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox40
			// 
			this->pictureBox40->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox40->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox40.Image")));
			this->pictureBox40->Location = System::Drawing::Point(117, 11);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(90, 120);
			this->pictureBox40->TabIndex = 42;
			this->pictureBox40->TabStop = false;
			// 
			// pictureBox41
			// 
			this->pictureBox41->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox41->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox41.Image")));
			this->pictureBox41->Location = System::Drawing::Point(67, 11);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(90, 120);
			this->pictureBox41->TabIndex = 41;
			this->pictureBox41->TabStop = false;
			// 
			// pictureBox42
			// 
			this->pictureBox42->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox42->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox42.Image")));
			this->pictureBox42->Location = System::Drawing::Point(17, 11);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(90, 120);
			this->pictureBox42->TabIndex = 40;
			this->pictureBox42->TabStop = false;
			// 
			// pictureBox43
			// 
			this->pictureBox43->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox43->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox43.Image")));
			this->pictureBox43->Location = System::Drawing::Point(117, 137);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(90, 120);
			this->pictureBox43->TabIndex = 39;
			this->pictureBox43->TabStop = false;
			// 
			// pictureBox44
			// 
			this->pictureBox44->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox44->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox44.Image")));
			this->pictureBox44->Location = System::Drawing::Point(92, 137);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(90, 120);
			this->pictureBox44->TabIndex = 38;
			this->pictureBox44->TabStop = false;
			// 
			// pictureBox45
			// 
			this->pictureBox45->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox45->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox45.Image")));
			this->pictureBox45->Location = System::Drawing::Point(67, 137);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(90, 120);
			this->pictureBox45->TabIndex = 37;
			this->pictureBox45->TabStop = false;
			// 
			// pictureBox46
			// 
			this->pictureBox46->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox46->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox46.Image")));
			this->pictureBox46->Location = System::Drawing::Point(42, 137);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(90, 120);
			this->pictureBox46->TabIndex = 36;
			this->pictureBox46->TabStop = false;
			// 
			// pictureBox47
			// 
			this->pictureBox47->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox47->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox47.Image")));
			this->pictureBox47->Location = System::Drawing::Point(17, 137);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(90, 120);
			this->pictureBox47->TabIndex = 35;
			this->pictureBox47->TabStop = false;
			// 
			// pictureBox48
			// 
			this->pictureBox48->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox48->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox48.Image")));
			this->pictureBox48->Location = System::Drawing::Point(117, 263);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(90, 120);
			this->pictureBox48->TabIndex = 34;
			this->pictureBox48->TabStop = false;
			// 
			// pictureBox49
			// 
			this->pictureBox49->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox49->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox49.Image")));
			this->pictureBox49->Location = System::Drawing::Point(92, 263);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(90, 120);
			this->pictureBox49->TabIndex = 33;
			this->pictureBox49->TabStop = false;
			// 
			// pictureBox50
			// 
			this->pictureBox50->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox50->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox50.Image")));
			this->pictureBox50->Location = System::Drawing::Point(67, 263);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(90, 120);
			this->pictureBox50->TabIndex = 32;
			this->pictureBox50->TabStop = false;
			// 
			// pictureBox51
			// 
			this->pictureBox51->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox51->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox51.Image")));
			this->pictureBox51->Location = System::Drawing::Point(42, 263);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(90, 120);
			this->pictureBox51->TabIndex = 31;
			this->pictureBox51->TabStop = false;
			// 
			// pictureBox52
			// 
			this->pictureBox52->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox52->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox52.Image")));
			this->pictureBox52->Location = System::Drawing::Point(17, 263);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(90, 120);
			this->pictureBox52->TabIndex = 30;
			this->pictureBox52->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel3->Controls->Add(this->pictureBox53);
			this->panel3->Controls->Add(this->pictureBox54);
			this->panel3->Controls->Add(this->pictureBox55);
			this->panel3->Controls->Add(this->pictureBox56);
			this->panel3->Controls->Add(this->pictureBox57);
			this->panel3->Controls->Add(this->pictureBox58);
			this->panel3->Controls->Add(this->pictureBox59);
			this->panel3->Controls->Add(this->pictureBox60);
			this->panel3->Controls->Add(this->pictureBox61);
			this->panel3->Controls->Add(this->pictureBox62);
			this->panel3->Controls->Add(this->pictureBox63);
			this->panel3->Controls->Add(this->pictureBox64);
			this->panel3->Controls->Add(this->pictureBox65);
			this->panel3->Location = System::Drawing::Point(971, 76);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(226, 393);
			this->panel3->TabIndex = 44;
			// 
			// pictureBox53
			// 
			this->pictureBox53->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox53->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox53.Image")));
			this->pictureBox53->Location = System::Drawing::Point(117, 11);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(90, 120);
			this->pictureBox53->TabIndex = 42;
			this->pictureBox53->TabStop = false;
			// 
			// pictureBox54
			// 
			this->pictureBox54->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox54->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox54.Image")));
			this->pictureBox54->Location = System::Drawing::Point(67, 11);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(90, 120);
			this->pictureBox54->TabIndex = 41;
			this->pictureBox54->TabStop = false;
			// 
			// pictureBox55
			// 
			this->pictureBox55->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox55->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox55.Image")));
			this->pictureBox55->Location = System::Drawing::Point(17, 11);
			this->pictureBox55->Name = L"pictureBox55";
			this->pictureBox55->Size = System::Drawing::Size(90, 120);
			this->pictureBox55->TabIndex = 40;
			this->pictureBox55->TabStop = false;
			// 
			// pictureBox56
			// 
			this->pictureBox56->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox56->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox56.Image")));
			this->pictureBox56->Location = System::Drawing::Point(117, 137);
			this->pictureBox56->Name = L"pictureBox56";
			this->pictureBox56->Size = System::Drawing::Size(90, 120);
			this->pictureBox56->TabIndex = 39;
			this->pictureBox56->TabStop = false;
			// 
			// pictureBox57
			// 
			this->pictureBox57->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox57->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox57.Image")));
			this->pictureBox57->Location = System::Drawing::Point(92, 137);
			this->pictureBox57->Name = L"pictureBox57";
			this->pictureBox57->Size = System::Drawing::Size(90, 120);
			this->pictureBox57->TabIndex = 38;
			this->pictureBox57->TabStop = false;
			// 
			// pictureBox58
			// 
			this->pictureBox58->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox58->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox58.Image")));
			this->pictureBox58->Location = System::Drawing::Point(67, 137);
			this->pictureBox58->Name = L"pictureBox58";
			this->pictureBox58->Size = System::Drawing::Size(90, 120);
			this->pictureBox58->TabIndex = 37;
			this->pictureBox58->TabStop = false;
			// 
			// pictureBox59
			// 
			this->pictureBox59->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox59->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox59.Image")));
			this->pictureBox59->Location = System::Drawing::Point(42, 137);
			this->pictureBox59->Name = L"pictureBox59";
			this->pictureBox59->Size = System::Drawing::Size(90, 120);
			this->pictureBox59->TabIndex = 36;
			this->pictureBox59->TabStop = false;
			// 
			// pictureBox60
			// 
			this->pictureBox60->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox60->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox60.Image")));
			this->pictureBox60->Location = System::Drawing::Point(17, 137);
			this->pictureBox60->Name = L"pictureBox60";
			this->pictureBox60->Size = System::Drawing::Size(90, 120);
			this->pictureBox60->TabIndex = 35;
			this->pictureBox60->TabStop = false;
			// 
			// pictureBox61
			// 
			this->pictureBox61->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox61->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox61.Image")));
			this->pictureBox61->Location = System::Drawing::Point(117, 263);
			this->pictureBox61->Name = L"pictureBox61";
			this->pictureBox61->Size = System::Drawing::Size(90, 120);
			this->pictureBox61->TabIndex = 34;
			this->pictureBox61->TabStop = false;
			// 
			// pictureBox62
			// 
			this->pictureBox62->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox62->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox62.Image")));
			this->pictureBox62->Location = System::Drawing::Point(92, 263);
			this->pictureBox62->Name = L"pictureBox62";
			this->pictureBox62->Size = System::Drawing::Size(90, 120);
			this->pictureBox62->TabIndex = 33;
			this->pictureBox62->TabStop = false;
			// 
			// pictureBox63
			// 
			this->pictureBox63->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox63->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox63.Image")));
			this->pictureBox63->Location = System::Drawing::Point(67, 263);
			this->pictureBox63->Name = L"pictureBox63";
			this->pictureBox63->Size = System::Drawing::Size(90, 120);
			this->pictureBox63->TabIndex = 32;
			this->pictureBox63->TabStop = false;
			// 
			// pictureBox64
			// 
			this->pictureBox64->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox64->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox64.Image")));
			this->pictureBox64->Location = System::Drawing::Point(42, 263);
			this->pictureBox64->Name = L"pictureBox64";
			this->pictureBox64->Size = System::Drawing::Size(90, 120);
			this->pictureBox64->TabIndex = 31;
			this->pictureBox64->TabStop = false;
			// 
			// pictureBox65
			// 
			this->pictureBox65->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox65->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox65.Image")));
			this->pictureBox65->Location = System::Drawing::Point(17, 263);
			this->pictureBox65->Name = L"pictureBox65";
			this->pictureBox65->Size = System::Drawing::Size(90, 120);
			this->pictureBox65->TabIndex = 30;
			this->pictureBox65->TabStop = false;
			// 
			// btn_deal
			// 
			this->btn_deal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_deal->Location = System::Drawing::Point(11, 687);
			this->btn_deal->Name = L"btn_deal";
			this->btn_deal->Size = System::Drawing::Size(186, 50);
			this->btn_deal->TabIndex = 25;
			this->btn_deal->Text = L"Deal";
			this->btn_deal->UseVisualStyleBackColor = true;
			this->btn_deal->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->btn_deal->Click += gcnew System::EventHandler(this, &Form1::btn_deal_Click);
			this->btn_deal->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_deal->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->btn_deal->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// btn_build
			// 
			this->btn_build->Enabled = false;
			this->btn_build->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_build->Location = System::Drawing::Point(204, 633);
			this->btn_build->Name = L"btn_build";
			this->btn_build->Size = System::Drawing::Size(90, 50);
			this->btn_build->TabIndex = 46;
			this->btn_build->Text = L"Auto  Build";
			this->btn_build->UseVisualStyleBackColor = true;
			this->btn_build->Click += gcnew System::EventHandler(this, &Form1::btn_build_Click);
			this->btn_build->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_build->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// btn_submit
			// 
			this->btn_submit->Enabled = false;
			this->btn_submit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_submit->Location = System::Drawing::Point(12, 632);
			this->btn_submit->Name = L"btn_submit";
			this->btn_submit->Size = System::Drawing::Size(186, 50);
			this->btn_submit->TabIndex = 45;
			this->btn_submit->Text = L"Submit Hand";
			this->btn_submit->UseVisualStyleBackColor = true;
			this->btn_submit->Click += gcnew System::EventHandler(this, &Form1::btn_submit_Click);
			this->btn_submit->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_submit->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// btn_stack
			// 
			this->btn_stack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_stack->Location = System::Drawing::Point(492, 688);
			this->btn_stack->Name = L"btn_stack";
			this->btn_stack->Size = System::Drawing::Size(90, 50);
			this->btn_stack->TabIndex = 47;
			this->btn_stack->Text = L"Stack Hand";
			this->btn_stack->UseVisualStyleBackColor = true;
			this->btn_stack->Click += gcnew System::EventHandler(this, &Form1::btn_stack_Click);
			this->btn_stack->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_stack->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// btn_sim
			// 
			this->btn_sim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_sim->Location = System::Drawing::Point(587, 633);
			this->btn_sim->Name = L"btn_sim";
			this->btn_sim->Size = System::Drawing::Size(186, 50);
			this->btn_sim->TabIndex = 48;
			this->btn_sim->Text = L"Simulate Hands";
			this->btn_sim->UseVisualStyleBackColor = true;
			this->btn_sim->Click += gcnew System::EventHandler(this, &Form1::btn_sim_Click);
			this->btn_sim->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_sim->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(11, 478);
			this->hScrollBar1->Maximum = 75;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(474, 19);
			this->hScrollBar1->TabIndex = 102;
			this->hScrollBar1->Value = 15;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar1_Scroll);
			// 
			// pictureBox117
			// 
			this->pictureBox117->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox117->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox117.Image")));
			this->pictureBox117->Location = System::Drawing::Point(969, 349);
			this->pictureBox117->Name = L"pictureBox117";
			this->pictureBox117->Size = System::Drawing::Size(90, 120);
			this->pictureBox117->TabIndex = 154;
			this->pictureBox117->TabStop = false;
			this->pictureBox117->Visible = false;
			this->pictureBox117->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox117->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox117->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox117->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox116
			// 
			this->pictureBox116->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox116->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox116.Image")));
			this->pictureBox116->Location = System::Drawing::Point(930, 349);
			this->pictureBox116->Name = L"pictureBox116";
			this->pictureBox116->Size = System::Drawing::Size(90, 120);
			this->pictureBox116->TabIndex = 153;
			this->pictureBox116->TabStop = false;
			this->pictureBox116->Visible = false;
			this->pictureBox116->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox116->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox116->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox116->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox115
			// 
			this->pictureBox115->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox115->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox115.Image")));
			this->pictureBox115->Location = System::Drawing::Point(891, 349);
			this->pictureBox115->Name = L"pictureBox115";
			this->pictureBox115->Size = System::Drawing::Size(90, 120);
			this->pictureBox115->TabIndex = 152;
			this->pictureBox115->TabStop = false;
			this->pictureBox115->Visible = false;
			this->pictureBox115->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox115->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox115->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox115->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox114
			// 
			this->pictureBox114->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox114->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox114.Image")));
			this->pictureBox114->Location = System::Drawing::Point(852, 349);
			this->pictureBox114->Name = L"pictureBox114";
			this->pictureBox114->Size = System::Drawing::Size(90, 120);
			this->pictureBox114->TabIndex = 151;
			this->pictureBox114->TabStop = false;
			this->pictureBox114->Visible = false;
			this->pictureBox114->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox114->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox114->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox114->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox113
			// 
			this->pictureBox113->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox113->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox113.Image")));
			this->pictureBox113->Location = System::Drawing::Point(813, 349);
			this->pictureBox113->Name = L"pictureBox113";
			this->pictureBox113->Size = System::Drawing::Size(90, 120);
			this->pictureBox113->TabIndex = 150;
			this->pictureBox113->TabStop = false;
			this->pictureBox113->Visible = false;
			this->pictureBox113->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox113->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox113->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox113->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox112
			// 
			this->pictureBox112->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox112->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox112.Image")));
			this->pictureBox112->Location = System::Drawing::Point(772, 349);
			this->pictureBox112->Name = L"pictureBox112";
			this->pictureBox112->Size = System::Drawing::Size(90, 120);
			this->pictureBox112->TabIndex = 149;
			this->pictureBox112->TabStop = false;
			this->pictureBox112->Visible = false;
			this->pictureBox112->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox112->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox112->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox112->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox111
			// 
			this->pictureBox111->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox111->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox111.Image")));
			this->pictureBox111->Location = System::Drawing::Point(735, 349);
			this->pictureBox111->Name = L"pictureBox111";
			this->pictureBox111->Size = System::Drawing::Size(90, 120);
			this->pictureBox111->TabIndex = 148;
			this->pictureBox111->TabStop = false;
			this->pictureBox111->Visible = false;
			this->pictureBox111->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox111->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox111->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox111->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox110
			// 
			this->pictureBox110->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox110->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox110.Image")));
			this->pictureBox110->Location = System::Drawing::Point(696, 349);
			this->pictureBox110->Name = L"pictureBox110";
			this->pictureBox110->Size = System::Drawing::Size(90, 120);
			this->pictureBox110->TabIndex = 147;
			this->pictureBox110->TabStop = false;
			this->pictureBox110->Visible = false;
			this->pictureBox110->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox110->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox110->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox110->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox109
			// 
			this->pictureBox109->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox109->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox109.Image")));
			this->pictureBox109->Location = System::Drawing::Point(657, 349);
			this->pictureBox109->Name = L"pictureBox109";
			this->pictureBox109->Size = System::Drawing::Size(90, 120);
			this->pictureBox109->TabIndex = 146;
			this->pictureBox109->TabStop = false;
			this->pictureBox109->Visible = false;
			this->pictureBox109->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox109->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox109->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox109->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox108
			// 
			this->pictureBox108->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox108->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox108.Image")));
			this->pictureBox108->Location = System::Drawing::Point(618, 349);
			this->pictureBox108->Name = L"pictureBox108";
			this->pictureBox108->Size = System::Drawing::Size(90, 120);
			this->pictureBox108->TabIndex = 145;
			this->pictureBox108->TabStop = false;
			this->pictureBox108->Visible = false;
			this->pictureBox108->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox108->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox108->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox108->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox107
			// 
			this->pictureBox107->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox107->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox107.Image")));
			this->pictureBox107->Location = System::Drawing::Point(579, 349);
			this->pictureBox107->Name = L"pictureBox107";
			this->pictureBox107->Size = System::Drawing::Size(90, 120);
			this->pictureBox107->TabIndex = 144;
			this->pictureBox107->TabStop = false;
			this->pictureBox107->Visible = false;
			this->pictureBox107->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox107->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox107->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox107->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox106
			// 
			this->pictureBox106->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox106->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox106.Image")));
			this->pictureBox106->Location = System::Drawing::Point(540, 349);
			this->pictureBox106->Name = L"pictureBox106";
			this->pictureBox106->Size = System::Drawing::Size(90, 120);
			this->pictureBox106->TabIndex = 143;
			this->pictureBox106->TabStop = false;
			this->pictureBox106->Visible = false;
			this->pictureBox106->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox106->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox106->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox106->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox105
			// 
			this->pictureBox105->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox105->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox105.Image")));
			this->pictureBox105->Location = System::Drawing::Point(501, 349);
			this->pictureBox105->Name = L"pictureBox105";
			this->pictureBox105->Size = System::Drawing::Size(90, 120);
			this->pictureBox105->TabIndex = 142;
			this->pictureBox105->TabStop = false;
			this->pictureBox105->Visible = false;
			this->pictureBox105->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox105->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox105->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox105->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox104
			// 
			this->pictureBox104->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox104->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox104.Image")));
			this->pictureBox104->Location = System::Drawing::Point(969, 265);
			this->pictureBox104->Name = L"pictureBox104";
			this->pictureBox104->Size = System::Drawing::Size(90, 120);
			this->pictureBox104->TabIndex = 141;
			this->pictureBox104->TabStop = false;
			this->pictureBox104->Visible = false;
			this->pictureBox104->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox104->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox104->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox104->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox103
			// 
			this->pictureBox103->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox103->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox103.Image")));
			this->pictureBox103->Location = System::Drawing::Point(931, 265);
			this->pictureBox103->Name = L"pictureBox103";
			this->pictureBox103->Size = System::Drawing::Size(90, 120);
			this->pictureBox103->TabIndex = 140;
			this->pictureBox103->TabStop = false;
			this->pictureBox103->Visible = false;
			this->pictureBox103->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox103->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox103->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox103->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox102
			// 
			this->pictureBox102->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox102->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox102.Image")));
			this->pictureBox102->Location = System::Drawing::Point(891, 265);
			this->pictureBox102->Name = L"pictureBox102";
			this->pictureBox102->Size = System::Drawing::Size(90, 120);
			this->pictureBox102->TabIndex = 139;
			this->pictureBox102->TabStop = false;
			this->pictureBox102->Visible = false;
			this->pictureBox102->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox102->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox102->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox102->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox101
			// 
			this->pictureBox101->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox101->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox101.Image")));
			this->pictureBox101->Location = System::Drawing::Point(852, 265);
			this->pictureBox101->Name = L"pictureBox101";
			this->pictureBox101->Size = System::Drawing::Size(90, 120);
			this->pictureBox101->TabIndex = 138;
			this->pictureBox101->TabStop = false;
			this->pictureBox101->Visible = false;
			this->pictureBox101->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox101->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox101->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox101->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox100
			// 
			this->pictureBox100->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox100->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox100.Image")));
			this->pictureBox100->Location = System::Drawing::Point(813, 265);
			this->pictureBox100->Name = L"pictureBox100";
			this->pictureBox100->Size = System::Drawing::Size(90, 120);
			this->pictureBox100->TabIndex = 137;
			this->pictureBox100->TabStop = false;
			this->pictureBox100->Visible = false;
			this->pictureBox100->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox100->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox100->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox100->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox99
			// 
			this->pictureBox99->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox99->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox99.Image")));
			this->pictureBox99->Location = System::Drawing::Point(772, 265);
			this->pictureBox99->Name = L"pictureBox99";
			this->pictureBox99->Size = System::Drawing::Size(90, 120);
			this->pictureBox99->TabIndex = 136;
			this->pictureBox99->TabStop = false;
			this->pictureBox99->Visible = false;
			this->pictureBox99->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox99->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox99->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox99->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox98
			// 
			this->pictureBox98->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox98->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox98.Image")));
			this->pictureBox98->Location = System::Drawing::Point(735, 265);
			this->pictureBox98->Name = L"pictureBox98";
			this->pictureBox98->Size = System::Drawing::Size(90, 120);
			this->pictureBox98->TabIndex = 132;
			this->pictureBox98->TabStop = false;
			this->pictureBox98->Visible = false;
			this->pictureBox98->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox98->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox98->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox98->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox97
			// 
			this->pictureBox97->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox97->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox97.Image")));
			this->pictureBox97->Location = System::Drawing::Point(696, 265);
			this->pictureBox97->Name = L"pictureBox97";
			this->pictureBox97->Size = System::Drawing::Size(90, 120);
			this->pictureBox97->TabIndex = 134;
			this->pictureBox97->TabStop = false;
			this->pictureBox97->Visible = false;
			this->pictureBox97->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox97->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox97->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox97->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox96
			// 
			this->pictureBox96->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox96->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox96.Image")));
			this->pictureBox96->Location = System::Drawing::Point(657, 265);
			this->pictureBox96->Name = L"pictureBox96";
			this->pictureBox96->Size = System::Drawing::Size(90, 120);
			this->pictureBox96->TabIndex = 133;
			this->pictureBox96->TabStop = false;
			this->pictureBox96->Visible = false;
			this->pictureBox96->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox96->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox96->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox96->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox95
			// 
			this->pictureBox95->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox95->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox95.Image")));
			this->pictureBox95->Location = System::Drawing::Point(618, 265);
			this->pictureBox95->Name = L"pictureBox95";
			this->pictureBox95->Size = System::Drawing::Size(90, 120);
			this->pictureBox95->TabIndex = 155;
			this->pictureBox95->TabStop = false;
			this->pictureBox95->Visible = false;
			this->pictureBox95->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox95->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox95->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox95->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox94
			// 
			this->pictureBox94->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox94->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox94.Image")));
			this->pictureBox94->Location = System::Drawing::Point(579, 265);
			this->pictureBox94->Name = L"pictureBox94";
			this->pictureBox94->Size = System::Drawing::Size(90, 120);
			this->pictureBox94->TabIndex = 131;
			this->pictureBox94->TabStop = false;
			this->pictureBox94->Visible = false;
			this->pictureBox94->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox94->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox94->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox94->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox93
			// 
			this->pictureBox93->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox93->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox93.Image")));
			this->pictureBox93->Location = System::Drawing::Point(540, 265);
			this->pictureBox93->Name = L"pictureBox93";
			this->pictureBox93->Size = System::Drawing::Size(90, 120);
			this->pictureBox93->TabIndex = 130;
			this->pictureBox93->TabStop = false;
			this->pictureBox93->Visible = false;
			this->pictureBox93->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox93->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox93->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox93->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox92
			// 
			this->pictureBox92->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox92->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox92.Image")));
			this->pictureBox92->Location = System::Drawing::Point(501, 265);
			this->pictureBox92->Name = L"pictureBox92";
			this->pictureBox92->Size = System::Drawing::Size(90, 120);
			this->pictureBox92->TabIndex = 129;
			this->pictureBox92->TabStop = false;
			this->pictureBox92->Visible = false;
			this->pictureBox92->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox92->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox92->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox92->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox91
			// 
			this->pictureBox91->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox91->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox91.Image")));
			this->pictureBox91->Location = System::Drawing::Point(969, 181);
			this->pictureBox91->Name = L"pictureBox91";
			this->pictureBox91->Size = System::Drawing::Size(90, 120);
			this->pictureBox91->TabIndex = 128;
			this->pictureBox91->TabStop = false;
			this->pictureBox91->Visible = false;
			this->pictureBox91->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox91->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox91->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox91->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox90
			// 
			this->pictureBox90->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox90->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox90.Image")));
			this->pictureBox90->Location = System::Drawing::Point(930, 181);
			this->pictureBox90->Name = L"pictureBox90";
			this->pictureBox90->Size = System::Drawing::Size(90, 120);
			this->pictureBox90->TabIndex = 127;
			this->pictureBox90->TabStop = false;
			this->pictureBox90->Visible = false;
			this->pictureBox90->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox90->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox90->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox90->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox89
			// 
			this->pictureBox89->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox89->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox89.Image")));
			this->pictureBox89->Location = System::Drawing::Point(891, 181);
			this->pictureBox89->Name = L"pictureBox89";
			this->pictureBox89->Size = System::Drawing::Size(90, 120);
			this->pictureBox89->TabIndex = 126;
			this->pictureBox89->TabStop = false;
			this->pictureBox89->Visible = false;
			this->pictureBox89->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox89->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox89->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox89->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox88
			// 
			this->pictureBox88->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox88->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox88.Image")));
			this->pictureBox88->Location = System::Drawing::Point(852, 181);
			this->pictureBox88->Name = L"pictureBox88";
			this->pictureBox88->Size = System::Drawing::Size(90, 120);
			this->pictureBox88->TabIndex = 125;
			this->pictureBox88->TabStop = false;
			this->pictureBox88->Visible = false;
			this->pictureBox88->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox88->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox88->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox88->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox87
			// 
			this->pictureBox87->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox87->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox87.Image")));
			this->pictureBox87->Location = System::Drawing::Point(813, 181);
			this->pictureBox87->Name = L"pictureBox87";
			this->pictureBox87->Size = System::Drawing::Size(90, 120);
			this->pictureBox87->TabIndex = 124;
			this->pictureBox87->TabStop = false;
			this->pictureBox87->Visible = false;
			this->pictureBox87->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox87->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox87->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox87->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox86
			// 
			this->pictureBox86->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox86->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox86.Image")));
			this->pictureBox86->Location = System::Drawing::Point(774, 181);
			this->pictureBox86->Name = L"pictureBox86";
			this->pictureBox86->Size = System::Drawing::Size(90, 120);
			this->pictureBox86->TabIndex = 123;
			this->pictureBox86->TabStop = false;
			this->pictureBox86->Visible = false;
			this->pictureBox86->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox86->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox86->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox86->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox85
			// 
			this->pictureBox85->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox85->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox85.Image")));
			this->pictureBox85->Location = System::Drawing::Point(733, 181);
			this->pictureBox85->Name = L"pictureBox85";
			this->pictureBox85->Size = System::Drawing::Size(90, 120);
			this->pictureBox85->TabIndex = 122;
			this->pictureBox85->TabStop = false;
			this->pictureBox85->Visible = false;
			this->pictureBox85->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox85->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox85->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox85->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox84
			// 
			this->pictureBox84->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox84->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox84.Image")));
			this->pictureBox84->Location = System::Drawing::Point(696, 181);
			this->pictureBox84->Name = L"pictureBox84";
			this->pictureBox84->Size = System::Drawing::Size(90, 120);
			this->pictureBox84->TabIndex = 121;
			this->pictureBox84->TabStop = false;
			this->pictureBox84->Visible = false;
			this->pictureBox84->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox84->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox84->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox84->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox83
			// 
			this->pictureBox83->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox83->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox83.Image")));
			this->pictureBox83->Location = System::Drawing::Point(657, 181);
			this->pictureBox83->Name = L"pictureBox83";
			this->pictureBox83->Size = System::Drawing::Size(90, 120);
			this->pictureBox83->TabIndex = 120;
			this->pictureBox83->TabStop = false;
			this->pictureBox83->Visible = false;
			this->pictureBox83->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox83->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox83->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox83->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox82
			// 
			this->pictureBox82->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox82->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox82.Image")));
			this->pictureBox82->Location = System::Drawing::Point(618, 181);
			this->pictureBox82->Name = L"pictureBox82";
			this->pictureBox82->Size = System::Drawing::Size(90, 120);
			this->pictureBox82->TabIndex = 119;
			this->pictureBox82->TabStop = false;
			this->pictureBox82->Visible = false;
			this->pictureBox82->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox82->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox82->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox82->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox81
			// 
			this->pictureBox81->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox81->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox81.Image")));
			this->pictureBox81->Location = System::Drawing::Point(579, 181);
			this->pictureBox81->Name = L"pictureBox81";
			this->pictureBox81->Size = System::Drawing::Size(90, 120);
			this->pictureBox81->TabIndex = 118;
			this->pictureBox81->TabStop = false;
			this->pictureBox81->Visible = false;
			this->pictureBox81->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox81->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox81->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox81->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox80
			// 
			this->pictureBox80->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox80->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox80.Image")));
			this->pictureBox80->Location = System::Drawing::Point(540, 181);
			this->pictureBox80->Name = L"pictureBox80";
			this->pictureBox80->Size = System::Drawing::Size(90, 120);
			this->pictureBox80->TabIndex = 117;
			this->pictureBox80->TabStop = false;
			this->pictureBox80->Visible = false;
			this->pictureBox80->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox80->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox80->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox80->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox79
			// 
			this->pictureBox79->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox79->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox79.Image")));
			this->pictureBox79->Location = System::Drawing::Point(501, 181);
			this->pictureBox79->Name = L"pictureBox79";
			this->pictureBox79->Size = System::Drawing::Size(90, 120);
			this->pictureBox79->TabIndex = 116;
			this->pictureBox79->TabStop = false;
			this->pictureBox79->Visible = false;
			this->pictureBox79->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox79->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox79->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox79->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox78
			// 
			this->pictureBox78->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox78->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox78.Image")));
			this->pictureBox78->Location = System::Drawing::Point(969, 97);
			this->pictureBox78->Name = L"pictureBox78";
			this->pictureBox78->Size = System::Drawing::Size(90, 120);
			this->pictureBox78->TabIndex = 115;
			this->pictureBox78->TabStop = false;
			this->pictureBox78->Visible = false;
			this->pictureBox78->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox78->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox78->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox78->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox77
			// 
			this->pictureBox77->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox77->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox77.Image")));
			this->pictureBox77->Location = System::Drawing::Point(930, 97);
			this->pictureBox77->Name = L"pictureBox77";
			this->pictureBox77->Size = System::Drawing::Size(90, 120);
			this->pictureBox77->TabIndex = 114;
			this->pictureBox77->TabStop = false;
			this->pictureBox77->Visible = false;
			this->pictureBox77->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox77->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox77->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox77->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox76
			// 
			this->pictureBox76->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox76->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox76.Image")));
			this->pictureBox76->Location = System::Drawing::Point(891, 97);
			this->pictureBox76->Name = L"pictureBox76";
			this->pictureBox76->Size = System::Drawing::Size(90, 120);
			this->pictureBox76->TabIndex = 113;
			this->pictureBox76->TabStop = false;
			this->pictureBox76->Visible = false;
			this->pictureBox76->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox76->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox76->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox76->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox75
			// 
			this->pictureBox75->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox75->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox75.Image")));
			this->pictureBox75->Location = System::Drawing::Point(852, 97);
			this->pictureBox75->Name = L"pictureBox75";
			this->pictureBox75->Size = System::Drawing::Size(90, 120);
			this->pictureBox75->TabIndex = 112;
			this->pictureBox75->TabStop = false;
			this->pictureBox75->Visible = false;
			this->pictureBox75->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox75->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox75->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox75->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox74
			// 
			this->pictureBox74->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox74->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox74.Image")));
			this->pictureBox74->Location = System::Drawing::Point(813, 97);
			this->pictureBox74->Name = L"pictureBox74";
			this->pictureBox74->Size = System::Drawing::Size(90, 120);
			this->pictureBox74->TabIndex = 111;
			this->pictureBox74->TabStop = false;
			this->pictureBox74->Visible = false;
			this->pictureBox74->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox74->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox74->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox74->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox73
			// 
			this->pictureBox73->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox73->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox73.Image")));
			this->pictureBox73->Location = System::Drawing::Point(774, 97);
			this->pictureBox73->Name = L"pictureBox73";
			this->pictureBox73->Size = System::Drawing::Size(90, 120);
			this->pictureBox73->TabIndex = 110;
			this->pictureBox73->TabStop = false;
			this->pictureBox73->Visible = false;
			this->pictureBox73->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox73->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox73->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox73->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox72
			// 
			this->pictureBox72->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox72->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox72.Image")));
			this->pictureBox72->Location = System::Drawing::Point(735, 97);
			this->pictureBox72->Name = L"pictureBox72";
			this->pictureBox72->Size = System::Drawing::Size(90, 120);
			this->pictureBox72->TabIndex = 109;
			this->pictureBox72->TabStop = false;
			this->pictureBox72->Visible = false;
			this->pictureBox72->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox72->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox72->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox72->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox71
			// 
			this->pictureBox71->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox71->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox71.Image")));
			this->pictureBox71->Location = System::Drawing::Point(696, 97);
			this->pictureBox71->Name = L"pictureBox71";
			this->pictureBox71->Size = System::Drawing::Size(90, 120);
			this->pictureBox71->TabIndex = 108;
			this->pictureBox71->TabStop = false;
			this->pictureBox71->Visible = false;
			this->pictureBox71->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox71->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox71->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox71->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox70
			// 
			this->pictureBox70->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox70->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox70.Image")));
			this->pictureBox70->Location = System::Drawing::Point(657, 97);
			this->pictureBox70->Name = L"pictureBox70";
			this->pictureBox70->Size = System::Drawing::Size(90, 120);
			this->pictureBox70->TabIndex = 107;
			this->pictureBox70->TabStop = false;
			this->pictureBox70->Visible = false;
			this->pictureBox70->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox70->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox70->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox70->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox69
			// 
			this->pictureBox69->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox69->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox69.Image")));
			this->pictureBox69->Location = System::Drawing::Point(618, 97);
			this->pictureBox69->Name = L"pictureBox69";
			this->pictureBox69->Size = System::Drawing::Size(90, 120);
			this->pictureBox69->TabIndex = 106;
			this->pictureBox69->TabStop = false;
			this->pictureBox69->Visible = false;
			this->pictureBox69->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox69->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox69->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox69->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox68
			// 
			this->pictureBox68->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox68->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox68.Image")));
			this->pictureBox68->Location = System::Drawing::Point(579, 97);
			this->pictureBox68->Name = L"pictureBox68";
			this->pictureBox68->Size = System::Drawing::Size(90, 120);
			this->pictureBox68->TabIndex = 105;
			this->pictureBox68->TabStop = false;
			this->pictureBox68->Visible = false;
			this->pictureBox68->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox68->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox68->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox68->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox67
			// 
			this->pictureBox67->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox67->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox67.Image")));
			this->pictureBox67->Location = System::Drawing::Point(540, 97);
			this->pictureBox67->Name = L"pictureBox67";
			this->pictureBox67->Size = System::Drawing::Size(90, 120);
			this->pictureBox67->TabIndex = 104;
			this->pictureBox67->TabStop = false;
			this->pictureBox67->Visible = false;
			this->pictureBox67->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox67->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox67->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox67->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// pictureBox66
			// 
			this->pictureBox66->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox66->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox66.Image")));
			this->pictureBox66->Location = System::Drawing::Point(501, 97);
			this->pictureBox66->Name = L"pictureBox66";
			this->pictureBox66->Size = System::Drawing::Size(90, 120);
			this->pictureBox66->TabIndex = 103;
			this->pictureBox66->TabStop = false;
			this->pictureBox66->Visible = false;
			this->pictureBox66->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->pictureBox66->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
			this->pictureBox66->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			this->pictureBox66->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			// 
			// btn_Sort_Rank
			// 
			this->btn_Sort_Rank->Enabled = false;
			this->btn_Sort_Rank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_Sort_Rank->Location = System::Drawing::Point(299, 687);
			this->btn_Sort_Rank->Name = L"btn_Sort_Rank";
			this->btn_Sort_Rank->Size = System::Drawing::Size(90, 50);
			this->btn_Sort_Rank->TabIndex = 156;
			this->btn_Sort_Rank->Text = L"Sort by Rank";
			this->btn_Sort_Rank->UseVisualStyleBackColor = true;
			this->btn_Sort_Rank->Click += gcnew System::EventHandler(this, &Form1::btn_Sort_Rank_Click);
			this->btn_Sort_Rank->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_Sort_Rank->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// btn_Sort_Suit
			// 
			this->btn_Sort_Suit->Enabled = false;
			this->btn_Sort_Suit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_Sort_Suit->Location = System::Drawing::Point(299, 633);
			this->btn_Sort_Suit->Name = L"btn_Sort_Suit";
			this->btn_Sort_Suit->Size = System::Drawing::Size(90, 50);
			this->btn_Sort_Suit->TabIndex = 157;
			this->btn_Sort_Suit->Text = L"Sort by Suit";
			this->btn_Sort_Suit->UseVisualStyleBackColor = true;
			this->btn_Sort_Suit->Click += gcnew System::EventHandler(this, &Form1::btn_Sort_Suit_Click);
			this->btn_Sort_Suit->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->btn_Sort_Suit->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			// 
			// btn_Clear_Scores
			// 
			this->btn_Clear_Scores->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_Clear_Scores->Location = System::Drawing::Point(491, 633);
			this->btn_Clear_Scores->Name = L"btn_Clear_Scores";
			this->btn_Clear_Scores->Size = System::Drawing::Size(90, 50);
			this->btn_Clear_Scores->TabIndex = 158;
			this->btn_Clear_Scores->Text = L"Clear Scores";
			this->btn_Clear_Scores->UseVisualStyleBackColor = true;
			this->btn_Clear_Scores->Click += gcnew System::EventHandler(this, &Form1::btn_Clear_Scores_Click);
			// 
			// lbl_score0
			// 
			this->lbl_score0->AutoSize = true;
			this->lbl_score0->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Bold));
			this->lbl_score0->Location = System::Drawing::Point(197, 24);
			this->lbl_score0->Name = L"lbl_score0";
			this->lbl_score0->Size = System::Drawing::Size(106, 31);
			this->lbl_score0->TabIndex = 159;
			this->lbl_score0->Text = L"You: 0";
			// 
			// lbl_score1
			// 
			this->lbl_score1->AutoSize = true;
			this->lbl_score1->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Bold));
			this->lbl_score1->Location = System::Drawing::Point(514, 24);
			this->lbl_score1->Name = L"lbl_score1";
			this->lbl_score1->Size = System::Drawing::Size(170, 31);
			this->lbl_score1->TabIndex = 160;
			this->lbl_score1->Text = L"Player 2: 0";
			// 
			// lbl_score2
			// 
			this->lbl_score2->AutoSize = true;
			this->lbl_score2->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Bold));
			this->lbl_score2->Location = System::Drawing::Point(748, 24);
			this->lbl_score2->Name = L"lbl_score2";
			this->lbl_score2->Size = System::Drawing::Size(170, 31);
			this->lbl_score2->TabIndex = 161;
			this->lbl_score2->Text = L"Player 3: 0";
			// 
			// lbl_score3
			// 
			this->lbl_score3->AutoSize = true;
			this->lbl_score3->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Bold));
			this->lbl_score3->Location = System::Drawing::Point(982, 24);
			this->lbl_score3->Name = L"lbl_score3";
			this->lbl_score3->Size = System::Drawing::Size(170, 31);
			this->lbl_score3->TabIndex = 162;
			this->lbl_score3->Text = L"Player 4: 0";
			// 
			// lbl_EV
			// 
			this->lbl_EV->Location = System::Drawing::Point(793, 642);
			this->lbl_EV->Multiline = true;
			this->lbl_EV->Name = L"lbl_EV";
			this->lbl_EV->Size = System::Drawing::Size(364, 92);
			this->lbl_EV->TabIndex = 163;
			this->lbl_EV->Visible = false;
			// 
			// rBtn_high
			// 
			this->rBtn_high->AutoSize = true;
			this->rBtn_high->Checked = true;
			this->rBtn_high->Location = System::Drawing::Point(11, 24);
			this->rBtn_high->Name = L"rBtn_high";
			this->rBtn_high->Size = System::Drawing::Size(163, 17);
			this->rBtn_high->TabIndex = 164;
			this->rBtn_high->TabStop = true;
			this->rBtn_high->Text = L"High,             High,         High";
			this->rBtn_high->UseVisualStyleBackColor = true;
			// 
			// rBtn_low
			// 
			this->rBtn_low->AutoSize = true;
			this->rBtn_low->Location = System::Drawing::Point(11, 47);
			this->rBtn_low->Name = L"rBtn_low";
			this->rBtn_low->Size = System::Drawing::Size(164, 17);
			this->rBtn_low->TabIndex = 165;
			this->rBtn_low->Text = L"High,         Low(2 to7),    High";
			this->rBtn_low->UseVisualStyleBackColor = true;
			// 
			// btn_SelLower
			// 
			this->btn_SelLower->Enabled = false;
			this->btn_SelLower->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_SelLower->Location = System::Drawing::Point(396, 688);
			this->btn_SelLower->Name = L"btn_SelLower";
			this->btn_SelLower->Size = System::Drawing::Size(90, 50);
			this->btn_SelLower->TabIndex = 167;
			this->btn_SelLower->Text = L"Select All Lower";
			this->btn_SelLower->UseVisualStyleBackColor = true;
			this->btn_SelLower->Click += gcnew System::EventHandler(this, &Form1::btn_SelLower_Click);
			// 
			// btn_SelUpper
			// 
			this->btn_SelUpper->Enabled = false;
			this->btn_SelUpper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_SelUpper->Location = System::Drawing::Point(395, 633);
			this->btn_SelUpper->Name = L"btn_SelUpper";
			this->btn_SelUpper->Size = System::Drawing::Size(90, 50);
			this->btn_SelUpper->TabIndex = 168;
			this->btn_SelUpper->Text = L"Select All Upper";
			this->btn_SelUpper->UseVisualStyleBackColor = true;
			this->btn_SelUpper->Click += gcnew System::EventHandler(this, &Form1::btn_SelUpper_Click);
			// 
			// cBox_ShowEV
			// 
			this->cBox_ShowEV->AutoSize = true;
			this->cBox_ShowEV->Location = System::Drawing::Point(11, 71);
			this->cBox_ShowEV->Name = L"cBox_ShowEV";
			this->cBox_ShowEV->Size = System::Drawing::Size(104, 17);
			this->cBox_ShowEV->TabIndex = 169;
			this->cBox_ShowEV->Text = L"Show Hand EVs";
			this->cBox_ShowEV->UseVisualStyleBackColor = true;
			this->cBox_ShowEV->CheckedChanged += gcnew System::EventHandler(this, &Form1::cBox_ShowEV_CheckedChanged);
			// 
			// mStrip_main
			// 
			this->mStrip_main->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->playerToolStripMenuItem});
			this->mStrip_main->Location = System::Drawing::Point(0, 0);
			this->mStrip_main->Name = L"mStrip_main";
			this->mStrip_main->Size = System::Drawing::Size(1276, 24);
			this->mStrip_main->TabIndex = 170;
			this->mStrip_main->Text = L"Menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->loadSavedStatsToolStripMenuItem, 
				this->mergeCurrentAndSavedStatsToolStripMenuItem, this->saveCurrentStatsToolStripMenuItem, this->saveCurrentStatsAsToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadSavedStatsToolStripMenuItem
			// 
			this->loadSavedStatsToolStripMenuItem->Name = L"loadSavedStatsToolStripMenuItem";
			this->loadSavedStatsToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->loadSavedStatsToolStripMenuItem->Text = L"Load Saved Stats";
			this->loadSavedStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadSavedStatsToolStripMenuItem_Click);
			// 
			// mergeCurrentAndSavedStatsToolStripMenuItem
			// 
			this->mergeCurrentAndSavedStatsToolStripMenuItem->Name = L"mergeCurrentAndSavedStatsToolStripMenuItem";
			this->mergeCurrentAndSavedStatsToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->mergeCurrentAndSavedStatsToolStripMenuItem->Text = L"Merge Current and Saved Stats";
			this->mergeCurrentAndSavedStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mergeCurrentAndSavedStatsToolStripMenuItem_Click);
			// 
			// saveCurrentStatsToolStripMenuItem
			// 
			this->saveCurrentStatsToolStripMenuItem->Enabled = false;
			this->saveCurrentStatsToolStripMenuItem->Name = L"saveCurrentStatsToolStripMenuItem";
			this->saveCurrentStatsToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->saveCurrentStatsToolStripMenuItem->Text = L"Save Current Stats";
			this->saveCurrentStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveCurrentStatsToolStripMenuItem_Click);
			// 
			// saveCurrentStatsAsToolStripMenuItem
			// 
			this->saveCurrentStatsAsToolStripMenuItem->Name = L"saveCurrentStatsAsToolStripMenuItem";
			this->saveCurrentStatsAsToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->saveCurrentStatsAsToolStripMenuItem->Text = L"Save Current Stats As...";
			this->saveCurrentStatsAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveCurrentStatsAsToolStripMenuItem_Click);
			// 
			// btn_reset
			// 
			this->btn_reset->Enabled = false;
			this->btn_reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_reset->Location = System::Drawing::Point(204, 688);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(90, 50);
			this->btn_reset->TabIndex = 171;
			this->btn_reset->Text = L"Reset Hand";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &Form1::btn_reset_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// playerToolStripMenuItem
			// 
			this->playerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadYourSavedStatsToolStripMenuItem, 
				this->saveYourCurrentStatsToolStripMenuItem, this->highScoresToolStripMenuItem});
			this->playerToolStripMenuItem->Name = L"playerToolStripMenuItem";
			this->playerToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->playerToolStripMenuItem->Text = L"Player";
			// 
			// loadYourSavedStatsToolStripMenuItem
			// 
			this->loadYourSavedStatsToolStripMenuItem->Name = L"loadYourSavedStatsToolStripMenuItem";
			this->loadYourSavedStatsToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->loadYourSavedStatsToolStripMenuItem->Text = L"Load your saved stats";
			// 
			// saveYourCurrentStatsToolStripMenuItem
			// 
			this->saveYourCurrentStatsToolStripMenuItem->Name = L"saveYourCurrentStatsToolStripMenuItem";
			this->saveYourCurrentStatsToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->saveYourCurrentStatsToolStripMenuItem->Text = L"Save your current stats";
			// 
			// highScoresToolStripMenuItem
			// 
			this->highScoresToolStripMenuItem->Name = L"highScoresToolStripMenuItem";
			this->highScoresToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->highScoresToolStripMenuItem->Text = L"High Scores";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(587, 688);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 50);
			this->button1->TabIndex = 172;
			this->button1->Text = L"Simulate Different Builds";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1276, 776);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btn_reset);
			this->Controls->Add(this->cBox_ShowEV);
			this->Controls->Add(this->btn_SelUpper);
			this->Controls->Add(this->btn_SelLower);
			this->Controls->Add(this->rBtn_low);
			this->Controls->Add(this->rBtn_high);
			this->Controls->Add(this->lbl_EV);
			this->Controls->Add(this->lbl_score3);
			this->Controls->Add(this->lbl_score2);
			this->Controls->Add(this->lbl_score1);
			this->Controls->Add(this->lbl_score0);
			this->Controls->Add(this->btn_Clear_Scores);
			this->Controls->Add(this->btn_Sort_Suit);
			this->Controls->Add(this->btn_Sort_Rank);
			this->Controls->Add(this->pictureBox117);
			this->Controls->Add(this->pictureBox116);
			this->Controls->Add(this->pictureBox115);
			this->Controls->Add(this->pictureBox114);
			this->Controls->Add(this->pictureBox113);
			this->Controls->Add(this->pictureBox112);
			this->Controls->Add(this->pictureBox111);
			this->Controls->Add(this->pictureBox110);
			this->Controls->Add(this->pictureBox109);
			this->Controls->Add(this->pictureBox108);
			this->Controls->Add(this->pictureBox107);
			this->Controls->Add(this->pictureBox106);
			this->Controls->Add(this->pictureBox105);
			this->Controls->Add(this->pictureBox104);
			this->Controls->Add(this->pictureBox103);
			this->Controls->Add(this->pictureBox102);
			this->Controls->Add(this->pictureBox101);
			this->Controls->Add(this->pictureBox100);
			this->Controls->Add(this->pictureBox99);
			this->Controls->Add(this->pictureBox98);
			this->Controls->Add(this->pictureBox97);
			this->Controls->Add(this->pictureBox96);
			this->Controls->Add(this->pictureBox95);
			this->Controls->Add(this->pictureBox94);
			this->Controls->Add(this->pictureBox93);
			this->Controls->Add(this->pictureBox92);
			this->Controls->Add(this->pictureBox91);
			this->Controls->Add(this->pictureBox90);
			this->Controls->Add(this->pictureBox89);
			this->Controls->Add(this->pictureBox88);
			this->Controls->Add(this->pictureBox87);
			this->Controls->Add(this->pictureBox86);
			this->Controls->Add(this->pictureBox85);
			this->Controls->Add(this->pictureBox84);
			this->Controls->Add(this->pictureBox83);
			this->Controls->Add(this->pictureBox82);
			this->Controls->Add(this->pictureBox81);
			this->Controls->Add(this->pictureBox80);
			this->Controls->Add(this->pictureBox79);
			this->Controls->Add(this->pictureBox78);
			this->Controls->Add(this->pictureBox77);
			this->Controls->Add(this->pictureBox76);
			this->Controls->Add(this->pictureBox75);
			this->Controls->Add(this->pictureBox74);
			this->Controls->Add(this->pictureBox73);
			this->Controls->Add(this->pictureBox72);
			this->Controls->Add(this->pictureBox71);
			this->Controls->Add(this->pictureBox70);
			this->Controls->Add(this->pictureBox69);
			this->Controls->Add(this->pictureBox68);
			this->Controls->Add(this->pictureBox67);
			this->Controls->Add(this->pictureBox66);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->btn_sim);
			this->Controls->Add(this->btn_stack);
			this->Controls->Add(this->btn_build);
			this->Controls->Add(this->btn_submit);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox26);
			this->Controls->Add(this->pictureBox25);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->btn_deal);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox24);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox23);
			this->Controls->Add(this->pictureBox22);
			this->Controls->Add(this->pictureBox21);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox20);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox19);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox18);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox17);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox16);
			this->Controls->Add(this->pictureBox15);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->mStrip_main);
			this->Controls->Add(this->panel3);
			this->MainMenuStrip = this->mStrip_main;
			this->Name = L"Form1";
			this->Text = L"Chinese Poker";
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox58))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox59))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox60))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox65))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox117))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox116))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox115))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox114))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox113))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox112))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox111))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox110))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox109))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox108))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox107))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox106))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox105))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox104))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox103))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox102))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox101))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox100))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox99))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox98))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox97))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox96))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox95))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox94))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox93))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox92))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox91))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox90))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox89))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox88))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox87))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox86))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox85))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox84))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox83))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox82))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox81))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox80))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox79))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox78))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox77))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox76))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox75))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox73))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox70))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox69))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox68))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox67))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox66))->EndInit();
			this->mStrip_main->ResumeLayout(false);
			this->mStrip_main->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion

		// Init functions
		private: System::Void InitPicBoxArray(void)
				 {
					picBox = gcnew array<PictureBox ^>(TOTAL_PIC_BOXES);
					picBoxData = gcnew array<int>(TOTAL_PIC_BOXES);
					for(int i = 0; i < TOTAL_PIC_BOXES; i++)
						picBoxData[i] = EMPTY;
					picBox[0] = pictureBox1;
					picBox[1] = pictureBox2;
					picBox[2] = pictureBox3;
					picBox[3] = pictureBox4;
					picBox[4] = pictureBox5;
					picBox[5] = pictureBox6;
					picBox[6] = pictureBox7;
					picBox[7] = pictureBox8;
					picBox[8] = pictureBox9;
					picBox[9] = pictureBox10;
					picBox[10] = pictureBox11;
					picBox[11] = pictureBox12;
					picBox[12] = pictureBox13;
					picBox[13] = pictureBox14;
					picBox[14] = pictureBox15;
					picBox[15] = pictureBox16;
					picBox[16] = pictureBox17;
					picBox[17] = pictureBox18;
					picBox[18] = pictureBox19;
					picBox[19] = pictureBox20;
					picBox[20] = pictureBox21;
					picBox[21] = pictureBox22;
					picBox[22] = pictureBox23;
					picBox[23] = pictureBox24;
					picBox[24] = pictureBox25;
					picBox[25] = pictureBox26;
					picBox[26] = pictureBox27;
					picBox[27] = pictureBox28;
					picBox[28] = pictureBox29;
					picBox[29] = pictureBox30;
					picBox[30] = pictureBox31;
					picBox[31] = pictureBox32;
					picBox[32] = pictureBox33;
					picBox[33] = pictureBox34;
					picBox[34] = pictureBox35;
					picBox[35] = pictureBox36;
					picBox[36] = pictureBox37;
					picBox[37] = pictureBox38;
					picBox[38] = pictureBox39;
					picBox[39] = pictureBox52;
					picBox[40] = pictureBox51;
					picBox[41] = pictureBox50;
					picBox[42] = pictureBox49;
					picBox[43] = pictureBox48;
					picBox[44] = pictureBox47;
					picBox[45] = pictureBox46;
					picBox[46] = pictureBox45;
					picBox[47] = pictureBox44;
					picBox[48] = pictureBox43;
					picBox[49] = pictureBox42;
					picBox[50] = pictureBox41;
					picBox[51] = pictureBox40;
					picBox[52] = pictureBox65;
					picBox[53] = pictureBox64;
					picBox[54] = pictureBox63;
					picBox[55] = pictureBox62;
					picBox[56] = pictureBox61;
					picBox[57] = pictureBox60;
					picBox[58] = pictureBox59;
					picBox[59] = pictureBox58;
					picBox[60] = pictureBox57;
					picBox[61] = pictureBox56;
					picBox[62] = pictureBox55;
					picBox[63] = pictureBox54;
					picBox[64] = pictureBox53;
					picBox[65] = pictureBox66;
					picBox[66] = pictureBox67;
					picBox[67] = pictureBox68;
					picBox[68] = pictureBox69;
					picBox[69] = pictureBox70;
					picBox[70] = pictureBox71;
					picBox[71] = pictureBox72;
					picBox[72] = pictureBox73;
					picBox[73] = pictureBox74;
					picBox[74] = pictureBox75;
					picBox[75] = pictureBox76;
					picBox[76] = pictureBox77;
					picBox[77] = pictureBox78;
					picBox[78] = pictureBox79;
					picBox[79] = pictureBox80;
					picBox[80] = pictureBox81;
					picBox[81] = pictureBox82;
					picBox[82] = pictureBox83;
					picBox[83] = pictureBox84;
					picBox[84] = pictureBox85;
					picBox[85] = pictureBox86;
					picBox[86] = pictureBox87;
					picBox[87] = pictureBox88;
					picBox[88] = pictureBox89;
					picBox[89] = pictureBox90;
					picBox[90] = pictureBox91;
					picBox[91] = pictureBox92;
					picBox[92] = pictureBox93;
					picBox[93] = pictureBox94;
					picBox[94] = pictureBox95;
					picBox[95] = pictureBox96;
					picBox[96] = pictureBox97;
					picBox[97] = pictureBox98;
					picBox[98] = pictureBox99;
					picBox[99] = pictureBox100;
					picBox[100] = pictureBox101;
					picBox[101] = pictureBox102;
					picBox[102] = pictureBox103;
					picBox[103] = pictureBox104;
					picBox[104] = pictureBox105;
					picBox[105] = pictureBox106;
					picBox[106] = pictureBox107;
					picBox[107] = pictureBox108;
					picBox[108] = pictureBox109;
					picBox[109] = pictureBox110;
					picBox[110] = pictureBox111;
					picBox[111] = pictureBox112;
					picBox[112] = pictureBox113;
					picBox[113] = pictureBox114;
					picBox[114] = pictureBox115;
					picBox[115] = pictureBox116;
					picBox[116] = pictureBox117;
				 }
		private: System::Void InitHands(void)
				{
					for(int i = 0; i < 13; i++)
						SetPicBoxTo(i, table->deck[i]);
					for(int i = 13; i < 26; i++)
						SetPicBoxTo(i, EMPTY);
				}

		// Utility functions
		private: System::Void PushPlayerHandLeft(void)
				 {
					for(int i = 0; i < 12; i++)
					{
						if(picBoxData[i] == EMPTY)
						{
							for(int j = i; j < 12; j++)
								picBoxData[j] = picBoxData[j+1];
							picBoxData[12] = EMPTY;
						}

						if(picBoxData[i] == EMPTY)
						{
							// Just moved in another empty slot. Check for end condition here(all EMPTY to the right)
							int j;
							for(j = i; j < 13; j++)
							{
								if(picBoxData[j] != EMPTY)
								{
									i--;
									break;
								}
							}

							if(j == 13) // Didn't find a non-empty slot
							{
								break;
							}
						}
					}
				}
		private: int GetIndex(PictureBox ^ pb)
				{
					for(int i = 0; i < picBox->Length; i++)
					{
						if(picBox[i] == pb) 
							return i;
					}
					return EMPTY; // Should never get called
				}
		private: bool IsIn(int x, int y, Point pbOrigin, int width, int height)
				 {
					return  (x >= pbOrigin.X) && 
							(x <= pbOrigin.X + width) && 
							(y >= pbOrigin.Y) && 
							(y <= pbOrigin.Y + height);
				 }
		private: bool IsIn(int x, int y, PictureBox ^pb)
				{
					return IsIn(x, y, pb->Location, pb->Width, pb->Height);
				}
		private: bool IsSelected(PictureBox^ pb)
				{
					return pb->BorderStyle == BorderStyle::FixedSingle;
				}
		private: System::Void SetSelected(PictureBox^ pb, bool val)
				{
					if((pb->BorderStyle == BorderStyle::None) && val)
						pb->Location = Point(pb->Location.X, pb->Location.Y - 20);
					else if((pb->BorderStyle == BorderStyle::FixedSingle) && !val)
						pb->Location = Point(pb->Location.X, pb->Location.Y + 20);

					pb->BorderStyle = (val ? BorderStyle::FixedSingle : BorderStyle::None);
				}

		private: System::Void RefreshScoreLabels(void)
				{
					lbl_score0->Text = ("You: " + score[0].ToString());
					lbl_score1->Text = ("Player 2: " + score[1].ToString());
					lbl_score2->Text = ("Player 3: " + score[2].ToString());
					lbl_score3->Text = ("Player 4: " + score[3].ToString());
				}
		// Picture Box Event handlers
		private: System::Void pictureBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
				{
					PictureBox ^pbs = (PictureBox^)sender;
					if(pbs->Visible && (picBoxData[GetIndex(pbs)] != EMPTY) && btn_Sort_Rank->Enabled) // SortRank->Enabled means the hand is in play
					{
						draggedPB = pbs;
						pbs->BringToFront();
						initPBPos = pbs->Location;
						initMousePos.X = initPBPos.X + e->X;
						initMousePos.Y = initPBPos.Y + e->Y;
					}
				}
		private: System::Void pictureBox_Click(System::Object^ sender, System::EventArgs^)
				{
					/*
					 * For float clicking *
					static int lastTime = 0;
					int newTime = System::DateTime:: + 1000 * System::DateTime::Second; // Add a second
					if(newTime < lastTime)
						newTime += 60000; // Add a minute
					if(newTime - lastTime <= DOUBLE_CLICK_THRESHOLD_MS)
					{
						RightClick(sender);
						lastTime = newTime;
						return;
					}
					lastTime = newTime;
					*/

					//Don't act while doing drag/drops
					if((initMousePos == Point::Empty) && ((PictureBox^)sender)->Visible && btn_Sort_Rank->Enabled)
						DoClickEffect(sender);
				}
		private: System::Void DoClickEffect(Object^ sender)
				{
					PictureBox ^ senderPB = (PictureBox ^)sender;
					if(IsSelected(senderPB))
					{	
						 SetSelected(senderPB, false);
						 cardsSelected--;
					}
					else if(cardsSelected == 0 || CtrlPressed)
					{
						SetSelected(senderPB, true);
						cardsSelected++;
					}
					else
					{
						// Find the selected card and do a swap
						int index = 0;
						while(!IsSelected(picBox[index]))
							index++;
						SwapPB(index, GetIndex(senderPB));
					}				 
					for(int i = 1; i < 13; i++)
						picBox[i]->BringToFront();

					if(stackedDeck)
					{
						for(int i = 0; i < 4; i++)
							for(int j = 0; j < 13; j++)
								picBox[65 + i*13 + j]->BringToFront();
						// if exactly 13 cards in first 26 slots, enable btn_build, else disable
						int count = 0;
						for(int i = 0; i < 26; i++)
							if(picBoxData[i] == EMPTY)
								count++;
						btn_build->Enabled = (count == 13);
					}
					int i;
					for(i = 13; i < 26; i++)
						if(picBoxData[i] == EMPTY)
							break;
					if(i == 26)
					{
						// Sort Hands withot changing picBoxes
						array<int> ^highHand = gcnew array<int>(5);
						array<int> ^midHand = gcnew array<int>(5);
						array<int> ^smallHand = gcnew array<int>(3);
						for(int a=0; a<5; a++)
							highHand[a] = picBoxData[13+a];
						for(int a=0; a<5; a++)
							midHand[a] = picBoxData[18+a];
						for(int a=0; a<3; a++)
							smallHand[a] = picBoxData[23+a];

						bool loop;
						do
						{
							loop = false;
							for(int a = 0; a < 4; a++)
							{
								if(highHand[a] > highHand[a+1])
								{
									int swap = highHand[a];
									highHand[a] = highHand[a+1];
									highHand[a+1] = swap;
									loop = true;
								}
							}
						}while(loop);
						do
						{
							loop = false;
							for(int a = 0; a < 4; a++)
							{
								if(midHand[a] > midHand[a+1])
								{
									int swap = midHand[a];
									midHand[a] = midHand[a+1];
									midHand[a+1] = swap;
									loop = true;
								}
							}
						}while(loop);
						do
						{
							loop = false;
							for(int a = 0; a < 2; a++)
							{
								if(smallHand[a] > smallHand[a+1])
								{
									int swap = smallHand[a];
									smallHand[a] = smallHand[a+1];
									smallHand[a+1] = swap;
									loop = true;
								}
							}
						}while(loop);

						if(rBtn_high->Checked)
							btn_submit->Enabled = table->brain->IsValid(midHand, smallHand, highHand);
						else
							btn_submit->Enabled = table->brain->IsValid(highHand, smallHand);
					}
					int a=0;
					while(picBoxData[a] != EMPTY)
						a++;
					btn_reset->Enabled = (a!=13);
				}
		private: System::Void SwapPB(int selected, int unselected)
			 {
				Image ^ tempImageP = (Image ^)picBox[selected]->Image->Clone();
				int tempPicData = picBoxData[selected];;
				picBoxData[selected] = picBoxData[unselected];
				picBoxData[unselected] = tempPicData;
				picBox[selected]->Image = picBox[unselected]->Image;
				picBox[unselected]->Image = tempImageP;
				SetSelected(picBox[selected], false);
				cardsSelected--;
			 }
		private: System::Void RightClick(System::Object^ sender)
			 {
				int i;
				for(i = 0; i < 26; i++)
					SetSelected(picBox[i], false);
				for(i = 13; i < 26; i++)
				{
					if(picBox[i]->Image->Equals(Image::FromFile("cards\\backBlue.bmp")))
						break;
				}
				
				if(i == 26)
					return;
				SetSelected(picBox[i], true);
				DoClickEffect(sender);
			 }

		private: System::Void SetPicBoxTo(int index, int cardValue)
				 {
					 if(cardValue == EMPTY)
					 {
						picBoxData[index] = EMPTY;
						picBox[index]->Load("cards\\backBlue.bmp");
					 }
					 else
					 {
						 picBox[index]->Load("cards\\" + table->deck->GetCondensedID(cardValue).ToString() + ".bmp");
						 picBoxData[index] = cardValue;
					 }
				 }
		// Button/ScrollBar Event handlers
		private: System::Void hScrollBar1_Scroll(System::Object^ , System::Windows::Forms::ScrollEventArgs^)
				{
					for(int i = 0; i < 13; i++)
					{
						picBox[i]->Location = Point(11 + (30 + hScrollBar1->Value) * i, 501 - (IsSelected(picBox[i]) ? 20 : 0));
						picBox[i]->BringToFront();
					}
				}
		private: System::Void btn_deal_Click(System::Object^ sender, System::EventArgs^  e)
				{
					btn_deal->Enabled = false;
					rBtn_high->Enabled = false;
					rBtn_low->Enabled = false;
					this->btn_stack->Enabled = false;
					panel1->Hide();
					panel2->Hide();
					panel3->Hide();

					table->deck->Shuffle();
					cardsSelected = 0;

					if(stackedDeck)
					{
						stackedDeck = false;
						for(int i = 0; i < 13; i++)
						{
							SetPicBoxTo(i+13, EMPTY);
							SetSelected(picBox[i], false);
							SetSelected(picBox[i+13], false);
						}
						cardsSelected = 0;

						for(int i = 65; i < 117; i++)
						{
							picBox[i]->Hide();
							SetSelected(picBox[i], false);
						}

						table->deck->Shuffle();
						for(int i = 0; i < 13; i++)
						{
							if(picBoxData[i]==EMPTY)
								SetPicBoxTo(i, table->deck[i]);
							else
							{
								// Find the card that should be in deck[i] and swap them
								int j=0;
								while(table->deck[j] != picBoxData[i])
									j++;
								table->deck->cards[j] = table->deck[i];
								table->deck->cards[i] = picBoxData[i];
							}
						}
					}
					else
					{
						InitHands();
					}

					btn_Sort_Rank_Click(sender, e);
					btn_Sort_Rank->Enabled = true;
					btn_Sort_Suit->Enabled = true;
					btn_SelUpper->Enabled = true;
					btn_SelLower->Enabled = true;
					btn_build->Enabled = true;
					btn_stack->Text = "Stack Hand";
				 }
		private: System::Void btn_submit_Click(System::Object^, System::EventArgs^)
				{
					btn_deal->Enabled = true;
					rBtn_high->Enabled = true;
					rBtn_low->Enabled = true;
					btn_stack->Enabled = true;
					btn_reset->Enabled = false;

					for(int i = 0; i < 13; i++)
					{
						SetSelected(picBox[i], false);
						SetSelected(picBox[i+13], false);
					}
					cardsSelected = 0;
					if(stackedDeck)
					{
						// Must clear the player hand and face-up deck, then deal the remaining cards to the automatic players
						for(int i = 0; i < 13; i++)
						{
							SetPicBoxTo(i, EMPTY);
						}
						for(int i = 65; i < 117; i++)
						{
							SetSelected(picBox[i], false);
							picBox[i]->Hide();
						}

						table->deck->Shuffle();
						for(int i = 13; i < 26; i++)
						{
							// Find the card that should be in deck[i] and swap them
							int j=0;
							while(table->deck[j] != picBoxData[i])
								j++;
							int swap = table->deck->cards[j];
							table->deck->cards[j] = table->deck[i-13];
							table->deck->cards[i-13] = swap;
						}
					}

					// Sort player hands
					bool loop;
					int swap;
					do
					{
						loop = false;
						for(int i = 23; i < 24; i++)
						{
							if(picBoxData[i] > picBoxData[i+1])
							{
								swap = picBoxData[i];
								picBoxData[i] = picBoxData[i+1];
								picBoxData[i+1] = swap;
								loop = true;
							}
						}
					} while(loop);

					do
					{
						loop = false;
						for(int i = 13; i < 16; i++)
						{
							if(picBoxData[i] > picBoxData[i+1])
							{
								swap = picBoxData[i];
								picBoxData[i] = picBoxData[i+1];
								picBoxData[i+1] = swap;
								loop = true;
							}
						}
					} while(loop);

					do
					{
						loop = false;
						for(int i = 18; i < 21; i++)
						{
							if(picBoxData[i] > picBoxData[i+1])
							{
								swap = picBoxData[i];
								picBoxData[i] = picBoxData[i+1];
								picBoxData[i+1] = swap;
								loop = true;
							}
						}
					} while(loop);

					/*
					for(int i=0; i<13; i++)
					{
						// Convert to Expanded ID
						int suit = picBoxData[13+i] & 0x3;
						table->deck->cards[i] = (picBoxData[13+i]-suit)<<2;
						suit = suit==0 ? 1 : suit==1 ? 2 : suit==2 ? 4 : 8;
						table->deck->cards[i] |= suit;
					}
					*/
					
					table->SortHand(1);
					table->SortHand(2);
					table->SortHand(3);

					// Solve opponent hands
					table->brain->SolveHand(rBtn_high->Checked, table->deck, 1);
					table->brain->SolveHand(rBtn_high->Checked, table->deck, 2);
					table->brain->SolveHand(rBtn_high->Checked, table->deck, 3);

					// Assess value of the player's hand
					handValue[0, 0] = table->brain->Evaluate(rBtn_high->Checked, true, picBoxData[13], picBoxData[14], picBoxData[15], picBoxData[16], picBoxData[17]);
					handValue[0, 1] = table->brain->Evaluate(rBtn_high->Checked, false, picBoxData[18], picBoxData[19], picBoxData[20], picBoxData[21], picBoxData[22]);
					handValue[0, 2] = (rBtn_high->Checked ? table->brain->dbHigh : table->brain->dbLow)->Small->All[RANK(picBoxData[23]), RANK(picBoxData[24]), RANK(picBoxData[25])];

					// Reduntant evaluation of all hands for scoring and debugging
					for(int i=0; i<4; i++)
					{
						handValue[i,0] = table->brain->Evaluate(rBtn_high->Checked, true, table->deck[13*i], table->deck[13*i+1], table->deck[13*i+2], table->deck[13*i+3], table->deck[13*i+4]);
						handValue[i,1] = table->brain->Evaluate(rBtn_high->Checked, false, table->deck[13*i+5], table->deck[13*i+6], table->deck[13*i+7], table->deck[13*i+8], table->deck[13*i+9]);
						handValue[i,2] = (rBtn_high->Checked ? table->brain->dbHigh : table->brain->dbLow)->Small->All[RANK(table->deck[13*i+10]), RANK(table->deck[13*i+11]), RANK(table->deck[13*i+12])];
					}
					
					if(!stackedDeck)
					{
						// Adjust scores
						for(int i = 0; i < 3; i++)
						{
							for(int j = i + 1; j < 4; j++)
							{
								for(int k = 0; k < 3; k++)
								{
									if(handValue[i, k] > handValue[j, k])
									{
										score[i]++;
										score[j]--;
									}
									else if(handValue[i, k] < handValue[j, k])
									{
										score[i]--;
										score[j]++;
									}
								}
							}
						}
						RefreshScoreLabels();
					}

					// Show opponent hands
					for(int i = 13; i < 52; i++)
						picBox[i+13]->Load("cards\\" + table->deck->GetCondensedID(table->deck[i]).ToString() + ".bmp");
					this->panel1->Show();
					this->panel2->Show();
					this->panel3->Show();
					
					// Adjust Active Controls
					btn_submit->Enabled = false;
					btn_Sort_Rank->Enabled = false;
					btn_Sort_Suit->Enabled = false;
					btn_SelUpper->Enabled = false;
					btn_SelLower->Enabled = false;
					btn_build->Enabled = false;
					btn_stack->Text = "Stack Hand";
					stackedDeck = false;

					// Write all hand EVs to lbl_EV
					System::String ^result = "";
					for(int i = 2; i >= 0; i--)
					{
						for(int j = 0; j < 4; j++)
						{
							result += handValue[j, i];
							if(handValue[j,i].ToString()->Length < 9)
								result += "\t";
							result += "\t";
						}
						result += "\r\n";
					}
					lbl_EV->Text = result;
				 }
		private: System::Void btn_build_Click(System::Object^, System::EventArgs^)
				{
					for(int i = 0; i < 13; i++)
					{
						SetSelected(picBox[i], false);
						SetSelected(picBox[i+13], false);
					}
					cardsSelected = 0;

					if(stackedDeck)
					{
						// Make deck[12:0] match first 13 non-empty pixBoxes in picBox[25:0]
						int count = 0;
						for(int i = 0; i < 26; i++)
						{
							if(picBoxData[i] == EMPTY)
								continue;

							int j=0;
							while(table->deck[j] != picBoxData[i])
								j++;
							int swap = table->deck[j];
							table->deck->cards[j] = table->deck[count]; // swap first X cards from deck with preselected cards
							table->deck->cards[count] = swap;
							count++;
						}
						if(count!=13)
							throw gcnew System::NotSupportedException();
					}

					table->SortHand(0); // First 13 cards
					table->brain->SolveHand(rBtn_high->Checked, table->deck, 0);

					for(int i = 0; i < 13; i++)
					{
						SetPicBoxTo(i, EMPTY);
						SetPicBoxTo(i+13, table->deck[i]);
					}
					btn_submit->Enabled = true;
					btn_reset->Enabled = true;
				}
		private: System::Void btn_stack_Click(System::Object^, System::EventArgs^)
				{
					panel1->Hide();
					panel2->Hide();
					panel3->Hide();
					stackedDeck = true;
					delete table->deck;
					table->deck = gcnew Deck(52);
					for(int i = 0; i < 26; i++)
						SetPicBoxTo(i, EMPTY);
					for(int i = 65; i < 117; i++)
					{
						SetPicBoxTo(i, table->deck[i-65]);
						picBox[i]->Show();
						picBox[i]->Visible = true;
					}
					for(int i = 0; i < 4; i++)
						for(int j = 0; j < 13; j++)
							picBox[65 + i*13 + j]->BringToFront();

					btn_deal->Enabled = true;
					rBtn_high->Enabled = true;
					rBtn_low->Enabled = true;
					btn_submit->Enabled = false;
					btn_build->Enabled = false;
					btn_Sort_Rank->Enabled = true;
					btn_Sort_Suit->Enabled = true;
					btn_SelUpper->Enabled = true;
					btn_SelLower->Enabled = true;
					btn_stack->Text = "Reset Deck";
				}
		private: System::Void btn_sim_Click(System::Object^, System::EventArgs^)
				{
					SimForm ^sf = gcnew SimForm(this, table);
					this->Enabled = false;
					sf->Show();					
					
					/*
					#pragma region Scoring
					// Reduntant evaluation of all hands for scoring purposes
					for(int i=0; i<4; i++)
					{
						handValue[i,0] = table->brain->Evaluate(rBtn_high->Checked, true, table->deck[13*i], table->deck[13*i+1], table->deck[13*i+2], table->deck[13*i+3], table->deck[13*i+4]);
						handValue[i,1] = table->brain->Evaluate(rBtn_high->Checked, false, table->deck[13*i+5], table->deck[13*i+6], table->deck[13*i+7], table->deck[13*i+8], table->deck[13*i+9]);
						Database ^tempDB = rBtn_high->Checked ? (table->brain->dbHigh) : (table->brain->dbLow);
						handValue[i,2] = tempDB->Small->All[RANK(table->deck[13*i+10]), RANK(table->deck[13*i+11]), RANK(table->deck[13*i+12])];
					}

					// Adjust scores
					for(int i = 0; i < 3; i++)
					{
						for(int j = i + 1; j < 4; j++)
						{
							for(int k = 0; k < 3; k++)
							{
								if(handValue[i, k] > handValue[j, k])
								{
									score[i]++;
									score[j]--;
								}
								else if(handValue[i, k] < handValue[j, k])
								{
									score[i]--;
									score[j]++;
								}
							}
						}
					}

					RefreshScoreLabels();
					#pragma endregion
					*/

					/*
					// Show hands
					for(int i = 0; i < 52; i++)
						SetPicBoxTo(i+13, table->deck[i]);
					this->panel1->Show();
					this->panel2->Show();
					this->panel3->Show();
					*/
					// Adjust Active Controls
					btn_submit->Enabled = false;
					btn_Sort_Rank->Enabled = false;
					btn_Sort_Suit->Enabled = false;
					btn_SelUpper->Enabled = false;
					btn_SelLower->Enabled = false;
					btn_build->Enabled = false;
					btn_deal->Enabled = true;
					rBtn_high->Enabled = true;
					rBtn_low->Enabled = true;
					btn_stack->Enabled = true;
					btn_stack->Text = "Stack Hand";
					stackedDeck = false;

					/*
					#pragma region Display EV
					//Display all hand values
					System::String ^result = "";
					for(int i = 2; i >= 0; i--)
					{
						for(int j = 0; j < 4; j++)
						{
							result += handValue[j, i];
							if(handValue[j,i].ToString()->Length < 9)
								result += "\t";
							result += "\t";
						}
						result += "\r\n";
					}
					lbl_EV->Text = result;
					#pragma endregion
					*/
				}
		private: System::Void btn_Sort_Rank_Click(System::Object^, System::EventArgs^)
			{
				PushPlayerHandLeft();
				bool loop = true;
				int swap;
				while(loop)
				{
					loop = false;
					for(int i = 0; i < 12; i++)
					{
						if(picBoxData[i+1] == EMPTY)
							break;
						if(picBoxData[i] > picBoxData[i+1])
						{
							swap = picBoxData[i];
							picBoxData[i] = picBoxData[i+1];
							picBoxData[i+1] = swap;
							loop = true;
						}
					}
				}

				for(int i = 0; i < 13; i ++)
				{
					if(picBoxData[i] == EMPTY)
						picBox[i]->Load("cards\\backBlue.bmp");
					else
						picBox[i]->Load("cards\\" + table->deck->GetCondensedID(picBoxData[i]).ToString() + ".bmp");
				}
			}
		private: System::Void btn_Sort_Suit_Click(System::Object^, System::EventArgs^)
			{
				PushPlayerHandLeft();
				bool loop = true;
				int swap;
				while(loop)
				{
					loop = false;
					for(int i = 0; i < 12; i++)
					{
						if(picBoxData[i+1] == EMPTY)
							break;
						int suitA = SUIT(picBoxData[i]);
						int suitB = SUIT(picBoxData[i+1]);
						if((suitA > suitB) || ((suitA == suitB) && picBoxData[i] > picBoxData[i+1]))
						{
							swap = picBoxData[i];
							picBoxData[i] = picBoxData[i+1];
							picBoxData[i+1] = swap;
							loop = true;
						}
					}
				}

				for(int i = 0; i < 13; i ++)
				{
					if(picBoxData[i] == EMPTY)
						picBox[i]->Load("cards\\backBlue.bmp");
					else
						picBox[i]->Load("cards\\" + table->deck->GetCondensedID(picBoxData[i]).ToString() + ".bmp");
				}
			}
		private: System::Void btn_Clear_Scores_Click(System::Object^, System::EventArgs^)
			{
				score[0] = 0;
				score[1] = 0;
				score[2] = 0;
				score[3] = 0;
				RefreshScoreLabels();
			}
		private: System::Void btn_SelUpper_Click(System::Object^ , System::EventArgs^) {
			bool allSelected = true;
			for(int i=13; i<26; i++)
				if(!IsSelected(picBox[i]))
				{
					allSelected = false;
					break;
				}
			if(allSelected)
			{
				for(int i=13; i<26; i++)
					SetSelected(picBox[i], false);
				cardsSelected -= 13;
			}
			else
			{
				int initCardsSelected = cardsSelected;
				for(int i=13; i < 26; i++)
				{
					if(!IsSelected(picBox[i]) && picBoxData[i]==EMPTY)
					{
						SetSelected(picBox[i], true);
						cardsSelected++;
					}
				}

				if(initCardsSelected == cardsSelected)
				{
					for(int i=13; i<26; i++)
					{
						if(!IsSelected(picBox[i]))
						{
							SetSelected(picBox[i], true);
							cardsSelected++;
						}
					}
				}
			}
		}
		private: System::Void btn_SelLower_Click(System::Object^ , System::EventArgs^) {
			bool allSelected = true;
			for(int i=0; i<13; i++)
				if(!IsSelected(picBox[i]))
				{
					allSelected = false;
					break;
				}
			if(allSelected)
			{
				for(int i=0; i<13; i++)
					SetSelected(picBox[i], false);
				cardsSelected -= 13;
			}
			else
			{
				int initCardsSelected = cardsSelected;
				for(int i=0; i < 13; i++)
				{
					if(!IsSelected(picBox[i]) && picBoxData[i]!=EMPTY)
					{
						SetSelected(picBox[i], true);
						cardsSelected++;
					}
				}
				if(initCardsSelected == cardsSelected)
				{
					for(int i=0; i<13; i++)
					{
						if(!IsSelected(picBox[i]))
						{
							SetSelected(picBox[i], true);
							cardsSelected++;
						}
					}
				}
			}
		}
		private: System::Void btn_reset_Click(System::Object^, System::EventArgs^) {
						//int count = 0;
						table->SortHand(0);
						for(int i = 0; i < 13; i++)
						{
							SetPicBoxTo(i, table->deck[i]);
							SetPicBoxTo(i+13, EMPTY);
						}
						btn_reset->Enabled = false;
						btn_submit->Enabled = false;
		 }
		// Other Event handlers
		private: System::Void Form1_KeyDown(System::Object^, System::Windows::Forms::KeyEventArgs^ e)
				{
					CtrlPressed = e->Control;
				}
		private: System::Void Form1_KeyUp(System::Object^, System::Windows::Forms::KeyEventArgs^ e) 
				{
					CtrlPressed = e->Control;
				}

		private: System::Void Form1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
				if(!initMousePos.Equals(Point::Empty) && (picBoxData[GetIndex((PictureBox^)sender)] != EMPTY) && btn_Sort_Rank->Enabled)
				{
					Point diff;
					diff.X += draggedPB->Location.X + e->X;
					diff.Y += draggedPB->Location.Y + e->Y;
					// diff is currently the absolute coordinates of the mouse
					diff.X -= initMousePos.X;
					diff.Y -= initMousePos.Y;
					// diff is how far the mouse has moved in absolute coordinates
					draggedPB->Location = Point(initPBPos.X + diff.X, initPBPos.Y + diff.Y);
				}
			}
		private: System::Void Form1_MouseUp(System::Object^, System::Windows::Forms::MouseEventArgs^ e)
			{
				if(!initMousePos.Equals(Point::Empty) && btn_Sort_Rank->Enabled)
				{
					int absX = e->X + draggedPB->Location.X;
					int absY = e->Y + draggedPB->Location.Y;
					// Check if the mouse is in bounding box of the original pictureBox and hasn't moved very far. If so, do a click
					if(IsIn(absX, absY, initPBPos, draggedPB->Width, draggedPB->Height) && (initMousePos == Point::Empty || Math::Pow(absX - initMousePos.X, 2)+Math::Pow(absY-initMousePos.Y, 2) < 10))
					{
						draggedPB->Location = initPBPos;
						initMousePos = Point::Empty; // Resets the drag/drop logic
						this->DoClickEffect(draggedPB);
					}
					else
					{
						draggedPB->Location = initPBPos;
						initMousePos = Point::Empty; // Resets the drag/drop logic
						// Redraw if dropped [0:11] or [65:115]
						int tempIndex = GetIndex(draggedPB);
						if(0 <= tempIndex && tempIndex <= 11)
						{
							for(; tempIndex < 13; tempIndex++)
								picBox[tempIndex]->BringToFront();
						}
						else if(65 <= tempIndex && tempIndex <= 115)
						{
							for(; tempIndex < 117; tempIndex++)
								picBox[tempIndex]->BringToFront();
						}

						for(int i = 25; i != 64; i--)
						{
							if(IsIn(absX, absY, picBox[i]))
							{
								for each(PictureBox ^pb2 in picBox)
									SetSelected(pb2, false);
								SetSelected(draggedPB, true);
								cardsSelected = 1;
								DoClickEffect(picBox[i]); // Swaps the two locations
								break;
							}
							if(i == 0)
							{
								if(stackedDeck)
									i = 117; // This will be decremented and end the loop at 64, Check picBox[116:65];
								else
									break;
							}
						}
					}
				}
			}			 
		private: System::Void cBox_ShowEV_CheckedChanged(System::Object^, System::EventArgs^) {
					 
					 Form1::lbl_EV->Visible ^= true; // Toggle
			 }
		private: System::Void saveCurrentStatsAsToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			 saveFileDialog1->ShowDialog();
			 if(saveFileDialog1->FileName)
			 {
				 activeBrainFilename = openFileDialog1->FileName;
				 saveCurrentStatsToolStripMenuItem->Enabled = true;
				 table->brain->myStats->DumpToFile(saveFileDialog1->FileName);
				 saveFileDialog1->Reset();
			 }
		 }
		private: System::Void loadSavedStatsToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			 openFileDialog1->ShowDialog();
			 if(openFileDialog1->FileName)
			 {
				 activeBrainFilename = openFileDialog1->FileName;
				 saveCurrentStatsToolStripMenuItem->Enabled = true;
				 table->brain->myStats->LoadFromFile(openFileDialog1->FileName);
				 openFileDialog1->Reset();
			 }
		 }
		private: System::Void saveCurrentStatsToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
					 table->brain->myStats->DumpToFile(activeBrainFilename);
		 }
		private: System::Void mergeCurrentAndSavedStatsToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
 			 openFileDialog1->ShowDialog();
			 if(openFileDialog1->FileName)
			 {
				 table->brain->myStats->MergeFromFile(openFileDialog1->FileName);
				 openFileDialog1->Reset();
			 }
		 }
};
}