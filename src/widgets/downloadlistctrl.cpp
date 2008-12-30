#include "downloadlistctrl.h"

const unsigned int column_count = 6;

WidgetDownloadListctrl::WidgetDownloadListctrl(wxWindow* parent, wxWindowID id, const wxString& name,
                    long style, const wxPoint& pt, const wxSize& sz)
    :CustomVirtListCtrl<Widget>(parent, 4239, wxDefaultPosition, wxDefaultSize,
            wxSUNKEN_BORDER | wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_ALIGN_LEFT, _T("WidgetDownloadListCtrl"), column_count, &CompareOneCrit)
{
    const int as = wxLIST_AUTOSIZE;
#if defined(__WXMSW__)
    const int widths [column_count] = { as, as, as, as, as, as };
#elif defined(__WXMAC__)
    const int widths [column_count] = { as, as, as, as, as, as };
#else
    const int widths [column_count] = { as, as, as, as, as, as };
#endif

    AddColumn( 0, widths[0], _("Name"), _T("Name") );
    AddColumn( 1, widths[1], _("Description"), _T("Description") );
    AddColumn( 2, widths[2], _T("Author"), _T("Author") );
    AddColumn( 3, widths[3], _T("Mods"), _T("Compatible mods") );
    AddColumn( 4, widths[4], _T("Downloads"), _T("Downloads") );
    AddColumn( 5, widths[5], _T("Date"), _T("Date") );

    m_sortorder[2].col = 2;
    m_sortorder[2].direction = 1;
    m_sortorder[0].col = 0;
    m_sortorder[0].direction = 1;
    m_sortorder[1].col = 1;
    m_sortorder[1].direction = 1;
}

WidgetDownloadListctrl::~WidgetDownloadListctrl()
{
    //dtor
}

int WidgetDownloadListctrl::CompareOneCrit( DataType u1, DataType u2, int col, int dir )
{
    return 0;
}

void WidgetDownloadListctrl::AddWidget( const Widget widget )
{
    m_data.push_back( widget );
    SetItemCount( m_data.size() );
    RefreshItem( m_data.size() );
}

wxString WidgetDownloadListctrl::OnGetItemText(long item, long column) const
{
    if ( item > m_data.size() || item < 0 )
        return wxEmptyString;

    const Widget& widget = m_data[item];
    switch ( column ) {
        default: return wxEmptyString;
        case 0: return widget.name;
        case 1: return widget.description;
        case 2: return widget.author;
        case 3: return widget.mods;
        case 4: return i2s( widget.num_downloads );
        case 5: return widget.date;
    }

}

int WidgetDownloadListctrl::OnGetItemImage(long item) const
{
    return -1;
}

int WidgetDownloadListctrl::OnGetItemColumnImage(long item, long column) const
{
    return -1;
}
