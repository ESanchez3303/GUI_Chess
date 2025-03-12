#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

// Bools to keep track of player's turn and if king is in check 
bool isP1Turn = true;
bool kingInCheck = false;

// Holds all the values of the visuals 
int xValues[9] = {0, 66,126,187,248,309,369,429,489 }; 
int yValues[9] = {0, 445,391,335,281,225,169,115,61 };

// Original board used for resets
std::string ogBoard[9][9] = {
	{"",  "" ,  "" , "", "", "", "",  "" ,  "" },
	{"", "r1", "p1", "", "", "", "", "p2", "r2"},
	{"", "h1", "p1", "", "", "", "", "p2", "h2"},
	{"", "b1", "p1", "", "", "", "", "p2", "b2"},
	{"", "q1", "p1", "", "", "", "", "p2", "q2"},
	{"", "k1", "p1", "", "", "", "", "p2", "k2"},
	{"", "b1", "p1", "", "", "", "", "p2", "b2"},
	{"", "h1", "p1", "", "", "", "", "p2", "h2"},
	{"", "r1", "p1", "" ,"" ,"" ,"", "p2", "r2"}
};

// Board array and danger lists array
std::string board[9][9];
bool p1dangerList[9][9];
bool p2dangerList[9][9];

// Clears the danger lists so that it can be reset 
void clearDangerLists() {
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			p1dangerList[i][j] = false;
			p2dangerList[i][j] = false;
		}
	}
}




