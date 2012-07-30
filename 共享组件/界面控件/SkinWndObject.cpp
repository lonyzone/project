#include "StdAfx.h"
#include "Resource.h"
#include "SkinWndObject.h"
#include "..\..\公共文件\Constant.h"

//////////////////////////////////////////////////////////////////////////

//静态变量
CSkinWndAttribute		CSkinWndObject::m_SkinAttribute;				//窗口属性
CSkinWndAttribute1		CSkinWndObject1::m_SkinAttribute;				//窗口属性
//////////////////////////////////////////////////////////////////////////

//构造函数
CSkinWndAttribute::CSkinWndAttribute() 
{
	//设置变量
	m_nButtonWidth=0;
	m_nButtonHeigth=0;
	m_nCaptionHeigth=0;

	m_crBackFrame=RGB(0,0,0);
	m_crBackGround=RGB(0,0,0);
	m_crInsideBorder=RGB(0,0,0);
	m_crCaptionTXColor=RGB(0,0,0);	
	m_crControlTXColor=RGB(0,0,0);	

	return;
}

//析构函数
CSkinWndAttribute::~CSkinWndAttribute()
{
}

//加载配置
bool CSkinWndAttribute::UpdateSkinResource(ISkinResource * pISkinResource)
{
	//获取信息
	tagSkinDialogResource SkinDialogResource;
	if (pISkinResource!=NULL) pISkinResource->GetResourceInfo(SkinDialogResource);

	//加载资源
	m_TitleLeft.SetLoadInfo(SkinDialogResource.LoadInfoImageTL);
	m_TitleMid.SetLoadInfo(SkinDialogResource.LoadInfoImageTM);
	m_TitleRight.SetLoadInfo(SkinDialogResource.LoadInfoImageTR);
    
	m_FramLeft.SetLoadInfo(SkinDialogResource.Left);
	m_BottomM.SetLoadInfo(SkinDialogResource.BottomM);
	m_FramRight.SetLoadInfo(SkinDialogResource.Right);
	m_BottomL.SetLoadInfo(SkinDialogResource.BottomL);
	m_BottomR.SetLoadInfo(SkinDialogResource.BottomR);
	m_ButtonMin.SetLoadInfo(SkinDialogResource.LoadInfoButtonMin);
	m_ButtonMax.SetLoadInfo(SkinDialogResource.LoadInfoButtonMax);
	m_ButtonRes.SetLoadInfo(SkinDialogResource.LoadInfoButtonRes);
	m_ButtonClose.SetLoadInfo(SkinDialogResource.LoadInfoButtonClose);

	m_BackGroundBtm.SetLoadInfo(szResPath("SkinControl\\SKIN_DLG_BACKGROUND_BTM.BMP"),false);
	m_BackGroundMid.SetLoadInfo(szResPath("SkinControl\\SKIN_DLG_BACKGROUND_MID.BMP"),false);
	m_BackGroundTop.SetLoadInfo(szResPath("SkinControl\\SKIN_DLG_BACKGROUND_TOP.BMP"),false);

	//颜色信息
	m_crBackGround=SkinDialogResource.crBackGround;
	m_crInsideBorder=SkinDialogResource.crInsideBorder;
	m_crBackFrame=SkinDialogResource.crBackFrame;
	m_crCaptionTXColor=SkinDialogResource.crTitleText;
	m_crControlTXColor=SkinDialogResource.crControlText;

	//建立对象
	m_brBackFrame.DeleteObject();
	m_brBackGround.DeleteObject();
	m_brBackFrame.CreateSolidBrush(m_crBackFrame);
	m_brBackGround.CreateSolidBrush(m_crBackGround);
    
	//设置变量
	CImageHandle TitleHandle(&m_TitleLeft);
	CImageHandle ButtonHandle(&m_ButtonClose);
	if (TitleHandle.IsResourceValid()) m_nCaptionHeigth=TitleHandle->GetHeight();
	else m_nCaptionHeigth=0;
	if (ButtonHandle.IsResourceValid())
	{
		m_nButtonHeigth=ButtonHandle->GetHeight();
		m_nButtonWidth=ButtonHandle->GetWidth()/4;
	}
	else 
	{
		m_nButtonHeigth=0;
		m_nButtonWidth=0;
	}

	return true;
}
///////////////////////////////////////////////
//构造函数
CSkinWndAttribute1::CSkinWndAttribute1() 
{
	//设置变量
	m_nButtonWidth=0;
	m_nButtonHeigth=0;
	m_nCaptionHeigth=0;

	m_crBackFrame=RGB(0,0,0);
	m_crBackGround=RGB(0,0,0);
	m_crInsideBorder=RGB(0,0,0);
	m_crCaptionTXColor=RGB(0,0,0);	
	m_crControlTXColor=RGB(0,0,0);	

	return;
}

//析构函数
CSkinWndAttribute1::~CSkinWndAttribute1()
{
}

//加载配置
bool CSkinWndAttribute1::UpdateSkinResource(ISkinResource * pISkinResource)
{
	//获取信息
	tagSkinDialogResource SkinDialogResource;
	if (pISkinResource!=NULL) pISkinResource->GetResourceInfo(SkinDialogResource);

	//加载资源
	m_TitleLeft.SetLoadInfo(SkinDialogResource.LoadInfoImageTL);
	m_TitleMid.SetLoadInfo(SkinDialogResource.LoadInfoImageTM);
	m_TitleRight.SetLoadInfo(SkinDialogResource.LoadInfoImageTR);
	m_ButtonMin.SetLoadInfo(SkinDialogResource.LoadInfoButtonMin);
	m_ButtonMax.SetLoadInfo(SkinDialogResource.LoadInfoButtonMax);
	m_ButtonRes.SetLoadInfo(SkinDialogResource.LoadInfoButtonRes);
	m_ButtonClose.SetLoadInfo(SkinDialogResource.LoadInfoButtonClose);

	//颜色信息
	m_crBackGround=SkinDialogResource.crBackGround;
	m_crInsideBorder=SkinDialogResource.crInsideBorder;
	m_crBackFrame=SkinDialogResource.crBackFrame;
	m_crCaptionTXColor=SkinDialogResource.crTitleText;
	m_crControlTXColor=SkinDialogResource.crControlText;

	//建立对象
	m_brBackFrame.DeleteObject();
	m_brBackGround.DeleteObject();
	m_brBackFrame.CreateSolidBrush(m_crBackFrame);
	m_brBackGround.CreateSolidBrush(m_crBackGround);

	//设置变量
	CImageHandle TitleHandle(&m_TitleLeft);
	CImageHandle ButtonHandle(&m_ButtonClose);
	if (TitleHandle.IsResourceValid()) m_nCaptionHeigth=TitleHandle->GetHeight();
	else m_nCaptionHeigth=0;
	if (ButtonHandle.IsResourceValid())
	{
		m_nButtonHeigth=ButtonHandle->GetHeight();
		m_nButtonWidth=ButtonHandle->GetWidth()/4;
	}
	else 
	{
		m_nButtonHeigth=0;
		m_nButtonWidth=0;
	}

	return true;
}


