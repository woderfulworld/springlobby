/* Copyright (C) 2007 The SpringLobby Team. All rights reserved. */
/* Author: Tobi Vollebregt */

#include "mapselectdialog.h"


BEGIN_EVENT_TABLE( MapSelectDialog, wxDialog )
END_EVENT_TABLE()


MapSelectDialog::MapSelectDialog( wxWindow* parent, Ui& ui )
	: wxDialog( parent, -1, _("Select map"), wxDefaultPosition, wxSize(640, 480),
			wxDEFAULT_DIALOG_STYLE | wxCLIP_CHILDREN | wxRESIZE_BORDER | wxMAXIMIZE_BOX)
	, m_ui(ui)
{
}


MapSelectDialog::~MapSelectDialog()
{
}