namespace ChessFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	
	// Constructor - Destructor
	public: MyForm(void){ InitializeComponent();}
	protected:~MyForm() { if (components) { delete components; } }

	private:
	// Holds the piece that the player has clicked on 
	PictureBox^ chosenPiece;
	PictureBox^ passingPawn;

	// The rest of the systems visuals
	System::Windows::Forms::Panel^ panel1;



	System::Windows::Forms::Panel^ panel2;
	System::Windows::Forms::Panel^ panel3;
	System::Windows::Forms::Panel^ panel4;
	System::Windows::Forms::Panel^ panel5;
	System::Windows::Forms::Panel^ panel6;
	System::Windows::Forms::Panel^ panel7;
	System::Windows::Forms::Panel^ panel8;
	System::Windows::Forms::Panel^ panel9;
	System::Windows::Forms::Panel^ panel10;
	System::Windows::Forms::Panel^ panel11;
	System::Windows::Forms::Panel^ panel12;
	System::Windows::Forms::Panel^ panel13;
	System::Windows::Forms::Panel^ panel14;
	System::Windows::Forms::Panel^ panel15;
	System::Windows::Forms::Panel^ panel16;
	System::Windows::Forms::Panel^ panel17;
	System::Windows::Forms::Panel^ panel18;
	System::Windows::Forms::Panel^ panel19;
	System::Windows::Forms::Panel^ panel20;
	System::Windows::Forms::Panel^ panel21;
	System::Windows::Forms::Panel^ panel22;
	System::Windows::Forms::Panel^ panel23;
	System::Windows::Forms::Panel^ panel24;
	System::Windows::Forms::Panel^ panel25;
	System::Windows::Forms::Panel^ panel26;
	System::Windows::Forms::Panel^ panel27;
	System::Windows::Forms::Panel^ panel28;
	System::Windows::Forms::Panel^ panel29;
	System::Windows::Forms::Panel^ panel30;
	System::Windows::Forms::Panel^ p1TurnPanel;
	System::Windows::Forms::Panel^ p2TurnPanel;
	System::Windows::Forms::Label^ player1NameTag;
	System::Windows::Forms::Label^ player2NameTag;
	System::Windows::Forms::Panel^ settingNamePanel;
	System::Windows::Forms::Button^ startButton;
	System::Windows::Forms::TextBox^ player2NameTextBox;
	System::Windows::Forms::TextBox^ player1NameTextBox;
	System::Windows::Forms::Label^ settingNamePanelTitle;
	System::Windows::Forms::PictureBox^ pictureBox2;
	System::Windows::Forms::PictureBox^ pictureBox1;
	System::Windows::Forms::PictureBox^ p1piece1;
	System::Windows::Forms::PictureBox^ p2piece10;
	System::Windows::Forms::PictureBox^ p1piece8;
	System::Windows::Forms::PictureBox^ p1piece7;
	System::Windows::Forms::PictureBox^ p1piece6;
	System::Windows::Forms::PictureBox^ p1piece5;
	System::Windows::Forms::PictureBox^ p1piece4;
	System::Windows::Forms::PictureBox^ p1piece3;
	System::Windows::Forms::PictureBox^ p1piece2;
	System::Windows::Forms::PictureBox^ p2piece9;
	System::Windows::Forms::PictureBox^ p2piece8;
	System::Windows::Forms::PictureBox^ p2piece7;
	System::Windows::Forms::PictureBox^ p2piece6;
	System::Windows::Forms::PictureBox^ p2piece5;
	System::Windows::Forms::PictureBox^ p2piece4;
	System::Windows::Forms::PictureBox^ p2piece3;
	System::Windows::Forms::PictureBox^ p2piece2;
	System::Windows::Forms::PictureBox^ p2piece1;
	System::Windows::Forms::PictureBox^ p1piece14;
	System::Windows::Forms::PictureBox^ p1piece15;
	System::Windows::Forms::PictureBox^ p1piece16;
	System::Windows::Forms::PictureBox^ p2piece16;
	System::Windows::Forms::PictureBox^ p2piece15;
	System::Windows::Forms::PictureBox^ p2piece14;
	System::Windows::Forms::PictureBox^ p2piece13;
	System::Windows::Forms::PictureBox^ p2piece12;
	System::Windows::Forms::PictureBox^ p2piece11;
	System::Windows::Forms::PictureBox^ p1piece9;
	System::Windows::Forms::PictureBox^ p1piece10;
	System::Windows::Forms::PictureBox^ p1piece11;
	System::Windows::Forms::PictureBox^ p1piece12;
	System::Windows::Forms::PictureBox^ p1piece13;
	System::Windows::Forms::PictureBox^ p1pawnSet;
	System::Windows::Forms::PictureBox^ p1queenSet;
	System::Windows::Forms::PictureBox^ p1bishopSet;
	System::Windows::Forms::PictureBox^ p1horseSet;
	System::Windows::Forms::PictureBox^ p1rookSet;
	System::Windows::Forms::PictureBox^ p1kingSet;
	System::Windows::Forms::PictureBox^ p2kingSet;
	System::Windows::Forms::PictureBox^ p2pawnSet;
	System::Windows::Forms::PictureBox^ p2rookSet;
	System::Windows::Forms::PictureBox^ p2horseSet;
	System::Windows::Forms::PictureBox^ p2bishopSet;
	System::Windows::Forms::PictureBox^ p2queenSet;
	System::Windows::Forms::Button^ button1;
	System::Windows::Forms::Panel^ pawnUpgradeWindow;
	System::Windows::Forms::Label^ label1;
	System::Windows::Forms::Button^ queenUpgrade;
	System::Windows::Forms::Button^ horseUpgrade;
	System::Windows::Forms::Button^ bishopUpgrade;
	System::Windows::Forms::Button^ rookUpgrade;
	System::Windows::Forms::Panel^ pawnUpgradeBackgroundPanel;
	System::Windows::Forms::Panel^ gameEndedPanel;
	System::Windows::Forms::Label^ winnerText;
	System::Windows::Forms::Button^ endGameButton;
	System::Windows::Forms::Button^ hideWinningMenu;
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->p1piece1 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece10 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece8 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece7 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece6 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece5 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece4 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece3 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece2 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece9 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece8 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece7 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece6 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece5 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece4 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece3 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece2 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece1 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece14 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece15 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece16 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece16 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece15 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece14 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece13 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece12 = (gcnew System::Windows::Forms::PictureBox());
			this->p2piece11 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece9 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece10 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece11 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece12 = (gcnew System::Windows::Forms::PictureBox());
			this->p1piece13 = (gcnew System::Windows::Forms::PictureBox());
			this->p1pawnSet = (gcnew System::Windows::Forms::PictureBox());
			this->p1queenSet = (gcnew System::Windows::Forms::PictureBox());
			this->p1bishopSet = (gcnew System::Windows::Forms::PictureBox());
			this->p1horseSet = (gcnew System::Windows::Forms::PictureBox());
			this->p1rookSet = (gcnew System::Windows::Forms::PictureBox());
			this->p1kingSet = (gcnew System::Windows::Forms::PictureBox());
			this->p2kingSet = (gcnew System::Windows::Forms::PictureBox());
			this->p2pawnSet = (gcnew System::Windows::Forms::PictureBox());
			this->p2rookSet = (gcnew System::Windows::Forms::PictureBox());
			this->p2horseSet = (gcnew System::Windows::Forms::PictureBox());
			this->p2bishopSet = (gcnew System::Windows::Forms::PictureBox());
			this->p2queenSet = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pawnUpgradeWindow = (gcnew System::Windows::Forms::Panel());
			this->pawnUpgradeBackgroundPanel = (gcnew System::Windows::Forms::Panel());
			this->horseUpgrade = (gcnew System::Windows::Forms::Button());
			this->queenUpgrade = (gcnew System::Windows::Forms::Button());
			this->rookUpgrade = (gcnew System::Windows::Forms::Button());
			this->bishopUpgrade = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->p1TurnPanel = (gcnew System::Windows::Forms::Panel());
			this->player1NameTag = (gcnew System::Windows::Forms::Label());
			this->p2TurnPanel = (gcnew System::Windows::Forms::Panel());
			this->player2NameTag = (gcnew System::Windows::Forms::Label());
			this->settingNamePanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->player2NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->player1NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->settingNamePanelTitle = (gcnew System::Windows::Forms::Label());
			this->gameEndedPanel = (gcnew System::Windows::Forms::Panel());
			this->hideWinningMenu = (gcnew System::Windows::Forms::Button());
			this->endGameButton = (gcnew System::Windows::Forms::Button());
			this->winnerText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1pawnSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1queenSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1bishopSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1horseSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1rookSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1kingSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2kingSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2pawnSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2rookSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2horseSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2bishopSet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2queenSet))->BeginInit();
			this->pawnUpgradeWindow->SuspendLayout();
			this->pawnUpgradeBackgroundPanel->SuspendLayout();
			this->p1TurnPanel->SuspendLayout();
			this->p2TurnPanel->SuspendLayout();
			this->settingNamePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->gameEndedPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// p1piece1
			// 
			this->p1piece1->AccessibleName = L"p1pawn";
			this->p1piece1->BackColor = System::Drawing::Color::Bisque;
			this->p1piece1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece1->Location = System::Drawing::Point(130, 894);
			this->p1piece1->Name = L"p1piece1";
			this->p1piece1->Size = System::Drawing::Size(96, 95);
			this->p1piece1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece1->TabIndex = 0;
			this->p1piece1->TabStop = false;
			this->p1piece1->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece10
			// 
			this->p2piece10->AccessibleName = L"p2horse";
			this->p2piece10->BackColor = System::Drawing::Color::Bisque;
			this->p2piece10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece10->Location = System::Drawing::Point(253, 145);
			this->p2piece10->Name = L"p2piece10";
			this->p2piece10->Size = System::Drawing::Size(96, 95);
			this->p2piece10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece10->TabIndex = 1;
			this->p2piece10->TabStop = false;
			this->p2piece10->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece8
			// 
			this->p1piece8->AccessibleName = L"p1pawn";
			this->p1piece8->BackColor = System::Drawing::Color::Bisque;
			this->p1piece8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece8->Location = System::Drawing::Point(980, 894);
			this->p1piece8->Name = L"p1piece8";
			this->p1piece8->Size = System::Drawing::Size(96, 95);
			this->p1piece8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece8->TabIndex = 2;
			this->p1piece8->TabStop = false;
			this->p1piece8->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece7
			// 
			this->p1piece7->AccessibleName = L"p1pawn";
			this->p1piece7->BackColor = System::Drawing::Color::Bisque;
			this->p1piece7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece7->Location = System::Drawing::Point(859, 894);
			this->p1piece7->Name = L"p1piece7";
			this->p1piece7->Size = System::Drawing::Size(96, 95);
			this->p1piece7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece7->TabIndex = 3;
			this->p1piece7->TabStop = false;
			this->p1piece7->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece6
			// 
			this->p1piece6->AccessibleName = L"p1pawn";
			this->p1piece6->BackColor = System::Drawing::Color::Bisque;
			this->p1piece6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece6->Location = System::Drawing::Point(739, 894);
			this->p1piece6->Name = L"p1piece6";
			this->p1piece6->Size = System::Drawing::Size(96, 95);
			this->p1piece6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece6->TabIndex = 4;
			this->p1piece6->TabStop = false;
			this->p1piece6->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece5
			// 
			this->p1piece5->AccessibleName = L"p1pawn";
			this->p1piece5->BackColor = System::Drawing::Color::Bisque;
			this->p1piece5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece5->Location = System::Drawing::Point(617, 894);
			this->p1piece5->Name = L"p1piece5";
			this->p1piece5->Size = System::Drawing::Size(96, 95);
			this->p1piece5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece5->TabIndex = 5;
			this->p1piece5->TabStop = false;
			this->p1piece5->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece4
			// 
			this->p1piece4->AccessibleName = L"p1pawn";
			this->p1piece4->BackColor = System::Drawing::Color::Bisque;
			this->p1piece4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece4->Location = System::Drawing::Point(498, 894);
			this->p1piece4->Name = L"p1piece4";
			this->p1piece4->Size = System::Drawing::Size(96, 95);
			this->p1piece4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece4->TabIndex = 6;
			this->p1piece4->TabStop = false;
			this->p1piece4->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece3
			// 
			this->p1piece3->AccessibleName = L"p1pawn";
			this->p1piece3->BackColor = System::Drawing::Color::Bisque;
			this->p1piece3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece3->Location = System::Drawing::Point(371, 894);
			this->p1piece3->Name = L"p1piece3";
			this->p1piece3->Size = System::Drawing::Size(96, 95);
			this->p1piece3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece3->TabIndex = 7;
			this->p1piece3->TabStop = false;
			this->p1piece3->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece2
			// 
			this->p1piece2->AccessibleName = L"p1pawn";
			this->p1piece2->BackColor = System::Drawing::Color::Bisque;
			this->p1piece2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece2->Location = System::Drawing::Point(253, 894);
			this->p1piece2->Name = L"p1piece2";
			this->p1piece2->Size = System::Drawing::Size(96, 95);
			this->p1piece2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece2->TabIndex = 8;
			this->p1piece2->TabStop = false;
			this->p1piece2->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece9
			// 
			this->p2piece9->AccessibleName = L"p2rook";
			this->p2piece9->BackColor = System::Drawing::Color::Bisque;
			this->p2piece9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece9->Location = System::Drawing::Point(130, 145);
			this->p2piece9->Name = L"p2piece9";
			this->p2piece9->Size = System::Drawing::Size(96, 95);
			this->p2piece9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece9->TabIndex = 9;
			this->p2piece9->TabStop = false;
			this->p2piece9->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece8
			// 
			this->p2piece8->AccessibleName = L"p2pawn";
			this->p2piece8->BackColor = System::Drawing::Color::Bisque;
			this->p2piece8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece8->Location = System::Drawing::Point(980, 273);
			this->p2piece8->Name = L"p2piece8";
			this->p2piece8->Size = System::Drawing::Size(96, 95);
			this->p2piece8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece8->TabIndex = 10;
			this->p2piece8->TabStop = false;
			this->p2piece8->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece7
			// 
			this->p2piece7->AccessibleName = L"p2pawn";
			this->p2piece7->BackColor = System::Drawing::Color::Bisque;
			this->p2piece7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece7->Location = System::Drawing::Point(859, 273);
			this->p2piece7->Name = L"p2piece7";
			this->p2piece7->Size = System::Drawing::Size(96, 95);
			this->p2piece7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece7->TabIndex = 11;
			this->p2piece7->TabStop = false;
			this->p2piece7->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece6
			// 
			this->p2piece6->AccessibleName = L"p2pawn";
			this->p2piece6->BackColor = System::Drawing::Color::Bisque;
			this->p2piece6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece6->Location = System::Drawing::Point(739, 273);
			this->p2piece6->Name = L"p2piece6";
			this->p2piece6->Size = System::Drawing::Size(96, 95);
			this->p2piece6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece6->TabIndex = 12;
			this->p2piece6->TabStop = false;
			this->p2piece6->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece5
			// 
			this->p2piece5->AccessibleName = L"p2pawn";
			this->p2piece5->BackColor = System::Drawing::Color::Bisque;
			this->p2piece5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece5->Location = System::Drawing::Point(617, 273);
			this->p2piece5->Name = L"p2piece5";
			this->p2piece5->Size = System::Drawing::Size(96, 95);
			this->p2piece5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece5->TabIndex = 13;
			this->p2piece5->TabStop = false;
			this->p2piece5->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece4
			// 
			this->p2piece4->AccessibleName = L"p2pawn";
			this->p2piece4->BackColor = System::Drawing::Color::Bisque;
			this->p2piece4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece4->Location = System::Drawing::Point(498, 273);
			this->p2piece4->Name = L"p2piece4";
			this->p2piece4->Size = System::Drawing::Size(96, 95);
			this->p2piece4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece4->TabIndex = 14;
			this->p2piece4->TabStop = false;
			this->p2piece4->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece3
			// 
			this->p2piece3->AccessibleName = L"p2pawn";
			this->p2piece3->BackColor = System::Drawing::Color::Bisque;
			this->p2piece3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece3->Location = System::Drawing::Point(371, 264);
			this->p2piece3->Name = L"p2piece3";
			this->p2piece3->Size = System::Drawing::Size(96, 95);
			this->p2piece3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece3->TabIndex = 15;
			this->p2piece3->TabStop = false;
			this->p2piece3->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece2
			// 
			this->p2piece2->AccessibleName = L"p2pawn";
			this->p2piece2->BackColor = System::Drawing::Color::Bisque;
			this->p2piece2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece2->Location = System::Drawing::Point(253, 264);
			this->p2piece2->Name = L"p2piece2";
			this->p2piece2->Size = System::Drawing::Size(96, 95);
			this->p2piece2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece2->TabIndex = 16;
			this->p2piece2->TabStop = false;
			this->p2piece2->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece1
			// 
			this->p2piece1->AccessibleName = L"p2pawn";
			this->p2piece1->BackColor = System::Drawing::Color::Bisque;
			this->p2piece1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece1->Location = System::Drawing::Point(130, 273);
			this->p2piece1->Name = L"p2piece1";
			this->p2piece1->Size = System::Drawing::Size(96, 95);
			this->p2piece1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece1->TabIndex = 17;
			this->p2piece1->TabStop = false;
			this->p2piece1->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece14
			// 
			this->p1piece14->AccessibleName = L"p1bishop";
			this->p1piece14->BackColor = System::Drawing::Color::Bisque;
			this->p1piece14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece14->Location = System::Drawing::Point(739, 1022);
			this->p1piece14->Name = L"p1piece14";
			this->p1piece14->Size = System::Drawing::Size(96, 95);
			this->p1piece14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece14->TabIndex = 18;
			this->p1piece14->TabStop = false;
			this->p1piece14->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece15
			// 
			this->p1piece15->AccessibleName = L"p1horse";
			this->p1piece15->BackColor = System::Drawing::Color::Bisque;
			this->p1piece15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece15->Location = System::Drawing::Point(859, 1022);
			this->p1piece15->Name = L"p1piece15";
			this->p1piece15->Size = System::Drawing::Size(96, 95);
			this->p1piece15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece15->TabIndex = 19;
			this->p1piece15->TabStop = false;
			this->p1piece15->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece16
			// 
			this->p1piece16->AccessibleName = L"p1rook";
			this->p1piece16->BackColor = System::Drawing::Color::Bisque;
			this->p1piece16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece16->Location = System::Drawing::Point(980, 1022);
			this->p1piece16->Name = L"p1piece16";
			this->p1piece16->Size = System::Drawing::Size(96, 95);
			this->p1piece16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece16->TabIndex = 20;
			this->p1piece16->TabStop = false;
			this->p1piece16->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece16
			// 
			this->p2piece16->AccessibleName = L"p2rook";
			this->p2piece16->BackColor = System::Drawing::Color::Bisque;
			this->p2piece16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece16->Location = System::Drawing::Point(980, 145);
			this->p2piece16->Name = L"p2piece16";
			this->p2piece16->Size = System::Drawing::Size(96, 95);
			this->p2piece16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece16->TabIndex = 21;
			this->p2piece16->TabStop = false;
			this->p2piece16->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece15
			// 
			this->p2piece15->AccessibleName = L"p2horse";
			this->p2piece15->BackColor = System::Drawing::Color::Bisque;
			this->p2piece15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece15->Location = System::Drawing::Point(859, 145);
			this->p2piece15->Name = L"p2piece15";
			this->p2piece15->Size = System::Drawing::Size(96, 95);
			this->p2piece15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece15->TabIndex = 22;
			this->p2piece15->TabStop = false;
			this->p2piece15->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece14
			// 
			this->p2piece14->AccessibleName = L"p2bishop";
			this->p2piece14->BackColor = System::Drawing::Color::Bisque;
			this->p2piece14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece14->Location = System::Drawing::Point(739, 145);
			this->p2piece14->Name = L"p2piece14";
			this->p2piece14->Size = System::Drawing::Size(96, 95);
			this->p2piece14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece14->TabIndex = 23;
			this->p2piece14->TabStop = false;
			this->p2piece14->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece13
			// 
			this->p2piece13->AccessibleName = L"p2king";
			this->p2piece13->BackColor = System::Drawing::Color::Bisque;
			this->p2piece13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece13->Location = System::Drawing::Point(617, 145);
			this->p2piece13->Name = L"p2piece13";
			this->p2piece13->Size = System::Drawing::Size(96, 95);
			this->p2piece13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece13->TabIndex = 24;
			this->p2piece13->TabStop = false;
			this->p2piece13->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece12
			// 
			this->p2piece12->AccessibleName = L"p2queen";
			this->p2piece12->BackColor = System::Drawing::Color::Bisque;
			this->p2piece12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece12->Location = System::Drawing::Point(498, 145);
			this->p2piece12->Name = L"p2piece12";
			this->p2piece12->Size = System::Drawing::Size(96, 95);
			this->p2piece12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece12->TabIndex = 25;
			this->p2piece12->TabStop = false;
			this->p2piece12->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p2piece11
			// 
			this->p2piece11->AccessibleName = L"p2bishop";
			this->p2piece11->BackColor = System::Drawing::Color::Bisque;
			this->p2piece11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2piece11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2piece11->Location = System::Drawing::Point(371, 145);
			this->p2piece11->Name = L"p2piece11";
			this->p2piece11->Size = System::Drawing::Size(96, 95);
			this->p2piece11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2piece11->TabIndex = 26;
			this->p2piece11->TabStop = false;
			this->p2piece11->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece9
			// 
			this->p1piece9->AccessibleName = L"p1rook";
			this->p1piece9->BackColor = System::Drawing::Color::Bisque;
			this->p1piece9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece9->Location = System::Drawing::Point(130, 1022);
			this->p1piece9->Name = L"p1piece9";
			this->p1piece9->Size = System::Drawing::Size(96, 95);
			this->p1piece9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece9->TabIndex = 27;
			this->p1piece9->TabStop = false;
			this->p1piece9->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece10
			// 
			this->p1piece10->AccessibleName = L"p1horse";
			this->p1piece10->BackColor = System::Drawing::Color::Bisque;
			this->p1piece10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece10->Location = System::Drawing::Point(253, 1022);
			this->p1piece10->Name = L"p1piece10";
			this->p1piece10->Size = System::Drawing::Size(96, 95);
			this->p1piece10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece10->TabIndex = 28;
			this->p1piece10->TabStop = false;
			this->p1piece10->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece11
			// 
			this->p1piece11->AccessibleName = L"p1bishop";
			this->p1piece11->BackColor = System::Drawing::Color::Bisque;
			this->p1piece11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece11->Location = System::Drawing::Point(381, 1022);
			this->p1piece11->Name = L"p1piece11";
			this->p1piece11->Size = System::Drawing::Size(96, 95);
			this->p1piece11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece11->TabIndex = 29;
			this->p1piece11->TabStop = false;
			this->p1piece11->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece12
			// 
			this->p1piece12->AccessibleName = L"p1queen";
			this->p1piece12->BackColor = System::Drawing::Color::Bisque;
			this->p1piece12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece12->Location = System::Drawing::Point(498, 1022);
			this->p1piece12->Name = L"p1piece12";
			this->p1piece12->Size = System::Drawing::Size(96, 95);
			this->p1piece12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece12->TabIndex = 30;
			this->p1piece12->TabStop = false;
			this->p1piece12->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1piece13
			// 
			this->p1piece13->AccessibleName = L"p1king";
			this->p1piece13->BackColor = System::Drawing::Color::Bisque;
			this->p1piece13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1piece13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1piece13->Location = System::Drawing::Point(617, 1022);
			this->p1piece13->Name = L"p1piece13";
			this->p1piece13->Size = System::Drawing::Size(96, 95);
			this->p1piece13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1piece13->TabIndex = 31;
			this->p1piece13->TabStop = false;
			this->p1piece13->Click += gcnew System::EventHandler(this, &MyForm::pieceClicked);
			// 
			// p1pawnSet
			// 
			this->p1pawnSet->AccessibleName = L"p1pawn";
			this->p1pawnSet->BackColor = System::Drawing::Color::Transparent;
			this->p1pawnSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1pawnSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p1pawnSet.Image")));
			this->p1pawnSet->Location = System::Drawing::Point(22, 1151);
			this->p1pawnSet->Name = L"p1pawnSet";
			this->p1pawnSet->Size = System::Drawing::Size(96, 95);
			this->p1pawnSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1pawnSet->TabIndex = 32;
			this->p1pawnSet->TabStop = false;
			// 
			// p1queenSet
			// 
			this->p1queenSet->AccessibleName = L"p1queen";
			this->p1queenSet->BackColor = System::Drawing::Color::Transparent;
			this->p1queenSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1queenSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p1queenSet.Image")));
			this->p1queenSet->Location = System::Drawing::Point(360, 1151);
			this->p1queenSet->Name = L"p1queenSet";
			this->p1queenSet->Size = System::Drawing::Size(96, 95);
			this->p1queenSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1queenSet->TabIndex = 33;
			this->p1queenSet->TabStop = false;
			// 
			// p1bishopSet
			// 
			this->p1bishopSet->AccessibleName = L"p1bishop";
			this->p1bishopSet->BackColor = System::Drawing::Color::Transparent;
			this->p1bishopSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1bishopSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p1bishopSet.Image")));
			this->p1bishopSet->Location = System::Drawing::Point(278, 1151);
			this->p1bishopSet->Name = L"p1bishopSet";
			this->p1bishopSet->Size = System::Drawing::Size(96, 95);
			this->p1bishopSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1bishopSet->TabIndex = 34;
			this->p1bishopSet->TabStop = false;
			// 
			// p1horseSet
			// 
			this->p1horseSet->AccessibleName = L"p1horse";
			this->p1horseSet->BackColor = System::Drawing::Color::Transparent;
			this->p1horseSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1horseSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p1horseSet.Image")));
			this->p1horseSet->Location = System::Drawing::Point(198, 1151);
			this->p1horseSet->Name = L"p1horseSet";
			this->p1horseSet->Size = System::Drawing::Size(96, 95);
			this->p1horseSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1horseSet->TabIndex = 35;
			this->p1horseSet->TabStop = false;
			// 
			// p1rookSet
			// 
			this->p1rookSet->AccessibleName = L"p1rook";
			this->p1rookSet->BackColor = System::Drawing::Color::Transparent;
			this->p1rookSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1rookSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p1rookSet.Image")));
			this->p1rookSet->Location = System::Drawing::Point(108, 1163);
			this->p1rookSet->Name = L"p1rookSet";
			this->p1rookSet->Size = System::Drawing::Size(96, 95);
			this->p1rookSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1rookSet->TabIndex = 36;
			this->p1rookSet->TabStop = false;
			// 
			// p1kingSet
			// 
			this->p1kingSet->AccessibleName = L"p1king";
			this->p1kingSet->BackColor = System::Drawing::Color::Transparent;
			this->p1kingSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p1kingSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p1kingSet.Image")));
			this->p1kingSet->Location = System::Drawing::Point(442, 1151);
			this->p1kingSet->Name = L"p1kingSet";
			this->p1kingSet->Size = System::Drawing::Size(96, 95);
			this->p1kingSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p1kingSet->TabIndex = 37;
			this->p1kingSet->TabStop = false;
			// 
			// p2kingSet
			// 
			this->p2kingSet->AccessibleName = L"p2king";
			this->p2kingSet->BackColor = System::Drawing::Color::Transparent;
			this->p2kingSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2kingSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p2kingSet.Image")));
			this->p2kingSet->Location = System::Drawing::Point(1088, 1151);
			this->p2kingSet->Name = L"p2kingSet";
			this->p2kingSet->Size = System::Drawing::Size(96, 95);
			this->p2kingSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2kingSet->TabIndex = 38;
			this->p2kingSet->TabStop = false;
			// 
			// p2pawnSet
			// 
			this->p2pawnSet->AccessibleName = L"p2pawn";
			this->p2pawnSet->BackColor = System::Drawing::Color::Transparent;
			this->p2pawnSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2pawnSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p2pawnSet.Image")));
			this->p2pawnSet->Location = System::Drawing::Point(664, 1151);
			this->p2pawnSet->Name = L"p2pawnSet";
			this->p2pawnSet->Size = System::Drawing::Size(96, 95);
			this->p2pawnSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2pawnSet->TabIndex = 39;
			this->p2pawnSet->TabStop = false;
			// 
			// p2rookSet
			// 
			this->p2rookSet->AccessibleName = L"p2rook";
			this->p2rookSet->BackColor = System::Drawing::Color::Transparent;
			this->p2rookSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2rookSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p2rookSet.Image")));
			this->p2rookSet->Location = System::Drawing::Point(739, 1151);
			this->p2rookSet->Name = L"p2rookSet";
			this->p2rookSet->Size = System::Drawing::Size(96, 95);
			this->p2rookSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2rookSet->TabIndex = 40;
			this->p2rookSet->TabStop = false;
			// 
			// p2horseSet
			// 
			this->p2horseSet->AccessibleName = L"p2horse";
			this->p2horseSet->BackColor = System::Drawing::Color::Transparent;
			this->p2horseSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2horseSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p2horseSet.Image")));
			this->p2horseSet->Location = System::Drawing::Point(822, 1151);
			this->p2horseSet->Name = L"p2horseSet";
			this->p2horseSet->Size = System::Drawing::Size(96, 95);
			this->p2horseSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2horseSet->TabIndex = 41;
			this->p2horseSet->TabStop = false;
			// 
			// p2bishopSet
			// 
			this->p2bishopSet->AccessibleName = L"p2bishop";
			this->p2bishopSet->BackColor = System::Drawing::Color::Transparent;
			this->p2bishopSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->p2bishopSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p2bishopSet.Image")));
			this->p2bishopSet->Location = System::Drawing::Point(924, 1151);
			this->p2bishopSet->Name = L"p2bishopSet";
			this->p2bishopSet->Size = System::Drawing::Size(96, 95);
			this->p2bishopSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2bishopSet->TabIndex = 42;
			this->p2bishopSet->TabStop = false;
			// 
			// p2queenSet
			// 
			this->p2queenSet->AccessibleName = L"p2queen";
			this->p2queenSet->BackColor = System::Drawing::Color::Transparent;
			this->p2queenSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->p2queenSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p2queenSet.Image")));
			this->p2queenSet->Location = System::Drawing::Point(1000, 1151);
			this->p2queenSet->Name = L"p2queenSet";
			this->p2queenSet->Size = System::Drawing::Size(96, 95);
			this->p2queenSet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->p2queenSet->TabIndex = 43;
			this->p2queenSet->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::IndianRed;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(1038, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 46);
			this->button1->TabIndex = 44;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			// 
			// pawnUpgradeWindow
			// 
			this->pawnUpgradeWindow->AccessibleName = L"p2pawn";
			this->pawnUpgradeWindow->BackColor = System::Drawing::Color::Tan;
			this->pawnUpgradeWindow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pawnUpgradeWindow->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pawnUpgradeWindow->Controls->Add(this->pawnUpgradeBackgroundPanel);
			this->pawnUpgradeWindow->Controls->Add(this->label1);
			this->pawnUpgradeWindow->Location = System::Drawing::Point(408, 345);
			this->pawnUpgradeWindow->Name = L"pawnUpgradeWindow";
			this->pawnUpgradeWindow->Size = System::Drawing::Size(405, 393);
			this->pawnUpgradeWindow->TabIndex = 45;
			this->pawnUpgradeWindow->Visible = false;
			// 
			// pawnUpgradeBackgroundPanel
			// 
			this->pawnUpgradeBackgroundPanel->BackColor = System::Drawing::Color::Wheat;
			this->pawnUpgradeBackgroundPanel->Controls->Add(this->horseUpgrade);
			this->pawnUpgradeBackgroundPanel->Controls->Add(this->queenUpgrade);
			this->pawnUpgradeBackgroundPanel->Controls->Add(this->rookUpgrade);
			this->pawnUpgradeBackgroundPanel->Controls->Add(this->bishopUpgrade);
			this->pawnUpgradeBackgroundPanel->Location = System::Drawing::Point(44, 87);
			this->pawnUpgradeBackgroundPanel->Name = L"pawnUpgradeBackgroundPanel";
			this->pawnUpgradeBackgroundPanel->Size = System::Drawing::Size(306, 269);
			this->pawnUpgradeBackgroundPanel->TabIndex = 5;
			// 
			// horseUpgrade
			// 
			this->horseUpgrade->AccessibleName = L"horse";
			this->horseUpgrade->BackColor = System::Drawing::Color::LightSalmon;
			this->horseUpgrade->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->horseUpgrade->Cursor = System::Windows::Forms::Cursors::Hand;
			this->horseUpgrade->Location = System::Drawing::Point(152, 21);
			this->horseUpgrade->Name = L"horseUpgrade";
			this->horseUpgrade->Size = System::Drawing::Size(137, 118);
			this->horseUpgrade->TabIndex = 2;
			this->horseUpgrade->UseVisualStyleBackColor = false;
			this->horseUpgrade->Click += gcnew System::EventHandler(this, &MyForm::pawnUpgradeChoice);
			// 
			// queenUpgrade
			// 
			this->queenUpgrade->AccessibleName = L"queen";
			this->queenUpgrade->BackColor = System::Drawing::Color::LightSalmon;
			this->queenUpgrade->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->queenUpgrade->Cursor = System::Windows::Forms::Cursors::Hand;
			this->queenUpgrade->Location = System::Drawing::Point(152, 136);
			this->queenUpgrade->Name = L"queenUpgrade";
			this->queenUpgrade->Size = System::Drawing::Size(137, 118);
			this->queenUpgrade->TabIndex = 3;
			this->queenUpgrade->UseVisualStyleBackColor = false;
			this->queenUpgrade->Click += gcnew System::EventHandler(this, &MyForm::pawnUpgradeChoice);
			// 
			// rookUpgrade
			// 
			this->rookUpgrade->AccessibleName = L"rook";
			this->rookUpgrade->BackColor = System::Drawing::Color::LightSalmon;
			this->rookUpgrade->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->rookUpgrade->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rookUpgrade->Location = System::Drawing::Point(19, 21);
			this->rookUpgrade->Name = L"rookUpgrade";
			this->rookUpgrade->Size = System::Drawing::Size(137, 118);
			this->rookUpgrade->TabIndex = 0;
			this->rookUpgrade->UseVisualStyleBackColor = false;
			this->rookUpgrade->Click += gcnew System::EventHandler(this, &MyForm::pawnUpgradeChoice);
			// 
			// bishopUpgrade
			// 
			this->bishopUpgrade->AccessibleName = L"bishop";
			this->bishopUpgrade->BackColor = System::Drawing::Color::LightSalmon;
			this->bishopUpgrade->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bishopUpgrade->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bishopUpgrade->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->bishopUpgrade->Location = System::Drawing::Point(19, 136);
			this->bishopUpgrade->Name = L"bishopUpgrade";
			this->bishopUpgrade->Size = System::Drawing::Size(137, 118);
			this->bishopUpgrade->TabIndex = 1;
			this->bishopUpgrade->UseVisualStyleBackColor = false;
			this->bishopUpgrade->Click += gcnew System::EventHandler(this, &MyForm::pawnUpgradeChoice);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(44, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(306, 45);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Choose Upgrade";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel1->Location = System::Drawing::Point(12, 145);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(36, 39);
			this->panel1->TabIndex = 46;
			this->panel1->Visible = false;
			this->panel1->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel2->Location = System::Drawing::Point(12, 190);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(36, 39);
			this->panel2->TabIndex = 50;
			this->panel2->Visible = false;
			this->panel2->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel3->Location = System::Drawing::Point(12, 235);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(36, 39);
			this->panel3->TabIndex = 51;
			this->panel3->Visible = false;
			this->panel3->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel4->Location = System::Drawing::Point(12, 280);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(36, 39);
			this->panel4->TabIndex = 47;
			this->panel4->Visible = false;
			this->panel4->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel5->Location = System::Drawing::Point(12, 325);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(36, 39);
			this->panel5->TabIndex = 47;
			this->panel5->Visible = false;
			this->panel5->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel6->Location = System::Drawing::Point(12, 370);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(36, 39);
			this->panel6->TabIndex = 47;
			this->panel6->Visible = false;
			this->panel6->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel7->Location = System::Drawing::Point(12, 415);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(36, 39);
			this->panel7->TabIndex = 47;
			this->panel7->Visible = false;
			this->panel7->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel8->Location = System::Drawing::Point(12, 460);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(36, 39);
			this->panel8->TabIndex = 47;
			this->panel8->Visible = false;
			this->panel8->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel9->Location = System::Drawing::Point(12, 505);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(36, 39);
			this->panel9->TabIndex = 47;
			this->panel9->Visible = false;
			this->panel9->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel10->Location = System::Drawing::Point(54, 120);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(36, 39);
			this->panel10->TabIndex = 47;
			this->panel10->Visible = false;
			this->panel10->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel11->Location = System::Drawing::Point(54, 555);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(36, 39);
			this->panel11->TabIndex = 47;
			this->panel11->Visible = false;
			this->panel11->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel12->Location = System::Drawing::Point(12, 570);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(36, 39);
			this->panel12->TabIndex = 47;
			this->panel12->Visible = false;
			this->panel12->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel13->Location = System::Drawing::Point(12, 615);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(36, 39);
			this->panel13->TabIndex = 47;
			this->panel13->Visible = false;
			this->panel13->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel14->Location = System::Drawing::Point(12, 685);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(36, 39);
			this->panel14->TabIndex = 47;
			this->panel14->Visible = false;
			this->panel14->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel15
			// 
			this->panel15->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel15->Location = System::Drawing::Point(12, 730);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(36, 39);
			this->panel15->TabIndex = 47;
			this->panel15->Visible = false;
			this->panel15->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel16
			// 
			this->panel16->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel16->Location = System::Drawing::Point(12, 775);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(36, 39);
			this->panel16->TabIndex = 47;
			this->panel16->Visible = false;
			this->panel16->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel17
			// 
			this->panel17->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel17->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel17->Location = System::Drawing::Point(12, 820);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(36, 39);
			this->panel17->TabIndex = 47;
			this->panel17->Visible = false;
			this->panel17->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel18->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel18->Location = System::Drawing::Point(12, 865);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(36, 39);
			this->panel18->TabIndex = 47;
			this->panel18->Visible = false;
			this->panel18->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel19
			// 
			this->panel19->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel19->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel19->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel19->Location = System::Drawing::Point(12, 910);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(36, 39);
			this->panel19->TabIndex = 47;
			this->panel19->Visible = false;
			this->panel19->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel20
			// 
			this->panel20->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel20->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel20->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel20->Location = System::Drawing::Point(12, 955);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(36, 39);
			this->panel20->TabIndex = 47;
			this->panel20->Visible = false;
			this->panel20->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel21
			// 
			this->panel21->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel21->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel21->Location = System::Drawing::Point(12, 1000);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(36, 39);
			this->panel21->TabIndex = 47;
			this->panel21->Visible = false;
			this->panel21->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel22->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel22->Location = System::Drawing::Point(12, 1045);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(36, 39);
			this->panel22->TabIndex = 52;
			this->panel22->Visible = false;
			this->panel22->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel23->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel23->Location = System::Drawing::Point(63, 796);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(36, 39);
			this->panel23->TabIndex = 47;
			this->panel23->Visible = false;
			this->panel23->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel24->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel24->Location = System::Drawing::Point(12, 1090);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(36, 39);
			this->panel24->TabIndex = 47;
			this->panel24->Visible = false;
			this->panel24->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel25->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel25->Location = System::Drawing::Point(54, 1106);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(36, 39);
			this->panel25->TabIndex = 47;
			this->panel25->Visible = false;
			this->panel25->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel26
			// 
			this->panel26->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel26->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel26->Location = System::Drawing::Point(63, 1045);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(36, 39);
			this->panel26->TabIndex = 47;
			this->panel26->Visible = false;
			this->panel26->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel27
			// 
			this->panel27->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel27->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel27->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel27->Location = System::Drawing::Point(63, 977);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(36, 39);
			this->panel27->TabIndex = 47;
			this->panel27->Visible = false;
			this->panel27->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel28
			// 
			this->panel28->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel28->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel28->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel28->Location = System::Drawing::Point(54, 865);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(36, 39);
			this->panel28->TabIndex = 47;
			this->panel28->Visible = false;
			this->panel28->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel29
			// 
			this->panel29->BackColor = System::Drawing::Color::Red;
			this->panel29->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel29->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel29->Location = System::Drawing::Point(54, 730);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(36, 39);
			this->panel29->TabIndex = 47;
			this->panel29->Visible = false;
			this->panel29->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// panel30
			// 
			this->panel30->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel30->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel30->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel30->Location = System::Drawing::Point(130, 764);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(96, 95);
			this->panel30->TabIndex = 47;
			this->panel30->Visible = false;
			this->panel30->Click += gcnew System::EventHandler(this, &MyForm::optionClicked);
			// 
			// p1TurnPanel
			// 
			this->p1TurnPanel->BackColor = System::Drawing::Color::Green;
			this->p1TurnPanel->Controls->Add(this->player1NameTag);
			this->p1TurnPanel->Location = System::Drawing::Point(1141, 535);
			this->p1TurnPanel->Name = L"p1TurnPanel";
			this->p1TurnPanel->Size = System::Drawing::Size(69, 430);
			this->p1TurnPanel->TabIndex = 54;
			// 
			// player1NameTag
			// 
			this->player1NameTag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player1NameTag->ForeColor = System::Drawing::Color::White;
			this->player1NameTag->Location = System::Drawing::Point(20, 0);
			this->player1NameTag->Name = L"player1NameTag";
			this->player1NameTag->Size = System::Drawing::Size(29, 430);
			this->player1NameTag->TabIndex = 0;
			this->player1NameTag->Text = L"Emanuel";
			this->player1NameTag->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// p2TurnPanel
			// 
			this->p2TurnPanel->BackColor = System::Drawing::Color::Green;
			this->p2TurnPanel->Controls->Add(this->player2NameTag);
			this->p2TurnPanel->Location = System::Drawing::Point(1141, 99);
			this->p2TurnPanel->Name = L"p2TurnPanel";
			this->p2TurnPanel->Size = System::Drawing::Size(69, 430);
			this->p2TurnPanel->TabIndex = 55;
			// 
			// player2NameTag
			// 
			this->player2NameTag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player2NameTag->ForeColor = System::Drawing::Color::White;
			this->player2NameTag->Location = System::Drawing::Point(20, 0);
			this->player2NameTag->Name = L"player2NameTag";
			this->player2NameTag->Size = System::Drawing::Size(29, 430);
			this->player2NameTag->TabIndex = 1;
			this->player2NameTag->Text = L"Emanuel";
			this->player2NameTag->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// settingNamePanel
			// 
			this->settingNamePanel->BackColor = System::Drawing::Color::Transparent;
			this->settingNamePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingNamePanel.BackgroundImage")));
			this->settingNamePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->settingNamePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->settingNamePanel->Controls->Add(this->pictureBox1);
			this->settingNamePanel->Controls->Add(this->pictureBox2);
			this->settingNamePanel->Controls->Add(this->startButton);
			this->settingNamePanel->Controls->Add(this->player2NameTextBox);
			this->settingNamePanel->Controls->Add(this->player1NameTextBox);
			this->settingNamePanel->Controls->Add(this->settingNamePanelTitle);
			this->settingNamePanel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->settingNamePanel->Location = System::Drawing::Point(198, 374);
			this->settingNamePanel->Name = L"settingNamePanel";
			this->settingNamePanel->Size = System::Drawing::Size(822, 302);
			this->settingNamePanel->TabIndex = 56;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(25, 58);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(84, 84);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(25, 149);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(84, 84);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// startButton
			// 
			this->startButton->BackColor = System::Drawing::Color::Sienna;
			this->startButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->startButton->Location = System::Drawing::Point(261, 218);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(315, 71);
			this->startButton->TabIndex = 3;
			this->startButton->Text = L"START";
			this->startButton->UseVisualStyleBackColor = false;
			this->startButton->Click += gcnew System::EventHandler(this, &MyForm::startButton_Click);
			// 
			// player2NameTextBox
			// 
			this->player2NameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player2NameTextBox->Location = System::Drawing::Point(130, 159);
			this->player2NameTextBox->Name = L"player2NameTextBox";
			this->player2NameTextBox->Size = System::Drawing::Size(588, 50);
			this->player2NameTextBox->TabIndex = 2;
			this->player2NameTextBox->Text = L"Player 2";
			this->player2NameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// player1NameTextBox
			// 
			this->player1NameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player1NameTextBox->Location = System::Drawing::Point(129, 77);
			this->player1NameTextBox->Name = L"player1NameTextBox";
			this->player1NameTextBox->Size = System::Drawing::Size(588, 50);
			this->player1NameTextBox->TabIndex = 1;
			this->player1NameTextBox->Text = L"Player 1";
			this->player1NameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// settingNamePanelTitle
			// 
			this->settingNamePanelTitle->BackColor = System::Drawing::Color::Transparent;
			this->settingNamePanelTitle->Font = (gcnew System::Drawing::Font(L"Rockwell Extra Bold", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->settingNamePanelTitle->ForeColor = System::Drawing::Color::White;
			this->settingNamePanelTitle->Location = System::Drawing::Point(0, 0);
			this->settingNamePanelTitle->Name = L"settingNamePanelTitle";
			this->settingNamePanelTitle->Size = System::Drawing::Size(820, 55);
			this->settingNamePanelTitle->TabIndex = 0;
			this->settingNamePanelTitle->Text = L"Welcome to Chess!";
			this->settingNamePanelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gameEndedPanel
			// 
			this->gameEndedPanel->BackColor = System::Drawing::Color::LightGray;
			this->gameEndedPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->gameEndedPanel->Controls->Add(this->hideWinningMenu);
			this->gameEndedPanel->Controls->Add(this->endGameButton);
			this->gameEndedPanel->Controls->Add(this->winnerText);
			this->gameEndedPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gameEndedPanel->Location = System::Drawing::Point(161, 362);
			this->gameEndedPanel->Name = L"gameEndedPanel";
			this->gameEndedPanel->Size = System::Drawing::Size(891, 211);
			this->gameEndedPanel->TabIndex = 57;
			// 
			// hideWinningMenu
			// 
			this->hideWinningMenu->BackColor = System::Drawing::Color::RosyBrown;
			this->hideWinningMenu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hideWinningMenu->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hideWinningMenu->Location = System::Drawing::Point(453, 78);
			this->hideWinningMenu->Name = L"hideWinningMenu";
			this->hideWinningMenu->Size = System::Drawing::Size(373, 102);
			this->hideWinningMenu->TabIndex = 2;
			this->hideWinningMenu->Text = L"Hide Window";
			this->hideWinningMenu->UseVisualStyleBackColor = false;
			this->hideWinningMenu->Click += gcnew System::EventHandler(this, &MyForm::hideWinningMenu_Click);
			// 
			// endGameButton
			// 
			this->endGameButton->BackColor = System::Drawing::Color::RosyBrown;
			this->endGameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endGameButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->endGameButton->Location = System::Drawing::Point(64, 78);
			this->endGameButton->Name = L"endGameButton";
			this->endGameButton->Size = System::Drawing::Size(373, 102);
			this->endGameButton->TabIndex = 1;
			this->endGameButton->Text = L"Reset  Game";
			this->endGameButton->UseVisualStyleBackColor = false;
			this->endGameButton->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			// 
			// winnerText
			// 
			this->winnerText->BackColor = System::Drawing::Color::LightGray;
			this->winnerText->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 13.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->winnerText->ForeColor = System::Drawing::Color::Red;
			this->winnerText->Location = System::Drawing::Point(110, 0);
			this->winnerText->Name = L"winnerText";
			this->winnerText->Size = System::Drawing::Size(652, 69);
			this->winnerText->TabIndex = 0;
			this->winnerText->Text = L"Original Message (ERROR)";
			this->winnerText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AccessibleName = L"p2horse";
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1212, 1258);
			this->Controls->Add(this->gameEndedPanel);
			this->Controls->Add(this->settingNamePanel);
			this->Controls->Add(this->p2TurnPanel);
			this->Controls->Add(this->p1TurnPanel);
			this->Controls->Add(this->panel27);
			this->Controls->Add(this->panel23);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel30);
			this->Controls->Add(this->panel29);
			this->Controls->Add(this->panel28);
			this->Controls->Add(this->panel26);
			this->Controls->Add(this->panel25);
			this->Controls->Add(this->panel24);
			this->Controls->Add(this->panel22);
			this->Controls->Add(this->panel21);
			this->Controls->Add(this->panel20);
			this->Controls->Add(this->panel19);
			this->Controls->Add(this->panel18);
			this->Controls->Add(this->panel17);
			this->Controls->Add(this->panel16);
			this->Controls->Add(this->panel15);
			this->Controls->Add(this->panel14);
			this->Controls->Add(this->panel13);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->panel10);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pawnUpgradeWindow);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->p2queenSet);
			this->Controls->Add(this->p2bishopSet);
			this->Controls->Add(this->p2horseSet);
			this->Controls->Add(this->p2rookSet);
			this->Controls->Add(this->p2pawnSet);
			this->Controls->Add(this->p2kingSet);
			this->Controls->Add(this->p1kingSet);
			this->Controls->Add(this->p1rookSet);
			this->Controls->Add(this->p1horseSet);
			this->Controls->Add(this->p1bishopSet);
			this->Controls->Add(this->p1queenSet);
			this->Controls->Add(this->p1pawnSet);
			this->Controls->Add(this->p1piece13);
			this->Controls->Add(this->p1piece12);
			this->Controls->Add(this->p1piece11);
			this->Controls->Add(this->p1piece10);
			this->Controls->Add(this->p1piece9);
			this->Controls->Add(this->p2piece11);
			this->Controls->Add(this->p2piece12);
			this->Controls->Add(this->p2piece13);
			this->Controls->Add(this->p2piece14);
			this->Controls->Add(this->p2piece15);
			this->Controls->Add(this->p2piece16);
			this->Controls->Add(this->p1piece16);
			this->Controls->Add(this->p1piece15);
			this->Controls->Add(this->p1piece14);
			this->Controls->Add(this->p2piece1);
			this->Controls->Add(this->p2piece2);
			this->Controls->Add(this->p2piece3);
			this->Controls->Add(this->p2piece4);
			this->Controls->Add(this->p2piece5);
			this->Controls->Add(this->p2piece6);
			this->Controls->Add(this->p2piece7);
			this->Controls->Add(this->p2piece8);
			this->Controls->Add(this->p2piece9);
			this->Controls->Add(this->p1piece2);
			this->Controls->Add(this->p1piece3);
			this->Controls->Add(this->p1piece4);
			this->Controls->Add(this->p1piece5);
			this->Controls->Add(this->p1piece6);
			this->Controls->Add(this->p1piece7);
			this->Controls->Add(this->p1piece8);
			this->Controls->Add(this->p2piece10);
			this->Controls->Add(this->p1piece1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"El Chess";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2piece11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1piece13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1pawnSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1queenSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1bishopSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1horseSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1rookSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1kingSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2kingSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2pawnSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2rookSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2horseSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2bishopSet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2queenSet))->EndInit();
			this->pawnUpgradeWindow->ResumeLayout(false);
			this->pawnUpgradeBackgroundPanel->ResumeLayout(false);
			this->p1TurnPanel->ResumeLayout(false);
			this->p2TurnPanel->ResumeLayout(false);
			this->settingNamePanel->ResumeLayout(false);
			this->settingNamePanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->gameEndedPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	// ===========================.
	// Start of program code:      \
	// =================================================================================================================================
