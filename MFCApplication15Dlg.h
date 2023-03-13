
// MFCApplication15Dlg.h : header file
//

#pragma once


// CMFCApplication15Dlg dialog
class CMFCApplication15Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication15Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION15_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChangeInterval();
	CString m_sTime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_sCount;
	int m_iInterval;
	CButton m_cStartTime;
	CButton m_cStopTime;
private:
	int m_iCount;
public:
	afx_msg void OnBnClickedStarttime();
	afx_msg void OnBnClickedStoptimer();
	int m_iIntervals;
	CButton m_cStartTimes;
	CButton m_cStopTimes;
	afx_msg void OnEnChangeIntervals();
	afx_msg void OnBnClickedStarttimes();
	afx_msg void OnBnClickedStoptimers();
	afx_msg void OnStnClickedStatictime();
};
