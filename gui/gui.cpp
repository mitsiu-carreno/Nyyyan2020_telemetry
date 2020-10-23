// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MySin;

class MySIN: public mpFX{
  double m_freq, m_amp
  public:
    MySin(double freq, double amp) : mpFX (wxT("f(x) = SIN(x)"), mpALIGN_LEFT){
      m_freq = feq;
      m_amp = amp;
      m_drawOutsideMargins = false;
    }

    virtual double GetY(double x) {
      return m_amp * sin(x/6.283185/m_freq);
    }
    virtual double GetMinY(){ 
      return -m_amp;
    }
    virtual double GetMaxY(){
      return m_amp;
    }
}

// Every app should define a new class derivated from wxApp (By overridding 
// xnApp's Oninit() virtual method the program can be initialized)
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// The main window is created by deriving a class from wxFrame and giving it a menu and status bar in its constructor
// Also any clases that wishes to respond to an "event" (mouse clicks, messages from the menu or a button) must 
// declare an event table using the macro below
// Reacting to such event is done via "event handlers" (functions, functors lambdas...) taking the event parameter
// of the type corresponding to the event being handled

// In our example we react to three menu items: "Hello" "Exit" and "About" (any program should normally implement the latter two)
// Notice these handlers don't need to ve virtual or public
class MyFrame : public wxFrame
{
public:
    MyFrame();

    
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnFit(wxCommandEvent& event);
    void OnAlignXAxis(wxCommandEvent& event);
    void OnAlignYAxis(wxCommandEvent& event);

    mpWindow    *m_plot;
    wxTextCtrl  *_log;
private:

    int axesPos[2];
    bool ticks;
    mpInfoCoords *nfo;  // mpInfoLayer *nfo;
    DECLARE_DYNAMIC_CLASS(MyFrame)
    DECLARE_EVENT_TABLE()
};

// In order to be able to react to a menu command, it must be given a unique identifier (const variable or enum element)
enum
{
    ID_Hello = 1 ID_EXIT = 108,
    ID_ABOUT,
    ID_ALIGN_X_AXIS,
    ID_ALIGN_Y_AXIS
};
// Notice you don't need to define identifiers FOR "About" and "Exit" as wxWidgets already predefines standard values
// such as wxID_ABOUT and wxID_EXIT ((use these whenever possible as they can be handled in a special way by a particular platform)


IMPLEMENT_DYNAMIC_CLASS(MyFrame, wxFrame)

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(ID_EXIT, MyFrame::OnExit)
    EVT_MENU(mpID_FIT, MyFrame::OnFit)
    EVT_MENU(ID_ALIGN_X_AXIS, MyFrame::OnAlignXAxis)
    EVT_MENU(ID_ALIGN_Y_AXIS, MyFrame::OnAlignYAxis)
END_EVENT_TABLE()

// As in all programs, there must be a "main" function. Under wxWidgets, main is implemented inside the "wxIMPLEMENT_APP()" macro, 
// which creates an application instance of the specified class and starts running the GUI event loop
wxIMPLEMENT_APP(MyApp);

// As mentioned wxApp::OnInit() is called upon startup and should be used to initialize the program (maybe showing a "splash screen") and creating the main window
// Frames are created hidden by default, to allow the creation of child windows before displaying them
// We need to explicitly show them
// Finally we return true from this method to indicate successful initialization 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
// In the constructor of the main window, we create a menu with our menu items, as well as a status bar to be shown at the bottom of the main window
// Both have to be bound to the frame with respective calls

// Notice we don't need to specify the labels for the standard menu items wxID_ABOUT and wxID_EXIT - they will be given standard labels
// and standard accelerators correct for the current platform, making our program behave more native

// We also have to connect our event handlers to the events we want to handle in them. We do this by calling Bind() to send all the menus events 
// (identified by wxEVENT_MENU event type) with the specified ID to the given function
MyFrame::MyFrame()
    //: wxFrame(NULL, wxID_ANY, "Hello World")
    : wxFrame( (wxFrame *)NULL, -1, wxT("wxWindow mathplot sample"), wxDefaultPosition, wxSize(500, 500) )
{
    //wxMenu *menuFile = new wxMenu;
    wxMenu *menu_file = new wxMenu();
    wxMenu *view_menu = new wxMenu();
    wxMenu *show_menu = new wxMenu();

    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // The params are:
    // 1-The event type (wxEVT_MENU, wxEVT_BUTTON, wxEVT_SIZE...)
    // 2-A pointer to the method call, and the object to call it on. In this case we just call our own function, and pass the "this" pointer for the object itself. 
    // (In fact any object that can be called with a wxCommandEvent, can be used here)
    // 3-An optional identifier, allowing us to select just some events of wxEVT_MENU type
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

// Standard event handler implementations
// MyFrame::OnExit() closes the main window by calling Close(). The parameter true indicates that other windows have no veto power such as after asking "Do you really want to close?" 
// If there is no other main window left, the application will quit
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

// MyFrame::OnAbout will display a small window with some text in it. In this case a typical "About" window
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

// The implementation of custom menu command handler may perform whatever task you program needs to do, in these case we will simply show a message
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

