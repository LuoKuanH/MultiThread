// ProsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "ProsDlg.h"
#include "afxdialogex.h"


// CProsDlg 对话框
extern int datax[100];
extern int datay[100];
IMPLEMENT_DYNAMIC(CProsDlg, CDialog)

CProsDlg::CProsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProsDlg::IDD, pParent)
{

}

CProsDlg::~CProsDlg()
{
}

void CProsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROS, m_pros);
}


BEGIN_MESSAGE_MAP(CProsDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CProsDlg 消息处理程序


void CProsDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	//// TODO: 在此处添加消息处理程序代码
	//// 不为绘图消息调用 CDialog::OnPaint()
	//CPen pen1(PS_SOLID,1,RGB(255,0,0)); ////建立一个画笔类对象，构造时设置画笔属性
	//dc.SelectObject(&pen1);
	//for (int i=1; i<100; i++)
	//{
	////int i = 1;
	//	dc.MoveTo(datax[i-1]*10,10);
	//	dc.LineTo(datax[i]*10,10);
	//	Sleep(10);
	//}
}
