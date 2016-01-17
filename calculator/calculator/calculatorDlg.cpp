
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "CString"
#include"math.h"
#include"CnewcalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	flag = 0;
	m_temp = 0;
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_CALCUATOR, &CcalculatorDlg::OnBnClickedCalcuator)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_SUB, &CcalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CcalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CcalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_CLEAR2, &CcalculatorDlg::OnBnClickedClear2)
	ON_BN_CLICKED(IDC_CLEAR3, &CcalculatorDlg::OnBnClickedClear3)
	ON_BN_CLICKED(IDC_SQRT, &CcalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_RECIPROC, &CcalculatorDlg::OnBnClickedReciproc)
	ON_BN_CLICKED(IDC_SIGN, &CcalculatorDlg::OnBnClickedSign)
	ON_BN_CLICKED(IDC_CHANGESIGN, &CcalculatorDlg::OnBnClickedChangesign)
	ON_BN_CLICKED(IDC_M1, &CcalculatorDlg::OnBnClickedM1)
	ON_BN_CLICKED(IDC_M1ADD, &CcalculatorDlg::OnBnClickedM1add)
	ON_BN_CLICKED(IDC_M1SUB, &CcalculatorDlg::OnBnClickedM1sub)
	ON_BN_CLICKED(IDC_M1C, &CcalculatorDlg::OnBnClickedM1c)
	ON_BN_CLICKED(IDC_M1R, &CcalculatorDlg::OnBnClickedM1r)
	ON_WM_KEYUP()
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ��������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





//***********************************************
//*               �˶�Ϊ�������ֵ              *
//***********************************************


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"0";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClicked1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"6";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClicked7()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"7";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClicked8()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str = m_str + L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	if(m_str.Find(L".")== -1)
	{
		if(m_str == "")
		{
			m_str = m_str + L"0";
		}
		m_str = m_str + L".";
	}
	UpdateData(false);
}



//***********************************************
//*               �˶�Ϊ�������ֵ              *
//***********************************************







//***********************************************
//*               �˶�Ϊ��������                *
//***********************************************

void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 1;
	m_str = "";
	UpdateData(false);

}

void CcalculatorDlg::OnBnClickedSub()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 2;
	m_str = "";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedMul()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 3;
	m_str = "";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDiv()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	UpdateData(true);
	if (flag == 1)
	{
		temp = temp + _ttof(m_str);
	}
	else if (flag == 2)
	{
		temp = temp - _ttof(m_str);
	}
	else if (flag == 3)
	{
		temp = temp * _ttof(m_str);
	}
	else if (flag == 4)
	{
		if (_ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp / _ttof(m_str);
			m_str.Format(L"%lf", temp);
		}
	}
	else
	{
		temp = _ttof(m_str);
	}
	flag = 4;
	m_str = "";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCalcuator()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	if(flag == 1)
	{
		temp = temp +  _ttof(m_str);
		m_str.Format(L"%lf",temp);
		
	}
	else if(flag == 2)
	{
		temp = temp -  _ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	else if(flag == 3)
	{ 
		temp = temp *  _ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	else if(flag == 4)
	{
		if( _ttof(m_str) == 0)
		{
			m_str = L"false:The denominator cannot be 0";
			flag = 0;
		}
		else
		{
			temp = temp /  _ttof(m_str);
			m_str.Format(L"%lf",temp);
		}
	}
	rigdel(m_str);
	UpdateData(false);
}


//***********************************************
//*               �˶�Ϊ��������                *
//***********************************************









//***********************************************
//*                 �˶�Ϊ���                  *
//***********************************************


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag = 0;
	temp = NULL;
	m_str = "";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedClear2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	m_str = "";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedClear3()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


//***********************************************
//*                 �˶�Ϊ���                  *
//***********************************************






//***********************************************
//*             �˶�Ϊ�������㷨��              *
//***********************************************



void CcalculatorDlg::OnBnClickedSqrt()//����
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	temp = sqrt(_ttof(m_str));
	m_str.Format(L"%lf",temp);
	rigdel(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedReciproc()//����
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	if( _ttof(m_str) == 0)
	{
		m_str = L"false:The denominator cannot be 0";
		flag = 0;
	}
	else
	{
		temp = _ttof(m_str);
		temp=1/temp;
		m_str.Format(L"%lf",temp);
	}
	rigdel(m_str);
	UpdateData(false);
}



void CcalculatorDlg::OnBnClickedSign()//�ٷֺ�
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	double temp1;
	UpdateData(true);
	if(!(flag == 0||m_str == L""))
	{
		temp1 = _ttof(m_str);
		temp1 = temp1/100;
	}
	m_str.Format(L"%lf",temp1);
	rigdel(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedChangesign()//�෴��
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	double temp2;
	UpdateData(true);
	temp2 = _ttof(m_str);
	temp2 = -temp2;
	m_str.Format(L"%lf",temp2);
	rigdel(m_str);
	UpdateData(false);
}


//***********************************************
//*             �˶�Ϊ�������㷨��              *
//***********************************************




//***********************************************
//*              �˶�ΪMϵ�ഢ��                *
//***********************************************


void CcalculatorDlg::OnBnClickedM1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CnewcalculatorDlg m_dlg4;
	m_dlg4.set(m_temp);
	ShowWindow(SW_HIDE); // ���ص�ǰ����
	m_dlg4.DoModal();
	ExitProcess(0);
}


void CcalculatorDlg::OnBnClickedM1add()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_temp = m_temp +  _ttof(m_str);
}


void CcalculatorDlg::OnBnClickedM1sub()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_temp = m_temp - _ttof(m_str);
}


void CcalculatorDlg::OnBnClickedM1c()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	m_temp = 0;
}


void CcalculatorDlg::OnBnClickedM1r()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	m_str.Format(L"%lf", m_temp);
	rigdel(m_str);
	UpdateData(false);
}

//***********************************************
//*              �˶�ΪMϵ�ഢ��                *
//***********************************************



//***********************************************
//*           �˶�Ϊ�´����ĳ�Ա����            *
//***********************************************

void CcalculatorDlg::rigdel(CString &m_s)
{
	while (m_s.Right(1) == "0")
	{
		m_s.Delete(m_s.GetLength() - 1, 1);
	}
	while (m_s.Right(1) == ".")
	{
		m_s.Delete(m_s.GetLength() - 1, 1);
	}
}


//***********************************************
//*           �˶�Ϊ�´����ĳ�Ա����            *
//***********************************************

void CcalculatorDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}