//////////////////////////////////////////////////////////////////////////

//构造函数
CSkinWndObject::CSkinWndObject(CWnd * pWndSkin)
{
	m_bActive=false;
	m_bMaxSize=false;
	m_nXExcursionPos=0;
	m_nYExcursionPos=0;
	m_pWndHook=pWndSkin;
	m_cbNowHotButton=255;
	m_cbNowDownButton=255;
	memset(m_cbButtonState,0,sizeof(m_cbButtonState));
}

//析构函数
CSkinWndObject::~CSkinWndObject(void)
{
}

//初始化
void CSkinWndObject::InitSkinObject()
{
	//设置变量
	m_bActive=false;
	m_nXExcursionPos=0;
	m_nYExcursionPos=0;
	m_cbNowHotButton=255;
	m_cbNowDownButton=255;
	memset(m_cbButtonState,0,sizeof(m_cbButtonState));
     
	//计算属性
	m_pWndHook->ModifyStyle(WS_CAPTION,0,SWP_DRAWFRAME);
	m_pWndHook->ModifyStyle(WS_CAPTION|WS_BORDER,0,0);
	m_pWndHook->ModifyStyleEx(WS_EX_CLIENTEDGE|WS_EX_WINDOWEDGE,0,0);
	m_pWndHook->GetWindowRect(&m_crNormalSize);
	LONG lWindowStyte=GetWindowLongPtr(m_pWndHook->m_hWnd,GWL_STYLE);
	if (lWindowStyte&WS_SYSMENU)
	{
		m_cbButtonState[BST_CLOSE]=BUT_EXIST|BUT_NORMAL;
		if ((lWindowStyte&WS_MAXIMIZEBOX)||(lWindowStyte&WS_MINIMIZEBOX)) 
		{
			m_cbButtonState[BST_MAX]=BUT_EXIST|BUT_DISABLE;
			m_cbButtonState[BST_MIN]=BUT_EXIST|BUT_DISABLE;
			if (lWindowStyte&WS_MAXIMIZEBOX) m_cbButtonState[BST_MAX]=BUT_EXIST|BUT_NORMAL;
			else m_cbButtonState[BST_MAX]=BUT_EXIST|BUT_DISABLE;
			if (lWindowStyte&WS_MINIMIZEBOX) m_cbButtonState[BST_MIN]=BUT_EXIST|BUT_NORMAL;
			else m_cbButtonState[BST_MIN]=BUT_EXIST|BUT_DISABLE;
		}
	}

	//计算数值
	CRect ClientRect;
	m_pWndHook->GetClientRect(&ClientRect);
	AdjustTitleButton(ClientRect.Width(),ClientRect.Height());
	m_nYExcursionPos=m_SkinAttribute.m_nCaptionHeigth;
	m_nXExcursionPos=0;

	return;
}

//调整按钮
void CSkinWndObject::AdjustTitleButton(int nCXWindow, int nCYWindow)
{
	for (int i=0;i<3;i++)
	{
		int nYPos=5;
		int nXPos=nCXWindow-m_SkinAttribute.m_nButtonWidth*(i+1)-i-10;
		m_rcButton[i].left=nXPos;
		m_rcButton[i].top=nYPos;
		m_rcButton[i].right=nXPos+m_SkinAttribute.m_nButtonWidth;
		m_rcButton[i].bottom=nYPos+m_SkinAttribute.m_nButtonHeigth;
	}

	return;
}
void CSkinWndObject::DrawSkinView1(CDC * pDC)
{
	
    
	return;
}
//绘画界面
void CSkinWndObject::DrawSkinView(CDC * pDC)
{
	//获取参数
	CRect ClientRect;
	m_pWndHook->GetClientRect(&ClientRect);
    
	//建立缓冲图
	CSkinImage CaptionImage;
	CaptionImage.Create(ClientRect.Width(),m_SkinAttribute.m_nCaptionHeigth,24);
	if (CaptionImage.IsNull()) return;

	//绘画背景
	CDC BufferDC;
	BufferDC.CreateCompatibleDC(NULL);
	BufferDC.SelectObject(CaptionImage);
	DrawCaption(&BufferDC,CaptionImage.GetWidth(),CaptionImage.GetHeight());
    
	//建立 DC
	if (pDC==NULL)
	{
		CClientDC ClientDC(m_pWndHook);
		ClientDC.BitBlt(m_nXExcursionPos,0,CaptionImage.GetWidth(),CaptionImage.GetHeight(),&BufferDC,0,0,SRCCOPY);
		//ClientDC.Draw3dRect(&ClientRect,RGB(0,0,0),RGB(0,0,0));
		BufferDC.DeleteDC();
	}
	else
	{
		pDC->BitBlt(m_nXExcursionPos,0,CaptionImage.GetWidth(),CaptionImage.GetHeight(),&BufferDC,0,0,SRCCOPY);
		//pDC->Draw3dRect(&ClientRect,RGB(0,0,0),RGB(0,0,0));
	}

	//获取标题
	TCHAR strTitle[128];
	GetWindowText(*m_pWndHook,strTitle,CountArray(strTitle));

	//计算位置
	INT nYPos=(m_SkinAttribute.m_nCaptionHeigth-12)/2+2;
	INT nXPos=35;

	//建立缓冲图
	CClientDC ClientDC(m_pWndHook);
	ClientDC.SetBkMode(TRANSPARENT);
	ClientDC.SelectObject(m_SkinAttribute.m_DefaultFont);
	ClientDC.SetTextAlign(TA_LEFT);	

	//变量定义
	int nStringLength=lstrlen(strTitle);
	int nXExcursion[8]={1,1,1,0,-1,-1,-1,0};
	int nYExcursion[8]={-1,0,1,1,1,0,-1,-1};

	int nXExcursion1=GetXExcursionPos();
	int nYExcursion1=GetYExcursionPos();

	CImageHandle m_FramLeft(&m_SkinAttribute.m_FramLeft);
	if (m_SkinAttribute.m_FramLeft.IsNull()) return ;
	CImageHandle m_BottomM(&m_SkinAttribute.m_BottomM);
	if (m_SkinAttribute.m_BottomM.IsNull()) return ;
	CImageHandle m_FramRight(&m_SkinAttribute.m_FramRight);
	if (m_SkinAttribute.m_FramRight.IsNull()) return ;

	CImageHandle BottomL(&m_SkinAttribute.m_BottomL);
	if (m_SkinAttribute.m_BottomL.IsNull()) return ;

	CImageHandle BottomR(&m_SkinAttribute.m_BottomR);
	if (m_SkinAttribute.m_BottomR.IsNull()) return ;


	int nLeftWidth=m_FramLeft->GetHeight();
	int nMidWidth=m_BottomM->GetWidth();
	int nRightWidth=m_FramRight->GetHeight();
    
	for (int i=ClientRect.top+CaptionImage.GetHeight();i<ClientRect.bottom-BottomL->GetHeight();i+=nLeftWidth)
		m_SkinAttribute.m_FramLeft.BitBlt(ClientDC,nXExcursion1,i);

	for (int i=ClientRect.top+CaptionImage.GetHeight();i<ClientRect.bottom-BottomR->GetHeight();i+=nRightWidth)
		m_SkinAttribute.m_FramRight.BitBlt(ClientDC,ClientRect.Width()-nXExcursion1-m_FramRight->GetWidth(),i);
    
	for (int i=nXExcursion1+BottomL->GetWidth();i<ClientRect.Width()-m_FramRight->GetWidth();i+=nMidWidth)
		m_SkinAttribute.m_BottomM.BitBlt(ClientDC,i,ClientRect.Height()-m_BottomM->GetHeight());
    
    m_SkinAttribute.m_BottomL.BitBlt(ClientDC,0,ClientRect.Height()-BottomL->GetHeight());
   
	m_SkinAttribute.m_BottomR.BitBlt(ClientDC,ClientRect.Width()-BottomR->GetWidth()-nXExcursion1,ClientRect.Height()-BottomR->GetHeight());
    
	//绘画边框
// 	ClientDC.SetTextColor(RGB(231,192,137));
// 	for (int i=0;i<CountArray(nXExcursion);i++)
// 	{
// 		ClientDC.TextOut(nXPos,nYPos,strTitle,nStringLength);
// 	}

	//CImageHandle TitleLeft1(&m_SkinAttribute.m_TitleLeft);
	//if (m_SkinAttribute.m_TitleLeft1.IsNull()) return ;
	//CImageHandle TitleMid1(&m_SkinAttribute.m_TitleMid);
	//if (m_SkinAttribute.m_TitleMid1.IsNull()) return ;
	//CImageHandle TitleRight1(&m_SkinAttribute.m_TitleRight);
	//if (m_SkinAttribute.m_TitleRight1.IsNull()) return ;

	//int nLeftWidth=TitleLeft1->GetHeight();
	//int nMidWidth=TitleMid1->GetWidth();
	//int nRightWidth=TitleRight1->GetWidth();
	/*for (int i=ClientRect.top;i<ClientRect.bottom;i+=nLeftWidth)
		TitleLeft1->BitBlt(BufferDC.m_hDC,ClientRect.left,i);*/
	/*for (int i=nLeftWidth;i<nXMinDrawPause;i+=nMidWidth) TitleMid1->BitBlt(pDC->m_hDC,i,0);
	TitleRight1->BitBlt(pDC->m_hDC,nXMinDrawPause,0);*/

	//绘画标题m_SkinAttribute.m_crCaptionTXColor
	//ClientDC.SetTextColor(m_SkinAttribute.m_crCaptionTXColor);
	//ClientDC.TextOut(nXPos,nYPos,strTitle);

	/*for (int i=ClientRect.top;i<ClientRect.bottom;i+=nLeftWidth)
		TitleLeft1->BitBlt(BufferDC.m_hDC,ClientRect.left,i);*/
	BufferDC.DeleteDC();

	return;
}

