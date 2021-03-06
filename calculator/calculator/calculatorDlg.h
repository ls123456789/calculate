
// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	int flag,mflag;
	double temp,m_temp1,m_temp2,m_temp3;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedCalcuator();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedClear2();
	afx_msg void OnBnClickedClear3();
	afx_msg void OnBnClickedSqrt();
	afx_msg void OnBnClickedReciproc();
	void rigdel(CString &m_s);
	afx_msg void OnBnClickedSign();
	afx_msg void OnBnClickedChangesign();
	afx_msg void OnBnClickedM1();
	afx_msg void OnBnClickedM1add();
	afx_msg void OnBnClickedM1sub();
	afx_msg void OnBnClickedM1c();
	afx_msg void OnBnClickedM1r();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedM1s();
	//clock
	double h, m, s;
	int  hor, min, sec;
	int r = 50, r1 = 40, r2 = 30;
	double x, y;
	double PI = 3.1415926535;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