// 
	// Resets the board overall
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		// Setting locations of all pieces
		p1piece1->Location = Point(xValues[1], yValues[2]); p2piece1->Location = Point(xValues[1], yValues[7]);
		p1piece2->Location = Point(xValues[2], yValues[2]); p2piece2->Location = Point(xValues[2], yValues[7]);
		p1piece3->Location = Point(xValues[3], yValues[2]); p2piece3->Location = Point(xValues[3], yValues[7]);
		p1piece4->Location = Point(xValues[4], yValues[2]); p2piece4->Location = Point(xValues[4], yValues[7]);
		p1piece5->Location = Point(xValues[5], yValues[2]); p2piece5->Location = Point(xValues[5], yValues[7]);
		p1piece6->Location = Point(xValues[6], yValues[2]); p2piece6->Location = Point(xValues[6], yValues[7]);
		p1piece7->Location = Point(xValues[7], yValues[2]); p2piece7->Location = Point(xValues[7], yValues[7]);
		p1piece8->Location = Point(xValues[8], yValues[2]); p2piece8->Location = Point(xValues[8], yValues[7]);
		p1piece9->Location = Point(xValues[1], yValues[1]); p2piece9->Location = Point(xValues[1], yValues[8]);
		p1piece10->Location = Point(xValues[2], yValues[1]); p2piece10->Location = Point(xValues[2], yValues[8]);
		p1piece11->Location = Point(xValues[3], yValues[1]); p2piece11->Location = Point(xValues[3], yValues[8]);
		p1piece12->Location = Point(xValues[4], yValues[1]); p2piece12->Location = Point(xValues[4], yValues[8]);
		p1piece13->Location = Point(xValues[5], yValues[1]); p2piece13->Location = Point(xValues[5], yValues[8]);
		p1piece14->Location = Point(xValues[6], yValues[1]); p2piece14->Location = Point(xValues[6], yValues[8]);
		p1piece15->Location = Point(xValues[7], yValues[1]); p2piece15->Location = Point(xValues[7], yValues[8]);
		p1piece16->Location = Point(xValues[8], yValues[1]); p2piece16->Location = Point(xValues[8], yValues[8]);

		// Setting the image of all pieces
		p1piece1->Image = p1pawnSet->Image; p2piece1->Image = p2pawnSet->Image;
		p1piece2->Image = p1pawnSet->Image; p2piece2->Image = p2pawnSet->Image;
		p1piece3->Image = p1pawnSet->Image; p2piece3->Image = p2pawnSet->Image;
		p1piece4->Image = p1pawnSet->Image; p2piece4->Image = p2pawnSet->Image;
		p1piece5->Image = p1pawnSet->Image; p2piece5->Image = p2pawnSet->Image;
		p1piece6->Image = p1pawnSet->Image; p2piece6->Image = p2pawnSet->Image;
		p1piece7->Image = p1pawnSet->Image; p2piece7->Image = p2pawnSet->Image;
		p1piece8->Image = p1pawnSet->Image; p2piece8->Image = p2pawnSet->Image;
		p1piece9->Image = p1rookSet->Image; p2piece9->Image = p2rookSet->Image;
		p1piece10->Image = p1horseSet->Image; p2piece10->Image = p2horseSet->Image;
		p1piece11->Image = p1bishopSet->Image; p2piece11->Image = p2bishopSet->Image;
		p1piece12->Image = p1queenSet->Image; p2piece12->Image = p2queenSet->Image;
		p1piece13->Image = p1kingSet->Image; p2piece13->Image = p2kingSet->Image;
		p1piece14->Image = p1bishopSet->Image; p2piece14->Image = p2bishopSet->Image;
		p1piece15->Image = p1horseSet->Image; p2piece15->Image = p2horseSet->Image;
		p1piece16->Image = p1rookSet->Image; p2piece16->Image = p2rookSet->Image;

		// Setting all pieces to visible 
		p1piece1->Visible = true; p2piece1->Visible = true;
		p1piece2->Visible = true; p2piece2->Visible = true;
		p1piece3->Visible = true; p2piece3->Visible = true;
		p1piece4->Visible = true; p2piece4->Visible = true;
		p1piece5->Visible = true; p2piece5->Visible = true;
		p1piece6->Visible = true; p2piece6->Visible = true;
		p1piece7->Visible = true; p2piece7->Visible = true;
		p1piece8->Visible = true; p2piece8->Visible = true;
		p1piece9->Visible = true; p2piece9->Visible = true;
		p1piece10->Visible = true; p2piece10->Visible = true;
		p1piece11->Visible = true; p2piece11->Visible = true;
		p1piece12->Visible = true; p2piece12->Visible = true;
		p1piece13->Visible = true; p2piece13->Visible = true;
		p1piece14->Visible = true; p2piece14->Visible = true;
		p1piece15->Visible = true; p2piece15->Visible = true;
		p1piece16->Visible = true; p2piece16->Visible = true;

		// Setting all pieces accesibleName
		p1piece1->AccessibleName = "p1pawn";   p2piece1->AccessibleName = "p2pawn";
		p1piece2->AccessibleName = "p1pawn";   p2piece2->AccessibleName = "p2pawn";
		p1piece3->AccessibleName = "p1pawn";   p2piece3->AccessibleName = "p2pawn";
		p1piece4->AccessibleName = "p1pawn";   p2piece4->AccessibleName = "p2pawn";
		p1piece5->AccessibleName = "p1pawn";   p2piece5->AccessibleName = "p2pawn";
		p1piece6->AccessibleName = "p1pawn";   p2piece6->AccessibleName = "p2pawn";
		p1piece7->AccessibleName = "p1pawn";   p2piece7->AccessibleName = "p2pawn";
		p1piece8->AccessibleName = "p1pawn";   p2piece8->AccessibleName = "p2pawn";
		p1piece9->AccessibleName = "p1rook";   p2piece9->AccessibleName = "p2rook";
		p1piece10->AccessibleName = "p1horse";   p2piece10->AccessibleName = "p2horse";
		p1piece11->AccessibleName = "p1bishop";   p2piece11->AccessibleName = "p2bishop";
		p1piece12->AccessibleName = "p1queen";   p2piece12->AccessibleName = "p2queen";
		p1piece13->AccessibleName = "p1king";   p2piece13->AccessibleName = "p2king";
		p1piece14->AccessibleName = "p1bishop";   p2piece14->AccessibleName = "p2bishop";
		p1piece15->AccessibleName = "p1horse";   p2piece15->AccessibleName = "p2horse";
		p1piece16->AccessibleName = "p1rook";   p2piece16->AccessibleName = "p2rook";

		// Setting all pieces colors back to transparent
		p1piece1->BackColor = Color::Transparent; p2piece1->BackColor = Color::Transparent;
		p1piece2->BackColor = Color::Transparent; p2piece2->BackColor = Color::Transparent;
		p1piece3->BackColor = Color::Transparent; p2piece3->BackColor = Color::Transparent;
		p1piece4->BackColor = Color::Transparent; p2piece4->BackColor = Color::Transparent;
		p1piece5->BackColor = Color::Transparent; p2piece5->BackColor = Color::Transparent;
		p1piece6->BackColor = Color::Transparent; p2piece6->BackColor = Color::Transparent;
		p1piece7->BackColor = Color::Transparent; p2piece7->BackColor = Color::Transparent;
		p1piece8->BackColor = Color::Transparent; p2piece8->BackColor = Color::Transparent;
		p1piece9->BackColor = Color::Transparent; p2piece9->BackColor = Color::Transparent;
		p1piece10->BackColor = Color::Transparent; p2piece10->BackColor = Color::Transparent;
		p1piece11->BackColor = Color::Transparent; p2piece11->BackColor = Color::Transparent;
		p1piece12->BackColor = Color::Transparent; p2piece12->BackColor = Color::Transparent;
		p1piece13->BackColor = Color::Transparent; p2piece13->BackColor = Color::Transparent;
		p1piece14->BackColor = Color::Transparent; p2piece14->BackColor = Color::Transparent;
		p1piece15->BackColor = Color::Transparent; p2piece15->BackColor = Color::Transparent;
		p1piece16->BackColor = Color::Transparent; p2piece16->BackColor = Color::Transparent;

		// Setting all the array pieces
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				board[i][j] = ogBoard[i][j];
			}
		}

		// Fixing the size of the panels
		panel1-> Size = Drawing::Size(46, 47);  panel11->Size = Drawing::Size(46, 47); panel21->Size = Drawing::Size(46, 47);
		panel2-> Size = Drawing::Size(46, 47);  panel12->Size = Drawing::Size(46, 47); panel22->Size = Drawing::Size(46, 47);
		panel3-> Size = Drawing::Size(46, 47);  panel13->Size = Drawing::Size(46, 47); panel23->Size = Drawing::Size(46, 47);
		panel4-> Size = Drawing::Size(46, 47);  panel14->Size = Drawing::Size(46, 47); panel24->Size = Drawing::Size(46, 47);
		panel5-> Size = Drawing::Size(46, 47);  panel15->Size = Drawing::Size(46, 47); panel25->Size = Drawing::Size(46, 47);
		panel6-> Size = Drawing::Size(46, 47);  panel16->Size = Drawing::Size(46, 47); panel26->Size = Drawing::Size(46, 47);
		panel7-> Size = Drawing::Size(46, 47);  panel17->Size = Drawing::Size(46, 47); panel27->Size = Drawing::Size(46, 47);
		panel8-> Size = Drawing::Size(46, 47);  panel18->Size = Drawing::Size(46, 47); panel28->Size = Drawing::Size(46, 47);
		panel9-> Size = Drawing::Size(46, 47);  panel19->Size = Drawing::Size(46, 47); panel20->Size = Drawing::Size(46, 47);
		panel10->Size = Drawing::Size(46, 47);  panel20->Size = Drawing::Size(46, 47); panel30->Size = Drawing::Size(46, 47);


		// Making the panels invisible in case the reset button is clicked while some are visible
		panel1->Visible = false;   panel11->Visible = false; panel21->Visible = false;
		panel2->Visible = false;   panel12->Visible = false; panel22->Visible = false;
		panel3->Visible = false;   panel13->Visible = false; panel23->Visible = false;
		panel4->Visible = false;   panel14->Visible = false; panel24->Visible = false;
		panel5->Visible = false;   panel15->Visible = false; panel25->Visible = false;
		panel6->Visible = false;   panel16->Visible = false; panel26->Visible = false;
		panel7->Visible = false;   panel17->Visible = false; panel27->Visible = false;
		panel8->Visible = false;   panel18->Visible = false; panel28->Visible = false;
		panel9->Visible = false;   panel19->Visible = false; panel20->Visible = false;
		panel10->Visible = false;  panel20->Visible = false; panel30->Visible = false;

		// Making upgrade window invisible
		pawnUpgradeWindow->Visible = false;

		// Refreshing danger list (or in this case, setting up)
		refresehKingNoMoveList();

		

		// Setting the turn
		isP1Turn = true;

		// Making invisible the name tags
		p1TurnPanel->Visible = 0;
		p2TurnPanel->Visible = 0;

		// Setting the nametags inputs back to original texts
		player1NameTextBox->Text = "Player 1";
		player2NameTextBox->Text = "Player 2";

		// Setting up the names for the players
		settingNamePanel->Visible = true;

		// Setting the game has ended panel to invisble
		gameEndedPanel->Visible = false;

		// Resetting borders
		resetBorders();


	}          
	
	// Pushing the start button after setting up the names
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Setting the names of the players
		player1NameTag->Text = player1NameTextBox->Text;
		player2NameTag->Text = player2NameTextBox->Text;
		
		// Making visible player 1 name tag
		p1TurnPanel->Visible = 1;
		p2TurnPanel->Visible = 0;

		// Making invisble the start menu
		settingNamePanel->Visible = false;
		
	}

	// =================================================================================================================================




	// ===========================.
	// Move a piece to Point:      \
	// =================================================================================================================================

	// Moves a piece to a target
	void move(PictureBox^ moving, Point target) {
		int xPrevious;
		if (moving->Location != Point(0, 0))
			xPrevious = tBoardX(moving->Location); int yPrevious = tBoardY(moving->Location);
		int xNew = tBoardX(target); int yNew = tBoardY(target);

		// ARRAY: Deleting moved item 
		if (moving->Location != Point(0, 0))
			board[xPrevious][yPrevious] = "";

		// IMAGE: Deleting victim item
		bool targetIsEmpty = isEmpty(xNew, yNew);
		if (!targetIsEmpty) {
			getPictureAt(target)->Visible = false;
			getPictureAt(target)->Location = Point(0, 0);
		}

		// ARRAY: Moving moved Item
		string movedItem = hToString(moving->AccessibleName).substr(2, 1);     // p2queen <- Example name
		movedItem = movedItem + hToString(moving->AccessibleName).substr(1, 1);
		board[xNew][yNew] = movedItem;

		// IMAGE: Moving moved item
		moving->Location = target;

		// IMAGE: Checking if pawn needs upgrade - Enters when IS pawn and NEEDS upgrade
		bool neededUpgrade = false;
		if (moving->AccessibleName[2] == 'p') {
			if ((moving->Location.Y == yValues[1]) || (moving->Location.Y == yValues[8])) {

				// Setting up the colors of the pieces shown
				if (moving->AccessibleName[1] == '1') {
					rookUpgrade->BackgroundImage = p1rookSet->Image;     horseUpgrade->BackgroundImage = p1horseSet->Image;
					bishopUpgrade->BackgroundImage = p1bishopSet->Image; queenUpgrade->BackgroundImage = p1queenSet->Image;
				}
				else {
					rookUpgrade->BackgroundImage = p2rookSet->Image;     horseUpgrade->BackgroundImage = p2horseSet->Image;
					bishopUpgrade->BackgroundImage = p2bishopSet->Image; queenUpgrade->BackgroundImage = p2queenSet->Image;
				}

				pawnUpgradeWindow->Visible = true;
				passingPawn = moving;
				return;
			}
		}


		// IMAGE: Updating the dangerList
		refresehKingNoMoveList();

		// Moves will only be avaiable if the king can get out of check
		updateKingChecked();

	}

	// =================================================================================================================================




	// ===========================.
	// Helper Functions:           \
	// =================================================================================================================================
 
	// Converts a handle to a string
	string hToString(String^ target) {
		string rValue = msclr::interop::marshal_as<std::string>(target);
		return rValue;
	}

	// Converts x,y coordinates into an index in corresponding arrays
	int tBoardX(Point target) {
		for (int i = 1; i < 9; i++) {
			if (target.X == xValues[i])
				return i;
		}
		return 0;
	}
	int tBoardY(Point target) {
		for (int i = 0; i < 9; i++) {
			if (target.Y == yValues[i])
				return i;
		}
		return 0;
	}

	// Checks if thiis position is empty, index level
	bool isEmpty(int x, int y) {
		return (board[x][y] == "");
	}

	// Grabs the pictureBox at a specific Point, coordinate level
	PictureBox^ getPictureAt(Point target) {
		if (target == p1piece1->Location) { return p1piece1; } if (target == p2piece1->Location) { return p2piece1; }
		if (target == p1piece2->Location) { return p1piece2; } if (target == p2piece2->Location) { return p2piece2; }
		if (target == p1piece3->Location) { return p1piece3; } if (target == p2piece3->Location) { return p2piece3; }
		if (target == p1piece4->Location) { return p1piece4; } if (target == p2piece4->Location) { return p2piece4; }
		if (target == p1piece5->Location) { return p1piece5; } if (target == p2piece5->Location) { return p2piece5; }
		if (target == p1piece6->Location) { return p1piece6; } if (target == p2piece6->Location) { return p2piece6; }
		if (target == p1piece7->Location) { return p1piece7; } if (target == p2piece7->Location) { return p2piece7; }
		if (target == p1piece8->Location) { return p1piece8; } if (target == p2piece8->Location) { return p2piece8; }
		if (target == p1piece9->Location) { return p1piece9; } if (target == p2piece9->Location) { return p2piece9; }
		if (target == p1piece10->Location) { return p1piece10; } if (target == p2piece10->Location) { return p2piece10; }
		if (target == p1piece11->Location) { return p1piece11; } if (target == p2piece11->Location) { return p2piece11; }
		if (target == p1piece12->Location) { return p1piece12; } if (target == p2piece12->Location) { return p2piece12; }
		if (target == p1piece13->Location) { return p1piece13; } if (target == p2piece13->Location) { return p2piece13; }
		if (target == p1piece14->Location) { return p1piece14; } if (target == p2piece14->Location) { return p2piece14; }
		if (target == p1piece15->Location) { return p1piece15; } if (target == p2piece15->Location) { return p2piece15; }
		if (target == p1piece16->Location) { return p1piece16; } if (target == p2piece16->Location) { return p2piece16; }
		
		return nullptr;
	}

	// Checks if x and y is in bounds in the ARRAY
	bool inBounds(int x, int y) {
		if (x < 1 || x > 8)
			return false;
		if (y < 1 || y > 8)
			return false;
		return true;
	}

	// Kills a piece - ONLY FOR TESTING
	void kill(PictureBox^ currPiece) {
		board[tBoardX(currPiece->Location)][tBoardY(currPiece->Location)] = "";
		getPictureAt(currPiece->Location)->Visible = false;
		getPictureAt(currPiece->Location)->Location = Point(0, 0);
		
		
	}

	// Switches the turns in the game and shows - also checks if the game is over 
	void changeTurn() {
		refresehKingNoMoveList();
		updateKingChecked();

		isP1Turn = !isP1Turn;
		if (isP1Turn) {
			p1TurnPanel->Visible = true;
			p2TurnPanel->Visible = false;
		}
		else {
			p1TurnPanel->Visible = false;
			p2TurnPanel->Visible = true;
		}
		resetChoices();

		

		if (currPlayerLost()) { 
			// Show the menu that this person has won
			// Ask if users would want to reset the board
			int winningPlayer = (isP1Turn) ? 2 : 1;
			gameEndedPanel->Visible = true;
		}
	}

	// Checking the conditions of the game ending
	bool currPlayerLost() {
		// Returns true if this player has lost the match
		// Game ends under these conditions:
		// - King is in check:
		//    -> King cannot move and no piece can save it  == Check Mate!
		// - Only the King remains
		//    -> King cannot move                           == Stale Mate!



		// Setting the current data
		int currPlayer = (isP1Turn) ? 1 : 2;
		if (currPlayer == 1)
			chosenPiece = p1piece13;
		else
			chosenPiece = p2piece13;
		

		
		
		// If the king is NOT in check and ONLY king is left -> checking for stalemate
		if (!kingInCheck && onlyKingLeft(currPlayer)) {
			if (currPlayer == 1) {
				showKingOptions(p1piece13);
			}
			else {
				showKingOptions(p2piece13);
			}

			if (!panel1->Visible) {
				resetChoices();
				if (currPlayer == 1) { winnerText->Text = "Player 2 WON - Stalemate"; }
				else { winnerText->Text = "Player 1 WON - Stalemate"; }
				
				return true;
			}
			resetChoices();

			// If only king is left, don't continue through rest of the code
			return false;
		}

		// Testing the corresponding king -------------------------------------------------------------------
		if (currPlayer == 1) {
			showKingOptions(p1piece13);
		}
		else {
			showKingOptions(p2piece13);
		}
		if (panel1->Visible) {    // King still has places it can move to
			resetChoices();
			return false;
		}


		
		// Testing the corresponding rooks ------------------------------------------------------------------
		if (currPlayer == 1) {                                      // If curr player is p1
			if (p1piece9->Visible)  { showRookOptions(p1piece9);  } // If still alive, try to show its options
			if (p1piece16->Visible) { showRookOptions(p1piece16); }
		}
		else {                                                      // If curr player is p2
			if (p2piece9->Visible)  { showRookOptions(p2piece9);  } // If still alive, try to show its options
			if (p2piece16->Visible) { showRookOptions(p2piece16); }
		}
		if (panel1->Visible) {                                      // If avail. choices, king can be saved
			resetChoices();
			return false;                                           // Found a way to save the king, return false
		}
		
	
		

		// Testing the corresponding bishops ----------------------------------------------------------------
		
		if (currPlayer == 1) {
			if (p1piece11->Visible) { showBishopOptions(p1piece11); } 
			if (p1piece14->Visible) { showBishopOptions(p1piece14); }
		}
		else {
			if (p2piece11->Visible) { showBishopOptions(p2piece11); }
			if (p2piece14->Visible) { showBishopOptions(p2piece14); }
		}

		if (panel1->Visible) {
			resetChoices();
			return false;
		}


		// Testing the corresponding horse ------------------------------------------------------------------
		if (currPlayer == 1) {
			if (p1piece10->Visible) { showHorseOptions(p1piece10); }
			if (p1piece15->Visible) { showHorseOptions(p1piece15); }
		}
		else {
			if (p2piece10->Visible) { showHorseOptions(p2piece10); }
			if (p2piece15->Visible) { showHorseOptions(p2piece15); }
		}

		if (panel1->Visible) {
			resetChoices();
			return false;
		}

		// Testing the corresponding queen ------------------------------------------------------------------
		if (currPlayer == 1) {
			if (p1piece12->Visible) { showQueenoptions(p1piece12); }
		}
		else {
			if (p2piece12->Visible) { showQueenoptions(p2piece12); }
		}

		if (panel1->Visible) {
			resetChoices();
			return false;
		}
		// Testing the corresponding pawns ------------------------------------------------------------------
		if (currPlayer == 1) {
			if (p1piece1->Visible) { showPawnOptions(p1piece1); }
			if (p1piece2->Visible) { showPawnOptions(p1piece2); }
			if (p1piece3->Visible) { showPawnOptions(p1piece3); }
			if (p1piece4->Visible) { showPawnOptions(p1piece4); }
			if (p1piece5->Visible) { showPawnOptions(p1piece5); }
			if (p1piece6->Visible) { showPawnOptions(p1piece6); }
			if (p1piece7->Visible) { showPawnOptions(p1piece7); }
			if (p1piece8->Visible) { showPawnOptions(p1piece8); }
		}
		else {
			if (p2piece1->Visible) { showPawnOptions(p2piece1); }
			if (p2piece2->Visible) { showPawnOptions(p2piece2); }
			if (p2piece3->Visible) { showPawnOptions(p2piece3); }
			if (p2piece4->Visible) { showPawnOptions(p2piece4); }
			if (p2piece5->Visible) { showPawnOptions(p2piece5); }
			if (p2piece6->Visible) { showPawnOptions(p2piece6); }
			if (p2piece7->Visible) { showPawnOptions(p2piece7); }
			if (p2piece8->Visible) { showPawnOptions(p2piece8); }
		}
		
		if (panel1->Visible) {
			resetChoices();
			return false;
		}
		
		// Setting winning panel text
		if (currPlayer == 1) { winnerText->Text = "Player 2 WON - Checkmate"; }
		else                 { winnerText->Text = "Player 1 WON - Checkmate"; }
		
		resetChoices();
		return true;                       // Returning that nobody was able to save king -> player has lost
	}

	// Checking if the king is the only piece left on the board
	bool onlyKingLeft(int team) {
		if (team == 1) {
			if(p1piece1-> Visible ){return false;}
			if(p1piece2-> Visible ){return false;}
			if(p1piece3-> Visible ){return false;}
			if(p1piece4-> Visible ){return false;}
			if(p1piece5-> Visible ){return false;}
			if(p1piece6-> Visible ){return false;}
			if(p1piece7-> Visible ){return false;}
			if(p1piece8-> Visible ){return false;}
			if(p1piece9-> Visible ){return false;}
			if(p1piece10->Visible ){return false;}
			if(p1piece11->Visible ){return false;}
			if(p1piece12->Visible ){return false;}
			if(p1piece14->Visible ){return false;}
			if(p1piece15->Visible ){return false;}
			if(p1piece16->Visible ){return false;}
			
		}
		else {
			if (p2piece1->Visible) { return false; }
			if (p2piece2->Visible) { return false; }
			if (p2piece3->Visible) { return false; }
			if (p2piece4->Visible) { return false; }
			if (p2piece5->Visible) { return false; }
			if (p2piece6->Visible) { return false; }
			if (p2piece7->Visible) { return false; }
			if (p2piece8->Visible) { return false; }
			if (p2piece9->Visible) { return false; }
			if (p2piece10->Visible) { return false; }
			if (p2piece11->Visible) { return false; }
			if (p2piece12->Visible) { return false; }
			if (p2piece14->Visible) { return false; }
			if (p2piece15->Visible) { return false; }
			if (p2piece16->Visible) { return false; }
		}
		return true;
	}

	void resetBorders(){
		p1piece1-> BorderStyle = BorderStyle::None; p2piece1-> BorderStyle = BorderStyle::None;
		p1piece2-> BorderStyle = BorderStyle::None; p2piece2-> BorderStyle = BorderStyle::None;
		p1piece3-> BorderStyle = BorderStyle::None; p2piece3-> BorderStyle = BorderStyle::None;
		p1piece4-> BorderStyle = BorderStyle::None; p2piece4-> BorderStyle = BorderStyle::None;
		p1piece5-> BorderStyle = BorderStyle::None; p2piece5-> BorderStyle = BorderStyle::None;
		p1piece6-> BorderStyle = BorderStyle::None; p2piece6-> BorderStyle = BorderStyle::None;
		p1piece7-> BorderStyle = BorderStyle::None; p2piece7-> BorderStyle = BorderStyle::None;
		p1piece8-> BorderStyle = BorderStyle::None; p2piece8-> BorderStyle = BorderStyle::None;
		p1piece9-> BorderStyle = BorderStyle::None; p2piece9-> BorderStyle = BorderStyle::None;
		p1piece10->BorderStyle = BorderStyle::None; p2piece10->BorderStyle = BorderStyle::None;
		p1piece11->BorderStyle = BorderStyle::None; p2piece11->BorderStyle = BorderStyle::None;
		p1piece12->BorderStyle = BorderStyle::None; p2piece12->BorderStyle = BorderStyle::None;
		p1piece13->BorderStyle = BorderStyle::None; p2piece13->BorderStyle = BorderStyle::None;
		p1piece14->BorderStyle = BorderStyle::None; p2piece14->BorderStyle = BorderStyle::None;
		p1piece15->BorderStyle = BorderStyle::None; p2piece15->BorderStyle = BorderStyle::None;
		p1piece16->BorderStyle = BorderStyle::None; p2piece16->BorderStyle = BorderStyle::None;

	}

	// Pressing the hide window button in the end of game screen
	private: System::Void hideWinningMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		gameEndedPanel->Visible = false;
	}

	// =================================================================================================================================




	// ===========================.
	// KNM List Functions:         \
	// =================================================================================================================================

	// Set dangerList for team 
	void setDanger(int xTarget, int yTarget, char team) {
		if (team == '1')
			p1dangerList[xTarget][yTarget] = true;
		else
			p2dangerList[xTarget][yTarget] = true;
	}


	// Setting KNML for each piece functions:
	void setPawnKNML(PictureBox^ currPawn, char team) {
		if (hToString(currPawn->AccessibleName).substr(2, 1) != "p") {
			if (hToString(currPawn->AccessibleName).substr(2, 1) == "h") 
				setHorseKNML(currPawn,team);
			else if (hToString(currPawn->AccessibleName).substr(2, 1) == "b") 
				setBishopKNML(currPawn, team);
			else if (hToString(currPawn->AccessibleName).substr(2, 1) == "r") 
				setRookKNML(currPawn, team);
			else if (hToString(currPawn->AccessibleName).substr(2, 1) == "q") 
				setRookKNML(currPawn, team);
			return;
		}

		
		int xArray = tBoardX(currPawn->Location);
		int yArray = tBoardY(currPawn->Location);


		if (xArray == 0 || yArray == 0)  // If this piece is not in the board, return, its dead
			return;

		// Moving one foward
		if (currPawn->Name[1] == '1') 
			yArray++;
		else
			yArray--;


		// Left Diag.
		xArray--;
		if (inBounds(xArray, yArray)) {
			setDanger(xArray, yArray, team);
		}


		// Right Diag.
		xArray += 2;
		if (inBounds(xArray, yArray)) {
			setDanger(xArray, yArray, team);
		}

		
	}
	
	void setRookKNML(PictureBox^ currRook, char team) {
		int xArray = tBoardX(currRook->Location);
		int yArray = tBoardY(currRook->Location);

		if (xArray == 0 || yArray == 0)  // If this piece is not in the board, return
			return;

		// UPWARDS
		for (int i = yArray+1; i < 9; i++){          // Going upwards
			setDanger(xArray, i, team);              // Add this positions
			if (!isEmpty(xArray, i))                 // If spot is taken, this will be the last added pos.
				break;
			
		}

		// DOWNWARDS
		for (int i = yArray-1; i > 0; i--){
			setDanger(xArray, i, team);
			if (!isEmpty(xArray, i))
				break;
		}

		// LEFTWARDS
		for (int i = xArray-1; i > 0; i--){
			setDanger(i, yArray, team);
			if (!isEmpty(i, yArray))
				break;
		}

		// RIGHTWARDS
		for (int i = xArray+1; i < 9; i++){
			setDanger(i, yArray, team);
			if (!isEmpty(i, yArray))
				break;
		}
	}
	
	void setHorseKNML(PictureBox^ currHorse, char team) {
		int xArray = tBoardX(currHorse->Location);
		int yArray = tBoardY(currHorse->Location);

		if (xArray == 0 || yArray == 0)  // If this piece is not in the board, return
			return;

		// Setting array with possible positions, for horses, perceptive foward does not matter
		int possiblePos[8][2] = {
			{xArray - 1, yArray + 2},   // Top-Left
			{xArray + 1, yArray + 2},	// Top-Right
			{xArray - 1, yArray - 2},	// Bottom-Left
			{xArray + 1, yArray - 2},	// Bottom-Right
			{xArray - 2, yArray + 1},	// Left-Top
			{xArray - 2, yArray - 1},	// Left-Bottom
			{xArray + 2, yArray + 1},	// Right-Top
			{xArray + 2, yArray - 1}	// Right-Bottom
		};

		for (int i = 0; i < 8; i++){
			if (inBounds(possiblePos[i][0], possiblePos[i][1]))
				setDanger(possiblePos[i][0], possiblePos[i][1], team);
		}
	}
	
	void setBishopKNML(PictureBox^ currBishop, char team) {
		int xArray = tBoardX(currBishop->Location);
		int yArray = tBoardY(currBishop->Location);
		if (xArray == 0 || yArray == 0)  // If this piece is not in the board, return
			return;

		
		// Diag. headed Top-Right
		xArray = tBoardX(currBishop->Location) + 1;
		yArray = tBoardY(currBishop->Location) + 1;
		while (inBounds(xArray, yArray)) {
			setDanger(xArray, yArray, team);
			if (!isEmpty(xArray, yArray))
				break;
			xArray++; yArray++;
		}

		// Diag. headed Top-Left
		xArray = tBoardX(currBishop->Location) - 1;
		yArray = tBoardY(currBishop->Location) + 1;
		while (inBounds(xArray, yArray)) {
			setDanger(xArray, yArray, team);
			if (!isEmpty(xArray, yArray))
				break;
			xArray--; yArray++;
		}

		// Diag. headed Bottom-Right
		xArray = tBoardX(currBishop->Location) + 1;
		yArray = tBoardY(currBishop->Location) - 1;
		while (inBounds(xArray, yArray)) {
			setDanger(xArray, yArray, team);
			if (!isEmpty(xArray, yArray))
				break;
			xArray++; yArray--;
		}

		// Diag. headed Bottom-Left
		xArray = tBoardX(currBishop->Location) - 1;
		yArray = tBoardY(currBishop->Location) - 1;
		while (inBounds(xArray, yArray)) {
			setDanger(xArray, yArray, team);
			if (!isEmpty(xArray, yArray))
				break;
			xArray--; yArray--;
		}
	}

	void setKingKNML(PictureBox^ currKing, char team) {
		int xArray, yArray;

		xArray = tBoardX(currKing->Location);
		yArray = tBoardY(currKing->Location);
		if (xArray == 0 || yArray == 0)  // If this piece is not in the board, return
			return;

		int possiblePos[8][2] = {     // Starting from the top, go around the circle clockwise:
			{xArray    , yArray + 1}, // Top
			{xArray + 1, yArray + 1}, // Top Right
			{xArray + 1, yArray    }, // Right
			{xArray + 1, yArray - 1}, // Bottom Right
			{xArray    , yArray - 1}, // Bottom
			{xArray - 1, yArray - 1}, // Bottom Left
			{xArray - 1, yArray    }, // Left 
			{xArray - 1, yArray + 1}  // Top Left
		};

		for (int i = 0; i < 8; i++) {
			if (inBounds(possiblePos[i][0], possiblePos[i][1]))
				setDanger(possiblePos[i][0], possiblePos[i][1], team);
		}
	}

	void setQueenKNML(PictureBox^ currQueen, char team){
		int xArray = tBoardX(currQueen->Location);
		int yArray = tBoardY(currQueen->Location);
		if (xArray == 0 || yArray == 0)   // If piece is not in board, return 
			return;

		//                                                      ___
		setRookKNML(currQueen, team);  // Using code from Rook     | 
		setBishopKNML(currQueen, team);// Using code from Bishop   |--> Queen uses all of these abilities
	}


	// Driving function of dangerList refresh
	void refresehKingNoMoveList() {
		// Clearing the dangerlist
		clearDangerLists();
		
		// ========[ Setting the danger positions for each piece ]==========
		// PAWN: P1
		setPawnKNML(p1piece1,'1'); setPawnKNML(p1piece2,'1'); setPawnKNML(p1piece3,'1'); setPawnKNML(p1piece4,'1');
		setPawnKNML(p1piece5,'1'); setPawnKNML(p1piece6,'1'); setPawnKNML(p1piece7,'1'); setPawnKNML(p1piece8,'1');
		
		// PAWN: P2
		setPawnKNML(p2piece1, '2'); setPawnKNML(p2piece2, '2'); setPawnKNML(p2piece3, '2'); setPawnKNML(p2piece4, '2');
		setPawnKNML(p2piece5, '2'); setPawnKNML(p2piece6, '2'); setPawnKNML(p2piece7, '2'); setPawnKNML(p2piece8, '2');
		
		// ROOK / HORSE / BISHOP: P1
		setRookKNML(p1piece9, '1');    setRookKNML(p1piece16, '1');
		setHorseKNML(p1piece10, '1');  setHorseKNML(p1piece15, '1');
		setBishopKNML(p1piece11, '1'); setBishopKNML(p1piece14, '1');
		
		// ROOK / HORSE / BISHOP: P2
		setRookKNML(p2piece9, '2');    setRookKNML(p2piece16, '2');
		setHorseKNML(p2piece10, '2');  setHorseKNML(p2piece15, '2');
		setBishopKNML(p2piece11, '2'); setBishopKNML(p2piece14, '2');
		
		// KING / QUEEN: P1
		setKingKNML(p1piece13, '1'); 
		setQueenKNML(p1piece12, '1');
		
		
		// KING / QUEEN: P2
		setKingKNML(p2piece13, '2');
		setQueenKNML(p2piece12, '2');
	
	}

	// Checks if this move caused the king to go to check:
	void updateKingChecked() {
		kingInCheck = false;
		// At this time, we are checking this current players king because the turns already changed
		if (p1dangerList[tBoardX(p2piece13->Location)][tBoardY(p2piece13->Location)]) { // p2 King in check 
			p2piece13->BackColor = Color::Red;
			kingInCheck = true;
		}
		else { // P2 King not in check
			p2piece13->BackColor = Color::Transparent;
		}
		if (p2dangerList[tBoardX(p1piece13->Location)][tBoardY(p1piece13->Location)]) { // p1 King in check 
			p1piece13->BackColor = Color::Red;
			kingInCheck = true;
		}
		else { // P1 King not in check
			p1piece13->BackColor = Color::Transparent;
		}

	}

	// =================================================================================================================================




	// ===========================.
	// Pawn Upgrade Choice:        \
	// =================================================================================================================================

	// When the option upgrade was chosen, set up the pawn both visually and in the array
	private: System::Void pawnUpgradeChoice(System::Object^ sender, System::EventArgs^ e) {
		Button^ choice = safe_cast<Button^>(sender);

		// ARRAY: Updating the piece name 
		char currPlayer = (isP1Turn) ? '1' : '2';
		string temp = hToString(choice->Name).substr(0, 1) + hToString(passingPawn->Name).substr(1,1);
		board[tBoardX(passingPawn->Location)][tBoardY(passingPawn->Location)] = temp;

		// IMAGE: Updating piece name and picture
		passingPawn->Image = choice->BackgroundImage;
		if (choice->AccessibleName[1] == '1') {
			if (choice->AccessibleName[0] == 'r')      { passingPawn->AccessibleName = p1rookSet->AccessibleName;   }
			else if (choice->AccessibleName[0] == 'h') { passingPawn->AccessibleName = p1horseSet->AccessibleName;  }
			else if (choice->AccessibleName[0] == 'b') { passingPawn->AccessibleName = p1bishopSet->AccessibleName; }
			else if (choice->AccessibleName[0] == 'q') { passingPawn->AccessibleName = p1queenSet->AccessibleName;  }
		}
		else {
			if (choice->AccessibleName[0] == 'r')      { passingPawn->AccessibleName = p2rookSet->AccessibleName;   }
			else if (choice->AccessibleName[0] == 'h') { passingPawn->AccessibleName = p2horseSet->AccessibleName;  }
			else if (choice->AccessibleName[0] == 'b') { passingPawn->AccessibleName = p2bishopSet->AccessibleName; }
			else if (choice->AccessibleName[0] == 'q') { passingPawn->AccessibleName = p2queenSet->AccessibleName;  }
		}

		// Making upgradeChoiceWindow invisible
		pawnUpgradeWindow->Visible = false;

		// Setting dangerList because it was not set in move function
		refresehKingNoMoveList();
		updateKingChecked();
	}

	// =================================================================================================================================




	// ===========================.
	// Show Choice Controls:       \
	// =================================================================================================================================