//最大窗口
void CSkinWndObject::MaxSizeWindow()
{
	if (m_bMaxSize==false)
	{
		//计算位置
		CRect rcClient;
		m_pWndHook->GetClientRect(&rcClient);
		m_pWndHook->ClientToScreen(&rcClient);
		m_pWndHook->GetWindowRect(&m_crNormalSize);

		//移动窗口
		CRect rcRect;
		SystemParametersInfo(SPI_GETWORKAREA,0,&rcRect,SPIF_SENDCHANGE);
		rcRect.top-=(rcClient.top-m_crNormalSize.top);
		rcRect.bottom+=(m_crNormalSize.bottom-rcClient.bottom);
		rcRect.left-=(rcClient.left-m_crNormalSize.left);
		rcRect.right+=(m_crNormalSize.right-rcClient.right);
		m_pWndHook->MoveWindow(&rcRect,FALSE);
		m_pWndHook->Invalidate(FALSE);

		//设置变量
		m_bMaxSize=true;
	}

	return;
}

//还原窗口
void CSkinWndObject::RestoreWindow()
{
	if (m_bMaxSize==true)
	{
		//移动窗口
		m_pWndHook->MoveWindow(&m_crNormalSize,TRUE);

		//设置变量
		m_bMaxSize=false;
		DrawSkinView(NULL);
	}
	return;
}

