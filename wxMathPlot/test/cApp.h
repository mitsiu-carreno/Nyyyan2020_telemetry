#ifndef C_APP_H
#define C_APP_H

#include "wx/wx.h"
#include "cMain.h"

class cApp: public wxApp{
  public:
    cApp();
    ~cApp();

  private:
    cMain* m_frame1 = nullptr;
  public:
    virtual bool OnInit();
};

#endif
