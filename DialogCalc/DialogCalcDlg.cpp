
#include "pch.h"
#include "framework.h"
#include "DialogCalc.h"
#include "DialogCalcDlg.h"
#include "afxdialogex.h"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

CDialogCalcDlg::CDialogCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGCALC_DIALOG, pParent)
	, m_first(0)
	, m_second(0)
	, m_result(L"")
	, m_oper(L"")
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIRST, m_first);
	DDX_Text(pDX, IDC_SECOND, m_second);
	DDX_Text(pDX, IDC_RESULT, m_result);
	DDX_Text(pDX, IDC_OPER, m_oper);
}

BEGIN_MESSAGE_MAP(CDialogCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULATE, &CDialogCalcDlg::OnBnClickedCalculate)
END_MESSAGE_MAP()


// CDialogCalcDlg message handlers

BOOL CDialogCalcDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialogCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogCalcDlg::OnPaint()
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
HCURSOR CDialogCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

class Operation
{
public:
	Operation(double o1, double o2) :
		op1(o1), op2(o2)
	{}

	double calculate(char operation)
	{
		// Perform the specific operation here:
		double result = 0;
		if (operation == '+')
			result = op1 + op2;
		else if (operation == '-')
			result = op1 - op2;
		else if (operation == '*')
			result = op1 * op2;
		else if (operation == '/')
			result = op1 / op2;
		else if (operation == '^')
			result = pow(op1, op2);
		else
			throw 0;

		return result;
	}

private:
	double op1, op2;
};

void CDialogCalcDlg::OnBnClickedCalculate()
{
	UpdateData(true);
	try
	{
		Operation op(m_first, m_second);
		double result = op.calculate(m_oper[0]);
		m_result.Format(L"%g", result);
	}
	catch (...)
	{
		m_result = L"Error!";
	}
	UpdateData(false);
}