//绘画标题栏
bool CSkinWndObject::DrawCaption(CDC * pDC, int cx, int cy)
{
	//加载位图
	CImageHandle TitleLeft(&m_SkinAttribute.m_TitleLeft);
	if (m_SkinAttribute.m_TitleLeft.IsNull()) return false;
	CImageHandle TitleMid(&m_SkinAttribute.m_TitleMid);
	if (m_SkinAttribute.m_TitleMid.IsNull()) return false;
	CImageHandle TitleRight(&m_SkinAttribute.m_TitleRight);
	if (m_SkinAttribute.m_TitleRight.IsNull()) return false;
    
	//绘画标题
	int nLeftWidth=TitleLeft->GetWidth();
	int nMidWidth=TitleMid->GetWidth();
	int nRightWidth=TitleRight->GetWidth();
	int nXMinDrawPause=cx-nRightWidth;
	TitleLeft->BitBlt(pDC->m_hDC,0,0);
	//m_SkinAttribute.m_TitleLeft.AlphaDrawImage(pDC,0,0,RGB(255,0,255));
	for (int i=nLeftWidth;i<nXMinDrawPause;i+=nMidWidth) TitleMid->BitBlt(pDC->m_hDC,i,0);
	TitleRight->BitBlt(pDC->m_hDC,nXMinDrawPause,0);
	m_SkinAttribute.m_TitleRight.AlphaDrawImage(pDC,nXMinDrawPause,0,RGB(255,0,255));
	
	//绘画文字
	CString strTitle;
	CRect rcTitleRect(35,4,cx-100,cy-2);
	m_pWndHook->GetWindowText(strTitle);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SelectObject(&m_SkinAttribute.m_DefaultFont);
	pDC->SetTextColor(m_SkinAttribute.m_crCaptionTXColor);
	//pDC->DrawText(strTitle,&rcTitleRect,DT_LEFT|DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS);
	//////////////////////////////////////////////////////////////////////////
	pDC->DrawText(strTitle,&rcTitleRect,DT_LEFT|DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS);

	//变量定义
// 	int nStringLength=lstrlen(strTitle);
// 	int nXExcursion[8]={1,1,1,0,-1,-1,-1,0};
// 	int nYExcursion[8]={-1,0,1,1,1,0,-1,-1};
// 
// 	//绘画边框
// 	pDC->SetTextColor(m_SkinAttribute.m_crCaptionTXColor/*RGB(0,98,142)*/);
// 	CRect rcDraw;
// 	for (int i=0;i<CountArray(nXExcursion);i++)
// 	{
// 		rcDraw.CopyRect(rcTitleRect);
// 		rcDraw.OffsetRect(nXExcursion[i],nYExcursion[i]);
// 		pDC->DrawText(strTitle,nStringLength,&rcDraw,DT_LEFT|DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS);
// 	}
// 
// 	//绘画字体
// 	rcDraw.CopyRect( rcTitleRect);
// 	pDC->SetTextColor(m_SkinAttribute.m_crCaptionTXColor);
// 	pDC->DrawText(strTitle,nStringLength,&rcDraw,DT_LEFT|DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS);
// 	//////////////////////////////////////////////////////////////////////////

	CImageHandle ButtonHandle(&m_SkinAttribute.m_ButtonClose);
	
	if (ButtonHandle.IsResourceValid())
	{
		m_SkinAttribute.m_nButtonHeigth=ButtonHandle->GetHeight();
		m_SkinAttribute.m_nButtonWidth=ButtonHandle->GetWidth()/5;
	}
	else 
	{
		m_SkinAttribute.m_nButtonHeigth=0;
		m_SkinAttribute.m_nButtonWidth=0;
	}
	//关闭按钮
	if (m_cbButtonState[BST_CLOSE]&BUT_EXIST)
	{
		int nDrawPos=0;
		CImageHandle ImageHandle(&m_SkinAttribute.m_ButtonClose);
		if (m_cbButtonState[BST_CLOSE]&BUT_DISABLE)
		{
			nDrawPos=ImageHandle->GetWidth()*3/5;
		}
		else if (m_cbNowDownButton==BST_CLOSE)
		{
			nDrawPos=ImageHandle->GetWidth()*2/5;
		}
		else if (m_cbNowHotButton==BST_CLOSE) 
		{
			nDrawPos=ImageHandle->GetWidth()/5;
		}
		ImageHandle->BitBlt(pDC->GetSafeHdc(),m_rcButton[BST_CLOSE].left,m_rcButton[BST_CLOSE].top,
			m_SkinAttribute.m_nButtonWidth,m_SkinAttribute.m_nButtonHeigth,nDrawPos,0);
	}

	//最大化和还原按钮
	if (m_cbButtonState[BST_MAX]&BUT_EXIST)
	{
		int nDrawPos=0;
		CImageHandle ImageHandle;
		if (m_bMaxSize==true) ImageHandle.AttachResource(&m_SkinAttribute.m_ButtonRes);
		else ImageHandle.AttachResource(&m_SkinAttribute.m_ButtonMax);
		if (m_cbButtonState[BST_MAX]&BUT_DISABLE)
		{
			nDrawPos=ImageHandle->GetWidth()*3/5;
		}
		if (m_cbNowDownButton==BST_MAX)
		{
			nDrawPos=ImageHandle->GetWidth()*2/5;
		}
		else if (m_cbNowHotButton==BST_MAX)
		{
			nDrawPos=ImageHandle->GetWidth()/5;
		}
		ImageHandle->BitBlt(pDC->GetSafeHdc(),m_rcButton[BST_MAX].left,m_rcButton[BST_MAX].top,
			m_SkinAttribute.m_nButtonWidth,m_SkinAttribute.m_nButtonHeigth,nDrawPos,0);
	}

	//最小化按钮
	if (m_cbButtonState[BST_MIN]&BUT_EXIST)	
	{
		int nDrawPos=0;
		CImageHandle ImageHandle(&m_SkinAttribute.m_ButtonMin);
		if (m_cbButtonState[BST_MIN]&BUT_DISABLE)
		{
			nDrawPos=ImageHandle->GetWidth()*3/5;
		}
		if (m_cbNowDownButton==BST_MIN)
		{
			nDrawPos=ImageHandle->GetWidth()*2/5;
		}
		else if (m_cbNowHotButton==BST_MIN) 
		{
			nDrawPos=ImageHandle->GetWidth()/5;
		}
		ImageHandle->BitBlt(pDC->GetSafeHdc(),m_rcButton[BST_MIN].left,m_rcButton[BST_MIN].top,
			m_SkinAttribute.m_nButtonWidth,m_SkinAttribute.m_nButtonHeigth,nDrawPos,0);
	}

	return true;	
}

//设置改变事件
void CSkinWndObject::OnSettingChange()
{
	//移动窗口
	if (m_bMaxSize==true)
	{
		//计算位置
		CRect rcClient;
		m_pWndHook->GetClientRect(&rcClient);
		m_pWndHook->ClientToScreen(&rcClient);
		m_pWndHook->GetWindowRect(&m_crNormalSize);

		//移动窗口
		CRect rcRect;
		SystemParametersInfo(SPI_GETWORKAREA,0,&rcRect,SPIF_SENDCHANGE);
		rcRect.top-=(rcClient.top-m_crNormalSize.top);
		rcRect.bottom+=(m_crNormalSize.bottom-rcClient.bottom);
		rcRect.left-=(rcClient.left-m_crNormalSize.left);
		rcRect.right+=(m_crNormalSize.right-rcClient.right);
		m_pWndHook->MoveWindow(&rcRect,FALSE);
		m_pWndHook->Invalidate(FALSE);
	}

	return;
}

