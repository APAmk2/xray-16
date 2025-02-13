// file:		UISpinNum.h
// description:	Spin Button with text data (unlike numerical data)
// created:		15.06.2005
// author:		Serge Vynnychenko
//

#pragma once

#include "xrUICore/SpinBox/UICustomSpin.h"

class XRUICORE_API CUISpinText final : public CUICustomSpin
{
public:
    CUISpinText();

    // CUIOptionsItem
    virtual void SetCurrentOptValue(); // opt->current
    virtual void SaveBackUpOptValue(); // current->backup
    virtual void SaveOptValue(); // current->opt
    virtual void UndoOptValue(); // backup->current
    virtual bool IsChangedOptValue() const; // backup!=current

    // own
    virtual void OnBtnUpClick();
    virtual void OnBtnDownClick();

    void AddItem_(const char* item, int id);
    LPCSTR GetTokenText();

    pcstr GetDebugType() override { return "CUISpinText"; }

protected:
    virtual bool CanPressUp();
    virtual bool CanPressDown();
    virtual void IncVal(){};
    virtual void DecVal(){};
    void SetItem(int v);
    struct SInfo
    {
        shared_str _orig;
        shared_str _transl;
        int _id;
    };
    typedef xr_vector<SInfo> Items;
    typedef Items::iterator Items_it;

    Items m_list;
    int m_curItem;
    int m_opt_backup_value;
};
