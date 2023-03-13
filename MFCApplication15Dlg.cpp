
// MFCApplication15Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication15.h"
#include "MFCApplication15Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication15Dlg dialog



CMFCApplication15Dlg::CMFCApplication15Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION15_DIALOG, pParent)
	, m_sTime(_T(""))
	, m_sCount(_T(""))
	, m_iInterval(0)
	, m_iIntervals(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iCount = 0;
}

void CMFCApplication15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATICTIME, m_sTime);
	DDX_Text(pDX, IDC_STATICCOUNT, m_sCount);
	DDX_Text(pDX, IDC_INTERVAL, m_iInterval);
	DDX_Control(pDX, IDC_STARTTIME, m_cStartTime);
	DDX_Control(pDX, IDC_STOPTIMER, m_cStopTime);
	DDX_Text(pDX, IDC_INTERVALS, m_iIntervals);
	DDX_Control(pDX, IDC_STARTTIMES, m_cStartTimes);
	DDX_Control(pDX, IDC_STOPTIMERS, m_cStopTimes);
}

BEGIN_MESSAGE_MAP(CMFCApplication15Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_INTERVAL, &CMFCApplication15Dlg::OnChangeInterval)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STARTTIME, &CMFCApplication15Dlg::OnBnClickedStarttime)
	ON_BN_CLICKED(IDC_STOPTIMER, &CMFCApplication15Dlg::OnBnClickedStoptimer)
	ON_EN_CHANGE(IDC_INTERVALS, &CMFCApplication15Dlg::OnEnChangeIntervals)
	ON_BN_CLICKED(IDC_STARTTIMES, &CMFCApplication15Dlg::OnBnClickedStarttimes)
	ON_BN_CLICKED(IDC_STOPTIMERS, &CMFCApplication15Dlg::OnBnClickedStoptimers)
	ON_STN_CLICKED(IDC_STATICTIME, &CMFCApplication15Dlg::OnStnClickedStatictime)
END_MESSAGE_MAP()


// CMFCApplication15Dlg message handlers

BOOL CMFCApplication15Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	 // Initialize the counter interval
	m_iInterval = 100;

	// Update the dialog
	UpdateData(FALSE);
	
	// Start the clock timer
	SetTimer(ID_CLOCK_TIMER, 1000, NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication15Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication15Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication15Dlg::OnChangeInterval()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);
}


void CMFCApplication15Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
// Get the current time
	CTime curTime = CTime::GetCurrentTime();
	// Which timer triggered this event?
	switch (nIDEvent) {
		// The clock timer?
	case ID_CLOCK_TIMER:
		// Display the current time
		m_sTime.Format("% d: % d : % d", curTime.GetHour(),
			curTime.GetMinute(),
			curTime.GetSecond());
		break;
		// The count timer?
	case ID_COUNT_TIMER:
		// Increment the count
		m_iCount++;
		// Format and display the count
		m_sCount.Format("%d", m_iCount);
		break;
	}
	// Update the dialog
	UpdateData(FALSE);
	///////////////////////
	// MY CODE ENDS HERE
	///////////////////////
	
	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication15Dlg::OnBnClickedStarttime()
{
	// TODO: Add your control notification handler code here
// MY CODE STARTS HERE
///////////////////////
// Update the variables
	UpdateData(TRUE);
	// Initialize the count
	m_iCount = 0;
	// Format the count for displaying
	m_sCount.Format("%d", m_iCount);
	// Update the dialog
	UpdateData(FALSE);
	// Start the timer
	SetTimer(ID_COUNT_TIMER, m_iInterval, NULL);
	// Enable the Stop Timer button
	m_cStopTime.EnableWindow(TRUE);
	// Disable the Start Timer button
	m_cStartTime.EnableWindow(FALSE);
}


void CMFCApplication15Dlg::OnBnClickedStoptimer()
{
	// TODO: Add your control notification handler code here
	// Stop the timer
	// Stop the timer
	KillTimer(ID_COUNT_TIMER);
	// Disable the Stop Timer button
	m_cStopTime.EnableWindow(FALSE);
	// Enable the Start Timer button
	m_cStartTime.EnableWindow(TRUE);
}


void CMFCApplication15Dlg::OnEnChangeIntervals()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO:  Add your control notification handler code here
}


void CMFCApplication15Dlg::OnBnClickedStarttimes()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// Initialize the count
	m_iCount = 0;
	// Format the count for displaying
	m_sCount.Format("%d", m_iCount);
	// Update the dialog
	UpdateData(FALSE);
	// Start the timer
	SetTimer(ID_COUNT_TIMER, m_iIntervals, NULL);
	// Enable the Stop Timer button
	m_cStopTimes.EnableWindow(TRUE);
	// Disable the Start Timer button
	m_cStartTimes.EnableWindow(FALSE);
}


void CMFCApplication15Dlg::OnBnClickedStoptimers()
{
	// TODO: Add your control notification handler code here
	KillTimer(ID_COUNT_TIMER);
	// Disable the Stop Timer button
	m_cStopTimes.EnableWindow(FALSE);
	// Enable the Start Timer button
	m_cStartTimes.EnableWindow(TRUE);
}


void CMFCApplication15Dlg::OnStnClickedStatictime()
{
	// TODO: Add your control notification handler code here
}