//鼠标移动事件
bool CSkinWndObject::OnMouseMoveEvent(CPoint ClientPoint)
{
	//设置光标
	SetCursor(LoadCursor(NULL,MAKEINTRESOURCE(IDC_ARROW)));

	//判断按下
	if (m_cbNowDownButton!=255) return false;	
	
	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(m_rcButton[i].PtInRect(ClientPoint)))
		{
			if (m_cbNowHotButton==i) return true;
			if (m_cbNowHotButton!=255)
			{
				m_cbButtonState[m_cbNowHotButton]|=BUT_NORMAL;
				m_cbNowHotButton=255;
			}
			if ((m_cbButtonState[i]&BUT_EXIST)&&(!(m_cbButtonState[i]&BUT_DISABLE)))
			{
				m_cbNowHotButton=i;
				m_cbButtonState[m_cbNowHotButton]&=~BUT_NORMAL;
			}
			DrawSkinView(NULL);
			return true;
		}
	}

	//清理旧焦点
	if (m_cbNowHotButton!=255)
	{
		m_cbButtonState[m_cbNowHotButton]|=BUT_NORMAL;
		m_cbNowHotButton=255;
		DrawSkinView(NULL);
	}

	return true;
}
//鼠标移动事件
bool CSkinWndObject::OnMouseMoveEvent1(CPoint ClientPoint)
{
	//设置光标
	SetCursor(LoadCursor(NULL,MAKEINTRESOURCE(IDC_ARROW)));

	//判断按下
	if (m_cbNowDownButton!=255) return false;	
	
	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(m_rcButton[i].PtInRect(ClientPoint)))
		{
			if (m_cbNowHotButton==i) return true;
			if (m_cbNowHotButton!=255)
			{
				m_cbButtonState[m_cbNowHotButton]|=BUT_NORMAL;
				m_cbNowHotButton=255;
			}
			if ((m_cbButtonState[i]&BUT_EXIST)&&(!(m_cbButtonState[i]&BUT_DISABLE)))
			{
				m_cbNowHotButton=i;
				m_cbButtonState[m_cbNowHotButton]&=~BUT_NORMAL;
			}
			DrawSkinView1(NULL);
			return true;
		}
	}

	//清理旧焦点
	if (m_cbNowHotButton!=255)
	{
		m_cbButtonState[m_cbNowHotButton]|=BUT_NORMAL;
		m_cbNowHotButton=255;
		DrawSkinView1(NULL);
	}

	return true;
}
//鼠标左键事件
bool CSkinWndObject::OnLMouseDownEvent(CPoint ClientPoint)
{
	//判断按下
	if (m_cbNowDownButton!=255) return false;

	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(!(m_cbButtonState[i]&BUT_DISABLE))
			&&(m_rcButton[i].PtInRect(ClientPoint)))
		{
			//设置数据
			m_pWndHook->SetCapture();
			m_cbNowDownButton=i;
			DrawSkinView(NULL);
			return true;
		}
	}

	//模拟按标题
	if (m_bMaxSize==false)
	{
		if (ClientPoint.y<GetYExcursionPos())
		{

			m_pWndHook->PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(ClientPoint.x,ClientPoint.y));
			return true;
		}
		return false;
	}

	return true;
}
//鼠标左键事件
bool CSkinWndObject::OnLMouseDownEvent1(CPoint ClientPoint)
{
	//判断按下
	if (m_cbNowDownButton!=255) return false;

	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(!(m_cbButtonState[i]&BUT_DISABLE))
			&&(m_rcButton[i].PtInRect(ClientPoint)))
		{
			//设置数据
			m_pWndHook->SetCapture();
			m_cbNowDownButton=i;
			DrawSkinView1(NULL);
			return true;
		}
	}

	//模拟按标题
	if (m_bMaxSize==false)
	{
		if (ClientPoint.y<GetYExcursionPos()+40)
		{
			m_pWndHook->PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(ClientPoint.x,ClientPoint.y));
			return true;
		}
		return false;
	}

	return true;
}
//鼠标左键事件
bool CSkinWndObject::OnLMouseUpEvent(CPoint ClientPoint)
{
	//按钮搜索
	if (m_cbNowDownButton!=255)
	{
		ReleaseCapture();
		if ((m_rcButton[m_cbNowDownButton].PtInRect(ClientPoint))
			&&(!(m_cbButtonState[m_cbNowDownButton]&BUT_DISABLE)))
		{
			switch (m_cbNowDownButton)
			{
			case BST_CLOSE:		//关闭按钮
				{
					m_cbNowDownButton=255;
					m_pWndHook->PostMessage(WM_CLOSE,0,0);
					return true;
				}
// 			case BST_MAX:		//还原按钮
// 				{
// 					m_cbNowDownButton=255;
// 					if (m_bMaxSize==true) RestoreWindow();
// 					else MaxSizeWindow();
// 					return true;
// 				}
			case BST_MIN:		//最小化按钮
				{
					m_cbNowDownButton=255;
					m_pWndHook->ShowWindow(SW_MINIMIZE);
					return true;
				}
			}
		}

		//默认操作
		m_cbNowDownButton=255;
		DrawSkinView(NULL);
	}

	return true;
}

//鼠标左键事件
bool CSkinWndObject::OnLMouseUpEvent1(CPoint ClientPoint)
{
	//按钮搜索
	if (m_cbNowDownButton!=255)
	{
		ReleaseCapture();
		if ((m_rcButton[m_cbNowDownButton].PtInRect(ClientPoint))
			&&(!(m_cbButtonState[m_cbNowDownButton]&BUT_DISABLE)))
		{
			switch (m_cbNowDownButton)
			{
			case BST_CLOSE:		//关闭按钮
				{
					m_cbNowDownButton=255;
					return true;
				}
			case BST_MAX:		//还原按钮
				{
					m_cbNowDownButton=255;
					
					return true;
				}
			case BST_MIN:		//最小化按钮
				{
					m_cbNowDownButton=255;
					
					return true;
				}
			}
		}

		//默认操作
		m_cbNowDownButton=255;
		DrawSkinView1(NULL);
	}

	return true;
}
//鼠标左键事件
bool CSkinWndObject::OnLMouseDoubleEvent(CPoint ClientPoint)
{
	//判断按下
	if (m_cbNowDownButton!=255) return false;	

	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(m_rcButton[i].PtInRect(ClientPoint)))
			return true;
	}

	//最大化窗口
// 	if ((ClientPoint.y<GetYExcursionPos())&&(m_cbButtonState[BST_MAX]&BUT_EXIST)&&
// 		(!(m_cbButtonState[BST_MAX]&BUT_DISABLE)))
// 	{
// 		if (m_bMaxSize==true) RestoreWindow();
// 		else MaxSizeWindow();
// 	}
	
	return true;
}

//鼠标右键事件
bool CSkinWndObject::OnRMouseDownEvent(CPoint ClientPoint)
{
	return true;
}

//鼠标右键事件
bool CSkinWndObject::OnRMouseUpEvent(CPoint ClientPoint)
{
	return true;
}

//鼠标右键事件
bool CSkinWndObject::OnRMouseDoubleEvent(CPoint ClientPoint)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////
//构造函数
CSkinWndObject1::CSkinWndObject1(CWnd * pWndSkin)
{
	m_bActive=false;
	m_bMaxSize=false;
	m_nXExcursionPos=0;
	m_nYExcursionPos=0;
	m_pWndHook=pWndSkin;
	m_cbNowHotButton=255;
	m_cbNowDownButton=255;
	memset(m_cbButtonState,0,sizeof(m_cbButtonState));
}

//析构函数
CSkinWndObject1::~CSkinWndObject1(void)
{
}

