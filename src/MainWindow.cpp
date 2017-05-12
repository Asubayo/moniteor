#include "MainWindow.h"

MainWindow::MainWindow(wxWindow* parent, const std::wstring& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(parent, wxID_ANY, title, pos, size, wxMINIMIZE_BOX | wxMAXIMIZE_BOX| wxCLOSE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLIP_CHILDREN | wxRESIZE_BORDER)
{
	// Display current window on screen center
	Centre();

	// This panel contains graphics canvas (GL or VK)
	mMainPanel = new wxPanel(this, wxID_ANY);
	
	// Create a menu for this main window
	createMenuBar();
	
	Bind(wxEVT_SIZE, &MainWindow::OnResize, this);
	Bind(wxEVT_CLOSE_WINDOW, &MainWindow::onClose, this);
}

MainWindow::~MainWindow()
{
	
}

void 
MainWindow::OnResize(wxSizeEvent& event)
{
	mMainPanel->SetSize(GetSize());
}

void 
MainWindow::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void 
MainWindow::onClose(wxCloseEvent& evt)
{
	evt.Skip();
}

void MainWindow::createMenuBar()
{
	menubar = new wxMenuBar;

	// "File" in menu bar
	fileMenu = new wxMenu();
	fileMenu->Append(ID_QUIT, wxT("&Quit"));
	menubar->Append(fileMenu, wxT("&File"));

	// "View" in menu bar
	viewMenu = new wxMenu();
	menubar->Append(viewMenu, wxT("&View"));

	SetMenuBar(menubar);
	SetFocus();
	
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainWindow::OnQuit));
	Connect(ID_QUIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnQuit));
}