// 
	// Checks if this move will save the king
	bool willSaveKing(Point target) {
		// chosenPiece - holds the piece that the options are currently being shown
		// target      - the current choice that is preparing to show
		// Return TRUE : when this choice will save king
		// Return FALSE: when this choice will NOT save king
		

		
		PictureBox^ moving_piece = chosenPiece;                   // saving moving piece pointer
		Point moving_piece_location = moving_piece->Location;	  // saving moving piece original location
		PictureBox^ killed_piece = nullptr;						  // creating space for killed piece
		Point killed_piece_location;							  // creating space for killed piece orginal location
		if (!isEmpty(tBoardX(target), tBoardY(target))) {		  // If move is aggressice
			killed_piece = getPictureAt(target);				  // then;  save killed piece pointer
			killed_piece_location = killed_piece->Location;		  // then;  save killed piece original location
		}

		
		
		moving_piece->Visible = false;                             // Making invisible pos invisible
		move(moving_piece, target);								   // Move piece to target
		if (pawnUpgradeWindow->Visible) {						   // If it was a pawn upgrade, ignore 
			pawnUpgradeWindow->Visible = false;
		}
		                                                           // Dangerlist and kingInCheck both update inside the move functions
		
		bool rValue = !kingInCheck;                                // Save status of if king would be saved

		

		move(moving_piece, moving_piece_location);                 // Moving moving piece to original location 
		moving_piece->Visible = true;							   // Making moving piece visible again
		if (killed_piece != nullptr) {							   // If it was aggressive, move back killed piece to original location and make visible
			move(killed_piece, killed_piece_location);
			killed_piece->Visible = true;
		}
																   // Dangerlist and kingInCheck both update inside the move functions

		
		return rValue;										       // Return status bool

	}

	// Checks if this move will cause the king to go into check
	bool willCauseCheck(Point target) {
		// Almost identical to the above, but we are checking with THIS current player, not after moving so it is a bit different

		PictureBox^ moving_piece = chosenPiece;                   // saving moving piece pointer
		Point moving_piece_location = moving_piece->Location;	  // saving moving piece original location
		PictureBox^ killed_piece = nullptr;						  // creating space for killed piece
		Point killed_piece_location;							  // creating space for killed piece orginal location
		if (!isEmpty(tBoardX(target), tBoardY(target))) {		  // If move is aggressice
			killed_piece = getPictureAt(target);				  // then;  save killed piece pointer
			killed_piece_location = killed_piece->Location;		  // then;  save killed piece original location
		}


		
		moving_piece->Visible = false;                            // Making invisible pos invisible
		move(moving_piece, target);								  // Move piece to target
		if (pawnUpgradeWindow->Visible) {						  // If it was a pawn upgrade, ignore 
			pawnUpgradeWindow->Visible = false;					  
		}
		                                                          // Dangerlist and kingInCheck both update inside the move functions



		// Finds out if this current players king was put in check, not if any king is in check <------- This is the difference
		bool rValue;
		int currPlayer = (isP1Turn) ? 1:2;
		if (currPlayer == 1) {
			if (p2dangerList[tBoardX(p1piece13->Location)][tBoardY(p1piece13->Location)])
				rValue = true;
			else
				rValue = false;
		}
		else {
			if (p1dangerList[tBoardX(p2piece13->Location)][tBoardY(p2piece13->Location)])
				rValue = true;
			else
				rValue = false;
		}
		

		move(moving_piece, moving_piece_location);                // Moving moving piece to original location 
		moving_piece->Visible = true;							  // Making moving piece visible again
		if (killed_piece != nullptr) {							  // If it was aggressive, move back killed piece to original location and make visible
			move(killed_piece, killed_piece_location);			  
			killed_piece->Visible = true;						  
		}														  
		                                                          // Dangerlist and kingInCheck both update inside the move functions

		
		
		return rValue;                                            // Return status bool
	}

	// Makes choices invisible and changing colors back to blue, no need to move them 
	void resetChoices() {
		panel1 ->Visible = false; panel1 ->BackColor = Color::PaleTurquoise;
		panel2 ->Visible = false; panel2 ->BackColor = Color::PaleTurquoise;
		panel3 ->Visible = false; panel3 ->BackColor = Color::PaleTurquoise;
		panel4 ->Visible = false; panel4 ->BackColor = Color::PaleTurquoise;
		panel5 ->Visible = false; panel5 ->BackColor = Color::PaleTurquoise;
		panel6 ->Visible = false; panel6 ->BackColor = Color::PaleTurquoise;
		panel7 ->Visible = false; panel7 ->BackColor = Color::PaleTurquoise;
		panel8 ->Visible = false; panel8 ->BackColor = Color::PaleTurquoise;
		panel9 ->Visible = false; panel9 ->BackColor = Color::PaleTurquoise;
		panel10->Visible = false; panel10->BackColor = Color::PaleTurquoise;
		panel11->Visible = false; panel11->BackColor = Color::PaleTurquoise;
		panel12->Visible = false; panel12->BackColor = Color::PaleTurquoise;
		panel13->Visible = false; panel13->BackColor = Color::PaleTurquoise;
		panel14->Visible = false; panel14->BackColor = Color::PaleTurquoise;
		panel15->Visible = false; panel15->BackColor = Color::PaleTurquoise;
		panel16->Visible = false; panel16->BackColor = Color::PaleTurquoise;
		panel17->Visible = false; panel17->BackColor = Color::PaleTurquoise;
		panel18->Visible = false; panel18->BackColor = Color::PaleTurquoise;
		panel19->Visible = false; panel19->BackColor = Color::PaleTurquoise;
		panel20->Visible = false; panel20->BackColor = Color::PaleTurquoise;
		panel21->Visible = false; panel21->BackColor = Color::PaleTurquoise;
		panel22->Visible = false; panel22->BackColor = Color::PaleTurquoise;
		panel23->Visible = false; panel23->BackColor = Color::PaleTurquoise;
		panel24->Visible = false; panel24->BackColor = Color::PaleTurquoise;
		panel25->Visible = false; panel25->BackColor = Color::PaleTurquoise;
		panel26->Visible = false; panel26->BackColor = Color::PaleTurquoise;
		panel27->Visible = false; panel27->BackColor = Color::PaleTurquoise;
		panel28->Visible = false; panel28->BackColor = Color::PaleTurquoise;
		panel29->Visible = false; panel29->BackColor = Color::PaleTurquoise;
		panel30->Visible = false; panel30->BackColor = Color::PaleTurquoise;
	}

	// Showing the next choice that is invisible
	void showChoice(Point target, bool cK) {
		// If king is currently in check: if this move will not change that, do not show
		if (kingInCheck) { 
			if (!willSaveKing(target)) {
				return;
			}
		}

		if (chosenPiece->Name[2] != 'k') { // If this chosenpiece is NOT the king (king is already moving to ONLY protected)
			if(willCauseCheck(target)) {
				return;
			}
		}
		
		
		if (!panel1->Visible) { panel1->Location = target; panel1->Visible = true; if (cK) { panel1->BackColor = Color::Red; } return; }
		else if (!panel2->Visible) { panel2->Location = target; panel2->Visible = true; if (cK) { panel2->BackColor = Color::Red; } return; }
		else if (!panel3->Visible) { panel3->Location = target; panel3->Visible = true; if (cK) { panel3->BackColor = Color::Red; } return; }
		else if (!panel4->Visible) { panel4->Location = target; panel4->Visible = true; if (cK) { panel4->BackColor = Color::Red; } return; }
		else if (!panel5->Visible) { panel5->Location = target; panel5->Visible = true; if (cK) { panel5->BackColor = Color::Red; } return; }
		else if (!panel6->Visible) { panel6->Location = target; panel6->Visible = true; if (cK) { panel6->BackColor = Color::Red; } return; }
		else if (!panel7->Visible) { panel7->Location = target; panel7->Visible = true; if (cK) { panel7->BackColor = Color::Red; } return; }
		else if (!panel8->Visible) { panel8->Location = target; panel8->Visible = true; if (cK) { panel8->BackColor = Color::Red; } return; }
		else if (!panel9->Visible) { panel9->Location = target; panel9->Visible = true; if (cK) { panel9->BackColor = Color::Red; } return; }
		else if (!panel10->Visible) { panel10->Location = target; panel10->Visible = true; if (cK) { panel10->BackColor = Color::Red; } return; }
		else if (!panel11->Visible) { panel11->Location = target; panel11->Visible = true; if (cK) { panel11->BackColor = Color::Red; } return; }
		else if (!panel12->Visible) { panel12->Location = target; panel12->Visible = true; if (cK) { panel12->BackColor = Color::Red; } return; }
		else if (!panel13->Visible) { panel13->Location = target; panel13->Visible = true; if (cK) { panel13->BackColor = Color::Red; } return; }
		else if (!panel14->Visible) { panel14->Location = target; panel14->Visible = true; if (cK) { panel14->BackColor = Color::Red; } return; }
		else if (!panel15->Visible) { panel15->Location = target; panel15->Visible = true; if (cK) { panel15->BackColor = Color::Red; } return; }
		else if (!panel16->Visible) { panel16->Location = target; panel16->Visible = true; if (cK) { panel16->BackColor = Color::Red; } return; }
		else if (!panel17->Visible) { panel17->Location = target; panel17->Visible = true; if (cK) { panel17->BackColor = Color::Red; } return; }
		else if (!panel18->Visible) { panel18->Location = target; panel18->Visible = true; if (cK) { panel18->BackColor = Color::Red; } return; }
		else if (!panel19->Visible) { panel19->Location = target; panel19->Visible = true; if (cK) { panel19->BackColor = Color::Red; } return; }
		else if (!panel20->Visible) { panel20->Location = target; panel20->Visible = true; if (cK) { panel20->BackColor = Color::Red; } return; }
		else if (!panel21->Visible) { panel21->Location = target; panel21->Visible = true; if (cK) { panel21->BackColor = Color::Red; } return; }
		else if (!panel22->Visible) { panel22->Location = target; panel22->Visible = true; if (cK) { panel22->BackColor = Color::Red; } return; }
		else if (!panel23->Visible) { panel23->Location = target; panel23->Visible = true; if (cK) { panel23->BackColor = Color::Red; } return; }
		else if (!panel24->Visible) { panel24->Location = target; panel24->Visible = true; if (cK) { panel24->BackColor = Color::Red; } return; }
		else if (!panel25->Visible) { panel25->Location = target; panel25->Visible = true; if (cK) { panel25->BackColor = Color::Red; } return; }
		else if (!panel26->Visible) { panel26->Location = target; panel26->Visible = true; if (cK) { panel26->BackColor = Color::Red; } return; }
		else if (!panel27->Visible) { panel27->Location = target; panel27->Visible = true; if (cK) { panel27->BackColor = Color::Red; } return; }
		else if (!panel28->Visible) { panel28->Location = target; panel28->Visible = true; if (cK) { panel28->BackColor = Color::Red; } return; }
		else if (!panel29->Visible) { panel29->Location = target; panel29->Visible = true; if (cK) { panel29->BackColor = Color::Red; } return; }
		else if (!panel30->Visible) { panel30->Location = target; panel30->Visible = true; if (cK) { panel30->BackColor = Color::Red; } return; }
		
		
	}

	// Option is clicked, move the piece to that location
	private: System::Void optionClicked(System::Object^ sender, System::EventArgs^ e) {
		Panel^ targetObject = safe_cast<Panel^>(sender);
		move(chosenPiece, targetObject->Location);        // Moves item here
		resetChoices();                                   // Hides all options
		changeTurn();                                     // Turn changes
		updateKingChecked();                              // Checks if king is checked
		resetBorders();
	}
	// =================================================================================================================================




	// ===========================.
	// Piece Clicked functions:    \
	// =================================================================================================================================

	// PAWN: show options for the pawn
	void showPawnOptions(PictureBox^ currPawn) {

		// One foward
		int xArray = tBoardX(currPawn->Location);
		int yArray = (currPawn->Name[1] == '1') ? (tBoardY(currPawn->Location) + 1) : (tBoardY(currPawn->Location) - 1);

		if (inBounds(xArray, yArray)) {                                        // If in bounds
			if (isEmpty(xArray, yArray)) {                                     // If spot is empty
				showChoice(Point( xValues[xArray], yValues[yArray] ), false);  // Show this choice 
			}
		}

		// Two foward - x stays the same 
		if ((currPawn->Location.Y == yValues[2] && currPawn->Name[1] == '1') ||
			(currPawn->Location.Y == yValues[7] && currPawn->Name[1] == '2')) {	 // If is in original location

			if (panel1->Visible) {                                                       // If first foward was not taken
				yArray = (currPawn->Name[1] == '1') ? (tBoardY(currPawn->Location) + 2) : (tBoardY(currPawn->Location) - 2);
				if (isEmpty(xArray, yArray)) {                                           // If spot is empty
					showChoice(Point(xValues[xArray], yValues[yArray]), false);          // Show this choice 
				}
			}
		}

		// Left Diag
		yArray = (currPawn->Name[1] == '1') ? (tBoardY(currPawn->Location) + 1) : (tBoardY(currPawn->Location) - 1);
		xArray -= 1;
		if (inBounds(xArray, yArray)) {								           // If in bounds
			if (!isEmpty(xArray, yArray)) {							           // If is NOT empty
				if (board[xArray][yArray][1] != currPawn->Name[1]) {           // If is enemy
					showChoice(Point(xValues[xArray], yValues[yArray]), true); // Show choice
				}
			}
		}

		// Right Diag - y stays the same
		xArray += 2;
		if (inBounds(xArray, yArray)) {								           // If in bounds
			if (!isEmpty(xArray, yArray)) {							           // If is NOT empty
				if (board[xArray][yArray][1] != currPawn->Name[1]) {           // If is enemy
					showChoice(Point(xValues[xArray], yValues[yArray]), true); // Show choice
				}
			}
		}
	}

	// ROOK: show options for the rook
	void showRookOptions(PictureBox^ currRook) {

		// Setting UPWARDS:
		int xArray = tBoardX(currRook->Location);
		int yArray = tBoardY(currRook->Location);
		char currPlayer = (currRook->Name[1] == '1') ? '1' : '2';
			
		for (int i = yArray+1; i < 9; i++){                                      // Going upwards in yValues
			if (inBounds(xArray, i)) {										     // If in bounds 
				if (isEmpty(xArray, i)) {									     // If is empty
					showChoice(Point(xValues[xArray], yValues[i]), false);	     // = Show this choice : NK
				}
				else {															 // If NOT empty
					if (board[xArray][i][1] != currPlayer) {                     // If is enemy
						showChoice(Point(xValues[xArray], yValues[i]), true);    // = Show this choice : YK
					}
					break;                                                       // If encountered, break
				}
			}
		}

		// Setting DOWNWARDS
		for (int i = yArray - 1; i > 0; i--) {
			if (inBounds(xArray, i)) {
				if (isEmpty(xArray, i)) {
					showChoice(Point(xValues[xArray], yValues[i]), false);
				}
				else {
					if (board[xArray][i][1] != currPlayer) {
						showChoice(Point(xValues[xArray], yValues[i]), true);
					}
					break;
				}
			}
		}

		// Setting LEFT_WAYS
		for (int i = xArray - 1; i > 0; i--) {
			if (inBounds(i, yArray)) {
				if (isEmpty(i, yArray)) {
					showChoice(Point(xValues[i], yValues[yArray]), false);
				}
				else {
					if (board[i][yArray][1] != currPlayer) {
						showChoice(Point(xValues[i], yValues[yArray]), true);
					}
					break;
				}
			}
		}

		// Setting RIGHT_WAYS
		for (int i = xArray + 1; i < 9; i++) {
			if (inBounds(i, yArray)) {
				if (isEmpty(i, yArray)) {
					showChoice(Point(xValues[i], yValues[yArray]), false);
				}
				else {
					if (board[i][yArray][1] != currPlayer) {
						showChoice(Point(xValues[i], yValues[yArray]), true);
					}
					break;
				}
			}
		}
	}

	// HORSE: show options for the horse
	void showHorseOptions(PictureBox^ currHorse) {
		int xArray = tBoardX(currHorse->Location);
		int yArray = tBoardY(currHorse->Location);
		char currPlayer = (currHorse->Name[1] == '1') ? '1' : '2';

		// Setting array with possible positions, for horses, perceptive foward does not matter
		int possiblePos[8][2] = {
			{xArray - 1, yArray + 2},   // Top-Left
			{xArray + 1, yArray + 2},	// Top-Right
			{xArray - 1, yArray - 2},	// Bottom-Left
			{xArray + 1, yArray - 2},	// Bottom-Right
			{xArray - 2, yArray + 1},	// Left-Top
			{xArray - 2, yArray - 1},	// Left-Bottom
			{xArray + 2, yArray + 1},	// Right-Top
			{xArray + 2, yArray - 1}	// Right-Bottom
		};


		int x_, y_;
		for (int i = 0; i < 8; i++) {				        	           // For all possible pos.
			x_ = possiblePos[i][0];									       // Grabbing the point from list
			y_ = possiblePos[i][1];									       // Grabbing the point from list
			if (inBounds(x_,y_)){                                          // If in bounds
				if (isEmpty(x_,y_)) {                                      // If is EMPTY
					showChoice(Point(xValues[x_], yValues[y_]), false);	   // Show this choice NK
				}													 
				else {												       // If is NOT empty
					if (board[x_][y_][1] != currPlayer) {                  // If is enemy
						showChoice(Point(xValues[x_], yValues[y_]), true); // Show this choice YK
					}
				}
			}
		}
	}

	// BISHOP: show options for the bishop
	void showBishopOptions(PictureBox^ currBishop) {
		int xArray = tBoardX(currBishop->Location);
		int yArray = tBoardY(currBishop->Location);
		char currPlayer = (currBishop->Name[1] == '1') ? '1' : '2';


		// Diag. headed Top-Right
		xArray = tBoardX(currBishop->Location) + 1;
		yArray = tBoardY(currBishop->Location) + 1;
		while (inBounds(xArray, yArray)) {
			if (!isEmpty(xArray, yArray)) {
				if (board[xArray][yArray][1] != currPlayer)
					showChoice(Point(xValues[xArray], yValues[yArray]), true);
				break;
			}
			else 
				showChoice(Point(xValues[xArray], yValues[yArray]), false);
			xArray++; yArray++;
		}

		// Diag. headed Top-Left
		xArray = tBoardX(currBishop->Location) - 1;
		yArray = tBoardY(currBishop->Location) + 1;
		while (inBounds(xArray, yArray)) {
			if (!isEmpty(xArray, yArray)) {
				if (board[xArray][yArray][1] != currPlayer)
					showChoice(Point(xValues[xArray], yValues[yArray]), true);
				break;
			}
			else
				showChoice(Point(xValues[xArray], yValues[yArray]), false);
			xArray--; yArray++;
		}

		// Diag. headed Bottom-Right
		xArray = tBoardX(currBishop->Location) + 1;
		yArray = tBoardY(currBishop->Location) - 1;
		while (inBounds(xArray, yArray)) {
			if (!isEmpty(xArray, yArray)) {
				if (board[xArray][yArray][1] != currPlayer)
					showChoice(Point(xValues[xArray], yValues[yArray]), true);
				break;
			}
			else
				showChoice(Point(xValues[xArray], yValues[yArray]), false);
			xArray++; yArray--;
		}

		// Diag. headed Bottom-Left
		xArray = tBoardX(currBishop->Location) - 1;
		yArray = tBoardY(currBishop->Location) - 1;
		while (inBounds(xArray, yArray)) {
			if (!isEmpty(xArray, yArray)) {
				if (board[xArray][yArray][1] != currPlayer)
					showChoice(Point(xValues[xArray], yValues[yArray]), true);
				break;
			}
			else
				showChoice(Point(xValues[xArray], yValues[yArray]), false);
			xArray--; yArray--;
		}
	}

	// KING: show options for the king
	void showKingOptions(PictureBox^ currKing) {
		int xArray = tBoardX(currKing->Location);
		int yArray = tBoardY(currKing->Location);
		char currPlayer = (currKing->Name[1] == '1') ? '1' : '2';
	
		int possiblePos[8][2] = {     // Starting from the top, go around the circle clockwise:
			{xArray    , yArray + 1}, // Top
			{xArray + 1, yArray + 1}, // Top Right
			{xArray + 1, yArray    }, // Right
			{xArray + 1, yArray - 1}, // Bottom Right
			{xArray    , yArray - 1}, // Bottom
			{xArray - 1, yArray - 1}, // Bottom Left
			{xArray - 1, yArray    }, // Left 
			{xArray - 1, yArray + 1}  // Top Left
		};
	
		int x_, y_;
		bool spotProtected;
		for (int i = 0; i < 8; i++) {
			x_ = possiblePos[i][0];
			y_ = possiblePos[i][1];
			if (inBounds(x_, y_)) {                                            // If in bounds
				if (currPlayer == '1')
					spotProtected = p2dangerList[x_][y_]; // Sees is this pos is protected in opp. team danger list
				else
					spotProtected = p1dangerList[x_][y_]; // Sees is this pos is protected in opp. team danger list
				
				// If the spot is not protected, then the king can possibly move there 
				if (!spotProtected) {                                          // If spot is NOT KNML
					if (isEmpty(x_, y_)) {                                     // If spot is empty
						showChoice(Point(xValues[x_], yValues[y_]), false);    // = Show choice
					}
					else {                                                     // If spot is taken
						if (board[x_][y_][1] != currPlayer) {                    // If spot is enemy
							showChoice(Point(xValues[x_], yValues[y_]), true); // = Show choice
						}
					}
				}
			}
		}
	}

	// QUEEN: options are the sum of bishop and rook
	void showQueenoptions(PictureBox^ currQueen) {
		showRookOptions(currQueen);
		showBishopOptions(currQueen);
	}

	// Driving function:
	private: System::Void pieceClicked(System::Object^ sender, System::EventArgs^ e) {
		resetBorders();                                                 // Unclicks the any previous options
		resetChoices();                                                 // Hides all previous points

		if (pawnUpgradeWindow->Visible)                                 // Does nothing if upgrade is open 
			return;														  
		if (settingNamePanel->Visible)                                  // Does nothing if welcome screen is open
			return;
		if (gameEndedPanel->Visible)                                    // Does nothing if End of Game panel is open
			return;


		PictureBox^ pieceClicked = safe_cast<PictureBox^>(sender);		// Casting the object to pictureBox

		
		
		if (isP1Turn && (pieceClicked->Name[1] != '1'))					// If not piece's turn
			return;														 
		if (!isP1Turn && (pieceClicked->Name[1] != '2'))				// If not piece's turn
			return;							


		chosenPiece = pieceClicked;

		chosenPiece->BorderStyle = BorderStyle::Fixed3D;

		if (hToString(pieceClicked->AccessibleName)[2] == 'p') {		// Show pawn's options
			showPawnOptions(pieceClicked);			 
		}																 
		else if (hToString(pieceClicked->AccessibleName)[2] == 'r') {	// Show rook's options
			showRookOptions(pieceClicked);								 
		}																 
		else if (hToString(pieceClicked->AccessibleName)[2] == 'h') {	// Show horse's options
			showHorseOptions(pieceClicked);								 
		}									
		else if (hToString(pieceClicked->AccessibleName)[2] == 'b') {   // Show bishop's options
			showBishopOptions(pieceClicked);
		}
		else if (hToString(pieceClicked->AccessibleName)[2] == 'k') {	// Show king's options
			showKingOptions(pieceClicked);								 
		}
		else if (hToString(pieceClicked->AccessibleName)[2] == 'q') {   // Show queen's options
			// Options are the sum of rook and bishop options
			showQueenoptions(pieceClicked);
		}
		
	}
	
	// Clears the screen of options
	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		resetChoices();
		resetBorders();
	}

	// =================================================================================================================================

};
}