//初始化
void CSkinWndObject1::InitSkinObject()
{
	//设置变量
	m_bActive=false;
	m_nXExcursionPos=0;
	m_nYExcursionPos=0;
	m_cbNowHotButton=255;
	m_cbNowDownButton=255;
	memset(m_cbButtonState,0,sizeof(m_cbButtonState));

	//计算属性
	m_pWndHook->ModifyStyle(WS_CAPTION,0,SWP_DRAWFRAME);
	m_pWndHook->GetWindowRect(&m_crNormalSize);
	LONG lWindowStyte=GetWindowLongPtr(m_pWndHook->m_hWnd,GWL_STYLE);
	if (lWindowStyte&WS_SYSMENU)
	{
		m_cbButtonState[BST_CLOSE]=BUT_EXIST|BUT_NORMAL;
		if ((lWindowStyte&WS_MAXIMIZEBOX)||(lWindowStyte&WS_MINIMIZEBOX)) 
		{
			m_cbButtonState[BST_MAX]=BUT_EXIST|BUT_DISABLE;
			m_cbButtonState[BST_MIN]=BUT_EXIST|BUT_DISABLE;
			if (lWindowStyte&WS_MAXIMIZEBOX) m_cbButtonState[BST_MAX]=BUT_EXIST|BUT_NORMAL;
			else m_cbButtonState[BST_MAX]=BUT_EXIST|BUT_DISABLE;
			if (lWindowStyte&WS_MINIMIZEBOX) m_cbButtonState[BST_MIN]=BUT_EXIST|BUT_NORMAL;
			else m_cbButtonState[BST_MIN]=BUT_EXIST|BUT_DISABLE;
		}
	}

	//计算数值
	CRect ClientRect;
	m_pWndHook->GetClientRect(&ClientRect);
	AdjustTitleButton(ClientRect.Width(),ClientRect.Height());
	m_nYExcursionPos=m_SkinAttribute.m_nCaptionHeigth;
	m_nXExcursionPos=1;

	return;
}

//调整按钮
void CSkinWndObject1::AdjustTitleButton(int nCXWindow, int nCYWindow)
{
	for (int i=0;i<3;i++)
	{
		int nYPos=2;
		int nXPos=nCXWindow-m_SkinAttribute.m_nButtonWidth*(i+1)-i-5;
		m_rcButton[i].left=nXPos;
		m_rcButton[i].top=nYPos;
		m_rcButton[i].right=nXPos+m_SkinAttribute.m_nButtonWidth;
		m_rcButton[i].bottom=nYPos+m_SkinAttribute.m_nButtonHeigth;
	}

	return;
}
void CSkinWndObject1::DrawSkinView1(CDC * pDC)
{
	//获取参数
	CRect ClientRect;
	m_pWndHook->GetClientRect(&ClientRect);

	//建立缓冲图
	CSkinImage CaptionImage;
	CaptionImage.Create(ClientRect.Width()-2*m_nXExcursionPos,m_SkinAttribute.m_nCaptionHeigth,24);
	if (CaptionImage.IsNull()) return;

	//绘画背景
	CDC BufferDC;
	BufferDC.CreateCompatibleDC(NULL);
	BufferDC.SelectObject(CaptionImage);
	//DrawCaption(&BufferDC,CaptionImage.GetWidth(),CaptionImage.GetHeight());

	//建立 DC
	if (pDC==NULL)
	{
		CClientDC ClientDC(m_pWndHook);
		ClientDC.BitBlt(m_nXExcursionPos,1,CaptionImage.GetWidth(),CaptionImage.GetHeight(),&BufferDC,0,0,SRCCOPY);
		//ClientDC.Draw3dRect(&ClientRect,RGB(0,0,0),RGB(0,0,0));
		BufferDC.DeleteDC();
	}
	else
	{
		pDC->BitBlt(m_nXExcursionPos,1,CaptionImage.GetWidth(),CaptionImage.GetHeight(),&BufferDC,0,0,SRCCOPY);
		//pDC->Draw3dRect(&ClientRect,RGB(0,0,0),RGB(0,0,0));
	}

	//获取标题
	TCHAR strTitle[128];
	GetWindowText(*m_pWndHook,strTitle,CountArray(strTitle));

	//计算位置
	INT nYPos=(m_SkinAttribute.m_nCaptionHeigth-12)/2+2;
	INT nXPos=35;

	//建立缓冲图
	CClientDC ClientDC(m_pWndHook);
	ClientDC.SetBkMode(TRANSPARENT);
	ClientDC.SelectObject(m_SkinAttribute.m_DefaultFont);
	ClientDC.SetTextAlign(TA_LEFT);

	//变量定义
	int nStringLength=lstrlen(strTitle);
	int nXExcursion[8]={1,1,1,0,-1,-1,-1,0};
	int nYExcursion[8]={-1,0,1,1,1,0,-1,-1};

	//绘画边框
	ClientDC.SetTextColor(RGB(0,112,192));
	for (int i=0;i<CountArray(nXExcursion);i++)
	{
		ClientDC.TextOut(nXPos+nXExcursion[i],nYPos+nYExcursion[i],strTitle,nStringLength);
	}

	//绘画标题m_SkinAttribute.m_crCaptionTXColor
	ClientDC.SetTextColor(m_SkinAttribute.m_crCaptionTXColor);
	ClientDC.TextOut(nXPos,nYPos,strTitle);

	BufferDC.DeleteDC();

	return;
}
//绘画界面
void CSkinWndObject1::DrawSkinView(CDC * pDC)
{
	//获取参数
	CRect ClientRect;
	m_pWndHook->GetClientRect(&ClientRect);

	//建立缓冲图
	CSkinImage CaptionImage;
	CaptionImage.Create(ClientRect.Width()-2*m_nXExcursionPos,m_SkinAttribute.m_nCaptionHeigth,24);
	if (CaptionImage.IsNull()) return;

	//绘画背景
	CDC BufferDC;
	BufferDC.CreateCompatibleDC(NULL);
	BufferDC.SelectObject(CaptionImage);
	//DrawCaption(&BufferDC,CaptionImage.GetWidth(),CaptionImage.GetHeight());

	//建立 DC
	if (pDC==NULL)
	{
		CClientDC ClientDC(m_pWndHook);
		ClientDC.BitBlt(m_nXExcursionPos,1,CaptionImage.GetWidth(),CaptionImage.GetHeight(),&BufferDC,0,0,SRCCOPY);
		//ClientDC.Draw3dRect(&ClientRect,RGB(0,0,0),RGB(0,0,0));
		BufferDC.DeleteDC();
	}
	else
	{
		pDC->BitBlt(m_nXExcursionPos,1,CaptionImage.GetWidth(),CaptionImage.GetHeight(),&BufferDC,0,0,SRCCOPY);
		//pDC->Draw3dRect(&ClientRect,RGB(0,0,0),RGB(0,0,0));
	}

	//获取标题
	TCHAR strTitle[128];
	GetWindowText(*m_pWndHook,strTitle,CountArray(strTitle));

	//计算位置
	INT nYPos=(m_SkinAttribute.m_nCaptionHeigth-12)/2+2;
	INT nXPos=35;

	//建立缓冲图
	CClientDC ClientDC(m_pWndHook);
	ClientDC.SetBkMode(TRANSPARENT);
	ClientDC.SelectObject(m_SkinAttribute.m_DefaultFont);
	ClientDC.SetTextAlign(TA_LEFT);

	//变量定义
	int nStringLength=lstrlen(strTitle);
	int nXExcursion[8]={1,1,1,0,-1,-1,-1,0};
	int nYExcursion[8]={-1,0,1,1,1,0,-1,-1};


	//绘画边框
	ClientDC.SetTextColor(RGB(0,112,192));
	for (int i=0;i<CountArray(nXExcursion);i++)
	{
		ClientDC.TextOut(nXPos+nXExcursion[i],nYPos+nYExcursion[i],strTitle,nStringLength);
	}

	//绘画标题m_SkinAttribute.m_crCaptionTXColor
	ClientDC.SetTextColor(RGB(255,255,255));
	ClientDC.TextOut(nXPos,nYPos,strTitle);

	BufferDC.DeleteDC();

	return;
}

