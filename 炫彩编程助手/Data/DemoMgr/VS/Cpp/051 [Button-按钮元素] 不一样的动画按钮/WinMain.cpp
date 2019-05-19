#include "Common.h"

class XCImage
{
public:
	XCImage()
	{
		m_imageArray = NULL;
	}
	~XCImage()
	{
		UnLoad();
	}
	void UnLoad()
	{
		if (m_imageArray)
		{
			delete[] m_imageArray;
			m_imageArray = NULL;
		}
	}
	void Load(const wchar_t* imageFile,int ImageCount,int imageWidth,int imageHeight)
	{
		UnLoad();
		m_imageCount = ImageCount;
		int x = 0;
		m_imageArray = new HIMAGE[ImageCount];
		for (int i = 0 ; i < ImageCount; i++)
		{
			m_imageArray[i] = XImage_LoadFileRect(imageFile,x,0,imageWidth,imageHeight);
			x += imageWidth;
		}
	}
	HIMAGE operator[](int index)
	{
		return m_imageArray[index];
	}
	int GetImageCount()
	{
		return m_imageCount;
	}
private:
	HIMAGE* m_imageArray;
	int     m_imageCount;
};

class XCButtonAnimate
{
public:
#define TIMER_ANIMATE_STAY 100
#define TIMER_ANIMATE_LEAVE 101

	XCButtonAnimate()
	{
	}
	void Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{

		m_hButtonAnimate = XBtn_Create(100, 50, 95, 95,L"", hParent);
		XEle_EnableBkTransparent(m_hButtonAnimate,TRUE);
		XEle_EnableDrawFocus(m_hButtonAnimate,FALSE);
		XBtn_AddBkImage(m_hButtonAnimate,button_state_leave,XImage_LoadFile(L"image\\clean.png"));


		XCImage image;
		image.Load(L"image\\qinglilaji_yijianqingli_Anima_Hover.png",10,95,95);
		for (int i = 0; i < 10; i++)
		{
			XBtn_AddAnimationFrame(m_hButtonAnimate,image[i],50);
		}
		XBtn_EnableAnimation(m_hButtonAnimate,TRUE);
//		XEle_RegEventCPP(m_hButtonAnimate,XE_MOUSESTAY,&XCButtonAnimate::OnMouseStay);
//		XEle_RegEventCPP(m_hButtonAnimate,XE_MOUSELEAVE,&XCButtonAnimate::OnMouseLeave);

	}
private:
	HELE m_hButton;
	HELE m_hButtonAnimate;
	HWINDOW m_hWindow;
};

class CWindow
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    XCButtonAnimate m_AnimateButton;
	
    CWindow(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
		m_AnimateButton.Create(100,100,95,95,m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