//最大窗口
void CSkinWndObject1::MaxSizeWindow()
{
	if (m_bMaxSize==false)
	{
		//计算位置
		CRect rcClient;
		m_pWndHook->GetClientRect(&rcClient);
		m_pWndHook->ClientToScreen(&rcClient);
		m_pWndHook->GetWindowRect(&m_crNormalSize);

		//移动窗口
		CRect rcRect;
		SystemParametersInfo(SPI_GETWORKAREA,0,&rcRect,SPIF_SENDCHANGE);
		rcRect.top-=(rcClient.top-m_crNormalSize.top);
		rcRect.bottom+=(m_crNormalSize.bottom-rcClient.bottom);
		rcRect.left-=(rcClient.left-m_crNormalSize.left);
		rcRect.right+=(m_crNormalSize.right-rcClient.right);
		m_pWndHook->MoveWindow(&rcRect,FALSE);
		m_pWndHook->Invalidate(FALSE);

		//设置变量
		m_bMaxSize=true;
	}

	return;
}

//还原窗口
void CSkinWndObject1::RestoreWindow()
{
	if (m_bMaxSize==true)
	{
		//移动窗口
		m_pWndHook->MoveWindow(&m_crNormalSize,TRUE);

		//设置变量
		m_bMaxSize=false;
		DrawSkinView(NULL);
	}
	return;
}

//绘画标题栏
bool CSkinWndObject1::DrawCaption(CDC * pDC, int cx, int cy)
{
	//加载位图
	CImageHandle TitleLeft(&m_SkinAttribute.m_TitleLeft);
	if (m_SkinAttribute.m_TitleLeft.IsNull()) return false;
	CImageHandle TitleMid(&m_SkinAttribute.m_TitleMid);
	if (m_SkinAttribute.m_TitleMid.IsNull()) return false;
	CImageHandle TitleRight(&m_SkinAttribute.m_TitleRight);
	if (m_SkinAttribute.m_TitleRight.IsNull()) return false;

	//绘画标题
	int nLeftWidth=TitleLeft->GetWidth();
	int nMidWidth=TitleMid->GetWidth();
	int nRightWidth=TitleRight->GetWidth();
	int nXMinDrawPause=cx-nRightWidth;
	TitleLeft->BitBlt(pDC->m_hDC,0,0);
	for (int i=nLeftWidth;i<nXMinDrawPause;i+=nMidWidth) TitleMid->BitBlt(pDC->m_hDC,i,0);
	TitleRight->BitBlt(pDC->m_hDC,nXMinDrawPause,0);
	
	//绘画文字
	CString strTitle;
	CRect rcTitleRect(35,4,cx-100,cy-2);
	m_pWndHook->GetWindowText(strTitle);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SelectObject(&m_SkinAttribute.m_DefaultFont);
	pDC->SetTextColor(m_SkinAttribute.m_crCaptionTXColor);
	//////////////////////////////////////////////////////////////////////////
	//pDC->DrawText(strTitle,&rcTitleRect,DT_LEFT|DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS);

	//变量定义
	int nStringLength=lstrlen(strTitle);
	int nXExcursion[8]={1,1,1,0,-1,-1,-1,0};
	int nYExcursion[8]={-1,0,1,1,1,0,-1,-1};

	//绘画边框
	pDC->SetTextColor(RGB(0,0,0/*0,98,142*/));
	CRect rcDraw;
	for (int i=0;i<CountArray(nXExcursion);i++)
	{
		rcDraw.CopyRect(rcTitleRect);
		rcDraw.OffsetRect(nXExcursion[i],nYExcursion[i]);
		pDC->DrawText(strTitle,nStringLength,&rcDraw,DT_VCENTER|DT_CENTER|DT_SINGLELINE|DT_END_ELLIPSIS);
	}

	//绘画字体
	rcDraw.CopyRect( rcTitleRect);
	pDC->SetTextColor(m_SkinAttribute.m_crCaptionTXColor);
	pDC->DrawText(strTitle,nStringLength,&rcDraw,DT_VCENTER|DT_CENTER|DT_SINGLELINE|DT_END_ELLIPSIS);
	//////////////////////////////////////////////////////////////////////////

	//关闭按钮
	if (m_cbButtonState[BST_CLOSE]&BUT_EXIST)
	{
		int nDrawPos=0;
		CImageHandle ImageHandle(&m_SkinAttribute.m_ButtonClose);
		if (m_cbButtonState[BST_CLOSE]&BUT_DISABLE)
		{
			nDrawPos=ImageHandle->GetWidth()*3/5;
		}
		else if (m_cbNowDownButton==BST_CLOSE)
		{
			nDrawPos=ImageHandle->GetWidth()*2/5;
		}
		else if (m_cbNowHotButton==BST_CLOSE) 
		{
			nDrawPos=ImageHandle->GetWidth()/5;
		}
		ImageHandle->BitBlt(pDC->GetSafeHdc(),m_rcButton[BST_CLOSE].left,m_rcButton[BST_CLOSE].top,
			m_SkinAttribute.m_nButtonWidth,m_SkinAttribute.m_nButtonHeigth,nDrawPos,0);
	}

	//最大化和还原按钮
	if (m_cbButtonState[BST_MAX]&BUT_EXIST)
	{
		int nDrawPos=0;
		CImageHandle ImageHandle;
		if (m_bMaxSize==true) ImageHandle.AttachResource(&m_SkinAttribute.m_ButtonRes);
		else ImageHandle.AttachResource(&m_SkinAttribute.m_ButtonMax);
		if (m_cbButtonState[BST_MAX]&BUT_DISABLE)
		{
			nDrawPos=ImageHandle->GetWidth()*3/5;
		}
		if (m_cbNowDownButton==BST_MAX)
		{
			nDrawPos=ImageHandle->GetWidth()*2/5;
		}
		else if (m_cbNowHotButton==BST_MAX)
		{
			nDrawPos=ImageHandle->GetWidth()/5;
		}
		ImageHandle->BitBlt(pDC->GetSafeHdc(),m_rcButton[BST_MAX].left,m_rcButton[BST_MAX].top,
			m_SkinAttribute.m_nButtonWidth,m_SkinAttribute.m_nButtonHeigth,nDrawPos,0);
	}

	//最小化按钮
	if (m_cbButtonState[BST_MIN]&BUT_EXIST)	
	{
		int nDrawPos=0;
		CImageHandle ImageHandle(&m_SkinAttribute.m_ButtonMin);
		if (m_cbButtonState[BST_MIN]&BUT_DISABLE)
		{
			nDrawPos=ImageHandle->GetWidth()*3/5;
		}
		if (m_cbNowDownButton==BST_MIN)
		{
			nDrawPos=ImageHandle->GetWidth()*2/5;
		}
		else if (m_cbNowHotButton==BST_MIN) 
		{
			nDrawPos=ImageHandle->GetWidth()/5;
		}
		ImageHandle->BitBlt(pDC->GetSafeHdc(),m_rcButton[BST_MIN].left,m_rcButton[BST_MIN].top,
			m_SkinAttribute.m_nButtonWidth,m_SkinAttribute.m_nButtonHeigth,nDrawPos,0);
	}

	return true;	
}

//设置改变事件
void CSkinWndObject1::OnSettingChange()
{
	//移动窗口
	if (m_bMaxSize==true)
	{
		//计算位置
		CRect rcClient;
		m_pWndHook->GetClientRect(&rcClient);
		m_pWndHook->ClientToScreen(&rcClient);
		m_pWndHook->GetWindowRect(&m_crNormalSize);

		//移动窗口
		CRect rcRect;
		SystemParametersInfo(SPI_GETWORKAREA,0,&rcRect,SPIF_SENDCHANGE);
		rcRect.top-=(rcClient.top-m_crNormalSize.top);
		rcRect.bottom+=(m_crNormalSize.bottom-rcClient.bottom);
		rcRect.left-=(rcClient.left-m_crNormalSize.left);
		rcRect.right+=(m_crNormalSize.right-rcClient.right);
		m_pWndHook->MoveWindow(&rcRect,FALSE);
		m_pWndHook->Invalidate(FALSE);
	}

	return;
}

//鼠标移动事件
bool CSkinWndObject1::OnMouseMoveEvent(CPoint ClientPoint)
{
	//设置光标
	SetCursor(LoadCursor(NULL,MAKEINTRESOURCE(IDC_ARROW)));

	//判断按下
	if (m_cbNowDownButton!=255) return false;	
	
	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(m_rcButton[i].PtInRect(ClientPoint)))
		{
			if (m_cbNowHotButton==i) return true;
			if (m_cbNowHotButton!=255)
			{
				m_cbButtonState[m_cbNowHotButton]|=BUT_NORMAL;
				m_cbNowHotButton=255;
			}
			if ((m_cbButtonState[i]&BUT_EXIST)&&(!(m_cbButtonState[i]&BUT_DISABLE)))
			{
				m_cbNowHotButton=i;
				m_cbButtonState[m_cbNowHotButton]&=~BUT_NORMAL;
			}
			DrawSkinView(NULL);
			return true;
		}
	}

	//清理旧焦点
	if (m_cbNowHotButton!=255)
	{
		m_cbButtonState[m_cbNowHotButton]|=BUT_NORMAL;
		m_cbNowHotButton=255;
		DrawSkinView(NULL);
	}

	return true;
}

//鼠标左键事件
bool CSkinWndObject1::OnLMouseDownEvent(CPoint ClientPoint)
{
	//判断按下
	if (m_cbNowDownButton!=255) return false;

	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(!(m_cbButtonState[i]&BUT_DISABLE))
			&&(m_rcButton[i].PtInRect(ClientPoint)))
		{
			//设置数据
			m_pWndHook->SetCapture();
			m_cbNowDownButton=i;
			DrawSkinView(NULL);
			return true;
		}
	}

	//模拟按标题
	if (m_bMaxSize==false)
	{
		if (ClientPoint.y<GetYExcursionPos())
		{
			m_pWndHook->PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(ClientPoint.x,ClientPoint.y));
			return true;
		}
		return false;
	}

	return true;
}

//鼠标左键事件
bool CSkinWndObject1::OnLMouseUpEvent(CPoint ClientPoint)
{
	//按钮搜索
	if (m_cbNowDownButton!=255)
	{
		ReleaseCapture();
		if ((m_rcButton[m_cbNowDownButton].PtInRect(ClientPoint))
			&&(!(m_cbButtonState[m_cbNowDownButton]&BUT_DISABLE)))
		{
			switch (m_cbNowDownButton)
			{
			case BST_CLOSE:		//关闭按钮
				{
					m_cbNowDownButton=255;
					m_pWndHook->PostMessage(WM_CLOSE,0,0);
					return true;
				}
// 			case BST_MAX:		//还原按钮
// 				{
// 					m_cbNowDownButton=255;
// 					if (m_bMaxSize==true) RestoreWindow();
// 					else MaxSizeWindow();
// 					return true;
// 				}
			case BST_MIN:		//最小化按钮
				{
					m_cbNowDownButton=255;
					m_pWndHook->ShowWindow(SW_MINIMIZE);
					return true;
				}
			}
		}

		//默认操作
		m_cbNowDownButton=255;
		DrawSkinView(NULL);
	}

	return true;
}

//鼠标左键事件
bool CSkinWndObject1::OnLMouseDoubleEvent(CPoint ClientPoint)
{
	//判断按下
	if (m_cbNowDownButton!=255) return false;	

	//按钮搜索
	for (int i=0;i<3;i++)
	{
		if ((m_cbButtonState[i]&BUT_EXIST)&&(m_rcButton[i].PtInRect(ClientPoint)))
			return true;
	}

	//最大化窗口
// 	if ((ClientPoint.y<GetYExcursionPos())&&(m_cbButtonState[BST_MAX]&BUT_EXIST)&&
// 		(!(m_cbButtonState[BST_MAX]&BUT_DISABLE)))
// 	{
// 		if (m_bMaxSize==true) RestoreWindow();
// 		else MaxSizeWindow();
// 	}
	
	return true;
}

//鼠标右键事件
bool CSkinWndObject1::OnRMouseDownEvent(CPoint ClientPoint)
{
	return true;
}

//鼠标右键事件
bool CSkinWndObject1::OnRMouseUpEvent(CPoint ClientPoint)
{
	return true;
}

//鼠标右键事件
bool CSkinWndObject1::OnRMouseDoubleEvent(CPoint ClientPoint)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////

